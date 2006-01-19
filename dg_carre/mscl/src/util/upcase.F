      subroutine upcase(a,b,n)
c
c  version : 20.06.93 20:38
c
      character a(*),b(*),u
c
      do 100 i=1,n
         u=a(i)
         k=ichar(u)
         if(k.ge.97 .and. k.le.122) u=char(k-32)
 100  b(i)=u
c
      end
c
c
c=====================================================
      subroutine locase(a,b,n)
c
      character a(*),b(*),u
c
      do 110 i=1,n
         u=a(i)
         k=ichar(u)
         if(k.ge.65 .and. k.le.90) u=char(k+32)
 110  b(i)=u
c
      end
