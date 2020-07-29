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

export DEGASROOT=$PWD/$SYSTEM
echo $SYSTEM > this_system
mkdir $SYSTEM
cd $SYSTEM
cp ../src/Makefile* .
make datasetup
make problemsetup
make boxgen
make definegeometry2d
make defineback
make randomtest
make tri_to_sonnet

# Replace DATADIR with the appropriate directory in template input files

# Create reference data
./datasetup

echo "*** Installation complete. ***"
echo "Add the line export DEGASROOT=$DEGASROOT to your shell init script (e.g., ~/.bashrc)."

