      subroutine ctime(ct,rt)
c
c  version : 08.03.93 19:37
c
c#$#$#$=ndp=lpi=ghl=cvx=sun=+
c      real t(2)
c      ct=etime(t)
c      rt=t(1)
c#$#$#$=aix=
      ct=mclock()*0.01
      rt=ct
c#$#$#$=ms=+
c      integer*2 ih,im,is,ic
c      call gettim(ih,im,is,ic)
c      rt =  is + 60*(im + 60*ih) + 0.01*ic
c      ct = rt
c#$#$#$
      end
