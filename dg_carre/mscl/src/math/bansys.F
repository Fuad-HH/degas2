      subroutine bansys(a,b,m,n,md,ind,irt)
c
c  version : 22.11.92 22:11
c
c-----------------------------------------------------
c*** solving a system of linear algebraic equations with band matrix
c***
c***                        ax = b
c***
c*** input;
c***
c***  a(m,n)   is the band matrix
c***  b(n)     is the right-hand-side
c***  n        is the number of equations
c***  m        is the band width
c***  md       is the number of lines below the diagonal
c***  ind(2,n) is a temporary storage area
c***
c*** output:
c***
c***  b(n)   contains the solution
c***  irt    is the return code, 0 is ok
c***
c-----------------------------------------------------
      dimension a(*),b(n),ind(*)
c
      if(n.le.0 .or. m.le.0 .or. md.ge.m) go to 60
      if(n.eq.1) go to 50
c
      ka=1
      k=1
      do 100 i=1,n
          ind(k)=ka
          ind(k+1)=i
          ka=ka+m
 100  k=k+2
      kn=n+n
c
      mm=md+1
      kz=n-mm
      ki=0
      do 101 j=2,n
          kk=ki+1
          r=0.
          km=0
          do 102 i=1,mm
              k=ind(kk)
              s=a(k)
              sa=abs(s)
              if(sa.le.r) go to 102
c
              km=kk
              r=sa
              ss=s
 102      kk=kk+2
c
          if(km.eq.0) go to 30
c
          ka=ind(km)
          kb=ind(km+1)
          kk=ki+1
          if(km.eq.kk) go to 10
c
          ind(km)=ind(ki+1)
          ind(ki+1)=ka
          ind(km+1)=ind(ki+2)
          ind(ki+2)=kb
c
 10       kk=ki+3
          if(mm.eq.1) go to 15
c
          do 103 i=2,mm
              k=ind(kk)
              s=a(k)
              r=s/ss
              la=k+1
              ll=ka+1
              do 104 ii=2,m
                  a(la-1)=a(la)-r*a(ll)
                  ll=ll+1
 104          la=la+1
              a(la-1)=0.
              lb=ind(kk+1)
              b(lb)=b(lb)-r*b(kb)
 103      kk=kk+2
c
 15       if(kz.le.0) mm=mm-1
          ki=ki+2
 101  kz=kz-1
c
      ka=ind(ki+1)
      kb=ind(ki+2)
      b(kb)=b(kb)/a(ka)
      do 105 j=2,n
          kz=kz+1
          ki=ki-2
          if(kz.le.0) mm=mm+1
          ka=ind(ki+1)
          kb=ind(ki+2)
          kk=ki+2
          s=b(kb)
          la=ka+1
          if(m.eq.1) go to 20
c
          do 106 ii=2,m
              if(kk.eq.kn) go to 20
c
              lb=ind(kk+2)
              s=s-a(la)*b(lb)
              la=la+1
 106      kk=kk+2
c
 20       b(kb)=s/a(ka)
 105  continue
c
      n1=n-1
      ki=0
      do 107 j=1,n1
          kb=ind(ki+2)
          do 108 k=j,n
              if(kb.eq.j) go to 107
c
              kk=kb+kb
              l=ind(kk)
              r=b(kb)
              b(kb)=b(l)
              b(l)=r
              ind(kk)=kb
              kb=l
              ind(ki+2)=kb
 108      continue
          go to 40
 107  ki=ki+2
      irt=0
      return
c
 30   irt=j-1
      return
c
 40   irt=-j
      return
c
 50   irt=1
      if(a(1).eq.0.) return
c
      b(1)=b(1)/a(1)
      irt=0
      return
c
 60   irt=-n
c
      end
c
c
c=====================================================
      subroutine bansht(a,m,md)
c
      dimension a(m,md)
c
      l=m-md
      k=md
      do 100 j=1,md
          do 101 i=1,l
          a(i,j)=a(i+k,j)
 101      continue
          ll=l+1
          do 102 i=ll,m
              a(i,j)=0.
 102      continue
          k=k-1
 100  l=l+1
c
      end
