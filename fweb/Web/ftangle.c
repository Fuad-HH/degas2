#if(0)
  FTANGLE v1.62,\
 created with UNIX on "Friday, November 17, 2017 at 13:24." \
  COMMAND LINE: "./ftangle ./ftangle -uCONFIG -mCONFIG -mGCC -= ftangle.c"\
  RUN TIME:     "Friday, November 17, 2017 at 13:51."\
  WEB FILE:     "./ftangle.web"\
  CHANGE FILE:  (none)
#endif
#define _FTANGLE_h  
#define _FWEB_h   \

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

#define RST_LAST_EXPR  {plast_char= last_char;last_xpr_overflowed= NO;} \

#define INDENT_SIZE  2 \
 \

#define NO_INDENT  0
#define INDENT  2 \

#define OUT_FILE  outp_file[lan_num(out_language)] \
 \

#define C_printf(c,a) \
{ \
if(!out_file)open_out(OC(""),YES); \
if(fprintf(out_file,c,a)<0)out_error(OC("fprintf")); \
} \

#define NOT_CONTINUATION  0
#define CONTINUATION  1 \

#define N_STRBUF  150 \

#define send_new_line  RST_LAST_EXPR flush0();PUTC('\n') \

#define NEWLINE_TO_FORTRAN(continuation_flag) \
flush_out(YES); \
rst_out(continuation_flag) \
 \

#define TO_BUFFER(type) \
if(!nuweb_mode) \
{ \
px= t_style.meta[lan_num(language)].msg.type; \
STRCPY(outp_buf,px); \
out_pos= STRLEN(px); \
} \

#define CUR_BUF  (pai->text_buf[pai->ilevel]) \

#define module_flag  (sixteen_bits)max_texts \
 \

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

#define UNNAMED_MODULE  0 \

#define UNNAMED_MOD  "unnamed"
#define flush_buffer()C_putc('\n') \

#define NEWLINE  puts("") \

#define BP_MARKER  1 \

#define PROPER_END(end) \
end= (np+1)->byte_start; \
if(*end==BP_MARKER&&np!=npmax)end= ((BP*)end)->byte_start \

#define MAX_ID_LENGTH  32 \

#define GLOBAL_SCOPE  YES
#define LOCAL_SCOPE  NO \

#define CHECK_OPEN  if(!out_file)open_out(OC(""),GLOBAL_SCOPE) \

#define OUT_OP(s)out_op(OC(s))
#define OUT_STR(s)out_str(OC(s)) \

#define F_OP(op77,op88)(Fortran88?op88:op77) \

#define LINE_CHAR  '@' \

#define stringg  (eight_bits)'\2'
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

#define MAYBE_SET_OUTPUT(l)if(last_char!='|')set_output_file(l) \

#define RETURN(pcode)return(eight_bits)pcode \

#define compress(c)if(loc++<=limit)return(eight_bits)(c)
#define Fcompress(c)if(is_FORTRAN_(language)&&loc<limit) \
return(eight_bits)(c)
#define STOP  (boolean)YES
#define DONT_STOP  (boolean)NO \
 \

#define app_repl(c){if(tok_ptr==tok_m_end) \
OVERFLW("tokens","tt"); \
*tok_ptr++= (eight_bits)(c);} \

#define BP_BUF_SIZE  (13+MAX_ID_LENGTH) \
 \
 \

#define N_IDBUF  100
#define TOO_BIG   \
 \
err0_print(ERR_T,OC("Construction too big to convert on \
this machine; max is 0x%x"),1,ULONG_MAX); \

#define MAX_LEVEL  20 \
 \
 \

#define EXPAND  YES \

#define DEF_OR_NDEF(flag) \
found_else= NO; \
if(!expand) \
{ \
to_endif(m_ifdef); \
goto next_macro_token; \
} \
else \
{ \
text_pointer m; \
if((next_control= get_next())!=identifier) \
{ \
 \
err0_print(ERR_T,OC("Expected identifier after @#ifdef \
or @#ifndef; assuming not defined"),0); \
if_switch= NO; \
} \
else if_switch=  \
BOOLEAN(flag((m= MAC_LOOKUP(ID_NUM(id_first,id_loc)))!=NULL \
&&!(m->built_in))); \
 \
if(if_switch) \
{ \
GET_LINE; \
 \
scan_text(text_type,p,if_switch); \
} \
else \
{ \
expand= NO;to_else(); \
 \
if(next_control!=m_endif) \
{ \
scanned_if= YES; \
goto next_macro_token; \
} \
else \
{ \
next_control= ignore; \
expand= YES; \
GET_LINE; \
 \
break; \
} \
} \
} \
 \
 \

#define M_TRUE  
#define M_FALSE  ! \

#define GET_LINE   \
if(!from_buffer) \
if(language!=TEX) \
get_line() \

#define OUT_OF_ORDER(cmd)out_of_order((outer_char*)cmd) \

#define IS_PROTECTED(np)((npq= (text_pointer)(np->equiv))&&npq->protected) \

#define LKWD  "$L_KEYWORD" \

#define SPCS_AFTER_CMNT  1 \

/* 1: */
#line 23 "./ftangle.web"

/* 6: */
#line 16 "./typedefs.hweb"


#ifndef part
#define part 0 
#else
#if(part != 1 && part != 2 && part != 3)
#define part 1 
#endif
#endif 


/* :6 */
/* 7: */
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


/* :7 */
#line 24 "./ftangle.web"


/* 35: */
#line 440 "./typedefs.hweb"

#include "typedefs.h"



#line 84 "./ftangle.web"

#line 8 "./val.hweb"

/* :35 */
/* 319: */
#line 8790 "./ftangle.web"


#include "map.h" 

/* :319 */
#line 26 "./ftangle.web"

/* 36: */
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
#line 86 "./ftangle.web"

#line 8 "./macs.hweb"

/* :36 */
/* 37: */
#line 49 "./macs.hweb"


typedef struct
{
sixteen_bits token[MAX_XLEVELS];
int level;
}XIDS;

/* :37 */
/* 70: */
#line 922 "./ftangle.web"




typedef struct
{
outer_char HUGE*start,HUGE*pos,HUGE*end;
}TEXT_BUF;


typedef struct
{
int ilevel;
TEXT_BUF HUGE*HUGE*text_buf;
TEXT_BUF HUGE*last_buf;
}PAREN_LEVEL;

EXTERN PAREN_LEVEL HUGE*paren_level,HUGE*paren_level_end,HUGE*pai;

EXTERN int rparen TSET(NO);


/* :70 */
/* 76: */
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

/* :76 */
/* 88: */
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

/* :88 */
/* 128: */
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
#line 2405 "./ftangle.web"

/* :128 */
/* 219: */
#line 5746 "./ftangle.web"


typedef struct
{
ASCII HUGE*start,HUGE*end;
}TEMPLATE;

/* :219 */
#line 27 "./ftangle.web"

/* 39: */
#line 91 "./ftangle.web"


#include "t_type.h" 

/* :39 */
#line 28 "./ftangle.web"

/* 34: */
#line 426 "./typedefs.hweb"





#ifdef SMALL_MEMORY
#define N_MSGBUF 2000
#else
#define N_MSGBUF 10000
#endif



/* :34 */
/* 38: */
#line 58 "./macs.hweb"


IN_COMMON STMT_LBL max_stmt;

EXTERN sixteen_bits outp_line[NUM_LANGUAGES]
#ifdef _FTANGLE_h
#if(part == 0 || part == 1)
= {1,1,1,1,1,1,1,1}
#endif 
#endif 
;
#line 88 "./ftangle.web"


/* :38 */
/* 40: */
#line 104 "./ftangle.web"


EXTERN int indnt_size SET(INDENT_SIZE);


EXTERN outer_char HUGE*last_char,HUGE*last_end;
EXTERN outer_char HUGE*plast_char;
EXTERN BUF_SIZE max_expr_chars;

EXTERN boolean last_xpr_overflowed SET(NO);

EXTERN int indent_level SET(0);

/* :40 */
/* 43: */
#line 142 "./ftangle.web"



EXTERN outer_char HUGE*C_buffer,HUGE*pC_end;
EXTERN outer_char HUGE*pC_buffer;
EXTERN BUF_SIZE C_buf_size;


EXTERN outer_char HUGE*split_pos;


EXTERN outer_char HUGE*X_buffer,HUGE*pX_end;
EXTERN outer_char HUGE*pX_buffer;
EXTERN BUF_SIZE X_buf_size;

/* :43 */
/* 57: */
#line 471 "./ftangle.web"


EXTERN int rst_pos SET(0);
EXTERN int out_pos SET(0);
EXTERN boolean in_string SET(NO);
EXTERN boolean in_constant SET(NO);
EXTERN boolean started_vcmnt SET(NO);
EXTERN boolean meta_mode SET(NO);

/* :57 */
/* 60: */
#line 542 "./ftangle.web"


IN_COMMON outer_char outp_buf[];
IN_COMMON int nbuf_length;
EXTERN boolean out_at_beginning SET(YES);

/* :60 */
/* 77: */
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
#line 1104 "./ftangle.web"


/* :77 */
/* 85: */
#line 1205 "./ftangle.web"


EXTERN text_pointer last_unnamed;


/* :85 */
/* 89: */
#line 82 "./stacks.hweb"


EXTERN output_state cur_state;


EXTERN long stck_size;
EXTERN output_state HUGE*stack;
EXTERN stack_pointer stck_end;
EXTERN stack_pointer stck_ptr;
#line 1232 "./ftangle.web"

/* :89 */
/* 94: */
#line 1377 "./ftangle.web"





#undef begin_format_stmt
#define begin_format_stmt (eight_bits)'\14'

#undef end_format_stmt
#define end_format_stmt (eight_bits)'\15'

EXTERN long cur_val;




/* :94 */
/* 98: */
#line 1481 "./ftangle.web"


EXTERN eight_bits sent;

/* :98 */
/* 103: */
#line 1642 "./ftangle.web"


IN_RATFOR sixteen_bits id_function,id_program,id_subroutine;

/* :103 */
/* 105: */
#line 1667 "./ftangle.web"


EXTERN sixteen_bits cur_mod_no SET(0);

/* :105 */
/* 113: */
#line 1835 "./ftangle.web"


EXTERN OUTPUT_STATE out_state;
EXTERN boolean protect;
EXTERN boolean copying_macros SET(NO);
EXTERN boolean in_cdir SET(NO);

/* :113 */
/* 129: */
#line 2407 "./ftangle.web"


EXTERN TRUNC sh;

/* :129 */
/* 135: */
#line 2591 "./ftangle.web"


EXTERN boolean mac_protected SET(NO);

EXTERN boolean send_rp SET(NO);



EXTERN boolean in_version SET(NO);
EXTERN T_META*pmeta;

/* :135 */
/* 146: */
#line 3031 "./ftangle.web"


EXTERN OPEN_FILE HUGE*open_file,HUGE*open_file_end,HUGE*last_file;
EXTERN BUF_SIZE num_files;

/* :146 */
/* 177: */
#line 3986 "./ftangle.web"


EXTERN LINE_NUMBER nearest_line SET(0);

/* :177 */
/* 183: */
#line 4119 "./ftangle.web"


IN_STYLE eight_bits ccode[128];

/* :183 */
/* 190: */
#line 4485 "./ftangle.web"


EXTERN boolean comment_continues SET(NO);

/* :190 */
/* 193: */
#line 4562 "./ftangle.web"


EXTERN name_pointer cur_module SET(NULL);
EXTERN ASCII c;
EXTERN boolean strt_cmnt;
EXTERN boolean strt_point_cmnt;
EXTERN boolean suppress_newline;
EXTERN boolean eat_blank_lines;
EXTERN boolean no_expand SET(NO);
EXTERN boolean insrt_line SET(NO);

/* :193 */
/* 206: */
#line 5128 "./ftangle.web"


EXTERN boolean starts_with_0,hex_constant,bin_constant,floating_constant;

/* :206 */
/* 227: */
#line 6058 "./ftangle.web"


EXTERN text_pointer cur_text;

EXTERN eight_bits next_control;
EXTERN boolean scanning_meta SET(NO);
EXTERN boolean macro_scan SET(NO);

/* :227 */
/* 230: */
#line 6247 "./ftangle.web"


EXTERN boolean breakpoints;

/* :230 */
/* 246: */
#line 6672 "./ftangle.web"


EXTERN int n_unique SET(0);
EXTERN boolean deferred_macro SET(NO);

/* :246 */
/* 274: */
#line 7438 "./ftangle.web"


EXTERN boolean is_WEB_macro SET(NO);
EXTERN boolean scanning_defn;
EXTERN boolean scanning_TeX;

EXTERN boolean nuweb_mode1;

EXTERN int mlevel SET(0);

/* :274 */
/* 276: */
#line 7487 "./ftangle.web"


EXTERN boolean found_else SET(NO);

/* :276 */
/* 286: */
#line 7988 "./ftangle.web"


text_pointer npq;

/* :286 */
/* 305: */
#line 8519 "./ftangle.web"


sixteen_bits lkwd;

/* :305 */
/* 307: */
#line 8539 "./ftangle.web"


EXTERN sixteen_bits num_distinct_modules SET(1);
EXTERN sixteen_bits num_modules;

/* :307 */
/* 313: */
#line 8635 "./ftangle.web"


#if SMALL_MEMORY
#define MSG_BUF_SIZE 5000
#else
#define MSG_BUF_SIZE 50000L
#endif

/* :313 */
#line 29 "./ftangle.web"




#if(part == 0 || part == 1)
/* 2: */
#line 47 "./ftangle.web"


int main FCN((ac,av))
int ac C0("Number of arguments.")
char**av C1("Argument list.")
{
#if TIMING
ini_timer();

#endif 



argc= ac;argv= (outer_char**)(av);

ini_program(tangle);

/* 3: */
#line 73 "./ftangle.web"

{
/* 147: */
#line 3039 "./ftangle.web"

{
ALLOC(OPEN_FILE,open_file,"nf",num_files,0);
last_file= open_file;
open_file_end= open_file+num_files;
}

/* :147 */
#line 75 "./ftangle.web"

common_init();
/* 41: */
#line 118 "./ftangle.web"


ALLOC(outer_char,last_char,"lx",max_expr_chars,0);
last_end= last_char+max_expr_chars;
plast_char= last_char;

/* :41 */
/* 44: */
#line 158 "./ftangle.web"



ALLOC(outer_char,C_buffer,"cb",C_buf_size,0);
pC_end= C_buffer+C_buf_size-1;
pC_buffer= C_buffer;

#if FANCY_SPLIT
/* 47: */
#line 208 "./ftangle.web"

{
split_pos= C_buffer;
}

/* :47 */
#line 166 "./ftangle.web"

#endif 


ALLOC(outer_char,X_buffer,"xb",X_buf_size,0);
pX_end= X_buffer+X_buf_size;
pX_buffer= X_buffer;

/* :44 */
/* 71: */
#line 945 "./ftangle.web"

{
paren_level= GET_MEM("paren_level",t_style.paren.nest,PAREN_LEVEL);
paren_level_end= paren_level+t_style.paren.nest;


for(pai= paren_level;pai<paren_level_end;pai++)
pai->text_buf= GET_MEM("pai->text_buf",t_style.paren.num,
TEXT_BUF HUGE*);

pai= paren_level;
pai->ilevel= 0;
pai->text_buf[0]= pai->last_buf= calloc(1,sizeof(TEXT_BUF));
}

/* :71 */
/* 78: */
#line 1107 "./ftangle.web"


alloc_Rat();

ALLOC(text,text_info,"x",max_texts,0);
text_end= text_info+max_texts-1;

ALLOC(text,txt_dinfo,"dx",dtexts_max,0);
textd_end= txt_dinfo+dtexts_max-1;

ALLOC(eight_bits,tok_mem,"tt",max_toks,0);
tok_m_end= tok_mem+max_toks-1;

ALLOC(eight_bits,tok_dmem,"dt",max_dtoks,0);
tokd_end= tok_dmem+max_dtoks-1;

/* :78 */
/* 90: */
#line 1234 "./ftangle.web"


ALLOC(output_state,stack,"kt",stck_size,1);
stck_end= stack+stck_size;

/* :90 */
/* 148: */
#line 3049 "./ftangle.web"

{
BUF_SIZE cur_num= last_file-open_file;


alloc((outer_char*)"nf",(BUF_SIZE HUGE*)&num_files,
sizeof(*open_file),-1);


open_file= (OPEN_FILE*)REALLOC(open_file,
num_files*sizeof(OPEN_FILE),cur_num*sizeof(OPEN_FILE));
last_file= open_file+cur_num;
open_file_end= open_file+num_files;
}

/* :148 */
#line 77 "./ftangle.web"

/* 79: */
#line 1127 "./ftangle.web"


CAST(text_pointer,text_info)->tok_start= tok_ptr= tok_mem;
CAST(text_pointer,txt_dinfo)->tok_start= tok_dptr= tok_dmem;


text_ptr= text_info+1;text_ptr->tok_start= tok_mem;
txt_dptr= txt_dinfo+1;txt_dptr->tok_start= tok_dmem;

/* :79 */
/* 81: */
#line 1141 "./ftangle.web"


CAST(name_pointer,name_dir)->equiv= (EQUIV)text_info;

/* :81 */
/* 86: */
#line 1211 "./ftangle.web"


last_unnamed= text_info;
CAST(text_pointer,text_info)->text_link= 0;

/* :86 */
/* 184: */
#line 4128 "./ftangle.web"


zero_ccodes();
ccode['/']= begin_vcmnt;



/* 185: */
#line 4147 "./ftangle.web"

{

ini_ccode((outer_char*)"new_module",(outer_char*)" \t*",new_module);


ini_ccode((outer_char*)"begin_code",(outer_char*)"aA",begin_code);

ini_ccode((outer_char*)"module_name",(outer_char*)"<",module_name);


ini_ccode((outer_char*)"definition",(outer_char*)"dD",definition);

ini_ccode((outer_char*)"undefinition",(outer_char*)"uU",undefinition);

ini_ccode((outer_char*)"WEB_definition",(outer_char*)"mM",WEB_definition);

ini_ccode((outer_char*)"formatt",(outer_char*)"fF",formatt);


ini_ccode((outer_char*)"ascii_constant",(outer_char*)"'\"",ascii_constant);

ini_ccode((outer_char*)"verbatim",(outer_char*)"=",verbatim);


ini_ccode((outer_char*)"TeX_string",(outer_char*)"tT",TeX_string);


ini_ccode((outer_char*)"L_switch",(outer_char*)"L",L_switch);

ini_ccode((outer_char*)"begin_C",(outer_char*)"c",begin_C);

ini_ccode((outer_char*)"begin_RATFOR",(outer_char*)"r",begin_RATFOR);

ini_ccode((outer_char*)"begin_FORTRAN",(outer_char*)"n",begin_FORTRAN);

ini_ccode((outer_char*)"begin_nuweb",(outer_char*)"N",begin_nuweb);


ini_ccode((outer_char*)"join",(outer_char*)"&",join);


ini_ccode((outer_char*)"Compiler_Directive",(outer_char*)"?",Compiler_Directive);

ini_ccode((outer_char*)"invisible_cmnt",(outer_char*)"%",invisible_cmnt);



ini_ccode((outer_char*)"xref_roman",(outer_char*)"^",xref_roman);

ini_ccode((outer_char*)"xref_typewriter",(outer_char*)".",xref_typewriter);

ini_ccode((outer_char*)"xref_wildcard",(outer_char*)"9",xref_wildcard);


ini_ccode((outer_char*)"big_line_break",(outer_char*)"#",big_line_break);


ini_ccode((outer_char*)"begin_meta",(outer_char*)"(",begin_meta);

ini_ccode((outer_char*)"end_meta",(outer_char*)")",end_meta);


ini_ccode((outer_char*)"limbo_text",(outer_char*)"l",limbo_text);

ini_ccode((outer_char*)"op_def",(outer_char*)"vV",op_def);

ini_ccode((outer_char*)"macro_def",(outer_char*)"wW",macro_def);

ini_ccode((outer_char*)"short_fcn",(outer_char*)"{",short_fcn);


ini_ccode((outer_char*)"begin_bp",(outer_char*)"B",begin_bp);

ini_ccode((outer_char*)"insert_bp",(outer_char*)"}b",insert_bp);


ini_ccode((outer_char*)"no_mac_expand",(outer_char*)"!",no_mac_expand);

ini_ccode((outer_char*)"set_line_info",(outer_char*)"q",set_line_info);


ini_ccode((outer_char*)"new_output_file",(outer_char*)"oO",new_output_file);


ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"\001",USED_BY_OTHER);
#if 0

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"/",USED_BY_OTHER);
#endif

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"\\",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"_",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"[",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"`]",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"$",USED_BY_OTHER);


ini_ccode((outer_char*)"keyword_name",(outer_char*)"kK",keyword_name);

{
char temp[3];

sprintf(temp,";%c",XCHR(interior_semi));

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)temp,USED_BY_OTHER);
}

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"e",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)":",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)",",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"|",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"~",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"-",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"+",USED_BY_OTHER);

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"p",USED_BY_OTHER);
#if(DEBUG)

ini_ccode((outer_char*)"USED_BY_OTHER",(outer_char*)"012",USED_BY_OTHER);
#endif 
}

/* :185 */
#line 4135 "./ftangle.web"

/* 186: */
#line 4231 "./ftangle.web"

{
reassign(xref_roman,control_text);
reassign(xref_typewriter,control_text);
reassign(xref_wildcard,control_text);
reassign(TeX_string,control_text);

reassign(verbatim,stringg);
}

/* :186 */
#line 4136 "./ftangle.web"

prn_codes();

/* :184 */
/* 218: */
#line 5741 "./ftangle.web"


mod_text[0]= ' ';

/* :218 */
#line 78 "./ftangle.web"

ini_internal_fcns();
ini_Ratfor();
}

#line 1 "./typedefs.hweb"


#line 8 "./formats.hweb"

/* :3 */
#line 64 "./ftangle.web"
;

phase1();
phase2();

return wrap_up();
}

/* :2 */
/* 42: */
#line 125 "./ftangle.web"


SRTN rst_last(VOID)
RST_LAST_EXPR

/* :42 */
/* 45: */
#line 177 "./ftangle.web"


SRTN split_C(VOID)
{
#if FANCY_SPLIT
/* 46: */
#line 192 "./ftangle.web"

{

if(in_string&&split_pos==C_buffer)
{
/* 48: */
#line 218 "./ftangle.web"

{
if(!meta_mode)
*pC_buffer++= '\\';

C_out(C_buffer,pC_buffer,&pC_buffer,OC("\n"),OC(""),NO_INDENT);

}

/* :48 */
#line 197 "./ftangle.web"

return;
}

*pC_buffer= '\0';
split0_C(split_pos);
}

/* :46 */
#line 182 "./ftangle.web"

#else
/* 48: */
#line 218 "./ftangle.web"

{
if(!meta_mode)
*pC_buffer++= '\\';

C_out(C_buffer,pC_buffer,&pC_buffer,OC("\n"),OC(""),NO_INDENT);

}

/* :48 */
#line 184 "./ftangle.web"

#endif 
}

/* :45 */
/* 49: */
#line 228 "./ftangle.web"


#if FANCY_SPLIT

SRTN
split0_C FCN((p))
outer_char*p C1("Position for the split")
{
int indent;


if(p==C_buffer)
{
*pC_buffer++= '\\';
p= pC_buffer;
indent= NO_INDENT;
}
else
indent= INDENT;

C_out(C_buffer,p,&pC_buffer,OC("\n"),OC(""),indent);


/* :49 */
/* 49: */
#line 255 "./ftangle.web"
}
#endif 

/* :49 */
/* 50: */
#line 259 "./ftangle.web"


SRTN
C_out FCN((C_buffer,p,ppC_buffer,end_str,begin_str,indent))
outer_char HUGE*C_buffer C0("Buffer we're working with")
outer_char HUGE*p C0("End (next available pos)")
outer_char HUGE*HUGE*ppC_buffer C0("")
outer_char*end_str C0("")
CONST outer_char*begin_str C0("")
int indent C1("Should the next buffer be indented?")
{
int n= PTR_DIFF(int,*ppC_buffer,p);

if(p>C_buffer)
WRITE1(C_buffer,p-C_buffer)


if(*end_str)
WRITE1(end_str,STRLEN(end_str))


*ppC_buffer= C_buffer;

while(*begin_str)
*(*ppC_buffer)++= *begin_str++;


while(indent--)
*(*ppC_buffer)++= ' ';


if(n)
{
STRNCPY(*ppC_buffer,p,n);
*ppC_buffer+= n;
}

flush0();
/* 47: */
#line 208 "./ftangle.web"

{
split_pos= C_buffer;
}

/* :47 */
#line 297 "./ftangle.web"

}

