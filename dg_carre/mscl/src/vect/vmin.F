      function vmin(a,n)
c
c  version : 14.06.94 14:27
c
      dimension a(*)
c
      w=a(1)
      do 100 i=2,n
         w=amin1(w,a(i))
 100  continue
      vmin=w
c
      end
c
c
c=====================================================
      function vmax(a,n)
c
      dimension a(*)
c
      w=a(1)
      do 101 i=2,n
          w=amax1(w,a(i))
 101  continue
      vmax=w
c
      end
