#if(0)
  FTANGLE v1.61,\
 created with UNIX on "Friday, September 25, 1998 at 8:02." \
  COMMAND LINE: "./ftangle ./macs -uCONFIG -mCONFIG -mGCC -= macs.c"\
  RUN TIME:     "Friday, November 17, 2017 at 11:29."\
  WEB FILE:     "./macs.web"\
  CHANGE FILE:  (none)
#endif
#define _MACS_h   \

#define stringg  (eight_bits)'\2' \

#define constant  (eight_bits)'\3'
#define begin_Xmeta  or_or
#define end_Xmeta  star_star
#define cdir  (eight_bits)'\6'
#define colon_colon  (eight_bits)'\11' \

#define join  (eight_bits)'\177' \

#define ID0  0200
#define TOKEN1(a)((a)<ID0) \

#define MACRO_ARGUMENT  0377 \

#define BASE2  0400 \

#define MODULE_NAME  10240
#define MODULE_NUM  20480
#define LINE_NUM  53248L \

#define IDENTIFIER(left,right) \
((sixteen_bits)(((left)-ID0)*BASE2+(sixteen_bits)(right))) \
 \

#define LEFT(a,id)((eight_bits)(((a)/BASE2+(id)))) \

#define RIGHT(a)((eight_bits)(((a)%BASE2))) \

#define ignore  0 \

#define begin_comment0  (eight_bits)'\xFE'
#define begin_comment1  (eight_bits)'\xFD' \

#define module_number  (eight_bits)'\201'
#define identifier  (eight_bits)'\202'
#define id_keyword  (eight_bits)'\203' \

#define L_switch  (eight_bits)'\257'
#define begin_FORTRAN  (eight_bits)'\260'
#define begin_RATFOR  (eight_bits)'\261'
#define begin_C  (eight_bits)'\262'
#define begin_LITERAL  (eight_bits)'\263' \

#define verbatim  (eight_bits)'\264' \
 \

#define invisible_cmnt  (eight_bits)'\265'
#define compiler_directive  (eight_bits)'\266'
#define Compiler_Directive  (eight_bits)'\267' \

#define keyword_name  (eight_bits)'\270' \

#define no_index  (eight_bits)'\300'
#define yes_index  (eight_bits)'\301' \

#define ascii_constant  (eight_bits)'\302'
#define begin_vcmnt  (eight_bits)'\303'
#define big_line_break  (eight_bits)'\304' \

#define begin_bp  (eight_bits)'\305'
#define insert_bp  (eight_bits)'\306' \

#define begin_meta  (eight_bits)'\17'
#define end_meta  (eight_bits)'\27' \

#define TeX_string  (eight_bits)'\307'
#define xref_roman  (eight_bits)'\310'
#define xref_typewriter  (eight_bits)'\311'
#define xref_wildcard  (eight_bits)'\312' \

#define control_text  (eight_bits)'\313' \

#define begin_nuweb  (eight_bits)'\314'
#define no_mac_expand  (eight_bits)'\315'
#define set_line_info  (eight_bits)'\316'
#define short_fcn  (eight_bits)'\317' \

#define formatt  (eight_bits)'\320' \

#define limbo_text  (eight_bits)'\323'
#define op_def  (eight_bits)'\324'
#define macro_def  (eight_bits)'\325' \

#define ignore_defn  (eight_bits)'\327' \

#define new_output_file  (eight_bits)'\331' \

#define definition  (eight_bits)'\332'
#define undefinition  (eight_bits)'\333'
#define WEB_definition  (eight_bits)'\334' \

#define m_ifdef  (eight_bits)'\335'
#define m_ifndef  (eight_bits)'\336'
#define m_if  (eight_bits)'\337'
#define m_else  (eight_bits)'\340'
#define m_elif  (eight_bits)'\341'
#define m_endif  (eight_bits)'\342'
#define m_for  (eight_bits)'\343'
#define m_endfor  (eight_bits)'\344'
#define m_line  (eight_bits)'\345'
#define m_undef  (eight_bits)'\346' \

#define end_of_buffer  (eight_bits)'\347' \

#define begin_code  (eight_bits)'\350'
#define module_name  (eight_bits)'\351' \

#define new_module  (eight_bits)'\352' \

#define cur_end  cur_state.end_field
#define cur_byte  cur_state.byte_field
#define cur_name  cur_state.name_field
#define cur_repl  cur_state.repl_field
#define cur_mod  cur_state.mod_field \

#define cur_language  cur_state.language
#define cur_global_language  cur_state.global_params.Language \
 \
 \

#define cur_params  cur_state.params
#define cur_global_params  cur_state.global_params \
 \

#define macrobuf  cur_state.macro_buf
#define cur_mp  cur_state.mp
#define macrobuf_end  cur_state.macro_buf_end \

#define BP_MARKER  1 \

#define PROPER_END(end) \
end= (np+1)->byte_start; \
if(*end==BP_MARKER&&np!=npmax)end= ((BP*)end)->byte_start \

#define MAX_ID_LENGTH  32 \

#define semi  01 \

#define SILENT  (boolean)NO
#define COMPLAIN  (boolean)YES \

#define OUTER_MACRO  0xFF
#define OUTER_UNMACRO  0xFE
#define UNDEFINED_MACRO  0xFD \

#define MAX_XLEVELS  200 \

#define equiv  equiv_or_xref
#define EQUIV  ASCII HUGE* \
 \
 \

#define MAC_LOOKUP(cur_val)(cur_val<MODULE_NAME? \
(text_pointer)(name_dir+(cur_val))->equiv:NULL) \

#define macro  0 \
 \
 \
 \

#define NOT_DEFINED  0
#define DEFERRED_MACRO  1 \

#define IMMEDIATE_MACRO  2
#define FILE_NAME  3 \
 \

#define MCHECK(n,reason)if(mp+(n)>macrobuf_end) \
mbuf_full((unsigned long)(n),(outer_char*)reason) \

#define MAKE_16(start)(((sixteen_bits)(*start)<<8)+(sixteen_bits)(*(start+1))) \

#define TYPE_DESCR_LEN  20 \
 \

#define save_name(a){if(xids->level>=MAX_XLEVELS) \
{ \
 \
macro_err(OC("! Macro inner recursion depth exceeded"),YES); \
 \
fatal(ERR_M,OC("!! BYE."),OC("")); \
} \
xids->token[slevel= xids->level++]= a; \
} \

#define unsave_name  xids->level= slevel \

#define DEFINED_ERR(s){ \
macro_err(OC(s),YES);goto done_expanding;} \

#define ERR_IF_DEFINED_AT_END  if(p>=end) \
DEFINED_ERR("! `defined' ends prematurely") \

#define CUR_QUOTE  ((eight_bits)(single_quote||(!double_quote&&R77_or_F)? \
'\'':'"')) \

#define UNNAMED_MODULE  0
#define CPY_OP(token,trans)case token:cpy_op(OC(trans));break \

#define MUST_QUOTE(name,p,p1)must_quote(OC(name),p,p1) \

#define CHECK_QUOTE(var,n)if(*var++!=end_char) \
macro_err(OC("! Argument %d of \
$TRANSLIT doesn't begin with '%c'"),YES,n,end_char) \

#define N_ENVBUF  200 \

#define SAVE_ENV(aval)if(t<temp_end)*t++= XCHR(aval); \
else OVERFLW("Env_buf","") \

#define DOES_ARG_FOLLOW(c) \
if(*p0!=MACRO_ARGUMENT) \
{ \
 \
macro_err(OC("! Macro token `#%c' must be followed by a parameter"),YES,c); \
break; \
} \
p0++ \

#define INS_ARG_LIST  pargs,m,n,&p0,&pasting,&xpn_argument,last_was_paste \

#define STOP  YES \

#define arg_must_be_constant(name) \
 \
macro_err(OC("Argument of \"%s\" must be constant or string"),YES,name); \

#define MTEXT_SIZE  2500 \

#define SAVE_MTEXT(val)if(p<mtext_end)*p++= (eight_bits)(val); \
else OVERFLW("Mtext","") \

/* 1: */
#line 34 "./macs.web"

/* 33: */
#line 440 "./typedefs.hweb"

#include "typedefs.h"



#line 41 "./macs.web"

#line 8 "./t_codes.hweb"

/* :33 */
/* 45: */
#line 51 "./macs.web"

#include "map.h"

/* :45 */
#line 35 "./macs.web"

/* 37: */
#line 47 "./texts.hweb"


typedef struct
{
eight_bits HUGE*tok_start;

sixteen_bits text_link;
boolean Language;
eight_bits nargs;
unsigned
moffset:8,
recursive:1,
var_args:1,
module_text:1,
built_in:1,
protected:1,
nbytes:19;
}text;

typedef text HUGE*text_pointer;

/* :37 */
/* 39: */
#line 46 "./stacks.hweb"


typedef struct{
eight_bits HUGE*end_field;
eight_bits HUGE*byte_field;
name_pointer name_field;
text_pointer repl_field;
sixteen_bits mod_field;
PARAMS global_params,params;
eight_bits HUGE*macro_buf,HUGE*mp,HUGE*macro_buf_end;

}output_state;

typedef output_state HUGE*stack_pointer;

/* :39 */
/* 41: */
#line 11 "./val.hweb"



typedef enum{BAD_TOKEN,OR_OR,AND_AND,BIT_OR,BIT_XOR,BIT_AND,LOG_EQ,LOG_LT,
BIT_SHIFT,PLUS_MINUS,TIMES,EXP,UNARY,HIGHEST_UNARY}PRECEDENCE;


typedef struct
{
eight_bits token;
PRECEDENCE precedence;
}OP;


typedef union
{
long i;
double d;
sixteen_bits id;
OP op;
}VALUE;



typedef enum{Int,Double,Id,Op}TYPE;



typedef struct val
{
VALUE value;
TYPE type;
struct val HUGE*last,HUGE*next;
}VAL;
#line 8 "./trunc.hweb"

/* :41 */
/* 42: */
#line 19 "./trunc.hweb"


#if(0)
IN_COMMON boolean truncate_ids;
IN_COMMON unsigned short tr_max[];
IN_COMMON name_pointer npmax;
#endif


typedef struct Bp
{
ASCII c;
LANGUAGE Language;
CONST ASCII HUGE*byte_start,HUGE*byte_end;

struct Bp HUGE*next;

struct Trunc HUGE*Root;
}BP;


typedef struct Trunc
{
boolean Language;
size_t num[NUM_LANGUAGES];

ASCII HUGE*id,HUGE*id_end;
BP HUGE*first,HUGE*last;
struct Trunc HUGE*next;
}TRUNC;
#line 47 "./macs.web"

#line 8 "./macs.hweb"

/* :42 */
/* 43: */
#line 49 "./macs.hweb"


typedef struct
{
sixteen_bits token[MAX_XLEVELS];
int level;
}XIDS;

/* :43 */
/* 49: */
#line 87 "./macs.web"


typedef struct
{
const char*name;
int len;
SRTN(*expnd)PROTO((int,unsigned char**));



boolean Language;
eight_bits nargs;
boolean var_args;
boolean recursive;
sixteen_bits id;
}INTERNAL_FCN;

/* :49 */
#line 36 "./macs.web"

/* 46: */
#line 55 "./macs.web"


#include "t_type.h" 

/* :46 */
#line 37 "./macs.web"

/* 32: */
#line 426 "./typedefs.hweb"





#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif



/* :32 */
/* 38: */
#line 69 "./texts.hweb"


