# An example for using these scripts. Will call degas2 executables as needed, so ensure that they are in your $PATH
# Also, make sure degas2/scripts is in your $PYTHONPATH
# To use as-is, run in your working directory. Otherwise, just use this as a template to copy into your own scripts
import os
import subprocess
import dg2d
import problem
import source
import defineback
import postprocess
import numpy as np
import scipy.interpolate as interpolate
import netCDF4 as nc

# >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
# POPULATE THESE ARRAYS WITH APPROPRIATE PLASMA DATA
#
psi_data = [0.0,1.0,2.0]
ne_data = [1.0e20,1.0e19,1.0e18]
Te_data = [10000.0,100.0,1.0]
Ti_data = [10000.0,200.0,10.0]
#
# <<<<<<<<<<<<<<<<<<<<<<<<<<<<<


# File containing magnetic equilibrium data
eqdsk_file = "g186414_03700_FwdBt.g"

# Recycling coefficient
recyc = 0.98

# Wall Material
material = "C"

# Wall temperature in Kelvin
walltemp = 300.0

# The number of flight samples
Nsample = 100000

p = problem.genStdProblem("C-D")
print("Running problemsetup...\n")
subprocess.run("$HOME/src/degas2/build-micer/bin/problemsetup",shell=True)

# dlim_max gives the maximum distance defined along limiter for triangulation, in meters. Roughly sets spatial resolution.

psifunc,nodes = dg2d.generateGeometryFromEFITfile(eqdsk_file,material,recyc_coef=recyc,Twall=walltemp,dlim_max=0.02,clockwise=True)

#print("Running definegeometry2d...\n")
#subprocess.run("$HOME/src/degas2/build-micer/bin/definegeometry2d dg2d.in",shell=True)

#defineback.generate_plasma_file_through_psi(ne_data,Te_data,Ti_data,psifunc,psi_data=psi_data)

# This will produce a "puff" type source at a temperature of 1eV uniformly around limiter at a strength of
# 1.0e24 nuclei per m^2 per s. Using Nsample flights and treating as a 
sgroup = source.Source(Nsample,"puff","D",rootspecies="D",strength=1.0e24,stratum=3,segment="*")
# This treats the source as if it's recycling, same flux as above, energy distribution of produced neturals
# are determined by ions near the wall and the recycling properies of the PFC.
#sgroup = source.Source(Nsample,"plate","D",rootspecies="D+",strength=1.0e24,stratum=3,segment="*")

source.write_db_input([sgroup])
#defineback.generate_db_input(Nsample)

print("Running defineback...\n")
subprocess.run("$HOME/src/degas2/build-micer/bin/defineback db.in",shell=True)

# Use supplied tally.in file
print("Running tallysetup...\n")
subprocess.run("$HOME/src/degas2/build-micer/bin/tallysetup",shell=True)

# You may or may not have compiled flighttest with MPI. Obey that here
print("Running flighttest...\n")
subprocess.run("mpirun -np 4 $HOME/src/degas2/build-micer/bin/flighttest",shell=True)

spectrum,spectrum_errs = postprocess.get_output("MICER spectrum",with_err=True)

signal,signal_errs = postprocess.get_output("MICER total",with_err=True)

