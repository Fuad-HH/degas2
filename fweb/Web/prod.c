#if(0)
  FTANGLE v1.62,\
 created with UNIX on "Friday, November 17, 2017 at 11:24." \
  COMMAND LINE: "./ftangle ./prod -uCONFIG -mCONFIG -mGCC -= prod.c"\
  RUN TIME:     "Friday, November 17, 2017 at 11:30."\
  WEB FILE:     "./prod.web"\
  CHANGE FILE:  (none)
#endif
#define _PROD_h   \

#define normal  0
#define roman  1
#define wildcard  2
#define typewriter  3 \

#define is_reserved(a)(a->ilk>typewriter) \

#define append_xref(c)if(xref_ptr==xmem_end) \
OVERFLW("cross-references","r"); \
else \
{ \
(++xref_ptr)->num= c; \
xref_ptr->Language= (boolean)language; \
} \

#define def_flag  ID_FLAG \

#define xref  equiv_or_xref \
 \
 \
 \

#define app(a)*(tok_ptr++)= a
#define APP_ID  app(id_flag+PTR_DIFF(sixteen_bits,id_lookup(id_first,id_loc,normal),name_dir))
#define app1(a)app(tok_flag+PTR_DIFF(sixteen_bits,(a)->trans,tok_start)) \

#undef expr  
#define expr  1 \

#undef unop  
#define unop  2 \

#undef binop  
#define binop  3 \

#define unorbinop  4 \

#define cast  5
#define question  6
#define lbrace  7
#define rbrace  8
#define decl_hd  9
#define comma  10
#define lpar  11
#define rpar  12
#define lbracket  13
#define rbracket  14
#define new_like  17
#define exp_op  18 \

#define max_math  19 \
 \

#define struct_hd  21
#define decl  20
#define label  22
#define stmt  23
#define functn  24
#define fn_decl  25
#define else_like  26
#define semi  27
#define colon  28
#define tag  29
#define if_hd  30
#define common_hd  31
#define read_hd  32
#define slashes  33
#define implicit_hd  34
#define lproc  35
#define rproc  36
#define ignore_scrap  37
#define for_hd  38
#define newline  39
#define language_scrap  40 \

#define do_like  55
#define for_like  56
#define if_like  57
#define int_like  58
#define case_like  59
#define sizeof_like  60
#define struct_like  61
#define typedef_like  62
#define define_like  63
#define common_like  64
#define read_like  65 \
 \

#define entry_like  66
#define implicit_like  67
#define assign_like  68
#define built_in  69 \

#define Rdo_like  70
#define endif_like  71
#define end_like  72
#define END_like  73
#define go_like  74
#define no_order  75
#define until_like  76
#define IF_like  77
#define IF_top  78
#define else_hd  79
#define ELSE_like  80
#define space  81
#define LPROC  82
#define UNOP  83
#define BINOP  84
#define COMMA  85
#define _EXPR  86
#define _EXPR_  87
#define EXPR_  88
#define Decl_hd  89
#define key_wd  90
#define program_like  91
#define CASE_like  92
#define modifier  93
#define class_like  94
#define op_like  95
#define proc_like  97
#define private_like  98
#define slash_like  99
#define fcn_hd  100
#define END_stmt  101
#define huge_like  102
#define imp_reserved  103
#define extern_like  104
#define while_do  105
#define template  106
#define langle  107
#define tstart  108
#define tlist  109
#define rangle  110
#define namespace  111
#define virtual  112
#define reference  113
#define kill_newlines  114 \

#define DFLUSH  if(dflush)puts(""); \

#define math_bin  (eight_bits)'\345'
#define math_rel  (eight_bits)'\346' \

#define toggle_meta  (eight_bits)'\347' \
 \

#define big_cancel  (eight_bits)'\360'
#define cancel  (eight_bits)'\361' \
 \

#define indent  (eight_bits)'\362'
#define outdent  (eight_bits)'\363'
#define opt  (eight_bits)'\364'
#define backup  (eight_bits)'\365'
#define break_space  (eight_bits)'\366'
#define force  (eight_bits)'\367'
#define big_force  (eight_bits)'\370' \

#define out_force  (eight_bits)'\371' \

#define end_translation  (eight_bits)'\377'
#define trans  trans_plus.Trans
#define no_math  2
#define yes_math  1
#define maybe_math  0 \

#define id_flag  ID_FLAG
#define res_flag  2*id_flag
#define mod_flag  ((sixteen_bits)(3*(sixteen_bits)id_flag)) \

#define tok_flag  ((sixteen_bits)(4*(sixteen_bits)id_flag))
#define inner_tok_flag  ((sixteen_bits)(5*(sixteen_bits)id_flag)) \
 \
 \

#define freeze_text  *(++text_ptr)= tok_ptr \

#define b_app2(a)b_app1(a);b_app1(a+1)
#define b_app3(a)b_app2(a);b_app1(a+2)
#define b_app4(a)b_app3(a);b_app1(a+3) \

#define INI_MATHNESS(p)((p)->mathness%4) \

#define LAST_MATHNESS(p)((p)->mathness/4) \
 \

#define FIRST_ID(p)(((tok0= first_id(p->trans))&&tok0!='(')?name_dir+tok0- \
id_flag:name_dir) \

#define cat0  pp->cat
#define cat1  (pp+1)->cat
#define cat2  (pp+2)->cat
#define cat3  (pp+3)->cat
#define cat4  (pp+4)->cat
#define cat5  (pp+5)->cat \

#define indent_force  b_app(indent);b_app(force) \
 \

#define OPT9  APP_SPACE;app(opt);app('9') \

#define APP_SPACE  APP_STR("\\ ") \

#define INDENT  if(!indented) \
{ \
b_app(indent); \
indented= YES; \
} \

#define OUTDENT  if(indented) \
{ \
b_app(outdent); \
indented= NO; \
} \

#define MAX_OP_TOKENS  5 \
 \

#define REDUCE(j,k,c,d,n)reduce(j,k,(eight_bits)(c),d,(RULE_NO)(n))
#define SQUASH(j,k,c,d,n)squash(j,k,c,d,(RULE_NO)(n)) \

#define MAX_CYCLES  500
#define OUT_WIDTH  40
/* 1: */
#line 19 "./prod.web"

/* 4: */
#line 16 "./typedefs.hweb"


#ifndef part
#define part 0 
#else
#if(part != 1 && part != 2 && part != 3)
#define part 1 
#endif
#endif 


/* :4 */
/* 5: */
#line 42 "./typedefs.hweb"


#if(part == 0 || part == 1)
#define part1_or_extern
#define SET1(stuff)  =  stuff
#define TSET1(stuff)  =  stuff
#else
#define part1_or_extern extern
#define SET1(stuff)
#define TSET1(stuff)
#endif


/* :5 */
#line 20 "./prod.web"


/* 33: */
#line 440 "./typedefs.hweb"

#include "typedefs.h"



#line 38 "./prod.web"

/* :33 */
/* 34: */
#line 40 "./prod.web"

#include "map.h"

/* :34 */
#line 22 "./prod.web"

/* 38: */
#line 79 "./xrefs.hweb"


typedef struct xref_info0
{
sixteen_bits num;
struct xref_info0 HUGE*xlink;

boolean Language;
}xref_info;

typedef xref_info HUGE*xref_pointer;
typedef ASCII HUGE*XREF_POINTER;



/* :38 */
/* 40: */
#line 27 "./tokens.hweb"


typedef sixteen_bits Token;
typedef Token HUGE*token_pointer;
typedef token_pointer HUGE*text_pointer;

/* :40 */
/* 48: */
#line 44 "./scraps.hweb"

#line 45 "./scraps.hweb"

typedef struct
{
eight_bits cat;


eight_bits mathness;
union
{
text_pointer Trans;
/* 53: */
#line 242 "./prod.web"

#line 243 "./prod.web"

/* :53 */
#line 55 "./scraps.hweb"

}trans_plus;
}scrap;

typedef scrap HUGE*scrap_pointer;

/* :48 */
/* 434: */
#line 5810 "./prod.web"


typedef unsigned long RULE_NO;

/* :434 */
#line 23 "./prod.web"

/* 35: */
#line 44 "./prod.web"


#include "p_type.h"

#line 8 "./xrefs.hweb"

/* :35 */
#line 24 "./prod.web"

/* 32: */
#line 426 "./typedefs.hweb"





#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif



/* :32 */
/* 37: */
#line 47 "./xrefs.hweb"


EXTERN boolean change_exists;

/* :37 */
/* 39: */
#line 111 "./xrefs.hweb"


#ifndef COMMON_FCNS_
IN_COMMON BUF_SIZE max_modules;
#endif

EXTERN BUF_SIZE max_refs;
EXTERN xref_info HUGE*xmem;
EXTERN xref_pointer xmem_end;

EXTERN xref_pointer xref_ptr;

EXTERN sixteen_bits xref_switch,mod_xref_switch;
EXTERN boolean defd_switch;
EXTERN NAME_TYPE defd_type SET(NEVER_DEFINED);
EXTERN boolean typd_switch;
EXTERN boolean index_short;
#line 8 "./tokens.hweb"

/* :39 */
/* 41: */
#line 37 "./tokens.hweb"


EXTERN long max_toks;

EXTERN Token HUGE*tok_mem;
EXTERN token_pointer tok_m_end;

EXTERN long max_texts;

EXTERN token_pointer HUGE*tok_start;
EXTERN text_pointer tok_end;

EXTERN token_pointer tok_ptr;
EXTERN text_pointer text_ptr;

EXTERN token_pointer mx_tok_ptr;
EXTERN text_pointer mx_text_ptr;
#line 50 "./prod.web"

/* :41 */
/* 44: */
#line 100 "./prod.web"


IN_PROD boolean dflush PSET(NO);

/* :44 */
/* 49: */
#line 67 "./scraps.hweb"


EXTERN long max_scraps;
EXTERN scrap HUGE*scrp_info;
EXTERN scrap_pointer scrp_end;

EXTERN scrap_pointer pp;
EXTERN scrap_pointer scrp_base;
EXTERN scrap_pointer scrp_ptr;
EXTERN scrap_pointer lo_ptr;
EXTERN scrap_pointer hi_ptr;

EXTERN scrap_pointer mx_scr_ptr;

/* :49 */
/* 56: */
#line 375 "./prod.web"


IN_PROD int cur_mathness,ini_mathness,last_mathness;

/* :56 */
/* 64: */
#line 720 "./prod.web"


IN_PROD sixteen_bits tok0;

/* :64 */
/* 68: */
#line 855 "./prod.web"


IN_PROD PARSING_MODE translate_mode;

/* :68 */
/* 97: */
#line 1208 "./prod.web"


IN_PROD boolean active_space PSET(NO);
IN_PROD boolean in_LPROC PSET(NO);
IN_PROD boolean expanded_lproc PSET(NO);

/* :97 */
/* 103: */
#line 1272 "./prod.web"


extern boolean did_arg;

/* :103 */
/* 132: */
#line 1708 "./prod.web"


IN_PROD int in_prototype PSET(NO);

IN_PROD int indented PSET(NO);

/* :132 */
/* 133: */
#line 1717 "./prod.web"


IN_PROD boolean in_function PSET(NO);

/* :133 */
/* 148: */
#line 2020 "./prod.web"


IN_PROD boolean typedefing PSET(NO);

/* :148 */
/* 176: */
#line 2462 "./prod.web"

IN_PROD boolean kill_nl PSET(NO);

/* :176 */
/* 215: */
#line 2885 "./prod.web"


/* :215 */
/* 215: */
#line 2890 "./prod.web"

/* :215 */
/* 264: */
#line 3417 "./prod.web"


IN_PROD boolean forward_exp PSET(NO);

/* :264 */
/* 275: */
#line 3626 "./prod.web"


IN_PROD int fcn_level PSET(0);

/* :275 */
/* 334: */
#line 4452 "./prod.web"


IN_PROD text_pointer label_text_ptr[50];

/* :334 */
/* 341: */
#line 4599 "./prod.web"


IN_PROD boolean found_until PSET(NO);

/* :341 */
/* 348: */
#line 4674 "./prod.web"


IN_PROD int indent_level PSET(0);
IN_PROD int loop_num[50],max_loop_num PSET(0);

/* :348 */
/* 392: */
#line 5319 "./prod.web"


/* :392 */
/* 412: */
#line 5613 "./prod.web"


IN_PROD int containing PSET(0);

/* :412 */
#line 25 "./prod.web"




#if(part != 2)
/* 45: */
#line 114 "./prod.web"

#ifdef DEBUG

SRTN
prn_cat FCN((c))
eight_bits c C1("Category.")
{
switch(c)
{
case language_scrap:printf("@L");break;
case expr:printf("expr");break;
case exp_op:printf("^^");break;
case _EXPR:printf("$_EXPR");break;case EXPR_:printf("$EXPR_");break;case _EXPR_:printf("$_EXPR_");break;
case new_like:printf("new_like");break;
case stmt:printf("stmt");break;
case decl:printf("decl");break;
case decl_hd:printf("decl_hd");break;
case Decl_hd:printf("$Decl_hd");break;
case struct_hd:printf("struct_hd");break;
case functn:printf("functn");break;
case fn_decl:printf("fn_decl");break;
case fcn_hd:printf("fcn_hd");break;
case else_like:printf("else");break;
case ELSE_like:printf("ELSE");break;
case if_hd:printf("if_hd");break;
case IF_top:printf("IF_top");break;
case else_hd:printf("else_hd");break;
case for_hd:printf("for_hd");break;
case unop:printf("unop");break;
case UNOP:printf("$UNOP_");break;
case binop:printf("binop");break;
case BINOP:printf("$_BINOP_");break;
case unorbinop:printf("unorbinop");break;
case semi:printf(";");break;
case colon:printf(":");break;
case comma:printf(",");break;
case COMMA:printf("$_COMMA_");break;
case question:printf("?");break;
case tag:printf("tag");break;
case cast:printf("cast");break;
case lpar:printf("(");break;
case rpar:printf(")");break;
case lbracket:printf("[");break;
case rbracket:printf("]");break;
case lbrace:printf("{");break;
case rbrace:printf("}");break;
case common_hd:printf("common_hd");break;
case read_hd:printf("read_hd");break;
case slash_like:printf("slash");break;
case private_like:printf("private");break;
case slashes:printf("slashes");break;
case lproc:printf("#{");break;
case LPROC:printf("LPROC");break;
case rproc:printf("#}");break;
case ignore_scrap:printf("ignore");break;

case define_like:printf("define");break;
case no_order:printf("no_order");break;
case do_like:printf("do");break;
case while_do:printf("while");break;
case Rdo_like:printf("Rdo");break;
case if_like:printf("if");break;
case IF_like:printf("IF");break;
case for_like:printf("for");break;
case program_like:printf("program");break;
case int_like:printf("int");break;
case modifier:printf("modifier");break;
case huge_like:printf("huge");break;
case CASE_like:printf("CASE");break;
case case_like:printf("case");break;
case sizeof_like:printf("sizeof");break;
case op_like:printf("op");break;
case proc_like:printf("proc");break;
case class_like:printf("class");break;
case struct_like:printf("struct");break;
case typedef_like:printf("typedef");break;
case imp_reserved:printf("imp_rsrvd");break;
case extern_like:printf("extern");break;
case common_like:printf("common");break;
case read_like:printf("read");break;
case entry_like:printf("entry");break;
case implicit_like:printf("implicit");break;
case implicit_hd:printf("implicit_hd");break;
case built_in:printf("built_in");break;
case endif_like:printf("endif");break;
case end_like:printf("end");break;
case END_like:printf("END");break;
case END_stmt:printf("END_stmt");break;
case go_like:printf("go");break;
case newline:printf("\n");break;
case label:printf("label");break;
case space:printf("space");break;
case until_like:printf("until");break;
case template:printf("template");break;
case langle:printf("langle");break;
case rangle:printf("rangle");break;
case tstart:printf("tstart");break;
case tlist:printf("tlist");break;
case namespace:printf("namespace");break;
case virtual:printf("virtual");break;
case reference:printf("ref");break;
case kill_newlines:printf("killnl");break;

case 0:printf("zero");break;
default:printf("UNKNOWN(%i)",c);break;
}

DFLUSH;
}

#endif 

#line 8 "./output.hweb"

/* :45 */
/* 54: */
#line 247 "./prod.web"

#ifdef DEBUG

SRTN
prn_text FCN((p))
text_pointer p C1("The token list.")
{
token_pointer j;
sixteen_bits r;

if(p>=text_ptr)
printf("BAD");
else for(j= *p;j<*(p+1);j++)
{
r= (sixteen_bits)(*j%id_flag);

switch(*j/id_flag)
{
case 1:printf("\\\\{");prn_id((name_dir+r));printf("}");break;

case 2:printf("\\&{");prn_id((name_dir+r));printf("}");break;

case 3:printf("<");prn_id((name_dir+r));printf(">");break;

case 4:printf("[[%d]]",r);break;
case 5:printf("|[[%d]]|",r);break;
default:/* 55: */
#line 290 "./prod.web"


switch(r)
{
case math_bin:printf("\\mathbin}");break;
case math_rel:printf("\\mathrel}");break;
case big_cancel:printf("[ccancel]");break;
case cancel:printf("[cancel]");break;
case indent:printf("[indent]");break;
case outdent:printf("[outdent]");break;
case backup:printf("[backup]");break;
case opt:printf("[opt]");break;
case break_space:printf("[break]");break;
case force:printf("[force]");break;
case big_force:printf("[fforce]");break;
case end_translation:printf("[quit]");break;
default:putxchar(XCHR(r));
}

/* :55 */
#line 273 "./prod.web"
;
}
}

DFLUSH;
}

SRTN
prn_trans FCN((p))
scrap_pointer p C1("")
{
prn_text(indirect(p->trans));
}

#endif 

/* :54 */
/* 57: */
#line 382 "./prod.web"


SRTN
app_str FCN((s))
CONST outer_char HUGE*s C1("String to be appended.")
{
while(*s)
app(XORD(*(s++)));
}


SRTN
app_ASCII_str FCN((s))
CONST ASCII HUGE*s C1("")
{
while(*s)
app(*s++);
}

/* :57 */
/* 58: */
#line 403 "./prod.web"


SRTN
b_app FCN((a))
Token a C1("Token to be appended.")
{
if(a==' '||(a>=big_cancel&&a<=big_force))
{
if(cur_mathness==maybe_math)
ini_mathness= no_math;
else if(cur_mathness==yes_math)
{
#ifdef DBGM
app('4');
#endif 
app('$');
}

cur_mathness= last_mathness= no_math;
}
else
{
if(cur_mathness==maybe_math)
ini_mathness= yes_math;
else if(cur_mathness==no_math)
{
app('$');
#ifdef DBGM
app('3');
#endif
}

cur_mathness= last_mathness= yes_math;
}

app(a);
}

/* :58 */
/* 59: */
#line 450 "./prod.web"


SRTN
b_app1 FCN((a))
scrap_pointer a C1("Scrap to be appended.")
{
switch(INI_MATHNESS(a))
{
case no_math:
if(cur_mathness==maybe_math)
ini_mathness= no_math;
else if(cur_mathness==yes_math)
{
#ifdef DBGM
app('2');
#endif
APP_STR("$");

}

cur_mathness= last_mathness= LAST_MATHNESS(a);
break;

case yes_math:
if(cur_mathness==maybe_math)
ini_mathness= yes_math;
else if(cur_mathness==no_math)
{
APP_STR("$");

#ifdef DBGM
app('1');
#endif
}

cur_mathness= last_mathness= LAST_MATHNESS(a);
break;

case maybe_math:
break;
}

app(a->trans+tok_flag-tok_start);
}

/* :59 */
/* 61: */
#line 563 "./prod.web"

int
get_language FCN((xp))
text_pointer xp C1("")
{
token_pointer tp,tp1;

tp= *xp;
tp1= *(xp+1)-1;


while(tp<tp1)
if(*tp++==begin_language)return*tp;

return
confusion(OC("get_language"),OC("Can't find |begin_language| token in language_scrap"));
}

/* :61 */
/* 62: */
#line 584 "./prod.web"


SRTN
C_productions(VOID)
{
switch(pp->cat)
{
case ignore_scrap:/* 71: */
#line 928 "./prod.web"


#if FCN_CALLS
C_ignore_scrap();
#else
/* 73: */
#line 947 "./prod.web"

{
switch(cat1)
{
case stmt:
case functn:
SQUASH(pp,2,cat1,0,1);
break;
}
}

/* :73 */
#line 933 "./prod.web"

#endif

/* :71 */
#line 591 "./prod.web"
break;
case built_in:/* 422: */
#line 5708 "./prod.web"

#if FCN_CALLS
R_built_in();
#else
/* 424: */
#line 5725 "./prod.web"

{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5728 "./prod.web"
;
REDUCE(pp,1,expr,-2,9998);
}

/* :424 */
#line 5712 "./prod.web"

#endif

/* :422 */
#line 592 "./prod.web"
break;
case expr:/* 74: */
#line 959 "./prod.web"

#if FCN_CALLS
C_expr();
#else
/* 76: */
#line 979 "./prod.web"

{
if(cat1==lbrace||((!Cpp)&&cat1==int_like))
{
defined_at(make_underlined(pp));

in_function= YES;
SQUASH(pp,1,fn_decl,0,111);
}
else if(cat1==unop)
SQUASH(pp,2,expr,-2,2);
else if(cat1==binop)
{
if(cat2==expr)
SQUASH(pp,3,expr,-2,3);
else if(cat2==decl_hd)
SQUASH(pp,3,tstart,0,6061);

}
else if(cat1==unorbinop&&cat2==expr)
{
sixteen_bits*s= *(pp+1)->trans;
b_app1(pp);



if((s[0]==(sixteen_bits)'\\')&&s[1]==(sixteen_bits)'a'
&&s[2]==(sixteen_bits)'m')
{
APP_SPACE;b_app1(pp+1);APP_SPACE;
}
else b_app1(pp+1);

b_app1(pp+2);
REDUCE(pp,3,expr,-2,3000);
}
else if(cat1==comma)
{
if((cat2==expr||cat2==int_like))
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,cat2,-2,4);
}
else if(cat2==space)
SQUASH(pp,3,expr,-2,88);
}
else if(cat1==expr)
SQUASH(pp,2,expr,-2,5);
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,6);
else if(cat1==colon)
{
if(!Cpp||in_function)
{
make_underlined(pp);
SQUASH(pp,2,tag,0,7);
}
else if(cat2==expr||cat2==int_like)
{

b_app1(pp);b_app(' ');b_app1(pp+1);b_app(' ');
b_app1(pp+2);
REDUCE(pp,3,expr,-2,701);

}
}
else if(cat1==space)
SQUASH(pp,2,expr,-2,8);
}

/* :76 */
#line 963 "./prod.web"

#endif

/* :74 */
#line 593 "./prod.web"
break;
case exp_op:/* 272: */
#line 3590 "./prod.web"

#if FCN_CALLS
R_exp_op();
#else
/* 274: */
#line 3607 "./prod.web"

{
if(cat1==lpar)SQUASH(pp,1,exp_op,PLUS 1,2995);
else if(cat1==expr)
if(cat2==lpar)SQUASH(pp,1,exp_op,PLUS 2,2996);

else if(cat2==expr)SQUASH(pp,1,exp_op,PLUS 1,2997);

else
{

b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
REDUCE(pp,2,expr,-1,2998);
}
}

/* :274 */
#line 3594 "./prod.web"

#endif

/* :272 */
#line 594 "./prod.web"
break;
case _EXPR:/* 87: */
#line 1130 "./prod.web"

#if FCN_CALLS
C__E();
#else
/* 89: */
#line 1147 "./prod.web"

{
APP_SPACE;b_app1(pp);
REDUCE(pp,1,expr,-2,4446);
}

/* :89 */
#line 1134 "./prod.web"

#endif

/* :87 */
#line 595 "./prod.web"
break;
case _EXPR_:/* 90: */
#line 1154 "./prod.web"

#if FCN_CALLS
C__E_();
#else
/* 92: */
#line 1171 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1173 "./prod.web"
;
REDUCE(pp,1,expr,-2,4447);
}

/* :92 */
#line 1158 "./prod.web"

#endif

/* :90 */
#line 596 "./prod.web"
break;
case EXPR_:/* 93: */
#line 1178 "./prod.web"

#if FCN_CALLS
C_E_();
#else
/* 95: */
#line 1195 "./prod.web"

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,expr,-2,4448);
}

/* :95 */
#line 1182 "./prod.web"

#endif

/* :93 */
#line 597 "./prod.web"
break;
case new_like:/* 98: */
#line 1215 "./prod.web"

#if FCN_CALLS
C_new_like();
#else
/* 100: */
#line 1232 "./prod.web"

