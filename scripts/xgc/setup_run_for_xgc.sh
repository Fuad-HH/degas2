#!/bin/sh
#
# Usage:
# ./setup_run_for_xgc.sh XGC_WORKDIR CASENAME
#
# Sets up degas2 files needed when coupled to XGC. Calls several python scripts to construct the correct files from the files in the templates directory.

# Set up environment
SYSTEM=`cat this_system`
XGCD2DIR = $XGC_WORKDIR/degas2files
mkdir XGCD2DIR

# Copy degas2 input file 
cat templates/degas2.in | sed "s#XGCD2DIR#$XGCD2DIR#g" > $XGCD2DIR/degas2.in
cp $XGCD2DIR/degas2.in ../../$SYSTEM/

# These are basic data files that should not be changed unless other species, reactions, material interactions, etc. are added to the degas2 database
cp templates/elements.input $XGCD2DIR/
cp templates/species.input $XGCD2DIR/
cp templates/reactions.input $XGCD2DIR/
cp templates/pmi.input $XGCD2DIR/

# Get relevant information from XGC input file
./readXGCfileforD2.py $XGC_WORKDIR/input
# TODO; get RECYC, EBINNUM and species

# Copy problem and tally files over. This is what actually chooses which reactions and species are included and one may want to change this.
cp templates/pr_xgc.input $XGCD2DIR/
cp templates/tally_xgc.input $XGCD2DIR/

# Copy template for definegeometry2d
./prepD2GeomFilesForXGC.py $XGC_WORKDIR $CASENAME
RMIN = `cat /tmp/RMIN`
RMAX = `cat /tmp/RMAX`
ZMIN = `cat /tmp/ZMIN`
ZMAX = `cat /tmp/ZMAX`
NUMELE = `cat /tmp/NUMELE`
cat templates/rpi_dg2d.in | sed "s#CASENAME#$XGC_WORKDIR/$CASENAME#g" | sed "s/RMIN/$RMIN/g" | sed "s/RMAX/$RMAX/g" | sed "s/ZMIN/$ZMIN/g" | sed "s/ZMAX/$ZMAX/g" |sed "s/RECYC/$RECYC/g" | sed "s#D2DIR#$XGCD2DIR#g" | sed "s/NUMELE/$NUMELE/g" > $XGCD2DIR/rpi_dg2d.in

# Prepare background plasma file
./prepplasmafileforxgc.py $XGCD2DIR
cat templates/rpi_db.in | sed 's/EBINNUM/$EBINNUM/g' > $XGCD2DIR/rpi_db.in 

# Now run setup
cd ../../$SYSTEM
./datasetup
./problemsetup
./definegeometry2d $XGCD2DIR/rpi_dg2d.in
./defineback $XGCD2DIR/rpi_db.in
./tallysetup

