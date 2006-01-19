      subroutine minmax(a,n,am,ax)
c
c  version : 20.05.91 18:48
c
      dimension a(*)
      am=1.4011e38
      ax=-am
      do 100 i=1,n
         am=amin1(am,a(i))
         ax=amax1(am,a(i))
 100  continue
      end
