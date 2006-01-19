      subroutine stprkn(x,y,f,n,h,ext,ist)
c
c  version : 25.12.92 15:24
c
c=====================================================
c*** runge-kutta integration over one step in x
c***  (ancilliary code for autrkn)
c=====================================================
      dimension y(n),f(n,5),am(3),bm(4)
      data am /2*0.5,1./, bm /1.,2*2.,1./
c=====================================================
c
      h6=h/6.
      ist=0
      iex=0
      call ext(x,y,f,iex)
      if(iex.ne.0) go to 30
      do 101 j=2,4
          a=am(j-1)*h
          do 102 i=1,n
              f(i,5)=f(i,j-1)*a+y(i)
102       continue
          call ext(x+a,f(1,5),f(1,j),iex)
          if(iex.ne.0) go to 30
101   continue
      do 103 i=1,n
          do 103 j=1,4
              y(i)=y(i)+f(i,j)*h6*bm(j)
103   continue
      x=x+h
      return
c=====================================================
 30   ist=1
c=====================================================
      end
