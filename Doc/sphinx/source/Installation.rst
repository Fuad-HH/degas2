Installing DEGAS2
=================

Requirements
^^^^^^^^^^^^

- NetCDF_, including Fortran 90 bindings.
- CMake_

Other dependencies (FWEB, SILO) are distributed with DEGAS2.

Instructions
^^^^^^^^^^^^

All executable components of DEGAS2 are installed with CMake_. 

Create a build directory
::

   mkdir build
   cd build

and run ``cmake`` to configure
::

   cmake ..

with the following options available:

- ``-DUSE_MPI=[ON|OFF]``: by default, if CMake finds an MPI implementation, it will use it. Use this flag to turn it on or force it off. Note that if compiled with MPI, ``flighttest`` *must* be run with ``mpirun`` or similar with more than one process.
- ``-DNETCDF_DIR=[/path/to/netcdf]``: if CMake has a hard time finding the NetCDF libraries, you can provide a path here to point it in the right direction.
- ``-DCMAKE_C_COMPILER=[path/to/gcc]``: on some systems (especially MacOS), ``gcc`` is a wrapper for CLANG, which is respected by CMake. Compiling FWEB (done at CMake configure time) currently requires GNU gcc proper. Try setting this option with the absolute path to GNU gcc if CMake is having trouble compiling FWEB at configure time. This is *only* needed at configure time, since CMake will leave FWEB alone once it sees the executable. If you're using another compiler routinely apart from FWEB compilation (which is supported), it is recommended to clear the build directory after the first configure step and re-configure without this flag. Such steps may look like:
  1. ``mkdir build; cd build``
  2. ``cmake -DUSE_MPI=ON -DCMAKE_C_COMPILER=/usr/bin/gcc-11 ..``
  3. ``rf -rf *``
  4. ``cmake -DUSE_MPI=ON ..``

This configuration step needs to be repeated every time you add or delete source files like ``usr2dplasma.web`` or ``usr2ddetector.web``.

You are now ready to build individual components. Binaries are stored in ``degas2/bin`` and it is a good idea to add this to your ``PATH`` environment variable, as well as including ``[/path/to/your/]degas2/scripts`` in your ``PYTHONPATH``.

A quick test:
::

   make randomtest
   ../bin/randomtest


Initializing data
^^^^^^^^^^^^^^^^^

The reactions, PMI, etc. need to be associated with the appropriate data files. This is done by running ``datasetup``, which needs a DEGAS2 input file, a sample of which is included in the ``degas2/data`` directory. From ``degas2/build``:
::

   make datasetup
   cp ../data/degas2.in .
   ../bin/datasetup

If this succeeds without a hitch, you are ready to run DEGAS2.

For developers
^^^^^^^^^^^^^^

The legacy Makefile system has been replaced with a CMake build system. If you add or edit source files, ensure dependencies are populated in ``CMakeLists.txt``. The legacy script to find said dependencies, ``makedepend.sh`` still works and generates the relevant section to be pasted in ``CMakeLists.txt`` (output by the script as the file ``cmakecommands``).








.. _CMake: https://cmake.org/
.. _NetCDF: https://www.unidata.ucar.edu/software/netcdf/
