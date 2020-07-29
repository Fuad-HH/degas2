#!/bin/sh
# 
# Usage:
# ./install_d2_for_xgc.sh SYSTEM COMPILER
#
# Installs DEGAS2 for use with XGC using typical parameters
# Run the script with an argument for the SYSTEM being used (as recognized by DEGAS2). Nowadays, this is usually LINUX64, but can also be MACOS, SUN, etc. Defaults to LINUX64 if no argument is given.
#
# Be sure to define the DEGASROOT environment variable that points to the degas2 directory.

if [ $# -eq 1 ]
   SYSTEM=$1
else
   SYSTEM=$1
   COMPILER=$2
fi

cd ../
./install_degas2.sh $SYSTEM $COMPILER
cd $DEGASROOT/$SYSTEM
make degas2_xgc.a

echo "*** Installation complete. ***"
echo "Add the line export DEGASROOT=$DEGASROOT to your shell init script (e.g., ~/.bashrc). Recompile XGC."

