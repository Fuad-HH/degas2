import matplotlib.pyplot as plt
import netCDF4 as nc
from scipy import interpolate
import numpy as np
import dg2d
import sys
from importlib import reload 

def get_zone_plasma_data(zone_coords,R_data,ne_data,Te_data,psifunc):

    psi_data = []

    for R in R_data:
        # Get average value on psi on each surface. Nominally all points should have equal psi
        psi_data.append(psifunc(R,0.0))

    ne_func = interpolate.interp1d(psi_data,ne_data,fill_value=(ne_data[0],ne_data[-1]))
    Te_func = interpolate.interp1d(psi_data,Te_data,fill_value=(Te_data[0],Te_data[-1]))

    ne_zone = []
    Te_zone = []

    for point in zone_coords:
        psi = psifunc(point[0],point[1])
        ne_zone.append(ne_func(psi))
        Te_zone.append(Te_func(psi))

    return ne_zone, Te_zone

def write_plasmafile(plasmafilename,ne_zone,Te_zone,TiTe_ratio,vpar_zone,area_zone):
    pfile = open(plasmafilename,'w')
    pfile.write("zone      T(1)         N(1)        T(2)        N(2)        V_PAR       AREA\n")

    Nzone = len(ne_zone)
    for idx in range(1,Nzone+1):
        pfile.write(str(idx)+"  "+str(Te_zone[idx-1])+"  "+str(ne_zone[idx-1])
                +"  "+str(TiTe_ratio*Te_zone[idx-1])+"  "+str(ne_zone[idx-1])+"  "+str(vpar_zone[idx-1])+" "+str(area_zone[idx-1])+"\n")
    pfile.close()


# Generates a plasma file for use in defineback
# Arguments:
#   R_data: array of the R coordinates at which ne and Te are given at Z=0
#   ne_data, Te_data: the arrays of plasma density and temperature data defined at the R_data locations. ne_data should be in units of m^-3 and Te_data in units of eV
#   TiTe_ratio: a float value that provides Ti/Te, used to infer Ti from Te uniformly. To eventually replace with a separate array.
#   psifunc: a function passed as an argument. This function should take R,Z as arguments and return psi
#   plasmafilename (optional): the name and/or path of the plasma file to write
def generate_plasma_file(R_data,ne_data,Te_data,TiTe_ratio,psifunc,geomfilename,bfieldfilename="gs_fields.dat",plasmafilename="plasmafile",mass=1.66e-27):

    ncdata = nc.Dataset(geomfilename)
    zone_coords_3D = ncdata["zone_center"]
    zone_type = ncdata["zone_type"]
    plasma_sector = ncdata["plasma_sector"]
    sector_zone = ncdata["sector_zone"]
    sector_points = ncdata["sector_points"]

    zone_coords = []
    zone_idx = []
    for point in range(0,len(zone_coords_3D)):
        # Store the plasma zones in zone_idx and their center locations in zone_coords
        if zone_type[point] == 2:
            zone_coords.append([zone_coords_3D[point,0],zone_coords_3D[point,2]])
            zone_idx.append(point)

    area_zone = np.zeros(np.size(zone_idx))
    vpar_zone = np.zeros(np.size(zone_idx))
   
    ne_zone, Te_zone = get_zone_plasma_data(zone_coords,R_data,ne_data,Te_data,psifunc)

    #diag_r = np.zeros(len(plasma_sector))
    #diag_z = np.zeros(len(plasma_sector))

    file = open(bfieldfilename,"r")
    first = True
    r_data = []
    z_data = []
    Br_data = []
    Bz_data = []
    for line in file:
        if not first:
            first=False
            data = line.split()
            r_data.append(float(data[0]))
            z_data.append(float(data[1]))
            Br_data.append(float(data[2]))
            Bz_data.append(float(data[4]))
        first=False

    print(r_data)
    # Find the zones corresponding to each plasma sector 
    for isector in range(1,len(plasma_sector)):
        psector = plasma_sector[isector]
        izone = sector_zone[psector]-1
        localidx = zone_idx.index(izone)
        vpar_zone[localidx] = np.sqrt(1.602e-19*Te_zone[localidx]/mass)

        # The two points that define the sector line segment
        print(psector,np.shape(sector_points))
        point1 = np.array([sector_points[psector,0,0],sector_points[psector,0,2]])
        point2 = np.array([sector_points[psector,1,0],sector_points[psector,1,2]])

        center = 0.5*(point1+point2)

        # Get the unit vector normal to this surface, a_unit
        diff = point2-point1
        normal = [-diff[1],diff[0]]
        a_unit = normal/np.linalg.norm(normal)
        fullarea = 2.0*np.pi*center[0]*np.linalg.norm(diff)

        # Get the magnetic field unit vector in the poloidal plane, b_unit
        # Use nearest data point:
        data_idx = np.argmin(np.sqrt( np.square(center[0]-r_data) + np.square(center[1]-z_data)) )

        Br=Br_data[data_idx]
        Bz=Bz_data[data_idx]

        b_unit = [Br,Bz]/np.linalg.norm([Br,Bz])

        area_zone[localidx] = fullarea*np.abs(np.dot(b_unit,a_unit))

        #diag_r[isector-1] = zone_coords[localidx][0]
        #diag_z[isector-1] = zone_coords[localidx][1]

    #plt.plot(diag_r,diag_z,'o')
    #plt.savefig("sectorzones.png")
    #plt.clf()
    #plt.close()

    write_plasmafile(plasmafilename,ne_zone,Te_zone,TiTe_ratio,vpar_zone,area_zone)


# Generates an input file for defineback
# Arguments:
#   Nflights: array of integers specifying the total number of flights from each strata
#   wallstrata: array of integers which identifies the strata which make up the wall
#   source_strength: array of floating point numbers specifying the given source strength. Needs to be generalized.
#   dbfilename: name of the defineback input file
#   plasmafilename: name of the plasmafile written by generate_plasma_file above
# TODO:
# - Figure out how to have a strictly recycling source
# - Scale Nflights with the length of the strata

def generate_db_input(Nflights,wallstrata,source_strength,dbfilename="db.in",plasmafilename="plasmafile"):

    f = open(dbfilename,"w")
    f.write("plasma_file "+plasmafilename+"\n")

    for i in range(0,len(wallstrata)):
        f.write("new_source_group\n")
        f.write("  source_type plate\n")
        f.write("  source_geom surface\n")
        f.write("  source_species H2\n")
        f.write("  source_root_sp H+\n")
        f.write("  specify_flux\n")
        f.write("  source_nflights "+str(Nflights[i])+"\n")
        f.write("  source_stratum "+str(wallstrata[i])+"\n")
        f.write("  source_segment *\n")
        f.write("  source_strength "+str(source_strength[i])+"\n")
        f.write("end_source_group\n \n")

