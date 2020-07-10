#!/bin/sh

if [ $# -eq 0 ]
then
   SYSTEM=LINUX64
else
   SYSTEM=$1
fi

cd ../
DEGASROOT=$PWD
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

echo "*** Installation complete. ***"
echo "Add the line export DEGASROOT=$DEGASROOT to your shell init script (e.g., ~/.bashrc)"

