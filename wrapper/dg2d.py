import matplotlib.pyplot as plt
import numpy as np
from polygon import *
import sys
from importlib import reload

def write_dg2d_input_from_wallfile(wallfile_name,topology,topology_params,material,recyc,dg2dfile_name="dg2d.in",polygon_filename="polygons.nc",debug=False):

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
    npoints = [0]*nwalls
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
    Rcoords = []
    Zcoords = []
    for iwall in range(0,nwalls):
        walls.append(Surface(iwall))
        for ipoint in range(0,npoints[iwall]):
            line = next_noncomment_line(wallfile)
            line_floats = [float(n) for n in line.split()]
            Rcoord = line_floats[0]
            Zcoord = line_floats[1]
            Rcoords.append(Rcoord)
            Zcoords.append(Zcoord)
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
        limiter_vertex_idx = [topology_params[1], topology_params[2]]

        # Important to do the lower one first so that indices are preserved after inserting
        limlcfs_idx_lower = walls[1].insert_vertex_into_surface(walls[0].vertices[limiter_vertex_idx[1]])
        limlcfs_idx_upper = walls[1].insert_vertex_into_surface(walls[0].vertices[limiter_vertex_idx[0]])

        polys=[]

        ############
        # First, define the closed flux surface zones
        for isurf in range(1,num_closed_surfaces):
            outer = walls[isurf]
            inner = walls[isurf+1]
            small, large= Surface.genpolys_from_two_closed_surfs(inner,outer)
            polys.append( Polygon() )
            polys[-1].vertices = copy.deepcopy(small.vertices)
            polys.append( Polygon() )
            polys[-1].vertices = copy.deepcopy(large.vertices)

        polys.append(Polygon())
        polys[-1].add_whole_surface(walls[num_closed_surfaces],backward=True)
        polys[-1].add_vertex(walls[num_closed_surfaces].vertices[-1])
    
        ############
        # Then, the limiter region beyond the LCFS
        polys.append(Polygon())
        # The relevant part of the solid wall
        for vertex in walls[0].vertices[limiter_vertex_idx[1]::-1]:
            polys[-1].add_vertex(vertex)
        for vertex in walls[0].vertices[-1:limiter_vertex_idx[0]-1:-1]:
            polys[-1].add_vertex(vertex)
        # The relevant part of the LCFS
        for vertex in walls[1].vertices[limlcfs_idx_upper:]:
            polys[-1].add_vertex(vertex)
        for vertex in walls[1].vertices[0:limlcfs_idx_lower+1]:
            polys[-1].add_vertex(vertex)

        if num_open_surfaces == 0:
            # Case where the scrape off layer is all one polygon
            polys.append(Polygon())

            # The relevant part of the LCFS
            for vertex in walls[1].vertices[limlcfs_idx_lower:limlcfs_idx_upper+1]:
                polys[-1].add_vertex(vertex)

            # Add relevant part of solid wall
            for vertex in walls[0].vertices[limiter_vertex_idx[0]-1:limiter_vertex_idx[1]:-1]:
                polys[-1].add_vertex(vertex)
 
            polys[-1].add_vertex(walls[1].vertices[limlcfs_idx_lower])
        else:
            ############
            # Then, the zone between the LCFS and the first open flux surface (last in the list of walls)
            polys.append(Polygon())
    
            # The relevant part of the LCFS
            for vertex in walls[1].vertices[limlcfs_idx_lower:limlcfs_idx_upper+1]:
                polys[-1].add_vertex(vertex)
            # Now, find the solid wall index corresponding to the ends of the first open flux surfaces
    
            # First build a dummy polygon to track other surface
            dummyPoly = Polygon(increment=False)
            for vertex in walls[-1].vertices[-1::-1]:
                dummyPoly.add_vertex(vertex)
            wallidx_intersect_upper = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])
            dummyPoly = Polygon(increment=False)
            for vertex in walls[-1].vertices:
                dummyPoly.add_vertex(vertex)
            wallidx_intersect_lower = dummyPoly.get_next_vertex_extrapolated_to_wall(walls[0])
    
            # Add relevant part of upper solid wall
            for vertex in walls[0].vertices[limiter_vertex_idx[0]:wallidx_intersect_upper-1:-1]:
                polys[-1].add_vertex(vertex)
    
            # Add first open flux surface
            for vertex in walls[-1].vertices:
                polys[-1].add_vertex(vertex)
    
            # Add relevant part of lower solid wall
            for vertex in walls[0].vertices[wallidx_intersect_lower:limiter_vertex_idx[1]-1:-1]:
                polys[-1].add_vertex(vertex)
    
            # Close the polygon
            polys[-1].add_vertex(walls[1].vertices[limlcfs_idx_lower])
    
            ############
            # Then, the zone between the outermost flux surface and the solid wall. Similar to above
            polys.append(Polygon())
            polys[-1].vertices = copy.deepcopy(Surface.genpoly_from_rightwall_and_surface(walls[0],walls[num_closed_surfaces+1]).vertices)

    
            ############
            # Finally, the zones bounded by open flux surfaces and solid wall
    
            for isurf in range(0,num_open_surfaces-1):
    
                polys.append( Polygon() )
    
                outer = walls[num_closed_surfaces + 1 + isurf]
                inner = walls[num_closed_surfaces + 1 + isurf + 1]
    
                polys[-1].vertices = copy.deepcopy(Surface.genpoly_from_two_open_surfs(inner,outer,walls[0]).vertices)
    
    # Don't think we need polygon-to-surface mapping anymore. Commenting out for now. 
    # If this is brought back, above logic needs to respected
