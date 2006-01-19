      function sighve(t)
c
c  version : 19.07.93 11:26
c
c*** t - [ev],  result - [1.e-8 cm**3/s]
c
c   electron impact ionization;   t=te.
c
      x=alog10(t)
      if(t.lt.20.) then
          w=-3.054*x-15.72*exp(-x)+1.603*exp(-x**2)
      else
          w=-0.5151*x-2.563/x-5.231
      end if
c
      sighve=exp(2.308525*(w+8))
c
      end
c
c
c=====================================================
      function sighvc (t)
c
c   resonance charge-exchange;  t=ti/a
c     ( 'hydrogen temperature' [ev]),   result - [1.e-8 cm**3/s]
c
      x=alog10(t)
      sighvc=1.1*(1-0.155*x)**2*sqrt(t)
c
      end
