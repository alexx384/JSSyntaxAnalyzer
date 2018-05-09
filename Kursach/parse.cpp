
/*  A Bison parser, made from parse.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	ABSTRACT	258
#define	BOOLEAN	259
#define	BREAK	260
#define	BYTE	261
#define	CASE	262
#define	CATCH	263
#define	CHAR	264
#define	CLASS	265
#define	CONST	266
#define	CONTINUE	267
#define	DEBUGGER	268
#define	DEFAULT	269
#define	DELETE	270
#define	DO	271
#define	DOUBLE	272
#define	ELSE	273
#define	ENUM	274
#define	EXPORT	275
#define	EXTENDS	276
#define	FALSE	277
#define	FINAL	278
#define	FINALLY	279
#define	FLOAT	280
#define	FOR	281
#define	FUNCTION	282
#define	GOTO	283
#define	IF	284
#define	IMPLEMENTS	285
#define	IMPORT	286
#define	IN	287
#define	INSTANCEOF	288
#define	INT	289
#define	INTERFACE	290
#define	LONG	291
#define	NATIVE	292
#define	NEW	293
#define	NUL	294
#define	PACKAGE	295
#define	PRIVATE	296
#define	PROTECTED	297
#define	PUBLIC	298
#define	RETURN	299
#define	SHORT	300
#define	STATIC	301
#define	SUPER	302
#define	SWITCH	303
#define	SYNCHRONIZED	304
#define	THIS	305
#define	THROW	306
#define	THROWS	307
#define	TRANSIENT	308
#define	TRUE	309
#define	TRY	310
#define	TYPEOF	311
#define	VAR	312
#define	VOID	313
#define	VOLATILE	314
#define	WHILE	315
#define	WITH	316
#define	UNDEFINED	317
#define	NAN	318
#define	INFINITY	319
#define	DOT	320
#define	COMA	321
#define	COLON	322
#define	QMARK	323
#define	LBRACKET_ROUND	324
#define	RBRACKET_ROUND	325
#define	LBRACKET_SQUARE	326
#define	RBRACKET_SQUARE	327
#define	LBRACKET_CURLY	328
#define	RBRACKET_CURLY	329
#define	INT_NUM	330
#define	LITERAL_NUMBER	331
#define	OBJ_NAME	332
#define	CSTRING	333
#define	END_OP	334
#define	ENDLINE	335
#define	OP_ASSIGN	336
#define	OP_ASSIGN_ADD	337
#define	OP_ASSIGN_SUB	338
#define	OP_ASSIGN_MUL	339
#define	OP_ASSIGN_POW	340
#define	OP_ASSIGN_DIV	341
#define	OP_ASSIGN_MOD	342
#define	OP_ASSIGN_LSHIFT	343
#define	OP_ASSIGN_RSHIFT	344
#define	OP_ASSIGN_AND	345
#define	OP_ASSIGN_XOR	346
#define	OP_ASSIGN_OR	347
#define	OPL_NOT	348
#define	OPL_AND	349
#define	OPL_OR	350
#define	OPL_EQ	351
#define	OPL_NEQ	352
#define	OPL_L	353
#define	OPL_G	354
#define	OPL_GE	355
#define	OPL_LE	356
#define	OPB_NOT	357
#define	OPB_OR	358
#define	OPB_AND	359
#define	OPB_XOR	360
#define	OPB_LSHIFT	361
#define	OPB_RSHIFT	362
#define	OPA_MUL	363
#define	OPA_DIV	364
#define	OPA_MOD	365
#define	OPA_ADD	366
#define	OPA_SUB	367
#define	OPA_INC	368
#define	OPA_DEC	369
#define	OPA_POW	370
#define	NO_ELSE	371

#line 83 "parse.y"
	
	#include <malloc.h>
	#include "KurCommon.h"
	
	#ifdef _DEBUG
	#define dbg(str) std::cout << str << std::endl;
	#else
	#define dbg(str)
	#endif

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		146
#define	YYFLAG		-32768
#define	YYNTBASE	117

#define YYTRANSLATE(x) ((unsigned)(x) <= 371 ? yytranslate[x] : 137)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     7,    10,    14,    17,    21,    25,    30,    32,
    34,    37,    40,    43,    47,    49,    51,    59,    64,    70,
    76,    84,    89,    91,    95,    97,   101,   104,   107,   109,
   113,   115,   119,   123,   127,   128,   132,   134,   136,   138,
   140,   142,   144,   146,   148,   150,   152,   155,   160,   163,
   168,   171,   174,   178,   182,   186,   190,   194,   198,   202,
   206,   210,   214,   218,   222,   226,   230,   234,   238,   242,
   246,   252,   254,   256
};

static const short yyrhs[] = {   129,
    79,     0,   117,   129,    79,     0,   125,    79,     0,   117,
   125,    79,     0,   122,    79,     0,   117,   122,    79,     0,
    73,   117,    74,     0,   117,    73,   117,    74,     0,   121,
     0,   119,     0,   129,    79,     0,   125,    79,     0,   122,
    79,     0,    73,   117,    74,     0,   121,     0,   119,     0,
    48,    69,   129,    70,    73,   120,    74,     0,     7,   129,
    67,   117,     0,   120,     7,   129,    67,   117,     0,    29,
    69,   129,    70,   118,     0,    29,    69,   129,    70,   118,
    18,   118,     0,   124,    69,   123,    70,     0,   129,     0,
   123,    65,   129,     0,   134,     0,   124,    65,   134,     0,
    57,   126,     0,    57,   134,     0,   126,     0,   126,    66,
   134,     0,   127,     0,   126,    66,   127,     0,   134,    81,
   129,     0,   134,    81,   127,     0,     0,    69,   129,    70,
     0,   132,     0,   133,     0,   131,     0,   136,     0,   135,
     0,   134,     0,   128,     0,   130,     0,     5,     0,    12,
     0,   113,   134,     0,   113,    69,   134,    70,     0,   114,
   134,     0,   114,    69,   134,    70,     0,   134,   113,     0,
   134,   114,     0,   129,   108,   129,     0,   129,   109,   129,
     0,   129,   110,   129,     0,   129,   112,   129,     0,   129,
   111,   129,     0,   129,    94,   129,     0,   129,    95,   129,
     0,   129,    96,   129,     0,   129,    97,   129,     0,   129,
    98,   129,     0,   129,    99,   129,     0,   129,   100,   129,
     0,   129,   101,   129,     0,   129,   104,   129,     0,   129,
   103,   129,     0,   129,   105,   129,     0,   129,   106,   129,
     0,   129,   107,   129,     0,   129,    68,   129,    67,   129,
     0,    77,     0,    78,     0,    76,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   124,   127,   130,   132,   135,   137,   140,   141,   143,   145,
   147,   151,   154,   157,   159,   161,   163,   166,   168,   170,
   172,   177,   180,   182,   184,   186,   192,   194,   195,   197,
   199,   200,   202,   204,   210,   213,   221,   222,   223,   225,
   226,   227,   229,   231,   233,   235,   237,   240,   241,   242,
   247,   249,   252,   254,   255,   256,   257,   259,   260,   261,
   262,   263,   264,   265,   266,   268,   269,   270,   271,   272,
   274,   282,   283,   284
};

static const char * const yytname[] = {   "$","error","$undefined.","ABSTRACT",
"BOOLEAN","BREAK","BYTE","CASE","CATCH","CHAR","CLASS","CONST","CONTINUE","DEBUGGER",
"DEFAULT","DELETE","DO","DOUBLE","ELSE","ENUM","EXPORT","EXTENDS","FALSE","FINAL",
"FINALLY","FLOAT","FOR","FUNCTION","GOTO","IF","IMPLEMENTS","IMPORT","IN","INSTANCEOF",
"INT","INTERFACE","LONG","NATIVE","NEW","NUL","PACKAGE","PRIVATE","PROTECTED",
"PUBLIC","RETURN","SHORT","STATIC","SUPER","SWITCH","SYNCHRONIZED","THIS","THROW",
"THROWS","TRANSIENT","TRUE","TRY","TYPEOF","VAR","VOID","VOLATILE","WHILE","WITH",
"UNDEFINED","NAN","INFINITY","DOT","COMA","COLON","QMARK","LBRACKET_ROUND","RBRACKET_ROUND",
"LBRACKET_SQUARE","RBRACKET_SQUARE","LBRACKET_CURLY","RBRACKET_CURLY","INT_NUM",
"LITERAL_NUMBER","OBJ_NAME","CSTRING","END_OP","ENDLINE","OP_ASSIGN","OP_ASSIGN_ADD",
"OP_ASSIGN_SUB","OP_ASSIGN_MUL","OP_ASSIGN_POW","OP_ASSIGN_DIV","OP_ASSIGN_MOD",
"OP_ASSIGN_LSHIFT","OP_ASSIGN_RSHIFT","OP_ASSIGN_AND","OP_ASSIGN_XOR","OP_ASSIGN_OR",
"OPL_NOT","OPL_AND","OPL_OR","OPL_EQ","OPL_NEQ","OPL_L","OPL_G","OPL_GE","OPL_LE",
"OPB_NOT","OPB_OR","OPB_AND","OPB_XOR","OPB_LSHIFT","OPB_RSHIFT","OPA_MUL","OPA_DIV",
"OPA_MOD","OPA_ADD","OPA_SUB","OPA_INC","OPA_DEC","OPA_POW","NO_ELSE","block",
"single_block","switch_operator","case_expression","if_operator","obj_and_method",
"parameters","object","var_init","var","operation_assign","empty_expression",
"expression","useful_words","unary_expression","binary_expression","ternary_expression",
"literal_string","constant_string","literal_number",""
};
#endif

static const short yyr1[] = {     0,
   117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
   118,   118,   118,   118,   118,   118,   119,   120,   120,   121,
   121,   122,   123,   123,   124,   124,   125,   125,   125,   126,
   126,   126,   127,   127,   128,   129,   129,   129,   129,   129,
   129,   129,   129,   129,   130,   130,   131,   131,   131,   131,
   131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
   132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
   133,   134,   135,   136
};

static const short yyr2[] = {     0,
     2,     3,     2,     3,     2,     3,     3,     4,     1,     1,
     2,     2,     2,     3,     1,     1,     7,     4,     5,     5,
     7,     4,     1,     3,     1,     3,     2,     2,     1,     3,
     1,     3,     3,     3,     0,     3,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     2,     4,     2,     4,
     2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     5,     1,     1,     1
};

static const short yydefact[] = {    35,
    45,    46,     0,     0,     0,    35,    35,    74,    72,    73,
     0,     0,    35,    10,     9,     0,     0,     0,    29,    31,
    43,     0,    44,    39,    37,    38,    42,    41,    40,    35,
    35,    27,    28,     0,    42,    35,     0,    47,     0,    49,
    35,     0,     0,     0,     5,     0,    35,     3,     0,    35,
     1,    35,    35,    35,    35,    35,    35,    35,    35,    35,
    35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
    51,    52,     0,     0,    36,     7,     0,     0,    35,     6,
     4,     2,    26,     0,    23,    32,    30,     0,    58,    59,
    60,    61,    62,    63,    64,    65,    67,    66,    68,    69,
    70,    53,    54,    55,    57,    56,    34,    33,    42,    35,
     0,    48,    50,     8,    35,    22,    35,    35,    20,    16,
    15,     0,     0,     0,     0,    24,    71,    35,    35,    13,
    12,    11,    35,     0,    14,    21,     0,    35,    17,    35,
     0,    35,    35,    35,     0,     0
};

static const short yydefgoto[] = {    13,
   119,    14,   134,    15,    16,    84,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    35,    28,    29
};

static const short yypact[] = {   126,
-32768,-32768,   -53,   -50,   -43,    48,   126,-32768,-32768,-32768,
   -51,   -49,   115,-32768,-32768,   -41,   -44,   -28,   -14,-32768,
-32768,   357,-32768,-32768,-32768,-32768,   -59,-32768,-32768,    48,
    48,   -14,   -22,   379,   -69,   195,   -43,-32768,   -43,-32768,
   126,   -18,   -17,   402,-32768,   -43,    48,-32768,   -43,    48,
-32768,    48,    48,    48,    48,    48,    48,    48,    48,    48,
    48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
-32768,-32768,   424,   447,-32768,-32768,    -7,    -4,   226,-32768,
-32768,-32768,-32768,   -56,   492,-32768,   -22,   269,   528,   511,
   594,   594,   182,   182,   182,   182,   545,   579,   562,   -79,
   -79,-32768,-32768,-32768,   -52,   -52,-32768,   492,   -66,   148,
    -9,-32768,-32768,-32768,    48,-32768,    48,   126,    53,-32768,
-32768,    -3,    -2,   470,    65,   492,   309,   248,   148,-32768,
-32768,-32768,    48,    -5,-32768,-32768,   288,    48,-32768,   126,
   334,   173,   126,   201,    74,-32768
};

static const short yypgoto[] = {    -6,
   -54,  -106,-32768,  -102,     4,-32768,-32768,    29,    73,   -46,
-32768,    37,-32768,-32768,-32768,-32768,     0,-32768,-32768
};


#define	YYLAST		706


static const short yytable[] = {    27,
    36,   138,    86,   120,    33,   -25,    27,   121,   115,   -25,
    38,    40,    27,   116,    70,    30,    42,    37,    31,    39,
    46,    70,   120,   107,    47,     9,   121,     9,    65,    66,
    67,    68,    69,     9,    79,    27,    77,    45,    78,    42,
    27,    43,    34,    71,    72,    83,    71,    72,    87,    44,
    48,    49,     1,    71,    72,    65,    66,    67,    70,     2,
    80,    81,   112,   125,    43,   113,    73,    74,   139,   109,
   129,   133,    44,   146,   136,   130,   131,    32,    27,     0,
     0,     0,    42,    85,     0,     0,    88,     0,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   108,    43,     0,    27,
     0,   128,     0,   122,   145,    44,     6,    27,     0,     1,
     0,     0,     0,     8,     9,    10,     2,    27,    27,     0,
     1,    42,   122,   142,     0,     0,   144,     2,   123,    27,
     0,    27,    27,    27,     0,    42,   124,    42,     0,     0,
     0,   126,     1,   127,     3,     0,    43,   123,     0,     2,
    11,    12,     0,     0,    44,   124,     0,     0,     0,   137,
    43,     5,    43,     4,   141,     0,     3,     1,    44,   -18,
    44,     0,     5,     6,     2,     0,     0,    41,     0,     0,
     8,     9,    10,     0,     6,     4,     0,     0,     7,     1,
     0,     8,     9,    10,     5,     1,     2,   -19,     0,     0,
     0,     0,     2,     0,     0,     0,     6,     0,     0,     0,
   118,     0,     0,     8,     9,    10,     0,    11,    12,     5,
     1,     0,     0,     0,     0,     0,     0,     2,    11,    12,
     0,     6,     0,     0,     0,    41,   -18,     0,     8,     9,
    10,     5,     1,     0,     0,     0,     0,     5,     0,     2,
    11,    12,     0,     6,     0,     0,     0,    41,    76,     6,
     8,     9,    10,    41,   -19,     0,     8,     9,    10,     0,
     0,     0,     5,     0,     0,    11,    12,    63,    64,    65,
    66,    67,    68,    69,     6,     0,     0,     0,    41,   114,
     0,     8,     9,    10,     5,     0,     0,    11,    12,     0,
     0,     0,     0,    11,    12,     0,     6,     0,     0,     0,
    41,   135,     0,     8,     9,    10,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   117,    50,     0,    11,    12,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   140,    50,     0,     0,     0,     0,
    11,    12,    52,    53,    54,    55,    56,    57,    58,    59,
     0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    52,    53,    54,    55,    56,    57,    58,    59,     0,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
   143,    50,    52,    53,    54,    55,    56,    57,    58,    59,
     0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,     0,     0,     0,    50,     0,     0,    52,    53,    54,
    55,    56,    57,    58,    59,    51,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    50,     0,    75,     0,
    52,    53,    54,    55,    56,    57,    58,    59,     0,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    50,
     0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
    82,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    50,     0,   110,     0,    52,    53,    54,    55,    56,
    57,    58,    59,     0,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    50,     0,   111,    52,    53,    54,
    55,    56,    57,    58,    59,     0,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,     0,    50,     0,     0,
    52,    53,    54,    55,    56,    57,    58,    59,   132,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    50,
     0,     0,     0,    52,    53,    54,    55,    56,    57,    58,
    59,     0,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,     0,     0,     0,    52,    53,    54,    55,    56,
    57,    58,    59,     0,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    52,     0,    54,    55,    56,    57,
    58,    59,     0,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    54,    55,    56,    57,    58,    59,     0,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    54,    55,    56,    57,    58,    59,     0,     0,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    54,    55,    56,
    57,    58,    59,     0,     0,    61,     0,    63,    64,    65,
    66,    67,    68,    69,    54,    55,    56,    57,    58,    59,
     0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
    69,    56,    57,    58,    59,     0,     0,     0,     0,    63,
    64,    65,    66,    67,    68,    69
};

static const short yycheck[] = {     0,
     7,     7,    49,   110,     5,    65,     7,   110,    65,    69,
    11,    12,    13,    70,    81,    69,    13,    69,    69,    69,
    65,    81,   129,    70,    69,    77,   129,    77,   108,   109,
   110,   111,   112,    77,    41,    36,    37,    79,    39,    36,
    41,    13,     6,   113,   114,    46,   113,   114,    49,    13,
    79,    66,     5,   113,   114,   108,   109,   110,    81,    12,
    79,    79,    70,    73,    36,    70,    30,    31,    74,    70,
    18,     7,    36,     0,   129,    79,    79,     5,    79,    -1,
    -1,    -1,    79,    47,    -1,    -1,    50,    -1,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    79,    -1,   110,
    -1,   118,    -1,   110,     0,    79,    69,   118,    -1,     5,
    -1,    -1,    -1,    76,    77,    78,    12,   128,   129,    -1,
     5,   128,   129,   140,    -1,    -1,   143,    12,   110,   140,
    -1,   142,   143,   144,    -1,   142,   110,   144,    -1,    -1,
    -1,   115,     5,   117,    29,    -1,   128,   129,    -1,    12,
   113,   114,    -1,    -1,   128,   129,    -1,    -1,    -1,   133,
   142,    57,   144,    48,   138,    -1,    29,     5,   142,     7,
   144,    -1,    57,    69,    12,    -1,    -1,    73,    -1,    -1,
    76,    77,    78,    -1,    69,    48,    -1,    -1,    73,     5,
    -1,    76,    77,    78,    57,     5,    12,     7,    -1,    -1,
    -1,    -1,    12,    -1,    -1,    -1,    69,    -1,    -1,    -1,
    73,    -1,    -1,    76,    77,    78,    -1,   113,   114,    57,
     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,   113,   114,
    -1,    69,    -1,    -1,    -1,    73,    74,    -1,    76,    77,
    78,    57,     5,    -1,    -1,    -1,    -1,    57,    -1,    12,
   113,   114,    -1,    69,    -1,    -1,    -1,    73,    74,    69,
    76,    77,    78,    73,    74,    -1,    76,    77,    78,    -1,
    -1,    -1,    57,    -1,    -1,   113,   114,   106,   107,   108,
   109,   110,   111,   112,    69,    -1,    -1,    -1,    73,    74,
    -1,    76,    77,    78,    57,    -1,    -1,   113,   114,    -1,
    -1,    -1,    -1,   113,   114,    -1,    69,    -1,    -1,    -1,
    73,    74,    -1,    76,    77,    78,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,   113,   114,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
   113,   114,    94,    95,    96,    97,    98,    99,   100,   101,
    -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
    67,    68,    94,    95,    96,    97,    98,    99,   100,   101,
    -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,    -1,    -1,    -1,    68,    -1,    -1,    94,    95,    96,
    97,    98,    99,   100,   101,    79,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,    68,    -1,    70,    -1,
    94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,    68,
    -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
    79,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,    68,    -1,    70,    -1,    94,    95,    96,    97,    98,
    99,   100,   101,    -1,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,    68,    -1,    70,    94,    95,    96,
    97,    98,    99,   100,   101,    -1,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,    -1,    68,    -1,    -1,
    94,    95,    96,    97,    98,    99,   100,   101,    79,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,    68,
    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
   101,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,    -1,    -1,    -1,    94,    95,    96,    97,    98,
    99,   100,   101,    -1,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,    94,    -1,    96,    97,    98,    99,
   100,   101,    -1,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,    96,    97,    98,    99,   100,   101,    -1,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
    96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
   106,   107,   108,   109,   110,   111,   112,    96,    97,    98,
    99,   100,   101,    -1,    -1,   104,    -1,   106,   107,   108,
   109,   110,   111,   112,    96,    97,    98,    99,   100,   101,
    -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
   112,    98,    99,   100,   101,    -1,    -1,    -1,    -1,   106,
   107,   108,   109,   110,   111,   112
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */
   
