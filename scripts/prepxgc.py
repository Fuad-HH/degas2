# Setup:
# $ git pull git@github.com:gjwilkie/degas2.git
# $ mkdir degas2/build; cd degas2/build
# $ cmake ..
# $ make datasetup
# $ make problemsetup
# $ make definegeometry2d
# $ make defineback
# $ make tallysetup
# $ make flighttest
# Add: export PATH=[degas2_parent_dir]/degas2/bin:$PATH 
# and: export PYTHONPATH=[degas2_parent_dir]/degas2/pyscripts:$PYTHONPATH
# to ~/.bashrc and run "source ~/.bashrc"
# In working directory (where this script is run), copy the files degas2.in, problem.in, and tally.in, and run:
# $ datasetup

# Required libraries/modules: netcdf, cmake, openmpi
# On PPPL cluster:
# module load gcc openmpi szip hdf5-parallel netcdf-c netcdf-fortran silo cmake
# Required python packages: numpy, matplotlib, netCDF4, scipy, shapely
import dg2d
import defineback
import subprocess
import problem
import postprocess
import numpy as np
import source
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm

# Overall parameters
# Options you may want to play with
Nflights=100000

trifile_base = "fwdBt"

#triangle_file_base = "nstu_triag"
#newformat=True

recyc_coeff = 0.99

# Initializes the "problem": neutral and plasma species, reactions, and PMI
# Rarely needed after initializing, but it runs quickly, so one might as well.
pr = problem.generateProblemInput(["0","D"],["e","D+"],["hionize5","dd_chargex"],["C"],["hdesorbc_xgc","dreflc"])
subprocess.run("problemsetup",shell=True)

# Writes out geometry data
# Also obtains background properties from triangle file.
# Arguments:
# - triangle_file_base: the base name of the .node and .ele files to read data from
# - wall_material: string representing the wall material
# - recyc_coeff: float specifying recycling coefficient
# - ionmass (OPTIONAL keyword, default 1.67e-27): main ion mass in kg (used to calculate cs for Bohm critereon with the source)

strata, segments, source_strength, triang =\
 dg2d.write_dg2d_input_from_simple_triangle_file(trifile_base,"C",0.99,dg2dfile_name="dg2d.in",polygon_filename="polygons.nc",debug=False,ionmass=1.67e-27)

# This is not parallelized and takes a while to run.
# Run this only when the mesh changes.
subprocess.run("definegeometry2d dg2d.in",shell=True)

# Writes out basic defineback input file
# Arguments:
# - Nflights: integer for the total number of flight samples. Noise error scales like 1/sqrt(Nflights)
# - sourcesp (OPTIONAL keyword, default "H"): String representing the neutral produced from recycling of the ion "sourcesp+"
# - specify_flux (OPTIONAL keyword, default False): whether the specified source is in units of flux. Need to override default here.

nzone = len(triang.triangles[:,0])
ne_zone = np.ones(nzone)*1.0e19
Te_zone = np.ones(nzone)*100.0
Ti_zone = np.ones(nzone)*100.0

# Writes out plasma and source specification files. Passing as arguments quantities calculated upstream.
defineback.write_plasmafile(ne_zone,Te_zone,Ti_zone)
defineback.generate_sourcefile(strata,segments,source_strength)
sgroups = []
# Recycling source:
sgroups.append( source.Source(Nflights,"plate","D",rootspecies="D+",sourcefile="sourcefile.txt"))

source.write_db_input(sgroups)

# Processes background and sources into degas2-readable data files
subprocess.run("defineback db.in",shell=True)

# Defines which moments/sources are calculated 
subprocess.run("tallysetup",shell=True)

# Run the actual Monte Carlo calculation. This also takes a while and is mpi-parallelized. Ensure you are on a compute node.
subprocess.run("mpirun -np 4 flighttest",shell=True)

# Post-process Degas2 results from NetCDF file to .ele file.
# Optionally make other plots?
# Momentum source not implemented yet
# This is total source by zone number 
ndensity, ndensity_err, psource, msource, esource_i, esource_e, zonevols \
        = postprocess.get_density_and_sources()

subprocess.run("ucd_plot polygon.nc",shell=True)

triang,Ntri = dg2d.get_triangulation_from_polygons("polygon.nc")


