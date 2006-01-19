      subroutine scheof(l)
c
c  version : 18.06.93 13:19
c
c=====================================================
      logical op
      character*8 f,y,c*1
      data y/'yes'/
c=====================================================
c
      inquire(l,opened=op,formatted=f)
      if(.not.op) return
      call locase(y,y,8)
      call locase(f,f,8)
      if(f.eq.y) go to 15
c
 10   read (l,end=20,err=20) i
      go to 10
c-----------------------------------------------------
 15   read (l,700,end=20,err=20) c
  700 format(a1)
      go to 15
c-----------------------------------------------------
 20   continue
c#$#$#$=ms=lpi=vs=cvx=aix=sg=mw=
      backspace l
c#$#$#$
c=====================================================
      end