{
if(cat1==lbracket&&cat2==rbracket)
{
b_app1(pp);b_app(' ');b_app1(pp+1);/* 325: */
#line 4334 "./prod.web"

{
b_app('\\');b_app(';');
}

/* :325 */
#line 1236 "./prod.web"
;b_app1(pp+2);
b_app(' ');
REDUCE(pp,3,expr,-2,910);
}
else if(cat1==decl_hd||cat1==expr)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
if(cat1==decl_hd)
{
OUTDENT;
}
REDUCE(pp,2,expr,-2,909);
}
}

/* :100 */
#line 1219 "./prod.web"

#endif

/* :98 */
#line 598 "./prod.web"
break;
case lpar:/* 165: */
#line 2332 "./prod.web"

#if FCN_CALLS
C_lpar();
#else
/* 167: */
#line 2349 "./prod.web"

{
if(cat2==rpar&&(cat1==expr||cat1==unorbinop))
SQUASH(pp,3,expr,-2,120);
else if(cat1==rpar)
{

b_app1(pp);/* 325: */
#line 4334 "./prod.web"

{
b_app('\\');b_app(';');
}

/* :325 */
#line 2356 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if((cat1==decl_hd)&&cat2==rpar)
{

b_app3(pp);

OUTDENT;

if(in_prototype)
in_prototype--;

REDUCE(pp,3,cast,-1,122);
}
else if(cat1==stmt)
{
b_app2(pp);b_app(' ');REDUCE(pp,2,lpar,0,123);
}
else if(cat1==for_like&&cat2==rpar)
SQUASH(pp,3,expr,-2,1201);
}

/* :167 */
#line 2336 "./prod.web"

#endif

/* :165 */
#line 599 "./prod.web"
break;
case lbracket:/* 168: */
#line 2380 "./prod.web"

#if FCN_CALLS
C_lbracket();
#else
/* 170: */
#line 2397 "./prod.web"

{
if(active_brackets)
{
b_app('\\');
APP_STR("WXA{");
}
else b_app1(pp);

REDUCE(pp,1,lpar,0,5000);
}

/* :170 */
#line 2384 "./prod.web"

#endif

/* :168 */
#line 600 "./prod.web"
break;
case rbracket:/* 171: */
#line 2410 "./prod.web"

#if FCN_CALLS
C_rbracket();
#else
/* 173: */
#line 2427 "./prod.web"

{
if(active_brackets)
{
text_pointer t= indirect(pp->trans);

if(**t==']')**t= '}';
}

b_app1(pp);

REDUCE(pp,1,rpar,-5,5001);
}

/* :173 */
#line 2414 "./prod.web"

#endif

/* :171 */
#line 601 "./prod.web"
break;
case question:/* 111: */
#line 1420 "./prod.web"

#if FCN_CALLS
C_question();
#else
/* 113: */
#line 1437 "./prod.web"

{
if(cat1==expr&&cat2==colon)SQUASH(pp,3,binop,-2,30);

}

/* :113 */
#line 1424 "./prod.web"

#endif

/* :111 */
#line 602 "./prod.web"
break;
case unop:/* 183: */
#line 2540 "./prod.web"

#if FCN_CALLS
C__unop();
#else
/* 185: */
#line 2557 "./prod.web"

{
if(cat1==expr)
SQUASH(pp,2,expr,-2,140);
else if(cat1==int_like)
SQUASH(pp,2,int_like,0,141);

}

/* :185 */
#line 2544 "./prod.web"

#endif

/* :183 */
#line 603 "./prod.web"
break;
case UNOP:/* 78: */
#line 1058 "./prod.web"

#if FCN_CALLS
C_UNOP();
#else
/* 80: */
#line 1075 "./prod.web"

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,unop,-1,4443);
}

/* :80 */
#line 1062 "./prod.web"

#endif

/* :78 */
#line 604 "./prod.web"
break;
case unorbinop:/* 186: */
#line 2567 "./prod.web"

#if FCN_CALLS
C_unorbinop();
#else
/* 188: */
#line 2584 "./prod.web"

{
if(cat1==expr||(cat1==int_like&&!(cat2==lpar||cat2==unop)))
{


b_app('{');b_app1(pp);b_app('}');
b_app1(pp+1);
REDUCE(pp,2,cat1,-2,150);
}
else if(cat1==binop)
/* 189: */
#line 2599 "./prod.web"

{
b_app(math_bin);
b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,151);
}

/* :189 */
#line 2595 "./prod.web"

}

/* :188 */
#line 2571 "./prod.web"

#endif

/* :186 */
#line 605 "./prod.web"
break;
case binop:/* 196: */
#line 2666 "./prod.web"

#if FCN_CALLS
C__binop();
#else
/* 198: */
#line 2683 "./prod.web"

{
if(cat1==binop)
/* 199: */
#line 2699 "./prod.web"

{
b_app(math_bin);b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,180);
}

/* :199 */
#line 2686 "./prod.web"

else if(cat1==space)
{
b_app1(pp);
REDUCE(pp,2,binop,-1,181);
}
else if(Cpp&&cat1==decl_hd)
SQUASH(pp,2,tstart,0,6063);


}

/* :198 */
#line 2670 "./prod.web"

#endif

/* :196 */
#line 606 "./prod.web"
break;
case BINOP:/* 81: */
#line 1082 "./prod.web"

#if FCN_CALLS
C_BINOP();
#else
/* 83: */
#line 1099 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1101 "./prod.web"
;
REDUCE(pp,1,binop,-1,4444);
}

/* :83 */
#line 1086 "./prod.web"

#endif

/* :81 */
#line 607 "./prod.web"
break;
case COMMA:/* 84: */
#line 1106 "./prod.web"

#if FCN_CALLS
C_COMMA();
#else
/* 86: */
#line 1123 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1125 "./prod.web"
;
REDUCE(pp,1,comma,-1,4445);
}

/* :86 */
#line 1110 "./prod.web"

#endif

/* :84 */
#line 608 "./prod.web"
break;
case cast:/* 190: */
#line 2609 "./prod.web"

#if FCN_CALLS
C_cast();
#else
/* 192: */
#line 2626 "./prod.web"

{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2630 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,expr,-2,160);
}
else if(cat1==unorbinop||cat1==reference)
SQUASH(pp,1,cast,PLUS 1,162);
else
SQUASH(pp,1,expr,-2,161);
}

/* :192 */
#line 2613 "./prod.web"

#endif

/* :190 */
#line 609 "./prod.web"
break;
case sizeof_like:/* 193: */
#line 2640 "./prod.web"

#if FCN_CALLS
C_sizeof_like();
#else
/* 195: */
#line 2657 "./prod.web"

{
if(cat1==cast)
SQUASH(pp,2,expr,-2,170);
else if(cat1==expr)
SQUASH(pp,2,expr,-2,171);
}

/* :195 */
#line 2644 "./prod.web"

#endif

/* :193 */
#line 610 "./prod.web"
break;
case int_like:/* 114: */
#line 1444 "./prod.web"

#if FCN_CALLS
C_int_like();
#else
/* 116: */
#line 1461 "./prod.web"

{
if(cat1==unop)
{
if(cat2==expr||cat2==int_like)
SQUASH(pp,3,expr,-2,35);

else if(cat2==op_like)
SQUASH(pp,1,int_like,PLUS 2,36);

}
else if(cat1==int_like||cat1==struct_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,cat1,0,40);
}
else if(cat1==reference)
SQUASH(pp,2,int_like,-2,43);
else if(cat1==expr||cat1==unorbinop||cat1==semi)
{
b_app1(pp);

if(cat1!=semi)
app('~');

#if 0
INDENT;

#endif

REDUCE(pp,1,decl_hd,-1,41);
}
else if(cat1==comma)
{
b_app1(pp);
#if 0
INDENT;
#endif
REDUCE(pp,1,decl_hd,-2,42);
}
else if(cat1==rpar)
{
b_app1(pp);
#if 0
INDENT;
#endif
REDUCE(pp,1,decl_hd,-2,502);
}
else if(Cpp&&cat1==lpar&&!in_prototype)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 1512 "./prod.web"

REDUCE(pp,1,expr,-2,5021);

}
else if(cat1==binop&&cat2==expr)
SQUASH(pp,3,int_like,-2,5022);
else if(cat1==langle)
SQUASH(pp,1,int_like,PLUS 1,5997);
else if(cat1==rangle)
{
b_app1(pp);
#if 0
INDENT;
#endif
REDUCE(pp,1,decl_hd,-2,5998);
}
else if(cat1==class_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,class_like,0,5995);
}
else if(cat1==tlist)
SQUASH(pp,2,int_like,-2,5999);
else if(cat1==namespace)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,namespace,0,5996);
}
}

/* :116 */
#line 1448 "./prod.web"

#endif

/* :114 */
#line 611 "./prod.web"
break;
case extern_like:/* 117: */
#line 1545 "./prod.web"

#if FCN_CALLS
C_ext_like();
#else
/* 119: */
#line 1562 "./prod.web"

{
if(Cpp&&cat1==expr)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
if(cat2==lbrace||cat2==kill_newlines)
REDUCE(pp,2,fn_decl,0,5025);
else
REDUCE(pp,2,int_like,0,5023);

}
else
SQUASH(pp,1,int_like,0,5024);
}

/* :119 */
#line 1549 "./prod.web"

#endif

/* :117 */
#line 612 "./prod.web"
break;
case modifier:/* 120: */
#line 1582 "./prod.web"

#if FCN_CALLS
C_modifier();
#else
/* 122: */
#line 1599 "./prod.web"

{
if(cat1==int_like||cat1==struct_like||cat1==class_like)
SQUASH(pp,1,cat1,-2,503);
else if(pp==lo_ptr)
SQUASH(pp,1,expr,0,5040);
else if(cat1==comma||cat1==semi||cat1==lbrace||cat1==kill_newlines)
SQUASH(pp,1,_EXPR,0,5042);


else
SQUASH(pp,1,EXPR_,0,5041);
}

/* :122 */
#line 1586 "./prod.web"

#endif

/* :120 */
#line 613 "./prod.web"
break;
case huge_like:/* 123: */
#line 1615 "./prod.web"

#if FCN_CALLS
C_huge_like();
#else
/* 125: */
#line 1632 "./prod.web"

{
if(cat1==unorbinop)
{
b_app1(pp);APP_SPACE;b_app1(pp+1);
REDUCE(pp,2,unorbinop,-1,505);
}
}

/* :125 */
#line 1619 "./prod.web"

#endif

/* :123 */
#line 614 "./prod.web"
break;
case decl_hd:/* 134: */
#line 1723 "./prod.web"

#if FCN_CALLS
C_decl_hd();
#else
/* 136: */
#line 1740 "./prod.web"

{
if(cat1==rpar)
{
if((pp-1)->cat==lpar)
SQUASH(pp,1,decl_hd,-1,4990);
else if((pp-2)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-2,4991);
else if((pp-3)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-3,4992);
}
else if(cat1==decl_hd)
SQUASH(pp,2,decl_hd,0,50);
else if(cat1==comma)
{
if(cat2==decl_hd)
{
b_app2(pp);OPT9;
b_app1(pp+2);
REDUCE(pp,3,decl_hd,0,501);
}
else if(cat2==ignore_scrap&&cat3==decl_hd)
{
b_app2(pp);OPT9;
b_app2(pp+2);
REDUCE(pp,4,decl_hd,0,504);
}
#if 0
else if(Cpp&&(cat2==decl||cat2==stmt))
SQUASH(pp,3,stmt,-2,508);


#endif
else
{
if(cat2==ignore_scrap&&(cat3==int_like||cat3==struct_like||
cat3==modifier))
{
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat3!=modifier)
in_prototype++;
REDUCE(pp,1,decl_hd,PLUS 3,5221);
}
else if(cat2==int_like||cat2==struct_like||cat2==modifier)
{
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat2!=modifier)
in_prototype++;


REDUCE(pp,1,decl_hd,PLUS 2,52);
}
else
{
b_app2(pp);app('~');

#if 0
if(Cpp)
REDUCE(pp,2,decl_hd,-2,540);

else
#endif
REDUCE(pp,2,decl_hd,-1,54);
}
}
}
else if(cat1==unorbinop)
{
b_app1(pp);
b_app('{');
b_app1(pp+1);
b_app('}');
REDUCE(pp,2,decl_hd,-1,55);
}
else if(cat1==expr)
{
make_underlined(pp+1);
SQUASH(pp,2,decl_hd,-1,56);

}
else if((cat1==binop||cat1==colon
||cat1==expr
)&&cat2==expr&&(cat3==comma||cat3==semi||cat3==rpar))
#if 0
if(cat1==binop)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,decl_hd,-1,5660);
}
else
#endif
SQUASH(pp,3,decl_hd,-1,5661);
else if(cat1==int_like&&(cat2==unop||cat2==langle))
SQUASH(pp,1,decl_hd,PLUS 1,5662);


else if(cat1==lbrace||(cat1==int_like&&
((pp-1)->trans==NULL||**(pp-1)->trans!='(')))


{
b_app1(pp);
#if 0
OUTDENT;
#endif
in_function= YES;
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi)
{
b_app2(pp);
#if 0
OUTDENT;
#endif
#if 0
if(Cpp)
REDUCE(pp,2,decl,-2,594);

else
#endif
REDUCE(pp,2,decl,-1,59);
}
else if(Cpp&&cat1==int_like&&cat2==unop)
SQUASH(pp,1,decl_hd,PLUS 1,590);
else if(Cpp&&cat1==rangle)
SQUASH(pp,1,decl_hd,-2,591);
else if(Cpp&&cat1==struct_like)
SQUASH(pp,2,decl_hd,-1,593);

}

/* :136 */
#line 1727 "./prod.web"

#endif

/* :134 */
#line 615 "./prod.web"
break;
case decl:/* 137: */
#line 1877 "./prod.web"

#if FCN_CALLS
C_decl();
#else
/* 139: */
#line 1894 "./prod.web"

{
if(Cpp)
{
if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,61);
}
else
SQUASH(pp,1,stmt,-1,611);
}
else
{
if(cat1==decl)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,61);
}
}
}

/* :139 */
#line 1881 "./prod.web"

#endif

/* :137 */
#line 616 "./prod.web"
break;
case typedef_like:/* 146: */
#line 2003 "./prod.web"

#if FCN_CALLS
C_typedef_like();
#else
/* 149: */
#line 2025 "./prod.web"

{
if(cat1==decl_hd&&(cat2==expr||cat2==int_like))
{
make_underlined(pp+2);make_reserved(pp+2);
b_app2(pp+1);
REDUCE(pp+1,2,decl_hd,0,90);
}
else if(cat1==decl)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,decl,-1,91);
}
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,94);

else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,stmt,-1,95);

}

}

/* :149 */
#line 2007 "./prod.web"

#endif

/* :146 */
#line 617 "./prod.web"
break;
case imp_reserved:/* 150: */
#line 2051 "./prod.web"

#if FCN_CALLS
C_imp_reserved();
#else
/* 152: */
#line 2070 "./prod.web"

{
if(typedefing)SQUASH(pp,1,expr,-2,92);
else SQUASH(pp,1,int_like,-2,93);
}

/* :152 */
#line 2055 "./prod.web"

#endif

/* :150 */
#line 618 "./prod.web"
break;
case op_like:/* 153: */
#line 2082 "./prod.web"

#if FCN_CALLS
C_op_like();
#else
/* 155: */
#line 2099 "./prod.web"

{
short n;


if((cat1==lpar&&cat2==rpar)||(cat1==lbracket&&cat2==rbracket))
{



APP_STR("\\Woperator");
b_app('{');
b_app1(pp+1);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2112 "./prod.web"

b_app1(pp+2);
b_app('}');
n= 3;
}
else
{

scrap_pointer q;
int k;



for(q= pp+1;q<=scrp_ptr&&q-pp<=MAX_OP_TOKENS;q++)
if(q->cat==lpar)
break;

n= (q->cat==lpar)?PTR_DIFF(short,q,pp):0;


if(n>0)
{
text_pointer xp;
token_pointer tp,tp1;

#if 0
b_app1(pp);
b_app('{');

#endif
APP_STR("\\Woperator");
b_app('{');

id_first= id_loc= mod_text+1;

for(k= 1;k<n;k++)
{
b_app1(pp+k);

xp= indirect((pp+k)->trans);
tp= *xp;
tp1= *(xp+1);
while(tp<tp1)
*id_loc++= (ASCII)(*tp++);
}

underline_xref(id_lookup(id_first,id_loc,0));

b_app('}');
}
}

if(n>0)
REDUCE(pp,n,expr,-2,6666);
else
{
APP_STR("\\Woperatoro");
REDUCE(pp,1,expr,-2,6668);
}
}

/* :155 */
#line 2086 "./prod.web"

#endif

/* :153 */
#line 619 "./prod.web"
break;
case class_like:/* 156: */
#line 2176 "./prod.web"

#if FCN_CALLS
C_class_like();
#else
/* 158: */
#line 2193 "./prod.web"

{
if(cat1==expr||cat1==int_like)
{
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(' ');b_app1(pp+1);

if((pp-1)->cat==tstart||(pp-1)->cat==decl_hd
||(pp-1)->cat==lpar)
REDUCE(pp,2,decl_hd,-1,8998);
else
REDUCE(pp,2,struct_like,0,8999);
}
else if(cat1==lbrace)
SQUASH(pp,1,struct_like,0,8987);

}

/* :158 */
#line 2180 "./prod.web"

#endif

/* :156 */
#line 620 "./prod.web"
break;
case struct_like:/* 159: */
#line 2214 "./prod.web"

#if FCN_CALLS
C_struct_like();
#else
/* 161: */
#line 2234 "./prod.web"

{
if(cat1==lbrace)
{
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}
else if(cat1==expr)
{
if(cat2==lbrace)
{

if(Cpp)
{make_underlined(pp+1);make_reserved(pp+1);}

b_app1(pp);b_app(' ');b_app1(pp+1);
indent_force;
b_app1(pp+2);
REDUCE(pp,3,struct_hd,0,101);
}
else
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,int_like,-1,102);
}
}
else if(cat1==colon&&cat2==int_like&&Cpp)
{
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1023);
else
{
b_app1(pp);b_app(' ');b_app1(pp+1);b_app(' ');
b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1021);
}
}
else if(cat1==comma&&cat2==int_like&&Cpp)
{
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1024);
else
{
b_app2(pp);b_app(' ');b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1022);
}
}
else if(cat1==tlist)
SQUASH(pp,2,struct_like,0,1025);
else if(cat1==semi)
SQUASH(pp,2,decl,-1,103);
else if(cat1==rangle)
SQUASH(pp,1,decl_hd,-2,592);
}

/* :161 */
#line 2218 "./prod.web"

#endif

/* :159 */
#line 621 "./prod.web"
break;
case struct_hd:/* 162: */
#line 2290 "./prod.web"

#if FCN_CALLS
C_str_hd();
#else
/* 164: */
#line 2307 "./prod.web"

{
if((cat1==decl||cat1==stmt
||cat1==expr
||cat1==functn
)&&cat2==rbrace)
{
b_app1(pp);
/* 182: */
#line 2528 "./prod.web"

{
/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2530 "./prod.web"


b_app1(pp+1);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2534 "./prod.web"


kill_nl= NO;
}

/* :182 */
#line 2315 "./prod.web"

b_app1(pp+2);
b_app(outdent);
/* :164 */
/* 164: */
#line 2321 "./prod.web"
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2325 "./prod.web"
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}

/* :164 */
#line 2294 "./prod.web"

#endif

/* :162 */
#line 622 "./prod.web"
break;
case fn_decl:/* 140: */
#line 1926 "./prod.web"

#if FCN_CALLS
C_fn_decl();
#else
/* 142: */
#line 1943 "./prod.web"

{
if(cat1==semi&&Cpp)
{
b_app2(pp);
REDUCE(pp,2,stmt,-1,72);
}
else if(cat1==decl)
{
b_app1(pp);
b_app(indent);indent_force;
b_app1(pp+1);
b_app(outdent);b_app(outdent);
REDUCE(pp,2,fn_decl,0,70);
}
else if(cat1==stmt)
{
#if(0)
b_app(backup);
#endif
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);
b_app(outdent);
in_function= kill_nl= NO;
REDUCE(pp,2,functn,-1,71);
}
}

/* :142 */
#line 1930 "./prod.web"

#endif

/* :140 */
#line 623 "./prod.web"
break;
case functn:/* 143: */
#line 1974 "./prod.web"

#if FCN_CALLS
C_functn();
#else
/* 145: */
#line 1992 "./prod.web"

{
if(cat1==functn||cat1==decl||cat1==stmt)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,80);
}
}

/* :145 */
#line 1978 "./prod.web"

#endif

/* :143 */
#line 624 "./prod.web"
break;
case lbrace:/* 179: */
#line 2482 "./prod.web"

#if FCN_CALLS
C_lbrace();
#else
/* 181: */
#line 2499 "./prod.web"

{
if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2503 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,stmt,-1,130);
}
else if((cat1==stmt||cat1==decl||cat1==functn)&&cat2==rbrace)

{
b_app(force);
b_app1(pp);

/* 182: */
#line 2528 "./prod.web"

{
/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2530 "./prod.web"


b_app1(pp+1);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2534 "./prod.web"


kill_nl= NO;
}

/* :182 */
#line 2512 "./prod.web"


b_app1(pp+2);

REDUCE(pp,3,stmt,-1,131);
}
else if(cat1==expr)
{
if(cat2==rbrace)
SQUASH(pp,3,expr,-2,132);
else if(cat2==comma&&cat3==rbrace)
SQUASH(pp,4,expr,-2,132);
}
}

/* :181 */
#line 2486 "./prod.web"

#endif

/* :179 */
#line 625 "./prod.web"
break;
case do_like:/* 200: */
#line 2708 "./prod.web"

#if FCN_CALLS
C_do_like();
#else
/* 202: */
#line 2725 "./prod.web"

{
if(cat1==stmt)
if(cat2==for_like)
{
cat2= while_do;
SQUASH(pp,1,do_like,PLUS 2,191);
}
else if(cat2==expr&&cat3==semi)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
b_app(force);
b_app2(pp+2);
REDUCE(pp,4,stmt,-1,190);
}
}

/* :202 */
#line 2712 "./prod.web"

#endif

/* :200 */
#line 626 "./prod.web"
break;
case while_do:/* 203: */
#line 2746 "./prod.web"

#if FCN_CALLS
C_wh_do();
#else
/* 205: */
#line 2763 "./prod.web"

{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2766 "./prod.web"
;
REDUCE(pp,1,expr,0,192);
}

/* :205 */
#line 2750 "./prod.web"

#endif

/* :203 */
#line 627 "./prod.web"
break;
case if_like:/* 212: */
#line 2852 "./prod.web"

#if FCN_CALLS
C_if_like();
#else
/* 214: */
#line 2869 "./prod.web"

{
if(cat1==lpar&&cat2==expr&&cat3==rpar)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2873 "./prod.web"
;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);
#endif
REDUCE(pp,4,IF_like,0,220);
}
}

/* :214 */
#line 2856 "./prod.web"

#endif

/* :212 */
#line 628 "./prod.web"
break;
case IF_like:/* 216: */
#line 2894 "./prod.web"

#if FCN_CALLS
C_IF();
#else
/* 218: */
#line 2911 "./prod.web"

{
if(cat1==stmt
||cat1==lbrace||cat1==if_like||cat1==for_like||cat1==do_like
||cat1==Rdo_like
#if(0)
||cmnt_after_IF
#endif
)
SQUASH(pp,1,if_hd,0,230);
#if(0)
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,231);
}
#endif
}

/* :218 */
#line 2898 "./prod.web"

#endif

/* :216 */
#line 629 "./prod.web"
break;
case IF_top:/* 231: */
#line 3050 "./prod.web"

#if FCN_CALLS
C_IF_top();
#else
/* 233: */
#line 3067 "./prod.web"

{
if(cat1==else_like||cat1==else_hd||cat1==space)
SQUASH(pp,1,IF_top,1,242);
else if(cat1==IF_top)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,238);
}
else if(cat1==ELSE_like)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,239);
}
else if(cat1==IF_like&&(cat2==expr||cat2==stmt))
SQUASH(pp,1,IF_top,1,241);
else
SQUASH(pp,1,stmt,-1,240);
}

/* :233 */
#line 3054 "./prod.web"

#endif

/* :231 */
#line 630 "./prod.web"
break;
case for_like:/* 206: */
#line 2774 "./prod.web"

#if FCN_CALLS
C_for_like();
#else
/* 208: */
#line 2791 "./prod.web"

{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2795 "./prod.web"
;b_app1(pp+1);
b_app(' ');

if(cat2==semi)
{
if(!auto_semi||(auto_semi&&cat3==semi))
{
indent_force;
b_app1(pp+2);
b_app(outdent);
REDUCE(pp,3,stmt,-2,200);

}
else
REDUCE(pp,3,for_hd,0,2011);
}
else
REDUCE(pp,2,for_hd,0,201);
}
else if(cat1!=lpar)
SQUASH(pp,1,expr,0,2010);
}

