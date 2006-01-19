      function newmin(n,nk,eps,mr,mi,x,f,d,lim,sys,der)
c
c  version : 14.07.89
c
c=====================================================
c*** solving a system of non-linear algebraic
c*** equations with newton method
c***
c*** input:
c*** n    the number of equations
c*** nw   printout control parameter
c***      0   print nothing
c***      1   print diagnostics if the solution is not found
c***      2   + the last values of arguments and functions
c***      3   + the number of iterations made
c***      4   + the minimum information on each iteration
c***      5   + the values of arguments and functions on each iteration
c*** eps  the accuracy parameter
c*** mr   the maximum number of step reductions on each iteration
c*** mi   the maximum number of iterations
c*** x    the array containing the starting values of the arguments (n)
c*** d    temporary array (n,n+1)
c***
c*** lim, sys, der are the user-supplied routines declared as external
c***
c***      function lim(n,x)
c***      real x(n)
c***
c*** returns positive value if the x vector is in allowable region
c***
c***      subroutine sys(n,x,f)
c***      real x(n),f(n)
c***
c*** calculates the values of functions f(x)
c***
c***      subroutine der(n,x,d)
c***      real x(n),d(n,n)
c***
c*** calculates the derivatives d(i,j) = df(i)/dx(j)
c***
c***
c*** output:
c***
c*** x    the solution (if newmin = 0)
c*** f    the values of functions f(x)
c***
c*** newmin returns the following values:
c***
c***  0   if the solution is found
c***  1   if the local extremum is encountered
c***  2   if the number of reductions is insufficient (this usually
c***      indicates that something is wrong with derivatives)
c***  3   if the specified number of iterations is too small
c***
c*** external subroutines:
c***
c***      lineqn : solving a system of linear algebraic eqations
c***      vmodsq : scalar product squared
c***
c***  reference:
c***
c***  a.s.kukushkin. preprint iae-3116, moscow, 1979.
c=====================================================
      dimension d(n,*),x(n),f(n)
c
      ns=0
      y2=0.
      nsr=0
      nout=0
      iter=0
      call sys(n,x,f)
      dl1=vmodsq(f,n)
      iit=1
      do 100 it=1,mi
      if(nk.lt.4) go to 1
  9   continue
      print 700,iter,nout,nsr,y2,dl1
  700 format(' newmin: iter,nout,nsr,y2,dl1 = ',3(i3,1h,),1p,2e12.4)
      if(nk.eq.4) go to 10
      print 701,x
      print 701,f
  701 format(1p,7e11.4)
 10   if(iit.eq.0) return
  1   call der(n,x,d)
      do 104 i=1,n
      d(i,n+1)=-f(i)
 104  continue
      call lineqn(d,n,ner)
      if(ner.eq.0) go to 2
      newmin=1
      if(nk.gt.0) print 702,ner
  702 format('newmin : derivative matrix ',
     '                'singularity in ',i3,' column')
      go to 3
  2   do 102 i=1,n
      x(i)=x(i)+d(i,1)
 102  continue
      nout=0
      nsr=0
      do 101 j=1,mr
      if(lim(n,x)) 4,4,5
  4   nout=nout+1
      go to 6
  5   call sys(n,x,f)
      dl2=vmodsq(f,n)
      if(dl2.ge.dl1) go to 6
      nsr=j
      dl1=dl2
      y2=vmodsq(d,n)
      go to 11
  6   do 103 i=1,n
      d(i,1)=0.5*d(i,1)
      x(i)=x(i)-d(i,1)
 103  continue
 101  continue
      if(nsr.eq.0) go to 7
      call vsend(d,x,n)
      call vsend(d(1,2),f,n)
 11   if(dl1.le.eps) go to 8
      go to 100
  8   newmin=0
      if(nk.eq.3) print 705,iter
  705 format(' newmin:',i5,'  iterations')
      if(nk.lt.4) return
      iit=0
      go to 9
 100  iter=iter+1
      newmin=3
      if(nk.gt.0) print 703
  703 format(' newmin : short of iterations')
  3   if(nk.le.1) return
      print 701,x
      print 701,f
      return
  7   newmin=2
      if(nk.gt.0) print 704
  704 format(' newmin : short of reductions')
      go to 3
c=====================================================
      end
