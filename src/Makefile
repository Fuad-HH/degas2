# $Id$

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

ifeq ($(MACHINE),CRAY)
  CRAY=on
endif
ifeq ($(MACHINE),SUN)
  SUN=on
endif
ifeq ($(MACHINE),IBM)
  IBM=on
endif
ifeq ($(MACHINE),ALPHA)
  ALPHA=on
endif
ifeq ($(MACHINE),HP)
  HP=on
endif
ifeq ($(MACHINE),SGI)
  SGI=on
endif
ifeq ($(MACHINE),VAX)
  VAX=on
endif

ifndef CRAY
  TARGET=$(notdir $(shell pwd))
endif

foof:
	echo $(SYSTEM) $(TARGET)

LPRFLAGS=-h
FTANGLE=ftangle
#FTANGLE=/u/krommes/fweb/web/ftangle1.31
FWEAVE=fweave
ifdef DEBUG
  TANGLEFLAGS=-mDEBUG -mINLINE -W[ -ytt500000
#  TANGLEFLAGS=-mDEBUG -mINLINE -W[ -n\)
else
  TANGLEFLAGS=-mINLINE -W[ -ytt500000
#  TANGLEFLAGS=-W[ -n\)
endif
WEAVEFLAGS=-f -i -W[

ifdef CRAY
  FC=cft77
  ifdef DEBUG
    FFLAGS=-e m -e z -a stack -o off
  else
    FFLAGS=-e m -e z -a stack
  endif
  LD=segldr
  SOFT=/nfs/pppl/theory/soft
else
  ifndef IBM
    FC=f77
  else
    FC=xlf
  endif
  LD=$(FC)
  ifdef DEBUG
    FFLAGS=-g -u
    CFLAGS=-g
  else
    FFLAGS=-O
    CFLAGS=-O
  endif
  ifdef SGI
    SOFT=/soft
  else
    SOFT=/soft
  endif
endif

IDENTAPPEND=cat $^ | ident -q | sort | uniq | sed 's/^/c/' >> $@
.PRECIOUS: %.tex %.dvi %.f %.cft %.o

HEADERS=macros.hweb array.hweb sysdep.hweb classes.hweb location.hweb \
    element.hweb species.hweb particle.hweb flight.hweb random.hweb \
    background.hweb zone.hweb vector.hweb reaction.hweb

%.f: %.web $(HEADERS)
	$(FTANGLE) $(TANGLEFLAGS) -m$(TARGET) $<
	fixit $@
	$(IDENTAPPEND)

ifeq ($(TARGET),IBM)
  sysdep.f sysdepc.c: sysdep.web macros.hweb
	$(FTANGLE) $(TANGLEFLAGS) -m$(TARGET) -=c=#c.c $<
	$(IDENTAPPEND)
endif


# Cancel some built-in rules
%: %.f
%: %.c
%.r: %.l
%.o %: %.mod

ifdef CRAY
  SOURCEDIR= ~/afs/degas2
  Makefile: $(SOURCEDIR)/nsrc/Makefile
	cp $< $@
  %.f: $(SOURCEDIR)/CRAY/%.f
	cp $< $@
  idtof.sh: $(SOURCEDIR)/nsrc/idtof.sh
	cp $< $@
  %.o: %.f
	$(FC) $(FFLAGS) $<
else
  %.o: %.f
	$(FC) -c $(FFLAGS) $< -o $@
endif

ifdef SGI
#  LOADLIBES=-L$(SOFT)/sgi/lib -L$(SOFT)/pvm/src/$(PVMARCH) $(SOFT)/pvm/f2c/$(PVMARCH)/libf2c.a -ldf -lpvm -lnetcdf
#  LOADLIBES=-L/usr/local/lib -lnetcdf -lsun
  LOADLIBES=-L/usr/local/lib
else
ifdef CRAY
  LOADLIBES=-L/usr/local/lib -lnetcdf
else
ifdef ALPHA
  LOADLIBES=
else
  LOADLIBES=-L/usr/local/lib -L$(SOFT)/pvm/lib/$(PVMARCH) -ldf -lfpvm3 -lpvm3 -lnetcdf
#  LOADLIBES=-L/usr/local/lib -lnetcdf -ldf
endif
endif
endif

vpath %.web ../nsrc
vpath %.hweb ../nsrc
vpath %.sh ../nsrc

%: %.o
	idtof $(patsubst %.o,%.f,$^) > $*.id.f
ifdef CRAY
	$(FC) $(FFLAGS) $*.id.f
else
	$(FC) -c $(FFLAGS) $*.id.f
endif
	$(LD) $(LDFLAGS) -o $@ $^ $*.id.o $(LOADLIBES)

%.tex: %.web fweb.sty
	$(FWEAVE) $(WEAVEFLAGS) $<

define RUN-LATEX
  if [ -r $*.aux ]; then cp $*.aux $*.aux0; fi
  nfss2ltx $*.tex
  if [ -r $*.aux ]; then cmp -s $*.aux $*.aux0 || nlatex $*.tex; fi
  rm -f $*.aux0
endef

%.dvi: %.tex fweboptions.sty
	$(RUN-LATEX)

%.bbl: %.aux ../../degas.bib
	bibtex $*

%.print: %.dvi
ifndef PAGES
	dvips -f $^ | rsh leo.gat.com lp
#	lpr $(LPRFLAGS) -d $^
else
#	dviselect $(PAGES) $^ | lpr $(LPRFLAGS) -d
	dviselect $(PAGES) $^ | dvips-filter | rsh leo.gat.com lp
endif

#%.view: %.ps
#	ghostview $^

%.view: %.dvi
	xdvi $^

%.ps: %.dvi
	dvips -f $^ > $@

all: programs documentation idtof
programs: randomtest geomtest sysdeptest
documentation: random.dvi randomtest.dvi geometry.dvi geomsetup.dvi \
  geomtest.dvi sysdep.dvi vector.dvi

ifndef CRAY
  array.f: netcdf.hweb
  random.f random.cft random.tex: random.hweb
  randother.f randother.cft randother.tex: random.hweb
  randomtest.f randomtest.cft: random.hweb
  geometry.f geometry.cft geometry.tex: geomint.hweb netcdf.hweb
  geomsetup.f geomsetup.cft geomsetup.tex: geomint.hweb netcdf.hweb
  geomutils.f geomutils.cft geomutils.tex: geomint.hweb
  geomfaces.f geomfaces.cft geomfaces.tex: geomint.hweb
  geomtest.f geomtest.cft geomtest.tex: geomint.hweb random.hweb
  plotgeom.f plotgeom.cft plotgeom.tex: geomint.hweb
  composite.f composite.cft composite.tex: geomint.hweb
  volumes.f volumes.cft volumes.tex: geomint.hweb random.hweb vector.hweb plasma.hweb constants.hweb
  pvmmaster.f pvmmaster.cft pvmmaster.tex: geomint.hweb random.hweb pvm.hweb
  pvmslave.f pvmslave.cft pvmslave.tex: geomint.hweb pvm.hweb
  netcdf.f netcdf.cft netcdf.tex: netcdf.hweb
  elementsetup.f: netcdf.hweb
  elementlookup.f: netcdf.hweb
  speciesetup.f: netcdf.hweb
  geomread.f: geomint.hweb
  plasma.f: plasma.hweb
endif

elementread: sysdep.o
elementsetup: sysdep.o string.o
test: sysdep.o
sysdeptest: sysdep.o string.o
array: sysdep.o
teststring: sysdep.o string.o
randomtest: random.o randother.o
geomtest: geometry.o geomsetup.o geomutils.o geomfaces.o sysdep.o composite.o string.o
geomtesta: geometry.o sysdep.o string.o plotgeom.o elementread.o
geomread: geomsetup.o geomutils.o geomfaces.o sysdep.o geometry.o composite.o string.o elementread.o
pvmmaster: pvmmaster.o sysdep.o random.o stat.o geometry.o
pvmslave: pvmslave.o sysdep.o random.o randother.o stat.o geometry.o elementread.o flight.o string.o reaction.o geomfront.o
elementlookup: sysdep.o string.o
speciesetup: elementread.o sysdep.o string.o
flighttest: sysdep.o string.o elementread.o geometry.o random.o stat.o randother.o reaction.o geomfront.o flight.o
reactionsetup: elementread.o sysdep.o string.o
ifdef IBM
  sysdep: sysdep.o sysdep.c.o
endif

netcdf: netcdf.o
	f77 -o $@ $^ -lnetcdf

idtof: idtof.sh
	cp $< $@
	chmod a+x $@

etags: etags.c
	cc -o etags -g -DETAGS etags.c

TAGS:
	etags *.web *.hweb

.PHONY: clean %.view %.print TAGS

clean:
	rm -f *.o *.f *.cft *.dvi *.tex *.dvi *.ind *.mod *.con *.ps *.aux *.log *.l *.c.c *.view *.print *.tcov *.d *.trace *.blg *.aux0