/* :208 */
#line 2778 "./prod.web"

#endif

/* :206 */
#line 631 "./prod.web"
break;
case for_hd:/* 209: */
#line 2819 "./prod.web"

#if FCN_CALLS
C_forhd();
#else
/* 211: */
#line 2836 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-1,210);
}
}

/* :211 */
#line 2823 "./prod.web"

#endif

/* :209 */
#line 632 "./prod.web"
break;
case else_like:/* 225: */
#line 2994 "./prod.web"

#if FCN_CALLS
C_else();
#else
/* 227: */
#line 3011 "./prod.web"

{
if(cat1==if_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);
#if 0 
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}

/* :227 */
#line 2998 "./prod.web"

#endif

/* :225 */
#line 633 "./prod.web"
break;
/* :62 */
/* 62: */
#line 637 "./prod.web"
case if_hd:/* 219: */
#line 2932 "./prod.web"

#if FCN_CALLS
C_if_hd();
#else
/* 221: */
#line 2949 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}

/* :221 */
#line 2936 "./prod.web"

#endif

/* :219 */
#line 637 "./prod.web"
break;
case else_hd:/* 222: */
#line 2964 "./prod.web"

#if FCN_CALLS
C_els_hd();
#else
/* 224: */
#line 2981 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,ELSE_like,-1,241);
}
}

/* :224 */
#line 2968 "./prod.web"

#endif

/* :222 */
#line 638 "./prod.web"
break;
case case_like:/* 237: */
#line 3130 "./prod.web"

#if FCN_CALLS
C_case_like();
#else
/* 239: */
#line 3147 "./prod.web"

{
if(cat1==semi)
SQUASH(pp,2,stmt,-1,260);
else if(cat1==colon)
SQUASH(pp,2,tag,-1,261);
else if(cat1==expr)
{
if(cat2==semi)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,stmt,-1,262);
}
else if(cat2==colon)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,tag,-1,263);
}
}
else if(cat1==int_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,int_like,-2,264);
}
}

/* :239 */
#line 3134 "./prod.web"

#endif

/* :237 */
#line 639 "./prod.web"
break;
case stmt:/* 234: */
#line 3092 "./prod.web"

#if FCN_CALLS
C_stmt();
#else
/* 236: */
#line 3109 "./prod.web"

{
if(cat1==stmt||(Cpp&&cat1==decl))
{
b_app1(pp);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 3115 "./prod.web"


b_app1(pp+1);

REDUCE(pp,2,stmt,-1,250);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,251);
}
}

/* :236 */
#line 3096 "./prod.web"

#endif

/* :234 */
#line 640 "./prod.web"
break;
case tag:/* 240: */
#line 3174 "./prod.web"

#if FCN_CALLS
C_tag();
#else
/* 242: */
#line 3191 "./prod.web"

{
if(cat1==tag)
{
b_app1(pp);
b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==decl||cat1==functn)

{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,271);
}
}

/* :242 */
#line 3178 "./prod.web"

#endif

/* :240 */
#line 641 "./prod.web"
break;
case semi:/* 243: */
#line 3211 "./prod.web"

#if FCN_CALLS
C_semi();
#else
/* 245: */
#line 3228 "./prod.web"

{
b_app(' ');b_app1(pp);
REDUCE(pp,1,stmt,-1,280);
}

/* :245 */
#line 3215 "./prod.web"

#endif

/* :243 */
#line 642 "./prod.web"
break;
case lproc:/* 101: */
#line 1253 "./prod.web"

#if FCN_CALLS
C_lproc();
#else
/* 104: */
#line 1277 "./prod.web"

{
expanded_lproc= YES;

if(!in_LPROC)
active_space= YES;

if(cat1==define_like)
make_underlined(pp+3);

if(cat1==else_like||cat1==if_like||cat1==define_like)
SQUASH(pp,2,lproc,0,10);

else if(cat1==rproc)
{
expanded_lproc= active_space= in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,11);
}
else if(cat1==expr)
#if 0
SQUASH(pp,1,LPROC,0,12);
#endif
{
b_app1(pp);b_app(' ');b_app1(pp+1);

if(cat2==lpar)
did_arg= NO;
else
{
b_app(' ');
did_arg= YES;
}

REDUCE(pp,2,LPROC,0,12);
}
else if(cat1==space)
{
if(cat2==lpar)
SQUASH(pp,1,lproc,PLUS 2,1332);


else if(cat3==lpar)
SQUASH(pp,1,lproc,PLUS 3,1333);
else if(cat3==expr)
SQUASH(pp,4,LPROC,0,13);

else if(cat3==space||cat3==ignore_scrap||cat3==rproc)
SQUASH(pp,3,LPROC,0,14);
}
expanded_lproc= NO;
}

/* :104 */
#line 1257 "./prod.web"

#endif

/* :101 */
#line 643 "./prod.web"
break;
case LPROC:/* 105: */
#line 1330 "./prod.web"

#if FCN_CALLS
C_LPRC();
#else
/* 107: */
#line 1347 "./prod.web"

{
active_space= NO;in_LPROC= YES;

if(cat1==space)
{
b_app1(pp);
b_app(' ');
REDUCE(pp,2,LPROC,0,20);
}
else if(!did_arg&&cat1==expr)
{
SQUASH(pp,2,LPROC,0,24);
did_arg= YES;
}
else if(cat1==rproc)
{
in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,21);
}
else if(cat2==rproc)
{
in_LPROC= NO;
SQUASH(pp,3,ignore_scrap,-1,22);
}

#if(0)
if(cat3==lpar&&cat4==expr&&cat5==rpar)
if(cat2==rproc)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,ignore_scrap,-1,53);
}
else if(cat2==expr&&cat3==rproc)
{
b_app1(pp);b_app(' ');b_app1(pp+1);b_app(' ');
b_app2(pp+2);REDUCE(pp,4,ignore_scrap,-1,53);
}
#endif
}

/* :107 */
#line 1334 "./prod.web"

#endif

/* :105 */
#line 644 "./prod.web"
break;
case space:/* 108: */
#line 1389 "./prod.web"

#if FCN_CALLS
C_space();
#else
/* 110: */
#line 1406 "./prod.web"

{
if(active_space)
{
if(expanded_lproc)
SQUASH(pp,1,space,-1,5336);
else
SQUASH(pp,1,space,1,5335);
}
else
REDUCE(pp,1,ignore_scrap,-1,5334);
}

/* :110 */
#line 1393 "./prod.web"

#endif

/* :108 */
#line 645 "./prod.web"
break;

case template:/* 246: */
#line 3235 "./prod.web"

#if FCN_CALLS
C_template();
#else
/* 248: */
#line 3252 "./prod.web"

{
if(cat1==langle)
SQUASH(pp,1,template,PLUS 1,6000);
else if(cat1==tlist)
{
b_app1(pp);b_app(' ');b_app1(pp+1);b_app(force);
REDUCE(pp,2,int_like,0,6001);
}
}

/* :248 */
#line 3239 "./prod.web"

#endif

/* :246 */
#line 647 "./prod.web"
break;
case langle:/* 249: */
#line 3264 "./prod.web"

#if FCN_CALLS
C_langle();
#else
/* 251: */
#line 3282 "./prod.web"

{
if((pp-1)->cat==template||(pp-1)->cat==int_like||(pp-1)->cat==
struct_like)
{
b_app('\\');
APP_STR("WLA ");
REDUCE(pp,1,tstart,0,6050);
}
else if(cat1==decl_hd&&cat2==rangle)
{
b_app('\\');
APP_STR("WLA ");
b_app1(pp+1);
b_app('\\');
APP_STR("WRA ");
REDUCE(pp,3,expr,-1,6053);
}
else if(cat1==int_like)
SQUASH(pp,1,langle,PLUS 1,6054);
else
SQUASH(pp,1,binop,-1,6051);
}

/* :251 */
#line 3268 "./prod.web"

#endif

/* :249 */
#line 648 "./prod.web"
break;
case rangle:/* 252: */
#line 3307 "./prod.web"

#if FCN_CALLS
C_rangle();
#else
/* 254: */
#line 3325 "./prod.web"

{
if((pp-1)->cat==decl_hd)
SQUASH(pp,1,rangle,-2,6055);
else
SQUASH(pp,1,binop,-1,6052);
}

/* :254 */
#line 3311 "./prod.web"

#endif

/* :252 */
#line 649 "./prod.web"
break;
case tstart:/* 255: */
#line 3334 "./prod.web"

#if FCN_CALLS
C_tstart();
#else
/* 257: */
#line 3351 "./prod.web"

{
if(cat2==rangle&&(cat1==int_like||cat1==decl_hd||cat1==expr
||cat1==unorbinop))
{
b_app2(pp);
b_app('\\');
APP_STR("WRA ");
OUTDENT;
REDUCE(pp,3,tlist,-1,6060);
}
}

/* :257 */
#line 3338 "./prod.web"

#endif

/* :255 */
#line 650 "./prod.web"
break;
case tlist:/* 258: */
#line 3365 "./prod.web"

#if FCN_CALLS
C_tlist();
#else
/* 260: */
#line 3382 "./prod.web"


/* :260 */
#line 3369 "./prod.web"

#endif

/* :258 */
#line 651 "./prod.web"
break;

case virtual:/* 126: */
#line 1642 "./prod.web"

#if FCN_CALLS
C_virtual();
#else
/* 128: */
#line 1659 "./prod.web"

{
b_app1(pp);

if(cat1==unop)
APP_SPACE;

REDUCE(pp,1,int_like,0,506);
}

/* :128 */
#line 1646 "./prod.web"

#endif

/* :126 */
#line 653 "./prod.web"
break;
case reference:/* 129: */
#line 1670 "./prod.web"

#if FCN_CALLS
C_reference();
#else
/* 131: */
#line 1688 "./prod.web"

{
SQUASH(pp,1,unorbinop,-1,507);
}

/* :131 */
#line 1674 "./prod.web"

#endif

/* :129 */
#line 654 "./prod.web"
break;
case namespace:/* 261: */
#line 3385 "./prod.web"

#if FCN_CALLS
C_namespace();
#else
/* 263: */
#line 3402 "./prod.web"

{
if(cat1==expr||cat1==int_like)
{
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(' ');b_app1(pp+1);

REDUCE(pp,2,fn_decl,0,7901);
}
else if(cat1==lbrace)
SQUASH(pp,1,fn_decl,0,7902);
}

/* :263 */
#line 3389 "./prod.web"

#endif

/* :261 */
#line 655 "./prod.web"
break;

case kill_newlines:/* 174: */
#line 2442 "./prod.web"

#if FCN_CALLS
C_killnl();
#else
/* 178: */
#line 2475 "./prod.web"

{
kill_nl= YES;
SQUASH(pp,1,lbrace,-2,8888);
}

/* :178 */
#line 2446 "./prod.web"

#endif

/* :174 */
#line 657 "./prod.web"
break;
}
}

/* :62 */
/* 63: */
#line 674 "./prod.web"


SRTN
make_reserved FCN((p))

scrap_pointer p C1("")
{
sixteen_bits tok_value= first_id(p->trans);

name_pointer pname= name_dir+tok_value-id_flag;

if(!tok_value||tok_value=='(')
return;

if(DEFINED_TYPE(pname)==M_MACRO||DEFINED_TYPE(pname)==D_MACRO)
return;


for(;p<=scrp_ptr;p++)
{
if(p->cat==expr)
{
if(**(p->trans)==tok_value)
{
p->cat= int_like;
**(p->trans)+= res_flag-id_flag;
}
}
}

pname->ilk= int_like;
pname->reserved_word|= (boolean)language;

if(mark_defined.typedef_name)
{
pname->defined_in(language)= module_count;
SET_TYPE(pname,TYPEDEF_NAME);
}
}

/* :63 */
/* 65: */
#line 729 "./prod.web"


sixteen_bits
first_id FCN((t))
text_pointer t C1("Pointer to start of token list")
{
token_pointer pk= *t;
token_pointer pk1= *(t+1);
sixteen_bits tok_value;

for(;pk<pk1;pk++)
{
tok_value= *pk;

if(tok_value>inner_tok_flag)tok_value-= (inner_tok_flag-
tok_flag);

if(tok_value<=tok_flag)
{
if(tok_value>=id_flag&&tok_value<res_flag)
return tok_value;
else if(tok_value=='(')return tok_value;
}
else
{
t= tok_start+(int)(tok_value-tok_flag);

tok_value= first_id(t);
if(tok_value)return tok_value;
}
}

return 0;
}

/* :65 */
/* 66: */
#line 773 "./prod.web"


name_pointer
make_underlined FCN((p))

scrap_pointer p C1("")
{
sixteen_bits tok_value;

tok_value= **(p->trans);

if(tok_value>inner_tok_flag)tok_value-= (inner_tok_flag-tok_flag);

if(tok_value>tok_flag){
do
{

tok_value= **(tok_start+
(int)(tok_value-tok_flag));

}
while(tok_value>tok_flag);

if(tok_value<id_flag||tok_value>=res_flag)return NULL;


xref_switch= def_flag;underline_xref(tok_value-id_flag+name_dir);
}

if(tok_value<id_flag||tok_value>=res_flag)return NULL;


xref_switch= def_flag;return underline_xref(tok_value-id_flag+name_dir);
}

/* :66 */
/* 67: */
#line 813 "./prod.web"


name_pointer
underline_xref FCN((p))
name_pointer p C1("")
{
xref_pointer q= (xref_pointer)p->xref;

xref_pointer r;
sixteen_bits m;
sixteen_bits n;
extern boolean strt_off;

if(no_xref||(strt_off&&!index_hidden))
return p;

xref_switch= def_flag;
m= (sixteen_bits)(module_count+xref_switch);

while(q!=xmem)
{
n= q->num;

if(n==m)return p;
else if(m==n+def_flag)

{
q->num= m;return p;
}
else if(n>=def_flag&&n<m)break;

q= q->xlink;
}

/* 70: */
#line 901 "./prod.web"


append_xref(0);
xref_ptr->xlink= (xref_pointer)p->xref;
r= xref_ptr;p->xref= (ASCII*)xref_ptr;

while(r->xlink!=q){r->num= r->xlink->num;r= r->xlink;}

r->num= m;

/* :70 */
#line 847 "./prod.web"
;

return p;
}

/* :67 */
/* 69: */
#line 860 "./prod.web"


SRTN
defined_at FCN((p))
name_pointer p C1("")
{
extern boolean ok_to_define;

if(ok_to_define&&translate_mode==OUTER&&p>name_dir)
{
sixteen_bits mod_defined= p->defined_in(language);

if(mod_defined&&mod_defined!=module_count&&language!=C_PLUS_PLUS)
{
if(msg_level>=WARNINGS)
{
printf("\n! (FWEAVE):  Implicit phase 2 declaration of `");
prn_id(p);
printf("' at %s \
repeats or conflicts with declaration at %s.\n",
(char*)MOD_TRANS(module_count),
(char*)MOD_TRANS(mod_defined));
mfree();
}
mark_harmless;
}
else if(mark_defined.fcn_name)
{
p->defined_in(language)= module_count;
SET_TYPE(p,FUNCTION_NAME);
}
}
}

/* :69 */
/* 72: */
#line 937 "./prod.web"


#if FCN_CALLS
SRTN C_ignore_scrap(VOID)
{
/* 73: */
#line 947 "./prod.web"

{
switch(cat1)
{
case stmt:
case functn:
SQUASH(pp,2,cat1,0,1);
break;
}
}

/* :73 */
#line 942 "./prod.web"

}
#endif

/* :72 */
/* 75: */
#line 967 "./prod.web"

#if FCN_CALLS
SRTN C_expr(VOID)
{
/* 76: */
#line 979 "./prod.web"

{
if(cat1==lbrace||((!Cpp)&&cat1==int_like))
{
defined_at(make_underlined(pp));

in_function= YES;
SQUASH(pp,1,fn_decl,0,111);
}
else if(cat1==unop)
SQUASH(pp,2,expr,-2,2);
else if(cat1==binop)
{
if(cat2==expr)
SQUASH(pp,3,expr,-2,3);
else if(cat2==decl_hd)
SQUASH(pp,3,tstart,0,6061);

}
else if(cat1==unorbinop&&cat2==expr)
{
sixteen_bits*s= *(pp+1)->trans;
b_app1(pp);



if((s[0]==(sixteen_bits)'\\')&&s[1]==(sixteen_bits)'a'
&&s[2]==(sixteen_bits)'m')
{
APP_SPACE;b_app1(pp+1);APP_SPACE;
}
else b_app1(pp+1);

b_app1(pp+2);
REDUCE(pp,3,expr,-2,3000);
}
else if(cat1==comma)
{
if((cat2==expr||cat2==int_like))
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,cat2,-2,4);
}
else if(cat2==space)
SQUASH(pp,3,expr,-2,88);
}
else if(cat1==expr)
SQUASH(pp,2,expr,-2,5);
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,6);
else if(cat1==colon)
{
if(!Cpp||in_function)
{
make_underlined(pp);
SQUASH(pp,2,tag,0,7);
}
else if(cat2==expr||cat2==int_like)
{

b_app1(pp);b_app(' ');b_app1(pp+1);b_app(' ');
b_app1(pp+2);
REDUCE(pp,3,expr,-2,701);

}
}
else if(cat1==space)
SQUASH(pp,2,expr,-2,8);
}

/* :76 */
#line 971 "./prod.web"

}
#endif

/* :75 */
/* 79: */
#line 1066 "./prod.web"

#if FCN_CALLS
SRTN C_UNOP(VOID)
{
/* 80: */
#line 1075 "./prod.web"

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,unop,-1,4443);
}

/* :80 */
#line 1070 "./prod.web"

}
#endif

/* :79 */
/* 82: */
#line 1090 "./prod.web"

#if FCN_CALLS
SRTN C_BINOP(VOID)
{
/* 83: */
#line 1099 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1101 "./prod.web"
;
REDUCE(pp,1,binop,-1,4444);
}

/* :83 */
#line 1094 "./prod.web"

}
#endif

/* :82 */
/* 85: */
#line 1114 "./prod.web"

#if FCN_CALLS
SRTN C_COMMA(VOID)
{
/* 86: */
#line 1123 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1125 "./prod.web"
;
REDUCE(pp,1,comma,-1,4445);
}

/* :86 */
#line 1118 "./prod.web"

}
#endif

/* :85 */
/* 88: */
#line 1138 "./prod.web"

#if FCN_CALLS
SRTN C__E(VOID)
{
/* 89: */
#line 1147 "./prod.web"

{
APP_SPACE;b_app1(pp);
REDUCE(pp,1,expr,-2,4446);
}

/* :89 */
#line 1142 "./prod.web"

}
#endif

/* :88 */
/* 91: */
#line 1162 "./prod.web"

#if FCN_CALLS
SRTN C__E_(VOID)
{
/* 92: */
#line 1171 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1173 "./prod.web"
;
REDUCE(pp,1,expr,-2,4447);
}

/* :92 */
#line 1166 "./prod.web"

}
#endif

/* :91 */
/* 94: */
#line 1186 "./prod.web"

#if FCN_CALLS
SRTN C_E_(VOID)
{
/* 95: */
#line 1195 "./prod.web"

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,expr,-2,4448);
}

/* :95 */
#line 1190 "./prod.web"

}
#endif

/* :94 */
/* 99: */
#line 1223 "./prod.web"

#if FCN_CALLS
SRTN C_new_like(VOID)
{
/* 100: */
#line 1232 "./prod.web"

{
if(cat1==lbracket&&cat2==rbracket)
{
b_app1(pp);b_app(' ');b_app1(pp+1);/* 325: */
#line 4334 "./prod.web"

{
b_app('\\');b_app(';');
}

/* :325 */
#line 1236 "./prod.web"
;b_app1(pp+2);
b_app(' ');
REDUCE(pp,3,expr,-2,910);
}
else if(cat1==decl_hd||cat1==expr)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
if(cat1==decl_hd)
{
OUTDENT;
}
REDUCE(pp,2,expr,-2,909);
}
}

/* :100 */
#line 1227 "./prod.web"

}
#endif

/* :99 */
/* 102: */
#line 1261 "./prod.web"

#if FCN_CALLS
SRTN C_lproc(VOID)
{
/* 104: */
#line 1277 "./prod.web"

{
expanded_lproc= YES;

if(!in_LPROC)
active_space= YES;

if(cat1==define_like)
make_underlined(pp+3);

if(cat1==else_like||cat1==if_like||cat1==define_like)
SQUASH(pp,2,lproc,0,10);

else if(cat1==rproc)
{
expanded_lproc= active_space= in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,11);
}
else if(cat1==expr)
#if 0
SQUASH(pp,1,LPROC,0,12);
#endif
{
b_app1(pp);b_app(' ');b_app1(pp+1);

if(cat2==lpar)
did_arg= NO;
else
{
b_app(' ');
did_arg= YES;
}

REDUCE(pp,2,LPROC,0,12);
}
else if(cat1==space)
{
if(cat2==lpar)
SQUASH(pp,1,lproc,PLUS 2,1332);


else if(cat3==lpar)
SQUASH(pp,1,lproc,PLUS 3,1333);
else if(cat3==expr)
SQUASH(pp,4,LPROC,0,13);

else if(cat3==space||cat3==ignore_scrap||cat3==rproc)
SQUASH(pp,3,LPROC,0,14);
}
expanded_lproc= NO;
}

/* :104 */
#line 1265 "./prod.web"

}
#endif

/* :102 */
/* 106: */
#line 1338 "./prod.web"

#if FCN_CALLS
SRTN C_LPRC(VOID)
{
/* 107: */
#line 1347 "./prod.web"

{
active_space= NO;in_LPROC= YES;

if(cat1==space)
{
b_app1(pp);
b_app(' ');
REDUCE(pp,2,LPROC,0,20);
}
else if(!did_arg&&cat1==expr)
{
SQUASH(pp,2,LPROC,0,24);
did_arg= YES;
}
else if(cat1==rproc)
{
in_LPROC= NO;
SQUASH(pp,2,ignore_scrap,-1,21);
}
else if(cat2==rproc)
{
in_LPROC= NO;
SQUASH(pp,3,ignore_scrap,-1,22);
}

#if(0)
if(cat3==lpar&&cat4==expr&&cat5==rpar)
if(cat2==rproc)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,ignore_scrap,-1,53);
}
else if(cat2==expr&&cat3==rproc)
{
b_app1(pp);b_app(' ');b_app1(pp+1);b_app(' ');
b_app2(pp+2);REDUCE(pp,4,ignore_scrap,-1,53);
}
#endif
}

/* :107 */
#line 1342 "./prod.web"

}
#endif

/* :106 */
/* 109: */
#line 1397 "./prod.web"

#if FCN_CALLS
SRTN C_space(VOID)
{
/* 110: */
#line 1406 "./prod.web"

{
if(active_space)
{
if(expanded_lproc)
SQUASH(pp,1,space,-1,5336);
else
SQUASH(pp,1,space,1,5335);
}
else
REDUCE(pp,1,ignore_scrap,-1,5334);
}

/* :110 */
#line 1401 "./prod.web"

}
#endif

/* :109 */
/* 112: */
#line 1428 "./prod.web"

#if FCN_CALLS
SRTN C_question(VOID)
{
/* 113: */
#line 1437 "./prod.web"

{
if(cat1==expr&&cat2==colon)SQUASH(pp,3,binop,-2,30);

}

/* :113 */
#line 1432 "./prod.web"

}
#endif

/* :112 */
/* 115: */
#line 1452 "./prod.web"

#if FCN_CALLS
SRTN C_int_like(VOID)
{
/* 116: */
#line 1461 "./prod.web"

{
if(cat1==unop)
{
if(cat2==expr||cat2==int_like)
SQUASH(pp,3,expr,-2,35);

else if(cat2==op_like)
SQUASH(pp,1,int_like,PLUS 2,36);

}
else if(cat1==int_like||cat1==struct_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,cat1,0,40);
}
else if(cat1==reference)
SQUASH(pp,2,int_like,-2,43);
else if(cat1==expr||cat1==unorbinop||cat1==semi)
{
b_app1(pp);

if(cat1!=semi)
app('~');

#if 0
INDENT;

#endif

REDUCE(pp,1,decl_hd,-1,41);
}
else if(cat1==comma)
{
b_app1(pp);
#if 0
INDENT;
#endif
REDUCE(pp,1,decl_hd,-2,42);
}
else if(cat1==rpar)
{
b_app1(pp);
#if 0
INDENT;
#endif
REDUCE(pp,1,decl_hd,-2,502);
}
else if(Cpp&&cat1==lpar&&!in_prototype)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 1512 "./prod.web"

REDUCE(pp,1,expr,-2,5021);

}
else if(cat1==binop&&cat2==expr)
SQUASH(pp,3,int_like,-2,5022);
else if(cat1==langle)
SQUASH(pp,1,int_like,PLUS 1,5997);
else if(cat1==rangle)
{
b_app1(pp);
#if 0
INDENT;
#endif
REDUCE(pp,1,decl_hd,-2,5998);
}
else if(cat1==class_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,class_like,0,5995);
}
else if(cat1==tlist)
SQUASH(pp,2,int_like,-2,5999);
else if(cat1==namespace)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,namespace,0,5996);
}
}

