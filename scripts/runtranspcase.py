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

# Overall parameters
# Options you may want to play with
Nflights=100000

triangle_file_base = "gNSTU.geqdsk_backup_triag"
newformat=False

#triangle_file_base = "solfi_triag"
#newformat=True

recyc_coeff = 0.99

# Initializes the "problem": neutral and plasma species, reactions, and PMI
# Rarely needed, but it runs quickly, so one might as well.
problem.genStdProblem("C")
subprocess.run("problemsetup",shell=True)

# Writes out geometry data
# Also obtains background properties from triangle file.
# Arguments:
# - triangle_file_base: the base name of the .node and .ele files to read data from
# - wall_material: string representing the wall material
# - recyc_coeff: float specifying recycling coefficient
# - ionmass (OPTIONAL keyword, default 1.67e-27): main ion mass in kg (used to calculate cs for Bohm critereon with the source)
ne_zone, Te_zone, Ti_zone, strata, segments, source_strength, zone_map =\
        dg2d.write_dg2d_input_from_triangle_file(triangle_file_base,"C",recyc_coeff,ionmass=1.67e-27,newformat=newformat)

# This is not parallelized and takes a while to run.
# Run this only when the mesh changes.
subprocess.run("~/src/d2test/bin/definegeometry2d dg2d.in",shell=True)

# Overwrites NaN values that are read from triangle file.
# More straightforward to give these a very low density rather than make it a pure vacuum
ne_zone=np.where(np.isnan(ne_zone),1.0e10,ne_zone)  # density in m^-3
Te_zone=np.where(np.isnan(Te_zone),1.0,Te_zone)     # temperature in eV 
Ti_zone=np.where(np.isnan(Ti_zone),1.0,Ti_zone)

# NaN values adjacent to wall are problematic for the source
# Currently zeroing out by removing those segments from the source
idx = np.where(np.isnan(source_strength))
print("Segments thrown out (of a total %d):\n"%len(segments))
print(segments[idx])
source_strength=np.delete(source_strength,idx)
strata=np.delete(strata,idx)
segments=np.delete(segments,idx)

# Writes out basic defineback input file
# Arguments:
# - Nflights: integer for the total number of flight samples. Noise error scales like 1/sqrt(Nflights)
# - sourcesp (OPTIONAL keyword, default "H"): String representing the neutral produced from recycling of the ion "sourcesp+"
# - specify_flux (OPTIONAL keyword, default False): whether the specified source is in units of flux. Need to override default here.

# Writes out plasma and source specification files. Passing as arguments quantities calculated upstream.
defineback.write_plasmafile(ne_zone,Te_zone,Ti_zone)
defineback.generate_sourcefile(strata,segments,source_strength)
sgroups = []
# Recycling source:
sgroups.append( source.Source(Nflights,"plate","H",rootspecies="H+",sourcefile="sourcefile.txt"))

# HFS gas puff on original mesh:
sgroups.append( source.Source(Nflights,"puff","H2",stratum=10986,segment=129,strength=3.6e20,specify_flux=False,pufftemp=300.0))
# on new mesh:
#sgroups.append( source.Source(Nflights,"puff","H2",stratum=15593,segment=160,strength=3.6e20,specify_flux=False,pufftemp=300.0))

# LFS gas puff on original mesh:
sgroups.append( source.Source(Nflights,"puff","H2",stratum=10986,segment=70,strength=4.8e20,specify_flux=False,pufftemp=300.0))
# on new mesh:
#sgroups.append( source.Source(Nflights,"puff","H2",stratum=15593,segment=94,strength=4.8e20,specify_flux=False,pufftemp=300.0))

source.write_db_input(sgroups)

# Processes background and sources into degas2-readable data files
subprocess.run("~/src/d2test/bin/defineback db.in",shell=True)

# Defines which moments/sources are calculated 
subprocess.run("~/src/d2test/bin/tallysetup",shell=True)

# Run the actual Monte Carlo calculation. This also takes a while and is mpi-parallelized. Ensure you are on a compute node.
subprocess.run("mpirun -np 4 ~/src/d2test/bin/flighttest",shell=True)

# Post-process Degas2 results from NetCDF file to .ele file.
# Optionally make other plots?
# Momentum source not implemented yet
# This is total source by zone number 
ndensity, ndensity_err, psource, msource, esource_i, esource_e, zonevols \
        = postprocess.get_density_and_sources()

postprocess.append_tri_file(triangle_file_base+".ele",zone_map,ndensity,psource,esource_i,esource_e,zonevols,newformat=newformat)

