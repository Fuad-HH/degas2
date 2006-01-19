      subroutine lineqn(d,n,nerror)
c
c  version : 14.07.89
c
c=====================================================
c*** solving a system of linear equations with gaussian method
c*** (adapted from besm-6)
c=====================================================
      dimension d(n,*)
c
      n1=n+1
      do 12 k=1,n
c find the line containing the maximum value in the column k
          k1=k+1
          k2=k-1
          r=0.
          do 2 l=k,n
              if(r-abs(d(l,k))) 1,2,2
    1         lp=l
              r=abs(d(l,k))
    2     continue
          if(r) 3,14,3
    3     if(lp-k) 6,6,4
c-----------------------------------------------------
c interchange of lines k and lp
c
    4     do 5 j=k,n1
              r=d(k,j)
              d(k,j)=d(lp,j)
    5     d(lp,j)=r
c annulation of terms in the column k
    6     do 7 j=k1,n1
    7     d(k,j)=d(k,j)/d(k,k)
          if(k-1) 10,10,8
    8     do 9 i=1,k2
              do 9 j=k1,n1
    9     d(i,j)=d(i,j)-d(k,j)*d(i,k)
          if(k-n) 10,12,12
   10     do 11 i=k1,n
              do 11 j=k1,n1
   11     d(i,j)=d(i,j)-d(k,j)*d(i,k)
   12 continue
      nerror=0
      do 13 i=1,n
   13 d(i,1)=d(i,n+1)
      return
c=====================================================
   14 nerror=k
c=====================================================
      end