/* :116 */
#line 1456 "./prod.web"

}
#endif

/* :115 */
/* 118: */
#line 1553 "./prod.web"

#if FCN_CALLS
SRTN C_ext_like(VOID)
{
/* 119: */
#line 1562 "./prod.web"

{
if(Cpp&&cat1==expr)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
if(cat2==lbrace||cat2==kill_newlines)
REDUCE(pp,2,fn_decl,0,5025);
else
REDUCE(pp,2,int_like,0,5023);

}
else
SQUASH(pp,1,int_like,0,5024);
}

/* :119 */
#line 1557 "./prod.web"

}
#endif

/* :118 */
/* 121: */
#line 1590 "./prod.web"

#if FCN_CALLS
SRTN C_modifier(VOID)
{
/* 122: */
#line 1599 "./prod.web"

{
if(cat1==int_like||cat1==struct_like||cat1==class_like)
SQUASH(pp,1,cat1,-2,503);
else if(pp==lo_ptr)
SQUASH(pp,1,expr,0,5040);
else if(cat1==comma||cat1==semi||cat1==lbrace||cat1==kill_newlines)
SQUASH(pp,1,_EXPR,0,5042);


else
SQUASH(pp,1,EXPR_,0,5041);
}

/* :122 */
#line 1594 "./prod.web"

}
#endif

/* :121 */
/* 124: */
#line 1623 "./prod.web"

#if FCN_CALLS
SRTN C_huge_like(VOID)
{
/* 125: */
#line 1632 "./prod.web"

{
if(cat1==unorbinop)
{
b_app1(pp);APP_SPACE;b_app1(pp+1);
REDUCE(pp,2,unorbinop,-1,505);
}
}

/* :125 */
#line 1627 "./prod.web"

}
#endif

/* :124 */
/* 127: */
#line 1650 "./prod.web"

#if FCN_CALLS
SRTN C_virtual(VOID)
{
/* 128: */
#line 1659 "./prod.web"

{
b_app1(pp);

if(cat1==unop)
APP_SPACE;

REDUCE(pp,1,int_like,0,506);
}

/* :128 */
#line 1654 "./prod.web"

}
#endif

/* :127 */
/* 130: */
#line 1678 "./prod.web"

#if FCN_CALLS
SRTN C_reference(VOID)
{
/* 131: */
#line 1688 "./prod.web"

{
SQUASH(pp,1,unorbinop,-1,507);
}

/* :131 */
#line 1682 "./prod.web"

}
#endif

/* :130 */
/* 135: */
#line 1731 "./prod.web"

#if FCN_CALLS
SRTN C_decl_hd(VOID)
{
/* 136: */
#line 1740 "./prod.web"

{
if(cat1==rpar)
{
if((pp-1)->cat==lpar)
SQUASH(pp,1,decl_hd,-1,4990);
else if((pp-2)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-2,4991);
else if((pp-3)->cat==decl_hd)
SQUASH(pp,1,decl_hd,-3,4992);
}
else if(cat1==decl_hd)
SQUASH(pp,2,decl_hd,0,50);
else if(cat1==comma)
{
if(cat2==decl_hd)
{
b_app2(pp);OPT9;
b_app1(pp+2);
REDUCE(pp,3,decl_hd,0,501);
}
else if(cat2==ignore_scrap&&cat3==decl_hd)
{
b_app2(pp);OPT9;
b_app2(pp+2);
REDUCE(pp,4,decl_hd,0,504);
}
#if 0
else if(Cpp&&(cat2==decl||cat2==stmt))
SQUASH(pp,3,stmt,-2,508);


#endif
else
{
if(cat2==ignore_scrap&&(cat3==int_like||cat3==struct_like||
cat3==modifier))
{
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat3!=modifier)
in_prototype++;
REDUCE(pp,1,decl_hd,PLUS 3,5221);
}
else if(cat2==int_like||cat2==struct_like||cat2==modifier)
{
b_app1(pp);
if((pp-3)->cat!=decl_hd&&(pp-2)->cat!=decl_hd
&&cat2!=modifier)
in_prototype++;


REDUCE(pp,1,decl_hd,PLUS 2,52);
}
else
{
b_app2(pp);app('~');

#if 0
if(Cpp)
REDUCE(pp,2,decl_hd,-2,540);

else
#endif
REDUCE(pp,2,decl_hd,-1,54);
}
}
}
else if(cat1==unorbinop)
{
b_app1(pp);
b_app('{');
b_app1(pp+1);
b_app('}');
REDUCE(pp,2,decl_hd,-1,55);
}
else if(cat1==expr)
{
make_underlined(pp+1);
SQUASH(pp,2,decl_hd,-1,56);

}
else if((cat1==binop||cat1==colon
||cat1==expr
)&&cat2==expr&&(cat3==comma||cat3==semi||cat3==rpar))
#if 0
if(cat1==binop)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,decl_hd,-1,5660);
}
else
#endif
SQUASH(pp,3,decl_hd,-1,5661);
else if(cat1==int_like&&(cat2==unop||cat2==langle))
SQUASH(pp,1,decl_hd,PLUS 1,5662);


else if(cat1==lbrace||(cat1==int_like&&
((pp-1)->trans==NULL||**(pp-1)->trans!='(')))


{
b_app1(pp);
#if 0
OUTDENT;
#endif
in_function= YES;
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi)
{
b_app2(pp);
#if 0
OUTDENT;
#endif
#if 0
if(Cpp)
REDUCE(pp,2,decl,-2,594);

else
#endif
REDUCE(pp,2,decl,-1,59);
}
else if(Cpp&&cat1==int_like&&cat2==unop)
SQUASH(pp,1,decl_hd,PLUS 1,590);
else if(Cpp&&cat1==rangle)
SQUASH(pp,1,decl_hd,-2,591);
else if(Cpp&&cat1==struct_like)
SQUASH(pp,2,decl_hd,-1,593);

}

/* :136 */
#line 1735 "./prod.web"

}
#endif

/* :135 */
/* 138: */
#line 1885 "./prod.web"

#if FCN_CALLS
SRTN C_decl(VOID)
{
/* 139: */
#line 1894 "./prod.web"

{
if(Cpp)
{
if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,61);
}
else
SQUASH(pp,1,stmt,-1,611);
}
else
{
if(cat1==decl)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,61);
}
}
}

/* :139 */
#line 1889 "./prod.web"

}
#endif

/* :138 */
/* 141: */
#line 1934 "./prod.web"

#if FCN_CALLS
SRTN C_fn_decl(VOID)
{
/* 142: */
#line 1943 "./prod.web"

{
if(cat1==semi&&Cpp)
{
b_app2(pp);
REDUCE(pp,2,stmt,-1,72);
}
else if(cat1==decl)
{
b_app1(pp);
b_app(indent);indent_force;
b_app1(pp+1);
b_app(outdent);b_app(outdent);
REDUCE(pp,2,fn_decl,0,70);
}
else if(cat1==stmt)
{
#if(0)
b_app(backup);
#endif
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);
b_app(outdent);
in_function= kill_nl= NO;
REDUCE(pp,2,functn,-1,71);
}
}

/* :142 */
#line 1938 "./prod.web"

}
#endif

/* :141 */
/* 144: */
#line 1982 "./prod.web"

#if FCN_CALLS
SRTN C_functn(VOID)
{
/* 145: */
#line 1992 "./prod.web"

{
if(cat1==functn||cat1==decl||cat1==stmt)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,80);
}
}

/* :145 */
#line 1986 "./prod.web"

}
#endif

/* :144 */
/* 147: */
#line 2011 "./prod.web"

#if FCN_CALLS
SRTN C_typedef_like(VOID)
{
/* 149: */
#line 2025 "./prod.web"

{
if(cat1==decl_hd&&(cat2==expr||cat2==int_like))
{
make_underlined(pp+2);make_reserved(pp+2);
b_app2(pp+1);
REDUCE(pp+1,2,decl_hd,0,90);
}
else if(cat1==decl)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,decl,-1,91);
}
else if(cat1==semi)
SQUASH(pp,2,stmt,-1,94);

else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,stmt,-1,95);

}

}

/* :149 */
#line 2015 "./prod.web"

}
#endif

/* :147 */
/* 151: */
#line 2059 "./prod.web"

#if FCN_CALLS
SRTN C_imp_reserved(VOID)
{
/* 152: */
#line 2070 "./prod.web"

{
if(typedefing)SQUASH(pp,1,expr,-2,92);
else SQUASH(pp,1,int_like,-2,93);
}

/* :152 */
#line 2063 "./prod.web"

}
#endif

/* :151 */
/* 154: */
#line 2090 "./prod.web"

#if FCN_CALLS
SRTN C_op_like(VOID)
{
/* 155: */
#line 2099 "./prod.web"

{
short n;


if((cat1==lpar&&cat2==rpar)||(cat1==lbracket&&cat2==rbracket))
{



APP_STR("\\Woperator");
b_app('{');
b_app1(pp+1);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2112 "./prod.web"

b_app1(pp+2);
b_app('}');
n= 3;
}
else
{

scrap_pointer q;
int k;



for(q= pp+1;q<=scrp_ptr&&q-pp<=MAX_OP_TOKENS;q++)
if(q->cat==lpar)
break;

n= (q->cat==lpar)?PTR_DIFF(short,q,pp):0;


if(n>0)
{
text_pointer xp;
token_pointer tp,tp1;

#if 0
b_app1(pp);
b_app('{');

#endif
APP_STR("\\Woperator");
b_app('{');

id_first= id_loc= mod_text+1;

for(k= 1;k<n;k++)
{
b_app1(pp+k);

xp= indirect((pp+k)->trans);
tp= *xp;
tp1= *(xp+1);
while(tp<tp1)
*id_loc++= (ASCII)(*tp++);
}

underline_xref(id_lookup(id_first,id_loc,0));

b_app('}');
}
}

if(n>0)
REDUCE(pp,n,expr,-2,6666);
else
{
APP_STR("\\Woperatoro");
REDUCE(pp,1,expr,-2,6668);
}
}

/* :155 */
#line 2094 "./prod.web"

}
#endif

/* :154 */
/* 157: */
#line 2184 "./prod.web"

#if FCN_CALLS
SRTN C_class_like(VOID)
{
/* 158: */
#line 2193 "./prod.web"

{
if(cat1==expr||cat1==int_like)
{
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(' ');b_app1(pp+1);

if((pp-1)->cat==tstart||(pp-1)->cat==decl_hd
||(pp-1)->cat==lpar)
REDUCE(pp,2,decl_hd,-1,8998);
else
REDUCE(pp,2,struct_like,0,8999);
}
else if(cat1==lbrace)
SQUASH(pp,1,struct_like,0,8987);

}

/* :158 */
#line 2188 "./prod.web"

}
#endif

/* :157 */
/* 160: */
#line 2222 "./prod.web"

#if FCN_CALLS
SRTN C_struct_like(VOID)
{
/* 161: */
#line 2234 "./prod.web"

{
if(cat1==lbrace)
{
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}
else if(cat1==expr)
{
if(cat2==lbrace)
{

if(Cpp)
{make_underlined(pp+1);make_reserved(pp+1);}

b_app1(pp);b_app(' ');b_app1(pp+1);
indent_force;
b_app1(pp+2);
REDUCE(pp,3,struct_hd,0,101);
}
else
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,int_like,-1,102);
}
}
else if(cat1==colon&&cat2==int_like&&Cpp)
{
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1023);
else
{
b_app1(pp);b_app(' ');b_app1(pp+1);b_app(' ');
b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1021);
}
}
else if(cat1==comma&&cat2==int_like&&Cpp)
{
if(cat3==langle)
SQUASH(pp,1,struct_like,PLUS 3,1024);
else
{
b_app2(pp);b_app(' ');b_app1(pp+2);
REDUCE(pp,3,struct_like,0,1022);
}
}
else if(cat1==tlist)
SQUASH(pp,2,struct_like,0,1025);
else if(cat1==semi)
SQUASH(pp,2,decl,-1,103);
else if(cat1==rangle)
SQUASH(pp,1,decl_hd,-2,592);
}

/* :161 */
#line 2226 "./prod.web"

}
#endif

/* :160 */
/* 163: */
#line 2298 "./prod.web"

#if FCN_CALLS
SRTN C_str_hd(VOID)
{
/* 164: */
#line 2307 "./prod.web"

{
if((cat1==decl||cat1==stmt
||cat1==expr
||cat1==functn
)&&cat2==rbrace)
{
b_app1(pp);
/* 182: */
#line 2528 "./prod.web"

{
/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2530 "./prod.web"


b_app1(pp+1);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2534 "./prod.web"


kill_nl= NO;
}

/* :182 */
#line 2315 "./prod.web"

b_app1(pp+2);
b_app(outdent);
/* :164 */
/* 164: */
#line 2321 "./prod.web"
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2325 "./prod.web"
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}

/* :164 */
#line 2302 "./prod.web"

}
#endif

/* :163 */
/* 166: */
#line 2340 "./prod.web"

#if FCN_CALLS
SRTN C_lpar(VOID)
{
/* 167: */
#line 2349 "./prod.web"

{
if(cat2==rpar&&(cat1==expr||cat1==unorbinop))
SQUASH(pp,3,expr,-2,120);
else if(cat1==rpar)
{

b_app1(pp);/* 325: */
#line 4334 "./prod.web"

{
b_app('\\');b_app(';');
}

/* :325 */
#line 2356 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if((cat1==decl_hd)&&cat2==rpar)
{

b_app3(pp);

OUTDENT;

if(in_prototype)
in_prototype--;

REDUCE(pp,3,cast,-1,122);
}
else if(cat1==stmt)
{
b_app2(pp);b_app(' ');REDUCE(pp,2,lpar,0,123);
}
else if(cat1==for_like&&cat2==rpar)
SQUASH(pp,3,expr,-2,1201);
}

/* :167 */
#line 2344 "./prod.web"

}
#endif

/* :166 */
/* 169: */
#line 2388 "./prod.web"

#if FCN_CALLS
SRTN C_lbracket(VOID)
{
/* 170: */
#line 2397 "./prod.web"

{
if(active_brackets)
{
b_app('\\');
APP_STR("WXA{");
}
else b_app1(pp);

REDUCE(pp,1,lpar,0,5000);
}

/* :170 */
#line 2392 "./prod.web"

}
#endif

/* :169 */
/* 172: */
#line 2418 "./prod.web"

#if FCN_CALLS
SRTN C_rbracket(VOID)
{
/* 173: */
#line 2427 "./prod.web"

{
if(active_brackets)
{
text_pointer t= indirect(pp->trans);

if(**t==']')**t= '}';
}

b_app1(pp);

REDUCE(pp,1,rpar,-5,5001);
}

/* :173 */
#line 2422 "./prod.web"

}
#endif

/* :172 */
/* 175: */
#line 2450 "./prod.web"

#if FCN_CALLS
SRTN C_killnl(VOID)
{
/* 178: */
#line 2475 "./prod.web"

{
kill_nl= YES;
SQUASH(pp,1,lbrace,-2,8888);
}

/* :178 */
#line 2454 "./prod.web"

}
#endif

/* :175 */
/* 180: */
#line 2490 "./prod.web"

#if FCN_CALLS
SRTN C_lbrace(VOID)
{
/* 181: */
#line 2499 "./prod.web"

{
if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2503 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,stmt,-1,130);
}
else if((cat1==stmt||cat1==decl||cat1==functn)&&cat2==rbrace)

{
b_app(force);
b_app1(pp);

/* 182: */
#line 2528 "./prod.web"

{
/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2530 "./prod.web"


b_app1(pp+1);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2534 "./prod.web"


kill_nl= NO;
}

/* :182 */
#line 2512 "./prod.web"


b_app1(pp+2);

REDUCE(pp,3,stmt,-1,131);
}
else if(cat1==expr)
{
if(cat2==rbrace)
SQUASH(pp,3,expr,-2,132);
else if(cat2==comma&&cat3==rbrace)
SQUASH(pp,4,expr,-2,132);
}
}

/* :181 */
#line 2494 "./prod.web"

}
#endif

/* :180 */
/* 184: */
#line 2548 "./prod.web"

#if FCN_CALLS
SRTN C__unop(VOID)
{
/* 185: */
#line 2557 "./prod.web"

{
if(cat1==expr)
SQUASH(pp,2,expr,-2,140);
else if(cat1==int_like)
SQUASH(pp,2,int_like,0,141);

}

/* :185 */
#line 2552 "./prod.web"

}
#endif

/* :184 */
/* 187: */
#line 2575 "./prod.web"

#if FCN_CALLS
SRTN C_unorbinop(VOID)
{
/* 188: */
#line 2584 "./prod.web"

{
if(cat1==expr||(cat1==int_like&&!(cat2==lpar||cat2==unop)))
{


b_app('{');b_app1(pp);b_app('}');
b_app1(pp+1);
REDUCE(pp,2,cat1,-2,150);
}
else if(cat1==binop)
/* 189: */
#line 2599 "./prod.web"

{
b_app(math_bin);
b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,151);
}

/* :189 */
#line 2595 "./prod.web"

}

/* :188 */
#line 2579 "./prod.web"

}
#endif

/* :187 */
/* 191: */
#line 2617 "./prod.web"

#if FCN_CALLS
SRTN C_cast(VOID)
{
/* 192: */
#line 2626 "./prod.web"

{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2630 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,expr,-2,160);
}
else if(cat1==unorbinop||cat1==reference)
SQUASH(pp,1,cast,PLUS 1,162);
else
SQUASH(pp,1,expr,-2,161);
}

/* :192 */
#line 2621 "./prod.web"

}
#endif

/* :191 */
/* 194: */
#line 2648 "./prod.web"

#if FCN_CALLS
SRTN C_sizeof_like(VOID)
{
/* 195: */
#line 2657 "./prod.web"

{
if(cat1==cast)
SQUASH(pp,2,expr,-2,170);
else if(cat1==expr)
SQUASH(pp,2,expr,-2,171);
}

/* :195 */
#line 2652 "./prod.web"

}
#endif

/* :194 */
/* 197: */
#line 2674 "./prod.web"

#if FCN_CALLS
SRTN C__binop(VOID)
{
/* 198: */
#line 2683 "./prod.web"

{
if(cat1==binop)
/* 199: */
#line 2699 "./prod.web"

{
b_app(math_bin);b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,180);
}

/* :199 */
#line 2686 "./prod.web"

else if(cat1==space)
{
b_app1(pp);
REDUCE(pp,2,binop,-1,181);
}
else if(Cpp&&cat1==decl_hd)
SQUASH(pp,2,tstart,0,6063);


}

/* :198 */
#line 2678 "./prod.web"

}
#endif

/* :197 */
/* 201: */
#line 2716 "./prod.web"

#if FCN_CALLS
SRTN C_do_like(VOID)
{
/* 202: */
#line 2725 "./prod.web"

{
if(cat1==stmt)
if(cat2==for_like)
{
cat2= while_do;
SQUASH(pp,1,do_like,PLUS 2,191);
}
else if(cat2==expr&&cat3==semi)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
b_app(force);
b_app2(pp+2);
REDUCE(pp,4,stmt,-1,190);
}
}

/* :202 */
#line 2720 "./prod.web"

}
#endif

/* :201 */
/* 204: */
#line 2754 "./prod.web"

#if FCN_CALLS
SRTN C_wh_do(VOID)
{
/* 205: */
#line 2763 "./prod.web"

{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2766 "./prod.web"
;
REDUCE(pp,1,expr,0,192);
}

/* :205 */
#line 2758 "./prod.web"

}
#endif

/* :204 */
/* 207: */
#line 2782 "./prod.web"

#if FCN_CALLS
SRTN C_for_like(VOID)
{
/* 208: */
#line 2791 "./prod.web"

{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2795 "./prod.web"
;b_app1(pp+1);
b_app(' ');

if(cat2==semi)
{
if(!auto_semi||(auto_semi&&cat3==semi))
{
indent_force;
b_app1(pp+2);
b_app(outdent);
REDUCE(pp,3,stmt,-2,200);

}
else
REDUCE(pp,3,for_hd,0,2011);
}
else
REDUCE(pp,2,for_hd,0,201);
}
else if(cat1!=lpar)
SQUASH(pp,1,expr,0,2010);
}

/* :208 */
#line 2786 "./prod.web"

}
#endif

/* :207 */
/* 210: */
#line 2827 "./prod.web"

#if FCN_CALLS
SRTN C_forhd(VOID)
{
/* 211: */
#line 2836 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-1,210);
}
}

/* :211 */
#line 2831 "./prod.web"

}
#endif

/* :210 */
/* 213: */
#line 2860 "./prod.web"

#if FCN_CALLS
SRTN C_if_like(VOID)
{
/* 214: */
#line 2869 "./prod.web"

{
if(cat1==lpar&&cat2==expr&&cat3==rpar)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2873 "./prod.web"
;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);
#endif
REDUCE(pp,4,IF_like,0,220);
}
}

/* :214 */
#line 2864 "./prod.web"

}
#endif

/* :213 */
/* 217: */
#line 2902 "./prod.web"

#if FCN_CALLS
SRTN C_IF(VOID)
{
/* 218: */
#line 2911 "./prod.web"

{
if(cat1==stmt
||cat1==lbrace||cat1==if_like||cat1==for_like||cat1==do_like
||cat1==Rdo_like
#if(0)
||cmnt_after_IF
#endif
)
SQUASH(pp,1,if_hd,0,230);
#if(0)
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,231);
}
#endif
}

/* :218 */
#line 2906 "./prod.web"

}
#endif

/* :217 */
/* 220: */
#line 2940 "./prod.web"

#if FCN_CALLS
SRTN C_if_hd(VOID)
{
/* 221: */
#line 2949 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}

/* :221 */
#line 2944 "./prod.web"

}
#endif

/* :220 */
/* 223: */
#line 2972 "./prod.web"

#if FCN_CALLS
SRTN C_els_hd(VOID)
{
/* 224: */
#line 2981 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,ELSE_like,-1,241);
}
}

/* :224 */
#line 2976 "./prod.web"

}
#endif

/* :223 */
/* 226: */
#line 3002 "./prod.web"

#if FCN_CALLS
SRTN C_else(VOID)
{
/* 227: */
#line 3011 "./prod.web"

{
if(cat1==if_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);
#if 0 
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}

/* :227 */
#line 3006 "./prod.web"

}
#endif

/* :226 */
/* 229: */
#line 3038 "./prod.web"

#if FCN_CALLS
SRTN C_ELS(VOID)
{
/* 230: */
#line 3047 "./prod.web"


/* :230 */
#line 3042 "./prod.web"

}
#endif

/* :229 */
/* 232: */
#line 3058 "./prod.web"

#if FCN_CALLS
SRTN C_IF_top(VOID)
{
/* 233: */
#line 3067 "./prod.web"

{
if(cat1==else_like||cat1==else_hd||cat1==space)
SQUASH(pp,1,IF_top,1,242);
else if(cat1==IF_top)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,238);
}
else if(cat1==ELSE_like)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,239);
}
else if(cat1==IF_like&&(cat2==expr||cat2==stmt))
SQUASH(pp,1,IF_top,1,241);
else
SQUASH(pp,1,stmt,-1,240);
}

/* :233 */
#line 3062 "./prod.web"

}
#endif

/* :232 */
/* 235: */
#line 3100 "./prod.web"

#if FCN_CALLS
SRTN C_stmt(VOID)
{
/* 236: */
#line 3109 "./prod.web"

{
if(cat1==stmt||(Cpp&&cat1==decl))
{
b_app1(pp);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 3115 "./prod.web"


b_app1(pp+1);

REDUCE(pp,2,stmt,-1,250);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,251);
}
}

/* :236 */
#line 3104 "./prod.web"

}
#endif

/* :235 */
/* 238: */
#line 3138 "./prod.web"

#if FCN_CALLS
SRTN C_case_like(VOID)
{
/* 239: */
#line 3147 "./prod.web"

{
if(cat1==semi)
SQUASH(pp,2,stmt,-1,260);
else if(cat1==colon)
SQUASH(pp,2,tag,-1,261);
else if(cat1==expr)
{
if(cat2==semi)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,stmt,-1,262);
}
else if(cat2==colon)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,tag,-1,263);
}
}
else if(cat1==int_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,int_like,-2,264);
}
}

