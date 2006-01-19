      function vdot(a,b,n)
c
c  version : 20.06.93 20:44
c
      dimension a(*),b(*)
c
      w=0.
      do 100 i=1,n
      w=w+a(i)*b(i)
 100  continue
      vdot=w
c
      end
c
c
c=====================================================
      function vsum(a,n)
c
      dimension a(*)
c
      w=0.
      do 101 i=1,n
      w=w+a(i)
 101  continue
      vsum=w
c
      end
c
c
c=====================================================
      function vmaxa(a,n)
c
      dimension a(*)
c
      w=0.
      do 102 i=1,n
      u=abs(a(i))
      if(u.gt.w) w=u
 102  continue
      vmaxa=w
c
      end
