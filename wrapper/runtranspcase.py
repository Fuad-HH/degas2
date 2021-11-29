import dg2d
import defineback
import subprocess
import numpy as np

# Overall parameters
Nflights=100000
triangle_file = "gNSTU.geqdsk_backup_triag"

# Writes out geometry data
ne_zone, Te_zone, Ti_zone, wall_strata, source_strength =\
        dg2d.write_dg2d_input_from_triangle_file(triangle_file,"C",0.9,ionmass=1.67e-27)
#subprocess.run("definegeometry2d dg2d.in",shell=True)

# Writes out plasma data
# Basic input file
#defineback.generate_db_input(Nflights,sourcesp="H")

#defineback.write_plasmafile("plasmafile",ne_zone,Te_zone,Ti_zone)
#defineback.generate_sourcefile(wall_strata,np.zeros(len(wall_strata),dtype=int),source_strength,sourcefilename="sourcefile")

#subprocess.run("defineback db.in",shell=True)



