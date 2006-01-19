      subroutine splinv(t,x,y,dr,f,n,md,nd,mf,ir)
c
c  version : 17.03.93 14:13
c
c=====================================================
      dimension x(n),y(*),dr(*),f(*)
c=====================================================
c
      ir=-1
      kk=1
      a=0
      b=0
      c=1
      d=t-x(1)
      k=1
      if(d.lt.0.) go to 20
c
      do 100 i=2,n
          w=d
          d=t-x(i)
          if(d.le.0) go to 10
 100  continue
      ir=1
      k=n
      go to 20
c-----------------------------------------------------
 10   ir=0
      k=i
      h=x(i)-x(i-1)
      w=w/h
      ww=1.-w
      u=ww**2
      a=u*(1.+2.*w)
      b=u*h*w
      u=w**2
      c=u*(1.+2.*ww)
      d=-u*h*ww
      do 110 j=1,nd
          f(kk)=a*y(k-1)+b*dr(k-1)+c*y(k)+d*dr(k)
          k=k+md
 110  kk=kk+mf
      return
c=====================================================
 20   do 120 j=1,nd
          f(kk) = c*y(k)+d*dr(k)
          k = k+md
 120  kk = kk+mf
c=====================================================
      end
