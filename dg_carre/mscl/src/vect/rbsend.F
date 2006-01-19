      subroutine rbsend(a,b,n)
c
c  version : 18.11.88
c
c*** character array transfer from end to begin
c===============================================
      character*1 a(*),b(*)
c===============================================
c
      if(n.le.0) return
c===============================================
      k=n
      do 100 i=1,n
      b(k)=a(k)
 100  k=k-1
c===============================================
      end