/* :239 */
#line 3142 "./prod.web"

}
#endif

/* :238 */
/* 241: */
#line 3182 "./prod.web"

#if FCN_CALLS
SRTN C_tag(VOID)
{
/* 242: */
#line 3191 "./prod.web"

{
if(cat1==tag)
{
b_app1(pp);
b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==decl||cat1==functn)

{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,cat1,-1,271);
}
}

/* :242 */
#line 3186 "./prod.web"

}
#endif

/* :241 */
/* 244: */
#line 3219 "./prod.web"

#if FCN_CALLS
SRTN C_semi(VOID)
{
/* 245: */
#line 3228 "./prod.web"

{
b_app(' ');b_app1(pp);
REDUCE(pp,1,stmt,-1,280);
}

/* :245 */
#line 3223 "./prod.web"

}
#endif

/* :244 */
/* 247: */
#line 3243 "./prod.web"

#if FCN_CALLS
SRTN C_template(VOID)
{
/* 248: */
#line 3252 "./prod.web"

{
if(cat1==langle)
SQUASH(pp,1,template,PLUS 1,6000);
else if(cat1==tlist)
{
b_app1(pp);b_app(' ');b_app1(pp+1);b_app(force);
REDUCE(pp,2,int_like,0,6001);
}
}

/* :248 */
#line 3247 "./prod.web"

}
#endif

/* :247 */
/* 250: */
#line 3272 "./prod.web"

#if FCN_CALLS
SRTN C_langle(VOID)
{
/* 251: */
#line 3282 "./prod.web"

{
if((pp-1)->cat==template||(pp-1)->cat==int_like||(pp-1)->cat==
struct_like)
{
b_app('\\');
APP_STR("WLA ");
REDUCE(pp,1,tstart,0,6050);
}
else if(cat1==decl_hd&&cat2==rangle)
{
b_app('\\');
APP_STR("WLA ");
b_app1(pp+1);
b_app('\\');
APP_STR("WRA ");
REDUCE(pp,3,expr,-1,6053);
}
else if(cat1==int_like)
SQUASH(pp,1,langle,PLUS 1,6054);
else
SQUASH(pp,1,binop,-1,6051);
}

/* :251 */
#line 3276 "./prod.web"

}
#endif

/* :250 */
/* 253: */
#line 3315 "./prod.web"

#if FCN_CALLS
SRTN C_rangle(VOID)
{
/* 254: */
#line 3325 "./prod.web"

{
if((pp-1)->cat==decl_hd)
SQUASH(pp,1,rangle,-2,6055);
else
SQUASH(pp,1,binop,-1,6052);
}

/* :254 */
#line 3319 "./prod.web"

}
#endif

/* :253 */
/* 256: */
#line 3342 "./prod.web"

#if FCN_CALLS
SRTN C_tstart(VOID)
{
/* 257: */
#line 3351 "./prod.web"

{
if(cat2==rangle&&(cat1==int_like||cat1==decl_hd||cat1==expr
||cat1==unorbinop))
{
b_app2(pp);
b_app('\\');
APP_STR("WRA ");
OUTDENT;
REDUCE(pp,3,tlist,-1,6060);
}
}

/* :257 */
#line 3346 "./prod.web"

}
#endif

/* :256 */
/* 259: */
#line 3373 "./prod.web"

#if FCN_CALLS
SRTN C_tlist(VOID)
{
/* 260: */
#line 3382 "./prod.web"


/* :260 */
#line 3377 "./prod.web"

}
#endif

/* :259 */
/* 262: */
#line 3393 "./prod.web"

#if FCN_CALLS
SRTN C_namespace(VOID)
{
/* 263: */
#line 3402 "./prod.web"

{
if(cat1==expr||cat1==int_like)
{
make_underlined(pp+1);make_reserved(pp+1);

b_app1(pp);b_app(' ');b_app1(pp+1);

REDUCE(pp,2,fn_decl,0,7901);
}
else if(cat1==lbrace)
SQUASH(pp,1,fn_decl,0,7902);
}

/* :263 */
#line 3397 "./prod.web"

}
#endif

/* :262 */
/* 442: */
#line 5998 "./prod.web"


SRTN
prn_math FCN((k))
scrap_pointer k C1("")
{
if(INI_MATHNESS(k)==yes_math)
putxchar('+');
else if(INI_MATHNESS(k)==no_math)
putxchar('-');

prn_cat(k->cat);

if(LAST_MATHNESS(k)==yes_math)
putxchar('+');
else if(LAST_MATHNESS(k)==no_math)
putxchar('-');

DFLUSH
}

/* :442 */
#line 30 "./prod.web"

#endif 

#if(part != 1)
/* 265: */
#line 3424 "./prod.web"


SRTN
R_productions(VOID)
{
switch(pp->cat)
{
case ignore_scrap:/* 71: */
#line 928 "./prod.web"


#if FCN_CALLS
C_ignore_scrap();
#else
/* 73: */
#line 947 "./prod.web"

{
switch(cat1)
{
case stmt:
case functn:
SQUASH(pp,2,cat1,0,1);
break;
}
}

/* :73 */
#line 933 "./prod.web"

#endif

/* :71 */
#line 3431 "./prod.web"
break;
case expr:/* 266: */
#line 3506 "./prod.web"

#if FCN_CALLS
R_expr();
#else
/* 268: */
#line 3523 "./prod.web"

{
if(cat1==unop)SQUASH(pp,2,expr,-2,2);
else if((cat1==binop||cat1==unorbinop||cat1==colon)&&cat2==expr)

if(cat1==colon&&(*pp->trans)[1]==(sixteen_bits)'#')
{
b_app1(pp);
APP_STR("\\Colon");
b_app1(pp+2);
REDUCE(pp,3,expr,-2,3333);
}
else if(cat1==binop&&**(pp+1)->trans==(sixteen_bits)'/')
SQUASH(pp,1,expr,PLUS 1,3334);
else
SQUASH(pp,3,expr,-2,3);

else if(cat1==comma&&(cat2==expr||cat2==end_like))
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,expr,-2,4);
}
else if(cat1==expr)SQUASH(pp,2,expr,-2,5);
else if(cat1==semi)SQUASH(pp,2,stmt,-2,6);
else if(cat1==colon&&cat2==unorbinop&&
(cat3==rpar||(active_brackets&&cat3==rbracket)))
SQUASH(pp,3,expr,-2,299);
else if(cat1==colon&&cat2!=lpar)
{
make_underlined(pp);SQUASH(pp,2,tag,0,7);
}
else if(cat1==comma&&cat2==int_like)
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,int_like,-2,4444);
}
}

/* :268 */
#line 3510 "./prod.web"

#endif

/* :266 */
#line 3432 "./prod.web"
break;
case key_wd:/* 269: */
#line 3564 "./prod.web"

#if FCN_CALLS
R_key_wd();
#else
/* 271: */
#line 3581 "./prod.web"

{
SQUASH(pp,1,expr,-2,4445);
}

/* :271 */
#line 3568 "./prod.web"

#endif

/* :269 */
#line 3433 "./prod.web"
break;
case exp_op:/* 272: */
#line 3590 "./prod.web"

#if FCN_CALLS
R_exp_op();
#else
/* 274: */
#line 3607 "./prod.web"

{
if(cat1==lpar)SQUASH(pp,1,exp_op,PLUS 1,2995);
else if(cat1==expr)
if(cat2==lpar)SQUASH(pp,1,exp_op,PLUS 2,2996);

else if(cat2==expr)SQUASH(pp,1,exp_op,PLUS 1,2997);

else
{

b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
REDUCE(pp,2,expr,-1,2998);
}
}

/* :274 */
#line 3594 "./prod.web"

#endif

/* :272 */
#line 3434 "./prod.web"
break;
case _EXPR:/* 87: */
#line 1130 "./prod.web"

#if FCN_CALLS
C__E();
#else
/* 89: */
#line 1147 "./prod.web"

{
APP_SPACE;b_app1(pp);
REDUCE(pp,1,expr,-2,4446);
}

/* :89 */
#line 1134 "./prod.web"

#endif

/* :87 */
#line 3435 "./prod.web"
break;
case _EXPR_:/* 90: */
#line 1154 "./prod.web"

#if FCN_CALLS
C__E_();
#else
/* 92: */
#line 1171 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1173 "./prod.web"
;
REDUCE(pp,1,expr,-2,4447);
}

/* :92 */
#line 1158 "./prod.web"

#endif

/* :90 */
#line 3436 "./prod.web"
break;
case EXPR_:/* 93: */
#line 1178 "./prod.web"

#if FCN_CALLS
C_E_();
#else
/* 95: */
#line 1195 "./prod.web"

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,expr,-2,4448);
}

/* :95 */
#line 1182 "./prod.web"

#endif

/* :93 */
#line 3437 "./prod.web"
break;
case lpar:/* 309: */
#line 4170 "./prod.web"

#if FCN_CALLS
R_lpar();
#else
/* 311: */
#line 4187 "./prod.web"


if(cat1==expr&&cat2==rpar)
SQUASH(pp,3,expr,-2,120);
else if(cat1==expr&&cat2==colon&&cat3==rpar)
{
b_app3(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4193 "./prod.web"
;b_app1(pp+3);
REDUCE(pp,4,expr,-2,9120);
}
else if(cat1==colon&&cat2!=comma)

{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4199 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,lpar,0,9121);
}
else if(cat1==rpar)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4204 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if(cat1==stmt)
{
b_app2(pp);b_app(' ');REDUCE(pp,2,lpar,0,123);
}

/* :311 */
#line 4174 "./prod.web"

#endif

/* :309 */
#line 3438 "./prod.web"
break;
case lbracket:/* 168: */
#line 2380 "./prod.web"

#if FCN_CALLS
C_lbracket();
#else
/* 170: */
#line 2397 "./prod.web"

{
if(active_brackets)
{
b_app('\\');
APP_STR("WXA{");
}
else b_app1(pp);

REDUCE(pp,1,lpar,0,5000);
}

/* :170 */
#line 2384 "./prod.web"

#endif

/* :168 */
#line 3439 "./prod.web"
break;
case rbracket:/* 171: */
#line 2410 "./prod.web"

#if FCN_CALLS
C_rbracket();
#else
/* 173: */
#line 2427 "./prod.web"

{
if(active_brackets)
{
text_pointer t= indirect(pp->trans);

if(**t==']')**t= '}';
}

b_app1(pp);

REDUCE(pp,1,rpar,-5,5001);
}

/* :173 */
#line 2414 "./prod.web"

#endif

/* :171 */
#line 3440 "./prod.web"
break;
case unop:/* 318: */
#line 4275 "./prod.web"

#if FCN_CALLS
R_unop();
#else
/* 320: */
#line 4292 "./prod.web"


if(cat1==expr)SQUASH(pp,2,expr,-2,33);

/* :320 */
#line 4279 "./prod.web"

#endif

/* :318 */
#line 3441 "./prod.web"
break;
case UNOP:/* 78: */
#line 1058 "./prod.web"

#if FCN_CALLS
C_UNOP();
#else
/* 80: */
#line 1075 "./prod.web"

{
b_app1(pp);APP_SPACE;
REDUCE(pp,1,unop,-1,4443);
}

/* :80 */
#line 1062 "./prod.web"

#endif

/* :78 */
#line 3442 "./prod.web"
break;
case unorbinop:/* 321: */
#line 4297 "./prod.web"

#if FCN_CALLS
R_unorbinop();
#else
/* 323: */
#line 4314 "./prod.web"


if(cat1==expr)
{
b_app('{');b_app1(pp);b_app('}');
b_app1(pp+1);
REDUCE(pp,2,expr,-2,140);
}
else if(cat1==binop)
/* 189: */
#line 2599 "./prod.web"

{
b_app(math_bin);
b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,151);
}

/* :189 */
#line 4323 "./prod.web"

else if(cat1==comma||cat1==rpar)
SQUASH(pp,1,expr,-2,141);

/* :323 */
#line 4301 "./prod.web"

#endif

/* :321 */
#line 3443 "./prod.web"
break;
case binop:/* 329: */
#line 4369 "./prod.web"

#if FCN_CALLS
R_binop();
#else
/* 331: */
#line 4386 "./prod.web"

{
sixteen_bits tok= **pp->trans;

if(cat1==binop)
{
if(tok==(sixteen_bits)'/')
{
if(**(pp+1)->trans==tok)
/* 332: */
#line 4421 "./prod.web"

{
b_app('{');
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4424 "./prod.web"
;b_app1(pp+1);
b_app('}');
REDUCE(pp,2,slashes,-1,180);
}

/* :332 */
#line 4395 "./prod.web"

else
{
APP_STR("\\WSl");
REDUCE(pp,1,binop,-1,1803);
}
}
else
/* 199: */
#line 2699 "./prod.web"

{
b_app(math_bin);b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,180);
}

/* :199 */
#line 4403 "./prod.web"

}
else
{
if(tok==(sixteen_bits)'/')
{
if(cat1==expr&&cat2==binop&&**(pp+2)->trans==tok)
/* 333: */
#line 4430 "./prod.web"

{
#if 0
b_app('{');
b_app1(pp);
b_app('}');
#endif

make_underlined(pp+1);
APP_STR("\\WCMN");
b_app1(pp+1);

#if 0
b_app('{');
b_app1(pp+2);
b_app('}');
#endif

REDUCE(pp,3,slashes,-1,9181);
}

/* :333 */
#line 4410 "./prod.web"

else
{
APP_STR("\\WSl");
REDUCE(pp,1,binop,-1,1804);
}
}
}
}

/* :331 */
#line 4373 "./prod.web"

#endif

/* :329 */
#line 3444 "./prod.web"
break;
case BINOP:/* 81: */
#line 1082 "./prod.web"

#if FCN_CALLS
C_BINOP();
#else
/* 83: */
#line 1099 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1101 "./prod.web"
;
REDUCE(pp,1,binop,-1,4444);
}

/* :83 */
#line 1086 "./prod.web"

#endif

/* :81 */
#line 3445 "./prod.web"
break;
case slash_like:/* 326: */
#line 4340 "./prod.web"

#if FCN_CALLS
R_slash_like();
#else
/* 328: */
#line 4357 "./prod.web"

if(cat1==slash_like)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4361 "./prod.web"
;
b_app1(pp+1);
REDUCE(pp,2,slashes,-1,1801);
}
else if(cat1==expr&&cat2==slash_like)
SQUASH(pp,3,slashes,-1,1802);

/* :328 */
#line 4344 "./prod.web"

#endif

/* :326 */
#line 3446 "./prod.web"
break;
case colon:/* 312: */
#line 4213 "./prod.web"

#if FCN_CALLS
R_colon();
#else
/* 314: */
#line 4230 "./prod.web"


if(cat1==expr||cat1==unorbinop)
SQUASH(pp,2,expr,-2,9500);
else if(cat1==comma&&cat2==colon)
SQUASH(pp,3,colon,-2,9502);


else
SQUASH(pp,1,expr,0,9501);

/* :314 */
#line 4217 "./prod.web"

#endif

/* :312 */
#line 3447 "./prod.web"
break;
case program_like:/* 276: */
#line 3631 "./prod.web"

#if FCN_CALLS
R_program_like();
#else
/* 278: */
#line 3648 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==expr&&cat2==semi)
{
fcn_level++;
b_app1(pp);b_app(' ');
b_app(indent);b_app2(pp+1);b_app(outdent);
defined_at(make_underlined(pp+1));
REDUCE(pp,3,fcn_hd,-1,2999);
}
else if(cat1==no_order)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,program_like,0,2997);
}
else if(cat1==semi)
{
fcn_level++;
b_app1(pp);
REDUCE(pp,2,fcn_hd,-1,2996);
}
else if(cat1==proc_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,int_like,0,2887);
}
}
else
{
fcn_level++;
SQUASH(pp,1,int_like,-1,2998);
}

/* :278 */
#line 3635 "./prod.web"

#endif

/* :276 */
#line 3448 "./prod.web"
break;
case struct_like:/* 291: */
#line 3867 "./prod.web"

#if FCN_CALLS
R_struct_like();
#else
/* 293: */
#line 3884 "./prod.web"

if(cat1==lpar)
{
b_app1(pp);
#if(0)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 3889 "./prod.web"

#endif
REDUCE(pp,1,int_like,0,9075);

}
else if(cat1==comma&&cat2==int_like)
{
b_app2(pp);b_app(' ');b_app1(pp+2);
REDUCE(pp,3,struct_like,0,90750);
}
else if(cat1==binop&&**(pp+1)->trans!=(sixteen_bits)'/')
SQUASH(pp,2,struct_like,0,90751);

else if(cat1==expr||cat1==slashes||cat1==struct_like)
{

b_app1(pp);b_app(' ');b_app1(pp+1);
make_underlined(pp+1);
REDUCE(pp,2,language==FORTRAN_90?struct_hd:struct_like,0,9076);
}
else if(cat1==semi)
SQUASH(pp,1,struct_hd,0,9077);
else if(cat1==lbrace)
{
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}

/* :293 */
#line 3871 "./prod.web"

#endif

/* :291 */
#line 3449 "./prod.web"
break;
case struct_hd:/* 294: */
#line 3918 "./prod.web"

#if FCN_CALLS
R_str_hd();
#else
/* 296: */
#line 3935 "./prod.web"

if(is_FORTRAN_(language))
{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 3940 "./prod.web"
b_app1(pp+1);

REDUCE(pp,2,struct_hd,0,90760);
}
else if(cat1==semi)
{
fcn_level++;
b_app2(pp);
b_app(indent);
REDUCE(pp,2,struct_hd,0,90770);
}
else if(cat1==decl||cat1==functn)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,struct_hd,0,9078);
}
else if(cat1==END_stmt)
{
b_app1(pp);
b_app(outdent);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,9079);
}
}
else/* 164: */
#line 2307 "./prod.web"

{
if((cat1==decl||cat1==stmt
||cat1==expr
||cat1==functn
)&&cat2==rbrace)
{
b_app1(pp);
/* 182: */
#line 2528 "./prod.web"

{
/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2530 "./prod.web"


b_app1(pp+1);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2534 "./prod.web"


kill_nl= NO;
}

/* :182 */
#line 2315 "./prod.web"

b_app1(pp+2);
b_app(outdent);
/* :164 */
/* 164: */
#line 2321 "./prod.web"
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2325 "./prod.web"
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}

/* :164 */
#line 3967 "./prod.web"


/* :296 */
#line 3922 "./prod.web"

#endif

/* :294 */
#line 3450 "./prod.web"
break;
case op_like:/* 297: */
#line 3970 "./prod.web"

#if FCN_CALLS
R_op_like();
#else
/* 299: */
#line 3987 "./prod.web"

{
short n;

if(cat1==lpar)
{

scrap_pointer q;
int k;



for(q= pp+2;q<=scrp_ptr&&q-pp<MAX_OP_TOKENS;q++)
if(q->cat==rpar)break;

n= (q->cat==rpar)?PTR_DIFF(short,q,pp):0;

if(n>0)
{
b_app1(pp);b_app(' ');
b_app1(pp+1);
b_app('{');
APP_STR("\\optrue");

for(k= 2;k<n;k++)
b_app1(pp+k);

APP_STR("\\opfalse");

b_app('}');
b_app1(pp+k);

REDUCE(pp,n+1,expr,-2,6667);
}
}
}

/* :299 */
#line 3974 "./prod.web"

#endif

/* :297 */
#line 3451 "./prod.web"
break;
case proc_like:/* 282: */
#line 3738 "./prod.web"

#if FCN_CALLS
R_proc_like();
#else
/* 284: */
#line 3755 "./prod.web"


if(fcn_level==0){}
else fcn_level--;

SQUASH(pp,1,int_like,-1,2989);

/* :284 */
#line 3742 "./prod.web"

#endif

/* :282 */
#line 3452 "./prod.web"
break;
case private_like:/* 285: */
#line 3764 "./prod.web"

#if FCN_CALLS
R_private_like();
#else
/* 287: */
#line 3781 "./prod.web"

{
if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{
app(backup);
b_app2(pp);
REDUCE(pp,2,decl,-1,2988);
}
else SQUASH(pp,1,int_like,-2,2987);
}

/* :287 */
#line 3768 "./prod.web"

#endif

/* :285 */
#line 3453 "./prod.web"
break;
case int_like:/* 288: */
#line 3793 "./prod.web"

#if FCN_CALLS
R_int_like();
#else
/* 290: */
#line 3810 "./prod.web"

{
if(cat1==lbrace)
{
b_app(indent);
b_app1(pp);
REDUCE(pp,1,decl_hd,0,940);
}
else if(cat1==unorbinop&&cat2==expr)
{
b_app1(pp);
b_app('{');b_app2(pp+1);b_app('}');
REDUCE(pp,3,int_like,-1,941);
}
else if(cat1==int_like||cat1==no_order)


{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,cat0,0,40);
}
else if(cat1==comma)
SQUASH(pp,2,int_like,0,9001);
else if(cat1==binop)
{
b_app2(pp);
b_app(indent);
REDUCE(pp,2,decl_hd,0,9002);
}
else if(cat1==slashes)
{
b_app1(pp);
b_app(' ');
b_app(indent);
REDUCE(pp,1,decl_hd,0,9002);
}
else if(cat1==expr&&**indirect((pp+1)->trans)=='(')
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 3848 "./prod.web"
b_app1(pp+1);
REDUCE(pp,2,int_like,0,9003);
}
else if(cat1==expr||cat1==semi)
{
b_app1(pp);

if(cat1!=semi)app('~');

b_app(indent);

REDUCE(pp,1,decl_hd,0,41);
}
else if(cat1==rbrace)
SQUASH(pp,1,decl,-1,411);

}

/* :290 */
#line 3797 "./prod.web"

#endif

/* :288 */
#line 3454 "./prod.web"
break;
case decl_hd:/* 300: */
#line 4025 "./prod.web"

#if FCN_CALLS
R_dcl_hd();
#else
/* 302: */
#line 4042 "./prod.web"

if(cat1==comma)
{
b_app2(pp);b_app(' ');REDUCE(pp,2,decl_hd,0,54);
}
else if(cat1==expr)
{
make_underlined(pp+1);

if(**(pp+2)->trans==(sixteen_bits)'=')
{
SQUASH(pp,1,decl_hd,PLUS 1,55);
}
else
{
SQUASH(pp,2,decl_hd,0,56);
}
}
else if(cat1==slashes)
{
SQUASH(pp,2,decl_hd,0,57);
}
/* :302 */
/* 302: */
#line 4071 "./prod.web"
else if(cat1==lbrace||cat1==int_like||cat1==implicit_like)


{
b_app1(pp);
b_app(outdent);
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi&&(!auto_semi||(auto_semi&&cat2!=lbrace)))
{
b_app2(pp);
b_app(outdent);
REDUCE(pp,2,
(eight_bits)(intermingle?(intermingle= NO,ignore_scrap):decl),
-1,59);
}
else if(cat1==built_in)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,decl_hd,0,5901);
}
#if(0)
else if(cat1==lpar&&cat2==expr)make_underlined(pp+2);

#endif

/* :302 */
#line 4029 "./prod.web"

#endif

/* :300 */
#line 3455 "./prod.web"
break;
case decl:/* 303: */
#line 4099 "./prod.web"

#if FCN_CALLS
R_decl();
#else
/* 305: */
#line 4116 "./prod.web"

if(is_FORTRAN_(language)&&cat1==END_like)SQUASH(pp,1,stmt,-1,960);

else if(cat1==decl)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,61);
}

/* :305 */
#line 4103 "./prod.web"

#endif

/* :303 */
#line 3456 "./prod.web"
break;
case fn_decl:/* 140: */
#line 1926 "./prod.web"

#if FCN_CALLS
C_fn_decl();
#else
/* 142: */
#line 1943 "./prod.web"

{
if(cat1==semi&&Cpp)
{
b_app2(pp);
REDUCE(pp,2,stmt,-1,72);
}
else if(cat1==decl)
{
b_app1(pp);
b_app(indent);indent_force;
b_app1(pp+1);
b_app(outdent);b_app(outdent);
REDUCE(pp,2,fn_decl,0,70);
}
else if(cat1==stmt)
{
#if(0)
b_app(backup);
#endif
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);
b_app(outdent);
in_function= kill_nl= NO;
REDUCE(pp,2,functn,-1,71);
}
}

/* :142 */
#line 1930 "./prod.web"

#endif

/* :140 */
#line 3457 "./prod.web"
break;
case fcn_hd:/* 279: */
#line 3684 "./prod.web"

#if FCN_CALLS
R_fcn_hd();
#else
/* 281: */
#line 3701 "./prod.web"

{
if(cat1==END_stmt)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,7172);
}
else if(cat1==stmt&&cat2==END_stmt)
{
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);

if(fcn_level==0)
{
if(containing)
b_app(big_force);

while(containing)
{
#if(0)
b_app(outdent);
#endif
containing--;
}
}

