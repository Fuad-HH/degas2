# $Id$
# $Log$
# Revision 1.52  1997/08/19 14:36:25  karney
# Changes to support compilation under f90.  This involved extensive changes
# in array.hweb and sysdep.web.  Nearly all other files needed some
# modifications.
#
# Revision 1.51  1997/08/07 19:01:19  dstotler
# Added tallysetup. Numerous .$O dependencies altered.
#
# Revision 1.50  1996/10/31 09:06:54  karney
# Define scoring arrays.
#
# Revision 1.49  1996/10/30 17:13:42  dstotler
# Add dependencies for readbackground. Define CRAMD library. Add
# sourcetest, dataexam, and allow for some rearrangement of "utility"
# routines in files.
#
# Revision 1.48  1996/05/24 18:42:34  dstotler
# Add pmitest as a target; split elementread.web into two pieces to form
# also pmimatread.web.
#
# Revision 1.47  1996/03/01 20:18:31  dstotler
# Add pmidata.hweb, sector.hweb to header list, plate.$O to problemsetup
# dependencies.
#
# Revision 1.46  1996/02/28 19:41:10  karney
# Implement makedepend and make depend.
#
# Revision 1.45  1996/01/25 14:59:17  dstotler
# Added dependencies (for materials, pmi stuff) to datasetup and
# readgeometry.
#
# Revision 1.44  1995/11/29 17:42:44  karney
# Specify path (.) for idtof
#
# Revision 1.43  1995/11/17 22:00:48  karney
# A couple of fixes for Cray compilation.
#
# Revision 1.42  1995/11/03 15:06:08  karney
# Clean up for release.
#
# Revision 1.41  1995/10/12 21:42:34  karney
# Finish the implementation of sectors.  Now track exits when encountering a
# sector (on either side).  Sector and strata information is now part of the
# location.
#
# Revision 1.40  1995/10/04 18:33:13  karney
# (1) Fix comments to avoid bugs in ftangle.
# (2) Implement transforms on surfaces.
# (3) Update universal_cell to impose periodicity on y boundaries.
#
# Revision 1.39  1995/08/23 14:44:59  dstotler
# Added dependencies for reactiontest.
#
# Revision 1.38  1995/08/01 17:56:26  karney
# Various changes to make compilation clean on ALPHA.
#
# Revision 1.37  1995/07/14 13:19:57  karney
# Coding for strata added.
# Switch \Wtitle to \Title.
# Update to use standard etags.
#
# Revision 1.36  1995/06/21 20:03:30  jshankar
# updated to include readfilenames
#
# Revision 1.35  1995/06/16 19:51:42  dstotler
# Switch strata -> segment in HEADERS definition (bug) and remove
# randomtest2.
#
# Revision 1.34  1995/06/16 09:54:44  karney
# remove unresolved conflict garbage
#
# Revision 1.33  1995/06/13 21:19:40  jshankar
# changed to compile readfilenames.
#
# Revision 1.32  1995/06/12 13:06:59  karney
# Add in dummy elements into common blocks to avoid complaints from
# Alpha.
#
# Revision 1.31  1995/06/07 15:55:49  karney
# Add profiling; fix bug in composite.web
#
# Revision 1.30  1995/06/06 13:37:40  csk
# Permit printing at Garching.
#
# Revision 1.29  1995/06/02 14:34:08  csk
# Remove fixit from Makefile.  (Not needed any more.)
#
# Revision 1.28  1995/06/02 09:10:13  karney
# Test of CVS under AFS.
#
# Revision 1.27  1995/05/31 19:20:56  dstotler
# Add in pmi files and programs.
#
# Revision 1.26  1995/05/26 04:00:11  karney
# Upgrade to fweb 1.51beta.
# Initial implementation of surface segments.
#
# Revision 1.25  1995/05/22 22:04:37  karney
# Update for fweb 1.50.  Several minor changes.  Implement collide.web.
#
# Revision 1.24  1995/04/25 22:14:27  karney
# Initial version of sources.web
#
# Revision 1.23  1995/04/24 20:43:31  karney
# Generalize reactiondata to allow multiple data arrays per reaction.
#
# Revision 1.22  1995/04/12 18:34:00  karney
# Merge in comments to array.hweb and changes for Sherwood '95 meeting.
#
# Revision 1.21  1995/03/30 17:07:04  karney
# Add readbackground
#
# Revision 1.20  1995/03/28 20:37:26  jshankar
# Initial version of readgeometry.
#
# Revision 1.19  1995/03/10 22:11:13  karney
# Reorder variable definitions in various header files
#
# Revision 1.18  1995/03/01 17:17:23  karney
# Minor changes to fweboptions.sty and Makefile.
#
# Revision 1.17  1995/02/14 21:43:49  karney
# Typos in Makefile.  Remove \loadfonts from geomsetup.web.
#
# Revision 1.16  1995/01/30 21:06:25  karney
# Merge in my changes with Daren's
#
# Revision 1.15  1994/11/21 15:48:47  dstotler
# Interim update associated with ratecalc. ratecalc.hweb and
# xsection.hweb have undergone substantial revision, but should be
# relatively stable from here on. Note also that all of the "ncreada", etc.
# macros have been combined into a single ncread macro. The user is
# responsible for ensuring that dimensions and variables are defined /
# used in the proper order (although the built-in "assert"s should
# help).
#
# Revision 1.14  1994/08/24 15:02:42  karney
# Added degasgeom to read in old degas' geometry spec.
#
# Revision 1.13  1994/07/05 11:56:15  karney
# Sync with repository
#
# Revision 1.12  1994/06/28 22:12:46  karney
# Add reaction data, test out {element,species,reaction}setup.
#
# Revision 1.11  1994/06/28 19:44:21  karney
# Get Makefiles working to update fixit, idtof when needed.

