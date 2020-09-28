#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import sys
import h5py

d2filename=sys.argv[1]
uefilename = sys.argv[2]
h5filename = sys.argv[3]

uefile=open(uefilename,'r')
uefile.readline() #first line doesn't have anything

line= uefile.readline().split() #second line contains resolution
Nx=int(line[0])
Ny=int(line[1])

line= uefile.readline().split() #third line contains location of separatrix
ix_sep=int(line[0])
iy_sep=int(line[1])

line= uefile.readline().split() #nothing usefule on fourth line

Rall = [float(x) for x in uefile.readline().split()] 
Zall = [float(x) for x in uefile.readline().split()] 

# Get the centers of all cells
R_c = np.reshape(Rall[0:Nx*Ny],[Ny,Nx]).transpose()
Z_c = np.reshape(Zall[0:Nx*Ny],[Ny,Nx]).transpose()

# Find the midplane (inboard and outboard) x indices
# These are two indices are those with the highest Z values on one side of the cell or the other
R_ur = np.reshape(Rall[4*Nx*Ny:5*Nx*Ny],[Ny,Nx]).transpose()
Z_ur = np.reshape(Zall[4*Nx*Ny:5*Nx*Ny],[Ny,Nx]).transpose()
R_ul = np.reshape(Rall[3*Nx*Ny:4*Nx*Ny],[Ny,Nx]).transpose()
Z_ul = np.reshape(Zall[3*Nx*Ny:4*Nx*Ny],[Ny,Nx]).transpose()
ix_imp = np.argmax(Z_ur[:,0])
ix_omp = np.argmax(Z_ul[:,0])

Rsep_inner = R_ur[ix_imp,iy_sep-1]
Rsep_outer = R_ul[ix_omp,iy_sep-1]

Rwall_inner = R_ur[0,iy_sep-1]
Zwall_inner = Z_ur[0,iy_sep-1]
Rwall_outer = R_ul[-1,iy_sep-1]
Zwall_outer = Z_ul[-1,iy_sep-1]

#Magnetic field on next three lines
line= uefile.readline().split()
line= uefile.readline().split() 
line= uefile.readline().split()

ni = np.reshape( [float(x) for x in uefile.readline().split()], [Ny,Nx]).transpose()

#velocity vector
line= uefile.readline().split()
line= uefile.readline().split() 
line= uefile.readline().split()

Ti = np.reshape( [float(x) for x in uefile.readline().split()], [Ny,Nx]).transpose()
Te = np.reshape( [float(x) for x in uefile.readline().split()], [Ny,Nx]).transpose()

uefile.close()


d2file=open(d2filename,'r')

line= d2file.readline().split()
if int(line[0]) != Nx or int(line[1]) != Ny:
    sys.exit("Files not compatible in dimensions.")
Nspec = int(line[2])

speclabels=[]

neutral_density = np.zeros([Nx,Ny,Nspec])
neutral_temperature = np.zeros([Nx,Ny,Nspec])
neutral_flux = np.zeros([Nx,Ny,3,Nspec])

for ispec in range(0,Nspec):
    speclabels.append(d2file.readline().strip())

for ispec in range(0,Nspec):
    # Density
    for iy in range(0,Ny):
        #Data comes in 5s
        for iline in range(0,int(Nx/5)):
            neutral_density[iline*5:(iline+1)*5,iy,ispec] = [float(x) for x in d2file.readline().split()]
        neutral_density[-(Nx%5):,iy,ispec] = [float(x) for x in d2file.readline().split()]

    # Temperature
    for iy in range(0,Ny):
        #Data comes in 5s
        for iline in range(0,int(Nx/5)):
            neutral_temperature[iline*5:(iline+1)*5,iy,ispec] = [float(x) for x in d2file.readline().split()]
        neutral_temperature[-(Nx%5):,iy,ispec] = [float(x) for x in d2file.readline().split()]
        
#    # Flux vector 
#    for icomp in range(0,3):
#        for iy in range(0,Ny):
#            #Data comes in 5s
#            for iline in range(0,int(Nx/5)):
#                neutral_flux[iline*5:(iline+1)*5,iy,icomp,ispec] = [float(x) for x in d2file.readline().split()]
#            neutral_flux[-1-(Nx%5):-1,iy,icomp,ispec] = [float(x) for x in d2file.readline().split()]

d2file.close()

f = h5py.File('base_pcore5MW.h5','r')
nn_ue = f['bbb']['ng'][()]
Tn_ue = f['bbb']['tg'][()]

el=1.602e-19

Nspec=2
speclabels = speclabels[0:2]

# Along inner separatrix
distanceToPlot = 0.04
inner_dist = np.sqrt( (R_c[:,iy_sep] - Rwall_inner)**2 + (Z_c[:,iy_sep] - Zwall_inner)**2 )  
idx = np.argmin(abs(inner_dist-distanceToPlot))
inner_dist = inner_dist[0:idx]
nInnerLeg = neutral_density[0:idx,iy_sep,:]
TInnerLeg = neutral_temperature[0:idx,iy_sep,:]

outer_dist = np.sqrt( (R_c[:,iy_sep] - Rwall_outer)**2 + (Z_c[:,iy_sep] - Zwall_outer)**2 )  
idx = np.argmin(abs(outer_dist-distanceToPlot))
outer_dist = outer_dist[idx:-1]
nOuterLeg = neutral_density[idx:-1,iy_sep,:]
TOuterLeg = neutral_temperature[idx:-1,iy_sep,:]


for ispec in range(0,Nspec):
    plt.plot(inner_dist*1000.0,nInnerLeg[:,ispec])
plt.legend(speclabels)
plt.title("Along inner separatrix leg")
plt.xlabel("Distance to wall (mm)")
plt.ylabel(r"$n$ ($\mathrm{m}^{-3}$)")
plt.savefig("n_ileg.pdf")
plt.clf()

