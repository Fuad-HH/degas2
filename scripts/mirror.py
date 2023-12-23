import polygon
import numpy as np
import dg2d
import problem
import defineback
import source
import postprocess
import matplotlib.pyplot as plt
import subprocess

def generate_input_files(Nx,Nz,Lx,Lz,ne_func,Te_func,Ti_func,ui_func=None,material="mirror",temperature=300.0,Rcoeff=1.0,sourcerate=None,sourceflux=None,Nflights=10000,xmin=0.003):
    """
    Generates necessary input files for degas2 in a rectangular R,Z mesh

    Args:
        Nx: The number of finite volumes in the x (radial) direction
        Nz: The number of finite volumes in the z (axial) direction
        Lx: Radius of the domain, in meters.
        Lz: Axial length of the domain, in meters.
        ne_func: Function that takes as arguments (R,Z) in meters, and returns electron density (=ion density) in m^-3.
        Te_func: Function that takes as arguments (R,Z) in meters, and returns electron tempearture in eV. 
        Ti_func: Function that takes as arguments (R,Z) in meters, and returns ion tempearture in eV. 
        ui_func: (optional) Function that takes as arguments (R,Z) in meters and returns polar velocity in m/s.
        material: (optional) String representing wall material. Currently only "mirror", "C", and "Fe" are automated. Default "mirror" (specular reflection).
        temperature: (optional) Wall temperature (in Kelvin)
        Rcoeff: (optional) Recycling coefficient
        sourcerate: (optional) Total rate of neutral production in nuclei/s (one of sourcerate or sourceflux needs to be specified)
        sourceflux: (optional) Total flux of neutral production in nuclei/m^2/s (one of sourcerate or sourceflux needs to be specified)
        Nflights: (optional) Integer number of trajectory samples. Default=10000.
        xmin: (optional) Due to how 2D grids are currently generated, one cannot go all the way to the axis. This parameter controls the minimal radius (which is effectively treated as a vacuum)
    Returns:
        x_center: Centers of grid volumes in the x (radial) direction (weighted by volume); to be used for plotting.
        z_center: Centers of grid volumes in the z direction; to be used for plotting. 
    """

    x_corner = np.linspace(0.0,Lx,Nx+1)
    z_corner = np.linspace(0.0,Lz,Nz+1)
    x_corner[0] = xmin

    x_corner,z_corner = np.meshgrid(x_corner,z_corner,indexing="ij")

    nodes, polys, centers = polygon.get_polys_from_corners(x_corner,z_corner)

    dg2d.write_wallfile(nodes)

    Xmin = 0.5*np.min(x_corner)
    Xmax = np.max(x_corner)+Xmin
    Lz = np.max(z_corner) - np.min(z_corner)
    Zmin = np.min(z_corner) - Xmin
    Zmax = np.max(z_corner) + Xmin

    dg2d_infile = open("dg2d.in","w")
    dg2d.write_dg2d_header(dg2d_infile,"cylindrical",Xmin,Xmax,Zmin,Zmax)

    ipoly = 0
    for poly in polys:
        ipoly += 1
        poly.write_plasma_polygon_dg2d(dg2d_infile,stratum=ipoly,wallid=1,commonzone=True,newzone=True)
    
    dg2d_infile.write("new_zone solid \n")
    dg2d_infile.write("new_polygon \n")
    dg2d_infile.write("  stratum %d \n"%(len(polys)+1))
    dg2d_infile.write("  material mirror\n")
    dg2d_infile.write("  recyc_coef 1.0 \n")
    dg2d_infile.write("  outer 0 1 \n")
    for iz in range(0,Nz+1):
        # Leftmost wall; reflective surface. Downward ix=0
        dg2d_infile.write("  wall 1 %d %d\n"%(Nz-iz,Nz-iz))
    dg2d_infile.write("  triangulate_polygon \n")
    
    
    dg2d_infile.write("new_zone exit \n")
    dg2d_infile.write("new_polygon \n")
    dg2d_infile.write("  stratum %d \n"%(len(polys)+2))
    dg2d_infile.write("  outer 1 2 \n")
    for ix in range(0,Nx+1):
        # Topmost wall; exit. Leftward iz=Nz-1
        idx = (Nx-ix)*(Nz+1) + Nz 
        dg2d_infile.write("  wall 1 %d %d\n"%(idx,idx))
    dg2d_infile.write("  triangulate_polygon \n")
    
    dg2d_infile.write("new_zone solid \n")
    dg2d_infile.write("new_polygon \n")
    dg2d_infile.write("  material "+material+" \n")
    dg2d_infile.write("  recyc_coef %f \n"%Rcoeff)
    dg2d_infile.write("  temperature %f \n"%temperature)
    dg2d_infile.write("  stratum %d \n"%(len(polys)+3))
    for iz in range(0,Nz+1):
        # Rightmost wall; recycling surface. Upward ix=Nx-1
        dg2d_infile.write("  wall 1 %d %d\n"%((Nz+1)*(Nx)+iz,(Nz+1)*(Nx)+iz))
    dg2d_infile.write("  outer 2 3 \n")
    dg2d_infile.write("  triangulate_polygon \n")
    
    dg2d_infile.write("new_zone exit\n")
    dg2d_infile.write("new_polygon \n")
    dg2d_infile.write("  stratum %d \n"%(len(polys)+4))
    dg2d_infile.write("  outer 3 4 \n")
    for ix in range(0,Nx+1):
        # Bottommost wall; exit. Rightward iz=0
        dg2d_infile.write("  wall 1 %d %d\n"%(ix*(Nz+1),ix*(Nz+1)))
    dg2d_infile.write("  triangulate_polygon \n")
    dg2d_infile.write("\npolygon_nc_file polygon.nc\nend\n")
    dg2d_infile.close()

    mats = [material,"mirror"]
    if material == "mirror":
        mats = ["mirror"]
        pmis = ["hmirror"]
    elif material == "Fe":
        pmis = ["h_des_maxw_fe","h2_des_maxw_fe","hreflfe","hmirror","h2mirror"]
    elif material == "C":
        pmis = ["hdesorbc","h2desorbc","hreflc"]

    if material == "mirror":
        p = problem.generateProblemInput(["0","H"],["e","H+"],["hionize5","hh_chargex"],mats,pmis)
    else:
        p = problem.generateProblemInput(["0","H","H2","H2+"],["e","H+"],["hionize5","hh_chargex","h2dis","h2ion","h2dision","h2pdision","h2pdis","h2pdisrec"],mats,pmis)

    x_center = np.zeros(Nx*Nz)
    z_center = np.zeros(Nx*Nz)
    ne_zone = np.zeros(Nx*Nz)
    Te_zone = np.zeros(Nx*Nz)
    Ti_zone = np.zeros(Nx*Nz)
    ui_zone = np.zeros(Nx*Nz)
    for ix in range(0,Nx):
        for iz in range(0,Nz):
            idx = ix*Nz+iz
            z_center[idx] = 0.5*(z_corner[0,iz] + z_corner[0,iz+1])
            x_center[idx] = np.sqrt( 0.5 * (x_corner[ix,0]**2 + x_corner[ix+1,0]**2) )
            ne_zone[idx] = ne_func(x_center[idx],z_center[idx])
            Te_zone[idx] = Te_func(x_center[idx],z_center[idx])
            Ti_zone[idx] = Ti_func(x_center[idx],z_center[idx])
            if not ui_func == None:
                ui_zone[idx] = ui_func(x_center[idx],z_center[idx])

    defineback.write_plasmafile(ne_zone,Te_zone,Ti_zone,uy_zone=ui_zone)

    if sourceflux == None:
        if sourcerate == None:
            print("ERROR: One of sourceflux or sourcerate needs to be specified")
        else:
            Sflux = sourcerate/((np.max(z_corner)-np.min(z_corner))*2.0*np.pi*np.max(x_corner))
    else:
        Sflux = sourceflux

    s = source.Source(1000000,"plate","H","H+",specify_flux=True)

    defineback.generate_sourcefile([len(polys)+3]*Nz,np.linspace(0,Nz-1,num=Nz,dtype=int),[Sflux]*Nz,sourcefilename=s.sourcefile)

    source.write_db_input([s])

    return x_center, z_center

def run_case(run_geo=True,run_flighttest=True,n_mpi=1,dir=""):
    """
    Runs sequence of executables.

    Args:
        run_geo: (optional) If false, skips definegeometry2d assuming mesh has already been generated
        run_flighttest: (optional) If false, skips flighttest (only post-processes an already-run case)
        n_mpi: (optional) Number of MPI processes to run. If > 1, flighttest must have been compiled with USE_MPI=ON
        dir: (optional) Absolute path to degas2 binaries if not in $PATH. String must end with "/"
    """

    subprocess.run(dir+"problemsetup",shell=True)
    if (run_geo):
        subprocess.run(dir+"definegeometry2d dg2d.in",shell=True)
    subprocess.run(dir+"defineback db.in",shell=True)
    subprocess.run(dir+"tallysetup",shell=True)
    if (run_flighttest):
        if (n_mpi > 1):
            subprocess.run("mpirun -np %d "%Nflights+dir+"flighttest",shell=True)
        else:
            subprocess.run(dir+"flighttest",shell=True)
    subprocess.run(dir+"ucd_plot polygon.nc",shell=True)


