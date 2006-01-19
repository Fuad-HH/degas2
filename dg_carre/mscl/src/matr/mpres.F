      subroutine mpres(a,m,n,l,mm,nn,b)
c
c  version : 25.02.89
c
      dimension a(m,n,*),b(*)
c
      ii=1
      do 101 k=1,l
      do 101 j=1,nn
      do 101 i=1,mm
      b(ii)=a(i,j,k)
101   ii=ii+1
      return
c
      entry mrare (a,m,n,l,mm,nn,b)
c
      ii=mm*nn*l
      k=l
      do 104 k1=1,l
      j=nn
      do 103 j1=1,nn
      i=mm
      do 102 i1=1,mm
      a(i,j,k)=b(ii)
      ii=ii-1
      i=i-1
102   continue
103   j=j-1
104   k=k-1
      end
