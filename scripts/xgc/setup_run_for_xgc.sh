#!/bin/sh
#
# Usage:
# ./setup_run_for_xgc.sh XGC_WORKDIR CASENAME
#
# Sets up degas2 files needed when coupled to XGC. Calls several python scripts to construct the correct files from the files in the templates directory.

# Set up environment
SYSTEM="cat $DEGASROOT/this_system"
XGCD2DIR=$XGC_WORKDIR/degas2files
mkdir XGCD2DIR

# Copy degas2 input file 
sed -i "s#WORKDIR#$XGCD2DIR#g" templates/degas2.in > $XGCD2DIR/degas2.in

# Get relevant information from XGC input file
./readXGCfileforD2.py $XGC_WORKDIR/input
# TODO: put neu_en_bin_num and neu_ptl_num in xgc inputs
# TODO: add logic for other isotopes


# Copy problem and tally files over. This is what actually chooses which reactions and species are included and one may want to change this.
cp $DEGASROOT/templates/d2problem.input $XGCD2DIR/
cp $DEGASROOT/templates/d2tally.input $XGCD2DIR/

# Copy template for definegeometry2d
./dump_outerpts.py $XGC_WORKDIR/$CASENAME.node
RMIN=`cat /tmp/RMIN`
RMAX=`cat /tmp/RMAX`
ZMIN=`cat /tmp/ZMIN`
ZMAX=`cat /tmp/ZMAX`
NUMELE=`head -n 1 $XGC_WORKDIR/$CASENAME.ele | awk '{print $1}'`
RECYC=`./get_recyc.py $XGC_WORKDIR`
EBINNUM=`./get_ebinnum.py $XGC_WORKDIR`
ISOTOPE=`./get_isotope.py $XGC_WORKDIR`
sed -i "s#CASENAME#$XGC_WORKDIR/$CASENAME#g" templates/dg2d_xgc.in |  sed "s/RMIN/$RMIN/g" | sed "s/RMAX/$RMAX/g" | sed "s/ZMIN/$ZMIN/g" | sed "s/ZMAX/$ZMAX/g" |sed "s/RECYC/$RECYC/g" | sed "s#D2DIR#$XGCD2DIR#g" | sed "s/NUMELE/$NUMELE/g" > $XGCD2DIR/rpi_dg2d.in

# Create the .aif wall file, needed for definegeometry2d
$DEGASROOT/$SYSTEM/tri_to_sonnet $XGCD2DIR/$CASENAME
$DEGASROOT/scripts/xgc/writewallfile.py $XGCD2DIR/$CASENAME

# Prepare background plasma file
# Create NUMELE lines in background plasma file with placeholders of zero
cp $DEGASROOT/scripts/templates/plasmadata_placeholder $XGCD2DIR/
for iz in {1..$NUMELE}
do
   echo "$iz 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0" >> $XGCD2DIR/plasmadata_placeholder
done

nwall=`head -n 2 $XGC_WORKDIR/$CASENAME.aif|tail -n 1`
let maxseg=$nwall-1

sourcefile=$XGCD2DIR/sourcedata_placeholder
echo '#  stratum  segment    strength' > $sourcefile
echo '1  0  1.e21' >> $sourcefile
for iw in {0..$maxseg}
do
   echo "2  $iw  1.e21" >> $sourcefile
done

sed -i "s/EBINNUM/$EBINNUM/g" templates/db_xgc.in > $XGCD2DIR/rpi_db.in 

# Now run degas2 setup routines
cd $XGCD2DIR
$DEGASROOT/$SYSTEM/problemsetup
$DEGASROOT/$SYSTEM/definegeometry2d $XGCD2DIR/dg2d_xgc.in
$DEGASROOT/$SYSTEM/defineback $XGCD2DIR/db_xgc.in
$DEGASROOT/$SYSTEM/tallysetup

ln -s $DEGASROOT/$SYSTEM/degas2_xgc.a $XGCD2DIR/degas2_xgc.a