/* :50 */
/* 51: */
#line 311 "./ftangle.web"


SRTN
C_putc FCN((c))
outer_char c C1("Character to be sent to output.")
{
static CONST outer_char HUGE*prefx= OC("");

CHECK_OPEN;

if(dbg_output)
printf("c = '%c' (0x%x)\n",c,c);

if(at_beginning&&meta_mode&&!nuweb_mode&&(in_string||in_version))
{
at_beginning= NO;
out_pos= 0;
pmeta= &t_style.meta[lan_num(language)];
prefx= OUT_STR(in_version?pmeta->hdr.prefx:pmeta->msg.prefx);
}

switch(language)
{
case RATFOR:
case RATFOR_90:
if(!Ratfor77)
{
RAT_out(c);

break;
}

case FORTRAN:
case FORTRAN_90:
if(reverse_indices
&&((pai>paren_level)||rparen||!(in_string||in_version)))
/* 74: */
#line 1037 "./ftangle.web"

{
switch(c)
{
case '(':
if(rparen)
{

pai->ilevel++;

if(pai->ilevel==(int)t_style.paren.num)
NEW_SPRM("paren.num",t_style.paren.num);

/* 75: */
#line 1097 "./ftangle.web"

{
if(!CUR_BUF)
CUR_BUF= GET_MEM("CUR_BUF",1,TEXT_BUF);
}

#line 8 "./texts.hweb"

/* :75 */
#line 1050 "./ftangle.web"


rparen= NO;
}
else
{

store(CUR_BUF,'(');

(pai+1)->last_buf= CUR_BUF;
pai++;

if(pai==paren_level_end)
NEW_SPRM("paren.nest",t_style.paren.nest);

pai->ilevel= 0;

/* 75: */
#line 1097 "./ftangle.web"

{
if(!CUR_BUF)
CUR_BUF= GET_MEM("CUR_BUF",1,TEXT_BUF);
}

#line 8 "./texts.hweb"

/* :75 */
#line 1067 "./ftangle.web"

}

break;

case ')':
if(!rparen)
rparen= YES;
else
unwind();

break;

default:
if(rparen)
{
unwind();
rparen= NO;
}

if(in_string&&pai==paren_level)
buffer_out(c);
else
store(CUR_BUF,c);

break;
}
}

/* :74 */
#line 347 "./ftangle.web"

else
buffer_out(c);

break;

case LITERAL:
case TEX:
/* 53: */
#line 389 "./ftangle.web"

{
*pX_buffer++= c;

if(c=='\n')
C_out(X_buffer,pX_buffer,&pX_buffer,OC(""),
(outer_char HUGE*)CHOICE(meta_mode&&language==TEX,prefx,OC("")),
NO_INDENT);
else if(pX_buffer==pX_end)
split_X(prefx);
}

/* :53 */
#line 355 "./ftangle.web"

break;

case C:
case C_PLUS_PLUS:
default:
#ifndef mac 
/* 52: */
#line 377 "./ftangle.web"

{
*pC_buffer++= c;

if(c=='\n')
C_out(C_buffer,pC_buffer,&pC_buffer,OC(""),OC(""),NO_INDENT);

else if(pC_buffer==pC_end)
split_C();
}

/* :52 */
#line 362 "./ftangle.web"



#else
if(c=='\n')
flush0();
PUTC(c);
#endif 
break;
}

at_beginning= BOOLEAN(c=='\n');
}

/* :51 */
/* 54: */
#line 402 "./ftangle.web"


SRTN
split_X FCN((prefx))
CONST outer_char HUGE*prefx C1("")
{
outer_char HUGE*p= pX_buffer-1;

WHILE()
{
if(p==X_buffer)
/* 55: */
#line 438 "./ftangle.web"

{

err0_print(ERR_T,OC("Line had to be broken"),0);
C_out(X_buffer,pX_buffer,&pX_buffer,
language==TEX?OC("%\n"):OC("\n"),
OC(""),NO_INDENT);
return;
}

/* :55 */
#line 414 "./ftangle.web"


if(*p==' ')
{
C_out(X_buffer,p+1,&pX_buffer,OC("\n"),
(outer_char HUGE*)CHOICE(meta_mode&&language==TEX,
prefx,OC("")),
NO_INDENT);
return;
}

if(*(p--)=='\\'&&*p!='\\')
{
C_out(X_buffer,p+1,&pX_buffer,
language==TEX?OC("%\n"):OC("\n"),
(outer_char HUGE*)CHOICE(meta_mode&&language==TEX,
prefx,OC("")),
NO_INDENT);
return;
}
}
}

/* :54 */
/* 56: */
#line 457 "./ftangle.web"


static outer_char last_out= '\0';


static boolean is_label= NO;
static boolean should_continue= NO;
static continuation_line= NOT_CONTINUATION;

static STMT_LBL stmt_num[50];

static short do_level= 0;

/* :56 */
/* 58: */
#line 488 "./ftangle.web"

SRTN
C_sprintf FCN(VA_ALIST((fmt,n VA_ARGS)))
VA_DCL(
CONST outer_char fmt[]C0("String to be printed.")
int n C2("Number of arguments to follow."))
{
VA_LIST(arg_ptr)
outer_char temp[N_STRBUF];
outer_char HUGE*t;

VA_START(arg_ptr,n);

#if(NUM_VA_ARGS==1)
{
char*fmt0= va_arg(arg_ptr,char*);

va_arg(arg_ptr,int);
vsprintf((char*)(char*)temp,fmt0,arg_ptr);
}
#else
vsprintf((char*)temp,(CONST char*)fmt,arg_ptr);
#endif
va_end(arg_ptr);

for(t= temp;*t;++t)
C_putc(*t);
}

/* :58 */
/* 59: */
#line 512 "./ftangle.web"


SRTN
RAT_out FCN((c))
outer_char c C1("Output this character to \Ratfor.")
{
switch(c)
{
case end_meta:
send_new_line;
return;

case begin_meta:
if(meta_mode)return;
meta_mode= YES;

case '\n':
send_new_line;
if(meta_mode)PUTC('#');
return;

default:
PUTC(c);
return;
}
}

/* :59 */
/* 61: */
#line 553 "./ftangle.web"


SRTN
buffer_out FCN((c))
outer_char c C1("Output this character to the \Fortran\ buffer.")
{
outer_char*px;




if(compound_assignments&&!send_rp)
if(plast_char>=last_end)
last_xpr_overflowed= YES;
else
*plast_char++= c;

/* 62: */
#line 592 "./ftangle.web"


switch(c)
{
case '\0':if(!in_string)
return;



if(in_string&&started_vcmnt)
{
NEWLINE_TO_FORTRAN(should_continue);
started_vcmnt= NO;
return;
}
break;

case '{':
case '}':

if(!in_string&&xpn_Ratfor)
return;
break;


case ' ':
if(out_at_beginning)
return;
break;

/* 63: */
#line 714 "./ftangle.web"


case '\n':
if(in_cdir)
{
out_pos= 0;
}
else if(!in_string||(in_string&&started_vcmnt))
{
NEWLINE_TO_FORTRAN(NOT_CONTINUATION);

if(in_string&&started_vcmnt)
/* 66: */
#line 794 "./ftangle.web"

{
int k;

if(!meta_mode)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

for(out_pos= 1,k= spcs_after_cmnt;k;k--)
outp_buf[out_pos++]= ' ';
}

nbuf_length= MAX(t_style.output_line_length[lan_num(out_language)],80);
out_at_beginning= NO;
}

/* :66 */
#line 726 "./ftangle.web"

}
else if(!started_vcmnt)
{

should_continue= BOOLEAN(out_pos>rst_pos);


if(should_continue)
{NEWLINE_TO_FORTRAN(NOT_CONTINUATION);}

should_continue= BOOLEAN((!free_Fortran)&&should_continue);
/* 66: */
#line 794 "./ftangle.web"

{
int k;

if(!meta_mode)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

for(out_pos= 1,k= spcs_after_cmnt;k;k--)
outp_buf[out_pos++]= ' ';
}

nbuf_length= MAX(t_style.output_line_length[lan_num(out_language)],80);
out_at_beginning= NO;
}

/* :66 */
#line 738 "./ftangle.web"
;
started_vcmnt= YES;
}

return;


/* :63 */
#line 622 "./ftangle.web"




case ';':
if(!(in_string||in_constant))
{
if(free_Fortran)
outp_buf[out_pos++]= ';';



NEWLINE_TO_FORTRAN(NOT_CONTINUATION);
return;
}
break;

case interior_semi:
case semi:
c= ';';
break;


case begin_meta:
if(!meta_mode&&last_out!='\n')
flush_out(YES);
meta_mode= YES;
if(in_string)
{
TO_BUFFER(top);
if(out_pos>0)
flush_out(YES);
}
rst_out(NOT_CONTINUATION);
return;

case end_meta:
if(in_string)
{
TO_BUFFER(bottom);
if(out_pos>0)
flush_out(YES);
started_vcmnt= NO;
}
else
flush_out(YES);

rst_out(NOT_CONTINUATION);
return;
}



if(out_pos>=nbuf_length)
{
if(free_Fortran)
outp_buf[out_pos++]= '&';

flush_out(YES);
rst_out(CONTINUATION);

if(in_string&&started_vcmnt)
/* 66: */
#line 794 "./ftangle.web"

{
int k;

if(!meta_mode)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

for(out_pos= 1,k= spcs_after_cmnt;k;k--)
outp_buf[out_pos++]= ' ';
}

nbuf_length= MAX(t_style.output_line_length[lan_num(out_language)],80);
out_at_beginning= NO;
}

/* :66 */
#line 684 "./ftangle.web"
;
}

if(out_at_beginning)
{
out_at_beginning= NO;



if(!in_string)
if(isdigit(c)&&!is_label)
{
is_label= YES;
out_pos= 0;
}
else if(c==LINE_CHAR)
{
outp_buf[0]= t_style.line_char[lan_num(language)];

out_pos= 1;
return;
}
else if(c=='#')
out_pos= 0;
}

/* :62 */
#line 570 "./ftangle.web"



if(is_label&&!isdigit(c))
{
is_label= NO;
out_pos= 6+indent_level*INDENT_SIZE;
if(c==':'||c==' ')
return;
}

/* 64: */
#line 748 "./ftangle.web"


if(number_dos&&!continuation_line&&(language==FORTRAN||
language==FORTRAN_90||R66))
{
outer_char HUGE*do_pos;

do_pos= outp_buf+6;

if(out_pos==9)
{
if(STRNCMP(do_pos,"do ",3)==0&&!isdigit(c))
{
sprintf((char*)(do_pos+= 3),"%lu ",
stmt_num[do_level++]= max_stmt++);

while(*do_pos++!='\0')
out_pos++;
}
}
else if((out_pos==10&&STRNCMP(do_pos,"endd",4)==0)||
(out_pos==11&&STRNCMP(do_pos,"end d",5)==0))
{
if(do_level==0)
{

err0_print(ERR_T,OC("Too many END DOs"),0);
*outp_buf= 'C';
}
else
{
sprintf((char*)outp_buf,"%-5lu CONTINUE",
stmt_num[--do_level]);
out_pos= 14;
return;
}
}
}

/* :64 */
#line 581 "./ftangle.web"



last_out= outp_buf[out_pos++]= c;

return;
}

/* :61 */
/* 67: */
#line 811 "./ftangle.web"


SRTN
flush_out FCN((prn_new_line))
boolean prn_new_line C1("Do we print a newline?")
{
outp_buf[out_pos]= '\0';


WRITE1(outp_buf,out_pos)

if(prn_new_line)
{
last_out= '\n';
PUTC(last_out);
flush0();
}
}

/* :67 */
/* 68: */
#line 840 "./ftangle.web"


int
rst_out FCN((continuation))
boolean continuation C1("Is line a continuation?")
{
if(!continuation)
RST_LAST_EXPR



for(out_pos= 0;out_pos<5;++out_pos)
outp_buf[out_pos]= ' ';


outp_buf[out_pos++]= continuation?t_style.cchar:(outer_char)' ';
continuation_line= continuation;
out_at_beginning= BOOLEAN(!continuation_line);

nbuf_length= t_style.output_line_length[lan_num(out_language)];

if(meta_mode)
{
if(!in_string||in_version)
{
outp_buf[0]= begin_comment_char[lan_num(out_language)];

if(!xpn_Ratfor)
out_pos= 1+spcs_after_cmnt;
}

nbuf_length= MAX(nbuf_length,80);
}



if(out_at_beginning&&xpn_Ratfor)
blank_out(indent_level);

return rst_pos= out_pos;
}

/* :68 */
/* 69: */
#line 883 "./ftangle.web"


SRTN
blank_out FCN((n))
int n C1("Number of levels to indent.")
{
outer_char HUGE*p;
int i;

for(i= 0,p= outp_buf+out_pos;i<n*INDENT_SIZE;i++)*p++= ' ';

out_pos+= i;
rst_pos= out_pos;
}

/* :69 */
/* 72: */
#line 964 "./ftangle.web"


SRTN
store FCN((t,c))
TEXT_BUF HUGE*t C0("")
outer_char c C1("")
{
if(pai==paren_level||t==paren_level[0].last_buf)
{
buffer_out(c);
return;
}


if(t->start==NULL)
{
t->pos= t->start= GET_MEM("t->start",t_style.paren.len,outer_char);
t->end= t->start+t_style.paren.len;
}

if(t->pos==t->end)
{
size_t len= PTR_DIFF(size_t,t->end,t->start);

t->start= (outer_char*)REALLOC(t->start,len+t_style.paren.len,len);
t->pos= t->start+len;
t->end= t->start+len+t_style.paren.len;
}

*t->pos++= c;
}

/* :72 */
/* 73: */
#line 1000 "./ftangle.web"


SRTN
unwind(VOID)
{
int i;
TEXT_BUF HUGE*t;
outer_char HUGE*s1;

if(pai==paren_level)
{

err0_print(ERR_T,OC("Missing '('"),0);
buffer_out(')');
return;
}

for(i= pai->ilevel;i>=0;i--)
{
t= pai->text_buf[i];

for(s1= t->start;s1<t->pos;s1++)
store(pai->last_buf,*s1);

t->pos= t->start;

if(i>0)
store(pai->last_buf,',');
}

store(pai->last_buf,')');
pai--;
}


/* :73 */
/* 82: */
#line 1148 "./ftangle.web"


boolean names_match FCN((p,first,l,dummy))
name_pointer p C0("Points to the proposed match.")
CONST ASCII HUGE*first C0("Position of first character of string.")
int l C0("length of identifier.")
eight_bits dummy C1("Not used here")
{
if(length(p)!=l)return NO;
return(boolean)(!STRNCMP(first,p->byte_start,l));
}

/* :82 */
/* 83: */
#line 1161 "./ftangle.web"


SRTN
ini_node FCN((node))
CONST name_pointer node C1("")
{
node->equiv= (EQUIV)text_info;
/* 25: */
#line 193 "./typedefs.hweb"

{


node->mod_info= GET_MEM("mod_info",1,MOD_INFO);

node->mod_info->Ilk= expr;
node->mod_info->params= params;
node->mod_info->params.uses= 0;

node->Language= (boolean)language;
}


/* :25 */
#line 1168 "./ftangle.web"

}

/* :83 */
/* 84: */
#line 1174 "./ftangle.web"


SRTN
ini_p FCN((p,t))
name_pointer p C0("")
eight_bits t C1("")
{}

SRTN
open_tex_file(VOID)
{}

/* :84 */
/* 87: */
#line 1219 "./ftangle.web"


SRTN
store_two_bytes FCN((x))
sixteen_bits x C1("Two-byte token to be entered into |tok_mem|.")
{
if(tok_ptr+2>tok_m_end)OVERFLW("tokens","tt");

*tok_ptr++= (eight_bits)(x>>8);
*tok_ptr++= (eight_bits)(x&0377);
}

#line 8 "./stacks.hweb"

/* :87 */
/* 92: */
#line 1269 "./ftangle.web"


SRTN
push_level FCN((p,b0,b1))
name_pointer p C0("The new replacement text.")
CONST eight_bits HUGE*b0 C0("If |p == NULL|, beginning of new \
stuff in memory.")
CONST eight_bits HUGE*b1 C1("If |p == NULL|, end of new stuff in \
memory.")
{
if(stck_ptr==stck_end)
OVERFLW("stack levels","kt");


cur_mp= mp;
*stck_ptr= cur_state;


cur_name= p;

if(p!=NULL)
{
cur_repl= (text_pointer)p->equiv;

if(cur_repl==NULL)

confusion(OC("push_level"),OC("cur_repl is NULL"));

cur_byte= cur_repl->tok_start;
cur_end= cur_byte+cur_repl->nbytes;
}
else
{
cur_repl= NULL;

cur_byte= (eight_bits HUGE*)b0;
cur_end= (eight_bits HUGE*)b1;
}

new_mbuf();




(stck_ptr++)->params= cur_params= cur_global_params= 
(p!=NULL)?params:params;
set_output_file(cur_language);
cur_mod= UNNAMED_MODULE;
}

/* :92 */
/* 93: */
#line 1323 "./ftangle.web"


boolean
pop_level(VOID)
{
if(cur_repl!=NULL&&cur_repl->text_link<module_flag)
{

cur_repl= cur_repl->text_link+text_info;
cur_byte= cur_repl->tok_start;
cur_end= cur_byte+cur_repl->nbytes;


if(cur_repl->module_text)
{
params= cur_params= cur_global_params;
frz_params();
set_output_file(cur_language);
}

return YES;
}

if(macrobuf)
FREE_MEM(macrobuf,"macrobuf",mbuf_size,eight_bits);

stck_ptr--;

if(stck_ptr>stack)
{
cur_state= *stck_ptr;
mp= cur_mp;

if(cur_language!=language)
flush_buffer();

set_output_file(cur_language);
return YES;
}

return NO;
}

/* :93 */
/* 95: */
#line 1396 "./ftangle.web"


eight_bits
get_output(VOID)
{
sixteen_bits a;

restart:
if(stck_ptr==stack)
return NO;

if(cur_byte==cur_end)
{
cur_val= -((long)cur_mod);



if(cur_val!=ignore)
OUT_CHAR(module_number);


pop_level();

if(cur_val==ignore)
goto restart;

return module_number;
}

/* 102: */
#line 1604 "./ftangle.web"

{
a= *cur_byte++;

if((in_string&&!nuweb_mode)||TOKEN1(a))
{
/* 99: */
#line 1489 "./ftangle.web"

{
send_single(a);
}

/* :99 */
#line 1610 "./ftangle.web"
;
return sent;
}
else
{
a= IDENTIFIER(a,*cur_byte++);

switch(a/MODULE_NAME)
{
case 0:
cur_val= a;
/* 104: */
#line 1649 "./ftangle.web"

{
IN_RATFOR boolean balanced;
IN_RATFOR ASCII cur_delim;

if(!balanced&&language==RATFOR&&
(a==id_function||a==id_program||a==id_subroutine))
{

RAT_error(ERROR,OC("Inserted missing '%c' at beginning of function"),1,XCHR(cur_delim));
cur_byte-= 2;
return OUT_CHAR(cur_delim);
}
}

/* :104 */
#line 1621 "./ftangle.web"

return OUT_CHAR(identifier);

case 1:
/* 109: */
#line 1726 "./ftangle.web"

{
name_pointer np;

a-= MODULE_NAME;

np= name_dir+a;

if(np->equiv!=(EQUIV)text_info)
push_level(np,NULL,NULL);
else if(a!=UNNAMED_MODULE)
{
CLR_PRINTF(ERRORS_ONLY,error,("\n! Not present: "));
CLR_PRINTF(ERRORS_ONLY,md_name,("<"));
prn_id(np);

err0_print(ERR_NULL,OC(">. "),0);

SET_COLOR(ordinary);
/* 111: */
#line 1773 "./ftangle.web"

{
#define TEMP_LEN 300

static eight_bits temp[TEMP_LEN],temp1[TEMP_LEN];
sixteen_bits stub;
size_t n= (size_t)length(np);

id_first= x__to_ASCII(OC("$STUB"));
stub= ID_NUM(id_first,id_first+5);

STRNCPY(temp1,np->byte_start,n);
temp1[n]= '\0';


if(
nsprintf(temp,OC("%c%c%c%c%s%c%c"),7,LEFT(stub,ID0),RIGHT(stub),'(',stringg,temp1,stringg,')')>=(int)(TEMP_LEN))OVERFLW("temp","");
#line 1790 "./ftangle.web"
copy_out(temp,temp+6+n,macro);
OUT_CHAR('\n');

#undef TEMP_LEN
}

/* :111 */
#line 1744 "./ftangle.web"

}
}

/* :109 */
#line 1625 "./ftangle.web"

goto restart;

default:
cur_val= a-MODULE_NUM;
if(cur_val>UNNAMED_MODULE)cur_mod= (sixteen_bits)cur_val;


return OUT_CHAR(module_number);

}
}
}

/* :102 */
#line 1425 "./ftangle.web"

}

/* :95 */
/* 96: */
#line 1430 "./ftangle.web"


eight_bits
get_saved_output FCN((stck_ptr0))
stack_pointer stck_ptr0 C1("")
{
sixteen_bits a;

restart:
if(stck_ptr==stack||stck_ptr!=stck_ptr0)
return NO;

if(DONE_LEVEL)
{
if(!pop_level())

confusion(OC("get_saved_output"),OC("Shouldn't encounter top level here"));
return ignore;
}

/* 102: */
#line 1604 "./ftangle.web"

{
a= *cur_byte++;

if((in_string&&!nuweb_mode)||TOKEN1(a))
{
/* 99: */
#line 1489 "./ftangle.web"

{
send_single(a);
}

/* :99 */
#line 1610 "./ftangle.web"
;
return sent;
}
else
{
a= IDENTIFIER(a,*cur_byte++);

switch(a/MODULE_NAME)
{
case 0:
cur_val= a;
/* 104: */
#line 1649 "./ftangle.web"

{
IN_RATFOR boolean balanced;
IN_RATFOR ASCII cur_delim;

if(!balanced&&language==RATFOR&&
(a==id_function||a==id_program||a==id_subroutine))
{

RAT_error(ERROR,OC("Inserted missing '%c' at beginning of function"),1,XCHR(cur_delim));
cur_byte-= 2;
return OUT_CHAR(cur_delim);
}
}

/* :104 */
#line 1621 "./ftangle.web"

return OUT_CHAR(identifier);

case 1:
/* 109: */
#line 1726 "./ftangle.web"

{
name_pointer np;

a-= MODULE_NAME;

np= name_dir+a;

if(np->equiv!=(EQUIV)text_info)
push_level(np,NULL,NULL);
else if(a!=UNNAMED_MODULE)
{
CLR_PRINTF(ERRORS_ONLY,error,("\n! Not present: "));
CLR_PRINTF(ERRORS_ONLY,md_name,("<"));
prn_id(np);

err0_print(ERR_NULL,OC(">. "),0);

SET_COLOR(ordinary);
/* 111: */
#line 1773 "./ftangle.web"

{
#define TEMP_LEN 300

static eight_bits temp[TEMP_LEN],temp1[TEMP_LEN];
sixteen_bits stub;
size_t n= (size_t)length(np);

id_first= x__to_ASCII(OC("$STUB"));
stub= ID_NUM(id_first,id_first+5);

STRNCPY(temp1,np->byte_start,n);
temp1[n]= '\0';


if(
nsprintf(temp,OC("%c%c%c%c%s%c%c"),7,LEFT(stub,ID0),RIGHT(stub),'(',stringg,temp1,stringg,')')>=(int)(TEMP_LEN))OVERFLW("temp","");
#line 1790 "./ftangle.web"
copy_out(temp,temp+6+n,macro);
OUT_CHAR('\n');

#undef TEMP_LEN
}

/* :111 */
#line 1744 "./ftangle.web"

}
}

/* :109 */
#line 1625 "./ftangle.web"

goto restart;

default:
cur_val= a-MODULE_NUM;
if(cur_val>UNNAMED_MODULE)cur_mod= (sixteen_bits)cur_val;


return OUT_CHAR(module_number);

}
}
}

/* :102 */
#line 1450 "./ftangle.web"

}

/* :96 */
/* 97: */
#line 1459 "./ftangle.web"


SRTN
copy_out FCN((p0,p1,is_expr))
CONST eight_bits HUGE*p0 C0("Start of memory buffer.")
CONST eight_bits HUGE*p1 C0("End of memory buffer.")
boolean is_expr C1("Flag for resetting pointer to last expression.")
{
stack_pointer stck_ptr0;


if(is_expr)
rst_last();

push_level(NULL,p0,p1);
stck_ptr0= stck_ptr;

while(get_saved_output(stck_ptr0))
;
}

