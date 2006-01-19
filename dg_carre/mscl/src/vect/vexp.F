      subroutine vexp(a,n)
c
c  version : 19.01.87
c
      dimension a(*)
      if(n.le.0) return
      do 100 i=1,n
      a(i)=exp(a(i))
 100  continue
      end
