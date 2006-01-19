      subroutine valog(a,n)
c
c  version : 19.01.87
c
      dimension a(*)
c
      if(n.le.0) return
c
      do 100 i=1,n
      w=a(i)
      ww=-400.
      if(w.gt.0.) ww=alog(w)
      a(i)=ww
 100  continue
      end