/* :97 */
/* 100: */
#line 1495 "./ftangle.web"


SRTN
send_single FCN((a))
sixteen_bits a C1("")
{
boolean scope;

switch(a)
{
case begin_language:

switch(sent= *cur_byte++)
{
case NO_LANGUAGE:
scope= *cur_byte++;
a= *cur_byte++;
a= IDENTIFIER(a,*cur_byte++);
new_out(scope,a);
sent= new_output_file;
break;

/* 142: */
#line 2930 "./ftangle.web"


case C:opn_output_file(C);break;
case C_PLUS_PLUS:opn_output_file(C_PLUS_PLUS);break;
case RATFOR:
if(!RAT_OK("(send_single)"))

confusion(OC("output default"),OC("Ratfor command during output"));
opn_output_file(RATFOR);
break;
case RATFOR_90:
if(!RAT_OK("(send_single)"))

confusion(OC("output default"),OC("Ratfor command during output"));
opn_output_file(RATFOR_90);
break;
case FORTRAN:opn_output_file(FORTRAN);break;
case FORTRAN_90:opn_output_file(FORTRAN_90);break;
case TEX:opn_output_file(TEX);break;
case LITERAL:opn_output_file(LITERAL);break

/* :142 */
#line 1517 "./ftangle.web"
;

case NUWEB_OFF:
case NUWEB_ON:
nuweb_mode= BOOLEAN(0x0F&sent);
break;

case no_mac_expand:
mac_protected= no_expand= YES;
break;

case set_line_info:
line_info= *cur_byte++;
break;
}
break;

case dot_const:
cur_val= *cur_byte++;

sent= OUT_CHAR(a);
break;

default:
sent= OUT_CHAR(a);
break;
}
}

/* :100 */
/* 101: */
#line 1549 "./ftangle.web"


#define TEMP_LEN (2*MAX_FILE_NAME_LENGTH)

SRTN
new_out FCN((global_scope,a))
boolean global_scope C0("0 for local, 1 for global")
sixteen_bits a C1("")
{
name_pointer np= name_dir+a;
CONST ASCII HUGE*end;
size_t len;
outer_char temp_from[TEMP_LEN],temp_to[TEMP_LEN];
outer_char temp[MAX_FILE_NAME_LENGTH];

if(global_scope)
{

if(
nsprintf(temp_from,OC("\n\n  (This file was continued via @O from %s.)"),1,params.OUTPUT_FILE_NAME)>=(int)(TEMP_LEN))OVERFLW("temp_from","");
}
else
{

if(
nsprintf(temp_from,OC(" "),0)>=(int)(TEMP_LEN))OVERFLW("temp_from","");
}


PROPER_END(end);
len= PTR_DIFF(size_t,end,np->byte_start);
STRNCPY(temp,np->byte_start,len);
TERMINATE(temp,len);
to_outer((ASCII HUGE*)temp);
new_fname(&params.OUTPUT_FILE_NAME,temp,NULL);


if(global_scope)
{
outer_char old_name[MAX_FILE_NAME_LENGTH];

STRCPY(old_name,global_params.OUTPUT_FILE_NAME);
new_fname(&global_params.OUTPUT_FILE_NAME,temp,NULL);

if(
nsprintf(temp_to,OC("  (Continued via @O to %s.)"),1,params.OUTPUT_FILE_NAME)>=(int)(TEMP_LEN))OVERFLW("temp_to","");
OUT_MSG(to_ASCII(temp_to),NULL);
close_out(out_file,old_name);
}
else
fflush(out_file);

open_out(temp_from,global_scope);
}

#undef TEMP_LEN

/* :101 */
/* 107: */
#line 1680 "./ftangle.web"


SRTN
i_mod_name_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int len;
name_pointer np= cur_name;
eight_bits HUGE*p;

CHK_ARGS("$MODULE_NAME",0);

if(cur_name)
cur_mod_no= (sixteen_bits)(np-name_dir);
else
cur_mod_no= 0;

len= cur_mod_no?(int)length(np):STRLEN(UNNAMED_MOD);
MCHECK(len,"current module name");

if(cur_mod_no)
for(p= np->byte_start;p<(np+1)->byte_start;)
*mp++= *p++;
else
{
STRCPY(mp,UNNAMED_MOD);
to_ASCII(mp);
mp+= len;
}
}

/* :107 */
/* 108: */
#line 1713 "./ftangle.web"


SRTN
i_sect_num_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
num_to_mbuf(n,pargs,"$SECTION_NUM",0,"section number",cur_mod);
}

/* :108 */
/* 112: */
#line 1797 "./ftangle.web"


SRTN
x_mod_a FCN((a))
sixteen_bits a C1("")
{
/* 109: */
#line 1726 "./ftangle.web"

{
name_pointer np;

a-= MODULE_NAME;

np= name_dir+a;

if(np->equiv!=(EQUIV)text_info)
push_level(np,NULL,NULL);
else if(a!=UNNAMED_MODULE)
{
CLR_PRINTF(ERRORS_ONLY,error,("\n! Not present: "));
CLR_PRINTF(ERRORS_ONLY,md_name,("<"));
prn_id(np);

err0_print(ERR_NULL,OC(">. "),0);

SET_COLOR(ordinary);
/* 111: */
#line 1773 "./ftangle.web"

{
#define TEMP_LEN 300

static eight_bits temp[TEMP_LEN],temp1[TEMP_LEN];
sixteen_bits stub;
size_t n= (size_t)length(np);

id_first= x__to_ASCII(OC("$STUB"));
stub= ID_NUM(id_first,id_first+5);

STRNCPY(temp1,np->byte_start,n);
temp1[n]= '\0';


if(
nsprintf(temp,OC("%c%c%c%c%s%c%c"),7,LEFT(stub,ID0),RIGHT(stub),'(',stringg,temp1,stringg,')')>=(int)(TEMP_LEN))OVERFLW("temp","");
#line 1790 "./ftangle.web"
copy_out(temp,temp+6+n,macro);
OUT_CHAR('\n');

#undef TEMP_LEN
}

/* :111 */
#line 1744 "./ftangle.web"

}
}

/* :109 */
#line 1803 "./ftangle.web"

}

/* :112 */
/* 114: */
#line 1853 "./ftangle.web"


SRTN
flush0()
{



if(phase==1)
return;



if(msg_level>=EVERYTHING&&cur_line%100==0)
{
if(cur_line%500==0)
{CLR_PRINTF(EVERYTHING,line_num,("%u",cur_line));}
else
{
CLR_PRINTF(EVERYTHING,info,("."));
}

UPDATE_TERMINAL;
}

cur_line++;
OUTPUT_LINE++;
}

/* :114 */
/* 115: */
#line 1885 "./ftangle.web"


SRTN
phase2(VOID)
{
phase= 2;

params= global_params;
frz_params();
set_output_file(global_language);


rst_out(NOT_CONTINUATION);

if(msg_level>=SHORT_INFO)
{
CLR_PRINTF(SHORT_INFO,info,("\nWriting the %soutput file(s):",
compare_outfiles?"temporary ":""));
printf("  ");
UPDATE_TERMINAL;
}

cur_line= 1;

if(CAST(text_pointer,text_info)->text_link==0)
{
CLR_PRINTF(WARNINGS,warning,("\n! No program text was specified."));
mark_harmless;

}
else
{
/* 125: */
#line 2205 "./ftangle.web"

{
name_pointer np;

npmax= name_ptr-1;

if(truncate_ids)
{
unsigned n= 0;

printf("\nTruncating %u identifiers...",
PTR_DIFF(unsigned,name_ptr,name_dir));

for(np= name_dir+1;np<name_ptr;np++)
n+= trunc_id(np);

printf("\n%u truncation(s) performed.",n);
}

not_unique();
}

/* :125 */
#line 1917 "./ftangle.web"
;

/* 91: */
#line 1247 "./ftangle.web"

{
stck_ptr= stack+1;
cur_name= name_dir;

cur_repl= CAST(text_pointer,text_info)->text_link+text_info;
cur_byte= cur_repl->tok_start;
cur_end= cur_byte+cur_repl->nbytes;

cur_mod= UNNAMED_MODULE;

params= cur_params= cur_global_params= global_params;
frz_params();
}

/* :91 */
#line 1919 "./ftangle.web"
;
/* 122: */
#line 2089 "./ftangle.web"

{
sixteen_bits a;
text_pointer cur_text;
boolean is_def;


copying_macros= YES;

for(cur_text= text_info+1;cur_text<text_ptr;cur_text++)
if(cur_text->text_link==macro)
{
cur_byte= cur_text->tok_start;
cur_end= cur_byte+cur_text->nbytes;

is_WEB_macro= 
BOOLEAN(!((is_def= BOOLEAN(cur_text->nargs==OUTER_MACRO))||
cur_text->nargs==OUTER_UNMACRO));


if(is_WEB_macro)
{
#if(0)
see_macro(cur_byte,cur_end)
#endif
;}
else
{
/* 123: */
#line 2131 "./ftangle.web"

{
LANGUAGE language0;
T_OUTER*po= &t_style.outer_start[lan_num(language)];
outer_char*outer_macro;

out_state= MISCELLANEOUS;

set_output_file((LANGUAGE)cur_text->Language);


protect= YES;

outer_macro= OC(is_def?po->def:po->undef);
language0= language;

C_sprintf(outer_macro,0);

stck_ptr= stack;
push_level(NULL,cur_byte,cur_end);

WHILE()
/* 124: */
#line 2165 "./ftangle.web"

{
if(DONE_LEVEL&&!pop_level())
break;

a= *cur_byte++;

if(cur_byte==cur_end&&a=='\n')
continue;

if(TOKEN1(a))
/* 99: */
#line 1489 "./ftangle.web"

{
send_single(a);
}

/* :99 */
#line 2176 "./ftangle.web"

else
{
a= IDENTIFIER(a,*cur_byte++);

if(a<MODULE_NAME)
{
cur_val= a;
OUT_CHAR(identifier);
}
else if(a!=MODULE_NUM)
{

confusion(OC("copy outer"),OC("Macros defs have strange char 0x%x"),a);
}
else
{
cur_mod= (sixteen_bits)(a-MODULE_NUM);
cur_val= (long)cur_mod;
OUT_CHAR(module_number);
}

}
}

/* :124 */
#line 2153 "./ftangle.web"


cur_state= *stck_ptr;
mp= cur_mp;

set_output_file(language0);

protect= NO;
flush_buffer();
}

/* :123 */
#line 2117 "./ftangle.web"

FREE_MEM(cur_text->tok_start,
"macro space",cur_text->nbytes,eight_bits);

}
}

copying_macros= NO;
}

/* :122 */
#line 1920 "./ftangle.web"
;

/* 91: */
#line 1247 "./ftangle.web"

{
stck_ptr= stack+1;
cur_name= name_dir;

cur_repl= CAST(text_pointer,text_info)->text_link+text_info;
cur_byte= cur_repl->tok_start;
cur_end= cur_byte+cur_repl->nbytes;

cur_mod= UNNAMED_MODULE;

params= cur_params= cur_global_params= global_params;
frz_params();
}

/* :91 */
#line 1922 "./ftangle.web"
;

while(get_output())
;

flush_buffer();

if(compare_outfiles)
cmp_outfiles();

CLR_PRINTF(SHORT_INFO,info,("\nDone."));
}
}

/* :115 */
/* 116: */
#line 1938 "./ftangle.web"

SRTN
out_version FCN((msg))
CONST outer_char*msg C1("")
{
outer_char HUGE*temp= GET_MEM("version:temp",N_MSGBUF,outer_char);
boolean in_string0= in_string;
OUTPUT_STATE out_state0= out_state;


if(
nsprintf(temp,OC("  FTANGLE v%s,\n created with %s on \"%s, %s at %s.\" %s\n"),6,"1.62",the_system,"Friday","November 17, 2017","13:51",local_banner)>=(int)(N_MSGBUF))OVERFLW("temp","");
STRCAT(temp,cmd_ln_buf);
STRCAT(temp,msg);

in_version= YES;
in_string= NO;


OUT_MSG(to_ASCII(temp),NULL);
FREE_MEM(temp,"version:temp",N_MSGBUF,outer_char);
in_version= NO;

in_string= in_string0;
out_state= out_state0;

if(line_info)
out_pos= 0;
else
{
rst_out(NOT_CONTINUATION);
}

if(FORTRAN_LIKE(language))
{
started_vcmnt= NO;

rst_out(NOT_CONTINUATION);
}
}

/* :116 */
/* 118: */
#line 1986 "./ftangle.web"


SRTN
i_version_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
CHK_ARGS("$VERSION",0);

mcopy(version);
}

/* :118 */
/* 120: */
#line 2021 "./ftangle.web"


SRTN
i_tm_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits HUGE*p;
struct tm*t;

CHK_ARGS("$TM",1);

p= pargs[0]+1;

if(*p++!=constant)
{

macro_err(OC("! Argument of $TM must be numerical constant"),YES);
return;
}

t= the_localtime();

switch(*p-'0')
{
case 0:
mcopy(the_day(t));
break;

case 1:

MCHECK(2,"the_cdate");
*mp++= '`';
mcopy(the_cdate(t));
*mp++= '`';
break;

case 2:
mcopy(the_time(t));
break;

default:

macro_err(OC("! Invalid case in _tm_"),YES);
break;
}
}

/* :120 */
/* 121: */
#line 2069 "./ftangle.web"


SRTN
mcopy FCN((s))
CONST outer_char*s C1("")
{
int n= STRLEN(s);

MCHECK(n,"mcopy");
STRCPY(mp,x_to_ASCII(s));
mp+= n;
}

/* :121 */
/* 126: */
#line 2234 "./ftangle.web"


SRTN
not_unique(VOID)
{
TRUNC HUGE*s,HUGE*HUGE*ss,HUGE*HUGE*ss0,HUGE*HUGE*ss1;
LANGUAGE Language;
int l;
size_t n;
size_t num_max;
BP HUGE*HUGE*bb0;
boolean found_dup= NO;

for(l= 0;l<NUM_LANGUAGES;l++)
{
Language= lan_enum(l);


n= 0;

for(s= &sh;s->next;s= s->next)
{
if(!((boolean)s->Language&(boolean)Language))continue;

if(s->num[l]>1)
{
char temp[10];
unsigned len= tr_max[l];

sprintf(temp,len?"%u":"*",len);

if(n==0)
{
printf("\n\n%c! Non-unique \
%s variables (filtered with {%s}, truncated to length %s):",
beep(1),languages[l],filter_char[l],temp);
found_dup= YES;
}
n++;
}
}

if(n==0)continue;


ss1= ss0= ss= GET_MEM("ss",n,TRUNC HUGE*);
num_max= 0;

for(s= &sh;s->next;s= s->next)
{
if(!((boolean)s->Language&(boolean)Language))continue;

if(s->num[l]>1)
{
*ss++= s;
num_max= MAX(num_max,s->num[l]);
}
}


QSORT(ss0,n,sizeof(TRUNC HUGE*),cmpr_trunc);


bb0= GET_MEM("bb",num_max,BP HUGE*);

while(ss1<ss)
see_dup(*ss1++,Language,bb0);

FREE_MEM(ss0,"ss",n,TRUNC HUGE*);
FREE_MEM(bb0,"bb",num_max,BP HUGE*);
}

if(found_dup)
NEWLINE;
}

SRTN
see_dup FCN((s,Language,bb0))
CONST TRUNC HUGE*s C0("")
LANGUAGE Language C0("")
BP HUGE*HUGE*bb0 C1("")
{
BP HUGE*b,HUGE*HUGE*bb,HUGE*HUGE*bb1;
int n;

NEWLINE;
printf(" ");
n= see(s->id,s->id_end);


for(n= tr_max[lan_num(Language)]+1-n;n>0;n--)printf(" ");
printf("<=");


for(b= s->first,bb= bb0;b!=NULL;b= b->next)
{
if(!((boolean)b->Language&(boolean)Language))continue;

*bb++= b;
}

QSORT(bb0,bb-bb0,sizeof(BP HUGE*),cmpr_bp);

for(bb1= bb0;bb1<bb;bb1++)
{
printf(" ");
see((*bb1)->byte_start,(*bb1)->byte_end);
}
}

int
see FCN((c0,c1))
CONST ASCII HUGE*c0 C0("Beginning.")
CONST ASCII HUGE*c1 C1("end.")
{
int n= PTR_DIFF(int,c1,c0);

while(c0<c1)
printf("%c",XCHR(*c0++));

return n;
}

/* :126 */
/* 127: */
#line 2358 "./ftangle.web"


int
cmpr_trunc FCN((t0,t1))
TRUNC HUGE**t0 C0("")
TRUNC HUGE**t1 C1("")
{
switch(web_strcmp((*t0)->id,(*t0)->id_end,(*t1)->id,(*t1)->id_end))
{
case EQUAL:
return 0;

case LESS:
case PREFIX:
return-1;

case GREATER:
case EXTENSION:
return 1;
}

return 0;
}

int cmpr_bp FCN((bb0,bb1))
BP HUGE**bb0 C0("")
BP HUGE**bb1 C1("")
{
switch(web_strcmp((*bb0)->byte_start,(*bb0)->byte_end,
(*bb1)->byte_start,(*bb1)->byte_end))
{
case EQUAL:
return 0;

case LESS:
case PREFIX:
return-1;

case GREATER:
case EXTENSION:
return 1;
}

return 0;
}

#line 8 "./trunc.hweb"

/* :127 */
/* 130: */
#line 2412 "./ftangle.web"


BP HUGE*b_link FCN((s,Language,p0,p1))
TRUNC HUGE*s C0("")
LANGUAGE Language C0("")
CONST ASCII HUGE*p0 C0("")
CONST ASCII HUGE*p1 C1("")
{
BP HUGE*bp;

bp= GET_MEM("bp",1,BP);

bp->c= BP_MARKER;


bp->Language= Language;


bp->byte_start= p0;
bp->byte_end= p1;


bp->Root= s;
s->Language|= (boolean)Language;
s->num[lan_num(Language)]++;

return bp;
}

/* :130 */
/* 131: */
#line 2443 "./ftangle.web"


TRUNC HUGE*s_link FCN((s,id,len))
TRUNC HUGE*s C0("Points to the current structure, to be \
filled with info.")
CONST ASCII HUGE*id C0("Truncated identifier.")
unsigned short len C1("Length of truncated identifier.")
{

s->id= GET_MEM("s->id",len,ASCII);
STRNCPY(s->id,id,len);
s->id_end= s->id+len;


s->next= GET_MEM("s->next",1,TRUNC);

return s;
}

/* :131 */
/* 132: */
#line 2463 "./ftangle.web"


name_pointer id0_lookup FCN((start,end,l))
CONST ASCII HUGE*start C0("Start of name.")
CONST ASCII HUGE*end C0("end of name.")
LANGUAGE l C1("")
{
name_pointer np;
CONST ASCII HUGE*p0,HUGE*p1;

for(np= name_dir+1;np<name_ptr;np++)
{
if(!(np->Language&(boolean)l)||
np->equiv!=NULL||*(p0= np->byte_start)==BP_MARKER)
continue;

PROPER_END(p1);

if(web_strcmp(p0,p1,start,end)==EQUAL)
return np;
}

return NULL;
}

/* :132 */
/* 134: */
#line 2501 "./ftangle.web"


unsigned
trunc_id FCN((np0))
CONST name_pointer np0 C1("Points to current id structure.")
{
CONST ASCII HUGE*p,HUGE*p0,HUGE*p1;
ASCII temp[N_IDBUF];
ASCII HUGE*t;
unsigned short n;
TRUNC HUGE*s;
name_pointer np;
unsigned short nmax;
LANGUAGE Language;
int l;
unsigned count= 0;

if(np0->Language==(boolean)NO_LANGUAGE||np0->equiv!=NULL)
return 0;

for(l= 0;l<NUM_LANGUAGES;l++)
{
Language= lan_enum(l);
np= np0;




if((nmax= tr_max[l])==0||!(np->Language&(boolean)Language)
||(np->reserved_word&(boolean)Language)
||(np->intrinsic_word&(boolean)Language)
||(np->keyword&(boolean)Language)
||(np->macro_type!=NOT_DEFINED))
continue;


p0= np->byte_start;

if(*p0==BP_MARKER)
continue;

PROPER_END(p1);


for(p= p0,t= temp,n= 0;p<p1&&n<nmax;p++)
if(STRCHR(filter_char[l],(int)XCHR(*p))==NULL)
{
n++;
*t++= *p;
}

n= PTR_DIFF(unsigned short,t,temp);

if(p1-p0==(long)n)
continue;

count++;


for(s= &sh;s->next!=NULL;s= s->next)
if(s->id_end-s->id==(long)n&&
web_strcmp(s->id,s->id_end,temp,t)==EQUAL)
{
another_bp:
s->last= s->last->next= b_link(s,Language,p0,p1);

np->byte_start= (ASCII*)s->last;
goto next_language;
}


s= s_link(s,temp,n);
s->first= s->last= b_link(s,Language,p0,p1);
np->byte_start= (ASCII*)s->first;



if((np= id0_lookup(temp,t,(LANGUAGE)np->Language))!=NULL)
{
p0= np->byte_start;PROPER_END(p1);
goto another_bp;
}

next_language:;
}

return count;
}

/* :134 */
/* 145: */
#line 2988 "./ftangle.web"


SRTN
open_out FCN((msg,global_scope))
CONST outer_char*msg C0("")
boolean global_scope C1("")
{
boolean is_stdout= BOOLEAN(STRCMP(params.OUTPUT_FILE_NAME,"stdout")==0);
boolean already_opened= NO;

if(is_stdout)
out_file= params.OUT_FILE= stdout;
else
{
already_opened= was_opened(params.OUTPUT_FILE_NAME,global_scope,
NULL,&out_file);

params.OUT_FILE= out_file;



if(top_version&&!(already_opened||compare_outfiles))
out_version(msg);
}




if(global_scope)
cur_global_params.OUT_FILE= global_params.OUT_FILE= out_file;


if(!already_opened)
{
CLR_PRINTF(SHORT_INFO,out_file,("(%s)%s",(char*)params.OUTPUT_FILE_NAME,
is_stdout?"\n":""));
UPDATE_TERMINAL;
}
}

/* :145 */
/* 149: */
#line 3071 "./ftangle.web"


boolean was_opened FCN((file_name,global_scope,pname,pfile_ptr))
CONST outer_char HUGE*file_name C0("")
boolean global_scope C0("")
outer_char HUGE*HUGE*pname C0("")
FILE**pfile_ptr C1("")
{
OPEN_FILE HUGE*f;

if(!*file_name)
{
*pname= (outer_char HUGE*)"";
*pfile_ptr= NULL;
return NO;
}


for(f= open_file;f<last_file;f++)
if(STRCMP(f->name,file_name)==0)
{
if(pname)
{
*pname= f->name;
*pfile_ptr= f->ptr;
return f->previously_opened;
}
else
goto open_it;
}

/* 150: */
#line 3120 "./ftangle.web"

{

if(last_file==open_file_end)
{
OVERFLW("previously opened files","nf");
}

last_file->name= GET_MEM("last_file",STRLEN(file_name)+1,outer_char);
STRCPY(last_file->name,file_name);
last_file++;
}

/* :150 */
#line 3102 "./ftangle.web"


if(pname)
{

*pname= f->name;
f->ptr= NULL;
f->previously_opened= NO;
f->global_scope= global_scope;
}
else
/* 151: */
#line 3141 "./ftangle.web"

{
open_it:
f->previously_opened= BOOLEAN(f->previously_opened||(f->ptr!=NULL));

if(f->previously_opened)
{
if(f->ptr==NULL)
f->ptr= FOPEN(compare_outfiles?f->tmp_name:f->name,"a");
}
else
{
if(compare_outfiles)
/* 152: */
#line 3170 "./ftangle.web"

{
char*buffer;
IN_COMMON outer_char wbprefix[MAX_FILE_NAME_LENGTH];

#if(HAVE_TEMPNAM)
extern char*tempnam();

if(!*wbprefix)
STRCPY(wbprefix,"./");

buffer= tempnam((char*)wbprefix,"FTMP");

#else
buffer= tmpnam(NULL);
#endif

f->tmp_name= GET_MEM("f->tmp_name",STRLEN(buffer)+1,outer_char);

STRCPY(f->tmp_name,buffer);

f->ptr= FOPEN(f->tmp_name,"w");
}

/* :152 */
#line 3154 "./ftangle.web"

else
f->ptr= FOPEN(f->name,"w");

if(!(f->ptr))
{

fatal(ERR_T,OC("ABORTING:  "),OC("Can't open output file %s."),file_name);
}
}
}

/* :151 */
#line 3113 "./ftangle.web"


*pfile_ptr= f->ptr;
return f->previously_opened;
}