for ispec in range(0,Nspec):
    plt.plot(inner_dist*1000.0,TInnerLeg[:,ispec]/el)
plt.legend(speclabels)
plt.title("Along inner separatrix leg")
plt.xlabel("Distance to wall (mm)")
plt.ylabel(r"$T$ (eV)")
plt.savefig("T_ileg.pdf")
plt.clf()

# Along outer separatrix
for ispec in range(0,Nspec):
    plt.plot(outer_dist*1000.0,nOuterLeg[:,ispec])
plt.legend(speclabels)
plt.title("Along outer separatrix leg")
plt.xlabel("Distance to wall (mm)")
plt.ylabel(r"$n$ ($\mathrm{m}^{-3}$)")
plt.savefig("n_oleg.pdf")
plt.clf()

for ispec in range(0,Nspec):
    plt.plot(outer_dist*1000.0,TOuterLeg[:,ispec]/el)
plt.legend(speclabels)
plt.title("Along outer separatrix leg")
plt.xlabel("Distance to wall (mm)")
plt.ylabel(r"$T$ (eV)")
plt.savefig("T_oleg.pdf")
plt.clf()




# Inboard midplane
for ispec in range(0,Nspec):
    plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,neutral_density[ix_imp,:,ispec])
    print(neutral_density[ix_imp,:,ispec])
#plt.plot(R_c[ix_imp,:]-Rsep_inner,ni[ix_imp,:])
plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,nn_ue[ix_imp+1,1:-1],":")
plt.legend(speclabels+["UEDGE"])
plt.title("Inboard midplane")
plt.xlabel(r"$R - R_\mathrm{omp}$ (mm)")
plt.ylabel(r"$n$ ($\mathrm{m}^{-3}$)")
plt.savefig("n_imp.pdf")
plt.clf()

for ispec in range(0,Nspec):
    plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,neutral_temperature[ix_imp,:,ispec]/el)
plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,Ti[ix_imp,:]/el)
plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,Tn_ue[ix_imp+1,1:-1]/el,":")
plt.legend(speclabels+["Ions","UEDGE"])
plt.title("Inboard midplane")
plt.xlabel(r"$R - R_\mathrm{sep}$ (mm)")
plt.ylabel(r"$T$ (eV)")
plt.savefig("T_imp.pdf")
plt.clf()

# Outboard midplane
for ispec in range(0,Nspec):
    plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,neutral_density[ix_omp,:,ispec])
#plt.plot(R_c[ix_omp,:]-Rsep_outer,ni[ix_omp,:])
plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,nn_ue[ix_omp+1,1:-1],":")
plt.legend(speclabels+["UEDGE"])
plt.title("Outboard midplane")
plt.xlabel(r"$R - R_\mathrm{omp}$ (mm)")
plt.ylabel(r"$n$ ($\mathrm{m}^{-3}$)")
plt.savefig("n_omp.pdf")
plt.clf()

for ispec in range(0,Nspec):
    plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,neutral_temperature[ix_omp,:,ispec]/el)
plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,Ti[ix_omp,:]/el)
plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,Tn_ue[ix_omp+1,1:-1]/el,":")
plt.title("Outboard midplane")
plt.legend(speclabels+["Ions","UEDGE"])
plt.xlabel(r"$R - R_\mathrm{sep}$ (mm)")
plt.ylabel(r"$T$ (eV)")
plt.savefig("T_omp.pdf")
plt.clf()

# Inner target
for ispec in range(0,Nspec):
    plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,neutral_density[0,:,ispec])
#plt.plot(R_c[ix_imp,:]-Rsep_inner,ni[0,:])
plt.title("Inner target")
plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,nn_ue[1,1:-1],":")
plt.legend(speclabels+["UEDGE"])
plt.xlabel(r"$R - R_\mathrm{sep}$ (mm)")
plt.ylabel(r"$n$ ($\mathrm{m}^{-3}$)")
plt.savefig("n_it.pdf")
plt.clf()

for ispec in range(0,Nspec):
    plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,neutral_temperature[0,:,ispec]/el)
plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,Ti[0,:]/el)
plt.plot((R_c[ix_imp,:]-Rsep_inner)*1000.0,Tn_ue[1,1:-1]/el,":")
plt.legend(speclabels+["Ions"]+["UEDGE"])
plt.title("Inner target")
plt.xlabel(r"$R - R_\mathrm{sep}$ (mm)")
plt.ylabel(r"$T$ (eV)")
plt.savefig("T_it.pdf")
plt.clf()

# Outer target
for ispec in range(0,Nspec):
    plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,neutral_density[-1,:,ispec])
#plt.plot(R_c[ix_omp,:]-Rsep_outer,ni[-1,:])
plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,nn_ue[-2,1:-1],":")
plt.legend(speclabels+["UEDGE"])
plt.title("Outer target")
plt.xlabel(r"$R - R_\mathrm{sep}$ (mm)")
plt.ylabel(r"$n$ ($\mathrm{m}^{-3}$)")
plt.savefig("n_ot.pdf")
plt.clf()

for ispec in range(0,Nspec):
    plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,neutral_temperature[-1,:,ispec]/el)
plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,Ti[-1,:]/el)
plt.plot((R_c[ix_omp,:]-Rsep_outer)*1000.0,Tn_ue[-2,1:-1]/el,":")
plt.legend(speclabels+["Ions","UEDGE"])
plt.title("Outer target")
plt.xlabel(r"$R - R_\mathrm{sep}$ (mm)")
plt.ylabel(r"$T$ (eV)")
plt.savefig("T_ot.pdf")
plt.clf()

