      subroutine rdfrin(iunit,vari,ii,ierror)
c  version : 03.07.2000 22:59
      implicit none
c  read a integer number from a chain of characters vari
c
c  arguments
      integer iunit,ii,ierror
      character vari*(*)
c  iunit: unit of temporary file
c  vari: chain of character from which to read
c  ii: integer read from vari (output)
c  ierror: error flag: 0 for no error, 1 when there is an error.
c
c  calculations
c      rewind iunit
c      write(iunit,100)vari
c100   format(a)
c      rewind iunit
c      read(iunit,*,err=99)ii
      read(vari,'(i)',err=99)ii
      ierror=0
      return
99    ierror=1
      return
      end