DEBUG=yes
STANDALONE=yes
FORTRAN90=no

# Figure out the system type
SYSTEM:=$(shell uname)

ifeq ($(SYSTEM),SunOS)
  MACHINE=SUN
  PVMARCH=SUN4
endif
ifeq ($(SYSTEM),AIX)
  MACHINE=IBM
endif
ifeq ($(SYSTEM),OSF1)
  MACHINE=ALPHA
endif
ifeq ($(SYSTEM),HP-UX)
  MACHINE=HP
endif
ifeq ($(SYSTEM),IRIX)
  MACHINE=SGI
  PVMARCH=SGI
endif
ifeq ($(findstring sn,$(SYSTEM)),sn)
  MACHINE=CRAY
  PVMARCH=CRAY
endif

# Figure out target machine
TARGET=$(notdir $(shell pwd))

ifneq ($(TARGET),$(MACHINE))
  CROSSCOMPILE=yes
endif

utils: makemodule idtof Makefile

# Cancel some built-in rules
%: %.f
%: %.c
%: %.o
%: %.mod
%.c: %.l
%.r: %.l
%.o %: %.mod
%.p: %.web
%.tex: %.web
%.dvi: %.tex

# Deal with location of things

ifndef DEGASROOT
    DEGASROOT=$(HOME)
endif

-include Makefile.local

ifeq ($(STANDALONE),yes)
  SOURCEDIR=$(DEGASROOT)/degas2/src
  vpath %.web $(SOURCEDIR)
  vpath %.hweb $(SOURCEDIR)
else
ifeq ($(MACHINE),CRAY)
  SOURCEDIR=$(DEGASROOT)/degas2/$(MACHINE)
  %.f: $(SOURCEDIR)/%.f
	cp $< $@
else
ifeq ($(MACHINE),HP)
  SOURCEDIR=$(DEGASROOT)/degas2/$(MACHINE)
  %.f: $(SOURCEDIR)/%.f
	cp $< $@
else
  STANDALONE=yes
  SOURCEDIR=$(DEGASROOT)/degas2/src
  vpath %.web $(SOURCEDIR)
  vpath %.hweb $(SOURCEDIR)
endif
endif
endif

ALADIR=$(DEGASROOT)/degas2/Aladdin

CRAMDIR=$(DEGASROOT)/degas2/CRAMD

Makefile: $(SOURCEDIR)/Makefile
	cp $< $@
Makefile.depends: $(SOURCEDIR)/Makefile.depends
	cp $< $@
%.sh: $(SOURCEDIR)/%.sh
	cp $< $@
%.el: $(SOURCEDIR)/%.el
	cp $< $@
%.sty: $(SOURCEDIR)/%.sty
	cp $< $@
degas2.in: $(SOURCEDIR)/degas2.in
	cp $< $@

# Set up librarys
LIBROOT=/usr/local

ifeq ($(MACHINE),SUN)
  NETCDF=-L$(LIBROOT)/lib -lnetcdf -lnsl
  HDF=-L$(LIBROOT)/lib -ldf -ljpeg -R/opt/SUNWspro/lib:/usr/local/lib -lz