#        poly_to_surf_map = []
#        # The polygons bounded by two closed flux surfaces (two polygons each):
#        for isurf in range(1,num_closed_surfaces):
#            poly_to_surf_map.append([isurf,isurf+1])
#            poly_to_surf_map.append([isurf,isurf+1])
#
#        # The innermost closed flux surface defines a single polygon
#        poly_to_surf_map.append([num_closed_surfaces,num_closed_surfaces])
#
#        # The limiter region
#        poly_to_surf_map.append([1,nwalls-1])
#
#        # The innermost open region
#        poly_to_surf_map.append([1,nwalls-1])
#
#        # The outermost open region
#        poly_to_surf_map.append([num_closed_surfaces+1,num_closed_surfaces+1])
#
#        for isurf in range(num_closed_surfaces+1,nwalls-1):
#            poly_to_surf_map.append([isurf,isurf+1])
#
#        if len(poly_to_surf_map) != len(polys):
#            print("ERROR: poly_to_surf_map does not have the same elements as polys")
#            print("len(polys)="+str(len(polys))+"\nlen(poly_to_surf_map)="+str(len(poly_to_surf_map)))
#            sys.exit(1)
#

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
    #Rcoords = walls[0].vertices[:].coords[0]
    #Zcoords = walls[0].vertices[:].coords[1]
    Rrange = np.amax(Rcoords) - np.amin(Rcoords)
    Zrange = np.amax(Zcoords) - np.amin(Zcoords)
    Zmin = np.amin(Zcoords) - Zrange
    Zmax = np.amax(Zcoords) + Zrange
#    Rmin = max(np.amin(Rcoords) - 0.8*Rrange, 0.2*np.amin(Rcoords))
    Rmin = 0.0001
    Rmax = np.amax(Rcoords) + Rrange
    dg2dfile.write("bounds     %f %f    %f %f \n" % (Rmin, Rmax, Zmin, Zmax))

    ####################################
    # Write out name of wallfile
    dg2dfile.write("wallfile "+wallfile_name.strip()+"\n")

    dg2dfile.write("end_prep\n")
    dg2dfile.write("\n")

 
    for poly in polys:
        poly.write_plasma_polygon_dg2d(dg2dfile,debug=debug)

    walls[0].write_solid_polygon_dg2d(len(polys)+1,dg2dfile,material,recyc,debug)
    dummyPoly=Polygon()
    dummyPoly=Polygon()

    dg2dfile.write("polygon_nc_file "+polygon_filename+"\n")

    if debug:
        dg2dfile.write("quit\n")

    dg2dfile.write("end\n")

    dg2dfile.close()

    Polygon.clear_numPolygon()

    return polys,walls

    # No longer needs to return this stuff for defineback to work properly
#    return polys, walls, poly_to_surf_map

def plot_polygon_from_file(ipoly):
    polyfilename="poly."+str(ipoly)+".dat"
    polyfile = open(polyfilename,'r')
    first = True
    R=[]
    Z=[]
    for line in polyfile:
        strdata=line.split()
        if first:
            first = False
        else:
            R.append(float(strdata[0]))
            Z.append(float(strdata[1]))

    # Make sure polygon is closed
    R.append(R[0])
    Z.append(Z[0])

    plt.plot(R,Z,"-+")

def plot_allpolys_from_file(N):
    plt.clf()
    for ipoly in range(1,N+1):
        plot_polygon_from_file(ipoly)