/* :149 */
/* 153: */
#line 3195 "./ftangle.web"


SRTN
close_out FCN((fp,name))
FILE*fp C0("")
outer_char*name C1("")
{
OPEN_FILE*f;

for(f= open_file;f<last_file;f++)
if(f->ptr==fp)
{
close0(f);
return;
}

confusion(OC("close_out"),
OC("Allegedly open file \"%s\" isn't in list"),name);
}

/* :153 */
/* 154: */
#line 3216 "./ftangle.web"


SRTN
cls_local(VOID)
{
OPEN_FILE*f;

for(f= open_file;f<last_file;f++)
if(f->ptr&&!f->global_scope)
close0(f);
}

/* :154 */
/* 155: */
#line 3229 "./ftangle.web"

SRTN
close0 FCN((f))
OPEN_FILE*f C1("")
{
fclose(f->ptr);
f->ptr= NULL;
f->previously_opened= YES;
}

/* :155 */
/* 156: */
#line 3242 "./ftangle.web"


SRTN
cls_files(VOID)
{}

/* :156 */
/* 157: */
#line 3253 "./ftangle.web"

SRTN
cmp_outfiles(VOID)
{
OPEN_FILE*f;
boolean renamed= NO;

printf("\nRenaming temporary file(s):  ");
UPDATE_TERMINAL;

for(f= open_file;f<last_file;f++)
if(f->previously_opened||f->ptr)
{
FILE*old_ptr= FOPEN(f->name,"r");

if(f->ptr)
fflush(f->ptr);

if(old_ptr)
/* 158: */
#line 3289 "./ftangle.web"

{
int c_old,c_new;
FILE*new_ptr;

if(f->ptr)
new_ptr= freopen((CONST char*)f->tmp_name,"r",f->ptr);
else
new_ptr= FOPEN(f->tmp_name,"r");

if(!new_ptr)

fatal(ERR_T,OC("ABORTING:  "),OC("Can't reopen temporary file %s."),f->tmp_name);

do
{
c_old= getc(old_ptr);
c_new= getc(new_ptr);
}
while(c_old==c_new&&c_old!=EOF);

fclose(old_ptr);
fclose(new_ptr);

if(c_old==c_new)
remove((CONST char*)f->tmp_name);
else
/* 159: */
#line 3324 "./ftangle.web"

{

remove((CONST char*)f->name);

printf("(%s",(char*)f->name);

if(rename((CONST char*)f->tmp_name,(CONST char*)f->name)!=0)
{



#if ANSI_SYSTEM
if(!system(NULL))
{

err0_print(ERR_T,OC("Couldn't rename \"%s\" to \"%s\""),2,f->tmp_name,f->name);
perror("");
}
else
#endif 
{
char temp[256];



#ifndef MV
#ifdef ibmpc
#define MV "rename"
#else
#define MV "mv"
#endif
#endif
sprintf(temp,"%s %s %s",MV,(char*)f->tmp_name,
(char*)f->name);
system(temp);
printf("*");
}
}

printf(")");UPDATE_TERMINAL;

renamed= YES;
}

/* :159 */
#line 3318 "./ftangle.web"

}

/* :158 */
#line 3272 "./ftangle.web"

else
{
fclose(f->ptr);

/* 159: */
#line 3324 "./ftangle.web"

{

remove((CONST char*)f->name);

printf("(%s",(char*)f->name);

if(rename((CONST char*)f->tmp_name,(CONST char*)f->name)!=0)
{



#if ANSI_SYSTEM
if(!system(NULL))
{

err0_print(ERR_T,OC("Couldn't rename \"%s\" to \"%s\""),2,f->tmp_name,f->name);
perror("");
}
else
#endif 
{
char temp[256];



#ifndef MV
#ifdef ibmpc
#define MV "rename"
#else
#define MV "mv"
#endif
#endif
sprintf(temp,"%s %s %s",MV,(char*)f->tmp_name,
(char*)f->name);
system(temp);
printf("*");
}
}

printf(")");UPDATE_TERMINAL;

renamed= YES;
}

/* :159 */
#line 3277 "./ftangle.web"

}
}

if(!renamed)
printf("[no changes]");
}

/* :157 */
/* 160: */
#line 3375 "./ftangle.web"


SRTN
out_op FCN((s))
CONST outer_char HUGE*s C1("String to translate.")
{
out_str(s);

out_state= MISCELLANEOUS;
}

CONST outer_char HUGE*out_str FCN((s0))
CONST outer_char HUGE*s0 C1("")
{
CONST outer_char HUGE*s;

for(s= s0;*s;s++)
C_putc(*s);

return s0;
}

/* :160 */
/* 165: */
#line 3630 "./ftangle.web"


eight_bits
x_identifier FCN((cur_char))
eight_bits cur_char C1("")
{
if(!in_cdir)
/* 169: */
#line 3788 "./ftangle.web"

{
boolean in_macro0= in_macro;
name_pointer np= name_dir+cur_val;
X_FCN(HUGE_FCN_PTR*pf)(VOID);

if(np->expandable&language)
{
expand_special:
in_macro= NO;

pf= np->x_translate[lan_num(language)];

if(pf)
(*pf)();
else

confusion(OC("possibly expand special"),OC("Allegedly expandable keyword has no associated function"));

in_macro= in_macro0;

cur_char= id_keyword;
goto end_identifier;
}
else if(R77&&Fortran88&&!checking_label)
switch(chk_lbl())
{
case YES:goto expand_special;
case-1:goto end_identifier;
case NO:break;
}
}

/* :169 */
#line 3637 "./ftangle.web"
;

if(is_deferred((sixteen_bits)cur_val))
return cur_char;





if(!mac_protected&&(macro_text= MAC_LOOKUP(cur_val))!=NULL)
{
/* 170: */
#line 3823 "./ftangle.web"

{
eight_bits HUGE*p1;


in_macro= YES;


#ifdef DEBUG_MACS
printf("\n<<< 0x%x >>>\n",macrobuf);
find_n(cur_val);
#endif

p1= xmacro(macro_text,&cur_byte,&cur_end,YES,macrobuf);



#ifdef DEBUG_MACS
printf("Expanded into (0x%x->0x%x) <<<%lu>>>\n",p1,mp,p1-macrobuf);
#endif




copy_out(p1,mp,macro);
in_macro= NO;
}

/* :170 */
#line 3648 "./ftangle.web"

return cur_char;
}
else
{
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3653 "./ftangle.web"


if(out_state==NUM_OR_ID&&!nuweb_mode)
C_putc(' ');

/* 171: */
#line 3853 "./ftangle.web"

{
name_pointer np;


np= name_dir+cur_val;

if(truncate_ids)
out_trunc(np);
else
see_id(np->byte_start,(np+1)->byte_start);
}

/* :171 */
#line 3658 "./ftangle.web"
;

if(no_expand)
no_expand= mac_protected= NO;
}

end_identifier:
out_state= in_format?MISCELLANEOUS:NUM_OR_ID;

return cur_char;
}

/* :165 */
/* 166: */
#line 3675 "./ftangle.web"


boolean
is_deferred FCN((cur_val))
sixteen_bits cur_val C1("")
{
name_pointer np;

np= name_dir+cur_val;

if(np->macro_type==DEFERRED_MACRO)
{
text_pointer tp;
eight_bits HUGE*p0,HUGE*p1;
eight_bits a0;

tp= (text_pointer)np->equiv;


p0= tp->tok_start;
p1= p0+tp->nbytes;

while(p0<p1)
{
if(TOKEN1(a0= *p0++))
if(a0=='#')
switch(*p0)
{
case '!':
if(*(p0+1)==MACRO_ARGUMENT)
app_repl(a0)
else
/* 167: */
#line 3746 "./ftangle.web"

{
if(TOKEN1(*++p0))

macro_err(OC("! Macro token `#!' must be followed by identifier"),YES);
else
{
text_pointer m;

if((m= MAC_LOOKUP(IDENTIFIER(*p0,*(p0+1))))==NULL)

macro_err(OC("! Expecting macro identifier after \"#!\""),YES);
else
if(m->nargs>0)

macro_err(OC("! Macro after \"#!\" can't have arguments"),YES);
else
/* 252: */
#line 6876 "./ftangle.web"

{
eight_bits HUGE*q0,HUGE*q1;


q0= m->tok_start+m->moffset;
q1= m->tok_start+m->nbytes;


while(q0<q1)
app_repl(*q0++);
}

/* :252 */
#line 3761 "./ftangle.web"


p0+= 2;
}
}

/* :167 */
#line 3707 "./ftangle.web"

break;

default:
app_repl(a0);
break;
}
else
app_repl(a0)
else
{
app_repl(a0);
app_repl(*p0++);
}
}

cur_text= text_ptr;

cur_text->Language= (boolean)language;
cur_text->nargs= tp->nargs;
cur_text->moffset= tp->moffset;
cur_text->recursive= NO;
cur_text->var_args= tp->var_args;

text_ptr++;

sv_macro();

np= name_dir+IDENTIFIER(tp->tok_start[0],tp->tok_start[1]);
np->macro_type= IMMEDIATE_MACRO;
np->equiv= (EQUIV)cur_text;

return YES;
}

return NO;
}

/* :166 */
/* 172: */
#line 3867 "./ftangle.web"


SRTN
out_ptrunc FCN((cur_val))
sixteen_bits cur_val C1("")
{
/* 171: */
#line 3853 "./ftangle.web"

{
name_pointer np;


np= name_dir+cur_val;

if(truncate_ids)
out_trunc(np);
else
see_id(np->byte_start,(np+1)->byte_start);
}

/* :171 */
#line 3873 "./ftangle.web"

}

/* :172 */
/* 173: */
#line 3877 "./ftangle.web"


SRTN
see_id FCN((start,end))
CONST ASCII HUGE*start C0("Beginning of identifier name.")
CONST ASCII HUGE*end C1("End of identifier name.")
{
CONST ASCII HUGE*j;

for(j= start;j<end;j++)C_putc(XCHR(*j));
}

/* :173 */
/* 174: */
#line 3892 "./ftangle.web"


int
id FCN((n))
int n C1("Identifier number.")
{
printf(_Xx("Id %d (0x%x): \"%s\"\n"),n,n,(char*)name_of((sixteen_bits)n));
return n;
}

/* :174 */
/* 175: */
#line 3905 "./ftangle.web"


outer_char HUGE*name_of FCN((id0))
sixteen_bits id0 C1("Identifier token whose name is sought.")
{
static ASCII temp[MAX_ID_LENGTH];
int k,n;
name_pointer np;
CONST ASCII HUGE*end;

np= name_dir+id0;


if(np>=name_ptr)
{
STRCPY(temp,"???");
return(outer_char HUGE*)temp;
}

PROPER_END(end);

#if 0 
n= MIN(end-np->byte_start,MAX_ID_LENGTH-1);
#else
if(end-np->byte_start<MAX_ID_LENGTH-1)
n= PTR_DIFF(int,end,np->byte_start);
else
n= MAX_ID_LENGTH-1;
#endif

STRNCPY(temp,np->byte_start,n);


if(breakpoints)
for(k= 0;k<n;k++)
if(temp[k]=='\\')temp[k]= '/';

temp[n]= '\0';

return to_outer(temp);
}

/* :175 */
/* 176: */
#line 3949 "./ftangle.web"


CONST ASCII HUGE*proper_end FCN((np))
name_pointer np C1("")
{
CONST ASCII HUGE*end;

PROPER_END(end);
return end;
}

SRTN
out_trunc FCN((np))
CONST name_pointer np C1("")
{
TRUNC HUGE*s;
ASCII HUGE*pc;

pc= np->byte_start;

if(*pc!=BP_MARKER)
{
CONST ASCII HUGE*end;


PROPER_END(end);
see_id((CONST ASCII HUGE*)pc,end);
}
else
{
s= ((BP HUGE*)pc)->Root;
see_id(s->id,s->id_end);
}
}

/* :176 */
/* 179: */
#line 4052 "./ftangle.web"


SRTN
prn_mod_num FCN((fmt,val))
outer_char*fmt C0("")
long val C1("")
{
int l;

if(line_info)
{
l= lan_num(R77_or_F&&!free_90?FORTRAN:language);

if(val<0)
{
val= -val;
#line 4069 "./ftangle.web"
}

if(FORTRAN_LIKE(language))
{
if(out_pos>rst_pos)flush_out(YES);
out_pos= 0;
}

C_sprintf(fmt,3,begin_comment_char[l],val,end_comment_char[l]);
}
/* :179 */
/* 179: */
#line 4103 "./ftangle.web"
}

/* :179 */
/* 187: */
#line 4251 "./ftangle.web"


eight_bits
skip_ahead FCN((last_control,skip_over_bars))
eight_bits last_control C0("Last token that was seen.")
boolean skip_over_bars C1("")
{
eight_bits cc;
int ncc= 0;


ASCII last_char;
ASCII HUGE*lc;
ASCII HUGE*l1= limit+1;

WHILE()
{
if(loc>limit)
{
another_line:
if(from_buffer)
{
undivert();
return ignore;
}
else
{
if(!get_line())
return new_module;

l1= limit+1;
}
}

*l1= '@';

more_stuff:
switch(*loc)
{
case '@':
break;

case '|':
if(skip_over_bars)
{
if(skip_bars()==new_module)return new_module;

continue;
}



default:
loc++;
if(loc>limit)
{
ncc= 2;
goto another_line;
}
goto more_stuff;
}

*l1= ' ';

if(loc>limit)ncc= 2;
else/* 189: */
#line 4393 "./ftangle.web"

{
last_char= ' ';

for(lc= loc-1;lc>=cur_buffer;lc--)
if(*lc!=' ')
{
last_char= *lc;
break;
}

++loc;
++ncc;

switch(cc= ccode[*(loc++)])
{
/* 10: */
#line 80 "./typedefs.hweb"


case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



/* :10 */
#line 4409 "./ftangle.web"
:
loc--;

case L_switch:
{
if(last_char!='|')
{
/* 21: */
#line 139 "./typedefs.hweb"

{
ASCII l= *loc++;

switch(l)
{
/* 11: */
#line 95 "./typedefs.hweb"

case 'c'

/* :11 */
#line 145 "./typedefs.hweb"
:
Cpp= BOOLEAN(*loc=='+');
break;

/* 12: */
#line 98 "./typedefs.hweb"

case 'r'

/* :12 */
#line 149 "./typedefs.hweb"
:
/* 13: */
#line 101 "./typedefs.hweb"

case 'n'

/* :13 */
#line 150 "./typedefs.hweb"
:
Fortran88= BOOLEAN(*loc=='9');
break;

/* 15: */
#line 107 "./typedefs.hweb"

case 'v'



/* :15 */
#line 154 "./typedefs.hweb"
:
/* 14: */
#line 104 "./typedefs.hweb"

case 'x'

/* :14 */
#line 155 "./typedefs.hweb"
:
break;

default:

err0_print(ERR_C,OC("! Invalid language command `@L%c' ignored"),1,XCHR(l));
break;
}

opt_args(l);

}


/* :21 */
#line 4416 "./ftangle.web"

if(module_count==0)global_params= params;
set_output_file(language);
}
continue;
}

case begin_nuweb:
nuweb_mode1= nuweb_mode= !NUWEB_MODE;

if(module_count==0)
global_params= params;

continue;

case control_text:
while((c= skip_ahead(ignore,NO))=='@');


if(*(loc-1)!='>')

err0_print(ERR_T,OC("Improper %s@%s within control text"),2,SSET_COLOR(character),SSET_COLOR(error));

continue;

case compiler_directive:
case Compiler_Directive:
if(scanning_TeX)

err0_print(ERR_T,OC("Compiler directives are allowed only in code"),0);
loc= limit+1;
continue;

case invisible_cmnt:
loc= limit+1;
continue;

case module_name:
if(ncc==1&&last_control==formatt)
{
loc-= 2;
get_next();
continue;
}
break;

case big_line_break:
if(loc>=limit)continue;

/* 33: */
#line 399 "./typedefs.hweb"

{
boolean mcode;

*limit= ' ';
id_first= loc;

while(isAlpha(*loc))
loc++;

if((mcode= is_mcmd(mcmds,id_first,loc))!=0)
{
while(loc<limit&&(*loc==' '||*loc==tab_mark))
loc++;

#ifdef _FWEAVE_h
defd_switch= NO;
#endif

return mcode;
}

loc= id_first;
}


/* :33 */
#line 4465 "./ftangle.web"
;
continue;

case USED_BY_NEITHER:

err0_print(ERR_T,OC("Invalid `@%c' ignored"),1,XCHR(*(loc-1)));
continue;
}

if(cc!=ignore||(*(loc-1)=='>'&&(ncc!=2)&&last_control!=formatt))
return cc;
}

/* :189 */
#line 4316 "./ftangle.web"

}

DUMMY_RETURN(ignore);
}

/* :187 */
/* 188: */
#line 4323 "./ftangle.web"


eight_bits skip_bars(VOID)
{
PARAMS params0;
LANGUAGE language0= language;
eight_bits ret_val;

params0= params;

loc++;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_T,OC("Reached end of file while skipping code text %s"),1,BTRANS);
ret_val= new_module;
goto done;
}

switch(next_control= get_next())
{
case begin_bp:
case insert_bp:
case begin_meta:
case end_meta:
case formatt:
case limbo_text:
case op_def:
case macro_def:
case definition:
case undefinition:
case WEB_definition:
case m_ifdef:
case m_ifndef:
case m_else:
case m_elif:
case m_endif:
case m_for:
case m_endfor:
case m_line:
case m_undef:
case begin_code:

err0_print(ERR_T,OC("Control code not allowed within |...|; \
inserted '|' in %s"),1,MTRANS);
loc-= 2;
ret_val= '|';
goto done;

case new_module:

err0_print(ERR_T,OC("Module%s ended while skipping code text; \
inserted '|'"),1,MTRANS0);

case '|':
ret_val= next_control;
goto done;
}
}

done:
params= params0;
frz_params();
set_output_file(language0);

return ret_val;
}

/* :188 */
#line 34 "./ftangle.web"

#endif 

#if(part == 0 || part == 2)
/* 137: */
#line 2618 "./ftangle.web"


