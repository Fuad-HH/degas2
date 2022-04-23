#if(0)
  FTANGLE v1.61,
 created with UNIX on "Friday, September 25, 1998 at 8:02." 
  COMMAND LINE: "./ftangle ./a_type -uCONFIG -mCONFIG -mGCC -= a_type.h"
  RUN TIME:     "Friday, November 17, 2017 at 11:24."
  WEB FILE:     "./a_type.web"
  CHANGE FILE:  (none)
#endif
/* 6: */
#line 20 "./a_type.web"


int tgetent PROTO((outer_char*buffer,CONST outer_char*name));
int tgetflag PROTO((CONST outer_char*id));
int tgetnum PROTO((CONST outer_char*id));
outer_char*tgetstr PROTO((CONST outer_char*id,outer_char**area));
outer_char*tgoto PROTO((CONST outer_char*cm,int destcol,int destline));
SRTN tputs PROTO((outer_char*cp,int affcnt,int(*outc)(int)));

/* :6 */

