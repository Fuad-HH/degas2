      subroutine prihdr(a,h,n,ncl,mch)
c
c  version : 04.04.92 21:49
c
c=====================================================
c*** printing elements of a, with headers taken from h above them,
c*** ncl columns across the page. output directed to unit mch
c=====================================================
      dimension a(*),h(*)
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
      write (mch,710) (a(i),i=kb,ke)
      go to 20
c-----------------------------------------------------
  700 format(1x,27(2x,a6,1x))
  710 format(1x,1p,27e9.2)
c=====================================================
      end
