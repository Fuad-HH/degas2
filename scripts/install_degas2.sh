#!/bin/sh
# Sets up the environment for running degas2
#
# Usage, from this directory:
# SYSTEM=LINUX64 COMPILER=GFORTRAN MPI_OPT=yes NETCDF_HOME=/usr/local/lib ./install_degas2.sh
# where SYSTEM is the degas2-specified system (LINUX64 by default), 
# COMPILER is the compiler to use (gfortran by default), and
# NETCDF_HOME is where libnetcdf.a and libnetcdff.a are located

if [ -z $SYSTEM ]
then
   SYSTEM=LINUX64
fi


if [ -z $COMPILER ]
then
   COMPILER=GFORTRAN
fi

if [ -z "$MPI_OPT" ]
then
   MPI_OPT=no
fi

cd ..
export DEGASROOT=$PWD
echo $SYSTEM > this_system
mkdir $SYSTEM
cd $SYSTEM
ln -s ../src/Makefile .
cd $DEGASROOT

if [ ! -z $NETCDF_C_HOME ]
then
   NCLIB="-L$NETCDF_C_HOME -lnetcdf"
   if [ $?NETCDF_FORTRAN_HOME ]
   then
      NCLIB="-L$NETCDF_FORTRAN_HOME -lnetcdff"
   else
      echo "Need to specify NETCDF_FORTRAN_HOME along with NETCDF_C_HOME"
   fi
elif [ ! -z $NETCDF_HOME ]
then
   NCLIB="-L$NETCDF_HOME -lnetcdf -lnetcdff "
else 
   if [ -f "/usr/local/lib/libnetcdff.a" || -f "/usr/local/lib/libnetcdff.so" ]
   then
      NCLIB="-L/usr/local/lib -lnetcdf -lnetcdff"
   elif [ -f "/usr/lib/libnetcdff.a" || -f "/usr/lib/libnetcdff.so" ]
   then
      NCLIB="-L/usr/lib -lnetcdf -lnetcdff"
   else
      echo "Need to specify NETCDF_HOME"
      exit 1
   fi
fi

FWEB_DIR=$DEGASROOT/fweb/Web

sed "s/COMPILER_OPT/$COMPILER/g" $DEGASROOT/scripts/templates/Makefile.local | sed "s/MPI_OPT/$MPI_OPT/g" | sed "s#NCLIB#$NCLIB#g"  | sed "s#FWEB_DIR#$FWEB_DIR#g" > $DEGASROOT/$SYSTEM/Makefile.local

if [ ! -f $DEGASROOT/fweb/Web/ftangle ]
then
   cd $DEGASROOT/fweb/Web
   ./configure
   make
fi

cd $DEGASROOT/$SYSTEM
make datasetup
make problemsetup
make boxgen
make definegeometry2d
make defineback
make randomtest
make tri_to_sonnet

cd ..

# Replace DATADIR with the appropriate directory in template input files
cp $DEGASROOT/scripts/templates/elements.input data/
cp $DEGASROOT/scripts/templates/species.input data/
cp $DEGASROOT/scripts/templates/materials.input data/
sed "s#DATADIR#$DEGASROOT/data#g" $DEGASROOT/scripts/templates/reactions.input > $DEGASROOT/data/reactions.input
sed "s#DATADIR#$DEGASROOT/data#g" $DEGASROOT/scripts/templates/pmi.input > $DEGASROOT/data/pmi.input
sed "s#DATADIR#$DEGASROOT/data#g" $DEGASROOT/scripts/templates/degas2.in > $DEGASROOT/$SYSTEM/degas2.in
cp $DEGASROOT/scripts/templates/d2problem.input $DEGASROOT/$SYSTEM
cp $DEGASROOT/scripts/templates/d2tally.input $DEGASROOT/$SYSTEM

# Create reference data
cd $DEGASROOT/$SYSTEM
./datasetup

cd $DEGASROOT/scripts

echo "*** Installation complete. ***"
echo "Add the line export DEGASROOT=$DEGASROOT to your shell init script (e.g., ~/.bashrc)."
echo "Example input files (degas2.in, d2problem.input, d2tally.input), which point to semipermanent reference data created by datasetup, are in the directory $DEGASROOT/LINUX64. Replace WORKDIR in degas2.in where necessary."