b_app(outdent);
b_app(force);

b_app1(pp+2);
REDUCE(pp,3,functn,-1,7171);
}
}

/* :281 */
#line 3688 "./prod.web"

#endif

/* :279 */
#line 3458 "./prod.web"
break;
case functn:/* 306: */
#line 4132 "./prod.web"

#if FCN_CALLS
R_functn();
#else
/* 308: */
#line 4149 "./prod.web"


if(cat1==functn||(is_RATFOR_(language)&&(cat1==decl||cat1==stmt)))
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,0,80);
}
else if(free_Fortran&&cat1==semi)
{
b_app2(pp);
REDUCE(pp,2,functn,0,8088);
}
#if(0)
else if(cat1==END_like)
{
b_app1(pp);
REDUCE(pp,1,stmt,-1,9050);
}
#endif

/* :308 */
#line 4136 "./prod.web"

#endif

/* :306 */
#line 3459 "./prod.web"
break;
case lbrace:/* 315: */
#line 4242 "./prod.web"

#if FCN_CALLS
R_lbrace();
#else
/* 317: */
#line 4259 "./prod.web"

if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4262 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,stmt,-2,130);
}
else if((cat1==stmt||cat1==decl)&&cat2==rbrace)
{
b_app(force);
b_app1(pp);b_app(force);
b_app1(pp+1);b_app(force);
b_app1(pp+2);
REDUCE(pp,3,stmt,-2,131);
}

/* :317 */
#line 4246 "./prod.web"

#endif

/* :315 */
#line 3460 "./prod.web"
break;
case do_like:/* 342: */
#line 4605 "./prod.web"

#if FCN_CALLS
R_do_like();
#else
/* 344: */
#line 4622 "./prod.web"


if(cat1==stmt)
{
if(cat2==until_like)
{
found_until= YES;
SQUASH(pp,1,do_like,PLUS 2,9190);

}
else
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
b_app(force);

if(found_until&&cat2==stmt)

{
found_until= NO;
b_app1(pp+2);REDUCE(pp,3,stmt,-2,9191);
}
else REDUCE(pp,2,stmt,-2,9192);

}
}

/* :344 */
#line 4609 "./prod.web"

#endif

/* :342 */
#line 3461 "./prod.web"
break;
case until_like:/* 345: */
#line 4652 "./prod.web"

#if FCN_CALLS
R_until_like();
#else
/* 347: */
#line 4669 "./prod.web"


SQUASH(pp,1,for_like,0,9195);

/* :347 */
#line 4656 "./prod.web"

#endif

/* :345 */
#line 3462 "./prod.web"
break;
case Rdo_like:/* 338: */
#line 4540 "./prod.web"

#if FCN_CALLS
R_Rdo_like();
#else
/* 340: */
#line 4557 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==for_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,Rdo_like,0,9600);
}
else if(cat1==expr&&((cat2==expr&&cat3==binop)||cat2==if_like))
{
label_text_ptr[indent_level]= (pp+1)->trans;

b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,Rdo_like,0,9601);
}
else if(cat1==stmt)
{
loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);
b_app(' ');
b_app1(pp+1);
app_loop_num(max_loop_num);

b_app(indent);
REDUCE(pp,2,stmt,-2,9602);
}
}

else if(cat1==stmt||(cat1==expr&&cat2==lbrace))

{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,for_hd,0,9603);
}

/* :340 */
#line 4544 "./prod.web"

#endif

/* :338 */
#line 3463 "./prod.web"
break;
case if_like:/* 349: */
#line 4680 "./prod.web"

#if FCN_CALLS
R_if_like();
#else
/* 351: */
#line 4697 "./prod.web"


if(cat1==CASE_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,if_like,0,9196);
}
else
if(is_FORTRAN_(language))
{
if(cat1==expr)
{
boolean if_form;

if((if_form= BOOLEAN(cat2==built_in&&cat3==semi))||cat2==semi)
{
short n;


loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4719 "./prod.web"
;
b_app1(pp+1);
b_app(' ');

if(if_form)
{
n= 4;
b_app2(pp+2);
}
else
{
n= 3;
b_app1(pp+2);
}

app_loop_num(max_loop_num);
b_app(indent);
REDUCE(pp,n,stmt,-2,9800);
}
else if(cat2==stmt)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4741 "./prod.web"
;
b_app1(pp+1);
app(' ');
b_app(cancel);
b_app1(pp+2);
REDUCE(pp,3,stmt,-2,9801);
}
else
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4751 "./prod.web"
;
b_app1(pp+1);
REDUCE(pp,2,if_hd,0,9802);
}
}
}

else/* 214: */
#line 2869 "./prod.web"

{
if(cat1==lpar&&cat2==expr&&cat3==rpar)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2873 "./prod.web"
;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);
#endif
REDUCE(pp,4,IF_like,0,220);
}
}

/* :214 */
#line 4758 "./prod.web"



/* :351 */
#line 4684 "./prod.web"

#endif

/* :349 */
#line 3464 "./prod.web"
break;
case IF_like:/* 216: */
#line 2894 "./prod.web"

#if FCN_CALLS
C_IF();
#else
/* 218: */
#line 2911 "./prod.web"

{
if(cat1==stmt
||cat1==lbrace||cat1==if_like||cat1==for_like||cat1==do_like
||cat1==Rdo_like
#if(0)
||cmnt_after_IF
#endif
)
SQUASH(pp,1,if_hd,0,230);
#if(0)
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,231);
}
#endif
}

/* :218 */
#line 2898 "./prod.web"

#endif

/* :216 */
#line 3465 "./prod.web"
break;

case IF_top:/* 231: */
#line 3050 "./prod.web"

#if FCN_CALLS
C_IF_top();
#else
/* 233: */
#line 3067 "./prod.web"

{
if(cat1==else_like||cat1==else_hd||cat1==space)
SQUASH(pp,1,IF_top,1,242);
else if(cat1==IF_top)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,IF_top,-1,238);
}
else if(cat1==ELSE_like)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,239);
}
else if(cat1==IF_like&&(cat2==expr||cat2==stmt))
SQUASH(pp,1,IF_top,1,241);
else
SQUASH(pp,1,stmt,-1,240);
}

/* :233 */
#line 3054 "./prod.web"

#endif

/* :231 */
#line 3467 "./prod.web"
break;
case endif_like:/* 362: */
#line 4881 "./prod.web"

#if FCN_CALLS
R_endif_like();
#else
/* 364: */
#line 4898 "./prod.web"

{
short n;
boolean no_construct_name;

if((no_construct_name= BOOLEAN(cat1==semi))||(cat1==expr&&cat2==semi))
{
b_app(outdent);
b_app(force);

if(no_construct_name)
{
n= 2;
b_app2(pp);
}
else
{
n= 3;
b_app1(pp);b_app(' ');b_app2(pp+1);
}

if(--indent_level<0)
indent_level= 0;

app_loop_num(loop_num[indent_level]);
REDUCE(pp,n,stmt,-2,9880);
}
}

/* :364 */
#line 4885 "./prod.web"

#endif

/* :362 */
#line 3468 "./prod.web"
break;
case end_like:/* 356: */
#line 4809 "./prod.web"

#if FCN_CALLS
R_end_like();
#else
/* 358: */
#line 4826 "./prod.web"

if(cat1==Rdo_like||cat1==if_like)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,endif_like,0,9860);

}
else
{
fcn_level--;
SQUASH(pp,1,END_like,-1,9861);
}

/* :358 */
#line 4813 "./prod.web"

#endif

/* :356 */
#line 3469 "./prod.web"
break;
case END_like:/* 359: */
#line 4843 "./prod.web"

#if FCN_CALLS
R_END();
#else
/* 361: */
#line 4860 "./prod.web"

{
if(cat1==program_like||cat1==struct_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);

if(cat2==expr)
{
b_app(' ');b_app1(pp+2);
REDUCE(pp,3,END_like,0,9860);
}
else
REDUCE(pp,2,END_like,0,9861);
}
else if(cat1==semi)
SQUASH(pp,2,END_stmt,-2,9862);
}

/* :361 */
#line 4847 "./prod.web"

#endif

/* :359 */
#line 3470 "./prod.web"
break;
case go_like:/* 353: */
#line 4779 "./prod.web"

#if FCN_CALLS
R_go_like();
#else
/* 355: */
#line 4796 "./prod.web"


if(cat1==built_in)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,case_like,0,9850);
}
else SQUASH(pp,1,expr,-2,9851);

/* :355 */
#line 4783 "./prod.web"

#endif

/* :353 */
#line 3471 "./prod.web"
break;
case for_like:/* 206: */
#line 2774 "./prod.web"

#if FCN_CALLS
C_for_like();
#else
/* 208: */
#line 2791 "./prod.web"

{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2795 "./prod.web"
;b_app1(pp+1);
b_app(' ');

if(cat2==semi)
{
if(!auto_semi||(auto_semi&&cat3==semi))
{
indent_force;
b_app1(pp+2);
b_app(outdent);
REDUCE(pp,3,stmt,-2,200);

}
else
REDUCE(pp,3,for_hd,0,2011);
}
else
REDUCE(pp,2,for_hd,0,201);
}
else if(cat1!=lpar)
SQUASH(pp,1,expr,0,2010);
}

/* :208 */
#line 2778 "./prod.web"

#endif

/* :206 */
#line 3472 "./prod.web"
break;
case for_hd:/* 209: */
#line 2819 "./prod.web"

#if FCN_CALLS
C_forhd();
#else
/* 211: */
#line 2836 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-1,210);
}
}

/* :211 */
#line 2823 "./prod.web"

#endif

/* :209 */
#line 3473 "./prod.web"
break;
case else_like:/* 368: */
#line 4965 "./prod.web"

#if FCN_CALLS
R_else_like();
#else
/* 370: */
#line 4982 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==if_like)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,else_like,0,9910);
}
else if(cat1==semi)
{
b_app(outdent);
b_app(force);
b_app2(pp);
app_loop_num(loop_num[indent_level-1]);
b_app(indent);
REDUCE(pp,2,stmt,-2,9911);
}
else if(cat1==expr&&cat2==built_in&&cat3==semi)

{
b_app(outdent);
b_app(force);

b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5009 "./prod.web"
;
b_app1(pp+1);
b_app(' ');
b_app2(pp+2);
app_loop_num(loop_num[indent_level-1]);

b_app(indent);
REDUCE(pp,4,stmt,-2,9912);
}
}

else/* 227: */
#line 3011 "./prod.web"

{
if(cat1==if_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);
#if 0 
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}

/* :227 */
#line 5020 "./prod.web"


/* :370 */
#line 4969 "./prod.web"

#endif

/* :368 */
#line 3474 "./prod.web"
break;
case else_hd:/* 222: */
#line 2964 "./prod.web"

#if FCN_CALLS
C_els_hd();
#else
/* 224: */
#line 2981 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,ELSE_like,-1,241);
}
}

/* :224 */
#line 2968 "./prod.web"

#endif

/* :222 */
#line 3475 "./prod.web"
break;
/* :265 */
/* 265: */
#line 3480 "./prod.web"
case if_hd:/* 365: */
#line 4928 "./prod.web"

#if FCN_CALLS
R_if_hd();
#else
/* 367: */
#line 4945 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==stmt)
{
#if 0
b_app1(pp);b_app(break_space);b_app1(pp+1);
#endif
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-2,9900);
}
}
else
/* 221: */
#line 2949 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}

/* :221 */
#line 4962 "./prod.web"


/* :367 */
#line 4932 "./prod.web"

#endif

/* :365 */
#line 3480 "./prod.web"
break;
case CASE_like:/* 374: */
#line 5093 "./prod.web"

#if FCN_CALLS
R_CASE();
#else
/* 376: */
#line 5110 "./prod.web"


if(is_FORTRAN_(language))
{
b_app(backup);
b_app1(pp);
REDUCE(pp,1,case_like,0,9258);
}
else SQUASH(pp,1,case_like,0,9259);

/* :376 */
#line 5097 "./prod.web"

#endif

/* :374 */
#line 3481 "./prod.web"
break;
case case_like:/* 377: */
#line 5121 "./prod.web"

#if FCN_CALLS
R_case_like();
#else
/* 379: */
#line 5138 "./prod.web"

if(cat1==read_like)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,case_like,0,9260);
}
else if(cat1==semi)SQUASH(pp,2,stmt,-2,260);
else if(cat1==colon)/* 380: */
#line 5161 "./prod.web"

{
b_app1(pp);APP_STR("\\Colon\\ ");
REDUCE(pp,2,tag,-1,261);
}

/* :380 */
#line 5147 "./prod.web"

else if(cat1==expr&&cat2==semi)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,stmt,-2,262);
}
else if((cat1==expr||cat1==label)&&cat2==colon)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
APP_STR("\\Colon\\ ");
REDUCE(pp,3,tag,-1,263);
}

/* :379 */
#line 5125 "./prod.web"

#endif

/* :377 */
#line 3482 "./prod.web"
break;
case stmt:/* 371: */
#line 5023 "./prod.web"

#if FCN_CALLS
R_stmt();
#else
/* 373: */
#line 5040 "./prod.web"


/* :373 */
/* 373: */
#line 5077 "./prod.web"
if(cat1==stmt||(free_Fortran&&cat1==decl))
{
b_app1(pp);
b_app(break_space);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,2501);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,2511);
}

/* :373 */
#line 5027 "./prod.web"

#endif

/* :371 */
#line 3483 "./prod.web"
break;
case tag:/* 381: */
#line 5168 "./prod.web"

#if FCN_CALLS
R_tag();
#else
/* 383: */
#line 5185 "./prod.web"


if(cat1==tag)
{
b_app1(pp);b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==END_like)
{
boolean end_of_loop;

end_of_loop= NO;


while(indent_level>0&&
compare_text(pp->trans,label_text_ptr[indent_level-1]))
{
--indent_level;
b_app(outdent);
end_of_loop= YES;
}

if(is_FORTRAN_(language)&&Fortran_label)
{
b_app(force);
APP_STR("\\Wlbl{");b_app1(pp);app('}');

}
else
{
b_app(big_force);
b_app(backup);
b_app1(pp);
b_app(force);
}

b_app1(pp+1);

if(end_of_loop)
app_loop_num(loop_num[indent_level]);

REDUCE(pp,2,cat1,-2,271);
}


/* :383 */
#line 5172 "./prod.web"

#endif

/* :381 */
#line 3484 "./prod.web"
break;
case label:/* 384: */
#line 5232 "./prod.web"

#if FCN_CALLS
R_label();
#else
/* 386: */
#line 5249 "./prod.web"

if(cat1==colon)
{
b_app1(pp);
REDUCE(pp,2,label,0,9270);


}
else if(cat1==stmt||cat1==END_like)
{
b_app1(pp);APP_STR("\\Colon\\ ");

if(is_FORTRAN_(language)&&Fortran_label)
b_app(cancel);

REDUCE(pp,1,tag,0,9271);

}

/* :386 */
#line 5236 "./prod.web"

#endif

/* :384 */
#line 3485 "./prod.web"
break;
case semi:/* 387: */
#line 5269 "./prod.web"

#if FCN_CALLS
R_semi();
#else
/* 389: */
#line 5286 "./prod.web"

if(is_RATFOR_(language)&&auto_semi)
{
text_pointer t;

t= indirect(pp->trans);

if(**t==';')**t= 0;
SQUASH(pp,1,ignore_scrap,-1,9280);
}
else
{
b_app(' ');b_app1(pp);REDUCE(pp,1,stmt,-2,280);
}

/* :389 */
#line 5273 "./prod.web"

#endif

/* :387 */
#line 3486 "./prod.web"
break;

case common_like:/* 390: */
#line 5302 "./prod.web"

#if FCN_CALLS
R_common_like();
#else
/* 393: */
#line 5322 "./prod.web"

if(cat1==expr||cat1==slashes||cat1==semi)
{
#if 0
b_app1(pp);
#if 0
if(cat1!=semi)
b_app(' ');
#endif
b_app(indent);
REDUCE(pp,1,common_hd,0,9950);
#endif
SQUASH(pp,1,common_hd,0,9950);
}

/* :393 */
#line 5306 "./prod.web"

#endif

/* :390 */
#line 3488 "./prod.web"
break;
case common_hd:/* 394: */
#line 5338 "./prod.web"

#if FCN_CALLS
R_cmn_hd();
#else
/* 396: */
#line 5355 "./prod.web"


#if 0
if(cat1==expr)
SQUASH(pp,2,common_hd,0,9951);
else if(cat1==slashes)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
b_app(' ');
REDUCE(pp,2,common_hd,0,9952);
}
else if(cat1==comma)
{
b_app2(pp);
b_app(' ');
REDUCE(pp,2,common_hd,0,9953);
}

if(cat1==expr)
{
b_app1(pp);
OPT9;
b_app1(pp+1);
REDUCE(pp,2,common_hd,0,9951);
}
else if(cat1==slashes)
{
SQUASH(pp,2,common_hd,0,9952);
}
else if(cat1==comma)
{
SQUASH(pp,2,common_hd,0,9953);
}
else if(cat1==semi)
{
b_app2(pp);
b_app(outdent);
REDUCE(pp,2,decl,-1,9954);
}
#endif
if(cat1==slashes)
SQUASH(pp,2,int_like,0,9952);
else
SQUASH(pp,1,int_like,0,9951);

/* :396 */
#line 5342 "./prod.web"

#endif

/* :394 */
#line 3489 "./prod.web"
break;
case read_like:/* 397: */
#line 5403 "./prod.web"

#if FCN_CALLS
R_read_like();
#else
/* 399: */
#line 5420 "./prod.web"


if(cat1==lpar&&cat2==expr&&cat3==rpar)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5425 "./prod.web"
;
b_app3(pp+1);
b_app(' ');
REDUCE(pp,4,read_hd,0,9960);
}
else if(cat1==expr&&cat2==comma)
{
b_app1(pp);
b_app(' ');
b_app2(pp+1);
b_app(' ');
REDUCE(pp,3,read_hd,0,9961);
}
else if(cat1==expr||cat1==unorbinop)
{
b_app1(pp);b_app(' ');b_app1(pp+1);

if(cat2==expr)b_app(' ');

REDUCE(pp,2,read_hd,0,9962);
}
else if(cat1==semi)SQUASH(pp,1,read_hd,0,9963);


/* :399 */
#line 5407 "./prod.web"

#endif

/* :397 */
#line 3490 "./prod.web"
break;
case read_hd:/* 400: */
#line 5450 "./prod.web"

#if FCN_CALLS
R_rd_hd();
#else
/* 402: */
#line 5467 "./prod.web"

if(cat1==comma)
{
b_app2(pp);
b_app(' ');
REDUCE(pp,2,read_hd,0,9965);
}
else if(cat1==expr)
{
if(cat2==comma||cat2==semi)
SQUASH(pp,2,read_hd,0,9966);
}
else if(cat1==semi&&cat2==read_like)
{
b_app1(pp);
/* :402 */
/* 402: */
#line 5485 "./prod.web"
b_app1(pp+1);
b_app(force);
b_app1(pp+2);
REDUCE(pp,3,read_like,0,9967);
}
else if(cat1==semi)
{
b_app1(pp);
/* :402 */
/* 402: */
#line 5496 "./prod.web"
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,9968);
}

/* :402 */
#line 5454 "./prod.web"

#endif

/* :400 */
#line 3491 "./prod.web"
break;
case entry_like:/* 413: */
#line 5618 "./prod.web"

#if FCN_CALLS
R_entry_like();
#else
/* 415: */
#line 5635 "./prod.web"

if(cat1==expr&&cat2==semi)
{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(' ');b_app2(pp+1);b_app(force);
REDUCE(pp,3,stmt,-2,9990);
}
else if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{
b_app(big_force);
b_app(backup);b_app2(pp);b_app(force);

containing++;
#if(0)
b_app(indent);
#endif
REDUCE(pp,2,stmt,-2,9991);
}

/* :415 */
#line 5622 "./prod.web"

#endif

/* :413 */
#line 3492 "./prod.web"
break;
case implicit_like:/* 403: */
#line 5504 "./prod.web"

#if FCN_CALLS
R_implicit_like();
#else
/* 405: */
#line 5521 "./prod.web"

if(cat1==int_like||cat1==expr)

{
b_app1(pp);
b_app(' ');
b_app(indent);
REDUCE(pp,1,implicit_hd,0,9970);
}
else if(cat1==semi)
{
b_app1(pp);
b_app(indent);
REDUCE(pp,1,implicit_hd,0,99700);
}

/* :405 */
#line 5508 "./prod.web"

#endif

/* :403 */
#line 3493 "./prod.web"
break;
case implicit_hd:/* 406: */
#line 5538 "./prod.web"

#if FCN_CALLS
R_imp_hd();
#else
/* 408: */
#line 5555 "./prod.web"

if(cat1==unorbinop&&cat2==expr)
{
b_app1(pp);
b_app('{');b_app2(pp+1);b_app('}');
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5560 "./prod.web"
;
REDUCE(pp,3,implicit_hd,0,9971);
}
else if(cat1==expr)SQUASH(pp,2,implicit_hd,0,9972);

else if(cat1==comma||cat1==int_like)
{
b_app2(pp);

if(cat2!=unorbinop)
if(cat2==int_like)b_app(' ');

else/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5572 "./prod.web"
;

REDUCE(pp,2,implicit_hd,0,9973);
}
else if(cat1==semi)SQUASH(pp,1,decl_hd,0,9974);


/* :408 */
#line 5542 "./prod.web"

#endif

/* :406 */
#line 3494 "./prod.web"
break;
case assign_like:/* 409: */
#line 5580 "./prod.web"

#if FCN_CALLS
R_assign_like();
#else
/* 411: */
#line 5597 "./prod.web"

if(cat1==expr&&cat2==built_in&&cat3==expr)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
b_app(' ');
b_app1(pp+2);
b_app(' ');
b_app1(pp+3);
REDUCE(pp,4,expr,0,9980);
}

/* :411 */
#line 5584 "./prod.web"

#endif

/* :409 */
#line 3495 "./prod.web"
break;
case define_like:/* 416: */
#line 5655 "./prod.web"

#if FCN_CALLS
R_define_like();
#else
/* 418: */
#line 5672 "./prod.web"

if(cat1==expr)
{
b_app(force);
b_app(backup);b_app2(pp);b_app(force);
REDUCE(pp,2,ignore_scrap,-1,9995);
}

/* :418 */
#line 5659 "./prod.web"

#endif

/* :416 */
#line 3496 "./prod.web"
break;
case built_in:/* 422: */
#line 5708 "./prod.web"

#if FCN_CALLS
R_built_in();
#else
/* 424: */
#line 5725 "./prod.web"

{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5728 "./prod.web"
;
REDUCE(pp,1,expr,-2,9998);
}

/* :424 */
#line 5712 "./prod.web"

#endif

/* :422 */
#line 3497 "./prod.web"
break;
case no_order:/* 419: */
#line 5683 "./prod.web"

#if FCN_CALLS
R_no_order();
#else
/* 421: */
#line 5700 "./prod.web"

intermingle= YES;
b_app(force);
b_app1(pp);b_app(' ');
REDUCE(pp,1,int_like,0,9996);


/* :421 */
#line 5687 "./prod.web"

#endif

/* :419 */
#line 3498 "./prod.web"
break;
case newline:/* 425: */
#line 5733 "./prod.web"

#if FCN_CALLS
R_newline();
#else
/* 427: */
#line 5750 "./prod.web"

SQUASH(pp,1,ignore_scrap,-1,9999);

/* :427 */
#line 5737 "./prod.web"

#endif

/* :425 */
#line 3499 "./prod.web"
break;
case COMMA:/* 84: */
#line 1106 "./prod.web"

#if FCN_CALLS
C_COMMA();
#else
/* 86: */
#line 1123 "./prod.web"

{
/* 77: */
#line 1053 "./prod.web"


APP_SPACE;b_app1(pp);APP_SPACE;

/* :77 */
#line 1125 "./prod.web"
;
REDUCE(pp,1,comma,-1,4445);
}

/* :86 */
#line 1110 "./prod.web"

#endif

/* :84 */
#line 3500 "./prod.web"
break;

}
}

/* :265 */
/* 267: */
#line 3514 "./prod.web"

