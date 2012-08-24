#  Original version number from Kukushkin : 02.11.2000 22:29

SHELL=/bin/sh
SYSTEM:=$(shell uname)
VPATH=src
MASTER=kk

ifeq ($(SYSTEM),SunOS)
  MACHINE=SUN
  LIBS=-L /usr/openwin/lib -lXm -lXt -lX11 -lm -lpthread
  CFLAGS=-g
  CC=cc
  INCLUDES=-I/opt/SUNWmotif/include
endif
ifeq ($(SYSTEM),AIX)
  MACHINE=IBM
  LIBS=-lXm -lXt -lX11 -lm -lpthread
  CFLAGS=
  CC=cc
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
ifeq ($(SYSTEM),IRIX64)
  MACHINE=SGI
endif
ifeq ($(SYSTEM),Linux)
#
# Both the 32 and 64 bit Linux OS have uname = Linux; use uname -m to
# differentiate.  The lib64 business may also be peculiar to PPPL; beware.
# An alternative might be to compile with -m32; can then use regular lib.
# 
  IS64:=$(shell uname -m | grep 64)
  ifneq ($(strip $(IS64)),)
    MACHINE=LINUX64
#    LIBS=-L/usr/lib64 -lXm -lXt -lX11 -lm -lpthread
#    CFLAGS=-g 
#    LIBS= -L/usr/lib -lXm -lXt -lX11 -lm -lpthread    
    LIBS= -L/usr/lib -lXm -lm -lpthread    
    CFLAGS=-g -m32
  else
    MACHINE=LINUX
    CFLAGS=-g
    LIBS=-L/usr/lib -lXm -lXt -lX11 -lm -lpthread
  endif
#  LIBS= -L$(LESSTIF) -lXm -L/usr/lib -lXt -lX11 -lm -lpthread
#   CC=gcc34
  CC=gcc
  INCLUDES=-I/usr/local/include
endif

DG=$(MACHINE)/dg
include LISTOBJ

DEST = $(OBJS:%.o=$(MACHINE)/%.o)

$(MACHINE)/%.o : %.c
	 $(CC) $(CFLAGS) -c $< -o $@

$(DG): $(DEST)
	 $(CC) $(CFLAGS) -o $@ $(DEST) $(LIBS)

all: listobj depend $(DG)

update: clean listobj depend all

clean:
	/bin/rm -rf ${MACHINE}/*.o $(DG) *.bak

neat:
	/bin/rm -rf ${MACHINE}/*.o *.bak

tags:
	etags src/*.c src/*.h

depend: ${OBJS:.o=.c}
	makedepend -f  ${MACHINE}/dependencies $^; \
	mv ${MACHINE}/dependencies ${MACHINE}/dependencies.bak; \
	sed -e '3,$$s/^/${MACHINE}\//' ${MACHINE}/dependencies.bak > ${MACHINE}/dependencies

listobj:
	@P=`pwd`; cd src ; rm -f $${P}/LISTOBJ; touch $${P}/LISTOBJ; \
	echo "OBJS =" *.c | sed -e 's/ [^ /]*\// /g' -e 's/\.c/.o/g' -e 's/res2fbr\.o//g' > $${P}/LISTOBJ

${MACHINE}/dependencies:
	touch ${MACHINE}/dependencies

LISTOBJ:
	touch LISTOBJ

include ${MACHINE}/dependencies

