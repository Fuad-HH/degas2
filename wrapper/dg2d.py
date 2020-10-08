import matplotlib.pyplot as plt
import numpy as np
import polygon
import sys

def write_dg2d_input_from_wallfile(wallfile_name,topology,topology_params,material,recyc,dg2dfile_name="dg2d.in",polygonfile_name="polygons.nc",debug=False):

    # Read the wallfile
    wallfile = open(wallfile_name,'r')

    def next_noncomment_line(f):
        found=False
        while not found:
            line = wallfile.readline().strip()
            if not line[0] == '#':
                found = True
        return line

    # Get the number of points defining each wall (npoints) 
    # from the next one-to-several lines
    nwalls = int(next_noncomment_line(wallfile))
    npoints = np.zeros(nwalls)
    nwalls_read=0
    while nwalls_read < nwalls:
        line = next_noncomment_line(wallfile)
        npoints_list = [int(n) for n in line.split()]
        nwalls_current = len(npoints_list)
        npoints[nwalls_read:nwalls_read+nwalls_current] = npoints_list
        nwalls_read += nwalls_current

    nlines = sum(npoints)
    iwall = 0
    ipoint = 0
    walls = []
    for iwall in range(0,nwalls):
        walls.append(Surface(iwall))
        for ipoint in range(0,npoints[iwall]):
            line = next_noncomment_line(wallfile)
            line_ints = [int(n) for n in line.split()]
            Rcoord = line_ints[0]
            Zcoord = line_ints[1]
            walls[iwall].add_vertex(WallVertex(iwall,ipoint,Rcoord,Zcoord))

    # Now we have read the wallfile. We know how many points are in each wall and the R/Z coordinates for each point defining these walls. We can close the wallfile now.
    wallfile.close()

    if topology == "LTX":
        # For LTX, the walls should be defined in the following order:
        # 1: External solid wall
        # 2: Several closed flux surfaces, starting from the outermost
        num_closed_surfaces = topology_params[0]
        # 3: The remainder are open flux surfaces (outside the limiter), starting with the outermost
        num_open_surfaces = nwalls-1-num_closed_surfaces

        clockwise = False

        # The vertex indices of the solid wall which correspond to the limiter edges.
        # MUST go from top to bottom (high to low index, when listed counterclockwise)
        limiter_vertex_idx = (topology_params[1], topology_params[2])

        limlcfs_idx_upper = walls[1].insert_vertex_into_surface(walls[0].vertices[limiter_vertex_idx[0]])
        limlcfs_idx_lower = walls[1].insert_vertex_into_surface(walls[0].vertices[limiter_vertex_idx[1]])

        polys=[]

        ############
        # First, define the closed flux surface zones
        for ipoly in range(0,num_closed_surfaces):
            polys.append( Polygon() )
            for vertex in walls[1+ipoly].vertices:
                polys[ipoly].add_vertex(vertex)
            polys[ipoly].add_vertex(walls[1+ipoly].vertices[0])
            if ipoly < num_closed_surfaces-1:
                for vertex in walls[1+ipoly+1].vertices[-1::-1]:
                    polys[ipoly].add_vertex(vertex)
                polys[ipoly].add_vertex(walls[1+ipoly+1].vertices[0])
                polys[ipoly].add_vertex(walls[1+ipoly].vertices[0])

        ############
        # Then, the limiter region beyond the LCFS
        polys.append(Polygon())

        # The relevant part of the solid wall
        for vertex in walls[0].vertices[limiter_vertex_idx[0]:-1]:
            polys[num_closed_surfaces].add_vertex(vertex)
        for vertex in walls[0].vertices[0:limiter_vertex_idx[1]]:
            polys[num_closed_surfaces].add_vertex(vertex)
        # The relevant part of the LCFS, in reverse order
        for vertex in walls[1].vertices[limlcfs_idx_lower::-1]:
            polys[num_closed_surfaces].add_vertex(vertex)
        for vertex in walls[1].vertices[-1:limlcfs_idx_upper:-1]:
            polys[num_closed_surfaces].add_vertex(vertex)
        polys[num_closed_surfaces].add_vertex(walls[0].vertices[limiter_vertex_idx[0]])


        ############
        # Then, the zone between the LCFS and the first open flux surface (last in the list of walls)
        polys.append(Polygon())

        # The relevant part of the LCFS
        for vertex in walls[1].vertices[limlcfs_idx_lower:limlcfs_idx_upper+1]:
            polys[num_closed_surfaces+1].add_vertex(vertex)
        # Now, find the solid wall index corresponding to the ends of the first open flux surfaces

        # First build a dummy polygon to track other surface
        dummyPoly = Polygon(increment=False)
        for vertex in walls[-1].vertices[-1::-1]:
            dummyPoly.add_vertex(vertex)
        wallidx_intersect_lower = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])
        dummyPoly = Polygon(increment=False)
        for vertex in walls[-1].vertices:
            dummyPoly.add_vertex(vertex)
        wallidx_intersect_upper = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])

        # Add relevant part of upper solid wall
        for vertex in walls[0].indices[limiter_vertex[0]:wallidx_intersect_upper-1:-1]:
            polys[num_closed_surfaces+1].add_vertex(vertex)

        # Add first open flux surface, in reverse order
        for vertex in walls[-1].indices[-1::-1]:
            polys[num_closed_surfaces+1].add_vertex(vertex)

        # Add relevant part of lower solid wall
        for vertex in walls[0].indices[limiter_vertex[1]:wallidx_intersect_lower-1:-1]:
            polys[num_closed_surfaces+1].add_vertex(vertex)

        # Close the polygon
        polys[num_closed_surfaces+1].add_vertex(walls[1].vertices[limlcfs_idx_lower])

        ############
        # Then, the zone between the outermost flux surface and the solid wall. Similar to above
        polys.append(Polygon())

        # Add the outermost flux surface
        for vertex in walls[num_closed_surfaces].vertices():
            polys[num_closed_surfaces+2].add_vertex(vertex)

        # Now, find the solid wall index corresponding to the ends of the first open flux surfaces
        wallidx_intersect_lower = polys[num_closed_surfaces+2].get_next_vertex_extrapolated_to_wall(walls[0])

        # First build a dummy polygon to track other surface
        dummyPoly = Polygon(increment=False)
        for vertex in walls[0].vertices[-1::-1]:
            dummyPoly.add_vertex(vertex)
        wallidx_intersect_upper = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])

        # Add relevant part of upper solid wall
        for vertex in walls[0].indices[wallidx_intersect_lower:wallidx_intersect_upper+1]:
            polys[num_closed_surfaces+2].add_vertex(vertex)

        # Close the polygon
        polys[num_closed_surfaces+2].add_vertex(walls[num_closed_surfaces].vertices[0])

        ############
        # Finally, the zones between the solid wall and the open flux surfaces
        for ipoly in range(num_closed_surfaces+2,num_closed_surfaces+2+num_open_surfaces):
            polys.append( Polygon() )
            opensurf_idx = ipoly-1
            for vertex in walls[opensurf_idx].vertices:
                polys[ipoly].add_vertex(vertex)
            wallidx_intersect_bl = polys[ipoly].get_next_vertex_extrapolated_to_wall(walls[0])
            
            dummyPoly = Polygon(increment=False)
            for vertex in walls[opensurf_idx-1].vertices:
                dummyPoly.add_vertex(vertex)
            wallidx_intersect_br = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])

            for vertex in walls[0].vertices[wallidx_intersect_bl:wallidx_intersect_br+1]:
                polys[ipoly].add_vertex(vertex)

            for vertex in walls[opensurf_idx-1].vertices[-1::-1]:
                polys[ipoly].add_vertex(vertex)

            wallidx_intersect_ur = polys[ipoly].get_next_vertex_extrapolated_to_wall(walls[0])

            dummyPoly = Polygon(increment=False)
            for vertex in walls[opensurf_idx].vertices[-1::-1]:
                dummyPoly.add_vertex(vertex)
            wallidx_intersect_ul = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])

            for vertex in walls[0].vertices[wallidx_intersect_ur:wallidx_intersect_ul-1:-1]:
                polys[ipoly].add_vertex(vertex)

            polys[ipoly].add_vertex(walls[opensurf_idx].vertices[0])

    else:
        print("Error: topology "+topology+" not defined.")
        sys.exit(0)

    # Now we build the wall specification in the dg2d input file
    dg2dfile = open(dg2dfile_name,'w')

    ####################################
    # First, set the header
    dg2dfile.write("symmetry cylindrical\n")

    ####################################
    # Find and write appropriate bounds
    Rrange = np.amax(Rcoords) - np.amin(Rcoords)
    Zrange = np.amax(Zcoords) - np.amin(Zcoords)
    Zmin = np.amin(Zcoords) - 0.5*Zrange
    Zmax = np.amax(Zcoords) + 0.5*Zrange
    Rmin = min(np.amin(Rcoords) - 0.5*Rrange, 0.5*np.amin(Rcoords))
    Rmax = np.amax(Rcoords) + 0.5*Rrange
    dg2dfile.write("bounds     %d %d    %d %d \n" % (Rmin, Rmax, Zmin, Zmax))

    ####################################
    # Write out name of wallfile
    dg2dfile.write("wallfile "+wallfile_name.strip()+"\n")

    dg2dfile.write("end_prep\n")

 
    for poly in polys:
        poly.write_plasma_polygon_dg2d(dg2dfile,debug=True)

    walls[0].write_solid_polygon_dg2d(len(polys),dg2dfile,material,recyc,debug)

    dg2dfile.write("polygon_nc_file "+polygon_filename+"\n")

    if debug:
        dg2dfile.write("quit\n")

    dg2dfile.write("end\n")
