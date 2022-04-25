#!/bin/env python3
import sys
import f90nml

filename=sys.argv[1]
namelist=f90nml.read(filename)

try:
    neu_ptl_num = namelist['neu_param']['neu_ptl_num']
except:
    neu_ptl_num = 9600

print(neu_ptl_num)