EXTERN long max_texts;
EXTERN text HUGE*text_info;
EXTERN text_pointer text_end;

EXTERN long dtexts_max;
EXTERN text HUGE*txt_dinfo;
EXTERN text_pointer textd_end;

EXTERN text_pointer text_ptr,txt_dptr;


EXTERN long max_toks;
EXTERN eight_bits HUGE*tok_mem;
EXTERN eight_bits HUGE*tok_m_end;

EXTERN long max_dtoks;
EXTERN eight_bits HUGE*tok_dmem;
EXTERN eight_bits HUGE*tokd_end;

EXTERN eight_bits HUGE*tok_ptr,HUGE*tok_dptr;

EXTERN eight_bits HUGE*mx_tok_ptr,HUGE*mx_dtok_ptr;


EXTERN text_pointer macro_text;
#line 8 "./stacks.hweb"

/* :38 */
/* 40: */
#line 82 "./stacks.hweb"


EXTERN output_state cur_state;


EXTERN long stck_size;
EXTERN output_state HUGE*stack;
EXTERN stack_pointer stck_end;
EXTERN stack_pointer stck_ptr;
#line 8 "./val.hweb"

/* :40 */
/* 44: */
#line 58 "./macs.hweb"


IN_COMMON STMT_LBL max_stmt;

EXTERN sixteen_bits outp_line[NUM_LANGUAGES]
#ifdef _FTANGLE_h
#if(part == 0 || part == 1)
= {1,1,1,1,1,1,1,1}
#endif 
#endif 
;
#line 49 "./macs.web"

/* :44 */
/* 47: */
#line 61 "./macs.web"


IN_COMMON sixteen_bits HUGE*args;

IN_COMMON BUF_SIZE max_margs;

/* :47 */
/* 50: */
#line 106 "./macs.web"


INTERNAL_FCN internal_fcns[]= {
{"$$ASCII",0,i_ascii_,0xF,1,NO,NO},
{"$ASSERT",0,i_assert_,0xF,1,NO,NO},
{"$$CONST",0,i_const_,0xF,2,YES,NO},
{"$DEFINE",0,i_define_,0xF,1,NO,NO},
{"_DUMPDEF",0,i_dumpdef_,0xF,0,YES,NO},
{"$DUMPDEF",0,i_dumpdef_,0xF,0,YES,NO},
{"$$ERROR",0,i_error_,0xF,1,NO,NO},
{"$$EVAL",0,i_eval_,0xF,1,NO,NO},
{"$$GETENV",0,i_getenv_,0xF,1,NO,NO},
{"$IF",0,i_if_,0xF,3,NO,YES},
{"$IFCASE",0,i_ifcase_,0xF,1,YES,YES},
{"$IFDEF",0,i_ifdef_,0xF,3,NO,YES},
{"$IFNDEF",0,i_ifndef_,0xF,3,NO,YES},
{"$IFELSE",0,i_ifelse_,0xF,4,NO,YES},
{"_INPUT_LINE",0,i_inp_line_,0xF,0,NO,NO},
{"$INPUT_LINE",0,i_inp_line_,0xF,0,NO,NO},
{"$$KEYWORD",0,i_keyword_,0xF,1,NO,NO},
{"_LANGUAGE",0,i_lang_,0xF,0,NO,NO},
{"$LANGUAGE",0,i_lang_,0xF,0,NO,NO},
{"$$LC",0,i_lowercase_,0xF,1,NO,NO},
{"$$LEN",0,i_len_,0xF,1,NO,NO},
{"$$LOG",0,i_log_,0xF,2,NO,NO},
{"_LANGUAGE_NUM",0,i_lnum_,0xF,0,NO,NO},
{"$LANGUAGE_NUM",0,i_lnum_,0xF,0,NO,NO},
{"$M",0,i_define_,0xF,1,NO,NO},
{"$$META",0,i_meta_,0xF,1,NO,NO},
{"$$MIN_MAX",0,i_min_max_,0xF,2,YES,NO},
{"$$MODULE_NAME",0,i_mod_name_,0xF,0,NO,NO},
{"$$MODULES",0,i_modules_,0xF,1,NO,NO},
{"$$NARGS",0,i_nargs_,0xF,1,NO,NO},
{"_OUTPUT_LINE",0,i_outp_line_,0xF,0,NO,NO},
{"$OUTPUT_LINE",0,i_outp_line_,0xF,0,NO,NO},
{"$$ROUTINE",0,i_routine_,RATFOR,0,NO,NO},
{"_SECTION_NUM",0,i_sect_num_,0xF,0,NO,NO},
{"$SECTION_NUM",0,i_sect_num_,0xF,0,NO,NO},
{"$$SWITCH",0,i_switch_,0,0,NO,NO},
{"$$TM",0,i_tm_,0xF,1,NO,NO},
{"$$TRANSLIT",0,i_translit_,0xF,3,NO,NO},
{"$UNDEF",0,i_undef_,0xF,1,NO,NO},
{"$$UNSTRING",0,i_unstring_,0xF,1,NO,NO},
{"$$UC",0,i_uppercase_,0xF,1,NO,NO},
{"$$VERBATIM",0,i_verbatim_,0xF,1,NO,NO},
{"$$VERSION",0,i_version_,0xF,0,NO,NO},
{"_XX",0,i_xflag_,0xF,1,NO,NO},
{"$XX",0,i_xflag_,0xF,1,NO,NO},
{"",0,NULL}
};


SRTN
ini_internal_fcns(VOID)
{
INTERNAL_FCN HUGE*s;
name_pointer np;
text_pointer m;

for(s= internal_fcns;(s->len= STRLEN(s->name))!=0;s++)
{
ASCII HUGE*p= x_to_ASCII(OC(s->name));

s->id= ID_NUM_ptr(np,p,p+s->len);

np->equiv= (ASCII HUGE*)(m= text_ptr++);
np->macro_type= IMMEDIATE_MACRO;

m->tok_start= (eight_bits HUGE*)s->expnd;
m->nbytes= 0;
m->text_link= macro;
m->Language= s->Language;
m->nargs= s->nargs;
m->recursive= s->recursive;
m->var_args= s->var_args;
m->module_text= NO;
m->built_in= YES;
m->protected= YES;
}



text_ptr->tok_start= tok_mem;
}

/* :50 */
/* 52: */
#line 205 "./macs.web"


IN_TANGLE text_pointer cur_text;
IN_TANGLE LINE_NUMBER nearest_line;

/* :52 */
/* 72: */
#line 880 "./macs.web"


XIDS HUGE*pids[MAX_XLEVELS];
int xlevel= 0;

/* :72 */
/* 84: */
#line 1302 "./macs.web"


static boolean keep_intact;
IN_COMMON boolean single_quote,double_quote;

/* :84 */
/* 88: */
#line 1359 "./macs.web"

OUTPUT_STATE copy_state;

/* :88 */
/* 161: */
#line 3388 "./macs.web"


int xflag= 1;

/* :161 */
#line 38 "./macs.web"


#line 1 "./typedefs.hweb"


#line 8 "./formats.hweb"

/* :1 */
/* 48: */
#line 69 "./macs.web"

SRTN
predefine_macros(VOID)
{
new_mbuf();

/* 63: */
#line 661 "./macs.web"


SAVE_MACRO("$DEFINED(macro)$EVAL(defined #!macro)");

/* :63 */
/* 70: */
#line 820 "./macs.web"


SAVE_MACRO("$ABS(a)$IF((a) > 0,$EVAL(a),$EVAL(-(a)))");

/* :70 */
/* 100: */
#line 1634 "./macs.web"


SAVE_MACRO("$STRING(expr)$STRING0(`expr`)");


SAVE_MACRO("$STRING0(expr)#*expr");

/* :100 */
/* 101: */
#line 1642 "./macs.web"


SAVE_MACRO("$LEN(s)$$LEN(#*s)");

/* :101 */
/* 103: */
#line 1671 "./macs.web"


SAVE_MACRO("$VERBATIM(s)$$VERBATIM(s)");

SAVE_MACRO("$UNQUOTE(s)$$VERBATIM(s)");

#line 1678 "./macs.web"
SAVE_MACRO("$P $VERBATIM($IF($LANGUAGE_NUM==2 || $LANGUAGE_NUM==4, \
	'#', \"#\"))");

SAVE_MACRO("$PP $UNSTRING($P)");

/* :103 */
/* 105: */
#line 1747 "./macs.web"


SAVE_MACRO("$UNSTRING(s)$$UNSTRING(s)");

/* :105 */
/* 108: */
#line 1836 "./macs.web"


SAVE_MACRO("$TRANSLIT(s,from,to)$$TRANSLIT(#*s,#*from,#*to)");


/* :108 */
/* 111: */
#line 1923 "./macs.web"


SAVE_MACRO("$GETENV(var)$STRING($$GETENV(#*var))");

SAVE_MACRO("$HOME $GETENV(HOME)");


/* :111 */
/* 143: */
#line 2996 "./macs.web"


SAVE_MACRO("$COMMENT(cmnt)$$META(#*cmnt)");

/* :143 */
/* 149: */
#line 3110 "./macs.web"


SAVE_MACRO("$ERROR(text)$$ERROR(#*text)");

/* :149 */
/* 151: */
#line 3141 "./macs.web"


SAVE_MACRO("$ROUTINE $STRING($$ROUTINE)");

/* :151 */
/* 153: */
#line 3177 "./macs.web"


SAVE_MACRO("$L(name)$$LC(name)");

SAVE_MACRO("$U(name)$$UC(name)");

/* :153 */
/* 155: */
#line 3228 "./macs.web"


SAVE_MACRO("$NARGS(mname)$$NARGS(#!mname)");

/* :155 */
/* 165: */
#line 3542 "./macs.web"


SAVE_MACRO("$KEYWORD(s)$$KEYWORD(#*s)");

SAVE_MACRO("$AUTHOR $KEYWORD(Author)");
SAVE_MACRO("$DATE_TIME $KEYWORD(Date)");
SAVE_MACRO("$HEADER $KEYWORD(Header)");
SAVE_MACRO("$ID $KEYWORD(Id)");
SAVE_MACRO("$LOCKER $KEYWORD(Locker)");
SAVE_MACRO("$NAME $KEYWORD(Name)");
SAVE_MACRO("$RCSFILE $KEYWORD(RCSfile)");
SAVE_MACRO("$REVISION $KEYWORD(Revision)");
SAVE_MACRO("$SOURCE $KEYWORD(Source)");
SAVE_MACRO("$STATE $KEYWORD(State)");

/* :165 */
#line 75 "./macs.web"
;

t_macros();
e_macros();
}

/* :48 */
/* 51: */
#line 196 "./macs.web"

SRTN
new_mbuf(VOID)
{
mp= cur_mp= macrobuf= GET_MEM("macrobuf",mbuf_size,eight_bits);
macrobuf_end= macrobuf+mbuf_size;
}

/* :51 */
/* 53: */
#line 216 "./macs.web"

