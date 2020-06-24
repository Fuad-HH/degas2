#if(0)
  FTANGLE v1.61,
 created with UNIX on "Friday, September 25, 1998 at 8:02." 
  COMMAND LINE: "./ftangle ./strmac -uCONFIG -mCONFIG -mGCC -= strmac.h"
  RUN TIME:     "Friday, November 17, 2017 at 11:29."
  WEB FILE:     "./strmac.web"
  CHANGE FILE:  (none)
#endif
/* 6: */
#line 21 "./strmac.web"

#ifndef _strmac_

#define _strmac_
/* 7: */
#line 30 "./strmac.web"


#define ATOF(s) atof((CONST char *)(s))
#define ATOI(s) atoi((CONST char *)(s))
#define ATOL(s) atol((CONST char *)(s))
#define FGETS(s,n,stream) fgets((char *)(s),(int)(n),(FILE *)(stream))
#define FOPEN(name,iomode) fopen((char *)(name),(char *)(iomode))
#define GETENV(env) OC(getenv((char *)(env)))
#define MEMCMP(s1,s2,n) memcmp((CONST void *)(s1),(CONST void *)(s2),\
  (size_t)(n))
#define MEMSET(buffer,c,n) memset((void *)(buffer),(int)(c),(size_t)(n))
#define QSORT(array,number,size,comparison) qsort((void *)(array),\
 (size_t)(number),(size_t)(size),\
 (int (*)(CONST void *,CONST void *))(comparison))
#define STRCAT(dest,src) strcat((char *)(dest),(CONST char *)(src))
#define STRNCAT(dest,src,n) strncat((char *)(dest),(CONST char *)(src),\
  (size_t)(n))
#define STRPBRK(s1,s2) strpbrk((CONST char *)(s1),(CONST char *)(s2))
#define STRCHR(s,c) strchr((CONST char *)(s),(int)(c))
#define STRRCHR(s,c) strrchr((CONST char *)(s),(int)(c))
#define STRCMP(s1,s2) strcmp((CONST char *)(s1),(CONST char *)(s2))
#define STRNCMP(s1,s2,n) strncmp((CONST char *)(s1),(CONST char *)(s2),\
  (size_t)(n))
#define STRCPY(dest,src) strcpy((char *)(dest),(CONST char *)(src))
#define STRNCPY(dest,src,n) strnmove((char *)(dest),(CONST char *)(src),\
  (size_t)(n))
#define MEMMOVE(dest,src,n) memmove((void *)(dest),(CONST void *)(src),\
  (size_t)(n))
#define STRSPN(s1,s2) strspn((CONST char *)(s1),(CONST char *)(s2))
#define STRLEN(s) strlen((CONST char *)(s))
#define STRTOD(s,endptr) strtod((CONST char *)(s),(char **)(endptr))
#define STRTOL(s,endptr,radix) strtol((CONST char *)(s),\
 (char **)(endptr),(int)(radix))

/* :7 */
#line 25 "./strmac.web"


#endif 

/* :6 */