eight_bits
out_char FCN((cur_char))
eight_bits cur_char C1("Token to control or be sent to the output.")
{
switch(cur_char)
{
case ignore:
if(R77_or_F&&started_vcmnt)C_putc(cur_char);
return ' ';



case bell:
return out_dflt(tab_mark);
#line 2635 "./ftangle.web"

case ',':
out_dflt(cur_char);
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2638 "./ftangle.web"

break;

case interior_semi:
if(!(Fortran88||in_string))cur_char= ';';


case ';':
/* 136: */
#line 2604 "./ftangle.web"


if(send_rp)
{
C_putc(')');
send_rp= NO;
}

/* :136 */
#line 2646 "./ftangle.web"
;
return out_dflt(cur_char);

case cdir:
in_cdir= BOOLEAN(!in_cdir);

if(FORTRAN_LIKE(language))
{
in_string= NO;
flush_buffer();
in_string= YES;
}
break;

case '\n':
if((copying_macros||!nuweb_mode)
&&(protect||out_state==VERBATIM))
{





if(copying_macros&&protect&&!in_string)
C_putc(' ');

out_str(t_style.protect_chars[lan_num(language)]);

}
/* 136: */
#line 2604 "./ftangle.web"


if(send_rp)
{
C_putc(')');
send_rp= NO;
}

/* :136 */
#line 2675 "./ftangle.web"
;
flush_buffer();
if(out_state!=VERBATIM)
out_state= MISCELLANEOUS;
break;

/* 164: */
#line 3611 "./ftangle.web"

case end_format_stmt:
in_format= NO;
C_putc(';');
out_state= NUM_OR_ID;
break;

case begin_format_stmt:
in_format= YES;
OUT_OP(" format");
out_state= MISCELLANEOUS;
break;

case identifier:
cur_char= x_identifier(cur_char);
break;


/* :164 */
#line 2681 "./ftangle.web"
;
/* 178: */
#line 3998 "./ftangle.web"


case module_number:
if(cur_val>0)
prn_mod_num(OC("%c* %ld: *%c\n"),cur_val);
else if(cur_val<0)
prn_mod_num(OC("%c* :%ld *%c\n"),cur_val);
else
{
if(line_info)
{
outer_char line_char;

switch(language)
{
case RATFOR:
case RATFOR_90:
case C:
case C_PLUS_PLUS:
case LITERAL:
line_char= '#';
break;

case FORTRAN:
case FORTRAN_90:
line_char= LINE_CHAR;
break;

case TEX:
line_char= '%';
break;
}

nearest_line= (LINE_NUMBER)(BASE2*(*cur_byte++));
nearest_line+= *cur_byte++;

C_sprintf(OC("%cline %u \""),2,
line_char,nearest_line);


cur_val= BASE2*(*cur_byte++);
cur_val+= *cur_byte++;

/* 171: */
#line 3853 "./ftangle.web"

{
name_pointer np;


np= name_dir+cur_val;

if(truncate_ids)
out_trunc(np);
else
see_id(np->byte_start,(np+1)->byte_start);
}

/* :171 */
#line 4041 "./ftangle.web"

C_sprintf(OC("\"\n"),0);
}
else
cur_byte+= 4;
}

break;

/* :178 */
#line 2682 "./ftangle.web"
;
/* 161: */
#line 3401 "./ftangle.web"


case plus_plus:
if(FORTRAN_LIKE(language))
{
/* 163: */
#line 3570 "./ftangle.web"

{
outer_char HUGE*l;



C_putc('=');
plast_char--;
out_state= MISCELLANEOUS;



if(compound_assignments)
{
send_rp= YES;

if(last_xpr_overflowed)
OVERFLW("last expression","lx");

for(l= last_char;isdigit(*l)||!isalpha(*l);l++)
;

if(plast_char-l>=3&&STRNCMP(last_char,"if(",3)==0)

err0_print(ERR_T,OC("Sorry, can't expand compound assignment \
operators correctly after simple IF; please use an IF...THEN construction"),0);

while(l<plast_char)
buffer_out(*l++);

send_rp= NO;
}
else

fatal(ERR_T,OC("ABORTING:  "),OC("Operators `++', `--', `+=', `-=', `*=', and `/=' \
are not allowed; they were turned off by option `-+'."));
}

/* :163 */
#line 3406 "./ftangle.web"
;
buffer_out('+');buffer_out('1');
out_state= MISCELLANEOUS;
}
else
{
if(*(pC_buffer-1)=='+'&&!nuweb_mode)
C_putc(' ');
OUT_OP("++");
}

/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3417 "./ftangle.web"

break;

case minus_minus:
if(FORTRAN_LIKE(language))
{
/* 163: */
#line 3570 "./ftangle.web"

{
outer_char HUGE*l;



C_putc('=');
plast_char--;
out_state= MISCELLANEOUS;



if(compound_assignments)
{
send_rp= YES;

if(last_xpr_overflowed)
OVERFLW("last expression","lx");

for(l= last_char;isdigit(*l)||!isalpha(*l);l++)
;

if(plast_char-l>=3&&STRNCMP(last_char,"if(",3)==0)

err0_print(ERR_T,OC("Sorry, can't expand compound assignment \
operators correctly after simple IF; please use an IF...THEN construction"),0);

while(l<plast_char)
buffer_out(*l++);

send_rp= NO;
}
else

fatal(ERR_T,OC("ABORTING:  "),OC("Operators `++', `--', `+=', `-=', `*=', and `/=' \
are not allowed; they were turned off by option `-+'."));
}

/* :163 */
#line 3423 "./ftangle.web"
;
buffer_out('-');buffer_out('1');
out_state= MISCELLANEOUS;
}
else
{
if(*(pC_buffer-1)=='-'&&!nuweb_mode)
C_putc(' ');
OUT_OP("--");
}

/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3434 "./ftangle.web"

break;

case minus_gt:OUT_OP(FORTRAN_LIKE(language)?".EQV.":"->");break;

case gt_gt:
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3440 "./ftangle.web"

OUT_OP(">>");break;

case eq_eq:
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3444 "./ftangle.web"

OUT_OP(R77_or_F?F_OP(".EQ.","=="):"==");break;

case lt_lt:
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3448 "./ftangle.web"

OUT_OP("<<");break;

case '>':
if(in_string||in_format)
out_dflt(cur_char);
else
{
OUT_OP(R77_or_F?F_OP(".GT.",">"):">");
if(language==C_PLUS_PLUS)
C_putc(' ');
}

/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3461 "./ftangle.web"

break;

case gt_eq:
OUT_OP(R77_or_F?F_OP(".GE.",">="):">=");
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3466 "./ftangle.web"

break;

case '<':
if(in_string||in_format)
out_dflt(cur_char);
else
OUT_OP(R77_or_F?F_OP(".LT.","<"):"<");

/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3475 "./ftangle.web"

break;

case lt_eq:
OUT_OP(R77_or_F?F_OP(".LE.","<="):"<=");
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3480 "./ftangle.web"

break;

case not_eq:
OUT_OP(R77_or_F?F_OP(".NE.","/="):"!=");
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3485 "./ftangle.web"

break;

case and_and:
OUT_OP(R77_or_F?".AND.":"&&");
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3490 "./ftangle.web"

break;

case or_or:
if(language==TEX)meta_mode= YES;
else
{
OUT_OP(R77_or_F?".OR.":"||");
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3498 "./ftangle.web"

}
break;

case star_star:
if(language==TEX)meta_mode= NO;
else OUT_OP(C_LIKE(language)?"^^":"**");
break;

case '!':
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3508 "./ftangle.web"

if(in_string)
return out_dflt(cur_char);
else
OUT_OP(R77_or_F?".NOT.":"!");
break;

case slash_slash:OUT_OP("//");break;

case colon_colon:
if(in_string&&!nuweb_mode)
return out_dflt(cur_char);


else
OUT_OP("::");
break;

case ellipsis:
OUT_OP(FORTRAN_LIKE(language)?".NEQV.":"...");
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3528 "./ftangle.web"

break;

case paste:OUT_OP("##");break;

case dot_const:
C_putc('.');
STRCPY(dot_op.name+1,dots[cur_val].symbol);
to_outer(dot_op.name+1);
OUT_OP(OC(dot_op.name+1));
C_putc('.');
break;

/* :161 */
#line 2683 "./ftangle.web"
;
/* 162: */
#line 3543 "./ftangle.web"

case '+':
case '-':
case '*':
case '/':


if(!FORTRAN_LIKE(language)||
cur_byte==cur_end||*cur_byte!='='||
out_state==VERBATIM||!xpn_Ratfor)
{
if(cur_char=='*'&&C_LIKE(language)&&out_state!=VERBATIM
&&*(pC_buffer-1)=='/'&&!nuweb_mode)
C_putc(' ');
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 3557 "./ftangle.web"

return out_dflt(cur_char);
}

cur_byte++;
/* 163: */
#line 3570 "./ftangle.web"

{
outer_char HUGE*l;



C_putc('=');
plast_char--;
out_state= MISCELLANEOUS;



if(compound_assignments)
{
send_rp= YES;

if(last_xpr_overflowed)
OVERFLW("last expression","lx");

for(l= last_char;isdigit(*l)||!isalpha(*l);l++)
;

if(plast_char-l>=3&&STRNCMP(last_char,"if(",3)==0)

err0_print(ERR_T,OC("Sorry, can't expand compound assignment \
operators correctly after simple IF; please use an IF...THEN construction"),0);

while(l<plast_char)
buffer_out(*l++);

send_rp= NO;
}
else

fatal(ERR_T,OC("ABORTING:  "),OC("Operators `++', `--', `+=', `-=', `*=', and `/=' \
are not allowed; they were turned off by option `-+'."));
}

/* :163 */
#line 3562 "./ftangle.web"
;
out_dflt(cur_char);
send_rp= YES;

C_putc('(');
break;

/* :162 */
#line 2684 "./ftangle.web"
;

case '=':
C_putc('=');

if(out_state!=VERBATIM)
{
if(C_LIKE(language)&&!nuweb_mode)
C_putc(' ');

out_state= MISCELLANEOUS;
}

/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2697 "./ftangle.web"

break;

case join:out_state= UNBREAKABLE;break;

case constant:
if(out_state==VERBATIM)
out_state= in_format?MISCELLANEOUS:NUM_OR_ID;

else
{
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2708 "./ftangle.web"


if(out_state==NUM_OR_ID&&!nuweb_mode)
C_putc(' ');

out_state= VERBATIM;
}

in_constant= BOOLEAN(!in_constant);
break;

case stringg:
if(in_string)
out_state= MISCELLANEOUS;
else
{
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2724 "./ftangle.web"


if(out_state==NUM_OR_ID&&!nuweb_mode)
C_putc(' ');


out_state= VERBATIM;
}

in_string= BOOLEAN(!in_string);
break;

case begin_meta:



pmeta= &t_style.meta[lan_num(language)];

switch(language)
{
outer_char*t;

case C:
case C_PLUS_PLUS:
case LITERAL:
case TEX:
if(meta_mode)
break;

if(!nuweb_mode)
{
if(in_string&&!in_version)
OUT_STR(t= pmeta->msg.top);
else
OUT_OP(t= pmeta->hdr.top);

if(*t)
OUT_STR("\n");
}
meta_mode= YES;
break;

case RATFOR:
case RATFOR_90:
case FORTRAN:
case FORTRAN_90:
if(meta_mode)
xpn_Ratfor= NO;
C_putc(cur_char);
out_state= MISCELLANEOUS;
break;

default:

confusion(OC("out_char:begin_meta"),OC("Language %i is not defined"),language);
}
break;

case end_meta:
meta_mode= NO;

switch(language)
{
outer_char*t;

case C:
case C_PLUS_PLUS:
case LITERAL:
case TEX:
if(meta_mode)break;

if(!nuweb_mode)
{
if(in_string&&!in_version)
OUT_OP(t= pmeta->msg.bottom);
else
OUT_OP(t= pmeta->hdr.bottom);

if(*t)OUT_OP("\n");
}
break;

case RATFOR:
case RATFOR_90:
case FORTRAN:
case FORTRAN_90:
xpn_Ratfor= YES;
C_putc(cur_char);
out_state= MISCELLANEOUS;
break;

default:

confusion(OC("out_char:end_meta"),OC("Language %i is invalid"),language);
}

break;

case '{':
if(R77&&!in_string)
/* 140: */
#line 2908 "./ftangle.web"

{
cp_fcn_body();
cur_char= 01;
}

/* :140 */
#line 2824 "./ftangle.web"

else
{
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2827 "./ftangle.web"

return out_dflt(cur_char);
}
break;


case '}':
{
if(R77&&!in_string&&brace_level==0)

RAT_error(WARNING,OC("Spurious '}' ignored, \
or missing program, module, subroutine, or function statement"),0);
else
{
out_dflt(cur_char);
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2841 "./ftangle.web"

}
}

break;

case '[':
out_bracket(cur_char,'(');
break;

case ']':
out_bracket(cur_char,')');
break;


case '`':
if(!(in_string||language==LITERAL))
{
mac_protected= BOOLEAN(!mac_protected);
break;
}
else
return out_dflt(cur_char);

case '&':
if(C_LIKE(language)&&out_state!=VERBATIM
&&*(pC_buffer-1)=='&'&&!nuweb_mode)
C_putc(' ');
/* 139: */
#line 2898 "./ftangle.web"

{
#if FANCY_SPLIT
if(C_LIKE(language)&&out_state!=VERBATIM)
split_pos= pC_buffer;
#endif 
}

/* :139 */
#line 2869 "./ftangle.web"

return out_dflt(cur_char);

case '\\':
if(R66)
cur_char= '$';


default:
return out_dflt(cur_char);
}

return cur_char;
}

/* :137 */
/* 138: */
#line 2885 "./ftangle.web"


eight_bits
out_bracket FCN((cur_char,new_char))
eight_bits cur_char C0("")
eight_bits new_char C1("")
{
if(out_state!=VERBATIM&&FORTRAN_LIKE(language)&&translate_brackets)
cur_char= new_char;
return out_dflt(cur_char);
}

/* :138 */
/* 141: */
#line 2915 "./ftangle.web"


eight_bits
out_dflt FCN((c))
eight_bits c C1("")
{
C_putc(XCHR(c));

if(out_state!=VERBATIM)
out_state= MISCELLANEOUS;

return c;
}

/* :141 */
/* 143: */
#line 2952 "./ftangle.web"


LANGUAGE set_output_file FCN((language0))
LANGUAGE language0 C1("")
{
language= language0;
ini0_language();
out_file= params.OUT_FILE;

return language;
}

/* :143 */
/* 144: */
#line 2968 "./ftangle.web"


LANGUAGE
opn_output_file FCN((language0))
LANGUAGE language0 C1("")
{
set_output_file(language0);
flush_buffer();
open_out(OC(""),LOCAL_SCOPE);

return language;
}

/* :144 */
/* 191: */
#line 4490 "./ftangle.web"


boolean skip_comment(VOID)
{
ASCII c;
PARSING_MODE outer_mode;

outer_mode= parsing_mode;
parsing_mode= OUTER;

if(comment_continues)
loc--;


else if(*(loc-1)=='/')
loc++;


WHILE()
{
if(loc>limit)
if(!long_comment)
/* 192: */
#line 4554 "./ftangle.web"

{
comment_continues= NO;
break;
}

/* :192 */
#line 4512 "./ftangle.web"

else if(get_line())
{
comment_continues= YES;
break;
}
else
{

err0_print(ERR_T,OC("Input ended in middle of comment %s"),1,BTRANS);

comment_continues= NO;
break;

}

c= *(loc++);

if(c=='*'&&*loc=='/')
{
loc++;
/* 192: */
#line 4554 "./ftangle.web"

{
comment_continues= NO;
break;
}

/* :192 */
#line 4532 "./ftangle.web"

}

if(c=='@')
{
if(ccode[*loc]==new_module)
{

err0_print(ERR_T,OC("Section name ended in middle of comment %s"),1,BTRANS);
loc--;

/* 192: */
#line 4554 "./ftangle.web"

{
comment_continues= NO;
break;
}

/* :192 */
#line 4543 "./ftangle.web"

}
else loc++;
}
}

parsing_mode= outer_mode;
return comment_continues;
}

/* :191 */
/* 194: */
#line 4583 "./ftangle.web"


eight_bits
get_next(VOID)
{
GOTO_CODE pcode;

strt_point_cmnt= suppress_newline= NO;

WHILE()
{
/* 195: */
#line 4639 "./ftangle.web"


if(preprocessing&&at_beginning)
{
at_beginning= NO;



for(;loc<limit;loc++)
if(!(*loc==' '||*loc==tab_mark))break;

*(loc-1)= '#';

return(eight_bits)prs_regular_code(GOTO_GET_IDENTIFIER);
}

/* :195 */
#line 4594 "./ftangle.web"
;
/* 196: */
#line 4659 "./ftangle.web"


if(*loc==cont_char&&loc==limit-1&&(preprocessing||free_Fortran))
{
loc+= 2;
return(eight_bits)CHOICE(free_Fortran,'&',cont_char);


}

/* :196 */
#line 4595 "./ftangle.web"
;

if(loc>limit)
/* 198: */
#line 4704 "./ftangle.web"

{
if(from_buffer)
{
undivert();
if(stop_the_scan)
return WEB_definition;
continue;
}
else
{
if(preprocessing&&*(limit-1)!=cont_char)
{
preprocessing= NO;
if(in_cdir)
{
id_first= id_loc= mod_text+1;
*id_loc++= cdir;
*id_loc++= '\0';
in_cdir= NO;
return stringg;
}
}
if(stop_the_scan)
return WEB_definition;
else if(!get_line())
return new_module;

if(eat_blank_lines)
{
eat_blank_lines= NO;

while(loc>=limit)
if(!get_line())
return new_module;
}

if(insrt_line)
{
ins_ln_no(0);
insrt_line= NO;
}

at_beginning= BOOLEAN(!preprocessing);

if(prn_where)
{
prn_where= NO;

if(!scanning_defn)
{
app_repl('\n');

/* 235: */
#line 6291 "./ftangle.web"
ins_ln_no(0)

/* :235 */
#line 4757 "./ftangle.web"
;
}
}
else if(!suppress_newline&&
(!R77_or_F||limit==cur_buffer||free_Fortran))
return '\n';

suppress_newline= NO;
}
}

/* :198 */
#line 4598 "./ftangle.web"

else
at_beginning= BOOLEAN(!preprocessing&&(loc==cur_buffer));

if(preprocessing)
/* 197: */
#line 4672 "./ftangle.web"

{
boolean found_white_space= NO;

do
{
if((c= *loc++)!=' '||c!=tab_mark)
break;

found_white_space= YES;
}
while(loc<limit);

/* :197 */
/* 197: */
#line 4692 "./ftangle.web"

if(found_white_space)
return ' ';
}

/* :197 */
#line 4603 "./ftangle.web"

else
/* 199: */
#line 4774 "./ftangle.web"

{
if(language==TEX)
c= *loc++;
else
{
ASCII HUGE*loc0= loc;

do
{
c= *loc++;
}
while(loc<=limit&&(c==' '||c==tab_mark));

if(nuweb_mode||scanning_meta)
{
if(!(c=='@'&&*loc=='#'))
{
loc= loc0;
c= *loc++;

if(loc>limit)
continue;
}
}
}
}

/* :199 */
#line 4605 "./ftangle.web"


strt_cmnt= NO;

switch(language)
{
case TEX:
if(!scanning_defn)
{
if((pcode= prs_TeX_code())==MORE_PARSE)
break;
else if(pcode<0)

confusion(OC("prs_TEX_code"),OC("Negative pcode %i"),pcode);
else
RETURN(pcode);
}

default:
if((pcode= prs_regular_code(MORE_PARSE))==MORE_PARSE)
break;
else if((int)pcode<0)

confusion(OC("prs_regular_code"),OC("Negative pcode %i"),pcode);
else
RETURN(pcode);
}
}

DUMMY_RETURN(ignore);
}

/* :194 */
/* 200: */
#line 4803 "./ftangle.web"


GOTO_CODE
prs_TeX_code(VOID)
{
GOTO_CODE icode;

if(loc>limit)
return MORE_PARSE;

if(TeX[c]==TeX_comment)
/* 201: */
#line 4837 "./ftangle.web"

{
long_comment= NO;

if((all_cmnts_verbatim||(keep_trailing_comments&&!at_beginning))
&&!(scanning_defn&&is_WEB_macro))
{
strt_cmnt= YES;
}
else
{
loc= limit+1;
suppress_newline= YES;

return MORE_PARSE;
}
}

/* :201 */
#line 4814 "./ftangle.web"


if(c=='@')
{
icode= get_control_code();

if(icode==MORE_PARSE)
return icode;

if((int)(icode)<0)
return prs_regular_code(icode);
else
return(eight_bits)icode;
}
else if(c=='$'&&STRNCMP(loc-1,LKWD,STRLEN(LKWD))==0)
return prs_regular_code(MORE_PARSE);
else
/* 202: */
#line 4856 "./ftangle.web"

{
loc--;
id_first= id_loc= mod_text+1;

if(strt_cmnt)
*id_loc++= begin_Xmeta;

while(loc<limit)
{
if(*loc=='@')
{
if(*(loc+1)=='@')
*id_loc++= *loc++;
/* :202 */
/* 202: */
#line 4873 "./ftangle.web"
}
else if(*loc=='$'&&STRNCMP(loc,LKWD,STRLEN(LKWD))==0)
break;
else if(!strt_cmnt&&TeX[*loc]==TeX_comment&&*(loc-1)!='\\')
break;

*id_loc++= *loc++;
}

if(strt_cmnt)
*id_loc++= end_Xmeta;

return stringg;
}

/* :202 */
#line 4831 "./ftangle.web"

}

/* :200 */
/* 203: */
#line 4890 "./ftangle.web"

GOTO_CODE
prs_regular_code FCN((iswitch))
GOTO_CODE iswitch C1("")
{
GOTO_CODE icode;

switch(iswitch)
{
case MORE_PARSE:break;

case GOTO_MISTAKE:goto mistake;
case GOTO_GET_IDENTIFIER:goto get_identifier;
case GOTO_GET_A_STRING:goto get_a_string;
case GOTO_SKIP_A_COMMENT:goto skip_a_comment;
}

if(language!=LITERAL)
/* 204: */
#line 4982 "./ftangle.web"

{
switch(c)
{
case(ASCII)begin_comment0:
long_comment= strt_cmnt= YES;
break;

case(ASCII)begin_comment1:
strt_cmnt= strt_point_cmnt= YES;
long_comment= NO;
break;

case '/':
if(*loc=='*')
long_comment= strt_cmnt= YES;
else if(*loc=='/'&&(C_LIKE(language)||(Cpp_comments&&
!in_format&&FORTRAN_LIKE(language))))
{
long_comment= NO;
strt_cmnt= YES;
}
break;

case '!':


if((*loc=='!'||point_comments)&&FORTRAN_LIKE(language))
{
*(loc-1)= (ASCII)begin_comment1;

strt_cmnt= strt_point_cmnt= YES;
long_comment= NO;
}
break;
}

if(strt_cmnt&&all_cmnts_verbatim&&!(scanning_defn&&is_WEB_macro))
{
loc--;

/* 213: */
#line 5483 "./ftangle.web"

switch(icode= get_control_code())
{
case GOTO_MISTAKE:goto mistake;
case GOTO_GET_A_STRING:goto get_a_string;
case GOTO_GET_IDENTIFIER:goto get_identifier;
case GOTO_SKIP_A_COMMENT:goto skip_a_comment;

case m_line:
ins_ln_no(1);
suppress_newline= YES;
return MORE_PARSE;

case MORE_PARSE:
default:return icode;
}

/* :213 */
#line 5023 "./ftangle.web"

}
else if(strt_cmnt||comment_continues)
{
skip_a_comment:
skip_comment();

if((comment_continues)&&
!(scanning_defn&&is_WEB_macro))return '\n';
else return MORE_PARSE;
}

if(loc==limit&&c==cont_char&&
(preprocessing||(auto_semi&&R77)))
return MORE_PARSE;
/* :204 */
/* 204: */
#line 5041 "./ftangle.web"
}

/* :204 */
#line 4908 "./ftangle.web"



if(c=='.'&&*loc=='.'&&*(loc+1)=='.')
{
++loc;
compress(ellipsis);
}


else if(FORTRAN_LIKE(language)&&dot_constants&&
(c==wt_style.dot_delimiter.begin)&&!isDigit(*loc))

/* 210: */
#line 5285 "./ftangle.web"

{
ASCII HUGE*p0;
int n;
eight_bits c;
ASCII dot_end= wt_style.dot_delimiter.end;



for(p0= loc,n= 0;n<MAX_DOT_LENGTH;n++,loc++)
if(*loc==dot_end||!isAlpha(*loc))break;


if(*loc!=dot_end)
{
loc= p0;
goto mistake;
}

c= dot_code(dots,uppercase(p0,n),loc++,dot_const);

if(c)return c;
else
{
loc= p0;
goto mistake;
}

}

/* :210 */
#line 4921 "./ftangle.web"



else if(isDigit(c)||c=='.'||(c=='\\'&&language!=LITERAL))
/* 207: */
#line 5133 "./ftangle.web"

{
boolean decimal_point;


if(loc==limit&&c==cont_char)
{
if(preprocessing)loc++;
return(eight_bits)c;
}

starts_with_0= hex_constant= bin_constant= floating_constant= NO;

id_first= loc-1;

if(*id_first=='.'&&!isDigit(*loc))
goto mistake;

if(*id_first=='\\')
{
if(*loc=='/')
goto mistake;

while(isOdigit(*loc))
loc++;

goto found;
}
else
{
starts_with_0= BOOLEAN(*id_first=='0');
if(starts_with_0)
{
hex_constant= BOOLEAN(*loc=='x'||*loc=='X');

if(hex_constant)
{
loc++;

while(isXdigit(*loc))
loc++;

goto found;
}
else if((bin_constant= BOOLEAN(*loc=='b'||*loc=='B'))!=0)
{
loc++;

while(isBdigit(*loc))
loc++;

goto found;
}
}

while(isDigit(*loc))loc++;
decimal_point= BOOLEAN(*loc=='.');
if(decimal_point)loc++;
while(isDigit(*loc))loc++;

if(FORTRAN_LIKE(language))
if(*(loc-1)=='.')
{


if(is_dot())
{
loc--;
goto found;
}
}
else if(*loc=='h'||*loc=='H')
/* 209: */
#line 5269 "./ftangle.web"

{
int l,n;


*loc++= '\0';

n= ATOI(id_first);
*(loc-1)= 'H';

for(l= 0;l<n;++l)++loc;

goto found;
}

/* :209 */
#line 5205 "./ftangle.web"


floating_constant= BOOLEAN(*loc=='e'||*loc=='E'||
(FORTRAN_LIKE(language)
&&(*loc=='d'||*loc=='D'||*loc=='q'||*loc=='Q')));

if(floating_constant)
{
if(*++loc=='+'||*loc=='-')loc++;
while(isDigit(*loc))loc++;
}

floating_constant|= decimal_point;
}

found:
if(C_LIKE(language))
{
boolean its_long= NO,its_unsigned= NO,its_constant= NO;

switch(*loc)
{
case 'l':
case 'L':
its_constant= its_long= YES;
break;

case 'u':
case 'U':
its_constant= its_unsigned= YES;
break;

case 'f':
case 'F':
its_constant= YES;
break;
}

if(its_constant)
{

loc++;


if(its_long&&(*loc=='u'||*loc=='U'))
loc++;
else if(its_unsigned&&(*loc=='l'||*loc=='L'))
loc++;
}
}
else if(Fortran88)/* 208: */
#line 5262 "./ftangle.web"

{
if(*loc=='_')
while(is_kind(*loc))loc++;
}

/* :208 */
#line 5255 "./ftangle.web"


id_loc= loc;
return constant;
}

/* :207 */
#line 4925 "./ftangle.web"



else if(is_identifier(c))
/* 30: */
#line 317 "./typedefs.hweb"

{
IN_COMMON ASCII HUGE*pformat,HUGE*pdata;

get_identifier:
/* 31: */
#line 353 "./typedefs.hweb"

{
id_first= --loc;


for(++loc;isAlpha(*loc)||isDigit(*loc)
||*loc=='_'||*loc=='$'||(in_format&&*loc=='.');loc++)
;

upcoming_kind= BOOLEAN(Fortran88&&(*loc=='"'||*loc=='\'')
&&loc[-1]=='_');

id_loc= loc-upcoming_kind;

}


/* :31 */
#line 322 "./typedefs.hweb"


if(FORTRAN_LIKE(language))
{
if(web_strcmp(pformat,pformat+6,id_first,id_loc)==EQUAL)
{

in_format= YES;
return begin_format_stmt;
}
else if(program==weave)
{
if(web_strcmp(pdata,pdata+4,id_first,id_loc)==EQUAL)
{
in_data= YES;
return identifier;
}
else if(at_beginning&&*loc==':'&&
!is_in(non_labels,id_first,id_loc))
return stmt_label;
}
}

if(is_include_like())
sharp_include_line= YES;

return identifier;
}


/* :30 */
#line 4929 "./ftangle.web"



else if((c=='\''||c=='"')
||(is_RATFOR_(language)&&sharp_include_line==YES&&c=='('))
{
if(language==LITERAL)
return c;
else
/* 211: */
#line 5321 "./ftangle.web"

get_a_string:
{
ASCII delim= c;
ASCII right_delim= c;
int level;
boolean equal_delims;

id_first= mod_text+1;
id_loc= mod_text;*++id_loc= delim;

if(delim=='(')
{
right_delim= ')';
sharp_include_line= NO;
}

level= 1;

equal_delims= BOOLEAN(right_delim==delim);

WHILE()
{
if(loc>=limit)
{
if((equal_delims||chk_ifelse)&&*(limit-1)!=cont_char)

{

err0_print(ERR_T,OC("String %s with %s'%s%c'%s didn't end"),5,BTRANS,SSET_COLOR(character),delim=='\''?"\\":"",XCHR(delim),SSET_COLOR(error));
loc= limit;break;

}

if(!get_line())
{

err0_print(ERR_T,OC("Input ended in middle of string \
%s with '%s%c'"),3,BTRANS,delim=='\''?"\\":"",XCHR(delim));
loc= cur_buffer;
break;

}
else
{
if(C_LIKE(language)&&++id_loc<=mod_end)*id_loc= '\n';




if(bslash_continued_strings)
{
for(;loc<limit;loc++)
if(*loc!=' '&&*loc!=tab_mark)break;

if(*loc==cont_char)loc++;
else
err0_print(ERR_T,OC("Inserted '%c' at beginning of continued \
string"),1,XCHR(cont_char));
}
}
}

if(!equal_delims)/* 212: */
#line 5459 "./ftangle.web"


if(*loc=='/'&&*(loc+1)=='*')
for(loc+= 2;;loc++)
{
if(loc>=limit)
if(!get_line())
{

err0_print(ERR_T,OC("Input ended in middle of embedded comment %s"),1,BTRANS);
loc= cur_buffer;
goto found_string;
}

if(*loc=='*'&&*(loc+1)=='/')
{
loc+= 2;
break;
}
}

/* :212 */
#line 5386 "./ftangle.web"
;

if((c= *loc++)==delim)
{
level++;

if(++id_loc<=mod_end)*id_loc= c;

if(!equal_delims)continue;

if(*loc==delim&&!(C_LIKE(language)||
(is_RATFOR_(language)&&Ratfor77)))
++loc;
else break;
}

if(c==right_delim)
if(--level==0)
{
if(++id_loc<=mod_end)*id_loc= c;
break;
}


if(R77&&c=='\'')
if(++id_loc<=mod_end)*id_loc= c;

if(c==cont_char)
{
if(loc>=limit&&(!is_FORTRAN_(language)||free_form_input))
continue;


if(!is_FORTRAN_(language))
{
c= *loc++;

if(R77)
switch(c)
{
#if(0)
#define n c
/* 266: */
#line 7168 "./ftangle.web"

case '0':n= '\0';break;
case '\\':n= '\\';break;
case '\'':n= '\'';break;
case '"':n= '\"';break;
case '?':n= '\?';break;
case 'a':n= '\007';break;
case 'b':n= '\b';break;
case 'f':n= '\f';break;
case 'n':n= '\n';break;
case 'r':n= '\r';break;
case 't':n= '\t';break;
case 'v':n= '\v';break;

/* :266 */
#line 5428 "./ftangle.web"

#undef n
#endif

case '\'':
if(++id_loc<=mod_end)*id_loc= c;
break;
}
else{if(++id_loc<=mod_end)*id_loc= '\\';}
}
}

if(++id_loc<=mod_end)*id_loc= c;
}

found_string:
if(id_loc>=mod_end)
{
SET_COLOR(error);
printf("\n! String too long: ");

ASCII_write(mod_text+1,25);
printf("...");
mark_error;
}

id_loc++;
return stringg;
}

/* :211 */
#line 4938 "./ftangle.web"

}


else if(c=='@')
/* 213: */
#line 5483 "./ftangle.web"

switch(icode= get_control_code())
{
case GOTO_MISTAKE:goto mistake;
case GOTO_GET_A_STRING:goto get_a_string;
case GOTO_GET_IDENTIFIER:goto get_identifier;
case GOTO_SKIP_A_COMMENT:goto skip_a_comment;

case m_line:
ins_ln_no(1);
suppress_newline= YES;
return MORE_PARSE;

case MORE_PARSE:
default:return icode;
}

/* :213 */
#line 4943 "./ftangle.web"



else if(c==' '||c==tab_mark)
if(nuweb_mode||scanning_meta)
return(c==tab_mark?bell:c);
else
{
if(!preprocessing||loc>limit)
return MORE_PARSE;

else
return ' ';
}


else if(c=='#'&&!macro_scan&&at_beginning&&C_LIKE(language))
{
preprocessing= YES;
return MORE_PARSE;
}


else if(in_format&&c==';')
{
in_format= NO;
return end_format_stmt;
}


mistake:
if(language!=LITERAL)
/* 205: */
#line 5052 "./ftangle.web"

switch(c)
{
case '\\':
if(FORTRAN_LIKE(language)&&!in_format&&*loc=='/')
compress(slash_slash);

break;

case '/':
if(FORTRAN_LIKE(language)&&!in_format)
{
if(*loc=='/')
{
if(Cpp_comments)
break;



compress(slash_slash);

}
else if(*loc=='='&&!compound_assignments)
compress(not_eq);
}
break;
case '+':if(*loc=='+')compress(plus_plus);break;

case '-':if(*loc=='-'){compress(minus_minus);}
else if(*loc=='>')compress(minus_gt);break;

case '=':if(*loc=='=')compress(eq_eq);break;

case '>':if(*loc=='='){compress(gt_eq);}
else if(*loc=='>'){compress(gt_gt);}
break;

case '<':if(*loc=='='){compress(lt_eq);}
else if(*loc=='<'){compress(lt_lt);}
else if(*loc=='>'){compress(not_eq);}
break;

case '&':if(*loc=='&')compress(and_and);break;

case '|':if(*loc=='|')compress(or_or);break;

case '!':if(*loc=='='){compress(not_eq);}break;

case '*':
if(FORTRAN_LIKE(language)&&(*loc=='*'))
{compress(star_star);}
break;

case '^':
if(*loc=='^'){compress(star_star);}
else if(FORTRAN_LIKE(language)&&(loc<limit))return star_star;
break;

case '#':
if(*loc=='#'){compress(paste);}
else if(*loc=='<')
{
loc++;
mac_mod_name= YES;
/* 217: */
#line 5714 "./ftangle.web"

{
ASCII HUGE*k;
static ASCII ell[]= "...";


/* 220: */
#line 5754 "./ftangle.web"

{
int arg_num= 0;
TEMPLATE arg_ptr[10];

mod_level= 1;
k= mod_text;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_T,OC("Input ended in section name %s"),1,BTRANS);

loc= cur_buffer+1;
break;
}

c= *loc;
/* 221: */
#line 5840 "./ftangle.web"


if(c=='@')
{
c= *(loc+1);

if(c=='>')
{
if(--mod_level==0)
{
loc+= 2;
break;
}
}
else if(c=='<')
mod_level++;

if(ccode[c]==new_module)
{

err0_print(ERR_T,OC("Section name %s didn't end"),1,BTRANS);

break;
}

*(++k)= '@';
loc++;
}

/* :221 */
#line 5773 "./ftangle.web"
;
loc++;

if(k<mod_end)
k++;

switch(c)
{
case ' ':
case tab_mark:
c= ' ';
if(*(k-1)==' ')
k--;
break;

case ';':
c= interior_semi;
break;

case '[':
/* :220 */
/* 220: */
#line 5800 "./ftangle.web"
break;
}

*k= c;
}

/* :220 */
/* 220: */
#line 5824 "./ftangle.web"

if(k>=mod_end)
{
SET_COLOR(warning);
printf("\n! Section name too long: ");

ASCII_write(mod_text+1,25);
printf("...");
mark_harmless;
}

if(*k==' '&&k>mod_text)
k--;
}

/* :220 */
#line 5720 "./ftangle.web"


if(k-mod_text>3&&STRNCMP(k-2,ell,3)==0)
cur_module= prefix_lookup(mod_text+1,k-3);
else
cur_module= mod_lookup(mod_text+1,k);

if(cur_module!=NULL)
{
set_output_file(cur_module->mod_info->language);
}

return module_name;
}

