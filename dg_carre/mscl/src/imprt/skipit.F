      subroutine skipit
c
c  version : 03.04.98 14:03
c
c======================================================================
c*** skips the data corresponding to the current inputname
c======================================================================
#include "impcom.inc"
      character u*(maxlin)
c======================================================================
      entry scipit
c======================================================================
c
      j=jmess
      jmess=5
      call resima(u)
      jmess=j
c
      end
