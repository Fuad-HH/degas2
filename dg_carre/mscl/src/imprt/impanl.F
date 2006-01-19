      subroutine impanl(arr,lar,nel,form,lfr)
c
c  version : 15.01.87
c
#include "impcom.inc"
      character c,form(mfr,lfr),arr(*)
c=====================================================
c
      if(dumanl) return
c=====================================================
      do 100  j=lbeg,lfin+1
      if(j.gt.lfin) go to 60
c-----------------------------------------------------
      c=ln(j)
      do 101 i=1,lterm
      if(c.eq.term(i)) go to (10,20,30,40,50),i
c-----------------------------------------------------
 101  continue
c
c*** not separator
c
      if(kw.eq.lenw) go to 100
      kw=kw+1
      wr(kw)=c
      go to 100
c-----------------------------------------------------
c
c*** blank
c
 10   go to 100
c-----------------------------------------------------
c
c*** comma
c
 20   if(ybrr) go to 25
      assign 25 to ll
      go to 80
c-----------------------------------------------------
 25   ybrr=.false.
      go to 100
c-----------------------------------------------------
c*** asterisk
c
 30   if(.not.yastr) go to 31
      call impmes(8)
      go to 90
c-----------------------------------------------------
 31   yastr=.true.
      if(kw.gt.0) go to 35
c-----------------------------------------------------
      call impmes(9)
      go to 90
c-----------------------------------------------------
 35   call impdci(wr,nrps,*91)
      nrps=max(nrps,1)
      call bfill(wr,kw,blnc)
      kw=0
      go to 100
c-----------------------------------------------------
c*** left ellipse
c
40    if(.not.ybrl) go to 41
c-----------------------------------------------------
      call impmes(10)
      go to 90
c-----------------------------------------------------
 41   ybrl=.true.
      krpb=ka
      krpf=kf
      if(.not.yastr) go to 42
c-----------------------------------------------------
      nrpb=nrps-1
      nrps=1
      yastr=.false.
      go to 45
c-----------------------------------------------------
 42   call impdci(wr,nrpb,*91)
      nrpb=max(0,nrpb-1)
      call bfill(wr,kw,blnc)
      kw=0
 45   go to 100
c-----------------------------------------------------
c*** right ellipse
c
 50   if(ybrl) go to 51
c-----------------------------------------------------
      call impmes(11)
      assign 90 to ll
      go to 80
c-----------------------------------------------------
 51   assign 53 to ll
      go to 80
c-----------------------------------------------------
 53   assign 55 to ll
      go to 85
c-----------------------------------------------------
 55   call bfill(wr,kw,blnc)
      kw=0
      ybrl=.false.
      nrpb=0
      yastr=.false.
      ybrr=.true.
      go to 100
c-----------------------------------------------------
 60   if(kw.eq.0) go to 70
      assign 70 to ll
      go to 80
c-----------------------------------------------------
 70   if(ybrl.and.immed) go to 75
 72   return
c=====================================================
 75   assign 72 to ll
      go to 85
c-----------------------------------------------------
 80   c=form(1,kf)
      do 102 l=1,nform
      if(c.eq.aform(l)) go to 81
 102  continue
 81   call impdc(l,wr,ww,*93)
      do 103 i=1,nrps
      exls=nel.ge.lar
      if(exls) go to 92
      if(kw.gt.0) go to 82
      if(.not.ybrl) go to 83
c-----------------------------------------------------
      call impmes(7)
      go to 90
c-----------------------------------------------------
 82   if(form(1,kf).ne.c) go to 94
      call bsend(ww,arr(ka),leng)
      nin=nin+1
      ninp=ninp+1
 83   ka=ka+leng
      kf=mod(kf,lfr)+1
      nel=nel+1
 103  continue
      call bfill(wr,kw,blnc)
      kw=0
      nrps=1
      yastr=.false.
      go to ll
c-----------------------------------------------------
 85   m=ka
      do 104  i=1,nrpb
      k=krpb
 87   exls=nel.ge.lar
      if(exls) go to 92
      if(form(1,kf).ne.form(1,krpf)) go to 94
      call bsend(arr(k),arr(ka),leng)
      nel=nel+1
      nin=nin+1
      ninp=ninp+1
      ka=ka+leng
      k=k+leng
      kf=mod(kf,lfr)+1
      if(k.lt.m) go to 87
c-----------------------------------------------------
 104  continue
      go to ll
c-----------------------------------------------------
 100  continue
c-----------------------------------------------------
 90   dumanl=.true.
      return
c=====================================================
 91   call impmes(12)
      go to 90
c-----------------------------------------------------
 92   call impmes(13)
      go to 90
c-----------------------------------------------------
 93   call impmes(14)
      go to 90
c-----------------------------------------------------
 94   call impmes(15)
      go to 90
c=====================================================
      end