#if FCN_CALLS
SRTN R_expr(VOID)
{
/* 268: */
#line 3523 "./prod.web"

{
if(cat1==unop)SQUASH(pp,2,expr,-2,2);
else if((cat1==binop||cat1==unorbinop||cat1==colon)&&cat2==expr)

if(cat1==colon&&(*pp->trans)[1]==(sixteen_bits)'#')
{
b_app1(pp);
APP_STR("\\Colon");
b_app1(pp+2);
REDUCE(pp,3,expr,-2,3333);
}
else if(cat1==binop&&**(pp+1)->trans==(sixteen_bits)'/')
SQUASH(pp,1,expr,PLUS 1,3334);
else
SQUASH(pp,3,expr,-2,3);

else if(cat1==comma&&(cat2==expr||cat2==end_like))
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,expr,-2,4);
}
else if(cat1==expr)SQUASH(pp,2,expr,-2,5);
else if(cat1==semi)SQUASH(pp,2,stmt,-2,6);
else if(cat1==colon&&cat2==unorbinop&&
(cat3==rpar||(active_brackets&&cat3==rbracket)))
SQUASH(pp,3,expr,-2,299);
else if(cat1==colon&&cat2!=lpar)
{
make_underlined(pp);SQUASH(pp,2,tag,0,7);
}
else if(cat1==comma&&cat2==int_like)
{
b_app2(pp);
OPT9;
b_app1(pp+2);REDUCE(pp,3,int_like,-2,4444);
}
}

/* :268 */
#line 3518 "./prod.web"

}
#endif

/* :267 */
/* 270: */
#line 3572 "./prod.web"

#if FCN_CALLS
SRTN R_key_wd(VOID)
{
/* 271: */
#line 3581 "./prod.web"

{
SQUASH(pp,1,expr,-2,4445);
}

/* :271 */
#line 3576 "./prod.web"

}
#endif

/* :270 */
/* 273: */
#line 3598 "./prod.web"

#if FCN_CALLS
SRTN R_exp_op(VOID)
{
/* 274: */
#line 3607 "./prod.web"

{
if(cat1==lpar)SQUASH(pp,1,exp_op,PLUS 1,2995);
else if(cat1==expr)
if(cat2==lpar)SQUASH(pp,1,exp_op,PLUS 2,2996);

else if(cat2==expr)SQUASH(pp,1,exp_op,PLUS 1,2997);

else
{

b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
REDUCE(pp,2,expr,-1,2998);
}
}

/* :274 */
#line 3602 "./prod.web"

}
#endif

/* :273 */
/* 277: */
#line 3639 "./prod.web"

#if FCN_CALLS
SRTN R_program_like(VOID)
{
/* 278: */
#line 3648 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==expr&&cat2==semi)
{
fcn_level++;
b_app1(pp);b_app(' ');
b_app(indent);b_app2(pp+1);b_app(outdent);
defined_at(make_underlined(pp+1));
REDUCE(pp,3,fcn_hd,-1,2999);
}
else if(cat1==no_order)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,program_like,0,2997);
}
else if(cat1==semi)
{
fcn_level++;
b_app1(pp);
REDUCE(pp,2,fcn_hd,-1,2996);
}
else if(cat1==proc_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,int_like,0,2887);
}
}
else
{
fcn_level++;
SQUASH(pp,1,int_like,-1,2998);
}

/* :278 */
#line 3643 "./prod.web"

}
#endif

/* :277 */
/* 280: */
#line 3692 "./prod.web"

#if FCN_CALLS
SRTN R_fcn_hd(VOID)
{
/* 281: */
#line 3701 "./prod.web"

{
if(cat1==END_stmt)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,functn,-1,7172);
}
else if(cat1==stmt&&cat2==END_stmt)
{
b_app1(pp);b_app(force);
b_app(indent);
b_app1(pp+1);

if(fcn_level==0)
{
if(containing)
b_app(big_force);

while(containing)
{
#if(0)
b_app(outdent);
#endif
containing--;
}
}

b_app(outdent);
b_app(force);

b_app1(pp+2);
REDUCE(pp,3,functn,-1,7171);
}
}

/* :281 */
#line 3696 "./prod.web"

}
#endif

/* :280 */
/* 283: */
#line 3746 "./prod.web"

#if FCN_CALLS
SRTN R_proc_like(VOID)
{
/* 284: */
#line 3755 "./prod.web"


if(fcn_level==0){}
else fcn_level--;

SQUASH(pp,1,int_like,-1,2989);

/* :284 */
#line 3750 "./prod.web"

}
#endif

/* :283 */
/* 286: */
#line 3772 "./prod.web"

#if FCN_CALLS
SRTN R_private_like(VOID)
{
/* 287: */
#line 3781 "./prod.web"

{
if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{
app(backup);
b_app2(pp);
REDUCE(pp,2,decl,-1,2988);
}
else SQUASH(pp,1,int_like,-2,2987);
}

/* :287 */
#line 3776 "./prod.web"

}
#endif

/* :286 */
/* 289: */
#line 3801 "./prod.web"

#if FCN_CALLS
SRTN R_int_like(VOID)
{
/* 290: */
#line 3810 "./prod.web"

{
if(cat1==lbrace)
{
b_app(indent);
b_app1(pp);
REDUCE(pp,1,decl_hd,0,940);
}
else if(cat1==unorbinop&&cat2==expr)
{
b_app1(pp);
b_app('{');b_app2(pp+1);b_app('}');
REDUCE(pp,3,int_like,-1,941);
}
else if(cat1==int_like||cat1==no_order)


{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,cat0,0,40);
}
else if(cat1==comma)
SQUASH(pp,2,int_like,0,9001);
else if(cat1==binop)
{
b_app2(pp);
b_app(indent);
REDUCE(pp,2,decl_hd,0,9002);
}
else if(cat1==slashes)
{
b_app1(pp);
b_app(' ');
b_app(indent);
REDUCE(pp,1,decl_hd,0,9002);
}
else if(cat1==expr&&**indirect((pp+1)->trans)=='(')
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 3848 "./prod.web"
b_app1(pp+1);
REDUCE(pp,2,int_like,0,9003);
}
else if(cat1==expr||cat1==semi)
{
b_app1(pp);

if(cat1!=semi)app('~');

b_app(indent);

REDUCE(pp,1,decl_hd,0,41);
}
else if(cat1==rbrace)
SQUASH(pp,1,decl,-1,411);

}

/* :290 */
#line 3805 "./prod.web"

}
#endif

/* :289 */
/* 292: */
#line 3875 "./prod.web"

#if FCN_CALLS
SRTN R_struct_like(VOID)
{
/* 293: */
#line 3884 "./prod.web"

if(cat1==lpar)
{
b_app1(pp);
#if(0)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 3889 "./prod.web"

#endif
REDUCE(pp,1,int_like,0,9075);

}
else if(cat1==comma&&cat2==int_like)
{
b_app2(pp);b_app(' ');b_app1(pp+2);
REDUCE(pp,3,struct_like,0,90750);
}
else if(cat1==binop&&**(pp+1)->trans!=(sixteen_bits)'/')
SQUASH(pp,2,struct_like,0,90751);

else if(cat1==expr||cat1==slashes||cat1==struct_like)
{

b_app1(pp);b_app(' ');b_app1(pp+1);
make_underlined(pp+1);
REDUCE(pp,2,language==FORTRAN_90?struct_hd:struct_like,0,9076);
}
else if(cat1==semi)
SQUASH(pp,1,struct_hd,0,9077);
else if(cat1==lbrace)
{
b_app1(pp);indent_force;
b_app1(pp+1);REDUCE(pp,2,struct_hd,0,100);
}

/* :293 */
#line 3879 "./prod.web"

}
#endif

/* :292 */
/* 295: */
#line 3926 "./prod.web"

#if FCN_CALLS
SRTN R_str_hd(VOID)
{
/* 296: */
#line 3935 "./prod.web"

if(is_FORTRAN_(language))
{
if(cat1==expr)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 3940 "./prod.web"
b_app1(pp+1);

REDUCE(pp,2,struct_hd,0,90760);
}
else if(cat1==semi)
{
fcn_level++;
b_app2(pp);
b_app(indent);
REDUCE(pp,2,struct_hd,0,90770);
}
else if(cat1==decl||cat1==functn)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,struct_hd,0,9078);
}
else if(cat1==END_stmt)
{
b_app1(pp);
b_app(outdent);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,9079);
}
}
else/* 164: */
#line 2307 "./prod.web"

{
if((cat1==decl||cat1==stmt
||cat1==expr
||cat1==functn
)&&cat2==rbrace)
{
b_app1(pp);
/* 182: */
#line 2528 "./prod.web"

{
/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2530 "./prod.web"


b_app1(pp+1);

/* 177: */
#line 2466 "./prod.web"

{
if(kill_nl)
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2469 "./prod.web"

else
b_app(force);
}

/* :177 */
#line 2534 "./prod.web"


kill_nl= NO;
}

/* :182 */
#line 2315 "./prod.web"

b_app1(pp+2);
b_app(outdent);
/* :164 */
/* 164: */
#line 2321 "./prod.web"
REDUCE(pp,3,int_like,-1,110);
}
else if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2325 "./prod.web"
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,int_like,-1,1101);
}
}

/* :164 */
#line 3967 "./prod.web"


/* :296 */
#line 3930 "./prod.web"

}
#endif

/* :295 */
/* 298: */
#line 3978 "./prod.web"

#if FCN_CALLS
SRTN R_op_like(VOID)
{
/* 299: */
#line 3987 "./prod.web"

{
short n;

if(cat1==lpar)
{

scrap_pointer q;
int k;



for(q= pp+2;q<=scrp_ptr&&q-pp<MAX_OP_TOKENS;q++)
if(q->cat==rpar)break;

n= (q->cat==rpar)?PTR_DIFF(short,q,pp):0;

if(n>0)
{
b_app1(pp);b_app(' ');
b_app1(pp+1);
b_app('{');
APP_STR("\\optrue");

for(k= 2;k<n;k++)
b_app1(pp+k);

APP_STR("\\opfalse");

b_app('}');
b_app1(pp+k);

REDUCE(pp,n+1,expr,-2,6667);
}
}
}

/* :299 */
#line 3982 "./prod.web"

}
#endif

/* :298 */
/* 301: */
#line 4033 "./prod.web"

#if FCN_CALLS
SRTN R_dcl_hd(VOID)
{
/* 302: */
#line 4042 "./prod.web"

if(cat1==comma)
{
b_app2(pp);b_app(' ');REDUCE(pp,2,decl_hd,0,54);
}
else if(cat1==expr)
{
make_underlined(pp+1);

if(**(pp+2)->trans==(sixteen_bits)'=')
{
SQUASH(pp,1,decl_hd,PLUS 1,55);
}
else
{
SQUASH(pp,2,decl_hd,0,56);
}
}
else if(cat1==slashes)
{
SQUASH(pp,2,decl_hd,0,57);
}
/* :302 */
/* 302: */
#line 4071 "./prod.web"
else if(cat1==lbrace||cat1==int_like||cat1==implicit_like)


{
b_app1(pp);
b_app(outdent);
defined_at(FIRST_ID(pp));
REDUCE(pp,1,fn_decl,0,58);
}
else if(cat1==semi&&(!auto_semi||(auto_semi&&cat2!=lbrace)))
{
b_app2(pp);
b_app(outdent);
REDUCE(pp,2,
(eight_bits)(intermingle?(intermingle= NO,ignore_scrap):decl),
-1,59);
}
else if(cat1==built_in)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,decl_hd,0,5901);
}
#if(0)
else if(cat1==lpar&&cat2==expr)make_underlined(pp+2);

#endif

/* :302 */
#line 4037 "./prod.web"

}
#endif

/* :301 */
/* 304: */
#line 4107 "./prod.web"

#if FCN_CALLS
SRTN R_decl(VOID)
{
/* 305: */
#line 4116 "./prod.web"

if(is_FORTRAN_(language)&&cat1==END_like)SQUASH(pp,1,stmt,-1,960);

else if(cat1==decl)
{
b_app1(pp);b_app(force);
b_app1(pp+1);
REDUCE(pp,2,decl,-1,60);
}
else if(cat1==stmt||cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,-1,61);
}

/* :305 */
#line 4111 "./prod.web"

}
#endif

/* :304 */
/* 307: */
#line 4140 "./prod.web"

#if FCN_CALLS
SRTN R_functn(VOID)
{
/* 308: */
#line 4149 "./prod.web"


if(cat1==functn||(is_RATFOR_(language)&&(cat1==decl||cat1==stmt)))
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);REDUCE(pp,2,cat1,0,80);
}
else if(free_Fortran&&cat1==semi)
{
b_app2(pp);
REDUCE(pp,2,functn,0,8088);
}
#if(0)
else if(cat1==END_like)
{
b_app1(pp);
REDUCE(pp,1,stmt,-1,9050);
}
#endif

/* :308 */
#line 4144 "./prod.web"

}
#endif

/* :307 */
/* 310: */
#line 4178 "./prod.web"

#if FCN_CALLS
SRTN R_lpar(VOID)
{
/* 311: */
#line 4187 "./prod.web"


if(cat1==expr&&cat2==rpar)
SQUASH(pp,3,expr,-2,120);
else if(cat1==expr&&cat2==colon&&cat3==rpar)
{
b_app3(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4193 "./prod.web"
;b_app1(pp+3);
REDUCE(pp,4,expr,-2,9120);
}
else if(cat1==colon&&cat2!=comma)

{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4199 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,lpar,0,9121);
}
else if(cat1==rpar)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4204 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,expr,-2,121);
}
else if(cat1==stmt)
{
b_app2(pp);b_app(' ');REDUCE(pp,2,lpar,0,123);
}

/* :311 */
#line 4182 "./prod.web"

}
#endif

/* :310 */
/* 313: */
#line 4221 "./prod.web"

#if FCN_CALLS
SRTN R_colon(VOID)
{
/* 314: */
#line 4230 "./prod.web"


if(cat1==expr||cat1==unorbinop)
SQUASH(pp,2,expr,-2,9500);
else if(cat1==comma&&cat2==colon)
SQUASH(pp,3,colon,-2,9502);


else
SQUASH(pp,1,expr,0,9501);

/* :314 */
#line 4225 "./prod.web"

}
#endif

/* :313 */
/* 316: */
#line 4250 "./prod.web"

#if FCN_CALLS
SRTN R_lbrace(VOID)
{
/* 317: */
#line 4259 "./prod.web"

if(cat1==rbrace)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4262 "./prod.web"
;b_app1(pp+1);
REDUCE(pp,2,stmt,-2,130);
}
else if((cat1==stmt||cat1==decl)&&cat2==rbrace)
{
b_app(force);
b_app1(pp);b_app(force);
b_app1(pp+1);b_app(force);
b_app1(pp+2);
REDUCE(pp,3,stmt,-2,131);
}

/* :317 */
#line 4254 "./prod.web"

}
#endif

/* :316 */
/* 319: */
#line 4283 "./prod.web"

#if FCN_CALLS
SRTN R_unop(VOID)
{
/* 320: */
#line 4292 "./prod.web"


if(cat1==expr)SQUASH(pp,2,expr,-2,33);

/* :320 */
#line 4287 "./prod.web"

}
#endif

/* :319 */
/* 322: */
#line 4305 "./prod.web"

#if FCN_CALLS
SRTN R_unorbinop(VOID)
{
/* 323: */
#line 4314 "./prod.web"


if(cat1==expr)
{
b_app('{');b_app1(pp);b_app('}');
b_app1(pp+1);
REDUCE(pp,2,expr,-2,140);
}
else if(cat1==binop)
/* 189: */
#line 2599 "./prod.web"

{
b_app(math_bin);
b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,151);
}

/* :189 */
#line 4323 "./prod.web"

else if(cat1==comma||cat1==rpar)
SQUASH(pp,1,expr,-2,141);

/* :323 */
#line 4309 "./prod.web"

}
#endif

/* :322 */
/* 327: */
#line 4348 "./prod.web"

#if FCN_CALLS
SRTN R_slash_like(VOID)
{
/* 328: */
#line 4357 "./prod.web"

if(cat1==slash_like)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4361 "./prod.web"
;
b_app1(pp+1);
REDUCE(pp,2,slashes,-1,1801);
}
else if(cat1==expr&&cat2==slash_like)
SQUASH(pp,3,slashes,-1,1802);

/* :328 */
#line 4352 "./prod.web"

}
#endif

/* :327 */
/* 330: */
#line 4377 "./prod.web"

#if FCN_CALLS
SRTN R_binop(VOID)
{
/* 331: */
#line 4386 "./prod.web"

{
sixteen_bits tok= **pp->trans;

if(cat1==binop)
{
if(tok==(sixteen_bits)'/')
{
if(**(pp+1)->trans==tok)
/* 332: */
#line 4421 "./prod.web"

{
b_app('{');
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4424 "./prod.web"
;b_app1(pp+1);
b_app('}');
REDUCE(pp,2,slashes,-1,180);
}

/* :332 */
#line 4395 "./prod.web"

else
{
APP_STR("\\WSl");
REDUCE(pp,1,binop,-1,1803);
}
}
else
/* 199: */
#line 2699 "./prod.web"

{
b_app(math_bin);b_app1(pp);
b_app('{');b_app1(pp+1);b_app('}');
b_app('}');
REDUCE(pp,2,binop,-1,180);
}

/* :199 */
#line 4403 "./prod.web"

}
else
{
if(tok==(sixteen_bits)'/')
{
if(cat1==expr&&cat2==binop&&**(pp+2)->trans==tok)
/* 333: */
#line 4430 "./prod.web"

{
#if 0
b_app('{');
b_app1(pp);
b_app('}');
#endif

make_underlined(pp+1);
APP_STR("\\WCMN");
b_app1(pp+1);

#if 0
b_app('{');
b_app1(pp+2);
b_app('}');
#endif

REDUCE(pp,3,slashes,-1,9181);
}

/* :333 */
#line 4410 "./prod.web"

else
{
APP_STR("\\WSl");
REDUCE(pp,1,binop,-1,1804);
}
}
}
}

/* :331 */
#line 4381 "./prod.web"

}
#endif

/* :330 */
/* 335: */
#line 4458 "./prod.web"


text_pointer
indirect FCN((t))
text_pointer t C1("")
{
Token tok_value;

if(t==NULL)return t;

tok_value= **t;

if(tok_value<=tok_flag)return t;

if(tok_value>inner_tok_flag)tok_value-= (inner_tok_flag-tok_flag);

if(tok_value>tok_flag)
do
{
Token tok_value0= tok_value;

t= tok_start+(int)(tok_value-tok_flag);
tok_value= **t;

if(tok_value==tok_value0)return t;

}
while(tok_value>tok_flag);

return t;
}

/* :335 */
/* 336: */
#line 4492 "./prod.web"

boolean
compare_text FCN((t0,t1))
text_pointer t0 C0("")
text_pointer t1 C1("")
{
token_pointer p0,p0_end,p1;

if(t0==NULL||t1==NULL)return NO;

t0= indirect(t0);t1= indirect(t1);

p0= *t0;p0_end= *(t0+1);
p1= *t1;

while(p0<p0_end)
{
if(*p0==':')return YES;
if(*p0++!=*p1++)return NO;
}

return YES;
}

/* :336 */
/* 337: */
#line 4517 "./prod.web"

sixteen_bits
tok_val FCN((p))
scrap_pointer p C1("")
{
sixteen_bits tok_value;

tok_value= **(p->trans);

if(tok_value>inner_tok_flag)
tok_value-= (inner_tok_flag-tok_flag);

if(tok_value>tok_flag)
do
{
tok_value= **(tok_start+(int)(tok_value-tok_flag));
}
while(tok_value>tok_flag);

return tok_value;
}

/* :337 */
/* 339: */
#line 4548 "./prod.web"

#if FCN_CALLS
SRTN R_Rdo_like(VOID)
{
/* 340: */
#line 4557 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==for_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,Rdo_like,0,9600);
}
else if(cat1==expr&&((cat2==expr&&cat3==binop)||cat2==if_like))
{
label_text_ptr[indent_level]= (pp+1)->trans;

b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,Rdo_like,0,9601);
}
else if(cat1==stmt)
{
loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);
b_app(' ');
b_app1(pp+1);
app_loop_num(max_loop_num);

b_app(indent);
REDUCE(pp,2,stmt,-2,9602);
}
}

else if(cat1==stmt||(cat1==expr&&cat2==lbrace))

{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,for_hd,0,9603);
}

/* :340 */
#line 4552 "./prod.web"

}
#endif

/* :339 */
/* 343: */
#line 4613 "./prod.web"

#if FCN_CALLS
SRTN R_do_like(VOID)
{
/* 344: */
#line 4622 "./prod.web"


if(cat1==stmt)
{
if(cat2==until_like)
{
found_until= YES;
SQUASH(pp,1,do_like,PLUS 2,9190);

}
else
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
b_app(force);

if(found_until&&cat2==stmt)

{
found_until= NO;
b_app1(pp+2);REDUCE(pp,3,stmt,-2,9191);
}
else REDUCE(pp,2,stmt,-2,9192);

}
}

/* :344 */
#line 4617 "./prod.web"

}
#endif

/* :343 */
/* 346: */
#line 4660 "./prod.web"

#if FCN_CALLS
SRTN R_until_like(VOID)
{
/* 347: */
#line 4669 "./prod.web"


SQUASH(pp,1,for_like,0,9195);

/* :347 */
#line 4664 "./prod.web"

}
#endif

/* :346 */
/* 350: */
#line 4688 "./prod.web"

#if FCN_CALLS
SRTN R_if_like(VOID)
{
/* 351: */
#line 4697 "./prod.web"


if(cat1==CASE_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,if_like,0,9196);
}
else
if(is_FORTRAN_(language))
{
if(cat1==expr)
{
boolean if_form;

if((if_form= BOOLEAN(cat2==built_in&&cat3==semi))||cat2==semi)
{
short n;


loop_num[indent_level++]= ++max_loop_num;

b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4719 "./prod.web"
;
b_app1(pp+1);
b_app(' ');

if(if_form)
{
n= 4;
b_app2(pp+2);
}
else
{
n= 3;
b_app1(pp+2);
}

app_loop_num(max_loop_num);
b_app(indent);
REDUCE(pp,n,stmt,-2,9800);
}
else if(cat2==stmt)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4741 "./prod.web"
;
b_app1(pp+1);
app(' ');
b_app(cancel);
b_app1(pp+2);
REDUCE(pp,3,stmt,-2,9801);
}
else
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 4751 "./prod.web"
;
b_app1(pp+1);
REDUCE(pp,2,if_hd,0,9802);
}
}
}

else/* 214: */
#line 2869 "./prod.web"

{
if(cat1==lpar&&cat2==expr&&cat3==rpar)
{
b_app1(pp);/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 2873 "./prod.web"
;b_app3(pp+1);
#if(0)
cmnt_after_IF= (cat4==ignore_scrap);
#endif
REDUCE(pp,4,IF_like,0,220);
}
}

/* :214 */
#line 4758 "./prod.web"



/* :351 */
#line 4692 "./prod.web"

}
#endif

/* :350 */
/* 352: */
#line 4763 "./prod.web"


SRTN
app_loop_num FCN((n))
int n C1("Loop number.")
{
char loop_id[100];

if(!block_nums)return;

sprintf(loop_id,"\\Wblock{%d}",n);

APP_STR(loop_id);
}

/* :352 */
/* 354: */
#line 4787 "./prod.web"

#if FCN_CALLS
SRTN R_go_like(VOID)
{
/* 355: */
#line 4796 "./prod.web"


if(cat1==built_in)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,case_like,0,9850);
}
else SQUASH(pp,1,expr,-2,9851);

/* :355 */
#line 4791 "./prod.web"

}
#endif

/* :354 */
/* 357: */
#line 4817 "./prod.web"

#if FCN_CALLS
SRTN R_end_like(VOID)
{
/* 358: */
#line 4826 "./prod.web"

if(cat1==Rdo_like||cat1==if_like)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,endif_like,0,9860);

}
else
{
fcn_level--;
SQUASH(pp,1,END_like,-1,9861);
}

/* :358 */
#line 4821 "./prod.web"

}
#endif

/* :357 */
/* 360: */
#line 4851 "./prod.web"

#if FCN_CALLS
SRTN R_END(VOID)
{
/* 361: */
#line 4860 "./prod.web"

{
if(cat1==program_like||cat1==struct_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);

if(cat2==expr)
{
b_app(' ');b_app1(pp+2);
REDUCE(pp,3,END_like,0,9860);
}
else
REDUCE(pp,2,END_like,0,9861);
}
else if(cat1==semi)
SQUASH(pp,2,END_stmt,-2,9862);
}

/* :361 */
#line 4855 "./prod.web"

}
#endif

/* :360 */
/* 363: */
#line 4889 "./prod.web"

#if FCN_CALLS
SRTN R_endif_like(VOID)
{
/* 364: */
#line 4898 "./prod.web"

{
short n;
boolean no_construct_name;

if((no_construct_name= BOOLEAN(cat1==semi))||(cat1==expr&&cat2==semi))
{
b_app(outdent);
b_app(force);

if(no_construct_name)
{
n= 2;
b_app2(pp);
}
else
{
n= 3;
b_app1(pp);b_app(' ');b_app2(pp+1);
}

if(--indent_level<0)
indent_level= 0;

app_loop_num(loop_num[indent_level]);
REDUCE(pp,n,stmt,-2,9880);
}
}

/* :364 */
#line 4893 "./prod.web"

}
#endif