eight_bits HUGE*
argize FCN((start,end))
eight_bits HUGE*start C0("Beginning of the raw tokens.")
eight_bits HUGE*end C1("End.")
{
eight_bits k,l;
eight_bits HUGE*p,HUGE*last2,HUGE*start0;
boolean var_args;

start0= start;

if(TOKEN1(*start))
{

err0_print(ERR_M,OC("! Macro must start with identifier"),0);

return end;
}



start= get_dargs(start,end,args,&k,&var_args);
cur_text->moffset= (unsigned char)(start-start0);


cur_text->nargs= k;
cur_text->var_args= var_args;


for(last2= p= start;p<end;p++)
{
if(TOKEN1(*p))
switch(*p)
{
case '#':
/* 54: */
#line 289 "./macs.web"

{
int n;
eight_bits HUGE*q= p;
outer_char*tmp;
size_t i;

if(*(p+1)!=constant)continue;

p+= 2;

for(i= 0;p[i]!=constant;i++)
;

tmp= GET_MEM("var arg buf",i+1,outer_char);

for(i= 0;p[i]!=constant;i++)
tmp[i]= XCHR(p[i]);
tmp[i+1]= '\0';

n= ATOI(tmp);



FREE_MEM(tmp,"var arg buf",i+1,outer_char);

if(!var_args)
macro_err(OC("! #%d may only be used with variable-argument \
macros"),YES,n);

while(*p!=constant)*p++= ignore;

if(n<0)
macro_err(OC("! #%d is not allowed"),YES,n);
else if(n==0)
*(q+1)= '0';

else
{
*q= MACRO_ARGUMENT;
*(q+1)= (eight_bits)(k+(eight_bits)(n-1));

}

last2= p;
*p= ignore;
}

/* :54 */
#line 251 "./macs.web"

continue;

case dot_const:
case begin_language:
p++;

default:
continue;
}



if(*p==0320&&*(p+1)==0)
p+= 5;
else
for(l= 0;l<k;++l)


if(args[l]>>8==*p&&(args[l]&0x00FF)==*(p+1))
{
*p= MACRO_ARGUMENT;
*(p+1)= l;

break;
}

last2= ++p;


}

/* 55: */
#line 337 "./macs.web"


for(last2++;p>last2;)
if(*(p-1)=='\n'||*(p-1)==' ')
p--;
else
break;

/* :55 */
#line 283 "./macs.web"
;
return p;
}

/* :53 */
/* 56: */
#line 354 "./macs.web"

eight_bits HUGE*
get_dargs FCN((start,end,args,n,pvar_args))
eight_bits HUGE*start C0("Start of token string.")
eight_bits HUGE*end C0("End of token string.")
sixteen_bits HUGE*args C0("Array of argument tokens, to be returned.")
eight_bits*n C0("Number of arguments found.")
boolean*pvar_args C1("Return whether variable arguments")
{
eight_bits k;
sixteen_bits id_token;

*pvar_args= NO;

id_token= IDENTIFIER(*start,*(start+1));
start+= 2;

*n= 0;

if(start==end)
return end;

if(*start!='(')
{
while(start!=end&&*start==' ')
start++;

return start;
}


for(k= 0,++start;start!=end&&*start!=')';++k)
{
if(TOKEN1(*start))
{
/* 57: */
#line 429 "./macs.web"


if(*start==ellipsis)
{
if(*++start!=')')
err0_print(ERR_M,OC("Expected ')' after ellipsis"),0);
else*pvar_args= YES;

break;
}

/* :57 */
#line 389 "./macs.web"



err0_print(ERR_M,OC("Invalid macro parameter in definition of macro \
\"%s\". Token %s is invalid; \
can only have identifiers and commas between (...)"),2,name_of(id_token),type1(*start));
return start;
}

if(k>=(eight_bits)max_margs)
mac_args(id_token);

args[k]= MAKE_16(start);

start+= 2;


if(*start==',')
start++;
}


*n= k;

if(start==end)
{

err0_print(ERR_M,OC("Missing right paren in definition of macro \"%s\""),1,name_of(id_token));
return end;
}



if(*start==')'&&k==0&&!*pvar_args)
args[k++]= 0;

return start+1;
}

/* :56 */
/* 58: */
#line 440 "./macs.web"

SRTN
mac_args FCN((id_token))
sixteen_bits id_token C1("")
{
char temp[200];

sprintf(temp,"arguments to macro \"%s\"",(char*)name_of(id_token));
OVERFLW(temp,"ma");
}

/* :58 */
/* 59: */
#line 457 "./macs.web"

outer_char*
type1 FCN((c))
eight_bits c C1("")
{
outer_char*p= NULL;
static outer_char type_descr[TYPE_DESCR_LEN];

if(isprint(XCHR(c)))
{
if(
nsprintf(type_descr,OC("'%c'"),1,XCHR(c))>=(int)(TYPE_DESCR_LEN))OVERFLW("type_descr","");}

else
{
switch(c)
{
case constant:
p= OC("constant");break;

case stringg:
p= OC("string");break;

case '\n':
p= OC("newline");break;
}

if(p)
{
if(
nsprintf(type_descr,OC("'%s'"),1,p)>=(int)(TYPE_DESCR_LEN))OVERFLW("type_descr","");}

else
{
if(
nsprintf(type_descr,OC("0x%x"),1,c)>=(int)(TYPE_DESCR_LEN))OVERFLW("type_descr","");}

}

return type_descr;
}

/* :59 */
/* 61: */
#line 521 "./macs.web"

eight_bits HUGE*
get_margs0 FCN((start,end,pcur_byte,pthe_end,multilevels,
var_args,pargs,n))
eight_bits HUGE*start C0("Beginning of the tokens for this \
macro call.")
eight_bits HUGE*end C0("Maximum possible end.")
eight_bits HUGE**pcur_byte C0("Pointer to |cur_byte|.")
eight_bits HUGE**pthe_end C0("End of the current buffer.")
boolean multilevels C0("")
boolean var_args C0("Does macro have variable arguments?")
PARGS pargs C0("Array of pointers to the actual arguments, \
to be returned.")
eight_bits*n C1("Number of arguments found.")
{
eight_bits k;
int bal,bbal;
boolean mac_protected;
sixteen_bits id_token;

id_token= IDENTIFIER(*start,*(start+1));
start+= 2;


if(start==end&&pthe_end!=NULL)
end= args_to_macrobuf(end,pcur_byte,pthe_end,multilevels,var_args);


if(start==end||*start!='(')
{
return pargs[*n= 0]= start;

}

pargs[k= 0]= start++;





bal= 1;
bbal= 0;
mac_protected= NO;

while(start<end)
{
eight_bits c= *start;

if(TOKEN1(c))
{
switch(c)
{
case '#':
if(start+1<end&&*(start+1)==',')
{
*start= '\0';
start+= 2;
continue;
}
break;

case constant:
case stringg:
for(start++;*start++!=c;);
continue;

case dot_const:
case begin_language:
start+= 2;
continue;

case '`':
mac_protected= BOOLEAN(!mac_protected);
*start++= '\0';

continue;



case '(':
bal++;
break;

case ')':
if(bal==0)

macro_err(OC("Unexpected ')' in macro argument"),YES);
else if(bal>0)bal--;
break;

case '[':
bbal++;
break;

case ']':
if(bbal==0)

macro_err(OC("Unexpected ']' in macro argument"),YES);
else if(bbal>0)bbal--;
break;
}

if(!mac_protected&&((bal==1&&bbal==0&&(c==','))
||bal==0))
{

if(++k>=max_margs)
mac_args(id_token);

pargs[k]= start++;

if(bal==0)break;
}
else start++;
}
else
start+= (c<0250?2:4+4*1);

}

*n= k;
return start;
}

/* :61 */
/* 62: */
#line 649 "./macs.web"

void HUGE*
mac_lookup FCN((cur_val))
sixteen_bits cur_val C1("Current id token.")
{
return(void*)MAC_LOOKUP(cur_val);
}

/* :62 */
/* 64: */
#line 696 "./macs.web"


SRTN
i_ifdef_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
text_pointer m;
sixteen_bits id;
eight_bits HUGE*p0= pargs[0]+1;
boolean e;

CHK_ARGS("$IFDEF",3);

if(TOKEN1(*p0))
{

macro_err(OC("! First argument of $IFDEF or $IFNDEF must be a macro"),YES);
return;
}

id= IDENTIFIER(p0[0],p0[1]);
e= ((m= mac_lookup(id))!=NULL&&!(m->built_in));

if(e)
{MCHECK(pargs[2]-pargs[1]-1,"ifdef");
for(p0= pargs[1]+1;p0<pargs[2];)*mp++= *p0++;}
else
{MCHECK(pargs[3]-pargs[2]-1,"ifdef");
for(p0= pargs[2]+1;p0<pargs[3];)*mp++= *p0++;}
}

SRTN
i_ifndef_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
text_pointer m;
sixteen_bits id;
eight_bits HUGE*p0= pargs[0]+1;
boolean e;

CHK_ARGS("$IFDEF",3);

if(TOKEN1(*p0))
{

macro_err(OC("! First argument of $IFDEF or $IFNDEF must be a macro"),YES);
return;
}

id= IDENTIFIER(p0[0],p0[1]);
e= ((m= mac_lookup(id))!=NULL&&!(m->built_in));

if(!e)
{MCHECK(pargs[2]-pargs[1]-1,"ifndef");
for(p0= pargs[1]+1;p0<pargs[2];)*mp++= *p0++;}
else
{MCHECK(pargs[3]-pargs[2]-1,"ifndef");
for(p0= pargs[2]+1;p0<pargs[3];)*mp++= *p0++;}
}

/* :64 */
/* 65: */
#line 707 "./macs.web"

SRTN
i_ifelse_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p0;
eight_bits HUGE*pp0,HUGE*pp1,HUGE*mp0,HUGE*mp1;
boolean args_identical= YES;

CHK_ARGS("$IFELSE",4);

pp0= xmac_text(mp0= mp,pargs[0]+1,pargs[1]);
mp1= mp;

pp1= xmac_text(mp,pargs[1]+1,pargs[2]);




if(mp-pp1!=mp1-pp0)
args_identical= NO;
else
while(pp0<mp1)
if(*pp0++!=*pp1++)
args_identical= NO;

mp= mp0;

if(args_identical)
{MCHECK(pargs[3]-pargs[2]-1,"_ifelse_");
for(p0= pargs[2]+1;p0<pargs[3];)*mp++= *p0++;}
else
{MCHECK(pargs[4]-pargs[3]-1,"_ifelse_");
for(p0= pargs[3]+1;p0<pargs[4];)*mp++= *p0++;}
}

/* :65 */
/* 66: */
#line 749 "./macs.web"

SRTN
i_if_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*pp;
eight_bits HUGE*mp0;
eight_bits HUGE*p0;
boolean e;

CHK_ARGS("$IF",3);

pp= xmac_text(mp0= mp,p0= pargs[0]+1,pargs[1]);
e= eval(pp,mp);
mp= mp0;

if(e)
{MCHECK(pargs[2]-pargs[1]-1,"_if_");
for(p0= pargs[1]+1;p0<pargs[2];)*mp++= *p0++;}
else
{MCHECK(pargs[3]-pargs[2]-1,"_if_");
for(p0= pargs[2]+1;p0<pargs[3];)*mp++= *p0++;}
}

/* :66 */
/* 67: */
#line 776 "./macs.web"

SRTN
i_ifcase_ FCN((n,pargs))
int n C0("Total number of arguments")
PARGS pargs C1("")
{
eight_bits HUGE*pp;
eight_bits HUGE*mp0;
int ncase;

CHK_ARGS("$IFCASE",-1);
pp= xmac_text(mp0= mp,pargs[0]+1,pargs[1]);
ncase= neval(pp,mp);
mp= mp0;
copy_nth_arg(ncase,n-3,pargs);
}

/* :67 */
/* 68: */
#line 795 "./macs.web"

