#if(0)
  FTANGLE v1.62,\
 created with UNIX on "Friday, November 17, 2017 at 11:24." \
  COMMAND LINE: "./ftangle ./ratfor0 -uCONFIG -mCONFIG -mGCC -= ratfor0.c"\
  RUN TIME:     "Friday, November 17, 2017 at 11:31."\
  WEB FILE:     "./ratfor0.web"\
  CHANGE FILE:  (none)
#endif
#define BAD_CALL(fcn_name)bad_call(OC(fcn_name)) \

/* 1: */
#line 18 "./ratfor0.web"

/* 33: */
#line 440 "./typedefs.hweb"

#include "typedefs.h"



#line 24 "./ratfor0.web"

/* :33 */
#line 19 "./ratfor0.web"

/* 34: */
#line 26 "./ratfor0.web"


#include "c_type.h"

/* :34 */
#line 20 "./ratfor0.web"

/* 32: */
#line 426 "./typedefs.hweb"





#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif



/* :32 */
/* 35: */
#line 31 "./ratfor0.web"


sixteen_bits id_function,id_program,id_subroutine;
boolean balanced= YES;
ASCII cur_delim= '\0';


/* :35 */
#line 21 "./ratfor0.web"


#line 1 "./typedefs.hweb"


#line 8 "./formats.hweb"

/* :1 */
/* 36: */
#line 41 "./ratfor0.web"

SRTN is_Rat_present(VOID)
{
Rat_is_loaded= BOOLEAN(program==weave);
}

/* :36 */
/* 37: */
#line 49 "./ratfor0.web"

boolean Rat_OK FCN((msg))
outer_char*msg C1("")
{
if(Rat_is_loaded)return YES;



err0_print(ERR_R,OC("Ratfor is not loaded.  %s"),1,msg);
return NO;
}

/* :37 */
/* 38: */
#line 64 "./ratfor0.web"

SRTN bad_call FCN((fcn_name))
outer_char*fcn_name C1("")
{

confusion(OC(fcn_name),OC("This function shouldn't be called"));
}

/* :38 */
/* 39: */
#line 72 "./ratfor0.web"

SRTN alloc_Rat(VOID)
{}

/* :39 */
/* 40: */
#line 77 "./ratfor0.web"

SRTN ini_Ratfor(VOID)
{}

/* :40 */
/* 41: */
#line 83 "./ratfor0.web"

SRTN ini_RAT_tokens FCN((language0))
LANGUAGE language0 C1("")
{
if(Rat_is_loaded)return;
BAD_CALL("ini_RAT_tokens");
}

/* :41 */
/* 42: */
#line 92 "./ratfor0.web"

SRTN cp_fcn_body(VOID)
{
BAD_CALL("cp_fcn_body");
}

/* :42 */
/* 43: */
#line 99 "./ratfor0.web"

int chk_lbl(VOID)
{
BAD_CALL("chk_lbl");
return-1;
}

/* :43 */
/* 44: */
#line 107 "./ratfor0.web"

SRTN RAT_error(VOID)
{
BAD_CALL("RAT_error");
}

/* :44 */
/* 45: */
#line 115 "./ratfor0.web"

X_FCN x_unroll(VOID)
{
Rat_OK(OC("Therefore, the _DO macro cannot be used, since it relies on some \
Ratfor features (sorry)"));
}

/* :45 */

