      subroutine vsend(a,b,n)
c
c  version : 18.05.94 12:48
c
      integer a(*),b(*)
c
      entry ivsend(a,b,n)
c
      do 100 i=1,n
 100  b(i)=a(i)
c
      end
c
c
c=====================================================
      subroutine vmove(a,b,n)
c
      integer a(*),b(*)
c
      entry ivmove(a,b,n)
c
      do 110 i=1,n
         b(i)=a(i)
         a(i)=0.
 110  continue
c
      end
c
c
c=====================================================
      subroutine rvsend(a,b,n)
c
      integer a(*),b(*)
c
      entry irvsnd(a,b,n)
c
      do 120 i=n,1,-1
 120  b(i)=a(i)
c
      end
c
c
c=====================================================
      subroutine vfill(a,n,k)
c
      integer a(*)
c
      entry ivfill(a,n,k)
c
      do 130 i=1,n
 130  a(i)=k
c
      end
c
c
c=====================================================
      subroutine vswap(a,b,n)
c
      integer a(*),b(*)
c
      entry ivswap(a,b,n)
c
      do 100 i=1,n
          u=a(i)
          a(i)=b(i)
 100  b(i)=u
c
      end