SRTN
copy_nth_arg FCN((n0,n,pargs))
int n0 C0("Should be a non-negative integer")
int n C0("Cases are numbered 0--n, default")
PARGS pargs C1("")
{
eight_bits HUGE*p0;

if(n0<0||n0>n)n0= n+1;

n0++;
MCHECK(pargs[n0+1]-pargs[n0]-1,"copy_nth_arg");
for(p0= pargs[n0]+1;p0<pargs[n0+1];)*mp++= *p0++;
}

/* :68 */
/* 69: */
#line 812 "./macs.web"

SRTN
i_switch_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{}

/* :69 */
/* 71: */
#line 828 "./macs.web"

SRTN
undef FCN((cur_val,warning))
sixteen_bits cur_val C0("Token to be undefined.")
boolean warning C1("Complain is there's an error?")
{
name_pointer np= name_dir+cur_val;
text_pointer m;

if(np->macro_type==NOT_DEFINED)
{
if(warning)

macro_err(OC("WARNING: \"%s\" is already undefined"),YES,name_of(cur_val));

return;
}


if(np->equiv==NULL)
{
if(np->macro_type==IMMEDIATE_MACRO)
{

macro_err(OC("Attempting to @#undef deferred macro \"%s\" \
during phase 1; consider using $UNDEF(%s)"),YES,name_of(cur_val),name_of(cur_val));
}
else
{

macro_err(OC("Missing equivalence field while undefining \"%s\"; \
this shouldn't happen!"),YES,name_of(cur_val));

np->macro_type= NOT_DEFINED;
}

return;
}

np->macro_type= NOT_DEFINED;

m= (text_pointer)np->equiv;
m->nargs= UNDEFINED_MACRO;
FREE(m->tok_start);
m->nbytes= m->moffset= 0;

np->equiv= NULL;
}

/* :71 */
/* 73: */
#line 898 "./macs.web"

boolean recursive_name FCN((a,xids,last_level))
sixteen_bits a C0("")
XIDS HUGE*xids C0("")
int last_level C1("")
{
int i;


for(i= 0;i<last_level;i++)
if(xids->token[i]==a)return YES;

return NO;
}

/* :73 */
/* 74: */
#line 915 "./macs.web"


SRTN
macro_err FCN(VA_ALIST((s,trail VA_ARGS)))
VA_DCL(
CONST outer_char s[]C0("Error message about macro expansion.")
int trail C2("Do we print out the expansion trail?"))
{
VA_LIST(arg_ptr)
outer_char HUGE*temp,HUGE*temp1,HUGE*t,HUGE*near_line;
int i,ntemp;
#if(NUM_VA_ARGS == 1)
CONST outer_char s[];
int trail;
#endif


temp= GET_MEM("macro_err:temp",N_MSGBUF,outer_char);
temp1= GET_MEM("macro_err:temp1",N_MSGBUF,outer_char);
near_line= GET_MEM("macro_err:near_line",N_MSGBUF,outer_char);

VA_START(arg_ptr,trail);

#if(NUM_VA_ARGS==1)
{
char*fmt0= va_arg(arg_ptr,char*);

va_arg(arg_ptr,int);
vsprintf((char*)(char*)temp1,fmt0,arg_ptr);
}
#else
vsprintf((char*)temp1,(CONST char*)s,arg_ptr);
#endif
va_end(arg_ptr);

if(phase==2)

if(
nsprintf(near_line,OC("; near input l. %u"),1,nearest_line)>=(int)(N_MSGBUF))OVERFLW("near_line","");






if(
nsprintf(temp,OC("\"%s.  (%s l. %u in %s%s.)  %s"),6,temp1,phase==1?"Input":"Output",phase==1?cur_line:OUTPUT_LINE,phase==1?cur_file_name:params.OUTPUT_FILE_NAME,near_line,trail&&(xlevel>0)?"Expanding ":"")>=(int)(N_MSGBUF))OVERFLW("temp","");

t= temp+STRLEN(temp);



if(trail&&(xlevel>0))
for(i= 0;i<1;i++)
see_xlevel(&t,pids[i]);

ntemp= STRLEN(temp);
temp[ntemp]= '"';
temp[ntemp+1]= '\0';


OUT_MSG(to_ASCII(temp),NULL);


temp[ntemp]= '\0';
printf("\n%s\n",(char*)to_outer((ASCII HUGE*)temp)+1);

mark_harmless;

FREE_MEM(temp,"macro_err:temp",N_MSGBUF,outer_char);
FREE_MEM(temp1,"macro_err:temp1",N_MSGBUF,outer_char);
FREE_MEM(near_line,"macro_err:near_line",N_MSGBUF,outer_char);
}

/* :74 */
/* 75: */
#line 982 "./macs.web"

SRTN
see_xlevel FCN((pt,p))
outer_char HUGE**pt C0("")
XIDS HUGE*p C1("")
{
int i,level;

level= p->level;

for(i= 0;i<level;
i++,sprintf((char*)(*pt),"%s",i==level?". ":", "),(*pt)+= 2)
prn_mname(pt,p->token[i]);
}


SRTN
prn_mname FCN((pt,token))
outer_char HUGE**pt C0("")
sixteen_bits token C1("")
{
name_pointer np;
ASCII HUGE*p;
CONST ASCII HUGE*end;

np= name_dir+token;

PROPER_END(end);

for(p= np->byte_start;p<end;)
*(*pt)++= XCHR(*p++);
}

/* :75 */
/* 76: */
#line 1016 "./macs.web"

SRTN
i_inp_line_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
num_to_mbuf(n,pargs,"$INPUT_LINE",0,"nearest line",nearest_line);
}

SRTN
i_outp_line_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
num_to_mbuf(n,pargs,"$OUTPUT_LINE",0,"output line",OUTPUT_LINE);
}

/* :76 */
/* 77: */
#line 1034 "./macs.web"

SRTN
num_to_mbuf FCN((n,pargs,built_in_name,num_args,num_descr,num))
int n C0("")
PARGS pargs C0("")
CONST char*built_in_name C0("")
int num_args C0("")
CONST char*num_descr C0("")
int num C1("")
{
CHK_ARGS(built_in_name,num_args);

MCHECK0(20,num_descr);

*mp++= constant;
sprintf((char*)mp,"%d",num);
to_ASCII((outer_char HUGE*)mp);
mp+= STRLEN(mp);
*mp++= constant;
}


/* :77 */
/* 78: */
#line 1064 "./macs.web"

