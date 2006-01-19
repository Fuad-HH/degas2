      function qrdarg(t,p)
c
c  version : 12.02.94 21:17
c
c=====================================================
c*** argon radiation
c***           (very approximate formula)
c*** input:
c***  t  - electron temperature, ev
c***  p  - not used yet
c*** output:
c***     rate constant, 10**-26 cm**3 10**19 ev/sec
c=====================================================
      parameter (npnt=35, xmin=-0.1, xmax=3.3, tmin=0.8,
     ,            aa=2.3025851,
     ,          nn=npnt-1, d=nn/(xmax-xmin), dd=1./d )
      real qm(npnt)
      data qm / 0.00, .455, .773, 1.59, 2.68, 3.18, 3.64, 4.05, 4.46,
     ,      4.82, 5.00, 5.14, 5.27, 5.36, 5.27, 5.00, 4.68, 4.32, 4.09,
     ,      4.09, 4.32, 4.41, 4.50, 4.64, 4.73, 4.77, 4.55, 3.77, 3.50,
     ,      3.27, 3.23, 3.27, 3.41, 3.46, 3.41 /
c=====================================================
c
      if(t.lt.tmin) then
          qrdarg=0.
          return
      end if
      x=alog10(t)
      k=(x-xmin)*d
      if(k.ge.nn) then
          ql=qm(npnt)*xmax/x
      else
          xx=dd*k+xmin
          e=(x-xx)*d
          ql=e*qm(k+2)+(1.-e)*qm(k+1)
      end if
      qrdarg=6.25e-5*exp(aa*ql)
c=====================================================
      end