/* :363 */
/* 366: */
#line 4936 "./prod.web"

#if FCN_CALLS
SRTN R_if_hd(VOID)
{
/* 367: */
#line 4945 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==stmt)
{
#if 0
b_app1(pp);b_app(break_space);b_app1(pp+1);
#endif
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,stmt,-2,9900);
}
}
else
/* 221: */
#line 2949 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
indent_force;
b_app1(pp+1);
b_app(outdent);
REDUCE(pp,2,IF_top,-1,233);
}
else if(cat1==IF_top&&cat2==else_like)
SQUASH(pp,1,if_hd,2,234);
}

/* :221 */
#line 4962 "./prod.web"


/* :367 */
#line 4940 "./prod.web"

}
#endif

/* :366 */
/* 369: */
#line 4973 "./prod.web"

#if FCN_CALLS
SRTN R_else_like(VOID)
{
/* 370: */
#line 4982 "./prod.web"


if(is_FORTRAN_(language))
{
if(cat1==if_like)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,else_like,0,9910);
}
else if(cat1==semi)
{
b_app(outdent);
b_app(force);
b_app2(pp);
app_loop_num(loop_num[indent_level-1]);
b_app(indent);
REDUCE(pp,2,stmt,-2,9911);
}
else if(cat1==expr&&cat2==built_in&&cat3==semi)

{
b_app(outdent);
b_app(force);

b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5009 "./prod.web"
;
b_app1(pp+1);
b_app(' ');
b_app2(pp+2);
app_loop_num(loop_num[indent_level-1]);

b_app(indent);
REDUCE(pp,4,stmt,-2,9912);
}
}

else/* 227: */
#line 3011 "./prod.web"

{
if(cat1==if_like)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,if_like,0,235);
}
else if(cat1==stmt||cat1==lbrace||cat1==for_like||cat1==do_like)
SQUASH(pp,1,else_hd,0,236);
#if 0 
else if(cat1==stmt)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
REDUCE(pp,2,ELSE_like,-1,237);
}
#endif
}

/* :227 */
#line 5020 "./prod.web"


/* :370 */
#line 4977 "./prod.web"

}
#endif

/* :369 */
/* 372: */
#line 5031 "./prod.web"

#if FCN_CALLS
SRTN R_stmt(VOID)
{
/* 373: */
#line 5040 "./prod.web"


/* :373 */
/* 373: */
#line 5077 "./prod.web"
if(cat1==stmt||(free_Fortran&&cat1==decl))
{
b_app1(pp);
b_app(break_space);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,2501);
}
else if(cat1==functn)
{
b_app1(pp);b_app(big_force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,2511);
}

/* :373 */
#line 5035 "./prod.web"

}
#endif

/* :372 */
/* 375: */
#line 5101 "./prod.web"

#if FCN_CALLS
SRTN R_CASE(VOID)
{
/* 376: */
#line 5110 "./prod.web"


if(is_FORTRAN_(language))
{
b_app(backup);
b_app1(pp);
REDUCE(pp,1,case_like,0,9258);
}
else SQUASH(pp,1,case_like,0,9259);

/* :376 */
#line 5105 "./prod.web"

}
#endif

/* :375 */
/* 378: */
#line 5129 "./prod.web"

#if FCN_CALLS
SRTN R_case_like(VOID)
{
/* 379: */
#line 5138 "./prod.web"

if(cat1==read_like)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
REDUCE(pp,2,case_like,0,9260);
}
else if(cat1==semi)SQUASH(pp,2,stmt,-2,260);
else if(cat1==colon)/* 380: */
#line 5161 "./prod.web"

{
b_app1(pp);APP_STR("\\Colon\\ ");
REDUCE(pp,2,tag,-1,261);
}

/* :380 */
#line 5147 "./prod.web"

else if(cat1==expr&&cat2==semi)
{
b_app1(pp);b_app(' ');b_app2(pp+1);
REDUCE(pp,3,stmt,-2,262);
}
else if((cat1==expr||cat1==label)&&cat2==colon)
{
b_app1(pp);b_app(' ');b_app1(pp+1);
APP_STR("\\Colon\\ ");
REDUCE(pp,3,tag,-1,263);
}

/* :379 */
#line 5133 "./prod.web"

}
#endif

/* :378 */
/* 382: */
#line 5176 "./prod.web"

#if FCN_CALLS
SRTN R_tag(VOID)
{
/* 383: */
#line 5185 "./prod.web"


if(cat1==tag)
{
b_app1(pp);b_app(force);
b_app(backup);
b_app1(pp+1);REDUCE(pp,2,tag,-1,270);
}
else if(cat1==stmt||cat1==END_like)
{
boolean end_of_loop;

end_of_loop= NO;


while(indent_level>0&&
compare_text(pp->trans,label_text_ptr[indent_level-1]))
{
--indent_level;
b_app(outdent);
end_of_loop= YES;
}

if(is_FORTRAN_(language)&&Fortran_label)
{
b_app(force);
APP_STR("\\Wlbl{");b_app1(pp);app('}');

}
else
{
b_app(big_force);
b_app(backup);
b_app1(pp);
b_app(force);
}

b_app1(pp+1);

if(end_of_loop)
app_loop_num(loop_num[indent_level]);

REDUCE(pp,2,cat1,-2,271);
}


/* :383 */
#line 5180 "./prod.web"

}
#endif

/* :382 */
/* 385: */
#line 5240 "./prod.web"

#if FCN_CALLS
SRTN R_label(VOID)
{
/* 386: */
#line 5249 "./prod.web"

if(cat1==colon)
{
b_app1(pp);
REDUCE(pp,2,label,0,9270);


}
else if(cat1==stmt||cat1==END_like)
{
b_app1(pp);APP_STR("\\Colon\\ ");

if(is_FORTRAN_(language)&&Fortran_label)
b_app(cancel);

REDUCE(pp,1,tag,0,9271);

}

/* :386 */
#line 5244 "./prod.web"

}
#endif

/* :385 */
/* 388: */
#line 5277 "./prod.web"

#if FCN_CALLS
SRTN R_semi(VOID)
{
/* 389: */
#line 5286 "./prod.web"

if(is_RATFOR_(language)&&auto_semi)
{
text_pointer t;

t= indirect(pp->trans);

if(**t==';')**t= 0;
SQUASH(pp,1,ignore_scrap,-1,9280);
}
else
{
b_app(' ');b_app1(pp);REDUCE(pp,1,stmt,-2,280);
}

/* :389 */
#line 5281 "./prod.web"

}
#endif

/* :388 */
/* 391: */
#line 5310 "./prod.web"

#if FCN_CALLS
SRTN R_common_like(VOID)
{
/* 393: */
#line 5322 "./prod.web"

if(cat1==expr||cat1==slashes||cat1==semi)
{
#if 0
b_app1(pp);
#if 0
if(cat1!=semi)
b_app(' ');
#endif
b_app(indent);
REDUCE(pp,1,common_hd,0,9950);
#endif
SQUASH(pp,1,common_hd,0,9950);
}

/* :393 */
#line 5314 "./prod.web"

}
#endif

/* :391 */
/* 395: */
#line 5346 "./prod.web"

#if FCN_CALLS
SRTN R_cmn_hd(VOID)
{
/* 396: */
#line 5355 "./prod.web"


#if 0
if(cat1==expr)
SQUASH(pp,2,common_hd,0,9951);
else if(cat1==slashes)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
b_app(' ');
REDUCE(pp,2,common_hd,0,9952);
}
else if(cat1==comma)
{
b_app2(pp);
b_app(' ');
REDUCE(pp,2,common_hd,0,9953);
}

if(cat1==expr)
{
b_app1(pp);
OPT9;
b_app1(pp+1);
REDUCE(pp,2,common_hd,0,9951);
}
else if(cat1==slashes)
{
SQUASH(pp,2,common_hd,0,9952);
}
else if(cat1==comma)
{
SQUASH(pp,2,common_hd,0,9953);
}
else if(cat1==semi)
{
b_app2(pp);
b_app(outdent);
REDUCE(pp,2,decl,-1,9954);
}
#endif
if(cat1==slashes)
SQUASH(pp,2,int_like,0,9952);
else
SQUASH(pp,1,int_like,0,9951);

/* :396 */
#line 5350 "./prod.web"

}
#endif

/* :395 */
/* 398: */
#line 5411 "./prod.web"

#if FCN_CALLS
SRTN R_read_like(VOID)
{
/* 399: */
#line 5420 "./prod.web"


if(cat1==lpar&&cat2==expr&&cat3==rpar)
{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5425 "./prod.web"
;
b_app3(pp+1);
b_app(' ');
REDUCE(pp,4,read_hd,0,9960);
}
else if(cat1==expr&&cat2==comma)
{
b_app1(pp);
b_app(' ');
b_app2(pp+1);
b_app(' ');
REDUCE(pp,3,read_hd,0,9961);
}
else if(cat1==expr||cat1==unorbinop)
{
b_app1(pp);b_app(' ');b_app1(pp+1);

if(cat2==expr)b_app(' ');

REDUCE(pp,2,read_hd,0,9962);
}
else if(cat1==semi)SQUASH(pp,1,read_hd,0,9963);


/* :399 */
#line 5415 "./prod.web"

}
#endif

/* :398 */
/* 401: */
#line 5458 "./prod.web"

#if FCN_CALLS
SRTN R_rd_hd(VOID)
{
/* 402: */
#line 5467 "./prod.web"

if(cat1==comma)
{
b_app2(pp);
b_app(' ');
REDUCE(pp,2,read_hd,0,9965);
}
else if(cat1==expr)
{
if(cat2==comma||cat2==semi)
SQUASH(pp,2,read_hd,0,9966);
}
else if(cat1==semi&&cat2==read_like)
{
b_app1(pp);
/* :402 */
/* 402: */
#line 5485 "./prod.web"
b_app1(pp+1);
b_app(force);
b_app1(pp+2);
REDUCE(pp,3,read_like,0,9967);
}
else if(cat1==semi)
{
b_app1(pp);
/* :402 */
/* 402: */
#line 5496 "./prod.web"
b_app1(pp+1);
REDUCE(pp,2,stmt,-2,9968);
}

/* :402 */
#line 5462 "./prod.web"

}
#endif

/* :401 */
/* 404: */
#line 5512 "./prod.web"

#if FCN_CALLS
SRTN R_implicit_like(VOID)
{
/* 405: */
#line 5521 "./prod.web"

if(cat1==int_like||cat1==expr)

{
b_app1(pp);
b_app(' ');
b_app(indent);
REDUCE(pp,1,implicit_hd,0,9970);
}
else if(cat1==semi)
{
b_app1(pp);
b_app(indent);
REDUCE(pp,1,implicit_hd,0,99700);
}

/* :405 */
#line 5516 "./prod.web"

}
#endif

/* :404 */
/* 407: */
#line 5546 "./prod.web"

#if FCN_CALLS
SRTN R_imp_hd(VOID)
{
/* 408: */
#line 5555 "./prod.web"

if(cat1==unorbinop&&cat2==expr)
{
b_app1(pp);
b_app('{');b_app2(pp+1);b_app('}');
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5560 "./prod.web"
;
REDUCE(pp,3,implicit_hd,0,9971);
}
else if(cat1==expr)SQUASH(pp,2,implicit_hd,0,9972);

else if(cat1==comma||cat1==int_like)
{
b_app2(pp);

if(cat2!=unorbinop)
if(cat2==int_like)b_app(' ');

else/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5572 "./prod.web"
;

REDUCE(pp,2,implicit_hd,0,9973);
}
else if(cat1==semi)SQUASH(pp,1,decl_hd,0,9974);


/* :408 */
#line 5550 "./prod.web"

}
#endif

/* :407 */
/* 410: */
#line 5588 "./prod.web"

#if FCN_CALLS
SRTN R_assign_like(VOID)
{
/* 411: */
#line 5597 "./prod.web"

if(cat1==expr&&cat2==built_in&&cat3==expr)
{
b_app1(pp);
b_app(' ');
b_app1(pp+1);
b_app(' ');
b_app1(pp+2);
b_app(' ');
b_app1(pp+3);
REDUCE(pp,4,expr,0,9980);
}

/* :411 */
#line 5592 "./prod.web"

}
#endif

/* :410 */
/* 414: */
#line 5626 "./prod.web"

#if FCN_CALLS
SRTN R_entry_like(VOID)
{
/* 415: */
#line 5635 "./prod.web"

if(cat1==expr&&cat2==semi)
{
b_app(big_force);
b_app(backup);b_app1(pp);b_app(' ');b_app2(pp+1);b_app(force);
REDUCE(pp,3,stmt,-2,9990);
}
else if(cat1==(eight_bits)(language==FORTRAN_90?semi:colon))
{
b_app(big_force);
b_app(backup);b_app2(pp);b_app(force);

containing++;
#if(0)
b_app(indent);
#endif
REDUCE(pp,2,stmt,-2,9991);
}

/* :415 */
#line 5630 "./prod.web"

}
#endif

/* :414 */
/* 417: */
#line 5663 "./prod.web"

#if FCN_CALLS
SRTN R_define_like(VOID)
{
/* 418: */
#line 5672 "./prod.web"

if(cat1==expr)
{
b_app(force);
b_app(backup);b_app2(pp);b_app(force);
REDUCE(pp,2,ignore_scrap,-1,9995);
}

/* :418 */
#line 5667 "./prod.web"

}
#endif

/* :417 */
/* 420: */
#line 5691 "./prod.web"

#if FCN_CALLS
SRTN R_no_order(VOID)
{
/* 421: */
#line 5700 "./prod.web"

intermingle= YES;
b_app(force);
b_app1(pp);b_app(' ');
REDUCE(pp,1,int_like,0,9996);


/* :421 */
#line 5695 "./prod.web"

}
#endif

/* :420 */
/* 423: */
#line 5716 "./prod.web"

#if FCN_CALLS
SRTN R_built_in(VOID)
{
/* 424: */
#line 5725 "./prod.web"

{
b_app1(pp);
/* 324: */
#line 4328 "./prod.web"

{
b_app('\\');b_app(',');
}

/* :324 */
#line 5728 "./prod.web"
;
REDUCE(pp,1,expr,-2,9998);
}

/* :424 */
#line 5720 "./prod.web"

}
#endif

/* :423 */
/* 426: */
#line 5741 "./prod.web"

#if FCN_CALLS
SRTN R_newline(VOID)
{
/* 427: */
#line 5750 "./prod.web"

SQUASH(pp,1,ignore_scrap,-1,9999);

/* :427 */
#line 5745 "./prod.web"

}
#endif

/* :426 */
/* 428: */
#line 5754 "./prod.web"

SRTN
V_productions(VOID)
{
switch(pp->cat)
{
case expr:/* 429: */
#line 5766 "./prod.web"


/* :429 */
#line 5760 "./prod.web"
break;
case stmt:/* 430: */
#line 5769 "./prod.web"


/* :430 */
#line 5761 "./prod.web"
break;
}
}

/* :428 */
/* 431: */
#line 5773 "./prod.web"

SRTN
X_productions(VOID)
{
switch(pp->cat)
{
case expr:/* 432: */
#line 5785 "./prod.web"

{
if(cat1==expr)SQUASH(pp,2,expr,0,5);
else if(cat1==semi)
{
b_app1(pp);
REDUCE(pp,2,stmt,-1,6);
}
}

/* :432 */
#line 5779 "./prod.web"
break;
case stmt:/* 433: */
#line 5796 "./prod.web"

{
if(cat1==stmt)
{
b_app1(pp);
b_app(force);
b_app1(pp+1);
REDUCE(pp,2,stmt,-1,250);
}
}

/* :433 */
#line 5780 "./prod.web"
break;
}
}

/* :431 */
/* 435: */
#line 5816 "./prod.web"

SRTN
reduce FCN((j,k,c,d,n))
scrap_pointer j C0("")
short k C0("Number of items to be reduced.")
eight_bits c C0("Reduce to this type.")
short d C0("Move by this amount.")
RULE_NO n C1("Rule number.")
{
scrap_pointer i,i1;


j->cat= c;j->trans= text_ptr;
j->mathness= (eight_bits)(4*last_mathness+ini_mathness);
freeze_text;



if(k>1)
{
for(i= j+k,i1= j+1;i<=lo_ptr;i++,i1++)
{
i1->cat= i->cat;i1->trans= i->trans;
i1->mathness= i->mathness;
}

lo_ptr= lo_ptr-k+1;
}

/* 436: */
#line 5855 "./prod.web"


if(pp+d>=scrp_base)pp= pp+d;
else pp= scrp_base;

/* :436 */
#line 5845 "./prod.web"
;

#ifdef DEBUG
/* 441: */
#line 5963 "./prod.web"

{
scrap_pointer k;


/* 440: */
#line 5943 "./prod.web"

{
static RULE_NO last_rule= ULONG_MAX;
static int ncycles= 0;

if(n&&n==last_rule)
{
if(ncycles++>MAX_CYCLES)
{

confusion(OC("reduce"),OC("Infinite production loop, rule %lu"),n);
}
}
else
{
last_rule= n;
ncycles= 0;
}
}

/* :440 */
#line 5968 "./prod.web"


if(tracing==VERBOSE)
{
printf("%5lu",n);

if(in_prototype)
printf(".%i",in_prototype);

printf(": ");

for(k= scrp_base;k<=lo_ptr;k++)
{
if(k==pp)
putxchar('*');
else
putxchar(' ');

prn_math(k);
}

if(hi_ptr<=scrp_ptr)printf("...");


/* 443: */
#line 6021 "./prod.web"

{
printf(" ==\"");

if(lo_ptr>scrp_base)
{
prn_trans(lo_ptr-1);
printf("\" \"");
}

prn_trans(lo_ptr);
puts("\"");
}

/* :443 */
#line 5992 "./prod.web"


}
}

/* :441 */
#line 5848 "./prod.web"
;
#endif 

pp--;
}

/* :435 */
/* 437: */
#line 5865 "./prod.web"

SRTN
squash FCN((j,k,c,d,n))
scrap_pointer j C0("")
short k C0("Number to be squashed.")
eight_bits c C0("Make it this type.")
short d C0("Move by this amount.")
RULE_NO n C1("Rule number.")
{
scrap_pointer i;

if(k==1)
{
j->cat= c;/* 436: */
#line 5855 "./prod.web"


if(pp+d>=scrp_base)pp= pp+d;
else pp= scrp_base;

/* :436 */
#line 5878 "./prod.web"
;

#ifdef DEBUG
/* 441: */
#line 5963 "./prod.web"

{
scrap_pointer k;


/* 440: */
#line 5943 "./prod.web"

{
static RULE_NO last_rule= ULONG_MAX;
static int ncycles= 0;

if(n&&n==last_rule)
{
if(ncycles++>MAX_CYCLES)
{

confusion(OC("reduce"),OC("Infinite production loop, rule %lu"),n);
}
}
else
{
last_rule= n;
ncycles= 0;
}
}

/* :440 */
#line 5968 "./prod.web"


if(tracing==VERBOSE)
{
printf("%5lu",n);

if(in_prototype)
printf(".%i",in_prototype);

printf(": ");

for(k= scrp_base;k<=lo_ptr;k++)
{
if(k==pp)
putxchar('*');
else
putxchar(' ');

prn_math(k);
}

if(hi_ptr<=scrp_ptr)printf("...");


/* 443: */
#line 6021 "./prod.web"

{
printf(" ==\"");

if(lo_ptr>scrp_base)
{
prn_trans(lo_ptr-1);
printf("\" \"");
}

prn_trans(lo_ptr);
puts("\"");
}

/* :443 */
#line 5992 "./prod.web"


}
}

/* :441 */
#line 5881 "./prod.web"
;
#endif 

pp--;
return;
}

for(i= j;i<j+k;i++)b_app1(i);

reduce(j,k,c,d,n);
}

/* :437 */
/* 444: */
#line 6048 "./prod.web"

text_pointer
translate FCN((mode0))
PARSING_MODE mode0 C1("")
{
LANGUAGE saved_language= language;
scrap_pointer i,
j;

translate_mode= mode0;

pp= scrp_base;lo_ptr= pp-1;hi_ptr= pp;
/* 447: */
#line 6154 "./prod.web"


#ifdef DEBUG
if(tracing==VERBOSE)
{
CLR_PRINTF(ALWAYS,warning,
("\nTracing after l. %u (language = %s):  ",
cur_line,languages[lan_num(language)]));
mark_harmless;

if(loc>=cur_buffer+OUT_WIDTH)
{
printf("...");
ASCII_write(loc-OUT_WIDTH,OUT_WIDTH);
}
else ASCII_write(cur_buffer,loc-cur_buffer);

puts("");
}
#endif 

/* :447 */
#line 6060 "./prod.web"
;
/* 438: */
#line 5897 "./prod.web"

{
in_prototype= indented= NO;

WHILE()
{
/* 439: */
#line 5928 "./prod.web"


if(lo_ptr<pp+3)
{
while(hi_ptr<=scrp_ptr&&lo_ptr!=pp+3)
{
(++lo_ptr)->cat= hi_ptr->cat;lo_ptr->mathness= (hi_ptr)->mathness;
lo_ptr->trans= (hi_ptr++)->trans;
}

for(i= lo_ptr+1;i<=pp+3;i++)i->cat= 0;
}

/* :439 */
#line 5903 "./prod.web"
;

if(tok_ptr+8>tok_m_end)
{
if(tok_ptr>mx_tok_ptr)mx_tok_ptr= tok_ptr;
OVERFLW("tokens","tw");
}

if(text_ptr+4>tok_end)
{
if(text_ptr>mx_text_ptr)mx_text_ptr= text_ptr;
OVERFLW("texts","x");
}

if(pp>lo_ptr)
break;

/* 60: */
#line 513 "./prod.web"

{
if(cat0==language_scrap)
{
language= lan_enum(get_language(pp->trans));

ini0_language();
SQUASH(pp,1,ignore_scrap,-1,0);
}
else if(cat1==ignore_scrap)SQUASH(pp,2,cat0,-2,0);
#line 524 "./prod.web"
else switch(language)
{
case NO_LANGUAGE:

confusion(OC("match production"),OC("Language hasn't been defined yet"));

case C:
case C_PLUS_PLUS:
C_productions();
break;

case RATFOR:
case RATFOR_90:
if(!RAT_OK("(translate)"))

confusion(OC("match production"),OC("Language shouldn't be Ratfor here"));

case FORTRAN:
case FORTRAN_90:
R_productions();
break;

case LITERAL:
V_productions();
break;

case TEX:
X_productions();
break;

case NUWEB_OFF:
case NUWEB_ON:

confusion(OC("match a production"),OC("Invalid language"));
}

pp++;
}

/* :60 */
#line 5920 "./prod.web"
;
ini_mathness= cur_mathness= last_mathness= maybe_math;
}
}

/* :438 */
#line 6061 "./prod.web"

/* 445: */
#line 6073 "./prod.web"

{
EXTERN int math_flag;

/* 446: */
#line 6128 "./prod.web"


#ifdef DEBUG
{
scrap_pointer scrap0= scrp_base;

while(scrap0->cat==ignore_scrap)scrap0++;

if(lo_ptr>scrap0&&tracing==BRIEF)
{
CLR_PRINTF(ALWAYS,warning,
("\nIrreducible scrap sequence in %s:",
MOD_TRANS(module_count)));
mfree();
mark_harmless;

for(j= scrap0;j<=lo_ptr;j++)
{
printf(" ");prn_cat(j->cat);
}
}
}
#endif 

/* :446 */
#line 6077 "./prod.web"
;

for(j= scrp_base;j<=lo_ptr;j++)
{
if(j!=scrp_base)
app(' ');

if((INI_MATHNESS(j)==yes_math)&&math_flag==NO)
{
app('$');
#ifdef DBGM
app('7');
#endif
}

if((INI_MATHNESS(j)==no_math)&&math_flag==YES)
{
app(' ');

#ifdef DBGM
app('8');
#endif
app('$');
}

app1(j);

if((LAST_MATHNESS(j)==yes_math)&&math_flag==NO)
{
#ifdef DBGM
app('9');
#endif
app('$');
}

if((LAST_MATHNESS(j)==no_math)&&math_flag==YES)
{
app('$');
#ifdef DBGM
app('0');
#endif
app(' ');
}

if(tok_ptr+6>tok_m_end)OVERFLW("tokens","tw");
}

freeze_text;
}

/* :445 */
#line 6062 "./prod.web"
;

language= saved_language;
return text_ptr-1;
}

/* :444 */
#line 34 "./prod.web"

#endif 

#line 1 "./typedefs.hweb"


#line 8 "./formats.hweb"

/* :1 */
/* 43: */
#line 123 "./ccodes.hweb"


#line 94 "./prod.web"

/* :43 */