#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 125 "parse.y"
{dbg("block: a + 0;");
    break;}
case 2:
#line 127 "parse.y"
{dbg("block: ... a + 0;");
    break;}
case 3:
#line 130 "parse.y"
{dbg("block: variable initialization;");
    break;}
case 4:
#line 132 "parse.y"
{dbg("block: ... ; variable initialization;");
    break;}
case 5:
#line 135 "parse.y"
{dbg("block: document.writeln('Hello World');");
    break;}
case 6:
#line 137 "parse.y"
{dbg("block: ... document.writeln('Hello World');");
    break;}
case 7:
#line 140 "parse.y"
{dbg("block: { block }");
    break;}
case 8:
#line 141 "parse.y"
{dbg("block: ... { block }");
    break;}
case 9:
#line 143 "parse.y"
{dbg("block: if ()");
    break;}
case 10:
#line 145 "parse.y"
{dbg("block: switch");
    break;}
case 11:
#line 148 "parse.y"
{dbg("block: a + 0;");
    break;}
case 12:
#line 151 "parse.y"
{dbg("block: variable initialization;");
    break;}
case 13:
#line 154 "parse.y"
{dbg("block: document.writeln('Hello World');");
    break;}
case 14:
#line 157 "parse.y"
{dbg("block: { block }");
    break;}
