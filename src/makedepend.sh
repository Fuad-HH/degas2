#! /bin/sh
# Do fweb style makedepend on args

# Looks for lines of the form
#    
#   @I  filename
#and
#   @i  filename
#
# Only treats bare file names (not ones in <> or ").  Doesn't treat include
# directories.  A comment can follow the file name but this must be separated
# from the file name by whitespace.
#
# Assumes Makefile is called Makefile.  Uses conventional "# DO NOT DELETE"
# to separate off depends.  Makefile lines are not broken.
#
# This is NOT fast!

temp=/tmp/makedepend_$$ # basename for temporary files

# $temp.a holds includes for intermediate files
# $temp.b holds accumulated includes for current file
# $temp.c a temporary file
# $temp.d holds accumulated includes for all files

# $temp.e holds F90 stuff

cp /dev/null $temp.d

for file do
    echo $file > $temp.a # Start things off by assuming "@i $file" is given.
    cp /dev/null $temp.b # No accumulated includes yet
    while true; do
	newfiles="`comm -13 $temp.b $temp.a`" # New files we need to consider
	cat $temp.a $temp.b | sort | uniq > $temp.c 
	mv $temp.c $temp.b # Merge new files into list for current file
	cp /dev/null $temp.a
	test "$newfiles" || break # Consider next file if no new files
	for f in $newfiles; do # Look in each new file
	    grep '^[ 	]*@[iI][ 	]' $f |
		sed -e 's/^[ 	]*@[iI][ 	]*//' -e 's/[ 	].*$//' |
		sort | uniq >> $temp.a
	done
	sort $temp.a | uniq > $temp.c # Prune out redundancies
	mv $temp.c $temp.a
    done
    grep -v "^$file\$" $temp.b > $temp.c # Remove head file.
    mv $temp.c $temp.b
    # Create a Makefile dependency line
    case $file in
        *.web ) test -s $temp.b && echo `echo $file | sed 's/\.[^.]*$/.f/'`: `cat $temp.b` >>$temp.d ;;
	*.hweb ) test -s $temp.b && grep '^[ 	]*package_init' $file > /dev/null && echo `echo $file | sed 's/\.[^.]*$/_mod.f/'`: `cat $temp.b` >>$temp.d ;;
    esac
done

# Do FORTRAN 90 depends
cp /dev/null $temp.e
for file do
    case $file in 
     *.hweb )
	mods=`grep "^[ 	]*package_init\([a-z0-9]*\)" $file | grep -v '@m' | tr -s '; 	/*!' '\012' | grep package_init | sort -u | sed -e 's/)/_suffix/' -e 's/^package_init(/prefix_/'`
	if test "$mods"; then
#	echo `echo $mods | sed -e 's/prefix_//' -e 's/_suffix/.mod/'`: `echo $file | sed 's/\.[^.]*$/_mod.f/'` >> $temp.e
	for mod in $mods;do
	    echo `echo $mod | sed -e 's/prefix_//' -e 's/_suffix/_MOD/'`:=`echo $file | sed 's/\.[^.]*$/_mod.$O/'` >> $temp.e
	 done
	fi
       ;;
    esac
done

for file do
    case $file in 
    *.web )
       mods=`grep "^[ 	]*[a-z0-9]*_common" $file | tr -s '; 	/*!' '\012' | grep _common | sort -u | sed -e 's/_common/_suffix/' -e 's/^/prefix_/'`
       if test "$mods"; then
	echo `echo $file | sed 's/\.[^.]*$/_mods/'`:= `echo $mods | sed -e 's/prefix_/$(/g' -e 's/_suffix/_MOD)/g'` >> $temp.e
#	echo `echo $file | sed 's/\.[^.]*$/.o/'`: `echo $mods | sed -e 's/prefix_/$(/g' -e 's/_suffix/_MOD)/'` >> $temp.e
	echo `echo $file | sed 's/\.[^.]*$/.o/'`: '$('`echo $file | sed 's/\.[^.]*$/_mods/'`')' >> $temp.e
       fi
       ;;
    esac
done


(
echo 'ifeq ($(FORTRAN90),yes)'
cat $temp.e
echo endif
echo 'ifeq ($(STANDALONE),yes)'
cat $temp.d
echo 'endif'
) > Makefile.depends

rm -rf $temp.*
