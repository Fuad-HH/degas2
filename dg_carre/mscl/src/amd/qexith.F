      function qexith(te)
c
c  version : 27.11.83
c
c*** intencity of line radiation from neutral hydrogen
c*** (corona model), 1.e-8 cm**3*ev/s
c===============================================
c
      qexith=0.
      if(te.lt.0.25) return
      w=10.2/te
      qexith=49.*exp(-w)*sqrt(w*(1.+w))/(0.28+w)
c===============================================
      end
