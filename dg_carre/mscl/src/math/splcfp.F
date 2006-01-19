      subroutine splcfp(x,y,nx,c,ic,w,ier)
c
c  version : 14.03.97 18:02
c
c======================================================================
c*** Cubic spline interpolation with periodic boundary conditions
c***
c*** Input
c***    x   array containing the abscissae of the data points
c***        Must be ordered so that x(i).lt.x(i+1).
c***    y   array containing the function values.
c***        y(1) is assumed equal to y(nx).
c***    nx  the number of elements in x and y ( > 3 )
c***    ic  row dimension of matrix c as specified in the
c***        dimension statement in the calling program.
c***
c*** Output
c***    c   spline coefficients (an nx-1 by 3 matrix)
c***          The value of the spline approximation at t is
c***            s(t) = ((c(i,3)*d+c(i,2))*d+c(i,1))*d+y(i)
c***          where x(i) .le. t .lt. x(i+1) and d = t-x(i).
c***
c***    w   work array of length 6*nx.
c***    ier return code
c***          ier = 0: OK
c***          ier = 1: y(1) is not equal to y(nx) (warning)
c***          ier =-1: ic is less than nx-1.
c***          ier =-2: nx is less than 4.
c***          ier =-3: input abscissae are not ordered so that
c***                    x(1) < x(2) ... < x(nx)
c***
c*** The calculated cubic spline passes through each data point and
c*** is periodic. That is, its value and its first and second
c*** derivatives are equal at the points x(1) and x(nx).
c***
c*** A warning is given if y(1) is not equal to y(nx), but y(nx) is
c*** not used in the computations.
c======================================================================
      implicit none
      integer nx,ic,ier
      real x(*),y(*),c(ic,3),w(6,*)
      integer ii,im1,imj,ip1,ip2,i,j,n,nm1
      real a2,a4,b2,b3,b4,c2,c3,c4,d1,d2,d3,d4,dt1,dt2,dt3,dt4,
     ,                                     hh(6),h(7),r,ht1,ht2,ht3,ht4
c======================================================================
c
      ier = -1
      n = nx-1
      if(ic.lt.n) then
        write(*,*) 'splcfp: wrong dimensions of array c:',ic,' < ',n
        return
      end if
      ier = -2
      if(nx.lt.4) then
        write(*,*) 'splcfp: too few data points:',nx
        return
      end if
      nm1 = 0
      if(y(1).ne.y(nx)) nm1 = 1
c
c*** Calculate coefficients of matrix A
c*** where A(i,j)=jth spline basis function evaluated at x(i)
c
      ier = -3
      do i=1,n
        do j=1,4
          imj = mod(n+i+j-4,n)+1
          h(j) = x(imj+1)-x(imj)
          if(h(j).le.0.0) then
            write(*,*) 'splcfp: x(i) >= x(i+1) at i =',imj
            return
          end if
        end do
        ht1 = h(3)+h(4)
        ht2 = h(1)+h(2)
        ht3 = h(2)+h(3)
        dt1 = (ht1+h(3))*h(2)*ht2+(ht2+h(2))*h(3)*ht1
        w(1,i) = 0.0
        a2 = h(1)**2*(ht3+h(4))*ht3/(ht2*dt1)
        w(2,i) = a2
        w(3,i) = 1.0
        a4 = h(4)**2*ht3*(h(1)+ht3)/(ht1*dt1)
        w(4,i) = a4
        w(5,i) = 0.0
        w(6,i) = y(i)
      end do
      ier = nm1
      nm1 = n-1
      w(1,1) = w(4,n)
      w(5,1) = w(2,1)
      w(1,nm1) = w(2,n)
      w(5,nm1) = w(4,nm1)
      w(1,n) = 1.0
c
c*** Solve linear system for coefficients of spline basis functions
c
      do i=1,nm1
        r = w(5,i)/w(3,i)
        w(1,n) = w(1,n)-r*w(1,i)
        w(6,n) = w(6,n)-r*w(6,i)
        if(i.ne.nm1) then
          ip1=i+1
          w(5,ip1) = w(5,ip1)-r*w(2,ip1)
          r = w(4,i)/w(3,i)
          w(3,ip1) = w(3,ip1)-r*w(2,ip1)
          w(1,ip1) = w(1,ip1)-r*w(1,i)
          w(6,ip1) = w(6,ip1)-r*w(6,i)
        end if
      end do
      w(6,n) = w(6,n)/w(1,n)
      w(6,nm1) = (w(6,nm1)-w(1,nm1)*w(6,n))/w(3,nm1)
      do ii=2,nm1
        i = n-ii
        ip1=i+1
        w(6,i) = (w(6,i)-w(2,ip1)*w(6,ip1)-w(1,i)*w(6,n))/w(3,i)
      end do
c
c*** In each interval calculate coefficients c(i,j),j=1,3 from the
c*** basis function coefficients
c
      do i=1,n
        im1 = mod(n+i-2,n)+1
        ip1 = mod(n+i,n)+1
        ip2 = mod(n+i+1,n)+1
        do j=1,7
          imj = mod(n+i+j-5,n)+1
          h(j) = x(imj+1)-x(imj)
        end do
        do j=1,6
          hh(j) = h(j)+h(j+1)
        end do
        ht1 = h(4)+hh(4)
        ht2 = h(3)+hh(2)
        ht3 = h(5)+hh(5)
        ht4 = h(4)+hh(3)
        dt1 = (h(3)+hh(3))*h(2)*hh(1)+(h(2)+hh(1))*h(3)*hh(3)
        dt2 = ht1*h(3)*hh(2)+ht2*h(4)*hh(4)
        dt3 = ht3*h(4)*hh(3)+ht4*h(5)*hh(5)
        dt4 = (h(6)+hh(6))*h(5)*hh(4)+(h(5)+hh(4))*h(6)*hh(6)
        d1 = hh(5)*(hh(5)+h(7))/(h(4)*hh(4)*dt4)
        b2 = 3.*h(3)*hh(4)*(hh(4)+h(6))/(hh(3)*dt3)
        c2 = b2/h(3)
        d2 = -(ht3*ht4+3.*hh(3)*h(4)+h(3)*h(3)+h(5)*hh(5)) /
     /                                                 (hh(3)*h(4)*dt3)
        b3 = 3.*(h(4)*hh(4)-h(3)*hh(2))/dt2
        c3 = -3.*(ht1+ht2)/dt2
        d3 = (ht1*ht2+3.*h(4)*hh(4)+h(5)*h(5)+h(3)*hh(2)) /
     /                                                 (hh(4)*h(4)*dt2)
        b4 = -3.*h(4)*hh(2)*(hh(1)+h(3))/(hh(3)*dt1)
        c4 = -b4/h(4)
        d4 = -c4/(3.*h(4))
        c(i,1) = w(6,im1)*b4+w(6,i)*b3+w(6,ip1)*b2
        c(i,2) = w(6,im1)*c4+w(6,i)*c3+w(6,ip1)*c2
        c(i,3) = w(6,im1)*d4+w(6,i)*d3+w(6,ip1)*d2+w(6,ip2)*d1
      end do
c======================================================================
      end
