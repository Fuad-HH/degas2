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
    test -s $temp.b && echo `echo $file | sed 's/\.[^.]*$/.f/'`: `cat $temp.b` >>$temp.d
done
mv Makefile Makefile.bak

sed -e '/^# DO NOT DELETE/,$d' Makefile.bak > Makefile
echo "# DO NOT DELETE THIS LINE -- make depend depends on it." >> Makefile
echo 'ifeq ($(STANDALONE),yes)' >> Makefile
cat $temp.d >> Makefile
echo 'endif' >> Makefile
rm -rf $temp.*
