      subroutine polint (f,a,n,x,r)
c
c  version : 20.02.89
c
      real f(n),a(n)
c
      r=0.
      do 100 j=1,n
         al=1.
         do 101 i=1,n
              if(i.ne.j) al=al*(x-a(i))/(a(j)-a(i))
 101     continue
 100  r=r+al*f(j)
c
      end
