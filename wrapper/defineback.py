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

def write_plasmafile(plasmafilename,ne_zone,Te_zone,TiTe_ratio):
    pfile = open(plasmafilename,'w')
    pfile.write("zone      T(1)         N(1)        T(2)        N(2)\n")

    Nzone = len(ne_zone)
    for idx in range(1,Nzone+1):
        pfile.write(str(idx)+"  "+str(Te_zone[idx-1])+"  "+str(ne_zone[idx-1])
                +"  "+str(TiTe_ratio*Te_zone[idx-1])+"  "+str(ne_zone[idx-1])+"\n")
    pfile.close()


# Generates a plasma file for use in defineback
# Arguments:
#   R_data: array of the R coordinates at which ne and Te are given at Z=0
#   ne_data, Te_data: the arrays of plasma density and temperature data defined at the R_data locations. ne_data should be in units of m^-3 and Te_data in units of eV
#   TiTe_ratio: a float value that provides Ti/Te, used to infer Ti from Te uniformly. To eventually replace with a separate array.
#   psifunc: a function passed as an argument. This function should take R,Z as arguments and return psi
#   plasmafilename (optional): the name and/or path of the plasma file to write
def generate_plasma_file(R_data,ne_data,Te_data,TiTe_ratio,psifunc,geomfilename,plasmafilename="plasmafile"):

    ncdata = nc.Dataset(geomfilename)
    zone_coords_3D = ncdata["zone_center"]
    zone_type = ncdata["zone_type"]

    zone_coords = []
    for point in range(0,len(zone_coords_3D)):
        if zone_type[point] == 2:
            zone_coords.append([zone_coords_3D[0],zone_coords_3D[2]])

    ne_zone, Te_zone = get_zone_plasma_data(zone_coords,R_data,ne_data,Te_data,psifunc)

    write_plasmafile(plasmafilename,ne_zone,Te_zone,TiTe_ratio)