boolean
x0macro FCN((p,end,xids,pcur_byte,pthe_end,multilevels))
eight_bits HUGE*p C0("Present position in the input buffer.")
eight_bits HUGE*end C0("Last filled position of the input \
buffer plus~1.")
XIDS HUGE*xids C0("")
eight_bits HUGE**pcur_byte C0("Pointer to |cur_byte|.")
eight_bits HUGE**pthe_end C0("End of buffer.")
boolean multilevels C1("")
{
boolean expanded;
sixteen_bits a;
eight_bits a0,a1;
text_pointer m;
eight_bits HUGE*p0,HUGE*p1;
eight_bits HUGE*HUGE*pargs= GET_MEM("pargs",max_margs,eight_bits HUGE*);
boolean must_paste= NO,pasting= NO;
int level0= xids->level;
boolean mac_protected= NO;

expanded= NO;


while(p<end)
{
a0= *p++;

if(p==end&&a0=='\n')break;

if(TOKEN1(a0))/* 79: */
#line 1111 "./macs.web"

{
switch(a0)
{
case '`':
mac_protected= BOOLEAN(!mac_protected);
continue;

case stringg:
case constant:
MCHECK(1,"`");
*mp++= a0;

copy_string:
do
{
if(!TOKEN1(*mp= *p++))
{
MCHECK(1,"id prefix");
*++mp= *p++;
}
MCHECK(1,"8-bit token");
}
while(*mp++!=a0);

if(a0==stringg)/* 80: */
#line 1155 "./macs.web"

{
eight_bits HUGE*p00;


for(p00= p;p<end;p++)
if(*p!=' '&&*p!='\t')break;

if(p<end&&*p==stringg)
{
eight_bits mchar= *(mp-2);
eight_bits pchar= *(p+1);

if((mchar=='\''||mchar=='\"')&&
(pchar=='\''||pchar=='\"'))
{
mp-= 2;
p+= 2;
goto copy_string;
}
}
else p= p00;
}

/* :80 */
#line 1136 "./macs.web"


continue;

case dot_const:
case begin_language:
MCHECK(2,"dot_const");
*mp++= a0;
*mp++= *p++;
continue;

default:
MCHECK(1,"`");
*mp++= a0;
continue;
}
}

/* :79 */
#line 1094 "./macs.web"

else/* 81: */
#line 1180 "./macs.web"

{
a= IDENTIFIER(a0,a1= *p++);

if(a==id_defined)
{
/* 83: */
#line 1260 "./macs.web"

{
MCHECK(6,"defined stuff");


*mp++= a0;
*mp++= a1;

ERR_IF_DEFINED_AT_END;
if(TOKEN1(a0= *p++))
{
if(a0!='(')DEFINED_ERR("! Invalid token after `defined'")
else*mp++= a0;

ERR_IF_DEFINED_AT_END;
if(TOKEN1(a0= *p++))DEFINED_ERR("! Invalid argument of `defined'")
else
{
*mp++= a0;
*mp++= *p++;
}

ERR_IF_DEFINED_AT_END;
if(TOKEN1(a0= *p++))
if(a0!=')')DEFINED_ERR("! Missing ')' after `defined'")
else*mp++= a0;
}
else
{
*mp++= a0;
*mp++= *p++;
}
}


/* :83 */
#line 1186 "./macs.web"

continue;
}





if((m= MAC_LOOKUP(a))!=NULL)
if(mac_protected)
{
MCHECK(2,"protected macro token");
*mp++= a0;
*mp++= a1;
}
else if(recursive_name(a,xids,level0))
/* 113: */
#line 1975 "./macs.web"

{
name_pointer np;
CONST ASCII HUGE*end;

np= name_dir+a;

PROPER_END(end);
copy_id(np->byte_start,end,"recursive macro name");


/* :113 */
/* 113: */
#line 1991 "./macs.web"
}



/* :113 */
#line 1202 "./macs.web"

else
{
int slevel= ignore;

if(!m->recursive)
save_name(a);

#ifdef DEBUG_MACS
dbg_macs(a,p,end);
#endif

/* 114: */
#line 2001 "./macs.web"

{
eight_bits n= 0;
eight_bits HUGE*mp0= NULL,HUGE*mp1,HUGE*m_start,HUGE*m_end;
boolean xpn_argument= YES;
boolean last_was_paste;
long max_n= 0;



if(m->nargs>0||m->var_args)
p= get_margs0(p-2,end,pcur_byte,pthe_end,multilevels,
(boolean)(m->var_args),pargs,&n);

if((!m->var_args&&n!=m->nargs)||(m->var_args&&n<m->nargs))
{

macro_err(OC("! Actual number of WEB macro arguments (%u) does not match \
number of def'n (%u); %s"),YES,n,m->nargs,n<m->nargs?"missing ones assumed to be NULL":
"extra ones discarded");




while(n<m->nargs)
{
pargs[n+1]= pargs[n]+1;
n++;
}
}


m_start= mp;
last_was_paste= NO;

if(m->built_in)
{
(*(SRTN(*)(int,unsigned char**))(m->tok_start))(n,pargs);
}
else
/* 115: */
#line 2059 "./macs.web"

{

p0= m->tok_start+m->moffset;
p1= m->tok_start+m->nbytes;

while(p0<p1)
{
if(TOKEN1(a= *p0++))
/* 117: */
#line 2105 "./macs.web"

{
if(!(a=='#'&&*p0=='.'))last_was_paste= NO;

if(p0==p1&&a=='\n')break;

switch(a)
{
case '#':
/* 119: */
#line 2242 "./macs.web"

{
keep_intact= NO;

switch(*p0++)
{
case '&':
/* 128: */
#line 2470 "./macs.web"

{
sixteen_bits id;


if(p0==p1)
macro_err(OC("! Missing internal function name after #&"),YES);
else
{
if(TOKEN1(a= *p0++))
macro_err(OC("! Identifier must follow #&"),YES);
else if(!x_int_fcn(id= IDENTIFIER(a,*p0++),n,pargs))

macro_err(OC("! Internal function name \"%s\" not defined"),YES,name_of(id));
}
}

/* :128 */
#line 2249 "./macs.web"
break;

case ':':
/* 130: */
#line 2511 "./macs.web"

{
int m;
long n;
outer_char*tmp;
size_t i;


if(*p0!=constant)
{

macro_err(OC("Expected constant after \"#:\""),YES);
break;
}

p0++;

for(i= 0;p0[i]!=constant;i++)
;

tmp= GET_MEM("stmt number",i+1,outer_char);


for(i= 0;*p0!=constant;i++,p0++)
tmp[i]= XCHR(*p0);
tmp[i+1]= '\0';
p0++;

n= ATOL(tmp);

FREE_MEM(tmp,"stmt number",i+1,outer_char);

if(n<=0)
{

macro_err(OC("! Invalid statement number offset (%ld) after #:; 1 assumed"),YES,n);
n= 1;
}

if(n>max_n)max_n= n;

MCHECK(2,"|constant|");
*mp++= constant;

m= 
nsprintf((outer_char*)mp,OC("%lu"),1,max_stmt+n-1);
MCHECK(m,"stmt label");
to_ASCII((outer_char HUGE*)mp);
mp+= m;

*mp++= constant;
}


/* :130 */
#line 2252 "./macs.web"
break;

case '!':
if(*p0==MACRO_ARGUMENT)xpn_argument= NO;
else
macro_err(OC("! Macro token '#!' must be followed by \
a parameter"),YES);
break;

case '\'':
single_quote= YES;
DOES_ARG_FOLLOW('\'');
goto do_stringize;

case '"':
double_quote= YES;
DOES_ARG_FOLLOW('\"');
goto do_stringize;

case '*':
DOES_ARG_FOLLOW('*');
keep_intact= YES;


case MACRO_ARGUMENT:
/* 85: */
#line 1310 "./macs.web"

{
eight_bits HUGE*begin;
boolean do_quote;


do_stringize:
for(begin= pargs[*p0]+1;*begin=='\0';begin++)
;


/* 86: */
#line 1341 "./macs.web"

MCHECK(1,"stringg");*mp++= stringg

/* :86 */
#line 1321 "./macs.web"
;

do_quote= BOOLEAN(!keep_intact||*begin!=stringg||begin[1]!=CUR_QUOTE);

if(do_quote)
/* 87: */
#line 1351 "./macs.web"

{
MCHECK(1,"quote");
*mp++= CUR_QUOTE;
}

/* :87 */
#line 1326 "./macs.web"


str_to_mb(begin,pargs[*p0+1],YES);
p0++;


if(do_quote)
/* 87: */
#line 1351 "./macs.web"

{
MCHECK(1,"quote");
*mp++= CUR_QUOTE;
}

/* :87 */
#line 1333 "./macs.web"


/* 86: */
#line 1341 "./macs.web"

MCHECK(1,"stringg");*mp++= stringg

/* :86 */
#line 1335 "./macs.web"
;

single_quote= double_quote= NO;
}

/* :85 */
#line 2276 "./macs.web"
break;

case '0':
/* 120: */
#line 2303 "./macs.web"

{
eight_bits HUGE*mp0;

p0+= 2;

MCHECK(4,"tokens for number of variable arguments");
*mp++= constant;
mp0= mp;
mp+= 
nsprintf((outer_char*)mp0,OC("%d"),1,n-m->nargs);
to_ASCII((outer_char HUGE*)mp0);
*mp++= constant;
}

/* :120 */
#line 2279 "./macs.web"

break;

case '{':
/* 122: */
#line 2325 "./macs.web"

expanded|= ins_arg('{','}',INS_ARG_LIST);

/* :122 */
#line 2283 "./macs.web"

break;

case '[':
/* 121: */
#line 2321 "./macs.web"

expanded|= ins_arg('[',']',INS_ARG_LIST);

/* :121 */
#line 2287 "./macs.web"

break;

case '.':
/* 124: */
#line 2395 "./macs.web"

{
eight_bits k;
boolean next_is_paste= BOOLEAN(*p0==paste);

for(k= m->nargs;k<n;k++)
{
pasting= cp_macro_arg(pargs,k,n,&xpn_argument,
(boolean)(last_was_paste&&k==m->nargs),
(boolean)(next_is_paste&&k==(eight_bits)(n-1)));
*mp++= ',';
}

if(*(mp-1)==',')mp--;

}

/* :124 */
#line 2291 "./macs.web"

break;

default:
p0--;

macro_err(OC(_Xx("! Invalid token 0x%x ('%c') after '#'")),YES,*p0,isprint(*p0)?*p0:'.');
break;
}
}

/* :119 */
#line 2114 "./macs.web"

break;

case stringg:
MCHECK(1,"\"");
*mp++= (eight_bits)a;

do
{
if(!TOKEN1(*mp= *p0++))
{
MCHECK(1,"id prefix");
*++mp= *p0++;
}
MCHECK(1,"8-bit token");
}
while(*mp++!=(eight_bits)a);

break;

case dot_const:
case begin_language:
MCHECK(2,"dot_const");
*mp++= (eight_bits)a;
*mp++= *p0++;
break;

default:

MCHECK(1,"single-byte token");
if((*mp++= (eight_bits)a)==paste)
last_was_paste= must_paste= YES;
break;
}
}

/* :117 */
#line 2068 "./macs.web"

else
/* 116: */
#line 2075 "./macs.web"

{
eight_bits k= *p0++;

if(a==MACRO_ARGUMENT)
{
pasting= cp_macro_arg(pargs,k,n,&xpn_argument,
last_was_paste,(boolean)(*p0==paste));
}
else
{
last_was_paste= NO;

MCHECK(2,"nonargument macro token");

*mp++= (eight_bits)a;
*mp++= k;

if(a==0320&&k=='\0')
{
MCHECK(4,"line info");
memcpy(mp,p0,4);
mp+= 4;
p0+= 4;
}
}
}

/* :116 */
#line 2070 "./macs.web"

}
}

/* :115 */
#line 2041 "./macs.web"



if(must_paste)
/* 131: */
#line 2567 "./macs.web"

{
m_end= mp;



copy_and_paste(m_start,m_end);


for(mp1= mp,mp= m_start,mp0= m_end;mp0<mp1;)
*mp++= *mp0++;
}

/* :131 */
#line 2045 "./macs.web"


if(max_n>0)
max_stmt+= max_n;

xpn_before(m_start,xids,pcur_byte,pthe_end,multilevels);
#if 0
if(must_paste)
#endif
expanded= YES;

}

/* :114 */
#line 1214 "./macs.web"


if(!m->recursive)
unsave_name;
}
else
{

MCHECK(2,"ordinary id");
*mp++= a0;
*mp++= a1;



if(a0>=0250)
{
int n= 2+4*1;

MCHECK(n,"module defn");
while(n-->0)
*mp++= *p++;
}
}
}

/* :81 */
#line 1095 "./macs.web"

}


done_expanding:
FREE_MEM(pargs,"pargs",max_margs,eight_bits HUGE*);
return expanded;

}

/* :78 */
/* 82: */
#line 1240 "./macs.web"

SRTN
dbg_macs FCN((n,start,end))
sixteen_bits n C0("")
eight_bits HUGE*start C0("")
eight_bits HUGE*end C1("")
{
printf("%lu = (0x%x->0x%x) <<%lu>>:  ",
end-start,start,end,start-macrobuf);
find_n(n);
}

/* :82 */
/* 89: */
#line 1364 "./macs.web"

SRTN
cpy_op FCN((s))
CONST outer_char HUGE*s C1("String such as \.{++}.")
{
MCHECK(2,"cpy_op");

while(*s)
*mp++= XORD(*s++);

copy_state= MISCELLANEOUS;
}

/* :89 */
/* 90: */
#line 1379 "./macs.web"

eight_bits HUGE*
str_to_mb FCN((begin_arg,end_arg,esc_chars))
CONST eight_bits HUGE*begin_arg C0("Beginning of string.")
CONST eight_bits HUGE*end_arg C0("End of string.")
boolean esc_chars C1("Insert escape characters?")
{
eight_bits HUGE*mp0= mp;
sixteen_bits c;

copy_state= MISCELLANEOUS;

while(begin_arg<end_arg)
{
if(TOKEN1(c= *begin_arg++))
{
/* 95: */
#line 1491 "./macs.web"


switch(c)
{
case ignore:
break;

/* 97: */
#line 1542 "./macs.web"


CPY_OP(plus_plus,"++");
CPY_OP(minus_minus,"--");
CPY_OP(minus_gt,C_LIKE(language)?"->":".EQV.");
CPY_OP(gt_gt,">>");
CPY_OP(eq_eq,"==");
CPY_OP(lt_lt,"<<");
CPY_OP(gt_eq,">=");
CPY_OP(lt_eq,"<=");
CPY_OP(not_eq,"!=");
CPY_OP(and_and,"&&");
CPY_OP(or_or,"||");
CPY_OP(star_star,"**");
CPY_OP(slash_slash,"//");
CPY_OP(ellipsis,C_LIKE(language)?"...":".XOR.");

case dot_const:
cpy_op(OC("."));
{
ASCII*symbol= dots[*begin_arg++].symbol;

cpy_op(to_outer(symbol));
to_ASCII((outer_char*)symbol);
}
cpy_op(OC("."));
break;

/* :97 */
#line 1498 "./macs.web"


case join:
copy_state= UNBREAKABLE;
break;

case constant:
if(copy_state==NUM_OR_ID)
/* 94: */
#line 1483 "./macs.web"

{
MCHECK(1,"' '");*mp++= ' ';
}

/* :94 */
#line 1506 "./macs.web"

/* 98: */
#line 1572 "./macs.web"

{
if(!keep_intact&&c==stringg)esc_certain_chars(*begin_arg++,YES);


while(*begin_arg!=(eight_bits)c)
{
MCHECK(1,"constant");
*mp++= *begin_arg++;
}

if(!keep_intact&&c==stringg)
esc_certain_chars((sixteen_bits)*(--mp),YES);


begin_arg++;
}

/* :98 */
#line 1507 "./macs.web"

copy_state= NUM_OR_ID;
break;

case stringg:
/* 98: */
#line 1572 "./macs.web"

{
if(!keep_intact&&c==stringg)esc_certain_chars(*begin_arg++,YES);


while(*begin_arg!=(eight_bits)c)
{
MCHECK(1,"constant");
*mp++= *begin_arg++;
}

if(!keep_intact&&c==stringg)
esc_certain_chars((sixteen_bits)*(--mp),YES);


begin_arg++;
}

/* :98 */
#line 1512 "./macs.web"

copy_state= MISCELLANEOUS;
break;

case ';':
if(R77_or_F)
{
/* 96: */
#line 1530 "./macs.web"

{
MCHECK(3,"\";\"");
*mp++= constant;
*mp++= ';';
*mp++= constant;
}

/* :96 */
#line 1519 "./macs.web"
;
break;
}

default:
esc_certain_chars(c,esc_chars);
if(copy_state!=VERBATIM)copy_state= MISCELLANEOUS;
break;
}

/* :95 */
#line 1395 "./macs.web"

}
else
{
name_pointer np;

if(copy_state==NUM_OR_ID)
/* 94: */
#line 1483 "./macs.web"

{
MCHECK(1,"' '");*mp++= ' ';
}

/* :94 */
#line 1402 "./macs.web"


if(c==MACRO_ARGUMENT)
/* 91: */
#line 1418 "./macs.web"

{
outer_char temp[10];
int n;

n= 
nsprintf(temp,OC("$%d"),1,*begin_arg++);
to_ASCII(temp);
MCHECK(n,"%arg");
STRCPY(mp,temp);
mp+= n;
}

/* :91 */
#line 1405 "./macs.web"

else
/* 92: */
#line 1432 "./macs.web"

{
c= IDENTIFIER(c,*begin_arg++);

switch(c/MODULE_NAME)
{
case 0:
np= name_dir+c;
/* 135: */
#line 2742 "./macs.web"

{
TRUNC HUGE*s;
ASCII HUGE*pc= np->byte_start;

if(*pc!=BP_MARKER)
{
CONST ASCII HUGE*end;

PROPER_END(end);
copy_id((CONST ASCII HUGE*)pc,end,"copied id");
}
else
{
s= ((BP HUGE*)pc)->Root;
copy_id(s->id,s->id_end,"copied id");
}
}

/* :135 */
#line 1440 "./macs.web"

break;

case 1:
MCHECK(5,"macro name");

*mp++= '#';
*mp++= '<';

c-= MODULE_NAME;

np= name_dir+c;

if(np->equiv!=(EQUIV)text_info)
/* 135: */
#line 2742 "./macs.web"

{
TRUNC HUGE*s;
ASCII HUGE*pc= np->byte_start;

if(*pc!=BP_MARKER)
{
CONST ASCII HUGE*end;

PROPER_END(end);
copy_id((CONST ASCII HUGE*)pc,end,"copied id");
}
else
{
s= ((BP HUGE*)pc)->Root;
copy_id(s->id,s->id_end,"copied id");
}
}

/* :135 */
#line 1454 "./macs.web"

else if(c!=UNNAMED_MODULE)
*mp++= '?';


*mp++= '@';
*mp++= '>';
break;

default:
if(c==MODULE_NUM)
begin_arg+= 4*1;

break;
}
}

/* :92 */
#line 1407 "./macs.web"


copy_state= NUM_OR_ID;
}
}

*mp= '\0';
return mp0;
}

