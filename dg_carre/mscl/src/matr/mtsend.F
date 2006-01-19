      subroutine mtsend(a,ma,b,mb,m,n)
c
c  version : 23.08.93 18:12
c
c=====================================================
c*** matrix copying
c=====================================================
      integer a(ma,*),b(mb,*)
c=====================================================
c
      do 100 j=1,n
          do 100 i=1,m
              b(i,j)=a(i,j)
 100  continue
c
      end
c
c
c=====================================================
      subroutine rmtsnd(a,ma,b,mb,m,n)
c
      integer a(ma,*),b(mb,*)
c
      do 100 j=n,1,-1
          do 100 i=m,1,-1
              b(i,j)=a(i,j)
 100  continue
c
      end
c
c
c=====================================================
      subroutine mtline(a,ma,fa,b,mb,fb,c,mc,m,n)
c
      real a(ma,*),b(mb,*),c(mc,*)
c
      do 100 j=1,n
          do 100 i=1,m
              c(i,j)=a(i,j)*fa+b(i,j)*fb
 100  continue
c
      end
