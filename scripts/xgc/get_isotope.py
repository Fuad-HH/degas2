#!/bin/env python3
import sys
import f90nml

mass_eps = 1.0e-3

filename=sys.argv[1]

namelist=f90nml.read(filename)

ptl_mass_au = namelist['ptl_param']['ptl_mass_au']

if abs(ptl_mass_au - 1.0) < mass_eps:
    ion_species='H'
elif abs(ptl_mass_au - 2.0) < mass_eps:
    ion_species='D'
else:
    sys.exit('Ion species not recognized from ptl_mass_au.')

print(ion_species)

