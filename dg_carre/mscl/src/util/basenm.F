      function basenm(f,m)
c
c  version : 22.06.93 11:15
c
c=====================================================
      parameter(lenfn=14)
      character basenm*(lenfn),f(*),c*(lenfn),cc(lenfn),bs
      equivalence (c,cc)
c=====================================================
c
c*** define backslash symbol to avoid mess with different compilers
c
      bs=char(92)
      k=1
      do 100 i=1,m
         if(f(i).eq.'/'.or.f(i).eq.':'.or.f(i).eq.bs) k=i+1
         if(f(i).eq.' ') go to 10
 100  continue
      i=m
 10   n=min(i-k+1,lenfn)
      call bsend(f(k),c,n)
      call bfill(cc(n+1),lenfn-n,' ')
      basenm=c
c=====================================================
      end