else
  NETCDF=-L$(LIBROOT)/lib -lnetcdf
  HDF=-L$(LIBROOT)/lib -ldf -ljpeg -R/opt/SUNWspro/lib:/usr/local/lib -lz
endif
PVM=-L$(PVM_ROOT)/pvm3/lib/$(PVMARCH) -lfpvm3 -lpvm3

ifeq ($(MACHINE),ALPHA)
	CRAMD=$(CRAMDIR)/LIB/CRAMDlib.a $(CRAMDIR)/LIB/cramd_lib.a $(CRAMDIR)/LIB/lc_sig.a $(CRAMDIR)/LIB/lc_std.a
endif

# Cancel some built-in rules
%: %.f
%: %.c
%: %.mod
%.c: %.l
%.r: %.l
%.o %: %.mod
%.p: %.web
%.tex: %.web
%.dvi: %.tex
%: %.mod

# Set up compilers etc.
ifeq ($(PRINTER),)
 LPRFLAGS=-h
else
 LPRFLAGS=-h -P$(PRINTER)
endif
ifeq ($(MACHINE),CRAY)
 FTANGLE=/afs/pppl.gov/@sys/usr/local/bin/ftangle
else
 FTANGLE=ftangle
endif
FWEAVE=fweave
LATEX=latex
# These are the old tangle flags -- not needed any more since we
# now don't stress tangle so much
# TANGLEFLAGS=-mINLINE -W[ -ytt40000000 -yn8000 -ymb65536 -n/ -n')' -Tv -j
TANGLEFLAGS=-mINLINE -W[ -n/ -n')' -Tv -j -yn6000
ifeq ($(DEBUG),yes)
  TANGLEDEBUG=-mDEBUG
else
  TANGLEDEBUG=
endif

ifeq ($(FORTRAN90),yes)
  TANGLEFORTRAN=-mFORTRAN90
else
  TANGLEFORTRAN=
endif

WEAVEFLAGS=-f -i! -W[ -ykw600 -ytw40000 -j -n/  # Added the '!', OK? (DPS)

ifeq ($(MACHINE),CRAY)
  FC=cft77
  ifeq ($(DEBUG),yes)
    FFLAGS=-e m -e z -a stack -o off
  else
    FFLAGS=-e m -e z -a stack
  endif
  LD=segldr
else  # !CRAY
  ifneq ($(MACHINE),IBM)
    FC=f77
  else
    FC=xlf
  endif
  LD=$(FC)
  ifeq ($(DEBUG),yes)
    FFLAGS=-c -g -u
    LDFLAGS=
    CFLAGS=-g
  else
    FFLAGS=-c -O -fast $(PROFILE)
    LDFLAGS=$(PROFILE)
    CFLAGS=-O
  endif
endif

ifeq ($(FORTRAN90),yes)
    FC=f90
    FFLAGS=-c -g
ifeq ($(MACHINE),SUN)
    F90MODS=-M.
endif
ifeq ($(MACHINE),CRAY)
    F90MODS=-p.
    LD=$(FC)
endif
ifeq ($(MACHINE),ALPHA)
    F90MODS=-I.
endif
endif

ifeq ($(MACHINE),IBM)
  SYSDEPO=sysdep.$O sysdepc.$O
else
  SYSDEPO=sysdep.$O
endif

ifndef CROSSCOMPILE
  O=o
  %.o: %.f
	$(FC) $(F90MODS) $(FFLAGS) $<
  %: %.o $(SYSDEPO) string.$O idtof degas2.in
	./idtof $(patsubst %.$O,%.f,$^) > $*.id.f
	$(FC) $(FFLAGS) $*.id.f
	$(LD) $(LDFLAGS) -o $@ $(filter %.$O,$^) $*.id.o $($@_libs)
else # We're cross compiling
  O=f
  %: %.o
  %: %.$O sysdep.$O string.$O idtof degas2.in
	@echo Made $^
endif

IDENTAPPEND=cat $^ | ident -q | sort | uniq | sed 's/^/c/' >> $@
.PRECIOUS: %.mweb %.tex %.dvi %.f %_mod.f %.cft %.o %.dum fweb.sty fweboptions.sty

%.f: %.web
	$(FTANGLE) $(TANGLEFLAGS) $(TANGLEDEBUG) $(TANGLEFORTRAN) -m$(TARGET) $<
	$(IDENTAPPEND)

ifeq ($(STANDALONE),yes)
# include files
endif

%.mweb: %.hweb makemodule
	./makemodule $< $@

%_mod.f: %.mweb
	$(FTANGLE) -I$(SOURCEDIR) $(TANGLEFLAGS) $(TANGLEDEBUG) $(TANGLEFORTRAN) -m$(TARGET) -=n=#_mod.f $<

ifeq ($(TARGET),IBM)
  sysdep.f sysdepc.c: sysdep.web macros.hweb
	$(FTANGLE) $(TANGLEFLAGS) $(TANGLEDEBUG) $(TANGLEFORTRAN) -m$(TARGET) -=c=#c.c $<
	$(IDENTAPPEND)
endif

%.tex: %.web fweb.sty
	$(FWEAVE) $(WEAVEFLAGS) $<

define RUN-LATEX
  if [ -r $*.aux ]; then cp $*.aux $*.aux0; fi
  $(LATEX) $*.tex
  if [ -r $*.aux ]; then cmp -s $*.aux $*.aux0 || latex $*.tex; fi
  rm -f $*.aux0
endef

%.dvi: %.tex fweboptions.sty fweb.sty
	$(RUN-LATEX)

%.bbl: %.aux ../../degas.bib
	bibtex $*

%.print: %.dvi
ifndef PAGES
	dvips -f $^
#	lpr $(LPRFLAGS) -d $^
else
	dviselect $(PAGES) $^ | lpr $(LPRFLAGS) -d
#	dviselect $(PAGES) $^ | dvips-filter | rsh leo.gat.com lp
endif

%.view: %.dvi
	xdvi $^

%.ps: %.dvi
	dvips -f $^ > $@

# Include dependencies

-include Makefile.depends

all: programs documentation idtof
programs: randomtest geomtest sysdeptest
documentation: random.dvi randomtest.dvi geometry.dvi geomsetup.dvi \
  geomtest.dvi sysdep.dvi vector.dvi

foof:
	echo $(MACHINE) $(TARGET) $(SOURCEDIR) $(STANDALONE) $(FC) $(FORTRAN90) $(CROSSCOMPILE)

sysdeptest = sysdeptest.$O
sysdeptest_libs = 
sysdeptest: $(sysdeptest) $(foreach arg,$(subst .$O,_mods,$(sysdeptest)),$($(arg)))

# elementsetup = 
# elementsetup_libs = $(NETCDF)
# elementsetup: $(elementsetup)

# speciesetup = elementread.$O
# speciesetup_libs = $(NETCDF)
# speciesetup: $(speciesetup)

randomtest = randomtest.$O random.$O randother.$O
randomtest_libs =
randomtest: $(randomtest) $(foreach arg,$(subst .$O,_mods,$(randomtest)),$($(arg)))

pvmmaster = pvmmaster.$O random.$O stat.$O geometry.$O readfilenames.$O
pvmmaster_libs = $(NETCDF) $(PVM)
pvmmaster: $(pvmmaster) $(foreach arg,$(subst .$O,_mods,$(pvmmaster)),$($(arg)))

pvmslave = pvmslave.$O random.$O randother.$O stat.$O geometry.$O elementread.$O pmimatread.$O flight.$O reaction.$O geomfront.$O readfilenames.$O
pvmslave_libs = $(NETCDF) $(PVM)
pvmslave: $(pvmslave) $(foreach arg,$(subst .$O,_mods,$(pvmslave)),$($(arg)))

flighttest = flighttest.$O elementread.$O pmimatread.$O geometry.$O random.$O stat.$O randother.$O reaction.$O geomfront.$O flight.$O sources.$O collide.$O readfilenames.$O plate.$O degasinit.$O score.$O
flighttest_libs = $(NETCDF)
flighttest: $(flighttest) $(foreach arg,$(subst .$O,_mods,$(flighttest)),$($(arg)))

geomtest = geomtest.$O geometry.$O geomsetup.$O allocate.$O geomutils.$O geomfaces.$O composite.$O string.$O readfilenames.$O geomfront.$O dediagsetup.$O
geomtest_libs = $(NETCDF)
geomtest: $(geomtest) $(foreach arg,$(subst .$O,_mods,$(geomtest)),$($(arg)))

geomtesta = geomtesta.$O geometry.$O plotgeom.$O elementread.$O pmimatread.$O readfilenames.$O score.$O reaction.$O collide.$O randother.$O random.$O
geomtesta_libs =  $(NETCDF) $(HDF)
geomtesta: $(geomtesta) $(foreach arg,$(subst .$O,_mods,$(geomtesta)),$($(arg)))

reactionwrite = reactionwrite.$O
reactionwrite_libs = $(NETCDF)
reactionwrite: $(reactionwrite) $(foreach arg,$(subst .$O,_mods,$(reactionwrite)),$($(arg)))

pmiwrite = pmiwrite.$O reaction.$O random.$O
pmiwrite_libs = $(NETCDF)
pmiwrite: $(pmiwrite) $(foreach arg,$(subst .$O,_mods,$(pmiwrite)),$($(arg)))

datasetup = datasetup.$O elementread.$O pmimatread.$O elementsetup.$O speciesetup.$O reactionsetup.$O materialsetup.$O pmisetup.$O readfilenames.$O
datasetup_libs = $(NETCDF)
datasetup: $(datasetup) $(foreach arg,$(subst .$O,_mods,$(datasetup)),$($(arg)))

problemsetup = problemsetup.$O elementread.$O pmimatread.$O reaction.$O readfilenames.$O plate.$O geometry.$O random.$O randother.$O
problemsetup_libs = $(NETCDF)
problemsetup: $(problemsetup) $(foreach arg,$(subst .$O,_mods,$(problemsetup)),$($(arg)))

geomread = geomread.$O geomsetup.$O allocate.$O geomutils.$O geomfaces.$O geometry.$O composite.$O string.$O elementread.$O pmimatread.$O
geomread_libs = $(NETCDF)
geomread: $(geomread) $(foreach arg,$(subst .$O,_mods,$(geomread)),$($(arg)))

cramdtest = cramdtest.$O cramdadd.$O readfilenames.$O elementread.$O pmimatread.$O geometry.$O degasinit.$O
cramdtest_libs = $(CRAMD) $(NETCDF)
cramdtest: $(cramdtest) $(foreach arg,$(subst .$O,_mods,$(cramdtest)),$($(arg)))

cramdtesta = cramdtesta.$O cramdadd.$O sysdep.$O string.$O pmimatread.$O
cramdtesta_libs = $(CRAMD) $(NETCDF)  
cramdtesta: $(cramdtesta) $(foreach arg,$(subst .$O,_mods,$(cramdtesta)),$($(arg)))

degasgeom = degasgeom.$O geomsetup.$O allocate.$O geomutils.$O geomfaces.$O geometry.$O composite.$O random.$O
degasgeom_libs = $(NETCDF)
degasgeom: $(degasgeom) $(foreach arg,$(subst .$O,_mods,$(degasgeom)),$($(arg)))

test = test.$O geomsetup.$O allocate.$O geomutils.$O geomfaces.$O geometry.$O composite.$O
test_libs = $(NETCDF)
test: $(test) $(foreach arg,$(subst .$O,_mods,$(test)),$($(arg)))

readgeometry = readgeometry.$O geomsetup.$O allocate.$O geomutils.$O geomfaces.$O geometry.$O composite.$O string.$O readdegas.$O readfilenames.$O elementread.$O pmimatread.$O dediagsetup.$O
readgeometry_libs = $(NETCDF)
readgeometry: $(readgeometry) $(foreach arg,$(subst .$O,_mods,$(readgeometry)),$($(arg)))

boxgen = boxgen.$O readfilenames.$O geomsetup.$O allocate.$O composite.$O geomutils.$O geomfaces.$O geometry.$O pmimatread.$O elementread.$O writeback.$O cramdadd.$O dediagsetup.$O reaction.$O random.$O
boxgen_libs = $(CRAMD) $(NETCDF)
boxgen: $(boxgen) $(foreach arg,$(subst .$O,_mods,$(boxgen)),$($(arg)))

cramdproblem = cramdproblem.$O pmimatread.$O cramdadd.$O readfilenames.$O elementread.$O geometry.$O
cramdproblem_libs = $(CRAMD) $(NETCDF)
cramdproblem: $(cramdproblem) $(foreach arg,$(subst .$O,_mods,$(cramdproblem)),$($(arg)))

readfilenames=  readfilenames.$O readfilenames.$O sysdep.$O string.$O
readfilename_libs =
readfilenames: $(readfilenames) $(foreach arg,$(subst .$O,_mods,$(readfilenames)),$($(arg)))

readbackground = readbackground.$O readdegas.$O geometry.$O elementread.$O readfilenames.$O geomsetup.$O allocate.$O reaction.$O composite.$O geomutils.$O geomfaces.$O geometry.$O writeback.$O pmimatread.$O cramdadd.$O random.$O
readbackground_libs = $(CRAMD) $(NETCDF)
readbackground: $(readbackground) $(foreach arg,$(subst .$O,_mods,$(readbackground)),$($(arg)))

reactiontest = reactiontest.$O elementread.$O reaction.$O readfilenames.$O random.$O randother.$O collide.$O pmimatread.$O geometry.$O
reactiontest_libs = $(NETCDF)
reactiontest: $(reactiontest) $(foreach arg,$(subst .$O,_mods,$(reactiontest)),$($(arg)))

pmitest = pmitest.$O elementread.$O pmimatread.$O plate.$O readfilenames.$O random.$O randother.$O geometry.$O reaction.$O
pmitest_libs = $(NETCDF)
pmitest: $(pmitest) $(foreach arg,$(subst .$O,_mods,$(pmitest)),$($(arg)))

sourcetest = sourcetest.$O sources.$O degasinit.$O readfilenames.$O randother.$O random.$O pmimatread.$O elementread.$O geometry.$O cramdadd.$O 
sourcetest_libs = $(NETCDF)
sourcetest: $(sourcetest) $(foreach arg,$(subst .$O,_mods,$(sourcetest)),$($(arg)))

ratecalc = ratecalc.$O $(ALADIR)/aladdin_subr.o readfilenames.$O
ratecalc_libs = $(NETCDF)
ratecalc: $(ratecalc) $(foreach arg,$(subst .$O,_mods,$(ratecalc)),$($(arg)))

dataexam = dataexam.$O readfilenames.o elementread.o
dataexam_libs = $(NETCDF)
dataexam: $(dataexam) $(foreach arg,$(subst .$O,_mods,$(dataexam)),$($(arg)))

tallysetup = tallysetup.$O elementread.$O pmimatread.$O readfilenames.$O string.$O geometry.$O
tallysetup_libs = $(NETCDF)
tallysetup: $(tallysetup) $(foreach arg,$(subst .$O,_mods,$(tallysetup)),$($(arg)))

allocate = allocate.$O
allocate_libs =
allocate: $(allocate) $(foreach arg,$(subst .$O,_mods,$(allocate)),$($(arg)))

#elementread: $(SYSDEPO)
#test: $(SYSDEPO)
#sysdeptest: $(SYSDEPO) string.$O
array: $(SYSDEPO)
teststring: $(SYSDEPO) string.$O
#geomtesta: geometry.$O $(SYSDEPO) string.$O plotgeom.$O elementread.$O
#geomread: geomsetup.$O allocate.$O geomutils.$O geomfaces.$O $(SYSDEPO) geometry.$O composite.$O string.$O elementread.$O
#pvmmaster: pvmmaster.$O $(SYSDEPO) random.$O stat.$O geometry.$O
#pvmslave: pvmslave.$O $(SYSDEPO) random.$O randother.$O stat.$O geometry.$O elementread.$O flight.$O string.$O reaction.$O geomfront.$O
elementlookup: $(SYSDEPO) string.$O
speciesetup: elementread.$O $(SYSDEPO) string.$O
#flighttest: $(SYSDEPO) string.$O elementread.$O geometry.$O random.$O stat.$O randother.$O reaction.$O geomfront.$O flight.$O

netcdf: netcdf.$O
	$(FC) -o $@ $^ -lnetcdf

idtof: idtof.sh
	cp $< $@
	chmod a+x $@

makemodule: makemodule.sh
	cp $< $@
	chmod a+x $@

makedepend: makedepend.sh
	cp $< $@
	chmod a+x $@

depend: makedepend
	./makedepend *.web *.hweb

#aladdin_subr.o: $(ALADIR)/ALPCOM.FOR $(ALADIR)/ALCOM.FOR
#	$(FC) -c -g  $(ALADIR)/aladdin_subr.F

TAGS:
	etags --language=fortran --regex='/[ 	]*define_[a-z]+_pk([a-z]+,[A-Za-z0-9_]+,/' --regex='/[ 	]*@m [A-Za-z0-9_]+(?/' *.web *.hweb

.PHONY: clean %.view %.print TAGS depends

clean:
	rm -f *.o *.f *.cft *.dvi *.tex *.dvi *.ind *.mod *.con *.ps *.aux *.log *.l *.c.c *.view *.print *.tcov *.d *.trace *.blg *.aux0 *.dum *.M *.mweb

