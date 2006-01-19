      subroutine solsys(a,m,b,l,ind)
c
c  version : 22.12.88
c
      dimension a(m,m),b(m,l),ind(m)
c
      do 107 i=1,m
      ind(i)=i
  107 continue
      m1=m-1
c
c
      do 100 j=1,m1
c
c
      r=1.e-75
      n=0
      do 101 k=j,m
      kk=ind(k)
      s=a(kk,j)
      if(s.eq.0.) go to 101
      s=abs(s)
      if(s.le.r) go to 101
      n=k
      r=s
  101 continue
      if(n.eq.0) go to 1
      if(n.eq.j) go to 2
      k=ind(n)
      ind(n)=ind(j)
      ind(j)=k
c
c
    2 s=a(n,j)
      do 100 k=j,m1
      kk=ind(k+1)
      r=a(kk,j)
      if(r.eq.0.) go to 100
      r=r/s
      do 102 i=j,m1
      a(kk,i+1)=a(kk,i+1)-r*a(n,i+1)
  102 continue
      do 110 i=1,l
      b(kk,i)=b(kk,i)-r*b(n,i)
  110 continue
  100 continue
c
c
      n=m
      do 103 j=1,m
      kk=ind(n)
      do 105 i=1,l
      do 104 k=n,m1
      kl=ind(k+1)
      b(kk,i)=b(kk,i)-a(kk,k+1)*b(kl,i)
  104 continue
      b(kk,i)=b(kk,i)/a(kk,n)
  105 continue
  103 n=n-1
      do 108 j=1,m1
      n=ind(j)
      if(n.eq.j) go to 108
      do 109 k=1,l
      r=b(j,k)
      b(j,k)=b(n,k)
      b(n,k)=r
  109 continue
  108 continue
      return
c
    1 print 700,j
  700 format(' solsys: singularity in column ',i3)
      end
