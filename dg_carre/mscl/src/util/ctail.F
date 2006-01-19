      subroutine ctail(a,m,b,n)
c
c  version : 04.05.91 21:08
c
c=====================================================
      character a(*),b(*)
c=====================================================
c
      if(n.ge.m) then
         call bsend(a,b,m)
         call bfill(b(m+1),n-m,' ')
      else
         l=m-n
         k=m
         do 100 i=1,l
              if(a(k).eq.' ') go to 100
              if(n.le.8) then
                   call bsend(a(k-n+1),b,n)
              else
                   j=k-n+4
                   call bsend(a(j),b(4),n-3)
                   call bfill(b,3,'.')
              end if
              return
c=====================================================
 100     k=k-1
         call bsend(a,b,n)
      end if
c=====================================================
      end