/* :90 */
/* 99: */
#line 1594 "./macs.web"

SRTN
esc_certain_chars FCN((c,esc_chars))
sixteen_bits c C0("Character to be maybe escaped.")
boolean esc_chars C1("Do we escape them?")
{
if(esc_chars)
if(C_LIKE(language))
{
if(c=='\\'||c=='"')
{
MCHECK(1,"'\\'");
*mp++= '\\';
}
}
else if(R77_or_F)
{
if(c=='\'')
{
MCHECK(1,"doubled quote");
*mp++= (eight_bits)c;

}
}
else
{
if(c=='"')
{
MCHECK(1,"'\"'");
*mp++= (eight_bits)c;
}
}


MCHECK(1,"escaped character");
*mp++= (eight_bits)c;
}

/* :99 */
/* 102: */
#line 1647 "./macs.web"

SRTN
i_len_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int m,num;

CHK_ARGS("$LEN",1);

m= (int)(pargs[1]-pargs[0]-5);



num= 
nsprintf((outer_char HUGE*)mp,OC("%d"),1,m);
MCHECK(num,"_len_");
to_ASCII((outer_char HUGE*)mp);
mp+= num;
}

/* :102 */
/* 104: */
#line 1684 "./macs.web"

SRTN
i_verbatim_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p,delim[2];
eight_bits quote_char[3];

CHK_ARGS("$VERBATIM",1);

if(*(p= pargs[0]+1)!=stringg)
{
MUST_QUOTE("$VERBATIM",p,pargs[1]);
return;
}

STRNCPY(delim,"\0\0",2);
STRNCPY(quote_char,"\"\0\0",3);


switch(language)
{
case FORTRAN:
quote_char[0]= '\'';
break;

case FORTRAN_90:
quote_char[1]= '\'';
break;

case TEX:
return;

default:
break;
}


MCHECK(1,"string token");
*mp++= *p++;


delim[0]= *p;

if(STRSPN(delim,quote_char))
p++;
else
delim[0]= stringg;

while(*p!=stringg)
{
MCHECK(1,"verbatim token");
*mp++= *p++;
}


if(STRSPN(delim,quote_char))
*(mp---1)= stringg;
}

/* :104 */
/* 106: */
#line 1752 "./macs.web"

SRTN
i_unstring_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p,delim[2];
eight_bits quote_char[3];

CHK_ARGS("$UNSTRING",1);

if(*(p= pargs[0]+1)!=stringg)
{
MUST_QUOTE("$UNSTRING",p,pargs[1]);
return;
}

STRNCPY(delim,"\0\0",2);
STRNCPY(quote_char,"\"\0\0",3);


switch(language)
{
case FORTRAN:
quote_char[0]= '\'';
break;

case FORTRAN_90:
quote_char[1]= '\'';
break;

case TEX:
return;

default:
break;
}


p++;


delim[0]= *p;

if(STRSPN(delim,quote_char))
p++;
else
delim[0]= stringg;

while(*p!=stringg)
{
MCHECK(1,"verbatim token");
*mp++= *p++;
}


if(STRSPN(delim,quote_char))
mp--;
}

/* :106 */
/* 107: */
#line 1816 "./macs.web"

SRTN
must_quote FCN((name,p,p1))
CONST outer_char*name C0("")
eight_bits HUGE*p C0("")
eight_bits HUGE*p1 C1("")
{

macro_err(OC("! Argument of %s must be a quoted string"),YES,name);


MCHECK(p1-p,"copy quotes");
while(p<p1)*mp++= *p++;
}

/* :107 */
/* 109: */
#line 1842 "./macs.web"

SRTN
i_translit_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int k;

CHK_ARGS("$TRANSLIT",3);

for(k= 0;k<2;k++)
if(*(pargs[k]+1)!=stringg)
macro_err(OC("! Argument %d of $TRANSLIT \
must be a string"),YES,k);

translit((ASCII HUGE*)(pargs[0]+2),
(ASCII HUGE*)(pargs[1]+2),
(ASCII HUGE*)(pargs[2]+2));
}

/* :109 */
/* 110: */
#line 1866 "./macs.web"

SRTN
translit FCN((s,from,to))
CONST ASCII HUGE*s C0("String to be transliterated")
CONST ASCII HUGE*from C0("Characters to replace")
CONST ASCII HUGE*to C1("Replace by")
{
short code[128],i,n;
ASCII end_char= *s++;
ASCII c,cfrom,cto;
ASCII esc_achar PROTO((CONST ASCII HUGE*HUGE*));

CHECK_QUOTE(from,1);
CHECK_QUOTE(to,2);

/* 86: */
#line 1341 "./macs.web"

MCHECK(1,"stringg");*mp++= stringg

/* :86 */
#line 1881 "./macs.web"
;


for(i= 0;i<128;i++)
code[i]= i;


while(*(to+1)!=stringg)
{
if(*(from+1)==stringg)break;


if((cfrom= *from++)=='\\')cfrom= esc_achar(&from);
if((cto= *to++)=='\\')cto= esc_achar(&to);

code[cfrom]= cto;
}



if(*(from+1)!=stringg)
while(*(from+1)!=stringg)
{
if((cfrom= *from++)=='\\')cfrom= esc_achar(&from);

code[cfrom]= -1;
}


while(*(s+1)!=stringg)
{
if((c= *s++)=='\\')c= esc_achar(&s);

if((n= code[c])==-1)continue;
MCHECK(1,"_translit_");
*mp++= (eight_bits)n;
}

/* 86: */
#line 1341 "./macs.web"

MCHECK(1,"stringg");*mp++= stringg

/* :86 */
#line 1919 "./macs.web"
;
}

/* :110 */
/* 112: */
#line 1940 "./macs.web"

SRTN
i_getenv_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
ASCII HUGE*p;
outer_char*pvar,HUGE*t;
outer_char HUGE*temp,HUGE*temp_end;


#if !HAVE_GETENV

macro_err(OC("Sorry, this machine doesn't support getenv"),YES);
#else

CHK_ARGS("$GETENV",1);


temp= GET_MEM("_getenv_:temp",N_ENVBUF,outer_char);
temp_end= temp+N_ENVBUF;

for(p= (ASCII HUGE*)(pargs[0]+3),t= temp;*(p+1)!=stringg;)
SAVE_ENV(*p++);

SAVE_ENV('\0');

if((pvar= GETENV((CONST char*)temp))!=NULL)mcopy(pvar);

FREE_MEM(temp,"_getenv_:temp",N_ENVBUF,outer_char);

#endif 
}

/* :112 */
/* 118: */
#line 2152 "./macs.web"

boolean cp_macro_arg FCN((pargs,k,n,pxpn_argument,
last_was_paste,next_is_paste))
PARGS pargs C0("")
eight_bits k C0("Current argument to process")
eight_bits n C0("")
boolean HUGE*pxpn_argument C0("")
boolean last_was_paste C0("")
boolean next_is_paste C1("")
{
boolean pasting;
eight_bits HUGE*begin_arg,HUGE*end_arg,HUGE*mp0= NULL;



if(k>=n)
{
pargs[k]= pargs[n];
pargs[k+1]= pargs[n]+1;
}

begin_arg= pargs[k]+1;



while(*begin_arg=='\n')begin_arg++;

end_arg= pargs[k+1];



if(last_was_paste||next_is_paste)pasting= YES;
else
{
pasting= NO;
mp0= mp;
}




if(begin_arg==end_arg)
{
if(pasting)
{
MCHECK(1,"null character");
*mp++= '\0';
}
}
else
{
MCHECK(end_arg-begin_arg,"argument tokens");
while(begin_arg<end_arg)*mp++= *begin_arg++;
}






if(!*pxpn_argument)
*pxpn_argument= YES;
else if(!pasting)
xpn_before(mp0,NULL,NULL,NULL,NO);

return pasting;
}

/* :118 */
/* 123: */
#line 2329 "./macs.web"

