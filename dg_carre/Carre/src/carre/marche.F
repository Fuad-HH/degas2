      SUBROUTINE MARCHE(x0,y0,plaque,fraplq,sens,nivox,nivoy,nvotot,
     .        nbcrb,xt,yt,nt,stp0,stpmin,nx,ny,x,y,psi,
     .        nstruc,npstru,xstruc,ystruc,a00,a10,
     .        a01,a11,indlim)
c
c  version : 07.07.97 20:42
c
c======================================================================
*..  Cette sous-routine parametrise des lignes de niveau jusqu'a
*  ce qu'on obtienne la derniere courbe de niveau qui va d'un deflectur
*  a un autre sans rencontrer de structure.
c======================================================================

      IMPLICIT NONE

cank-970707: dimensions from the file
*  dimensions
#include <CARREDIM.F>

*  arguments
      INTEGER nx,ny,nstruc,npstru(strumx),indlim,
     .        nvotot,plaque,fraplq,sens,nbcrb,nt(2)

      REAL*8 x(nxmax),y(ny),psi(nxmax,ny),xstruc(npstmx,strumx),
     .     ystruc(npstmx,strumx),x0,y0,stp0,stpmin,nivox(npnimx),
     .     nivoy(npnimx),a00(nxmax,nymax),a10(nxmax,nymax),
     .     a01(nxmax,nymax),a11(nxmax,nymax),xt(npnimx,2),yt(npnimx,2)

*  variables locales
      INTEGER ii,jj,dir,k,j,repart,ind1,ind2,ind3,indstr
      REAL*8 const1,un
      PARAMETER (const1=1.E-08,un=1.)
      REAL*8 pas,x1,y1,x2,y2,psi1,psi2,pastmp,ecart1,ecart2,
     .       niv1x(npnimx),niv1y(npnimx)
      LOGICAL echec,coin,ouvert

*  procedures
      INTEGER ifind,indsgm
      LOGICAL in, chgdir, cross
      INTRINSIC MOD,SQRT
      EXTERNAL chgdir,CRBNIV,cross,ifind,in,indsgm

c=========================
c.. plaque: indice de la structure (plaque) sur laquelle on marche.
c.. fraplq: indice de la structure (plaque) que la ligne de niveau doit
c           frapper.
c.. sens: sens de deplacement sur la plaque
c.. x0,y0: point de depart.
c.. nivox,nivoy: tableaux des coordonnees x et y des points parametrises
c                de la derniere ligne de niveau.
c.. nvotot: nombre de points de cette courbe.
c.. knivtm: nombre de points de cette courbe.
c.. x2,y2: point sur la structure ou debute la nouvelle ligne de niveau.
c.. x1,y1: point de la ligne precedente.
c.. psi1,ps2: valeur de la fonction aux points 1 et 2.
c.. ind1,ind2: indices de segments des points 1 et 2.
c.. ind3: indice d'un point de structure, coin.
c.. pas: valeur du pas auquel on marche.
c.. pastmp: valeur temporaire du pas.
c.. ii,jj: indice d'identification d'un carre.
c.. dir: direction de recherche.
c.. k  : indice du point parametrise de chaque courbe.
c.. indlim: indice de la derniere structure frappee autre que la
c           structure designee fraplq.
c.. indstr: indice de la derniere structure frappee.
c.. repart: variable necessaire pour signifier a "SAUTE" que l'on
c           travaille en distance absolue.
c.. ecart1,ecart2: distance entre un point et chaque extremitee du
c                  segment sur lequel il se trouve.
c.. rien: logique,si oui ou non on n'a pas encore rencontre une
c         structure differente de fraplq.
c.. echec: logique, si on doit considerer le debut de la courbe comme
c          un echec ou non.
c.. coin: logique, si on est a un point de structure ou non.
c.. ouvert: logique=.t. si la structure sur laquelle on marche est
c            ouverte.
c=========================

*..Initialisation
c***
c     print*,'entree dans marche'
c     print*,'nx,ny=',nx,ny
c     print*,'strumx=',strumx
c     print*,'nbcrb, nt(nbcrb)=',nbcrb,nt(nbcrb)
c     do j=1,nt(nbcrb)
c       print*,'j, x/yt=',j,xt(j,nbcrb),yt(j,nbcrb)
c     enddo
c     pause
c***

      x2 = x0
      y2 = y0

      ouvert=xstruc(1,plaque).ne.xstruc(npstru(plaque),plaque)
     .  .or. ystruc(1,plaque).ne.ystruc(npstru(plaque),plaque)

*..Calcul de la valeur de la fonction au premier point.

      ii = ifind(x2,x,nx,1)
      jj = ifind(y2,y,ny,1)
c***
c     print*,'ii, jj=',ii,jj
c***
      psi2 = a00(ii,jj) + a10(ii,jj)*x2 + a01(ii,jj)*y2 +
     .         a11(ii,jj)*x2*y2
