#  Original version number from Kukushkin : 28.05.95 18:08
# Modified by D. P. Stotler, ca. 2006

SHELL=/bin/sh
SYSTEM:=$(shell uname)
VPATH=src/amd:src/imprt:src/sfun:src/math:src/matr:src/util:src/vect

ifeq ($(SYSTEM),SunOS)
  MACHINE=SUN
  FC=f77
  CPP=/usr/ccs/lib/cpp
  NFLAGS=-O0 -xtypemap=real:64,double:64,integer:32 -r8const
  FFLAGS=-O -xtypemap=real:64,double:64,integer:32 -r8const
  CPP=/usr/ccs/lib/cpp
endif
ifeq ($(SYSTEM),AIX)
  MACHINE=IBM
# Kukushkin has flag settings, but rather complicated and may be out of date
endif
ifeq ($(SYSTEM),OSF1)
  MACHINE=ALPHA
endif
ifeq ($(SYSTEM),HP-UX)
  MACHINE=HP
endif
ifeq ($(SYSTEM),IRIX)
  MACHINE=SGI
endif
ifeq ($(SYSTEM),Linux)
  MACHINE=LINUX
  CPP=/lib/cpp -C -traditional
  ifeq ($(COMPILER),PATHSCALE)
    FC=pathf90
    NFLAGS=-O0 -r8
    FFLAGS=-O -r8
  endif
  ifeq ($(COMPILER),PGROUP)
    FC=pgf90
    NFLAGS=-O0 -r8 -i4
    FFLAGS=-O -r8 -i4
  endif 
endif

COMPILE=${FC} -c ${FFLAGS}
COMPILENO=${FC} -c ${NFLAGS}
CC=cc -c

SRC= qexith.F qrdarg.F qrneon.F sighve.F svhic0.F svhih.F svhihe.F svieh.F svxhht.F impanl.F impchf.F impdc.F impdca.F implin.F impmes.F import.F impset.F rearr.F rearre.F skipit.F autrkn.F bansys.F evalsp.F evlbcs.F evlspl.F gauss.F gauss2.F lineqn.F newmin.F polint.F solsys.F splbcb.F splcfn.F splcfp.F splinv.F stprkn.F zeroin.F mpres.F mtsend.F trictu.F ddawsn.F derf.F erf.F expinv.F rnd1.F urand.F basenm.F ctail.F ctime.F date2.c ifshtd.F lefta.F prihdi.F prihdr.F scheof.F sortia.F upcase.F bfill.F bsend.F lvmaxa.F lvsend.F minmax.F rbsend.F vadd.F valog.F vbias.F vdot.F vexp.F vmin.F vmod.F vmodsq.F vrbias.F vrvrs.F vsend.F vzero.F

objs=	$(SRC:.F=.o)
OBJS=	$(objs:.c=.o)

LIB = $(MACHINE)/libmscl.a
DEST = $(OBJS:%.o=$(MACHINE)/%.o)

$(MACHINE)/%.o : %.F
	${CPP} -P -C $< ${MACHINE}/$*.f
	$(COMPILE) -o ${MACHINE}/$*.o ${MACHINE}/$*.f

$(MACHINE)/%.o : %.c
	$(CC) -o ${MACHINE}/$*.o $<

all: $(LIB)

$(LIB): $(DEST) Makefile
	ar -r $(LIB) $(DEST)

clean:
	rm -rf ${MACHINE}/*.o ${MACHINE}/*.f $(LIB)

depend: $(SRC)
	makedepend -f	${MACHINE}/dependencies.${MACHINE} $^
	mv ${MACHINE}/dependencies.${MACHINE} ${MACHINE}/dependencies.${MACHINE}.bak
	sed -e '3,$$s/^/${MACHINE}\//' ${MACHINE}/dependencies.${MACHINE}.bak > ${MACHINE}/dependencies.${MACHINE}

listsrc:
	cd src ; echo " " *.F *.c

tags:
	rm TAGS ; etags src/*.F src/*.c

$(MACHINE)/import.o : import.F
	${CPP} -P -C $< $*.f
	$(COMPILENO) -o $*.o $*.f

include ${MACHINE}/dependencies.${MACHINE}
