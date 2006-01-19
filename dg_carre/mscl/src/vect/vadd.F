      subroutine vadd(a,b,x,n)
c
c  version : 20.06.93 20:42
c
      real a(*),b(*),x(*)
c
      do 100 i=1,n
      x(i)=a(i)+b(i)
 100  continue
      end
c
c
c====================================================
      subroutine vsub(a,b,x,n)
c
      real a(*),b(*),x(*)
c
      do 101 i=1,n
      x(i)=a(i)-b(i)
 101  continue
      end
c
c
c====================================================
      subroutine vmul(a,b,x,n)
c
      real a(*),b(*),x(*)
c
      do 102 i=1,n
      x(i)=a(i)*b(i)
 102  continue
      end
c
c
c====================================================
      subroutine vdiv(a,b,x,n)
c
      real a(*),b(*),x(*)
c
      do 103 i=1,n
      x(i)=a(i)/b(i)
 103  continue
      end
c
c
c====================================================
      subroutine vline(a,c,b,d,x,n)
c
      real a(*),b(*),x(*)
c
      do 104 i=1,n
      x(i)=c*a(i)+d*b(i)
 104  continue
      end
c
c
c====================================================
      subroutine vscale(a,c,x,n)
c
      real a(*),x(*)
c
      do 105 i=1,n
      x(i)=c*a(i)
 105  continue
      end
c
c
c====================================================
      subroutine vsqrt(a,x,n)
c
      real a(*),x(*)
c
      do 106 i=1,n
      x(i)=sqrt(a(i))
 106  continue
c
      end
