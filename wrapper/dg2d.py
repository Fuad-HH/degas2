import matplotlib.pyplot as plt
import numpy as np
import polygon

def write_dg2d_input_from_wallfile(wallfile_name,dg2dfile_name="dg2d.in",direction="clockwise",debug=False):

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

    Rcoords = np.zeros(nwalls,max(npoints))
    Zcoords = np.zeros(nwalls,max(npoints))

    nlines = sum(npoints)
    iwall = 0
    ipoint = 0
    for iwall in range(0,nwalls):
        for ipoint in range(0,npoints[iwall]):
            line = next_noncomment_line(wallfile)
            line_ints = [int(n) for n in line.split()]
            Rcoods[iwall,ipoint] = line_ints[0]
            Zcoods[iwall,ipoint] = line_ints[1]

    # Now we have read the wallfile. We know how many points are in each wall and the R/Z coordinates for each point defining these walls. We can close the wallfile now.
    wallfile.close()

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

    # Now, the polygons need to be generated. Some decisions need to communicated about the topology.
    polygons = polygon.get_polygons() 
    
