#!/bin/env python3
import sys
import f90nml
import numpy as np

filename=sys.argv[1]
try:
    namelist=f90nml.read(filename)
except:
    sys.exit('Failed to read xgc input file. Check path and filename.')

try:
    neu_recycle_rate = namelist['neu_param']['neu_recycle_rate']
except:
    neu_recycle_rate = 0.9

print(neu_recycle_rate)
