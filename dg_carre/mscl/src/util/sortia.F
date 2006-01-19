      subroutine sortia(a,ind,n)
c
c  version : 11.07.94 13:03
c
c=====================================================
c*** sorting integer array in accending order
c
      integer a(*),ind(*)
c
      do 100 i=1,n
         ind(i)=i
 100  continue
      if(n.le.1) return
c
      do 101 k=2,n
         m=k-1
         ll=ind(k-1)
         r=a(ll)
         do 102 j=k,n
              l=ind(j)
              u=a(l)
              if(u.lt.r) then
                   ll=l
                   r=u
                   m=j
              end if
 102     continue
         if(m.ne.k-1) then
              i=ind(k-1)
              ind(k-1)=ll
              ind(m)=i
         end if
 101  continue
c
      end
c
c
c=====================================================
      subroutine sortra(a,ind,n)
c=====================================================
c*** sorting real array in accending order
c
      dimension a(*),ind(*)
c
      do 100 i=1,n
         ind(i)=i
 100  continue
      if(n.le.1) return
c
      do 101 k=2,n
         m=k-1
         ll=ind(k-1)
         r=a(ll)
         do 102 j=k,n
              l=ind(j)
              u=a(l)
              if(u.lt.r) then
                   ll=l
                   r=u
                   m=j
              end if
 102     continue
         if(m.ne.k-1) then
              i=ind(k-1)
              ind(k-1)=ll
              ind(m)=i
         end if
 101  continue
c
      end
c
c
c=====================================================
      subroutine rshffl(nuin,ind,nuout,n)
c=====================================================
c*** reshuffling the input array nuin after sorting,
c*** the result in nuout ( must be different from nuin)
c
      integer nuin(*),ind(*),nuout(*)
c
      do 100 i=1,n
          j = ind(i)
          nuout(i) = nuin(j)
 100  continue
c
      end
