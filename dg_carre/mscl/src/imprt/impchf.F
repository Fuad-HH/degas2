      subroutine impchf(form,lfr)
c
c  version : 14.01.87
c
#include "impcom.inc"
      character c,form(mfr,lfr)
c=====================================================
c
      if(lfr.gt.0) go to 10
c-----------------------------------------------------
      call impmes(3)
      go to 90
c-----------------------------------------------------
 10   len(1)=lena
      ll=0
      do 100 i=1,lfr
      c=form(1,i)
      do 101 j=1,nform
      if(c.eq.aform(j)) go to 20
 101  continue
      call impmes(4)
      go to 90
c-----------------------------------------------------
 20   l=len(j)
      if(i.eq.1 .or. l.eq.ll) go to 100
      call impmes(5)
      go to 90
c-----------------------------------------------------
 100  ll=l
      leng=l
      return
c=====================================================
 90   dumanl=.true.
c=====================================================
      end
