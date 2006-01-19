      real function zeroin(ax,bx,f,tol)
c
c  version : 29.10.92 16:11
c
c=====================================================
c*** calculates the zero of function f(x),  ax < x < bx
c***
c*** input data:
c***
c***  ax      left edge of the interval
c***  bx      right edge of the interval
c***  f       function
c***  tol     desirable tolerance
c***
c*** f(ax) and f(bx) must be of different sign - no checking
c***
c*** source:  g.forsythe et al. computer methods for mathematical
c***          computations.
c=====================================================
      real ax,bx,tol
      real a,b,c,d,e,eps,fa,fb,fc,tol1,xm,p,q,r,s
      eps=1.0
10    eps=eps/2.0
      tol1=1.0+eps
      if(tol1.gt.1.0) go to 10
      a=ax
      b=bx
      fa=f(a)
      fb=f(b)
20    c=a
      fc=fa
      d=b-a
      e=d
30    if(abs(fc).ge.abs(fb)) go to 40
      a=b
      b=c
      c=a
      fa=fb
      fb=fc
      fc=fa
40    tol1=2.0*eps*abs(b)+0.5*tol
      xm=0.5*(c-b)
      if(abs(xm).le.tol1) go to 90
      if(fb.eq.0.0) go to 90
      if(abs(e).lt.tol1) go to 70
      if(abs(fa).le.abs(fb)) go to 70
      if(a.ne.c) go to 50
      s=fb/fa
      p=2.0*xm*s
      q=1.0-s
      go to 60
50    q=fa/fc
      r=fb/fc
      s=fb/fa
      p=s*(2.0*xm*q*(q-r)-(b-a)*(r-1.0))
      q=(q-1.0)*(r-1.0)*(s-1.0)
60    if(p.gt.0.0) q=-q
      p=abs(p)
      if((2.0*p).ge.(3.0*xm*q-abs(tol1*q))) go to 70
      if(p.ge.abs(0.5*e*q)) go to 70
      e=d
      d=p/q
      go to 80
70    d=xm
      e=d
80    a=b
      fa=fb
      if(abs(d).gt.tol1) b=b+d
      if(abs(d).le.tol1) b=b+sign(tol1,xm)
      fb=f(b)
      if((fb*(fc/abs(fc))).gt.0.0) go to 20
      go to 30
90    zeroin=b
      return
      end