case 15:
#line 159 "parse.y"
{dbg("block: if ()");
    break;}
case 16:
#line 161 "parse.y"
{dbg("block: switch");
    break;}
case 18:
#line 167 "parse.y"
{dbg("case_expression: case 1: block");
    break;}
case 19:
#line 168 "parse.y"
{dbg("case_expression: ... case 1: block");
    break;}
case 20:
#line 171 "parse.y"
{dbg("if_operator: if (expression) block");
    break;}
case 21:
#line 172 "parse.y"
{dbg("if_operator: if (expression) single_stat_blck else single_stat_blck");
    break;}
case 22:
#line 178 "parse.y"
{dbg("obj_and_method: f(expr)");
    break;}
case 23:
#line 181 "parse.y"
{dbg("parameters: 1");
    break;}
case 24:
#line 182 "parse.y"
{dbg("parameters: ... , 1");
    break;}
case 25:
#line 185 "parse.y"
{dbg("object: a");
    break;}
case 26:
#line 186 "parse.y"
{dbg("object: ... .a");
    break;}
case 27:
#line 193 "parse.y"
{dbg("var_init: var a...; (local variable)");
    break;}
case 28:
#line 194 "parse.y"
{dbg("var_init: var a");
    break;}
case 29:
#line 195 "parse.y"
{dbg("var_init: a...; (global variable)");
    break;}
