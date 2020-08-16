#!/bin/sh
# Sets up the environment for running degas2
#
# Usage, from this directory:
# ./setup_degas2_environment SYSTEM COMPILER
# where SYSTEM is the degas2-specified system (LINUX64 by default), 
# and COMPILER is the compiler to use (gfortran by default)

if [ $# -eq 0 ]
then
   SYSTEM=LINUX64
   COMPILER=gfortran
elif [ $# -eq 1 ]
   SYSTEM=$1
   COMPILER=gfortran
else
   SYSTEM=$1
   COMPILER=$2
fi

if [-z "$SYSTEM"]
then
   SYSTEM=LINUX64
fi

if [-z "$COMPILER"]
then
   COMPILER=gfortran
fi

if [-z "$MPI_OPT"]
then
   MPI_OPT=no
fi

cd ..
export DEGASROOT=$PWD/$SYSTEM
echo $SYSTEM > this_system
mkdir $SYSTEM
cd $SYSTEM
cp src/Makefile $SYSTEM/

if [ $?NETCDF_C_HOME ]
then
   NCLIB=-L$NETCDF_C_HOME -lnetcdf
   if [ $?NETCDF_FORTRAN_HOME ]
      NCLIB=-L$NETCDF_FORTRAN_HOME -lnetcdff
   else
      echo "Need to specify NETCDF_FORTRAN_HOME along with NETCDF_C_HOME"
   fi
elif [ $?NETCDF_HOME ]
   NCLIB=-L$NETCDF_HOME -lnetcdf -lnetcdff 
else [ $SYSTEM -eq 'MACOS' ]
   if test -f "/usr/local/lib/libnetcdff.a"
      NCLIB=-L/usr/local/lib -lnetcdf -lnetcdff
   else
      echo "Need to specify NETCDF_HOME"
   fi
fi

sed "s/COMPILER_OPT/$COMPILER/g" scripts/templates/Makefile.local | sed "s/MPI_OPT/$MPI_OPT/g" | sed "s/NCLIB/$NCLIB/g" > $SYSTEM/Makefile.local

mkdir refdata

cd $SYSTEM
make datasetup
make problemsetup
make boxgen
make definegeometry2d
make defineback
make randomtest
make tri_to_sonnet

cd ..

# Replace DATADIR with the appropriate directory in template input files
cp templates/elements.input refdata/
cp templates/species.input refdata/
cp templates/materials.input refdata/
sed -i "s#DATADIR#$PWD/refdata#g" templates/reactions.input > refdata/reactions.input
sed -i "s#DATADIR#$PWD/refdata#g" templates/pmi.input > refdata/pmi.input

sed -i "s#DATADIR#$PWD/refdata#g" templates/degas2.in > $SYSTEM/degas2.in


# Create reference data
cd $SYSTEM
./datasetup

cd ../scripts

echo "*** Installation complete. ***"
echo "Add the line export DEGASROOT=$DEGASROOT to your shell init script (e.g., ~/.bashrc)."
echo "Template input files (degas2.in, d2problem.input, d2tally.input), which points to semipermanent reference data created by datasetup, is in the directory $DEGASROOT/LINUX64"


