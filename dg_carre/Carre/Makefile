#  Original version number from Kukushkin : 27.07.97 22:41
#  Modified by D. P. Stotler ca. 2005.

SHELL=/bin/sh
SYSTEM:=$(shell uname)
#
# To compile with NCAR, be sure the environment variable NCARG_ROOT is
# set before running gmake.  Gmake will make it into a local variable
# here.  To compile without NCAR, leave this variable unset.  Note
# that LISTOBJ needs to be remade to add or remove NCAR.
#
INCLUDE =	-Isrc/include
MSCL=../mscl/$(MACHINE)
EQUTRN=../DG/equtrn
ifdef NCARG_ROOT
  VPATH	=	src/carre:src/cntour:src/graphe:src/trans:src/fcrr:$(EQUTRN)/src/shared
  NCAR_LIBS =   -L$(NCARG_ROOT)/lib -lncarg -lncarg_gks -lncarg_c
else
  VPATH	=	src/carre:src/trans:src/fcrr:$(EQUTRN)/src/shared:src/dummy
  NCAR_LIBS =   
endif
CPP=/usr/lib/cpp
DEBUG=yes

ifeq ($(SYSTEM),SunOS)
  MACHINE=SUN
  FC=f77
  CPP=/usr/ccs/lib/cpp
  ifeq ($(DEBUG),yes)
    FFLAGS=-g -C 
  else
    FFLAGS=-O
  endif
#  DBLPAD=-r8 -i4
  DBLPAD=-xtypemap=real:64,double:64,integer:32 -r8const
#  LDLIBS=-L$${NCARG_ROOT}/lib -L$(MSCL)
#   LDFLAGS=-lncarg -lncarg_gks -lncarg_c -lX11 -lm -lmscl -lsocket
  LDLIBS=-L$(MSCL)
  LDFLAGS=$(NCAR_LIBS) -lX11 -lm -lmscl -lsocket
  LDEXTRA= 
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
  DEFINES=-DHPUX
  FC=f77
  CPP=/lib/cpp
  ifeq ($(DEBUG),yes)
    FFLAGS=-g -C -R8 +FPOZV
  else
    FFLAGS=+O3 -R8
  endif
  DBLPAD= 
  LDLIBS=-Wl,-L${SOLPSTOP}/src/lib/${MACHINE} -Wl,-L$${NCARG_ROOT}/lib -Wl,-L/usr/lib/X11R5
  LDFLAGS=-lncarg -lncarg_gks -lncarg_c -lncarg_loc -lmach -lX11 -lm
  LDEXTRA= 
endif
ifeq ($(SYSTEM),IRIX)
  MACHINE=SGI
endif
ifeq ($(SYSTEM),Linux)
  MACHINE=LINUX
  CPP=/lib/cpp -C -traditional
#  LDLIBS= -L$${NCARG_ROOT}/lib -L$(MSCL)
#  LDFLAGS=-lncarg -lncarg_gks -lncarg_c -L/usr/X11R6/lib -lX11 -lm -lmscl
  LDLIBS=-L$(MSCL)
  LDFLAGS=$(NCAR_LIBS) -L/usr/X11R6/lib -lX11 -lm -lmscl
  LDEXTRA= 
#
#  See about setting the compiler via an environment variable
#  COMPILER=PATHSCALE
#  COMPILER=PGROUP
#
# Note: have detected an incompatibility between PathScale and NCAR. 
# Suggest compiling without NCAR when using PathScale Fortran.
#
  ifeq ($(COMPILER),PATHSCALE)
    FC=pathf90
    ifeq ($(DEBUG),yes)
      FFLAGS=-g -C
    else
      FFLAGS=-O
    endif
    DBLPAD=-r8
  endif
  ifeq ($(COMPILER),PGROUP)
    FC=pgf90
    ifeq ($(DEBUG),yes)
      FFLAGS=-g -C 
    else
      FFLAGS=-O
    endif
    DBLPAD=-r8 -i4
  endif 
endif
    
COMPILE=${FC} -c ${FFLAGS}

EXCLUDELIS = carre.o tradui.o fcrr.o fcrblkd.o

include LISTOBJ

