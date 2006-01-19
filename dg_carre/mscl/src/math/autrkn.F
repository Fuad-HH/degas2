      subroutine autrkn(x,y,f,n,h,hmax,hmin,eps,t,ext,aut,irt)
c
c  version : 25.12.92 15:48
c
c=====================================================
c*** adaptive runge-kutta algorithm for solving the odi system
c***
c***          dy/dx = f(x,y)
c***
c***     a.egorov approach for the residual estimate
c***          (idea by o.arushanyan)
c***
c*** input:
c***
c***   x  - starting value of x
c***   y  - starting values of y(i)
c***   n  - the number of equations
c***   h  - starting value of the integration step
c*** hmax - upper limit of the absolute value of the integration step
c*** hmax - lower limit of the absolute value of the integration step
c***  eps - the accuracy parameter (typically, 0.001)
c***   t  - the target value of x
c***  ext - user-supplied subroutine for calculation of f(x,y)
c***  aut - user-supplied subroutine for analysis of solution
c***
c***
c*** output:
c***
c***   x  - ending value of x
c***   y  - ending values of y(i)
c***  irt - the return code:
c***          0   ok, x=t
c***         -1   error in input parameters (hmax.le.0)
c***          1   stopped by user (nonzero retcode from aut)
c***          2   integration step too small (no convergence)
c***          3   integration step too small (nonzero rc from ext)
c***
c***
c*** external subroutines:
c***
c***      subr. stprkn(x,y,f,n,h,ext,irt)
c***
c***
c*** user-supplied subroutines:
c***
c***      subr. ext(x,y,f,irt)    calculates f(x,y)
c***
c***          irt.ne.0   on return means error and causes step reduction
c***
c***      subr. aut(xold,yold,xnew,ynew,n,h,irt)   analyses current y(x)
c***
c***          xold,yold  are the values from the previous step
c***          xnew,ynew  are the values from the last step
c***          irt.ne.0   on return means "stop integration"
c=====================================================
      dimension y(n),f(n,6)
      logical ub
c=====================================================
c
      ipr=0
      irt=0
      ist=0
      if(hmax.le.0.) then
          irt=-1
          return
      end if
      if(abs(h).lt.hmin) h=hmax
      e1=eps/32.
c
 10   do 100 i=1,n
100   f(i,6)=y(i)
      x1=x
c
 20   h=amin1(h,t-x)
      if(abs(h).lt.hmin) return
c
      call stprkn(x1,f(1,6),f,n,h,ext,ist)
      if(ist.ne.0) then
          h=h*0.5
          ist=0
          if(abs(h).ge.hmin) go to 10
          irt=3
          return
      end if
      do 101 i=1,n
          d=abs(f(i,1)-f(i,2)-f(i,3)+f(i,4))
          if(d.gt.eps) then
              d1=0.
              do 102 k=1,4
102           d1=d1+abs(f(i,k))
              d1=d1*0.25
              if(d.gt.eps*d1) then
                  h=h*0.5
                  if(abs(h).ge.hmin) go to 10
                  irt=2
                  return
              end if
              ub = d.le.e1*d1
          else
              ub = d.le.e1
          end if
101   continue
      call aut(x,y,x1,f(1,6),n,h,ipr)
      if(ipr.ne.0) then
          irt=1
          return
      end if
      if(ub .and. h.lt.hmax) h=2.*h
      x=x1
      do 103 i=1,n
103   y(i)=f(i,6)
      if(abs(x).ge.t) return
      go to 20
c=====================================================
      end
