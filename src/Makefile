# $Id$
# $Log$
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
	echo $(MACHINE) $(TARGET) $(SOURCEDIR)

utils: idtof fixit Makefile

# Deal with location of things

ifeq ($(MACHINE),CRAY)
  SOURCEDIR=$(HOME)/degas2/$(MACHINE)
  %.f: $(SOURCEDIR)/%.f
	cp $< $@
else
ifeq ($(MACHINE),HP)
  SOURCEDIR=$(HOME)/degas2/$(MACHINE)
  %.f: $(SOURCEDIR)/%.f
	cp $< $@
else
  SOURCEDIR=$(HOME)/degas2/src
  vpath %.web $(SOURCEDIR)
  vpath %.hweb $(SOURCEDIR)
endif
endif

ALADIR=$(HOME)/degas2/Aladdin

Makefile: $(SOURCEDIR)/Makefile
	cp $< $@
%.sh: $(SOURCEDIR)/%.sh
	cp $< $@
%.el: $(SOURCEDIR)/%.el
	cp $< $@
%.sty: $(SOURCEDIR)/%.sty
	cp $< $@

# Set up librarys
NETCDF=-L/usr/local/lib -lnetcdf
HDF=-L/usr/local/lib -ldf
PVM=-L/soft/pvm/lib/$(PVMARCH) -lfpvm3 -lpvm3

# Cancel some built-in rules
%: %.f
%: %.c
%.c: %.l
%.r: %.l
%.o %: %.mod
%.p: %.web
%.tex: %.web
%.dvi: %.tex

# Set up compilers etc.
ifeq ($(PRINTER),"")
 LPRFLAGS=-h
else
 LPRFLAGS=-h -P$(PRINTER)
endif
FTANGLE=ftangle
FWEAVE=fweave
LATEX=latex
ifdef DEBUG
  TANGLEFLAGS=-mDEBUG -mINLINE -W[ -ytt2000000 -yn6000
else
  TANGLEFLAGS=-mINLINE -W[ -ytt2000000 -yn6000
endif
WEAVEFLAGS=-f -i -W[ -ykw600

ifeq ($(MACHINE),CRAY)
  FC=cft77
  ifdef DEBUG
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
  ifdef DEBUG
    FFLAGS=-c -g -u
    CFLAGS=-g
  else
    FFLAGS=-c -O
    CFLAGS=-O
  endif
endif

ifndef CROSSCOMPILE
  O=o
  %.o: %.f
	$(FC) $(FFLAGS) $<
  %: %.o sysdep.$O string.$O idtof
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
.PRECIOUS: %.tex %.dvi %.f %.cft %.o %.dum fweb.sty fweboptions.sty fixit fixit.el

HEADERS=macros.hweb array.hweb sysdep.hweb classes.hweb location.hweb \
    element.hweb species.hweb particle.hweb flight.hweb random.hweb \
    background.hweb zone.hweb vector.hweb reaction.hweb xsection.hweb \
    ratecalc.hweb

%.f: %.web $(HEADERS) fixit
	$(FTANGLE) $(TANGLEFLAGS) -m$(TARGET) $<
	fixit $@
	$(IDENTAPPEND)

# include files
# geomsetup.f: geomint.hweb
# degasgeom.f: degas.hweb geomint.hweb

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
#	dvips -f $^ | rsh leo.gat.com lp
	lpr $(LPRFLAGS) -d $^
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

sysdeptest =
sysdeptest_libs = 
sysdeptest: $(sysdeptest)

elementsetup =
elementsetup_libs = $(NETCDF)
elementsetup: $(elementsetup)

speciesetup = elementread.$O
speciesetup_libs = $(NETCDF)
speciesetup: $(speciesetup)

randomtest = random.$O randother.$O
randomtest_libs =
randomtest: $(randomtest)


pvmmaster = random.$O stat.$O geometry.$O
pvmmaster_libs = $(NETCDF) $(PVM)
pvmmaster: $(pvmmaster)

pvmslave = random.$O randother.$O stat.$O geometry.$O elementread.$O flight.$O reaction.$O geomfront.$O
pvmslave_libs = $(NETCDF) $(PVM)
pvmslave: $(pvmslave)

flighttest = elementread.$O geometry.$O random.$O stat.$O randother.$O reaction.$O geomfront.$O flight.$O
flighttest_libs = $(NETCDF)
flighttest: $(flighttest)

geomtesta = geometry.$O plotgeom.$O elementread.$O
geomtesta_libs = $(HDF) $(NETCDF)
geomtesta: $(geomtesta)

reactionwrite = 
reactionwrite_libs = $(NETCDF)
reactionwrite: $(reactionwrite)

reactionsetup = elementread.$O
reactionsetup_libs = $(NETCDF)
reactionsetup: $(reactionsetup)

geomread = geomsetup.$O geomutils.$O geomfaces.$O sysdep.$O geometry.$O composite.$O string.$O elementread.$O
geomread_libs = $(NETCDF)
geomread: $(geomread)

degasgeom = geomsetup.$O geomutils.$O geomfaces.$O geometry.$O composite.$O random.$O
degasgeom_libs = $(NETCDF)
degasgeom: $(degasgeom)

ratecalc = $(ALADIR)/aladdin_subr.o
ratecalc_libs = $(NETCDF)
ratecalc: $(ratecalc)

#elementread: sysdep.$O
#test: sysdep.$O
#sysdeptest: sysdep.$O string.$O
array: sysdep.$O
teststring: sysdep.$O string.$O
geomtest: geometry.$O geomsetup.$O geomutils.$O geomfaces.$O sysdep.$O composite.$O string.$O
#geomtesta: geometry.$O sysdep.$O string.$O plotgeom.$O elementread.$O
#geomread: geomsetup.$O geomutils.$O geomfaces.$O sysdep.$O geometry.$O composite.$O string.$O elementread.$O
#pvmmaster: pvmmaster.$O sysdep.$O random.$O stat.$O geometry.$O
#pvmslave: pvmslave.$O sysdep.$O random.$O randother.$O stat.$O geometry.$O elementread.$O flight.$O string.$O reaction.$O geomfront.$O
elementlookup: sysdep.$O string.$O
speciesetup: elementread.$O sysdep.$O string.$O
#flighttest: sysdep.$O string.$O elementread.$O geometry.$O random.$O stat.$O randother.$O reaction.$O geomfront.$O flight.$O
ifeq ($(MACHINE),IBM)
  sysdep: sysdep.$O sysdep.c.$O
endif

netcdf: netcdf.$O
	$(FC) -o $@ $^ -lnetcdf

idtof: idtof.sh
	cp $< $@
	chmod a+x $@

fixit: fixit.sh fixit.el
	cp $< $@
	chmod a+x $@
	
etags: etags.c getopt.c getopt1.c getopt.h
	gcc -o etags -g -DETAGS -Demacs etags.c getopt.c getopt1.c

#aladdin_subr.o: $(ALADIR)/ALPCOM.FOR $(ALADIR)/ALCOM.FOR
#	$(FC) -c -g  $(ALADIR)/aladdin_subr.F

TAGS:  etags
	etags *.web *.hweb

.PHONY: clean %.view %.print TAGS

clean:
	rm -f *.o *.f *.cft *.dvi *.tex *.dvi *.ind *.mod *.con *.ps *.aux *.log *.l *.c.c *.view *.print *.tcov *.d *.trace *.blg *.aux0 *.dum
