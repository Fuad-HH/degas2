      subroutine lvsend(a,b,n)
c
c  version : 19.01.87
c
c================================================
      dimension a(*),b(*)
c================================================
c
      if(n.le.0) return
c
      do 100 i=1,n
      w=a(i)
      ww=-400.
      if(w.gt.0.) ww=alog(w)
      b(i)=ww
 100  continue
c=======================================
      end
