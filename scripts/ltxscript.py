# An example for using these scripts. Will call degas2 executables as needed, so ensure that they are in your $PATH
# Also, make sure degas2/wrapper is in your $PYTHONPATH
# To use as-is, run in your working directory. Otherwise, just use this as a template to copy into your own scripts
import os
import subprocess
import dg2d
import problem
import defineback
import postprocess
import numpy as np
import read_eqdsk
import scipy.interpolate as interpolate

# Name of the file specifying the wall coordinates and LCFS
# (same format as before, but it will ignore all but the first two "walls"
wallfile = "wallfilesep22_471msec"

lymanfile = "Lyman_sep-22-471.DAT"

# Contains information about the magnetic field 
bfieldfile = "gs_fields.dat"

solfile = "SOL_sep-22-471.DAT"

tsfile = "TS_sep-22-471.DAT"

eqdsk_file = "LTX_103955_01.eqdsk"

# Recycling coefficient
recyc = 0.6

# Wall Material
material = "Li"

# Wall temperature in Kelvin
walltemp = 300.0

# The number of flight samples
Nsample = 100000

# The neutral source will get multiplied by (1-ftrapped)
ftrapped = 0.0

# definegeometry2d will split up the domain into triangles, and
# it will try to keep these triangles below this maximum area (in m^2)
minarea = 1.0e-5
# Doesn't seem to do anything though.

TiTe_ratio = 1.0/3.0

# Define psi as a function of R,Z. Only used inside separatrix.
def psirz(R,Z):
    # R = list of R points, Z list of Z point
    equilib = read_eqdsk.read_eqdsk( eqdsk_file )
    flux = np.transpose(equilib['psirz'])
    r_1d = np.linspace(equilib['rleft'], equilib['rleft'] + equilib['rdim'], num=equilib['nr'])
    z_1d = np.linspace(equilib['zmid'] - equilib['zdim'] / 2, equilib['zmid'] + equilib['zdim'] / 2, num=equilib['nz'])
    f = interpolate.interp2d(r_1d, z_1d, flux, kind='cubic')
    psirz = f(R, Z)
    return psirz[0]


problem.genStdProblem("Li")
print("Running problemsetup...\n")
subprocess.run("problemsetup",shell=True)

# This routine reads only the first two entries in the wallfile:
# the solid wall itself
# the LCFS, whose coordinates are saved to Rsep and Zsep
# Exit nodes count from zero!
polys, walls, Rsep, Zsep = dg2d.write_dg2d_input_from_single_wall(wallfile,material,recyc,minarea=minarea,exitnodes=(523,526))

print("Running definegeometry2d...\n")
subprocess.run("definegeometry2d dg2d.in",shell=True)

defineback.generate_db_input(Nsample)

defineback.generate_plasma_file_with_psi_and_rz(solfile,psirz,tsfile,Rsep,Zsep,TiTe_ratio=TiTe_ratio,bfieldfilename=bfieldfile,ionmass=1.67e-27,hfs_R_lim=0.143942,trapped_fraction=ftrapped,hfs_ne=5.9e15,hfs_Te=11.6)

defineback.generate_db_input(Nsample,"db.in",sourcesp="H")

print("Running defineback...\n")
subprocess.run("defineback db.in",shell=True)

print("Running tallysetup...\n")
subprocess.run("tallysetup",shell=True)

# You may or may not have compiled flighttest with MPI. Obey that here
print("Running flighttest...\n")
subprocess.run("mpirun -np 4 flighttest",shell=True)

R,Z,dens,dens_err,emission,signal,sig_err = postprocess.process_output_with_detectors(plot=True,lymandatafile=lymanfile)
# dens = neutral density 2D profile
# dens_err = relative error of dens
# emission = 2D Lyman profile
# signal = synthetic detectors
# sig_err = relative error estimated for signal

# signal is an array with the strength of the 20 Lyman-alpha detectors
# R and Z are the zone centers, correspondinding to:
# dens: neutral density
# error: estimated relative error in the neutral density
# emission: Lyman-alpha emission as a function of R and Z

#print("Lyman alpha detector signals:")
#print("-----------------------------")
#print("Detector #  |  Strength   | Relative error")
#for i in range(0,len(signal)):
#    print("%d            %.4e     %.4e\n"%(i+1,signal[i],sig_err[i]))

np.savetxt("signals.dat",signal)
