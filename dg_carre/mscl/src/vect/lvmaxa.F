      function lvmaxa(a,n)
c
c  version : 06.12.94 13:19
c
      dimension a(*)
c
      w=-1.
      l=0
      if(n.le.0) go to 10
      do 100 i=1,n
          b=abs(a(i))
          if(b.le.w) go to 100
          l=i
          w=b
 100  continue
 10   lvmaxa=l
c
      end
c
c
c=====================================================
      function lvmax(a,n)
c
      dimension a(*)
c
      w=-1.e38
      l=0
      if(n.le.0) go to 10
      do 100 i=1,n
          b=a(i)
          if(b.le.w) go to 100
          l=i
          w=b
 100  continue
 10   lvmax=l
c
      end
c
c
c=====================================================
      function lvmin(a,n)
c
      dimension a(*)
c
      w=1.e38
      l=0
      if(n.le.0) go to 10
      do 100 i=1,n
          b=a(i)
          if(b.ge.w) go to 100
          l=i
          w=b
 100  continue
 10   lvmin=l
c
      end
c
c
c=====================================================
      function lvdmin(a,n)
c
      real*8 a(*),b,w
c
      w=1.d300
      l=0
      if(n.le.0) go to 10
      do 100 i=1,n
          b=a(i)
          if(b.ge.w) go to 100
          l=i
          w=b
 100  continue
 10   lvdmin=l
c
      end
