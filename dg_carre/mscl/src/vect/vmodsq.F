      function vmodsq(a,n)
c
c  version : 19.01.87
c
      dimension a(*)
c
      w=0.
      do 100 i=1,n
      w=w+a(i)**2
 100  continue
      vmodsq=w
c
      end
