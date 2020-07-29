#!/bin/env python3
import sys
import numpy as np

filename=sys.argv[1]

iline =0
file = open(nodefilename)
for line in file:
    if iline == 0:
        nnode = int(line.split()[0])
        Rarray = np.zeros(nnode)
        Zarray = np.zeros(nnode)
    elif iline+1 <= nnode:
        Rarray[iline-1] = line.split()[1]
        Zarray[iline-1] = line.split()[2]
    iline+=1
file.close()

rmin = np.min(Rarray)
rmax = np.max(Rarray)
zmin = np.min(Zarray)
zmax = np.max(Zarray)

dr = 0.2*(rmax-rmin)
dz = 0.2*(zmax-zmin)

rmin = rmin-dr
rmax = rmax+dr
zmin = zmin-dz
zmax = zmax+dz

stdout=sys.stdout
sys.stdout=open('/tmp/RMIN','w')
print(rmin)
sys.stdout=open('/tmp/RMAX','w')
print(rmax)
sys.stdout=open('/tmp/ZMIN','w')
print(zmin)
sys.stdout=open('/tmp/ZMAX','w')
print(zmax)