c***
c     print*,'psi2=',psi2
c     print*,'plaque=',plaque
c***

      ind2 = indsgm(xstruc(1,plaque),ystruc(1,plaque),npstru(plaque),
     .              x2,y2)
c***
c     print*,'ind2=',ind2
c***

*..Initialisation.

      pas = stp0
      repart = 1
      pastmp = pas

      DO 5 j=1, nt(nbcrb)
         nivox(j) = xt(j,nbcrb)
         nivoy(j) = yt(j,nbcrb)
    5 CONTINUE
c***
c     print*,'apres la definition: nbcrb, nt()=',nbcrb,nt(nbcrb)
c     do j=1,nt(nbcrb)
c       print*,'j, x/yt=',j,xt(j,nbcrb),yt(j,nbcrb)
c     enddo
c     do j=1,nt(nbcrb)
c       print*,'j, nivox/y=',j,nivox(j),nivoy(j)
c     enddo
c***

      nvotot = nt(nbcrb)

   10 CONTINUE

      IF (pastmp .LT. 0.5*stpmin) RETURN

      x1 = x2
      y1 = y2
      psi1 = psi2
      ind1 = ind2
      coin = .FALSE.

*..On recherche le prochain point.

      CALL SAUTE(xstruc(1,plaque),ystruc(1,plaque),npstru(plaque),
     .           x1,y1,psi1,x2,y2,pas,sens,repart,nx,ny,x,y,
     .           a00,a10,a01,a11,nxmax,nymax)
c***
c     print*,' '
c     print*,'pas=',pas
c     print*,'apres saute: x1,y1=',x1,y1
c     print*,'             x2,y2=',x2,y2
c     pause
c***

*..On s'assure que l'on ne depasse pas la maille.

      IF ((x2 .LT. x(1)) .OR. (x2 .GT. x(nx)) .OR. (y2 .LT. y(1)) .OR.
     .      (y2 .GT. y(ny))) THEN

         pastmp = pastmp/2.
         pas = pastmp
         x2 = x1
         y2 = y1

         psi2 = psi1
         ind2 = ind1
         GO TO 10

      ENDIF

*..Indice du segment de structure sur lequel se trouve x2,y2.

      ind2 = indsgm(xstruc(1,plaque),ystruc(1,plaque),npstru(plaque),
     .              x2,y2)
c***
c     print*,'ind1, ind2=',ind1,ind2
c***

      IF (ind1 .NE. ind2) THEN

         COIN = .TRUE.

         IF (sens .EQ. 1) THEN
            ind3 = ind2
         ELSE
            ind3 = ind1
         ENDIF

         x2 = xstruc(ind3,plaque)
         y2 = ystruc(ind3,plaque)

         pastmp = pas

         pas = SQRT((x1-x2)**2 + (y1-y2)**2)

      ENDIF

*..Calcul de la fonction pour le point 2.

      ii = ifind(x2,x,nx,1)
      jj = ifind(y2,y,ny,1)

      psi2 = a00(ii,jj) + a10(ii,jj)*x2 + a01(ii,jj)*y2 +
     .         a11(ii,jj)*x2*y2
c***
c     print*,'psi2=',psi2
c***

*..Definition du premier point du vecteur de niveau.

      niv1x(1) = x2
      niv1y(1) = y2

*..Recheche du deuxieme point sur le perimetre du carre ii,jj.

      ecart1 = SQRT((x2-xstruc(ind2,plaque))**2 +
     .                       (y2-ystruc(ind2,plaque))**2)

      ecart2 = SQRT((x2-xstruc(ind2+1,plaque))**2 +
     .                       (y2-ystruc(ind2+1,plaque))**2)

      echec = .FALSE.
      dir = 0
      k = 1
      CALL CRBNIV(ii,jj,k,dir,nxmax,nx,ny,x,y,psi,psi2,niv1x,niv1y,
     .            npnimx,strumx,npstmx,nstruc,npstru,xstruc,ystruc,
     .            indstr,xt,yt,nt,nbcrb,plaque,x2,y2)
c***
c     print*,'apres crbniv1: k, indstr=',k,indstr
c     do j=1,k
c       print*,'j, niv1x/y=',j,niv1x(j),niv1y(j)
c     enddo
c***

