      subroutine vbias(a,s,b,n)
      dimension a(*),b(*)
      do 100 i=1,n
      b(i)=a(i)+s
 100  continue
      end
