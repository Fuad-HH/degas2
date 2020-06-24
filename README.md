This is (currently) a fork of dstotler's DEGAS2 repository. Here, FWEB is included as a submodule.

To install:
- In .bashrc or wherever you set environment variables, Set DEGASROOT to the directory you installed DEGAS (the directory in which this file is located)
- Navigate to fweb/Web.
- Type ./configure and make. Ensure ftangle and fweave are created as executables.
- Full configure scripts are not supported. Instead, make sure your compiler is used in src/Makefile and src/Makefile.local
- Create a run directory in DEGASROOT named after your system (e.g. LINUX64, MACOSX, etc.)
- Go into that run directory and type "make randomtest" and run the associated exectutable. It should have worked.
- Further documentation is in the Doc directory, especially degas2_all.pdf and  Running_DEGAS2_at_PPPL.txt