case 30:
#line 198 "parse.y"
{dbg("var: ...a");
    break;}
case 31:
#line 199 "parse.y"
{dbg("var_init: a = 0;");
    break;}
case 32:
#line 200 "parse.y"
{dbg("var_init: a = 0, ...");
    break;}
case 33:
#line 203 "parse.y"
{dbg("operation_assign: a = 0;");
    break;}
case 34:
#line 204 "parse.y"
{dbg("operation_assign: a = ...");
    break;}
case 35:
#line 211 "parse.y"
{dbg("empty_expression: ;");
    break;}
case 36:
#line 219 "parse.y"
{dbg("expression: (a+0)");
    break;}
case 37:
#line 221 "parse.y"
{dbg("expression: binary_expression");
    break;}
case 38:
#line 222 "parse.y"
{dbg("expression: ternary_expression");
    break;}
case 39:
#line 223 "parse.y"
{dbg("expression: unary_expression");
    break;}
case 40:
#line 225 "parse.y"
{dbg("expression: literal_number");
    break;}
case 41:
#line 226 "parse.y"
{dbg("expression: constant_string");
    break;}
case 42:
#line 227 "parse.y"
{dbg("expression: literal_string");
    break;}
case 43:
#line 229 "parse.y"
{dbg("expression: empty_expression");
    break;}
