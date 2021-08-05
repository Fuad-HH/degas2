import dg2d
import defineback
import netCDF4 as nc
import numpy as np

# Outputs neutral density and temperature from netcdf output
# Assumes first len(rgrid) zones are the ones of interest
def process_output(rgrid,outputfilename="output.nc",tallyfilename="tally.nc",geometryfilename="tally.nc",plot=False,asciioutfilename=None):
    outputdata=nc.Dataset(outputfilename)
    tallydata=nc.Dataset(tallyfilename)

    # Find the tally indicee to use
    tallynames = tallydata["tally_name"]
    Ntally=len(tallynames)
    dens_idx = -1
    pres_idx = -1
    flux_idx = -1
    for itally in range(0,Ntally):
        if "neutral density" in str(nc.chartostring(tallynames[itally])):
            dens_idx = itally
        elif "neutral pressure" in str(nc.chartostring(tallynames[itally])):
            pres_idx = itally
        elif "neutral flux vector" in str(nc.chartostring(tallynames[itally])):
            flux_idx = itally

    # Find the indicee of the independent variables
    zone_idx = -1
    testsp_idx = -1
    sp_idx = -1
    rc_idx = -1
    varnames = tallydata["tally_var_list"]
    Nvar = len(varnames)
    for ivar in range(0,Nvar):
        if "zone " in str(nc.chartostring(varnames[itally])):
            zone_idx = ivar
        elif "test " in str(nc.chartostring(varnames[itally])):
            testsp_idx = ivar
        elif "problem_sp" in str(nc.chartostring(varnames[itally])):
            sp_idx = ivar
        elif "reaction" in str(nc.chartostring(varnames[itally])):
            rc_idx = ivar

    dens_base = tallydata["tally_base"][dens_idx]
    pres_base = tallydata["tally_base"][pres_idx]
    flux_base = tallydata["tally_base"][flux_idx]

    # tally_tab_index holds the dimensionality of each tally (Ntally x tally_rank_ind)
    tally_indices = tallydata["tally_tab_index"]

    max_tally_rank = len(tally_indices[0,:])

    Nzone = tally_indices[dens_idx,0]
    NR=len(rgrid)

    density = []
    pressure = []
    molec_density = []
    molec_pressure = []
    density_err = []
    pressure_err = []
    molec_density_err = []
    molec_pressure_err = []
    for izone in range(0,NR):
        density.append(outputdata["out_post_all"][dens_base+1*Nzone+izone,0])
        pressure.append(outputdata["out_post_all"][pres_base+1*Nzone+izone,0])
        molec_density.append(outputdata["out_post_all"][dens_base+2*Nzone+izone,0])
        molec_pressure.append(outputdata["out_post_all"][pres_base+2*Nzone+izone,0])
        density_err.append(outputdata["out_post_all"][dens_base+1*Nzone+izone,1])
        pressure_err.append(outputdata["out_post_all"][pres_base+1*Nzone+izone,1])
        molec_density_err.append(outputdata["out_post_all"][dens_base+2*Nzone+izone,1])
        molec_pressure_err.append(outputdata["out_post_all"][pres_base+2*Nzone+izone,1])

    density = np.array(density)
    pressure = np.array(pressure)
    molec_density = np.array(molec_density)
    molec_pressure = np.array(molec_pressure)
    density_err = np.array(density_err)
    pressure_err = np.array(pressure_err)
    molec_density_err = np.array(molec_density_err)
    molec_pressure_err = np.array(molec_pressure_err)

    if asciioutfilename:
        f = open(asciioutfilename,"w")
        f.write("#%14s %15s %15s %15s %15s %15s %15s %15s %15s %15s \n"%\
                ("izone","radius (m)","n_H (m^-3)", "rel. err.","n_H2", "rel. err.", "p_H (Pa)","rel. err.","p_H2","rel. err.") )
        for i in range(0,NR):
            f.write("%15d %15e %15e %15e %15e %15e %15e %15e %15e %15e \n"%\
                    (i,rgrid[i],density[i],density_err[i], \
                    molec_density[i],molec_density_err[i], \
                    pressure[i],pressure_err[i],\
                    molec_pressure[i],molec_pressure_err[i]))
        f.close()


    return density,molec_density,pressure,molec_pressure


def write_cylinder_input(R_tot,NR,eource,ne,Te,material,TiTe_ratio=1.0,Nflights=10000,Ntheta_min=12,Ntheta_max=200,walltemp=300.0):
    rgrid = dg2d.write_cylinder_dg2d_input(R_tot,NR,material,Ntheta_min=Ntheta_min,Ntheta_max=Ntheta_max,walltemp=walltemp)

    defineback.write_cylinder_db_input(rgrid,ne,Te,TiTe_ratio,eource,R_tot,NR,Nflights,walltemp=walltemp)
    return rgrid

