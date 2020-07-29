#!/bin/env python3
import sys
import f90nml

filename=sys.argv[1]
namelist=f90nml.read(filename)

try:
    neu_en_bin_num = namelist['neu_param']['neu_en_bin_num']
except:
    neu_en_bin_num = 16

print(neu_en_bin_num)