/* :217 */
#line 5117 "./ftangle.web"

}
break;

case ':':if(*loc==':'&&language==C_PLUS_PLUS&&!scanning_meta)
compress(colon_colon);break;

}


/* :205 */
#line 4975 "./ftangle.web"


return(eight_bits)c;
}


/* :203 */
/* 214: */
#line 5501 "./ftangle.web"

GOTO_CODE
get_control_code(VOID)
{
eight_bits cc;

c= *loc++;
SET_CASE(c);

if(c==(ASCII)begin_comment1||c==(ASCII)begin_comment0)
{
c= *(loc-1)= '/';

strt_cmnt= YES;
}

if(c=='>'&&mod_level==0)
{

err0_print(ERR_T,OC("Unmatched `%s@>%s' ignored"),2,SSET_COLOR(character),SSET_COLOR(error));
return MORE_PARSE;
}

switch(cc= ccode[c])
{
case ignore:return MORE_PARSE;




/* 10: */
#line 80 "./typedefs.hweb"


case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



/* :10 */
#line 5532 "./ftangle.web"
:
loc--;

case L_switch:
{
/* 21: */
#line 139 "./typedefs.hweb"

{
ASCII l= *loc++;

switch(l)
{
/* 11: */
#line 95 "./typedefs.hweb"

case 'c'

/* :11 */
#line 145 "./typedefs.hweb"
:
Cpp= BOOLEAN(*loc=='+');
break;

/* 12: */
#line 98 "./typedefs.hweb"

case 'r'

/* :12 */
#line 149 "./typedefs.hweb"
:
/* 13: */
#line 101 "./typedefs.hweb"

case 'n'

/* :13 */
#line 150 "./typedefs.hweb"
:
Fortran88= BOOLEAN(*loc=='9');
break;

/* 15: */
#line 107 "./typedefs.hweb"

case 'v'



/* :15 */
#line 154 "./typedefs.hweb"
:
/* 14: */
#line 104 "./typedefs.hweb"

case 'x'

/* :14 */
#line 155 "./typedefs.hweb"
:
break;

default:

err0_print(ERR_C,OC("! Invalid language command `@L%c' ignored"),1,XCHR(l));
break;
}

opt_args(l);

}


/* :21 */
#line 5537 "./ftangle.web"

set_output_file(language);
return begin_language;
}

case control_text:while((c= skip_ahead(ignore,NO))=='@');


if(*(loc-1)!='>')

err0_print(ERR_T,OC("Improper @ within control text %s"),1,BTRANS);


return MORE_PARSE;

case module_name:
mac_mod_name= NO;
/* 217: */
#line 5714 "./ftangle.web"

{
ASCII HUGE*k;
static ASCII ell[]= "...";


/* 220: */
#line 5754 "./ftangle.web"

{
int arg_num= 0;
TEMPLATE arg_ptr[10];

mod_level= 1;
k= mod_text;

WHILE()
{
if(loc>limit&&!get_line())
{

err0_print(ERR_T,OC("Input ended in section name %s"),1,BTRANS);

loc= cur_buffer+1;
break;
}

c= *loc;
/* 221: */
#line 5840 "./ftangle.web"


if(c=='@')
{
c= *(loc+1);

if(c=='>')
{
if(--mod_level==0)
{
loc+= 2;
break;
}
}
else if(c=='<')
mod_level++;

if(ccode[c]==new_module)
{

err0_print(ERR_T,OC("Section name %s didn't end"),1,BTRANS);

break;
}

*(++k)= '@';
loc++;
}

/* :221 */
#line 5773 "./ftangle.web"
;
loc++;

if(k<mod_end)
k++;

switch(c)
{
case ' ':
case tab_mark:
c= ' ';
if(*(k-1)==' ')
k--;
break;

case ';':
c= interior_semi;
break;

case '[':
/* :220 */
/* 220: */
#line 5800 "./ftangle.web"
break;
}

*k= c;
}

/* :220 */
/* 220: */
#line 5824 "./ftangle.web"

if(k>=mod_end)
{
SET_COLOR(warning);
printf("\n! Section name too long: ");

ASCII_write(mod_text+1,25);
printf("...");
mark_harmless;
}

if(*k==' '&&k>mod_text)
k--;
}

/* :220 */
#line 5720 "./ftangle.web"


if(k-mod_text>3&&STRNCMP(k-2,ell,3)==0)
cur_module= prefix_lookup(mod_text+1,k-3);
else
cur_module= mod_lookup(mod_text+1,k);

if(cur_module!=NULL)
{
set_output_file(cur_module->mod_info->language);
}

return module_name;
}

/* :217 */
#line 5554 "./ftangle.web"


case keyword_name:
case stringg:
/* 226: */
#line 6010 "./ftangle.web"

{
id_first= loc;


*(limit+1)= '@';*(limit+2)= '>';

while(*loc!='@'||*(loc+1)!='>')
loc++;

if(loc>=limit)

err0_print(ERR_T,OC("Verbatim string %s didn't end"),1,BTRANS);


id_loc= loc;
loc+= 2;

return cc;
}

/* :226 */
#line 5558 "./ftangle.web"
;

case begin_vcmnt:


if(strt_cmnt||*loc=='*'||*loc=='/')
if(!(scanning_defn&&is_WEB_macro)&&!deferred_macro)
{
if(!strt_point_cmnt)long_comment= 
BOOLEAN(!(*loc=='/'));
/* 223: */
#line 5894 "./ftangle.web"

{
loc--;


id_first= id_loc= mod_text+1;


if(!C_LIKE(language))
{
loc++;
/* 225: */
#line 5998 "./ftangle.web"

{
if(R66)*id_loc++= '#';
else*id_loc++= '\n';

}

/* :225 */
#line 5905 "./ftangle.web"
;
}

WHILE()
{
if(loc>limit)
if(!long_comment)
/* 224: */
#line 5977 "./ftangle.web"

{
if(C_LIKE(language))
{

if(!long_comment&&!Cpp)
{
*id_loc++= id_first[1]= '*';
*id_loc++= id_first[0]= '/';
}
}
else
{
if(long_comment)id_loc-= 2;
}

break;
}

/* :224 */
#line 5912 "./ftangle.web"

else if(!get_line())
{

err0_print(ERR_T,OC("Input ended in verbatim comment %s"),1,BTRANS);

loc= cur_buffer+1;
break;
}
else
{
*id_loc++= '\n';

if(R66)
{
*id_loc++= '#';
*id_loc++= ' ';
}
}

if(id_loc<mod_end-3)
{
if(loc[0]=='@')
{
if(loc[1]=='@')
*id_loc++= *loc++;
else if(ccode[loc[1]]==keyword_name)

err0_print(ERR_T,OC("@K and @k aren't (yet) allowed in comments"),0);
}

*id_loc++= *loc++;
}
else
{
SET_COLOR(warning);
printf("\n! Verbatim comment too long: ");

ASCII_write(mod_text,25);
printf("...");mark_harmless;

id_loc= mod_end-3;
*id_loc++= '*';*id_loc++= '/';

comment_continues= YES;

goto finish_vcmnt;
}


if(long_comment&&*loc=='/'&&*(loc-1)=='*')
{
*id_loc++= *loc++;
/* 224: */
#line 5977 "./ftangle.web"

{
if(C_LIKE(language))
{

if(!long_comment&&!Cpp)
{
*id_loc++= id_first[1]= '*';
*id_loc++= id_first[0]= '/';
}
}
else
{
if(long_comment)id_loc-= 2;
}

break;
}

/* :224 */
#line 5963 "./ftangle.web"

}
}

finish_vcmnt:
if(!C_LIKE(language))
{
*id_loc++= '\0';
}
return stringg;
}


/* :223 */
#line 5568 "./ftangle.web"

}
else return GOTO_SKIP_A_COMMENT;
else return MORE_PARSE;


case invisible_cmnt:




if(*loc=='%')
eat_blank_lines= YES;



if(auto_line&&!scanning_defn&&loc==cur_buffer+2)
insrt_line= YES;

loc= limit+1;
suppress_newline= YES;
return MORE_PARSE;

case compiler_directive:
{
int n;
outer_char*s= t_style.cdir_start[language_num];

id_first= id_loc= mod_text+1;

*id_loc++= cdir;


STRCPY(id_loc,s);
to_ASCII((outer_char HUGE*)id_loc);
id_loc+= STRLEN(s);


STRNCPY(id_loc,loc,n= PTR_DIFF(int,limit,loc));
id_loc+= n;

*id_loc++= cdir;
*id_loc++= '\0';

loc= limit+1;
return stringg;
}

case Compiler_Directive:
{
outer_char*s= t_style.cdir_start[language_num];

id_first= id_loc= mod_text+1;

*id_loc++= cdir;
preprocessing= in_cdir= YES;
at_beginning= NO;


STRCPY(id_loc,s);
to_ASCII((outer_char HUGE*)id_loc);
id_loc+= STRLEN(s);

return stringg;
}

case new_output_file:
/* 32: */
#line 371 "./typedefs.hweb"

{
while(*loc==' '||*loc==tab_mark)
{
loc++;
if(loc>limit)return ignore;
}

id_first= loc;
while(*loc!=' '&&*loc!=tab_mark)loc++;
id_loc= loc;
if(*id_first=='"')id_first++;
if(*(id_loc-1)=='"')id_loc--;
if(id_loc-id_first>=MAX_FILE_NAME_LENGTH)
{

err0_print(ERR_T,OC("Output file name too long; allowed only %d characters"),1,MAX_FILE_NAME_LENGTH-1);
id_loc= id_first+MAX_FILE_NAME_LENGTH-1;
}
}


/* :32 */
#line 5635 "./ftangle.web"

loc= limit+1;
return cc;

case ascii_constant:
if(translate_ASCII)/* 216: */
#line 5684 "./ftangle.web"

{
ASCII delim= *(loc-1);

id_first= loc-1;

while(*loc!=delim)
{
if(*loc=='\\')
if(*++loc==delim)
{

loc++;
continue;
}

loc++;

if(loc>limit)
{

err0_print(ERR_T,OC("ASCII string %s didn't end"),1,BTRANS);
loc= limit-1;break;
}
}

loc++;
return ascii_constant;
}

/* :216 */
#line 5640 "./ftangle.web"

else
{
c= *(loc-1);
return GOTO_GET_A_STRING;
}

case big_line_break:

if(loc>=limit)return MORE_PARSE;

/* 33: */
#line 399 "./typedefs.hweb"

{
boolean mcode;

*limit= ' ';
id_first= loc;

while(isAlpha(*loc))
loc++;

if((mcode= is_mcmd(mcmds,id_first,loc))!=0)
{
while(loc<limit&&(*loc==' '||*loc==tab_mark))
loc++;

#ifdef _FWEAVE_h
defd_switch= NO;
#endif

return mcode;
}

loc= id_first;
}


/* :33 */
#line 5651 "./ftangle.web"
;
return MORE_PARSE;

case set_line_info:
/* 215: */
#line 5670 "./ftangle.web"

{
outer_char c= XCHR(*loc++);

if(!isdigit(c))
{

err0_print(ERR_T,OC("You must say `@q0' or `@q1', not `@q%c'"),1,c);
loc--;
}
else
line_info= BOOLEAN((c!='0')&&global_params.Line_info);
}

/* :215 */
#line 5655 "./ftangle.web"

return cc;

case short_fcn:
return c;

case USED_BY_NEITHER:

err0_print(ERR_T,OC("Invalid `@%c' ignored"),1,XCHR(c));
return ignore;

default:return cc;
}
}

/* :214 */
#line 38 "./ftangle.web"

#endif 

#if(part == 0 || part == 3)
/* 228: */
#line 6067 "./ftangle.web"


