      subroutine rearr(arr,lar,nel,form,lfr)
c
c  version : 19.01.87
c
c=====================================================
#include "impcom.inc"
      logical b
c=====================================================
c
      done=.true.
      lim=lar
      nin=0
      dumanl=.false.
c
c*** check the format list
c
      call impchf(form,lfr)
c
c*** set the beginning
c
      call impset(nel)
c
c*** analyse the line
c
 10   call impanl(arr,lar,nel,form,lfr)
      yline = .false.
c
c*** and proceed to the next one
c
      oldnam=nam
      if(immed) go to 20
c-----------------------------------------------------
      call implin(nam)
      if(nonam) go to 10
      if(.not.ybrl) go to 20
c-----------------------------------------------------
      l=lbeg
      lbeg=lfin+1
      b = immed
      immed = .true.
      call impanl(arr,lar,nel,form,lfr)
      lbeg=l
      immed = b
 20   call impmes(1)
c=====================================================
      end
