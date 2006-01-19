      function ifshtd()
c
c  version : 10.05.95 21:22
c
      common/trpsht/lsspn,lshtd,lstpn
      logical ex,lsspn,lshtd,lstpn
      ifshtd=0
      inquire(file='/tmp/suspend',exist=ex)
      if(ex .and. lsspn) then
         ifshtd=3
         return
      end if
      inquire(file='/tmp/shutdown',exist=ex)
      if(ex .and. lshtd) then
         ifshtd=2
         return
      end if
      inquire(file='stopnow',exist=ex)
      if(ex .and. lstpn) then
         ifshtd=1
         return
      end if
      end
      block data ifshbl
      common/trpsht/lsspn,lshtd,lstpn
      logical lsspn,lshtd,lstpn
      data lsspn,lshtd,lstpn / 3*.true./
      end
