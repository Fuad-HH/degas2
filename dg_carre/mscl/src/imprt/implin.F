      subroutine implin(nme)
c
c  version : 12.02.93 19:06
c
#include "impcom.inc"
      character nme(maxkey),bbl*8
      real*8 bl
      data bbl / '        ' /
c=====================================================
c
      call bsend(bbl,bl,8)
      if(promp(1).ne.bl .or. promp(2).ne.bl)
     -                          write (mess,700) promp
  700 format(1x,2a8)
      read (mimp,fr,err=40,end=35) (ln(i),i=1,lfin)
      yline = .true.
      kline=kline+1
      nonam=.true.
      lbeg=1
      do 100 i=1,nnum
      if(ln(1).eq.number(i)) return
 100  continue
c
c*** a new name
c
      call bfill(nam,maxkey,blnc)
      if(fixkey) go to 20
c-----------------------------------------------------
c*** free key format
c
      do 101 i=1,maxkey
      if(ln(i).eq.blnc) go to 30
      nme(lbeg)=ln(i)
 101  lbeg=lbeg+1
      go to 30
c-----------------------------------------------------
c*** fixed key format
c
 20   call  bsend(ln,nam,keylen)
      lbeg=keylen+1
 30   nonam=.false.
      return
c=====================================================
 35   backspace mimp
 40   nam=fin
      nonam=.false.
c=====================================================
      end
