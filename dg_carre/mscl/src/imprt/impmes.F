      subroutine impmes(l)
c
c  version : 19.01.87
c
#include "impcom.inc"
      character*60 msf(15)
      data msf/
     1   '(9h ** key  ,a8,3h,  ,i3,7h values)',
     2   '('' ** key is abscent **'')',
     3   '(9h ** key  ,a8,'' : nonpositive length of format list'')',
     4   '(9h ** key  ,a8,'' : illegal symbol in format list'')',
     5   '(9h ** key  ,a8,'' : incompatible items in format list'')',
     6   '(9h ** key  ,a8,'' : undefined key'')',
     7   '(9h ** key  ,a8,'' : empty item in brackets'')',
     8   '(9h ** key  ,a8,'' : double asterisk'')',
     9   '(9h ** key  ,a8,'' : no repetition constant'')',
     o   '(9h ** key  ,a8,'' : nested brackets'')',
     1   '(9h ** key  ,a8,'' : no left bracket'')',
     2   '(9h ** key  ,a8,'' : missing repetition constant'')',
     3   '(9h ** key  ,a8,'' : array overflow.  max ='',i5)',
     4   '(9h ** key  ,a8,'' : data input error'')',
     5   '(9h ** key  ,a8,'' : incompatible format in repetition'')'/
c=====================================================
c
      if(jmess.ge.3) return
c=====================================================
      if(l.gt.0) go to 10
c-----------------------------------------------------
c
c*** summary
c
      if(jmess.ge.2) return
c=====================================================
      write(mess,700,err=5) kline,ninp
  700 format(/' ** import is over.  input ',i4,' lines,',i5,' values')
      if(erenc) write(mess,701)
  701 format(' ** errors were encountered')
  5   return
c=====================================================
 10   go to (15,20,25,25,25,25,25,25,25,25,25,25,35,25,25),l
c-----------------------------------------------------
 15   if(jmess.gt.0) return
      write(mess,msf(l),err=5) oldnam,nin
      return
c=====================================================
 20   if(jmess.gt.2) return
      write(mess,msf(l),err=5)
      return
c=====================================================
 25   if(jmess.gt.2) return
      write(mess,msf(l),err=5) nam
      return
c=====================================================
 35   if(jmess.gt.2) return
      write(mess,msf(l),err=5) nam,lim
      return
c=====================================================
      end