case 44:
#line 231 "parse.y"
{dbg("expression: useful_words");
    break;}
case 45:
#line 234 "parse.y"
{dbg("useful_words: break");
    break;}
case 46:
#line 235 "parse.y"
{dbg("useful_words: continue");
    break;}
case 47:
#line 239 "parse.y"
{dbg("unary_expression: ++ a");
    break;}
case 48:
#line 240 "parse.y"
{dbg("unary_expression: ++ (a)");
    break;}
case 49:
#line 241 "parse.y"
{dbg("unary_expression: -- a");
    break;}
case 50:
#line 242 "parse.y"
{dbg("unary_expression: -- (a)");
    break;}
case 51:
#line 247 "parse.y"
{dbg("unary_expression: a ++");
    break;}
case 52:
#line 249 "parse.y"
{dbg("unary_expression: a --");
    break;}
case 53:
#line 253 "parse.y"
{dbg("binary_expression: a * a");
    break;}
case 54:
#line 254 "parse.y"
{dbg("binary_expression: a / a");
    break;}
case 55:
#line 255 "parse.y"
{dbg("binary_expression: a % a");
    break;}
case 56:
#line 256 "parse.y"
{dbg("binary_expression: a - a");
    break;}
case 57:
#line 257 "parse.y"
{dbg("binary_expression: a + a");
    break;}