*..Si on est rendu a l'extremite du segment, on verifie si ce point est
*  a l'interieur de la structure ou si le sens est change. Si on est pas
*  a l'extr., on verifie si le point est a l'interieur ou si on a
*  traverse un autre segment de la structure. Pour chaque fois, si c'est
*  le cas, on doit inverser les directions, revenir d'un carre et on
*  oublie le point que l'on vient de prendre. Sinon, on continue en
*  conservant le point obtenu, la direction et les coord. du carre.

      IF ((ABS(x2-x(nx)).LT.const1) .OR. (ABS(y2-y(ny)).LT.const1)
     .  .OR. (ABS(x2-x(1)).LT.const1) .OR. (ABS(y2-y(1)).LT.const1))
     .                                                         THEN

         IF (((dir .EQ. 1) .AND. (ii .EQ. nx))
     .       .OR. ((dir .EQ. 2) .AND. (jj .EQ. ny))
     .       .OR. ((dir .EQ. 3) .AND. (ii .EQ. 1))
     .       .OR. ((dir .EQ. 4) .AND. (jj .EQ. 1))) THEN

            k = 1
            dir = MOD(dir+1,4) + 1
            ii = ii - MOD(dir-2,2)
            jj = jj - MOD(dir-3,2)

            CALL CRBNIV(ii,jj,k,dir,nxmax,nx,ny,x,y,psi,psi2,
     .             niv1x,niv1y,npnimx,strumx,npstmx,nstruc,npstru,
     .             xstruc,ystruc,indstr,xt,yt,nt,nbcrb,plaque,x2,y2)
            if(indstr.ne.0 .and. indstr.ne.fraplq) indlim=indstr
c***
c     print*,'apres crbniv2: k, indstr=',k,indstr
c     do j=1,k
c       print*,'j, niv1x/y=',j,niv1x(j),niv1y(j)
c     enddo
c***

            IF (cross(ind2,niv1x,niv1y,xstruc(1,plaque),
     ,                         ystruc(1,plaque),npstru(plaque)))   THEN

               echec = .TRUE.
c***
c        print*,'point 2: echec=',echec
c***

            ENDIF

         ENDIF

      ELSE IF ((ecart1 .LT. const1) .OR. (ecart2 .LT. const1)) THEN

         IF (chgdir(niv1x,niv1y,nivox,nivoy))     THEN

            k = 1
            dir = MOD(dir+1,4) + 1
            ii = ii - MOD(dir-2,2)
            jj = jj - MOD(dir-3,2)

         ENDIF

      ELSE
c***
c     do j=1,k
c       print*,'j, niv1x/y=',j,niv1x(j),niv1y(j)
c     enddo
c     do j=1,k
c       print*,'j, nivox/y=',j,nivox(j),nivoy(j)
c     enddo
c     print*,'chgdir=',chgdir(niv1x,niv1y,nivox,nivoy)
c***

         IF (chgdir(niv1x,niv1y,nivox,nivoy))     THEN

            IF ((in(niv1x(2),niv1y(2),xstruc(1,plaque),
     .                         ystruc(1,plaque),npstru(plaque)))
     .         .OR. (cross(ind2,niv1x,niv1y,xstruc(1,plaque),
     .                         ystruc(1,plaque),npstru(plaque)))
     .         .OR. ouvert)   THEN

               k = 1
               dir = MOD(dir+1,4) + 1
               ii = ii - MOD(dir-2,2)
               jj = jj - MOD(dir-3,2)

            ELSE

               echec = .TRUE.
c***
c              print*,'point 3: echec=',echec
c***

            ENDIF

         ELSE

           if(.not. ouvert) then
            IF ((in(niv1x(2),niv1y(2),xstruc(1,plaque),y
     .                           struc(1,plaque),npstru(plaque)))
     .        .OR. (cross(ind2,niv1x,niv1y,xstruc(1,plaque),
     .                          ystruc(1,plaque),npstru(plaque)))) THEN

               echec = .TRUE.
c***
c              print*,'point 4: echec=',echec
c***

            ENDIF
           endif
         ENDIF
      ENDIF

*..Pour les points successifs, on poursuit jusqu'a ce qu'on frappe une
*  structure.

      IF (.NOT.(echec)) THEN

         CALL CRBNIV(ii,jj,k,dir,nxmax,nx,ny,x,y,psi,psi2,
     .          niv1x,niv1y,npnimx,strumx,npstmx,nstruc,npstru,xstruc,
     .          ystruc,indstr,xt,yt,nt,nbcrb,plaque,x2,y2)
         if(indstr.ne.0 .and. indstr.ne.fraplq) indlim=indstr
c***
c     print*,'apres crbniv3: k, indstr=',k,indstr
c     do j=1,k
c       print*,'j, niv1x/y=',j,niv1x(j),niv1y(j)
c     enddo
c***

      ENDIF

*..Si on a frappe une plaque, on verifie si on est rendu a l'extremite
*  de notre plaque de depart, sinon on avance d'un pas et on recommence.

c***
c     print*,'indstr, fraplq=',indstr,fraplq
c     print*,'k=',k
c***
      IF ((indstr .EQ. fraplq) .AND. (.NOT.(echec))) THEN

        DO 15 j=1, k
           nivox(j) = niv1x(j)
           nivoy(j) = niv1y(j)
   15   CONTINUE

         nvotot = k

         IF (pastmp .LT. stp0) THEN

            pastmp = pastmp/2.
            pas = pastmp

         ELSE

            pas = pastmp

         ENDIF

      ELSE

         IF (coin) THEN
            pastmp = pas
         ENDIF

         pastmp = pastmp/2.
         pas = pastmp

         x2 = x1
         y2 = y1
         psi2 = psi1
         ind2 = ind1

      ENDIF

      GO TO 10

      END
