      subroutine prihdi(l,h,n,ncl,mch)
c
c  version : 09.03.93 14:15
c
c=====================================================
c*** printing elements of l, with headers taken from h above them,
c*** ncl columns across the page. output directed to unit mch
c=====================================================
      dimension l(*),h(*)
      character*6 h
      parameter (nclmax=27)
c=====================================================
c
      m=min0(ncl,nclmax)
      m=max0(m,1)
      ke=0
 20   kb=ke+1
      if(kb.gt.n) return
c
      ke=min0(ke+m,n)
      write (mch,700) (h(i),i=kb,ke)
      write (mch,720) (l(i),i=kb,ke)
      go to 20
c-----------------------------------------------------
  700 format(1x,27(2x,a6,1x))
  720 format(1x,i6,26(1x,i8))
c=====================================================
      end