SRTN
scan_repl FCN((t,stop))
eight_bits t C0("Either |macro| or |module_name|.")
boolean stop C1("IF |YES|, stops the scan at the end of current\
line.")
{
eight_bits a0= ignore;
sixteen_bits a;
LANGUAGE language0;
int ntoken= 2;
boolean auto_bp= YES;


macro_scan= (t==macro);
scanning_meta= NO;
language0= language;

stop_the_scan= stop;

if(t==module_name)
{
ins_ln_no(column_mode);


app_repl(begin_language);
app_repl(NUWEB_OFF|nuweb_mode);
}
else if(stop)
/* 234: */
#line 6283 "./ftangle.web"

{
*limit= ' ';
*(limit+1)= '@';
*(limit+2)= 'm';
}

/* :234 */
#line 6097 "./ftangle.web"


WHILE()
{
if(stop)
{
while(loc<=limit)
if(*loc!=' ')break;
else loc++;

if(loc>limit)goto done;
}




if(ntoken)
ntoken--;

a0= (ntoken&&nuweb_mode&&t==module_name)
?begin_meta:get_next();

reswitch:
switch(a0)
{
case '\\':
if(loc==limit&&language!=LITERAL)
{
if(!get_line())

fatal(ERR_T,OC("Input ended "),OC("while scanning \
FWEB preprocessor statement."));
/* 234: */
#line 6283 "./ftangle.web"

{
*limit= ' ';
*(limit+1)= '@';
*(limit+2)= 'm';
}

/* :234 */
#line 6130 "./ftangle.web"

}
else
{
app_repl(a0);

if(loc==limit&&language==LITERAL)
loc++;
}
break;

case '#':
if(t==macro&&is_WEB_macro)
/* 248: */
#line 6750 "./ftangle.web"

{
switch(*loc)
{
case ':':
/* 249: */
#line 6776 "./ftangle.web"

{
outer_char temp[N_IDBUF];
ASCII HUGE*t;


loc++;



if(*loc!='0')
{
app_repl('#');
app_repl(':');
break;
}

loc++;

if(
nsprintf(temp,OC("%lu"),1,max_stmt++)>=(int)(N_IDBUF))OVERFLW("temp","");
to_ASCII(temp);


app_repl(constant);

for(t= (ASCII*)temp;*t!='\0';t++)app_repl(*t);

app_repl(constant);
}

/* :249 */
#line 6755 "./ftangle.web"
break;

case '!':
if(scanning_defn)/* 251: */
#line 6842 "./ftangle.web"

{
sixteen_bits a;


loc++;

if(get_next()!=identifier)

err0_print(ERR_M,OC("Identifier must follow #!; command ignored"),0);
else
{
text_pointer m;


a= ID_NUM(id_first,id_loc);



if((m= MAC_LOOKUP(a))==NULL)
{
app_repl('#');
app_repl('!');
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 6864 "./ftangle.web"
;
break;
}
else
if(m->nargs>0)

err0_print(ERR_M,OC("Macro after #! may not have arguments"),0);
else
/* 252: */
#line 6876 "./ftangle.web"

{
eight_bits HUGE*q0,HUGE*q1;


q0= m->tok_start+m->moffset;
q1= m->tok_start+m->nbytes;


while(q0<q1)
app_repl(*q0++);
}

/* :252 */
#line 6871 "./ftangle.web"

}
}

/* :251 */
#line 6758 "./ftangle.web"

else app_repl('#');
break;

case '\'':
case '"':
app_repl(a0);
app_repl(*loc++);
break;

default:
/* 250: */
#line 6806 "./ftangle.web"

{
sixteen_bits a;


if(isDigit(*loc)||*loc==','||*loc=='&'||*loc=='*'||*loc=='.'||
*loc=='['||*loc=='{')


{app_repl('#');}
else if(get_next()!=identifier)

macro_err(OC("! '#' should be followed by identifier"),YES);
else
{
a= ID_NUM(id_first,id_loc);




if((MAC_LOOKUP(a))==NULL)
{
app_repl('#');
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 6828 "./ftangle.web"
;
break;
}



macro_err(OC("! Immediate expansion of macro \"%s\" not implemented"),YES,name_of(a));
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 6835 "./ftangle.web"
;
}
}

/* :250 */
#line 6769 "./ftangle.web"

break;
}
}

/* :248 */
#line 6143 "./ftangle.web"

else
{
app_repl(a0);
}
break;

/* 241: */
#line 6386 "./ftangle.web"


case identifier:
/* 238: */
#line 6326 "./ftangle.web"

{
a= ID_NUM(id_first,id_loc);

if(a==lkwd)
/* 239: */
#line 6337 "./ftangle.web"

{
language0= language;

language= C;

if(get_next()!='(')
{

err0_print(ERR_T,OC("Missing left parenthesis"),0);
goto done_lkwd;
}

if(get_next()!=stringg)
{

err0_print(ERR_T,OC("Expected string argument to $L_KEYWORD"),0);
}
else
{
if(get_next()!=')')
{

err0_print(ERR_T,OC("Missing right parenthesis"),0);
goto done_lkwd;
}

/* 240: */
#line 6370 "./ftangle.web"

{
while(IS_WHITE(*id_first))
id_first++;

while(IS_WHITE(id_loc[-1]))
id_loc--;

mp= macrobuf;
x_keyword(&mp,macrobuf_end,id_first,id_loc,NO,language0!=TEX,
upper_case_code?WEB_FILE:CUR_FILE);
*mp= ' ';
divert((ASCII HUGE*)macrobuf,(ASCII HUGE*)mp,DONT_STOP);
}

/* :240 */
#line 6362 "./ftangle.web"

}

done_lkwd:
language= language0;
}

/* :239 */
#line 6331 "./ftangle.web"

else
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 6333 "./ftangle.web"

}

/* :238 */
#line 6389 "./ftangle.web"

break;

case keyword_name:
/* 240: */
#line 6370 "./ftangle.web"

{
while(IS_WHITE(*id_first))
id_first++;

while(IS_WHITE(id_loc[-1]))
id_loc--;

mp= macrobuf;
x_keyword(&mp,macrobuf_end,id_first,id_loc,NO,language0!=TEX,
upper_case_code?WEB_FILE:CUR_FILE);
*mp= ' ';
divert((ASCII HUGE*)macrobuf,(ASCII HUGE*)mp,DONT_STOP);
}

/* :240 */
#line 6393 "./ftangle.web"

break;

case module_name:



if(t==macro&&!mac_mod_name)
goto done;
else
{
/* 253: */
#line 6890 "./ftangle.web"

{
}

/* :253 */
#line 6404 "./ftangle.web"

/* 254: */
#line 6895 "./ftangle.web"

{
ASCII HUGE*try_loc= loc;


while(*try_loc==' '&&try_loc<limit)
try_loc++;

if(*try_loc=='+'&&try_loc<limit)
try_loc++;

while(*try_loc==' '&&try_loc<limit)
try_loc++;

if(*try_loc=='=')

err0_print(ERR_T,OC("Nested named modules.  Missing `@*' or `@ '?"),0);

}

/* :254 */
#line 6405 "./ftangle.web"
;
a= (sixteen_bits)(cur_module-name_dir);
app_repl(LEFT(a,0250));
app_repl(RIGHT(a));
ins_ln_no(0);
if(nuweb_mode)
{
a0= begin_meta;
goto reswitch;
}
break;
}

case constant:
case stringg:
/* 255: */
#line 6915 "./ftangle.web"


if(C_LIKE(language))
{
if(bin_constant&&a0==constant)
/* 263: */
#line 7109 "./ftangle.web"

{
app_converted(btoi(id_first,id_loc));
}

/* :263 */
#line 6920 "./ftangle.web"

else
copy_string(a0);
}
else if(a0==constant)
{
if(language==LITERAL)
copy_string(a0);
else if(hex_constant)
/* 258: */
#line 7022 "./ftangle.web"

{
app_converted(xtoi(id_first,id_loc));
}

/* :258 */
#line 6929 "./ftangle.web"

else if(bin_constant)
/* 263: */
#line 7109 "./ftangle.web"

{
app_converted(btoi(id_first,id_loc));
}

/* :263 */
#line 6931 "./ftangle.web"

else if(starts_with_0&&!floating_constant)
/* 261: */
#line 7079 "./ftangle.web"

{
app_converted(otoi(id_first,id_loc));
}

/* :261 */
#line 6933 "./ftangle.web"

else
copy_string(a0);
}
else if(R77&&a0==stringg&&!in_format)
{
if(*id_first=='\'')
rdc_char_constant();
else
{


if(*id_first=='"')*id_first= *(id_loc-1)= '\'';
copy_string(a0);
}
}
else
copy_string(a0);

break;

/* :255 */
#line 6420 "./ftangle.web"
;

case ascii_constant:
cp_ASCII();
break;

case begin_meta:
/* 242: */
#line 6565 "./ftangle.web"

{
app_repl(stringg);

if(!nuweb_mode)
app_repl(a0);


if(FORTRAN_LIKE(language))
{
column_mode= NO;
app_repl('\n');
}

scanning_meta= YES;

}

/* :242 */
#line 6427 "./ftangle.web"

break;

case end_meta:
/* 300: */
#line 8415 "./ftangle.web"


if(FORTRAN_LIKE(language)&&!free_form_input)
/* 301: */
#line 8421 "./ftangle.web"

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}

/* :301 */
#line 8418 "./ftangle.web"


/* :300 */
#line 6431 "./ftangle.web"
;
get_line();
app_repl(end_meta);
#line 6435 "./ftangle.web"
app_repl(stringg);
scanning_meta= NO;
break;

case dot_const:
app_repl(a0);
app_repl(dot_op.num);
break;

case begin_language:
switch(language)
{
case NO_LANGUAGE:

confusion(OC("scan_repl:begin_language"),OC("A language hasn't been defined yet"));

case RATFOR:
case RATFOR_90:
if(!RAT_OK("(scan_repl)"))

confusion(OC("scan_repl:begin_language"),OC("Attempting to append @Lr"));

case C:
case C_PLUS_PLUS:
case LITERAL:
column_mode= NO;
break;

case FORTRAN:
case FORTRAN_90:
case TEX:
if(!(scanning_defn||free_form_input))
{
/* 301: */
#line 8421 "./ftangle.web"

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}

/* :301 */
#line 6468 "./ftangle.web"

}
break;

default:

confusion(OC("app_id"),OC("Language %i is invalid"),language);
}




set_output_file(language);
if(!scanning_defn)
{app_repl(a0);app_repl((eight_bits)language);}
/* 302: */
#line 8429 "./ftangle.web"

{
store_two_bytes((sixteen_bits)(LINE_NUM+module_count));
}

/* :302 */
#line 6482 "./ftangle.web"

ins_ln_no(column_mode);
break;

case no_mac_expand:
app_repl(begin_language);
app_repl(a0);
break;

case set_line_info:
app_repl(begin_language);
app_repl(a0);
app_repl(line_info);
break;

case new_output_file:
if(t==macro)
goto done;
else
{
name_pointer np;

app_repl(begin_language);
app_repl(NO_LANGUAGE);
app_repl(upper_case_code);

a= ID_NUM_ptr(np,id_first,id_loc);
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 6509 "./ftangle.web"

np->macro_type= FILE_NAME;

if(nuweb_mode)
{
a0= begin_meta;
goto reswitch;
}
}
break;

case WEB_definition:
if(t==macro)
goto done;
else
{
/* 247: */
#line 6685 "./ftangle.web"

{
#define NAME_LEN 100

name_pointer np;
eight_bits HUGE*tok_ptr0,HUGE*tok_m_end0;
text_pointer text_ptr0,text_end0;
outer_char new_name[NAME_LEN];
ASCII HUGE*nn,HUGE*b;
sixteen_bits a;

if(!deferred_macros)
{

err0_print(ERR_T,OC("Sorry, deferred FWEB macros (defined in code part) are \
prohibited; use option `-TD' to permit them"),0);
continue;
}

tok_ptr0= tok_ptr;
tok_m_end0= tok_m_end;
text_ptr0= text_ptr;
text_end0= text_end;

tok_ptr= tok_dptr;
tok_m_end= tokd_end;
text_ptr= txt_dptr;
text_end= textd_end;

deferred_macro= YES;
np= app_macro(WEB_definition);
deferred_macro= NO;

tok_dptr= tok_ptr;
tok_ptr= tok_ptr0;
tok_m_end= tok_m_end0;

txt_dptr= text_ptr;
text_ptr= text_ptr0;
text_end= text_end0;

if(np==NULL)
continue;



if(
nsprintf(new_name,OC("@%d"),1,n_unique++)>=(int)(NAME_LEN))OVERFLW("new_name","");
to_ASCII(new_name);
for(nn= (ASCII*)new_name+STRLEN(new_name),b= np->byte_start;
b<(np+1)->byte_start;)
*nn++= *b++;

a= ID_NUM_ptr(np,(ASCII*)new_name,nn);
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 6736 "./ftangle.web"
;

np->macro_type= DEFERRED_MACRO;
np->equiv= (EQUIV)cur_text;

#undef NAME_LEN
}

/* :247 */
#line 6525 "./ftangle.web"
;
continue;
}

case begin_nuweb:
if(t!=module_name)
{
nuweb_mode1= nuweb_mode= !NUWEB_MODE;
goto done;
}
else
{

err0_print(ERR_T,OC("@N ignored; must appear before beginning of code part"),0);
continue;
}

case formatt:
case limbo_text:case op_def:case macro_def:
case definition:case undefinition:
case begin_code:
if(t!=module_name)
goto done;
else
{

err0_print(ERR_T,OC("@d, @l, @v, @W, @u, @f, and @a \
are ignored in code text"),0);
continue;

}

case end_of_buffer:
a0= ignore;

case m_ifdef:case m_ifndef:
case m_if:case m_else:case m_elif:case m_endif:case m_undef:case m_line:
case m_for:case m_endfor:
case new_module:
goto done;

/* :241 */
#line 6153 "./ftangle.web"


/* :228 */
/* 228: */
#line 6159 "./ftangle.web"

case '\n':


if(ntoken)ntoken++;
app_repl(a0);
break;

case '{':
app_repl(a0);

if(ntoken&&breakpoints&&t==module_name&&auto_bp)
/* 229: */
#line 6231 "./ftangle.web"

{
ASCII bp_cmd[BP_BUF_SIZE];

if(cur_module!=NULL)
{

if(
nsprintf(bp_cmd,OC("_BP(%d,\"%s\")"),2,module_count,name_of((sixteen_bits)(cur_module-name_dir)))>=(int)(BP_BUF_SIZE))OVERFLW("bp_cmd","");
to_ASCII(OC(bp_cmd));
divert(bp_cmd,bp_cmd+STRLEN(bp_cmd),DONT_STOP);
}
}

/* :229 */
#line 6171 "./ftangle.web"


break;

case begin_bp:
auto_bp= NO;
app_repl('{');
break;

case insert_bp:
if(breakpoints)
/* 229: */
#line 6231 "./ftangle.web"

{
ASCII bp_cmd[BP_BUF_SIZE];

if(cur_module!=NULL)
{

if(
nsprintf(bp_cmd,OC("_BP(%d,\"%s\")"),2,module_count,name_of((sixteen_bits)(cur_module-name_dir)))>=(int)(BP_BUF_SIZE))OVERFLW("bp_cmd","");
to_ASCII(OC(bp_cmd));
divert(bp_cmd,bp_cmd+STRLEN(bp_cmd),DONT_STOP);
}
}

/* :229 */
#line 6182 "./ftangle.web"

break;

default:
app_repl(a0);
break;
}
}

done:
if(stop_the_scan&&!from_buffer)
{
stop_the_scan= NO;
next_control= ignore;
}
else next_control= 
(eight_bits)CHOICE((from_buffer&&loc>limit)||stop,
ignore,a0);

if(t==module_name)
{

if(scanning_meta)
{
if(!nuweb_mode)
app_repl(end_meta);

app_repl(stringg);
scanning_meta= NO;
}
app_repl(begin_language);
app_repl(NUWEB_OFF|nuweb_mode);
}

/* 233: */
#line 6270 "./ftangle.web"

{
if(text_ptr>text_end)
OVERFLW("texts","x");

cur_text= text_ptr;
cur_text->nbytes= tok_ptr-cur_text->tok_start;

(++text_ptr)->tok_start= tok_ptr;
}

/* :233 */
#line 6216 "./ftangle.web"

cur_text->Language= (boolean)language0;
macro_scan= NO;
}

/* :228 */
/* 236: */
#line 6300 "./ftangle.web"

SRTN
ins_ln_no FCN((delta))
int delta C1("Increment to line number")
{
name_pointer np;

store_two_bytes((sixteen_bits)LINE_NUM);

id_first= x_to_ASCII(changing?change_file_name:cur_file_name);
id_loc= id_first+STRLEN(id_first);

store_two_bytes((sixteen_bits)((changing?change_line:cur_line)+delta));

store_two_bytes(ID_NUM_ptr(np,id_first,id_loc));
np->Language= (boolean)NO_LANGUAGE;
}

/* :236 */
/* 256: */
#line 6955 "./ftangle.web"

SRTN
copy_string FCN((a0))
eight_bits a0 C1("")
{
app_repl(a0);

for(;id_first<id_loc;id_first++)
{
if(*id_first=='@')
/* 257: */
#line 6987 "./ftangle.web"


if(language==TEX&&*(id_first+1)=='@')
id_first++;
else
{
id_first++;

switch(ccode[*id_first])
{
case '@':
break;

/* 10: */
#line 80 "./typedefs.hweb"


case begin_C:
case begin_RATFOR:
case begin_FORTRAN:
case begin_LITERAL



/* :10 */
#line 7000 "./ftangle.web"
:
case L_switch:
app_repl('@');
break;

case keyword_name:
case module_name:

err0_print(ERR_T,OC("RCS keywords and module names aren't \
allowed inside strings"),0);
for(id_first++;id_first[0]!='@'&&id_first[1]!='>';
id_first++)
{
app_repl('?');
}

default:
id_first++;
continue;
}
}

/* :257 */
#line 6965 "./ftangle.web"


/* :256 */
/* 256: */
#line 6976 "./ftangle.web"
app_repl(*id_first);
}

app_repl(a0);
}

/* :256 */
/* 259: */
#line 7033 "./ftangle.web"


unsigned long
xtoi FCN((b,b1))
CONST ASCII HUGE*b C0("Beginning of string.")
CONST ASCII HUGE*b1 C1("End of string.")
{
unsigned long n= 0;

for(b+= 2;b<b1;b++)
{
if(n>ULONG_MAX/16)
{
TOO_BIG;
break;
}

n*= 16;

if(isDigit(*b))
n+= *b-'0';
else
n+= A_TO_UPPER(*b)-'A'+10;
}

return n;
}

/* :259 */
/* 260: */
#line 7062 "./ftangle.web"

SRTN
app_converted FCN((n))
unsigned long n C1("")
{
ASCII temp[N_IDBUF];
ASCII HUGE*b;


if(
nsprintf((outer_char*)(temp),OC("%lu"),1,n)>=(int)(N_IDBUF))OVERFLW("(outer_char*)(temp)","");
to_ASCII((outer_char*)(temp));

app_repl(constant);
for(b= temp;*b!='\0';b++)app_repl(*b)
app_repl(constant);
}

/* :260 */
/* 262: */
#line 7085 "./ftangle.web"


unsigned long
otoi FCN((b,b1))
CONST ASCII HUGE*b C0("Beginning of string.")
CONST ASCII HUGE*b1 C1("End of string.")
{
unsigned long n= 0;

for(b++;b<b1;b++)
{
if(n>ULONG_MAX/8)
{
TOO_BIG;
break;
}

n= 8*n+(*b-'0');
}

return n;
}

/* :262 */
/* 264: */
#line 7115 "./ftangle.web"


unsigned long
btoi FCN((b,b1))
CONST ASCII HUGE*b C0("Beginning of string.")
CONST ASCII HUGE*b1 C1("End of string.")
{
unsigned long n= 0;

for(b+= 2;b<b1;b++)
{
if(n>ULONG_MAX/2)
{
TOO_BIG;
break;
}

n= 2*n+(*b-'0');
}

return n;
}

/* :264 */
/* 265: */
#line 7140 "./ftangle.web"

SRTN
rdc_char_constant(VOID)
{
int n;

if(*++id_first=='\\')
switch(*++id_first)
{
/* 266: */
#line 7168 "./ftangle.web"

case '0':n= '\0';break;
case '\\':n= '\\';break;
case '\'':n= '\'';break;
case '"':n= '\"';break;
case '?':n= '\?';break;
case 'a':n= '\007';break;
case 'b':n= '\b';break;
case 'f':n= '\f';break;
case 'n':n= '\n';break;
case 'r':n= '\r';break;
case 't':n= '\t';break;
case 'v':n= '\v';break;

/* :266 */
#line 7149 "./ftangle.web"

default:

err0_print(ERR_T,OC("Invalid escape sequence '\\%c' \
in Ratfor character constant; null assumed"),1,XCHR(*id_first));
n= 0;
break;
}
else n= *id_first;

if(*(id_first+1)!='\'')
err0_print(ERR_T,OC("Ratfor character constant longer \
than one byte; extra characters ignored"),0);

app_converted(n);
}

/* :265 */
/* 267: */
#line 7186 "./ftangle.web"

SRTN
cp_ASCII(VOID)
{
if(*id_first++=='\'')
{
if(C_LIKE(language))
app_aconst('o',YES);
else
app_aconst('d',NO);

if(*id_first!='\'')
/* 268: */
#line 7250 "./ftangle.web"

{
ASCII temp[100],HUGE*t= temp;

id_first--;

if(id_first[-1]=='\\')
id_first--;

while(*id_first!='\'')
*t++= *id_first++;

*t= '\0';


macro_err(OC("! $A('%c') requires just one character between \
the single quotes; did you mean $A(\"%s\")?"),NO,temp[0],temp);
}

/* :268 */
#line 7198 "./ftangle.web"

}
else
{
if(C_LIKE(language))
{
app_repl('"');

while(*id_first!='"')
{
app_repl('\\');
app_aconst('o',NO);
}

app_repl('"');
}
else
{
sixteen_bits a;
ASCII delim= (ASCII)(is_RATFOR_(language)?'"':'\'');
int n= STRLEN(t_style.ASCII_fcn);


a= ID_NUM(t_style.ASCII_fcn,t_style.ASCII_fcn+n);
/* 237: */
#line 6319 "./ftangle.web"

{
app_repl(LEFT(a,ID0));
app_repl(RIGHT(a));
}

/* :237 */
#line 7222 "./ftangle.web"

app_repl('(');
app_repl(delim);
while(*id_first!='"')
app_repl(*id_first++);
app_repl(delim);
app_repl(')');
}
}

#if(0) 


app_repl('{');

while(*id_first!='"')
{
app_aconst(YES);
app_repl(',');
}

app_repl('0');
app_repl('}');
}
#endif
}

/* :267 */
/* 269: */
#line 7269 "./ftangle.web"


SRTN
app_aconst FCN((fmt_char,leading_zero))
outer_char fmt_char C0("Either 'o' (octal) or 'd' (decimal)")
boolean leading_zero C1("For octal format")
{
eight_bits n;
outer_char value[10],*v;

if(*id_first=='@')
{
n= *id_first++;

if(*id_first!='@')
err0_print(ERR_T,OC("Should use double @ within \
ASCII constant"),0);
else id_first++;
}
else if(*id_first=='\\')
{

id_first++;

n= esc_achar((CONST ASCII HUGE*HUGE*)&id_first);

/* :269 */
/* 269: */
#line 7304 "./ftangle.web"
}
else n= *id_first++;









#ifdef scramble_ASCII
n= xxord[n];
#endif

#ifdef unscramble_ASCII
n= XCHR(n);
#endif




app_repl(constant);


if(
nsprintf(value,OC(fmt_char=='o'?"%s%o":"%s%d"),2,leading_zero?"0":"",n)>=(int)(10))OVERFLW("value","");

for(v= value;*v;v++)
app_repl(XORD(*v));

app_repl(constant);

#if(0) 
int l;

if(leading_zero)app_repl('0');

value[0]= '0'+(n>>6);
value[1]= '0'+((n-0100*(n>>6))>>3);
value[2]= '0'+(n-010*(n>>3));

for(l= 0;l<3;l++)
if(value[l]!='0')break;

for(;l<3;l++)
app_repl(value[l]);

#endif
}

/* :269 */
/* 271: */
#line 7368 "./ftangle.web"


SRTN
i_ascii_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
int len;
eight_bits*start= pargs[0]+1;

CHK_ARGS("$A",1);

if(translate_ASCII)
{
eight_bits HUGE*tok_ptr0= tok_ptr;

if(*start==stringg)
id_first= (ASCII HUGE*)(start+1);
else
{

err0_print(ERR_T,OC("Argument of _A should be quoted; \
just returning argument"),0);
goto just_return;
}

cp_ASCII();

len= PTR_DIFF(int,tok_ptr,tok_ptr0);
MCHECK(len,"_ascii_");
memcpy(mp,tok_ptr0,len);
tok_ptr= tok_ptr0;
}
else
{
just_return:
len= PTR_DIFF(int,pargs[1],start);
MCHECK(len,"_ascii_");
STRNCPY(mp,start,len);
}

mp+= len;
}

/* :271 */
/* 273: */
#line 7418 "./ftangle.web"


SRTN
scan_module(VOID)
{
name_pointer p= NULL;

module_count++;

params= global_params;
frz_params();
set_output_file(global_language);

progress();

/* 275: */
#line 7452 "./ftangle.web"

{
parsing_mode= INNER;
nuweb_mode1= nuweb_mode;

next_control= ignore;

if(module_count==1)
{
*(mp-1)= '@';
*mp= 'm';
divert((ASCII HUGE*)macrobuf,(ASCII HUGE*)mp,STOP);




}


scanning_TeX= YES;
scan_text(macro,p,EXPAND);
scanning_TeX= NO;

if(module_count==1)/* 231: */
#line 6252 "./ftangle.web"

{
IN_COMMON ASCII HUGE*pbp;


breakpoints= BOOLEAN(MAC_LOOKUP(ID_NUM(pbp,pbp+3))!=NULL);
}

/* :231 */
#line 7475 "./ftangle.web"
;

if(mlevel!=0)
{

err0_print(ERR_M,OC("Invalid preprocessor block structure (level %d). \
Missing @#endif?"),1,mlevel);
mlevel= 0;
}
}

/* :275 */
#line 7433 "./ftangle.web"
;
/* 296: */
#line 8332 "./ftangle.web"

switch(next_control)
{
case begin_code:
{
boolean nuweb_mode0= nuweb_mode;

params= global_params;
nuweb_mode= nuweb_mode0;
frz_params();
set_output_file(global_language);

p= name_dir;
/* 300: */
#line 8415 "./ftangle.web"


if(FORTRAN_LIKE(language)&&!free_form_input)
/* 301: */
#line 8421 "./ftangle.web"

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}

/* :301 */
#line 8418 "./ftangle.web"


/* :300 */
#line 8345 "./ftangle.web"
;
break;
}

case module_name:
if(cur_module)
{
p= cur_module;
params= cur_module->mod_info->params;
}
else
{
/* :296 */
/* 296: */
#line 8362 "./ftangle.web"

while((next_control= skip_ahead(ignore,NO))!=new_module)
;
return;
}

/* 297: */
#line 8386 "./ftangle.web"

{
}

/* :297 */
#line 8368 "./ftangle.web"


/* 299: */
#line 8396 "./ftangle.web"

{
while((next_control= get_next())=='+')
;

if(next_control!='='&&next_control!=eq_eq)
{

err0_print(ERR_T,OC("Code text of %s flushed; = sign is missing"),1,MTRANS);


while((next_control= skip_ahead(ignore,NO))!=new_module)
;

return;
}
}

/* :299 */
#line 8370 "./ftangle.web"
;
frz_params();
/* 300: */
#line 8415 "./ftangle.web"


if(FORTRAN_LIKE(language)&&!free_form_input)
/* 301: */
#line 8421 "./ftangle.web"

{
loc= limit+1;
column_mode= YES;
parsing_mode= OUTER;
}

/* :301 */
#line 8418 "./ftangle.web"


/* :300 */
#line 8372 "./ftangle.web"
;
break;

default:return;
}

next_control= ignore;
scan_text(module_name,p,EXPAND);
column_mode= NO;


/* :296 */
#line 7434 "./ftangle.web"
;
}

/* :273 */
/* 277: */
#line 7501 "./ftangle.web"


