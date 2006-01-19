      subroutine fcraxn(nam)
c
c  version : 25.08.97 16:30
c
c======================================================================
c*** Input of auxiliary data for Carre
c======================================================================
      implicit none
#include <FCRCOM.F>
      character*8 nam
c
      integer nnm
      parameter (nnm=7)
      character nms(nnm)*8
      integer i
      data nms /
     1    'repart  ','nrelax  ','relax   ','pasmin  ','rlcept  ',
     2    'tgarde  ','xpttol  '/
c======================================================================
c
      do i=1,nnm
        if(nam.eq.nms(i)) go to (10,20,30,40,50,60,70),i
      end do
      call fcrtrn(nam)
      return
c
 10   call resimi(repart)
      return
 20   call resimi(nrelax)
      return
 30   call resimd(relax)
      return
 40   call resimd(pasmin)
      return
 50   call resimd(rlcept)
      return
 60   call rearrd(tgarde,ntrgx,ntrg)
      return
 70   call resimd(xpttol)
      return
c======================================================================
      end
