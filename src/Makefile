# $Id$
# $Log$
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

foof:
	echo $(TEMP)

utils: idtof Makefile

# Deal with location of things

ifndef DEGASROOT
    DEGASROOT=$(HOME)
endif

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
  SOURCEDIR=$(DEGASROOT)/degas2/src
  vpath %.web $(SOURCEDIR)
  vpath %.hweb $(SOURCEDIR)
endif
endif

ALADIR=$(DEGASROOT)/degas2/Aladdin

Makefile: $(SOURCEDIR)/Makefile
	cp $< $@
%.sh: $(SOURCEDIR)/%.sh
	cp $< $@
%.el: $(SOURCEDIR)/%.el
	cp $< $@
%.sty: $(SOURCEDIR)/%.sty
	cp $< $@

# Set up librarys
LIBROOT=/usr/local

NETCDF=-L$(LIBROOT)/lib -lnetcdf
HDF=-L$(LIBROOT)/lib -ldf
PVM=-L$(PVM_ROOT)/pvm3/lib/$(PVMARCH) -lfpvm3 -lpvm3

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
FTANGLE=ftangle
FWEAVE=fweave
LATEX=latex
ifeq ($(DEBUG),yes)
  TANGLEFLAGS=-mDEBUG -mINLINE -W[ -ytt4000000 -yn8000 -n/ -n')' -Tv -j
else
  TANGLEFLAGS=-mINLINE -W[ -ytt4000000 -yn8000 -n/ -n')' -Tv
endif
WEAVEFLAGS=-f -i -W[ -ykw600 -j -n/

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
    FFLAGS=-c -O $(PROFILE)
    LDFLAGS=$(PROFILE)
    CFLAGS=-O
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
	$(FC) $(FFLAGS) $<
  %: %.o $(SYSDEPO) string.$O idtof
	idtof $(patsubst %.$O,%.f,$^) > $*.id.f
	$(FC) $(FFLAGS) $*.id.f
	$(LD) $(LDFLAGS) -o $@ $(filter-out idtof,$^) $*.id.o $($@_libs)
else # We're cross compiling
  O=f
  %: %.o
  %: %.$O sysdep.$O string.$O idtof
	@echo Made $^
endif

IDENTAPPEND=cat $^ | ident -q | sort | uniq | sed 's/^/c/' >> $@
.PRECIOUS: %.tex %.dvi %.f %.cft %.o %.dum fweb.sty fweboptions.sty

HEADERS=macros.hweb array.hweb sysdep.hweb classes.hweb location.hweb \
    element.hweb species.hweb particle.hweb flight.hweb random.hweb \
    background.hweb zone.hweb vector.hweb reaction.hweb xsection.hweb \
    ratecalc.hweb problem.hweb reactiondata.hweb sources.hweb segment.hweb \
    pmi.hweb pmiformat.hweb 

%.f: %.web $(HEADERS)
	$(FTANGLE) $(TANGLEFLAGS) -m$(TARGET) $<
	$(IDENTAPPEND)

# include files
geomfaces.f geomfront.f geomtest.f geomtesta.f geomutils.f plotgoem.f composite.f geometry.f geomsetup.f: geomint.hweb

degasgeom.f: degas.hweb geomint.hweb

ifeq ($(TARGET),IBM)
  sysdep.f sysdepc.c: sysdep.web macros.hweb
	$(FTANGLE) $(TANGLEFLAGS) -m$(TARGET) -=c=#c.c $<
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

all: programs documentation idtof
programs: randomtest geomtest sysdeptest
documentation: random.dvi randomtest.dvi geometry.dvi geomsetup.dvi \
  geomtest.dvi sysdep.dvi vector.dvi

sysdeptest = $(SYSDEPO)
sysdeptest_libs = 
sysdeptest: $(sysdeptest)

# elementsetup =
# elementsetup_libs = $(NETCDF)
# elementsetup: $(elementsetup)

# speciesetup = elementread.$O
# speciesetup_libs = $(NETCDF)
# speciesetup: $(speciesetup)

randomtest = random.$O randother.$O
randomtest_libs =
randomtest: $(randomtest)

pvmmaster = random.$O stat.$O geometry.$O
pvmmaster_libs = $(NETCDF) $(PVM)
pvmmaster: $(pvmmaster)

pvmslave = random.$O randother.$O stat.$O geometry.$O elementread.$O flight.$O reaction.$O geomfront.$O
pvmslave_libs = $(NETCDF) $(PVM)
pvmslave: $(pvmslave)

flighttest = elementread.$O geometry.$O random.$O stat.$O randother.$O reaction.$O geomfront.$O flight.$O sources.$O collide.$O
flighttest_libs = $(NETCDF)
flighttest: $(flighttest)

geomtesta = geometry.$O plotgeom.$O elementread.$O
geomtesta_libs = $(HDF) $(NETCDF)
geomtesta: $(geomtesta)

reactionwrite = 
reactionwrite_libs = $(NETCDF)
reactionwrite: $(reactionwrite)

pmiwrite =
pmiwrite_libs = $(NETCDF)
pmiwrite: $(pmiwrite)

datasetup = elementread.$O elementsetup.$O speciesetup.$O reactionsetup.$O
datasetup_libs = $(NETCDF)
datasetup: $(datasetup)

problemsetup = elementread.$O reaction.$O
problemsetup_libs = $(NETCDF)
problemsetup: $(problemsetup)

geomread = geomsetup.$O geomutils.$O geomfaces.$O $(SYSDEPO) geometry.$O composite.$O string.$O elementread.$O
geomread_libs = $(NETCDF)
geomread: $(geomread)

degasgeom = geomsetup.$O geomutils.$O geomfaces.$O geometry.$O composite.$O random.$O
degasgeom_libs = $(NETCDF)
degasgeom: $(degasgeom)

test = geomsetup.$O geomutils.$O geomfaces.$O geometry.$O composite.$O
test_libs = $(NETCDF)
test: $(test)

readgeometry = geomsetup.$O geomutils.$O geomfaces.$O geometry.$O composite.$O string.$O readdegas.$O
readgeometry_libs = $(NETCDF)
readgeometry: $(readgeometry)

readfilenames= readfilenames.$O sysdep.$O string.$O
readfilename_libs =
readfilenames: $(readfilenames)

readbackground = readdegas.$O geometry.$O elementread.$O
readbackground_libs = $(NETCDF)
readbackground: $(readbackground)

reactiontest = reactiontest.$O elementread.$O reaction.$O
reactiontest_libs = $(NETCDF)
reactiontest: $(reactiontest)

ratecalc = $(ALADIR)/aladdin_subr.o
ratecalc_libs = $(NETCDF)
ratecalc: $(ratecalc)

#elementread: $(SYSDEPO)
#test: $(SYSDEPO)
#sysdeptest: $(SYSDEPO) string.$O
array: $(SYSDEPO)
teststring: $(SYSDEPO) string.$O
geomtest: geometry.$O geomsetup.$O geomutils.$O geomfaces.$O $(SYSDEPO) composite.$O string.$O
#geomtesta: geometry.$O $(SYSDEPO) string.$O plotgeom.$O elementread.$O
#geomread: geomsetup.$O geomutils.$O geomfaces.$O $(SYSDEPO) geometry.$O composite.$O string.$O elementread.$O
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

../$(MACHINE)/etags: etags.c getopt.c getopt1.c getopt.h
	gcc -o $@ -g -DETAGS -Demacs etags.c getopt.c getopt1.c

#aladdin_subr.o: $(ALADIR)/ALPCOM.FOR $(ALADIR)/ALCOM.FOR
#	$(FC) -c -g  $(ALADIR)/aladdin_subr.F

TAGS:  ../$(MACHINE)/etags
	$< *.web *.hweb

.PHONY: clean %.view %.print TAGS

clean:
	rm -f *.o *.f *.cft *.dvi *.tex *.dvi *.ind *.mod *.con *.ps *.aux *.log *.l *.c.c *.view *.print *.tcov *.d *.trace *.blg *.aux0 *.dum
