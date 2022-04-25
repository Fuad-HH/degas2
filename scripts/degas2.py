#!/bin/env pyton3
# A python wrapper for the degas2 neutral transport solver. 

# Written by: George Wilkie (gwilkie@pppl.gov)
# A degas2 object contains all the data needed for a run and is composed of several subclasses, each in their own modules.
# If a degas2 component has its own distinct input file and/or executable, it will have its own class here
# For now, the structure of degas2 will not change. You should be able to use the degas2 installation normally, as long as your path is set to $DEGASROOT/LINUX64

# The degas2 class is associated with the whole run, including setting it up and post-processing. It's job is to communicate among the classes and manage the "degas2.in" input file.
import os
import degas2_data

try: 
    root = os.getenv('DEGASROOT')
    break
except:
    print("ERROR: Set DEGASROOT environment variable to your degas2 installation"))
    sys.exit(1)

# Program is run from an arbitrary directory that reads wrapper input and dumps output files. Degas2 files get written to $PWD/.degas2 in case access is needed.
workdir = os.getcwd()

# Make sure .degas2 does not already exist in workdir. If so, confirm overwrite.


# Get appropriate directories
# These should be absolute paths.
datadir = root + "/data"
srcdir = root + "/src"
fdir = root + "/LINUX64"

data = degas2_data(datadir)
problem = degas2_problem(workdir)


