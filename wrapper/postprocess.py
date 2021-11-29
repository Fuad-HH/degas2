import matplotlib.pyplot as plt
import numpy as np
import sys
import netCDF4 as nc
import matplotlib.tri as tri
from importlib import reload

# Returns neutral density and detector signals 
def process_output(outputfilename="output.nc",tallyfilename="tally.nc",geometryfilename="geometry.nc",plot=False,lymandatafile=None):
    outputdata=nc.Dataset(outputfilename)
    tallydata=nc.Dataset(tallyfilename)

    geomdata = nc.Dataset(geometryfilename)
    zone_coords_3D = geomdata["zone_center"]
    zone_type = geomdata["zone_type"]
    x_zone = zone_coords_3D[:][0]
    z_zone = zone_coords_3D[:][2]

    # Find the tally indices to use
    tallynames = tallydata["tally_name"]
    Ntally=len(tallynames)
    dens_idx = -1
    emission_idx = -1
    signal_idx = -1
    for itally in range(0,Ntally):
        if "neutral density" in str(nc.chartostring(tallynames[itally])):
            dens_idx = itally
        elif "Lyman detector view" in str(nc.chartostring(tallynames[itally])):
            signal_idx = itally
        elif "Lyman emission rate" in str(nc.chartostring(tallynames[itally])):
            emission_idx = itally

    # Find the indices of the independent variables
    zone_idx = -1
    det_idx = -1
    varnames = tallydata["tally_var_list"]
    Nvar = len(varnames)
    for ivar in range(0,Nvar):
        if "zone " in str(nc.chartostring(varnames[itally])):
            zone_idx = ivar
        elif "detector " in str(nc.chartostring(varnames[itally])):
            detector_idx = ivar

    dens_base = tallydata["tally_base"][dens_idx]
    signal_base = tallydata["tally_base"][signal_idx]
    emission_base = tallydata["tally_base"][emission_idx]

    # tally_tab_index holds the dimensionality of each tally (Ntally x tally_rank_ind)
    tally_indices = tallydata["tally_tab_index"]

    Ndetector = tally_indices[signal_idx,0]

    max_tally_rank = len(tally_indices[0,:])

    Nzone = tally_indices[dens_idx,0]

    x = []
    z = []
    density = []
    density_err = []
    emission = []
    for izone in range(0,tally_indices[dens_idx,0]):
        if zone_type[izone] == 2:
           x.append(geomdata["zone_center"][izone,0])
           z.append(geomdata["zone_center"][izone,2])
           density.append(outputdata["out_post_all"][dens_base+1*Nzone+izone,0])
           density_err.append(outputdata["out_post_all"][dens_base+1*Nzone+izone,1])
           emission.append(outputdata["out_post_all"][emission_base+izone,0])

    signal = []
    signal_err = []
    for idet in range(0,Ndetector):
        signal.append(outputdata["out_post_all"][signal_base+idet,0])
        signal_err.append(outputdata["out_post_all"][signal_base+idet,1])

    x = np.array(x)
    z = np.array(z)
    density = np.array(density)
    density_err = np.array(density_err)
    emission = np.array(emission)
    signal = np.array(signal)
    signal_err = np.array(signal_err)

    if plot:
        triang = tri.Triangulation(x,z)
        plt.title("Neutral density (m^-3)")
        plt.xlabel("x (m)")
        plt.ylabel("z (m)")
        plt.tricontourf(triang,density)
        plt.colorbar()
        plt.savefig("density.pdf",bbox_inches="tight")
        plt.close()

#        triang = tri.Triangulation(x,z)
#        plt.title("Neutral density (m^-3)")
#        plt.xlabel("x (m)")
#        plt.ylabel("z (m)")
#        plt.tricontourf(triang,np.log(density))
#        plt.colorbar()
#        plt.savefig("logdensity.pdf",bbox_inches="tight")
#        plt.close()


        plt.title("Relative error of neutral density")
        plt.xlabel("x (m)")
        plt.ylabel("z (m)")
        plt.tricontourf(triang,density_err)
        plt.colorbar()
        plt.savefig("error.pdf",bbox_inches="tight")
        plt.close()

        plt.title("Lyman-alpha emission (W / m^2)")
        plt.xlabel("x (m)")
        plt.ylabel("z (m)")
        plt.tricontourf(triang,emission)
        plt.colorbar()
        plt.savefig("emission.pdf",bbox_inches="tight")
        plt.close()

        if lymandatafile:
            xint_raw = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
            f = open(lymandatafile,"rb")
            first = True
            signal_raw = []
            i=0
            for line in f:
                if not first:
                    data = line.split()
                    if data[1] == "nan":
                        xinit_raw.pop(i)
                    else:
                        signal_raw.append(float(data[1]))
                    i+=1
                first=False
            f.close()

            xint_raw = np.array(xint_raw)

            E_per_photon = 6.626e-34*3.0e8/1216.0e-10
            signal_raw = np.array(signal_raw) * E_per_photon
            xint = range(1,len(signal)+1)
            plt.plot(xint_raw,signal_raw,"-o")
            plt.errorbar(xint,signal,yerr=signal*signal_err,fmt="-o",capsize=3)
            plt.xticks(xint)
            plt.xlabel("Detector number")
            plt.ylabel("Predicted signal (W / m^2-sr)") 
            plt.legend(["Observation","DEGAS2"])
            plt.savefig("signals.pdf",bbox_inches="tight")
            plt.close()

    return x,z,density,density_err,emission,signal,signal_err




