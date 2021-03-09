This is (currently) a fork of dstotler's DEGAS2 repository. 

NetCDF is required as a dependency. FWEB and Silo are included in this repository.

To install:
- In .bashrc or wherever you set environment variables, Set DEGASROOT to the directory in which you installed DEGAS2 (the directory in which this file is located)
- Robust configure scripts are not yet supported. Instead, make sure your compiler is supported in scripts/templates/Makefile.local
- Navigate to the scripts directory and run (for example, using gfortran on on Mac, with MPI enabled):
   SYSTEM=MACOSX COMPILER=GFORTRAN MPI_OPT=yes GCC10_OPT=yes ./install_degas2.sh
- This should compile the most common executables and provide an example set of input files in the MACOSX directory. For other SYSTEMs like LINUX64 (the defualt) or SUN, see the manual).
- If the script cannot find your NetCDF library, include the environment variable NETCDF_HOME=/path/to/netcdf/lib
- For more details see the user manual (Doc/degas2_all.pdf) and the getting started guide (doc/Running_degas2_at_PPPL.txt).
