import matplotlib.pyplot as plt
import matplotlib.path as path
import netCDF4 as nc
from scipy import interpolate
import numpy as np
import dg2d
import polygon
import sys
from importlib import reload 

# Given midplane plasma characterization as a function of R, 
# interpolate to get the plasma properties on each surface.
def get_plasma_on_surfaces(R_data,ne_data,Te_data,surfs):

    # Make interpolant function from data
    ne_func = interpolate.interp1d(R_data,ne_data)
    Te_func = interpolate.interp1d(R_data,Te_data)

    ne_surf = []
    Te_surf = []

    for surf in surfs[1:]:
        # Find the index(ices) which straddles Z=0
        # Is it then only one? Then use it.
        # If it's one of two, is only one within the bounds of R_data?
        # If not, then use the average of the two points
        if ( surf.vertices[0].coords[0] == surf.vertices[-1].coords[0] and
                ( surf.vertices[0].coords[1] == surf.vertices[-1].coords[1]) ):
            # Surface is closed. There will be two such intersections
            idx_cross = [-1,-1]
            found_one = False
            inside_data = [False, False]
            for idx in range(0,len(surf.vertices)-1):
                Zstraddle = [surf.vertices[idx].coords[1], surf.vertices[idx+1].coords[1]]
                if min(Zstraddle) < 0.0 and max(Zstraddle) >= 0.0 :
                    Ravg = 0.5*(surf.vertices[idx].coords[0] + surf.vertices[idx+1].coords[0])
                    if found_one:
                        idx_cross[1] = idx
                        if Ravg >= np.min(R_data) and Ravg <= np.max(R_data) :
                            inside_data[1] = True
                    else:
                        idx_cross[0] = idx
                        found_one = True
                        if Ravg >= np.min(R_data) and Ravg <= np.max(R_data) :
                            inside_data[0] = True

            if idx_cross[0] == -1 or idx_cross[1] == -1:
                print("ERROR: could not find two intersection points for what should be a closed flux surface.")
                sys.exit(1)

            if sum(inside_data) == 0:
                print("ERROR: Neither intersection with Z=0 plane is within the data range. Don't know what to do.")
                sys.exit(1)
            elif sum(inside_data) == 1:
                if inside_data[0]:
                    idx_cross = idx_cross[0]
                else:
                    idx_cross = idx_cross[1]
                Ravg = 0.5*(surf.vertices[idx_cross].coords[0] + surf.vertices[idx_cross+1].coords[0])
                ne_surf.append( ne_func(Ravg) )
                Te_surf.append( Te_func(Ravg) )
            elif sum(inside_data) == 2:
                Ravg0 = 0.5*(surf.vertices[idx_cross[0]].coords[0] + surf.vertices[idx_cross[0]+1].coords[0])
                Ravg1 = 0.5*(surf.vertices[idx_cross[1]].coords[0] + surf.vertices[idx_cross[1]+1].coords[0])
                ne_surf.append( 0.5*(ne_func(Ravg0) + ne_func(Ravg1)) )
                Te_surf.append( 0.5*(Te_func(Ravg0) + Te_func(Ravg1)) )

        else:
            # Surface is open
            idx_cross = -1
            found_one=False
            for idx in range(0,len(surf.vertices)-1):
                Zstraddle = [surf.vertices[idx].coords[1], surf.vertices[idx+1].coords[1]]
                if min(Zstraddle) < 0.0 and max(Zstraddle) >= 0.0 :
                    idx_cross = idx
                    if found_one == True:
                        print("ERROR: Found two intersections on what should be an open flux surface.\n")
                        print("Vertex dump:\n")
                        print(surf.vertices[0].coords)
                        print(surf.vertices[-1].coords)
                        sys.exit(1)
                    found_one=True
            if idx_cross == -1:
                print("ERROR: could not find a point on the surface that straddles Z=0 plane.  \
                        Cannot assign plasma data with current algorithm")
                sys.exit(1)

            Ravg = 0.5*(surf.vertices[idx_cross].coords[0] + surf.vertices[idx_cross+1].coords[0])
            ne_surf.append( ne_func(Ravg) )
            Te_surf.append( Te_func(Ravg) )

    return ne_surf, Te_surf

# Interpolate between neighboring surfaces (as defined by polymap)
def interpolate_point_between_surfaces(pt_coords,polys,surfs,polymap,surf_data):

    vertex_in = Vertex(-1,pt_coords[0],pt_coords[1])

    found = False
    for ipoly in range(0,len(polys)):
        mplpath = path.Path(polys[ipoly].vertices)
        if mplpath.contains_point(pt_coords):
            found = True
            bound_surfaces = polymap[ipoly]
        
    if not found:
        print("ERROR: Could not find point in any polygon")
        sys.exit(1)


    idx0 = surfs[bound_surfaces[0]].vertices.get_N_closest_vertices(1,vertex_in)
    idx1 = surfs[bound_surfaces[1]].vertices.get_N_closest_vertices(1,vertex_in)

    dist0 = np.sqrt( ( surfs[bound_surfaces[0]].vertices[idx0].coords[0] - pt_coords[0])**2 
            +  ( surfs[bound_surfaces[0]].vertices[idx0].coords[1] - pt_coords[1])**2  )
    dist1 = np.sqrt( ( surfs[bound_surfaces[1]].vertices[idx0].coords[0] - pt_coords[0])**2 
            +  ( surfs[bound_surfaces[1]].vertices[idx0].coords[1] - pt_coords[1])**2  )
    totaldist = dist0+dist1
    
    interpfunc = interpolate.interp1d([0.0,totaldist], [surf_data[bound_surfaces[0]],surf_data[bound_surfaces[1]]])

    point_data = interpfunc( dist0)

    return point_data

def get_zone_plasma_data(zone_coords,polys,surfs,polymap,R_data,ne_data,Te_data):

    ne_surf, Te_surf = get_plasma_on_surfaces(R_data,ne_data,Te_data,surfs)

    ne_zone = []
    Te_zone = []

    for coords in zone_coords:
        ne = interpolate_point_between_surfaces(coords,polys,surfs,polymap,ne_surf)
        Te = interpolate_point_between_surfaces(coords,polys,surfs,polymap,Te_surf)
        ne_zone.append(ne)
        Te_zone.append(Te)

    return ne_zone, Te_zone

def write_plasmafile(plasmafilename,ne_zone,Te_zone):
    pfile = open(plasmafilename,'w')
    pfile.write("zone      T(1)         N(1)        T(2)        T(2)\n")

    Nzone = len(ne_zone)
    for zone_idx in range(1,Nzone+1):
        pfile.write(str(idx)+"  "+str(Te_zone[idx-1])+"  "+str(ne_zone[idx-1])
                +"  "+str(Te_zone[idx-1])+"  "+str(ne_zone[idx-1])+"\n")
    pfile.close()



def generate_plasma_file(polys,surfs,polymap,R_data,ne_data,Te_data,geomfilename,plasmafilename="plasmafile"):

    ncdata = nc.Dataset(geomfilename)
    zone_coords_3D = ncdata["zone_center"]

    zone_coords = []
    for point in range(0,len(zone_coords_3D)):
        zone_coords.append([zone_coords_3D[0],zone_coords_3D[2]])

    ne_zone, Te_zone = get_zone_plasma_data(zone_coords,polys,surfs,polymap,R_data,ne_data,Te_data)

    write_plasmafile(plasmafilename,ne_zone,Te_zone)