SRTN
scan_text FCN((text_type,p,expand))
int text_type C0("Either |macro| or |module_name|.")
CONST name_pointer p C0("Module name.")
boolean expand C1("Do we expand?")
{
boolean if_switch;
boolean scanned_if= NO;
boolean first_text= YES;
eight_bits HUGE*pp;
text_pointer q;

scanning_defn= BOOLEAN(text_type==macro);

if(++mlevel>=MAX_LEVEL)

fatal(ERR_T,OC("Conditional nesting depth exceeded."),OC(""));


WHILE()
{
if(scanning_defn&&expand)
{
while(next_control<=ignore_defn)
{
if((next_control= 
skip_ahead(next_control,YES))==module_name)
{
loc-= 2;next_control= get_next();
}
}
scanning_TeX= NO;
}
else
if(!expand)
{
while((next_control= 
skip_ahead(next_control,YES))==module_name)
if((next_control= skip_ahead(next_control,YES))!=ignore)

err0_print(ERR_T,OC("Expected @> after @<"),0);
}
else
{
/* 302: */
#line 8429 "./ftangle.web"

{
store_two_bytes((sixteen_bits)(LINE_NUM+module_count));
}

/* :302 */
#line 7547 "./ftangle.web"


scan_repl(module_name,stop_the_scan);


/* 298: */
#line 8391 "./ftangle.web"

{
}

/* :298 */
#line 7552 "./ftangle.web"


/* 303: */
#line 8435 "./ftangle.web"

{
if(p==name_dir||p==NULL)
{
cur_text->module_text= (first_text&&mlevel==1);




if(cur_text->module_text)
cur_text->Language= (boolean)global_language;

last_unnamed->text_link= (sixteen_bits)(cur_text-text_info);

last_unnamed= cur_text;
}
else if(p->equiv==(EQUIV)text_info)
{
cur_text->module_text= YES;
p->equiv= (EQUIV)cur_text;
}
else
{
LANGUAGE language0;

q= (text_pointer)p->equiv;
language0= (LANGUAGE)q->Language;






cur_text->module_text= (first_text&&mlevel==1);

if(cur_text->module_text)
cur_text->Language= (boolean)language0;



while(q->text_link<module_flag)q= q->text_link+text_info;

q->text_link= (sixteen_bits)(cur_text-text_info);

}



cur_text->text_link= module_flag;
}

/* :303 */
#line 7555 "./ftangle.web"

first_text= NO;
}

next_macro_token:
switch(next_control)
{
/* 278: */
#line 7653 "./ftangle.web"


case m_ifdef:
DEF_OR_NDEF(M_TRUE);
break;

case m_ifndef:
DEF_OR_NDEF(M_FALSE);
break;

case m_if:
found_else= NO;

if(!expand)
{
to_endif(m_if);
goto next_macro_token;
}
else
/* 279: */
#line 7786 "./ftangle.web"

{
/* 284: */
#line 7966 "./ftangle.web"

{
boolean scan0= scanning_defn;

scanning_defn= YES;
scan_repl(macro,STOP);
scanning_defn= scan0;

cur_text->nargs= UNDEFINED_MACRO;

pp= xmac_text(macrobuf,cur_text->tok_start,tok_ptr);
if_switch= eval(pp,mp);
}

/* :284 */
#line 7788 "./ftangle.web"
;
GET_LINE;

if(if_switch)
scan_text(text_type,p,if_switch);
else
/* 280: */
#line 7804 "./ftangle.web"

{
expand= NO;to_else();

if(next_control!=m_endif)
{
scanned_if= YES;
goto next_macro_token;
}
else
{
next_control= ignore;
expand= YES;
GET_LINE;
break;
}
}

/* :280 */
#line 7794 "./ftangle.web"

}

/* :279 */
#line 7672 "./ftangle.web"


break;

case m_elif:






next_control= ignore;

if((mlevel==1&&!scanned_if)||found_else)
{
OUT_OF_ORDER("elif");
break;
}

scanned_if= NO;

if(expand)
{
to_endif(m_elif);
goto next_macro_token;
}
else
/* 279: */
#line 7786 "./ftangle.web"

{
/* 284: */
#line 7966 "./ftangle.web"

{
boolean scan0= scanning_defn;

scanning_defn= YES;
scan_repl(macro,STOP);
scanning_defn= scan0;

cur_text->nargs= UNDEFINED_MACRO;

pp= xmac_text(macrobuf,cur_text->tok_start,tok_ptr);
if_switch= eval(pp,mp);
}

/* :284 */
#line 7788 "./ftangle.web"
;
GET_LINE;

if(if_switch)
scan_text(text_type,p,if_switch);
else
/* 280: */
#line 7804 "./ftangle.web"

{
expand= NO;to_else();

if(next_control!=m_endif)
{
scanned_if= YES;
goto next_macro_token;
}
else
{
next_control= ignore;
expand= YES;
GET_LINE;
break;
}
}

/* :280 */
#line 7794 "./ftangle.web"

}

/* :279 */
#line 7699 "./ftangle.web"


expand= YES;
break;

case m_else:






next_control= ignore;

if((mlevel==1&&!scanned_if)||found_else)
{
OUT_OF_ORDER("else");
break;
}

found_else= YES;
scanned_if= NO;

expand= BOOLEAN(!expand);

GET_LINE;

if(expand)
scan_text(text_type,p,expand);
else
{
to_endif(m_else);
expand= YES;
goto next_macro_token;
}

break;

case m_endif:
next_control= ignore;

if(mlevel==1)
{
OUT_OF_ORDER("endif");
break;
}

found_else= NO;
GET_LINE;
mlevel--;
return;

case m_undef:
if(!expand)
next_control= ignore;
else
{
if((next_control= get_next())!=identifier)

err0_print(ERR_M,OC("Identifier must follow @#undef"),0);
else
{
undef(ID_NUM(id_first,id_loc),SILENT);
GET_LINE;

}
}
break;

case m_line:

confusion(OC("preprocessor cases"),OC("m_line shouldn't reach here"));

case m_for:
case m_endfor:
if(!expand)next_control= ignore;
else
{

err0_print(ERR_M,OC("Sorry, preprocessor command isn't implemented yet"),0);
}
break;

/* :278 */
#line 7562 "./ftangle.web"


case new_output_file:

err0_print(ERR_T,OC("@O and @o are allowed only in the code \
section; command ignored"),0);
next_control= ignore;
loc= limit+1;
break;

case definition:case undefinition:
case WEB_definition:
if(!expand)
next_control= ignore;
else
{
name_pointer np;
eight_bits last_control;

if((np= app_macro(last_control= next_control))
==NULL)continue;
else if(last_control==WEB_definition
&&!(IS_PROTECTED(np)&&(npq->built_in&&!redefine_builtins
||!npq->built_in&&!redefine_macros)))
np->equiv= (EQUIV)cur_text;
}
break;


default:
if(next_control<=ignore_defn)
break;

mlevel--;
return;
}
}
}

/* :277 */
/* 281: */
#line 7826 "./ftangle.web"


SRTN
out_of_order FCN((cmd))
CONST outer_char cmd[]C1("Name of bad preprocessor command.")
{

err0_print(ERR_M,OC("Ignored out-of-order \"@#%s\" (mlevel = %d)"),2,cmd,mlevel);
}

/* :281 */
/* 282: */
#line 7840 "./ftangle.web"


SRTN
to_else(VOID)
{
int elevel= 0,elifs[MAX_LEVEL],elses[MAX_LEVEL],k;

for(k= 0;k<MAX_LEVEL;k++)
elifs[k]= elses[k]= 0;

WHILE()
switch(next_control= skip_ahead(next_control,NO))
{
case m_if:
case m_ifdef:
case m_ifndef:
elevel++;
break;

case m_elif:
if(elses[elevel])

err0_print(ERR_M,OC("Can't have @#elif after @#else"),0);
elifs[elevel]++;
if(elevel==0)return;
break;

case m_else:
if(elses[elevel]++)

err0_print(ERR_M,OC("Only one @#else allowed \
(scanning to @else)"),0);
if(elevel==0)
{
if(language==TEX&&!get_line())
loc= limit+1;
return;
}
break;

case m_endif:

elifs[elevel]= elses[elevel]= 0;

if(elevel--==0)
{
found_else= NO;
if(language==TEX&&!get_line())
loc= limit+1;
return;
}
break;

case new_module:

err0_print(ERR_M,OC("Section ended during scan for \
\"@#else\", \"@#elif\", or \"@#endif\". Inserted \"@#endif\". \
(elevel = %d)"),1,elevel);
if(elevel==0)
found_else= NO;

return;
}
}

/* :282 */
/* 283: */
#line 7903 "./ftangle.web"


SRTN
to_endif FCN((m_case))
int m_case C1("Case that called to_endif")
{
int elevel= 1,elifs[MAX_LEVEL],elses[MAX_LEVEL],k;

for(k= 0;k<MAX_LEVEL;k++)
elifs[k]= elses[k]= 0;

if(m_case==m_elif)
elifs[elevel]= 1;
else
{
if(m_case==m_else)
elses[elevel]= 1;
}

WHILE()
switch(next_control= skip_ahead(next_control,NO))
{
case m_if:
case m_ifdef:
case m_ifndef:
elevel++;
break;

case m_elif:
if(elses[elevel])

err0_print(ERR_M,OC("Can't have @#elif after @#else"),0);
elifs[elevel]++;
break;

case m_else:
if(elses[elevel]++)

err0_print(ERR_M,OC("Only one @#else allowed \
(scanning to @endif)"),0);
break;

case m_endif:

elifs[elevel]= elses[elevel]= 0;

if(--elevel==0)
{
found_else= NO;
if(language==TEX&&!get_line())
loc= limit+1;
return;
}
break;

case new_module:

err0_print(ERR_M,OC("Section ended during scan for \
\"endif\"; inserted \"endif\". (elevel = %d)"),1,elevel);
if(elevel==0)
found_else= NO;
return;
}
}

/* :283 */
/* 287: */
#line 7993 "./ftangle.web"


name_pointer
app_macro FCN((last_control))
eight_bits last_control C1("Last token processed.")
{
sixteen_bits a;
name_pointer np= NULL;
boolean make_recursive= NO;
boolean make_protected= NO;
ASCII insert_type[6];
int insert_num= 0;
eight_bits temp[2];
boolean nuweb_mode0= nuweb_mode;

nuweb_mode= NO;

is_WEB_macro= BOOLEAN(last_control==WEB_definition);

if(is_WEB_macro||C_LIKE(language))
{
while((next_control= get_next())=='\n')
;


if(is_WEB_macro)
if(next_control==MAKE_RECURSIVE)
{
make_recursive= YES;
next_control= get_next();
}
else if(next_control==AUTO_INSERT)
/* 288: */
#line 8098 "./ftangle.web"

{
ASCII c;

while((c= *loc++)!=END_AUTO_INSERT)
{
if(*loc==' ')
{

err0_print(ERR_M,OC("Found space instead of ']' after automatic \
insertion material"),0);
break;
}

if(loc==limit)
break;

if(insert_num>=6)
{
if(insert_num++==6)

err0_print(ERR_M,OC("Can't have more than 6 types of automatic \
insertion material; remaining ignored"),0);
continue;
}

switch(c)
{
case '*':
STRNCPY(insert_type,"pmsfbi",insert_num= 6);
break;

case 'p':case 'P':
case 'm':case 'M':
case 's':case 'S':
case 'f':case 'F':
case 'b':case 'B':
case 'i':case 'I':
insert_type[insert_num++]= c;
break;

default:

err0_print(ERR_M,OC("Auto insertion type must be one of \
\"ibfmps\""),0);
continue;
}
}

next_control= get_next();
}

/* :288 */
#line 8025 "./ftangle.web"

else if(next_control==PROTECTED)
{
make_protected= YES;
next_control= get_next();
}

if(next_control!=identifier)
{

err0_print(ERR_M,OC("Definition flushed in %s; must start with \
identifier"),1,MTRANS);

np= NULL;
goto done_append;
}

a= ID_NUM_ptr(np,id_first,id_loc);


temp[0]= LEFT(a,ID0);temp[1]= RIGHT(a);
/* 289: */
#line 8154 "./ftangle.web"

{
while(insert_num-->0)
switch(insert_type[insert_num])
{
case 'p':case 'P':
if(insert.program.end>insert.program.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"program");
STRNCPY(insert.program.start,temp,2);
insert.program.end= insert.program.start+2;
break;

case 'm':case 'M':
if(insert.module.end>insert.module.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"module");
STRNCPY(insert.module.start,temp,2);
insert.module.end= insert.module.start+2;
break;

case 's':case 'S':
if(insert.subroutine.end>insert.subroutine.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"subroutine");
STRNCPY(insert.subroutine.start,temp,2);
insert.subroutine.end= insert.subroutine.start+2;
break;

case 'f':case 'F':
if(insert.function.end>insert.function.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"function");
STRNCPY(insert.function.start,temp,2);
insert.function.end= insert.function.start+2;
break;

case 'b':case 'B':
if(insert.blockdata.end>insert.blockdata.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"blockdata");
STRNCPY(insert.blockdata.start,temp,2);
insert.blockdata.end= insert.blockdata.start+2;
break;

case 'i':case 'I':
if(insert.interface.end>insert.interface.start)

err0_print(ERR_M,OC("Overriding previous auto insertion type %s"),1,"interface");
STRNCPY(insert.interface.start,temp,2);
insert.interface.end= insert.interface.start+2;
break;
}
}

/* :289 */
#line 8045 "./ftangle.web"



app_repl(temp[0]);
app_repl(temp[1]);

np->macro_type= IMMEDIATE_MACRO;


if(*loc!='(')
{
if(is_WEB_macro)
{app_repl(' ');}
else if(C_LIKE(language))
{

app_repl(stringg);app_repl(' ');app_repl(stringg);
}
}
}

nuweb_mode= nuweb_mode0;
scan_repl((eight_bits)macro,(boolean)(!scanning_defn));



if(is_WEB_macro)
/* 290: */
#line 8187 "./ftangle.web"

{
#if 0
text_ptr->tok_start= 
#endif
tok_ptr= argize(cur_text->tok_start,tok_ptr);

cur_text->Language= (boolean)global_language;
cur_text->recursive= make_recursive;
cur_text->protected= make_protected;
}

/* :290 */
#line 8072 "./ftangle.web"

else
cur_text->nargs= (eight_bits)CHOICE(last_control==definition,
OUTER_MACRO,OUTER_UNMACRO);

if(is_WEB_macro&&IS_PROTECTED(np)&&(npq->built_in&&!redefine_builtins
||!npq->built_in&&!redefine_macros))

err0_print(ERR_M,OC("Can't redefine protected %s `%s'; definition \
(probably on previous line) ignored.  \
Use command-line option `-T%c' to override"),3,npq->built_in?"built-in function":"macro",name_of(a),npq->built_in?'b':'m');
else
sv_macro();

done_append:
is_WEB_macro= NO;
return np;
}

/* :287 */
/* 291: */
#line 8203 "./ftangle.web"


SRTN
sv_macro(VOID)
{
eight_bits HUGE*p;

cur_text->nbytes= tok_ptr-cur_text->tok_start;
p= GET_MEM("macro space",cur_text->nbytes,eight_bits);
memcpy(p,cur_text->tok_start,cur_text->nbytes);
text_ptr->tok_start= tok_ptr= cur_text->tok_start;
cur_text->tok_start= p;

cur_text->text_link= macro;
}

/* :291 */
/* 292: */
#line 8221 "./ftangle.web"


SRTN
app_dmacro FCN((p,p1))
CONST eight_bits HUGE*p C0("Start")
CONST eight_bits HUGE*p1 C1("End.")
{
eight_bits a0,a1;
sixteen_bits a;
name_pointer np;
boolean make_recursive= NO;
boolean make_protected= NO;

if(*p==MAKE_RECURSIVE)
{
make_recursive= YES;
p++;
}

if(p+2>p1)
{

macro_err(OC("! Invalid argument to $DEFINE"),YES);
return;
}

if(TOKEN1(a0= *p++))
{

macro_err(OC("! $DEFINE flushed; must start with identifier"),YES);
return;
}

a= IDENTIFIER(a0,a1= *p++);
app_repl(a0);
app_repl(a1);

np= name_dir+a;

np->macro_type= IMMEDIATE_MACRO;

if(*p=='=')
{p++;app_repl(' ');}

while(p<p1)
{app_repl(*p++);}

/* 233: */
#line 6270 "./ftangle.web"

{
if(text_ptr>text_end)
OVERFLW("texts","x");

cur_text= text_ptr;
cur_text->nbytes= tok_ptr-cur_text->tok_start;

(++text_ptr)->tok_start= tok_ptr;
}

/* :233 */
#line 8266 "./ftangle.web"



/* 290: */
#line 8187 "./ftangle.web"

{
#if 0
text_ptr->tok_start= 
#endif
tok_ptr= argize(cur_text->tok_start,tok_ptr);

cur_text->Language= (boolean)global_language;
cur_text->recursive= make_recursive;
cur_text->protected= make_protected;
}

/* :290 */
#line 8269 "./ftangle.web"

sv_macro();

np->equiv= (EQUIV)cur_text;
}

/* :292 */
/* 293: */
#line 8278 "./ftangle.web"


SRTN
i_define_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
CHK_ARGS("$M",1);

app_dmacro(pargs[0]+1,pargs[1]);
}

/* :293 */
/* 294: */
#line 8292 "./ftangle.web"


SRTN
i_undef_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
eight_bits a0;
eight_bits HUGE*p= pargs[0]+1;

CHK_ARGS("$UNDEF",1);

if(p+2>pargs[1])
{

macro_err(OC("! Invalid argument to $UNDEF(...)"),YES);
return;
}

if(TOKEN1(a0= *p++))
{

macro_err(OC("! $UNDEF(...) flushed; must start with identifier"),YES);
return;
}

undef(IDENTIFIER(a0,*p),NO);
}

/* :294 */
/* 304: */
#line 8488 "./ftangle.web"


SRTN
phase1(VOID)
{
LANGUAGE language0= language;

phase= 1;
module_count= 0;
rst_input();rst_out(NOT_CONTINUATION);
reading(web_file_name,NO);

/* 306: */
#line 8527 "./ftangle.web"

{
ASCII*pkwd;

pkwd= x__to_ASCII(OC(LKWD));

lkwd= ID_NUM(pkwd,pkwd+STRLEN(LKWD));
}

/* :306 */
#line 8500 "./ftangle.web"


while((next_control= skip_ahead(ignore,NO))!=new_module)
;

chk_override(language0);
fin_language();
global_params= params;
set_output_file(global_language);


while(!input_has_ended)
scan_module();

chk_complete();
/* 308: */
#line 8545 "./ftangle.web"

{
name_pointer np;


for(np= name_dir;np<name_ptr;np++)
if(np->equiv!=NULL&&np->equiv!=(EQUIV)text_info
&&np->macro_type==NOT_DEFINED)
num_distinct_modules++;

num_modules= module_count;
}

/* :308 */
#line 8515 "./ftangle.web"

}

/* :304 */
/* 310: */
#line 8569 "./ftangle.web"


SRTN
i_modules_ FCN((n,pargs))
int n C0("")
PARGS pargs C1("")
{
outer_char temp[50];
int m= 
nsprintf(temp,OC("%c%u%c"),3,XCHR(constant),*(pargs[0]+2)=='0'?num_distinct_modules:num_modules,XCHR(constant));

CHK_ARGS("$MODULES",1);

MCHECK(m,"_modules_");
STRCPY(mp,to_ASCII(temp));
mp+= m;
}

/* :310 */
/* 311: */
#line 8589 "./ftangle.web"


SRTN
see_statistics(VOID)
{
CLR_PRINTF(ALWAYS,info,("\n\nMEMORY USAGE STATISTICS:\n"));
STAT0("names",sizeof(*name_ptr),
SUB_PTRS(name_ptr,name_dir),max_names,smin0(MAX_VAL("n")),"n","");

STAT0("replacement texts",sizeof(*text_ptr),
SUB_PTRS(text_ptr,text_info),max_texts,smin0(MAX_VAL("x")),"x","");

STAT0("deferred texts",sizeof(*txt_dptr),
SUB_PTRS(txt_dptr,txt_dinfo),dtexts_max,smin0(MAX_VAL("dx")),"dx",";");

STAT0("bytes",sizeof(*byte_ptr),
SUB_PTRS(byte_ptr,byte_mem),max_bytes,smin0(MAX_VAL("b")),"b","");

STAT0("tokens",sizeof(*tok_ptr),
SUB_PTRS((mx_tok_ptr>tok_ptr?mx_tok_ptr:tok_ptr),tok_mem),
max_toks,smin0(MAX_VAL("tt")),"tt","");

STAT0("deferred tokens",sizeof(*tok_dptr),
SUB_PTRS((mx_dtok_ptr>tok_dptr?mx_dtok_ptr:tok_dptr),tok_dmem),
max_dtoks,smin0(MAX_VAL("dt")),"dt",".");

mem_avail(1);
}

/* :311 */
/* 312: */
#line 8619 "./ftangle.web"


SRTN
t_macros(VOID)
{
/* 106: */
#line 1673 "./ftangle.web"


#line 1676 "./ftangle.web"
SAVE_MACRO("$MODULE_NAME $STRING($$MODULE_NAME)");

/* :106 */
/* 110: */
#line 1752 "./ftangle.web"


#if 0
SAVE_MACRO("_STUB(s)$IFCASE($LANGUAGE_NUM,\
{missing_mod(#s);},{missing_mod(#s);},\
call nomod(#s),call nomod(#s),\
call nomod(#s),call nomod(#s),\
\\missingmod{s},\
%nomod(s),%nomod(s))");
#endif

SAVE_MACRO("$STUB(s)$IFCASE($LANGUAGE_NUM,\
missing_mod(#s);, missing_mod(#s);,\
call nomod(#s), call nomod(#s),\
call nomod(#s), call nomod(#s),\
\\missingmod{s},\
%nomod(s), %nomod(s))");

/* :110 */
/* 117: */
#line 1980 "./ftangle.web"


#line 1983 "./ftangle.web"
SAVE_MACRO("$VERSION $STRING($$VERSION)");

/* :117 */
/* 119: */
#line 2007 "./ftangle.web"


#line 2010 "./ftangle.web"
#line 2011 "./ftangle.web"
#line 2012 "./ftangle.web"

SAVE_MACRO("$DAY $TM(0)");
SAVE_MACRO("$DATE $TM(1)");
SAVE_MACRO("$TIME $TM(2)");

#line 2018 "./ftangle.web"
SAVE_MACRO("$TM(i)$STRING($$TM(i))");

/* :119 */
/* 232: */
#line 6261 "./ftangle.web"


/* :232 */
/* 232: */
#line 6266 "./ftangle.web"

/* :232 */
/* 270: */
#line 7359 "./ftangle.web"


#line 7362 "./ftangle.web"
SAVE_MACRO("$A(s)$$ASCII(s)");

#line 7365 "./ftangle.web"
SAVE_MACRO("$ASCII(s)$$ASCII(s)");

/* :270 */
/* 295: */
#line 8320 "./ftangle.web"


#line 8323 "./ftangle.web"
SAVE_MACRO("$INCR(N,...)$INCR0(#!N,$EVAL(N+$IFELSE(#0,0,1,#1)))");

#line 8326 "./ftangle.web"
SAVE_MACRO("$DECR(N,...)$INCR0(#!N,$EVAL(N-$IFELSE(#0,0,1,#1)))");

#line 8329 "./ftangle.web"
SAVE_MACRO("$INCR0(N,N1)$M(#!N N1)");

/* :295 */
/* 309: */
#line 8560 "./ftangle.web"


#line 8563 "./ftangle.web"
SAVE_MACRO("$MODULES $$MODULES(0)");

#line 8566 "./ftangle.web"
SAVE_MACRO("$SECTIONS $$MODULES(1)");

/* :309 */
/* 316: */
#line 8723 "./ftangle.web"


SAVE_MACRO("$DO(k,kmin,kmax,...)$UNROLL(k,kmin,kmax,$IFCASE(#0,1,#.))");

/* :316 */
#line 8624 "./ftangle.web"
;
}

/* :312 */
/* 314: */
#line 8644 "./ftangle.web"


SRTN
out_msg FCN((msg,msg1))
CONST ASCII*msg C0("Start of message.")
CONST ASCII*msg1 C1("See the description below.")
{
eight_bits HUGE*temp;
eight_bits HUGE*mp0= mp,
HUGE*macrobuf0= macrobuf,HUGE*macrobuf_end0= macrobuf_end;
char HUGE*new_msg;
boolean nuweb_mode0,in_string0,meta_mode0;


mp= macrobuf= temp= GET_MEM("out_msg:temp",MSG_BUF_SIZE,eight_bits);
macrobuf_end= temp+MSG_BUF_SIZE;



if(msg1==NULL)
msg1= msg+STRLEN(msg);

new_msg= (char HUGE*)str_to_mb((eight_bits HUGE*)msg,
(eight_bits HUGE*)msg1,NO);


spcs_after_cmnt= SPCS_AFTER_CMNT;




nuweb_mode0= nuweb_mode;
in_string0= in_string;
meta_mode0= meta_mode;

meta_mode= nuweb_mode= NO;
#if 0
in_string= YES;


#endif

OUT_CHAR(begin_meta);
OUT_CHAR(begin_meta);
in_string= YES;
while(*new_msg)
OUT_CHAR(*new_msg++);
in_string= NO;
OUT_CHAR(end_meta);

nuweb_mode= nuweb_mode0;
in_string= in_string0;
meta_mode= meta_mode0;

spcs_after_cmnt= 0;

FREE_MEM(temp,"out_msg:temp",MSG_BUF_SIZE,eight_bits);
macrobuf= macrobuf0;mp= mp0;macrobuf_end= macrobuf_end0;
}

/* :314 */
/* 315: */
#line 8705 "./ftangle.web"


static sixteen_bits id_unroll;

SPEC univ_tokens[]= {
{"_UNROLL",0,x_unroll,&id_unroll},
{"$UNROLL",0,x_unroll,&id_unroll},
{"",0,NULL,NULL}
};

SRTN
ini_univ_tokens FCN((language0))
LANGUAGE language0 C1("")
{
ini_special_tokens(language0,univ_tokens);
}

/* :315 */
/* 317: */
#line 8728 "./ftangle.web"


SRTN
ini_tokens FCN((language0))
LANGUAGE language0 C1("")
{
switch(language0)
{
case C:
break;

case C_PLUS_PLUS:
break;

case FORTRAN:
break;

case FORTRAN_90:
break;

case TEX:
break;

default:
break;
}

ini_univ_tokens(language0);
}

/* :317 */
/* 318: */
#line 8759 "./ftangle.web"


int
get_constant FCN((e))
eight_bits HUGE*e C1("")
{
boolean positive= YES;
int i= 1;

if(*e=='-')
{
positive= NO;
e++;
}

if(*e++!=constant)
{

err0_print(ERR_T,OC("Invalid loop constant"),0);
return i;
}

to_outer(e);
i= ATOI(e);
return(positive)?i:-i;
}



/* :318 */
#line 42 "./ftangle.web"

#endif 

/* :1 */