boolean ins_arg FCN((cleft,cright,
pargs,m,n,pp0,ppasting,pxpn_argument,last_was_paste))
ASCII cleft C0("")
ASCII cright C0("")
PARGS pargs C0("")
text_pointer m C0("")
eight_bits n C0("")
eight_bits HUGE*HUGE*pp0 C0("")
boolean*ppasting C0("")
boolean*pxpn_argument C0("")
boolean last_was_paste C1("")
{
int k;
boolean next_is_paste= BOOLEAN(*(*pp0)==paste);
eight_bits HUGE*pp;
eight_bits HUGE*mp0= mp;
eight_bits HUGE*p00= (*pp0);
boolean fixed= BOOLEAN(cleft=='[');

WHILE()
if(*(*pp0)==cright)
{
break;
}
else if(TOKEN1(*(*pp0)))(*pp0)++;
else(*pp0)+= 2;

pp= xmac_text(mp0,p00,(*pp0)++);
k= neval(pp,mp);

mp= mp0;


if(k==0)
{
*mp++= '#';
*mp++= '{';

while(p00<*pp0)
*mp++= *p00++;

return YES;
}

if(k<=0)
{
outer_char temp[5];


nsprintf(temp,OC("#%c0%c"),3,5,XCHR(cleft),XCHR(cright));
MCHECK(4,temp);
*mp++= constant;
mp0= mp;
mp+= 
nsprintf((outer_char*)mp0,OC("%d"),1,n-(fixed?0:m->nargs));
to_ASCII((outer_char HUGE*)mp0);
*mp++= constant;
}
else
*ppasting= cp_macro_arg(pargs,(eight_bits)(k-1+(fixed?0:m->nargs)),
n,pxpn_argument,last_was_paste,next_is_paste);

return NO;
}

/* :123 */
/* 127: */
#line 2446 "./macs.web"

SRTN
xpn_before FCN((mp0,xids,pcur_byte,pthe_end,multilevels))
eight_bits HUGE*mp0 C0("Remember this end of |macro_buf|.")
XIDS HUGE*xids C0("")
eight_bits HUGE**pcur_byte C0("Pointer to |cur_byte|.")
eight_bits HUGE**pthe_end C0("End of buffer.")
boolean multilevels C1("")
{
eight_bits HUGE*mp1;

mp1= xmac_buf(mp0,xids,pcur_byte,pthe_end,multilevels);


while(mp1<mp)
*mp0++= *mp1++;


mp= mp0;
}

/* :127 */
/* 129: */
#line 2489 "./macs.web"

boolean
x_int_fcn FCN((id,n,pargs))
sixteen_bits id C0("Token for internal function.")
int n C0("Number of arguments")
PARGS pargs C1("Array of pointers to arguments.")
{
INTERNAL_FCN HUGE*f;

for(f= internal_fcns;f->len!=0;f++)
if(f->id==id)
{
(*f->expnd)(n,pargs);

return YES;
}

return NO;
}

/* :129 */
/* 132: */
#line 2582 "./macs.web"

eight_bits HUGE*
copy_and_paste FCN((m_start,m_end))
eight_bits HUGE*m_start C0("Start of range.")
eight_bits HUGE*m_end C1("End of range.")
{
eight_bits HUGE*mp0;
eight_bits a0;
eight_bits HUGE*m_last= m_start;

for(mp0= m_start;mp0<m_end;)
{
if(TOKEN1(a0= *mp0))
{
if(a0==paste)/* 133: */
#line 2655 "./macs.web"

{
eight_bits HUGE*p;

p= mp;

paste1(m_last,m_start);
mp0= paste1(++mp0,m_end);


divert((ASCII HUGE*)p,(ASCII HUGE*)mp,STOP);

scan_repl(macro,STOP);


mp= m_last;
m_last= copy_and_paste(cur_text->tok_start,tok_ptr);


text_ptr= cur_text;
mx_tok_ptr= tok_ptr;
tok_ptr= text_ptr->tok_start;
}

/* :133 */
#line 2596 "./macs.web"

else
{
if(a0==ignore)
{
mp0++;
continue;
}

m_last= mp;

switch(a0)
{
case constant:
case stringg:
MCHECK(1,"|constant| or |stringg|");
*mp++= *mp0++;

do
{
*mp= *mp0++;
MCHECK(1,"text of \
|constant| or |stringg|");
}
while(*mp++!=a0);

break;

case dot_const:
case begin_language:
MCHECK(2,"dot_const");
*mp++= *mp0++;
*mp++= *mp0++;
break;

default:
MCHECK(1,"ASCII token");
*mp++= *mp0++;
break;
}
}
}
else
{
m_last= mp;
MCHECK(2,"two-byte token");
*mp++= *mp0++;*mp++= *mp0++;
}
}

return m_last;
}

/* :132 */
/* 134: */
#line 2681 "./macs.web"

eight_bits HUGE*
paste1 FCN((p0,begin_or_end))
eight_bits HUGE*p0 C0("Beginning of tokens to be expanded.")
eight_bits HUGE*begin_or_end C1("")
{
eight_bits a0,a1;
sixteen_bits a;

if(p0==begin_or_end)
{

macro_err(OC("! Missing argument to token-paste operation. Null assumed"),YES);
return p0;
}

if(TOKEN1(a0= *p0++))
switch(a0)
{
case ignore:break;

case constant:
case stringg:

while((a1= *p0++)!=a0)
{
MCHECK(1,"stuff between tokens");
*mp++= a1;
}
break;

case dot_const:
case begin_language:
MCHECK(2,"dot_const");
*mp++= a0;
*mp++= *p0++;
break;

default:
MCHECK(1,"default ASCII token");
*mp++= a0;
break;
}
else
{
a= IDENTIFIER(a0,*p0++);

if(a<MODULE_NAME)
{
name_pointer np;

np= name_dir+a;
/* 135: */
#line 2742 "./macs.web"

{
TRUNC HUGE*s;
ASCII HUGE*pc= np->byte_start;

if(*pc!=BP_MARKER)
{
CONST ASCII HUGE*end;

PROPER_END(end);
copy_id((CONST ASCII HUGE*)pc,end,"copied id");
}
else
{
s= ((BP HUGE*)pc)->Root;
copy_id(s->id,s->id_end,"copied id");
}
}

/* :135 */
#line 2733 "./macs.web"

}
else{}
}

return p0;
}

/* :134 */
/* 136: */
#line 2762 "./macs.web"

SRTN
copy_id FCN((start,end,descr))
CONST ASCII HUGE*start C0("Beginning of identifier name.")
CONST ASCII HUGE*end C0("End of identifier name.")
CONST char*descr C1("")
{
CONST ASCII HUGE*j;

MCHECK(end-start,descr);

for(j= start;j<end;)
*mp++= (eight_bits)(*j++);
}

/* :136 */
/* 137: */
#line 2779 "./macs.web"

SRTN
mbuf_full FCN((n,reason))
unsigned long n C0("Number of bytes requested.")
CONST outer_char reason[]C1("Reason for request.")
{

macro_err(OC("! Macro buffer full; %lu byte(s) requested for %s"),YES,n,reason);
OVERFLW("macro buffer bytes","mb");
}


SRTN
mcheck0 FCN((n,reason))
unsigned long n C0("Number of bytes requested.")
CONST outer_char reason[]C1("Reason for request.")
{
MCHECK(n,reason);
}

/* :137 */
/* 138: */
#line 2799 "./macs.web"

eight_bits HUGE*
xmacro FCN((macro_text,pcur_byte,pthe_end,multilevels,mp0))
text_pointer macro_text C0("")
eight_bits HUGE**pcur_byte C0("Pointer to |cur_byte|.")
eight_bits HUGE**pthe_end C0("End of buffer.")
boolean multilevels C0("Read args through many levels?")
eight_bits HUGE*mp0 C1("Build the expansion beginning here in \
|macrobuf|.")
{
eight_bits HUGE*macro_start;
extern long cur_val;


mp= mp0;

MCHECK(2,"macro token");

if(macro_text->built_in)
{
*mp++= LEFT(cur_val,ID0);
*mp++= RIGHT(cur_val);
}
else
{
macro_start= macro_text->tok_start;
*mp++= *macro_start++;*mp++= *macro_start++;
}



if(macro_text->nargs>0||macro_text->var_args)
mp= args_to_macrobuf(mp,pcur_byte,pthe_end,multilevels,
(boolean)(macro_text->var_args));

return xmac_buf(mp0,NULL,pcur_byte,pthe_end,multilevels);


}

/* :138 */
/* 139: */
#line 2846 "./macs.web"

eight_bits HUGE*
args_to_macrobuf FCN((mp,pcur_byte,pthe_end,
multilevels,var_args))
eight_bits HUGE*mp C0("Next available position in |macro_buf|.")
eight_bits HUGE**pcur_byte C0("Pointer to |cur_byte|.")
eight_bits HUGE**pthe_end C0("End of buffer.")
boolean multilevels C0("Read through many levels?")
boolean var_args C1("Does macro have variable args?")
{
eight_bits c;
sixteen_bits id_token;
int bal= 0;

id_token= IDENTIFIER(*(mp-2),*(mp-1));


do
{
if(*pcur_byte==*pthe_end)
{
if(!(multilevels&&pop_level()))
{

macro_err(OC("! No ')' in call to macro \"%s\""),YES,name_of(id_token));
break;
}
}

MCHECK(1,"arg to macrobuf");
c= *mp++= *(*pcur_byte)++;

if(TOKEN1(c))
/* 140: */
#line 2898 "./macs.web"

{
switch(c)
{
case stringg:
do
{
MCHECK(1,"string arg");
*mp= *(*pcur_byte)++;
}
while(*mp++!=stringg);
break;

case dot_const:
case begin_language:
MCHECK(1,"dot const");
*mp++= *(*pcur_byte)++;
break;

case '(':
bal++;
break;

case ')':
if(bal==0&&!var_args)
{

macro_err(OC("! Missing '(' in call to macro \"%s\""),YES,name_of(id_token));
goto done_copying;
}
else bal--;

break;
}
}

/* :140 */
#line 2879 "./macs.web"

else
{

int n;

n= (c<0250?1:3+4*1);
MCHECK(n,"second id token");
while(n-->0)*mp++= *(*pcur_byte)++;
continue;
}
}
while(bal>0);

done_copying:
return mp;
}

/* :139 */
/* 141: */
#line 2944 "./macs.web"

eight_bits HUGE*
xmac_buf FCN((mp0,old_xids,pcur_byte,pthe_end,multilevels))
eight_bits HUGE*mp0 C0("Text to be expanded begins here.")
XIDS HUGE*old_xids C0("")
eight_bits HUGE**pcur_byte C0("Pointer to |cur_byte|.")
eight_bits HUGE**pthe_end C0("End of buffer.")
boolean multilevels C1("")
{
eight_bits HUGE*p,HUGE*p1;
XIDS xids;
XIDS HUGE*pid;

xids.level= 0;

if(xlevel>=MAX_XLEVELS)
{

macro_err(OC("! Macro outer recursion depth exceeded"),YES);

fatal(ERR_M,OC("!! BYE."),OC(""));
}

pid= pids[xlevel++]= old_xids?old_xids:&xids;


for(p= mp0,p1= mp;
x0macro(p,p1,pid,pcur_byte,pthe_end,multilevels);
p= p1,p1= mp);

xlevel--;

return p1;
}

/* :141 */
/* 142: */
#line 2979 "./macs.web"

eight_bits HUGE*
xmac_text FCN((mp0,start,end))
eight_bits HUGE*mp0 C0("")
eight_bits HUGE*start C0("")
eight_bits HUGE*end C1("")
{

for(mp= mp0;start<end;)
*mp++= *start++;


return xmac_buf(mp0,NULL,NULL,NULL,NO);
}

/* :142 */
/* 144: */
#line 3005 "./macs.web"

SRTN
i_meta_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p;

CHK_ARGS("$COMMENT",1);


p= pargs[0]+1;
if(!(*p==constant||*p==stringg))
{
arg_must_be_constant("$COMMENT");
return;
};

/* 145: */
#line 3035 "./macs.web"

