      subroutine vrbias(a,n,b)
c
c  version : 19.01.87
c
      dimension a(*)
c
      do 100 i=1,n
      a(i)=a(i)+b
 100  continue
      end