case 58:
#line 259 "parse.y"
{dbg("binary_expression: a && a");
    break;}
case 59:
#line 260 "parse.y"
{dbg("binary_expression: a || a");
    break;}
case 60:
#line 261 "parse.y"
{dbg("binary_expression: a == a, a === a");
    break;}
case 61:
#line 262 "parse.y"
{dbg("binary_expression: a != a, a !== a");
    break;}
case 62:
#line 263 "parse.y"
{dbg("binary_expression: a < a");
    break;}
case 63:
#line 264 "parse.y"
{dbg("binary_expression: a > a");
    break;}
case 64:
#line 265 "parse.y"
{dbg("binary_expression: a <= a");
    break;}
case 65:
#line 266 "parse.y"
{dbg("binary_expression: a >= a");
    break;}
case 66:
#line 268 "parse.y"
{dbg("binary_expression: a & a");
    break;}
case 67:
#line 269 "parse.y"
{dbg("binary_expression: a | a");
    break;}
case 68:
#line 270 "parse.y"
{dbg("binary_expression: a ^ a");
    break;}
case 69:
#line 271 "parse.y"
{dbg("binary_expression: a << a, a <<< a");
    break;}
case 70:
#line 272 "parse.y"
{dbg("binary_expression: a >> a, a >>> a");
    break;}
case 71:
#line 275 "parse.y"
{dbg("ternary_expression: (a > 0) ? 1 : 0");
    break;}
case 72:
#line 282 "parse.y"
{dbg("Literal string")	;
    break;}
case 73:
#line 283 "parse.y"
{dbg("Constant string");;
    break;}
case 74:
#line 284 "parse.y"
{dbg("Literal number")	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 288 "parse.y"


void yyYaccInit() {}
void yyYaccCleanup() {}