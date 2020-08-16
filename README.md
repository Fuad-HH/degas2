This is (currently) a fork of dstotler's DEGAS2 repository. Here, FWEB is included as a dependency.

To install:
- In .bashrc or wherever you set environment variables, Set DEGASROOT to the directory in which you installed DEGAS2 (the directory in which this file is located)
- Full configure scripts are not supported. Instead, make sure your compiler is supported in scripts/templates/Makefile.local
- Navigate to the scripts directory and run (for example, using gfortran on on Mac, with MPI enabled):
   SYSTEM=MACOSX COMPILER=GFORTRAN MPI_OPT=yes ./install_degas2.sh
- This should 
