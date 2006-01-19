      function urand(iy)
c
c  version : 07.05.89
c
      integer iy
      integer ia,ic,itwo,m2,m,mic
      double precision halfm
      real s
      double precision datan,dsqrt
      data m2/0/,itwo/2/
      if (m2.ne.0) go to 20
c
      m=1
  10  m2=m
      m=itwo*m2
      if (m.gt.m2) go to 10
      halfm=m2
c
      ia=8*idint(halfm*datan(1.d0)/8.d0)+5
      ic=8*idint(halfm*(0.5d0-dsqrt(3.d0)/6.d0))+1
      mic=(m2-ic)+m2
c
      s=0.5/halfm
c
  20  iy=iy*ia
      iy=iy+ic
c
      if (iy.lt.0) iy=(iy+m2)+m2
      urand=float(iy)*s
      end