{
static eight_bits begin_C_meta[]= {constant,'/','*',constant,'\0'};
eight_bits HUGE*p;


if(C_LIKE(language))
{
MCHECK0(4,"begin_C_meta");
for(p= begin_C_meta;*p;)*mp++= *p++;
}
else
{
MCHECK0(2,"begin_meta");
*mp++= begin_meta;
*mp++= begin_meta;
}
}

/* :145 */
#line 3017 "./macs.web"
;

*(p+1)= *(pargs[1]-2)= ' ';

do
{
MCHECK0(1,"_meta_");
*mp++= *p++;
}
while(p<pargs[1]);

/* 146: */
#line 3055 "./macs.web"

{
static eight_bits end_C_meta[]= "*/";
eight_bits HUGE*p;


if(C_LIKE(language))
{
MCHECK0(2,"end_C_meta");
for(p= end_C_meta;*p;)*mp++= *p++;
}
else
{
MCHECK0(1,"end_meta");
*mp++= end_meta;
}
}

/* :146 */
#line 3028 "./macs.web"
;
}

/* :144 */
/* 148: */
#line 3083 "./macs.web"

SRTN
i_assert_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p;
eight_bits HUGE*pp;
eight_bits HUGE*mp0;
boolean e;

CHK_ARGS("$ASSERT",1);

pp= xmac_text(mp0= mp,p= pargs[0]+1,pargs[1]);
e= eval(pp,mp);
mp= mp0;

if(e)
return;

mp= str_to_mb(p,pargs[1],YES);


macro_err(OC("! $ASSERT(%s) failed"),NO,to_outer((ASCII HUGE*)mp));

fatal(ERR_M,OC(""),OC("Processing ABORTED!"));
}

/* :148 */
/* 150: */
#line 3115 "./macs.web"

SRTN
i_error_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits c;
eight_bits HUGE*t,HUGE*p,HUGE*temp;

CHK_ARGS("$ERROR",1);


p= pargs[0]+1;
if(!(*p==constant||*p==stringg))
{
arg_must_be_constant("$ERROR");
return;
};

temp= GET_MEM("_error_:temp",N_MSGBUF,eight_bits);

for(c= *p++,t= temp;*p!=c;)*t++= *p++;
*t= '\0';


macro_err(OC("%cUSER ERROR:  %s"),NO,beep(1),to_outer((ASCII HUGE*)temp));
FREE_MEM(temp,"_error_:temp",N_MSGBUF,eight_bits);
}

/* :150 */
/* 152: */
#line 3146 "./macs.web"

SRTN
i_routine_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
name_pointer np;
CONST ASCII HUGE*f,HUGE*end;

CHK_ARGS("$ROUTINE",0);

if(!(is_RATFOR_(language)))return;
if(!RAT_OK(""))
confusion(OC("_routine_"),OC("Language shouldn't be Ratfor here"));

if(cur_fcn==NO_FCN)
{
MCHECK0(1,"'?'");
*mp++= '?';
return;
}

np= name_dir+cur_fcn;
end= proper_end(np);

MCHECK0(end-np->byte_start,"_routine_");
for(f= np->byte_start;f<end;)
*mp++= *f++;
}


/* :152 */
/* 154: */
#line 3184 "./macs.web"

SRTN
i_lowercase_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p= pargs[0]+1,HUGE*p1= pargs[1];

CHK_ARGS("$LC",1);

if(*p!=stringg)
{
MUST_QUOTE("$L",p,p1);
return;
}

MCHECK(p1-p,"lowercase");

for(;p<p1;p++)
*mp++= A_TO_LOWER(*p);
}

SRTN
i_uppercase_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p= pargs[0]+1,HUGE*p1= pargs[1];

CHK_ARGS("$UC",1);

if(*p!=stringg)
{
MUST_QUOTE("$U",p,p1);
return;
}

MCHECK(p1-p,"uppercase");

for(;p<p1;p++)
*mp++= A_TO_UPPER(*p);
}

/* :154 */
/* 156: */
#line 3233 "./macs.web"

SRTN
i_nargs_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
text_pointer m;
eight_bits*pa= pargs[0]+1;

if((m= MAC_LOOKUP(IDENTIFIER(pa[0],pa[1])))==NULL)
{

macro_err(OC("! Argument of $NARGS is not a WEB macro"),YES);
put_long(-1L);
}
else put_long((long)m->nargs);
}

/* :156 */
/* 157: */
#line 3251 "./macs.web"

SRTN
put_long FCN((l))
long l C1("")
{
outer_char temp[100];
int n;

n= 
nsprintf(temp,OC("%ld"),1,l);
to_ASCII(temp);
MCHECK(n+2,"long");
*mp++= constant;
STRCPY(mp,temp);
mp+= n;
*mp++= constant;
}

/* :157 */
/* 158: */
#line 3271 "./macs.web"

SRTN
chk_args FCN((name,proper_num,actual_num,pargs))
outer_char*name C0("")
int proper_num C0("")
int actual_num C0("")
PARGS pargs C1("")
{
if(proper_num>=0)
{
if(actual_num!=proper_num)

macro_err(OC("Built-in macro %s should be called with %d \
argument(s), not %d"),NO,name,proper_num,actual_num);
}
}

/* :158 */
/* 159: */
#line 3295 "./macs.web"

SRTN
see_macro FCN((p0,p1))
CONST eight_bits HUGE*p0 C0("Beginning of token list.")
CONST eight_bits HUGE*p1 C1("End of token list.")
{
int k,l,num_tokens;
ASCII HUGE*q0;
sixteen_bits HUGE*tokens;
ASCII HUGE*mtext;

num_tokens= PTR_DIFF(int,p1,p0);

tokens= GET_MEM("see_macro:tokens",num_tokens,sixteen_bits);
mtext= GET_MEM("see_macro:mtext",MTEXT_SIZE,ASCII);

k= rcvr_macro(mtext,tokens,p0,p1);

printf(">> \"");
for(l= 0;l<k;++l)
printf(_Xx("%x "),tokens[l]);

printf("\"\n== \"");
for(q0= mtext;q0<mtext+k;++q0)
putchar(XCHR(*q0));
puts("\"");

FREE_MEM(mtext,"see_macro:mtext",MTEXT_SIZE,ASCII);
if(num_tokens)FREE_MEM(tokens,"see_macro:tokens",num_tokens,sixteen_bits);
}

/* :159 */
/* 160: */
#line 3327 "./macs.web"

int
rcvr_macro FCN((mtext,tokens,p0,p1))
ASCII HUGE*mtext C0("Holds readable translation of the	text.")
sixteen_bits HUGE*tokens C0("Slightly translated tokens.")
CONST eight_bits HUGE*p0 C0("")
CONST eight_bits HUGE*p1 C1("")
{
ASCII HUGE*mtext_end= mtext+MTEXT_SIZE;
ASCII HUGE*p;
ASCII HUGE*j;
int k;
sixteen_bits a;

for(k= 0,p= mtext;p0<p1;k++)
{
if(TOKEN1(a= *p0++))
switch(a)
{
case paste:
SAVE_MTEXT('#');SAVE_MTEXT('#');
break;

default:
SAVE_MTEXT(a);
break;
}
else if(a==MACRO_ARGUMENT)
{
SAVE_MTEXT('$');
a= (sixteen_bits)(-(*p0));
SAVE_MTEXT(*p0+++'0');
}
else
{
a= IDENTIFIER(a,*p0++);

if(a<MODULE_NAME)
{
CONST ASCII HUGE*end;
name_pointer np= name_dir+a;

PROPER_END(end);

for(j= np->byte_start;j<end;++j)
{SAVE_MTEXT(*j);}
}
else
{
SAVE_MTEXT('M');
}
}

if(tokens)tokens[k]= a;
}

return k;
}

/* :160 */
/* 162: */
#line 3393 "./macs.web"

SRTN
i_xflag_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p= pargs[0]+1;
outer_char temp[100],*t= temp;

CHK_ARGS("$XX",1);

if(*p++!=constant)
{

macro_err(OC("Argument of $XX is not a numerical constant"),NO);
return;
}

while(*p!=constant)
*t++= XCHR(*p++);

TERMINATE(t,0);

xflag= ATOI(temp);
}

/* :162 */
/* 163: */
#line 3419 "./macs.web"

SRTN
i_dumpdef_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int k;
eight_bits HUGE*p,HUGE*mp0,HUGE*mp1,HUGE*mp2;
sixteen_bits a;
extern long cur_val;
eight_bits HUGE*q0,HUGE*q1;
ASCII HUGE*mtext= GET_MEM("rcvr_macro:mtext",MTEXT_SIZE,ASCII);
ASCII HUGE*mx,HUGE*mx0;
name_pointer np;

CHK_ARGS("$DUMPDEF",INT_MIN);

for(k= 0;k<n;k++)
{
text_pointer m;

if(xflag)
printf("\n");

mp0= mp;

p= pargs[k]+1;

while(IS_WHITE(*p)||*p=='\n')p++;

a= IDENTIFIER(*p,*(p+1));

if((m= MAC_LOOKUP(a))==NULL)
{
str_to_mb(p,pargs[k+1],NO);
printf("NOT WEB MACRO:  %s\n",(char*)to_outer((ASCII*)mp0));
}
else
/* 164: */
#line 3466 "./macs.web"

{
p+= 2;


np= name_dir+a;

for(mx= mtext,mx0= np->byte_start;mx0<(np+1)->byte_start;)
*mx++= *mx0++;

*mx++= '\0';
to_outer(mtext);


if(m->built_in)
{
cur_val= a;
STRCPY(mp0,"<built-in>");
mp= mp0+STRLEN(mp0)+1;
}
else
{
q0= m->tok_start+m->moffset;
q1= m->tok_start+m->nbytes;

str_to_mb(q0,q1,NO);
mp++;
to_outer((ASCII*)mp0);
}


printf("%s",(char*)mtext);

if(m->nargs||m->var_args)
{
eight_bits n;

printf("(");
for(n= 0;n<m->nargs;n++)
printf("$%d%s",(int)n,
CHOICE(n==(eight_bits)(m->nargs-1),"",","));
if(m->var_args)printf("%s...",
CHOICE(m->nargs,",",""));
printf(")");
}

printf(" = %s\n",(char*)(mp= mp0));

if(xflag)
{

mp0= mp;
str_to_mb(p,pargs[k+1],NO);
mp++;
to_outer((ASCII*)mp0);


mp1= xmacro(m,&p,&pargs[k+1],NO,mp);
*mp++= '\0';
mp2= mp;
str_to_mb(mp1,mp,NO);
mp++;
to_outer((ASCII*)mp2);

printf("%s%s = %s\n",(char*)mtext,(char*)mp0,(char*)(mp= mp2));

if(p!=pargs[k+1])

err0_print(ERR_M,OC("Extra text after macro call"),0);
}
}


/* :164 */
#line 3457 "./macs.web"


mp= mp0;
}

FREE_MEM(mtext,"_dumpdef_:mtext",MTEXT_SIZE,ASCII);
}

/* :163 */
/* 166: */
#line 3563 "./macs.web"

SRTN
i_keyword_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p= pargs[0]+1,HUGE*p1= pargs[1];

CHK_ARGS("$KEYWORD",1);

if(*p!=stringg)
{
MUST_QUOTE("$KEYWORD",p,p1);
return;
}

MCHECK(1,"stringg0");
*mp++= *p++;

x_keyword(&mp,macrobuf_end,p,p1-1,YES,YES,WEB_FILE);

MCHECK(1,"stringg1");
*mp++= stringg;
}

/* :166 */

