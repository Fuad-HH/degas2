#!/bin/sh
# 
# Usage:
# ./install_d2_for_xgc.sh SYSTEM
#
# Installs DEGAS2 for use with XGC using typical parameters
# Run the script with an argument for the SYSTEM being used (as recognized by DEGAS2). Nowadays, this is usually LINUX64, but can also be MACOS, SUN, etc. Defaults to LINUX64 if no argument is given.
#
# Be sure to define the DEGASROOT environment variable that points to the degas2 directory.

if [ $# -eq 0 ]
then
   SYSTEM=LINUX64
else
   SYSTEM=$1
fi

cd ../../
export DEGASROOT=$PWD/$SYSTEM
echo $SYSTEM > this_system
mkdir $SYSTEM
cd $SYSTEM
cp ../src/Makefile* .
make datasetup
make problemsetup
make definegeometry2d
make defineback
make randomtest
./randomtest
./datasetup
cd ../scripts/xgc

echo "*** Installation complete. ***"
echo "Add the line export DEGASROOT=$DEGASROOT to your shell init script (e.g., ~/.bashrc). Recompile XGC."