DEST = $(OBJS:%.o=$(MACHINE)/%.o)
MAINLIST = $(EXCLUDELIS:.=\.)
LIBRARIES = $(LDFLAGS:-l%=${LIBSOLDIR}/lib%.a)

$(MACHINE)/%.o : %.F
	- /bin/rm -f ${MACHINE}/$*.f
	${CPP} ${DEFINES} -P -C ${INCLUDE} $< ${MACHINE}/$*.f; \
	case $< in \
		src/trans/* ) $(COMPILE) $(DBLPAD) -o ${MACHINE}/$*.o ${MACHINE}/$*.f;; \
		       *    ) $(COMPILE) -o ${MACHINE}/$*.o ${MACHINE}/$*.f;; \
	esac; \
	if [ -f $*.o ]; then /bin/mv $*.o ${MACHINE}; fi

all: ${MACHINE}/carre ${MACHINE}/traduit ${MACHINE}/fcrr

${MACHINE}/carre: ${MACHINE}/carre.o ${MACHINE}/libcarre.a
	rm -f ${MACHINE}/carre 2>/dev/null; \
	${FC} $(FFLAGS) -o ${MACHINE}/carre ${MACHINE}/carre.o ${MACHINE}/libcarre.a ${LDLIBS} $(LDFLAGS) $(LDEXTRA)

${MACHINE}/traduit: ${MACHINE}/tradui.o ${MACHINE}/libcarre.a
	rm -f ${MACHINE}/traduit 2>/dev/null; \
	${FC} $(FFLAGS) -o ${MACHINE}/traduit ${MACHINE}/tradui.o ${MACHINE}/libcarre.a ${LDLIBS} $(LDFLAGS) $(LDEXTRA)

${MACHINE}/fcrr: ${MACHINE}/fcrr.o ${MACHINE}/fcrblkd.o ${MACHINE}/libcarre.a ${MSCL}/libmscl.a Makefile
	rm -f ${MACHINE}/fcrr 2>/dev/null; \
	${FC} $(FFLAGS) -o ${MACHINE}/fcrr ${MACHINE}/fcrr.o ${MACHINE}/fcrblkd.o ${MACHINE}/libcarre.a ${LDLIBS} $(LDFLAGS) $(LDEXTRA)

${MACHINE}/libcarre.a: ${DEST}
	ar r $@ $?
	ranlib $@

clean:
	rm -rf ${MACHINE}/*.o ${MACHINE}/*.f ${MACHINE}/libcarre.a ${MACHINE}/carre ${MACHINE}/traduit ${MACHINE}/fcrr

neat:
	rm -rf ${MACHINE}/*.o ${MACHINE}/*.f

local:
	-rm rzpsi.mtv rzpsi.ps map loadmap gnuplot.data gnuplot.cmd
	-gtfl btor.dat structure.dat rzpsi.dat ncar.cfg gmeta fort.11 carre.out carre.log carre.dat warnings.dat traduit.log selptx.inf traduit.out 

tags:
	rm TAGS ; etags src/*/*.F $(EQUTRN)/src/shared/*.F

depend: ${OBJS:.o=.F} ${EXCLUDELIS:.o=.F}
	makedepend -f	${MACHINE}/dependencies.${MACHINE} ${INCLUDE} $^
	mv ${MACHINE}/dependencies.${MACHINE} ${MACHINE}/dependencies.${MACHINE}.bak
	sed -e '3,$$s/^\.\.\/src\/[^\/]*\///' ${MACHINE}/dependencies.${MACHINE}.bak | \
	sed -e '3,$$s/^/${MACHINE}\//' > ${MACHINE}/dependencies.${MACHINE}

listobj:
	@rm -f LISTOBJ; touch LISTOBJ; l="OBJS ="; \
	for d in `echo "$(VPATH)" | tr : \ `; do \
		l="$$l `(cd $$d > /dev/null; echo *.F)`"; \
	done; \
	E="-e 's/\.F/\.o/g'" ; for f in $(MAINLIST); do \
		E="$$E -e 's/ $$f//'"; \
	done; \
	echo "$$l" | eval sed "$$E" > LISTOBJ

LISTOBJ: listobj

include ${MACHINE}/dependencies.${MACHINE}

# DO NOT DELETE THIS LINE -- make depend depends on it.
