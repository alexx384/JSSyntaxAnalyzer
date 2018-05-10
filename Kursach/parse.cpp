
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



#define	YYFINAL		186
#define	YYFLAG		-32768
#define	YYNTBASE	117

#define YYTRANSLATE(x) ((unsigned)(x) <= 371 ? yytranslate[x] : 140)

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
     0,     3,     7,    10,    14,    17,    21,    25,    30,    33,
    37,    39,    42,    44,    47,    49,    52,    54,    57,    59,
    62,    70,    76,    86,    94,   102,   107,   113,   119,   127,
   130,   133,   136,   140,   143,   145,   147,   149,   151,   153,
   158,   160,   164,   166,   170,   173,   176,   178,   182,   184,
   188,   192,   196,   197,   201,   203,   205,   207,   209,   211,
   213,   215,   217,   219,   222,   227,   230,   235,   238,   241,
   245,   249,   253,   257,   261,   265,   269,   273,   277,   281,
   285,   289,   293,   297,   301,   305,   309,   313,   319,   321,
   323
};

static const short yyrhs[] = {   132,
    79,     0,   117,   132,    79,     0,   128,    79,     0,   117,
   128,    79,     0,   125,    79,     0,   117,   125,    79,     0,
    73,   117,    74,     0,   117,    73,   117,    74,     0,    73,
    74,     0,   117,    73,    74,     0,   123,     0,   117,   123,
     0,   121,     0,   117,   121,     0,   119,     0,   117,   119,
     0,   120,     0,   117,   120,     0,   118,     0,   117,   118,
     0,    16,   124,    60,    69,   132,    70,    79,     0,    60,
    69,   132,    70,   124,     0,    26,    69,   132,    79,   132,
    79,   132,    70,   124,     0,    26,    69,   137,    32,   127,
    70,   124,     0,    48,    69,   132,    70,    73,   122,    74,
     0,     7,   132,    67,   117,     0,   122,     7,   132,    67,
   117,     0,    29,    69,   132,    70,   124,     0,    29,    69,
   132,    70,   124,    18,   124,     0,   132,    79,     0,   128,
    79,     0,   125,    79,     0,    73,   117,    74,     0,    73,
    74,     0,   123,     0,   121,     0,   119,     0,   120,     0,
   118,     0,   127,    69,   126,    70,     0,   132,     0,   126,
    65,   132,     0,   137,     0,   127,    65,   137,     0,    57,
   129,     0,    57,   137,     0,   129,     0,   129,    66,   137,
     0,   130,     0,   129,    66,   130,     0,   137,    81,   132,
     0,   137,    81,   130,     0,     0,    69,   132,    70,     0,
   135,     0,   136,     0,   134,     0,   139,     0,   138,     0,
   137,     0,   131,     0,   133,     0,    39,     0,   113,   137,
     0,   113,    69,   137,    70,     0,   114,   137,     0,   114,
    69,   137,    70,     0,   137,   113,     0,   137,   114,     0,
   132,   108,   132,     0,   132,   109,   132,     0,   132,   110,
   132,     0,   132,   112,   132,     0,   132,   111,   132,     0,
   132,    94,   132,     0,   132,    95,   132,     0,   132,    96,
   132,     0,   132,    97,   132,     0,   132,    98,   132,     0,
   132,    99,   132,     0,   132,   100,   132,     0,   132,   101,
   132,     0,   132,   104,   132,     0,   132,   103,   132,     0,
   132,   105,   132,     0,   132,   106,   132,     0,   132,   107,
   132,     0,   132,    68,   132,    67,   132,     0,    77,     0,
    78,     0,    76,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   123,   125,   127,   128,   130,   131,   133,   134,   136,   137,
   139,   140,   142,   143,   145,   146,   148,   149,   151,   152,
   154,   157,   160,   162,   166,   169,   171,   177,   179,   182,
   185,   187,   189,   191,   193,   195,   197,   199,   201,   207,
   210,   212,   214,   216,   222,   224,   225,   227,   229,   230,
   232,   234,   240,   243,   253,   254,   255,   258,   259,   260,
   262,   264,   266,   270,   273,   274,   275,   280,   282,   285,
   287,   288,   289,   290,   292,   293,   294,   295,   296,   297,
   298,   299,   301,   302,   303,   304,   305,   307,   315,   316,
   317
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
"do_operator","while_operator","for_operator","switch_operator","case_expression",
"if_operator","single_block","obj_and_method","parameters","object","var_init",
"var","operation_assign","empty_expression","expression","useful_words","unary_expression",
"binary_expression","ternary_expression","literal_string","constant_string",
"literal_number",""
};
#endif

static const short yyr1[] = {     0,
   117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
   117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
   118,   119,   120,   120,   121,   122,   122,   123,   123,   124,
   124,   124,   124,   124,   124,   124,   124,   124,   124,   125,
   126,   126,   127,   127,   128,   128,   128,   129,   129,   129,
   130,   130,   131,   132,   132,   132,   132,   132,   132,   132,
   132,   132,   133,   134,   134,   134,   134,   134,   134,   135,
   135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
   135,   135,   135,   135,   135,   135,   135,   136,   137,   138,
   139
};

static const short yyr2[] = {     0,
     2,     3,     2,     3,     2,     3,     3,     4,     2,     3,
     1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
     7,     5,     9,     7,     7,     4,     5,     5,     7,     2,
     2,     2,     3,     2,     1,     1,     1,     1,     1,     4,
     1,     3,     1,     3,     2,     2,     1,     3,     1,     3,
     3,     3,     0,     3,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     2,     4,     2,     4,     2,     2,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     5,     1,     1,
     1
};

static const short yydefact[] = {    53,
    53,     0,     0,    63,     0,     0,     0,    53,    53,    91,
    89,    90,     0,     0,    53,    19,    15,    17,    13,    11,
     0,     0,     0,    47,    49,    61,     0,    62,    57,    55,
    56,    60,    59,    58,    53,    39,    37,    38,    36,    35,
     0,     0,     0,     0,    53,    53,    53,    45,    46,    53,
     0,    60,     9,    53,     0,    64,     0,    66,    53,    20,
    16,    18,    14,    12,     0,     0,     0,     5,     0,    53,
     3,     0,    53,     1,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    68,    69,    34,    53,     0,    32,    31,
    30,     0,    60,     0,     0,     0,    54,     7,     0,     0,
    10,    53,     6,     4,     2,    44,     0,    41,    50,    48,
     0,    75,    76,    77,    78,    79,    80,    81,    82,    84,
    83,    85,    86,    87,    70,    71,    72,    74,    73,    52,
    51,    60,    33,    53,    53,     0,    53,     0,    53,    65,
    67,     8,    53,    40,    53,     0,     0,     0,    43,    28,
     0,    22,    42,    88,     0,    53,    53,    53,    53,     0,
    21,     0,    24,    29,     0,    53,    25,    53,    53,     0,
    23,    53,    53,    53,     0,     0
};

static const short yydefgoto[] = {    15,
    16,    17,    18,    19,   170,    20,    41,    21,   117,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    52,
    33,    34
};

static const short yypact[] = {   657,
   663,   -62,   -45,-32768,   -42,   -55,   -25,    27,   465,-32768,
-32768,-32768,   -58,   -52,   365,-32768,-32768,-32768,-32768,-32768,
   -43,   -26,   -39,   -20,-32768,-32768,   750,-32768,-32768,-32768,
-32768,   -49,-32768,-32768,   471,-32768,-32768,-32768,-32768,-32768,
   -12,   -21,   -19,   773,    27,    27,    27,   -20,   -31,    27,
   795,   -80,-32768,   534,   -55,-32768,   -55,-32768,   561,-32768,
-32768,-32768,-32768,-32768,   -17,   -16,   818,-32768,   -55,    27,
-32768,   -55,    27,-32768,    27,    27,    27,    27,    27,    27,
    27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
    27,    27,    27,-32768,-32768,-32768,   567,   -18,-32768,-32768,
-32768,   841,   -29,   863,   886,   908,-32768,-32768,    13,    19,
-32768,   630,-32768,-32768,-32768,-32768,   -47,   999,-32768,   -31,
   651,  1054,  1037,   554,   554,   -33,   -33,   -33,   -33,   165,
   458,   362,    -2,    -2,-32768,-32768,-32768,   -28,   -28,-32768,
   999,   -76,-32768,    27,    27,   -55,   663,    -6,   663,-32768,
-32768,-32768,    27,-32768,    27,   931,   954,   -44,-32768,    35,
    61,-32768,   999,  1018,    -9,    27,   663,   663,    27,    -3,
-32768,   976,-32768,-32768,   697,    27,-32768,   663,   657,   716,
-32768,   379,   657,   438,    90,-32768
};

static const short yypgoto[] = {    -7,
    46,   100,   144,   147,-32768,   188,  -137,   191,-32768,   -54,
   233,    88,   -64,-32768,    41,-32768,-32768,-32768,-32768,     0,
-32768,-32768
};


#define	YYLAST		1166


static const short yytable[] = {    32,
    32,    54,   146,   176,    93,    49,    45,   119,    32,   160,
    55,   162,    56,    58,    32,   -43,    57,   153,    11,   -43,
    69,    11,   154,    46,    11,   167,    47,    97,   140,   173,
   174,    93,    94,    95,    32,    68,    94,    95,    69,    71,
   181,    44,    70,    50,   103,    72,    36,    98,    51,    93,
   144,   112,   168,    32,   109,    67,   110,    99,    32,   100,
    60,   113,   114,    94,    95,     4,   161,   169,   116,   171,
   177,   120,    86,    87,    88,    89,    90,    91,    92,    88,
    89,    90,   150,    94,    95,   102,   104,   105,   151,   186,
   106,   158,   142,    48,    67,     8,    32,     0,     0,    60,
    37,     0,    10,    11,    12,    88,    89,    90,    91,    92,
   118,    32,     0,   121,    61,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   141,     0,     0,     0,    67,     0,    13,
    14,     0,    60,     0,    38,   159,    32,    39,    32,     0,
     0,     0,    67,    61,     0,     0,     0,    60,    62,     0,
     0,    63,     0,     0,     0,     0,    32,    32,     0,     0,
     0,   182,     0,     0,     0,   184,     0,    32,    32,     0,
     0,    32,    32,    32,   156,   157,     0,    44,    40,    44,
     0,    42,    36,   163,    36,   164,    61,    62,     0,     0,
    63,     0,    64,     0,     0,    65,   172,    44,    44,   175,
     0,    61,    36,    36,     0,     0,   180,     0,    44,     0,
     0,     0,    67,    36,    67,     0,     0,    60,     0,    60,
     0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
    62,    64,     0,    63,    65,     0,    37,    66,    37,     0,
     0,     0,     0,     0,     0,    62,     0,     0,    63,     0,
    77,    78,    79,    80,    81,    82,    37,    37,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    37,     0,     0,
     0,    61,     0,    61,    64,     0,    66,    65,     0,     0,
    38,     0,    38,    39,     0,    39,     0,     0,     0,    64,
     0,     0,    65,     0,     0,     0,     0,     0,     0,     0,
    38,    38,     0,    39,    39,     0,     0,     0,     0,     0,
     0,    38,     0,     0,    39,    62,     0,    62,    63,    66,
    63,     0,     0,     0,    40,     0,    40,    42,     0,    42,
     0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    40,    40,     0,    42,    42,     0,
     0,     0,     0,     0,   185,    40,     0,     0,    42,    64,
     0,    64,    65,     0,    65,     0,     0,     0,     0,    43,
     1,    43,     0,     0,     0,   -26,     0,     0,     0,     0,
     2,     0,     0,     3,     1,     0,     0,     0,     0,    43,
    43,     0,     0,     4,     2,     0,     0,     3,     0,     0,
    43,     0,     5,     0,    66,     0,    66,     4,     0,     0,
     0,     6,     0,     0,     7,     0,     5,     0,     0,     0,
     0,     0,     0,     8,     0,     6,     0,    59,     7,     0,
    10,    11,    12,     0,   -27,     0,     0,     8,     0,     0,
     0,    59,   -26,     1,    10,    11,    12,    77,    78,    79,
    80,    81,    82,     2,     0,    84,     3,    86,    87,    88,
    89,    90,    91,    92,     0,     0,     4,    13,    14,     0,
     1,     0,     0,     0,     0,     5,     1,     0,     0,     0,
     2,    13,    14,     3,     6,     0,     2,     7,     0,     3,
     0,     0,     0,     4,     0,     0,     8,     0,     0,     4,
    59,   -27,     5,    10,    11,    12,     0,     0,     5,     0,
     0,     6,     0,     0,     7,     0,     0,     6,     0,     0,
     7,     0,     0,     8,     0,     0,     0,     9,    53,     8,
    10,    11,    12,     9,    96,     0,    10,    11,    12,     1,
    13,    14,     0,    77,    78,    79,    80,    81,    82,     2,
     0,     0,     3,    86,    87,    88,    89,    90,    91,    92,
     0,     0,     4,     0,     0,     0,     1,    13,    14,     0,
     0,     5,     1,    13,    14,     0,     2,     0,     0,     3,
     6,     0,     2,     7,     0,     3,     0,     0,     0,     4,
     0,     0,     8,     0,     0,     4,    59,   108,     5,    10,
    11,    12,     0,     0,     5,     0,     0,     6,     0,     0,
     7,     0,     0,     6,     0,     0,     7,     0,     0,     8,
     0,     0,     0,     9,   111,     8,    10,    11,    12,    59,
   143,     0,    10,    11,    12,     1,    13,    14,     0,     0,
     0,    79,    80,    81,    82,     2,     0,     0,     3,    86,
    87,    88,    89,    90,    91,    92,     0,     0,     4,     0,
     0,     0,     1,    13,    14,     0,     0,     5,     1,    13,
    14,     0,     2,     0,     0,     3,     6,     0,     2,     7,
     0,     3,     0,     0,     0,     4,     0,     0,     8,     0,
     0,     4,    59,   152,     5,    10,    11,    12,     0,     0,
     5,     0,     0,     6,     0,     0,     7,   155,    73,     6,
     0,     0,     7,     0,     0,     8,     0,     0,     0,     9,
     0,     8,    10,    11,    12,    35,     0,     0,    10,    11,
    12,     0,    13,    14,    75,    76,    77,    78,    79,    80,
    81,    82,     0,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,   179,    73,     0,     0,     0,     0,    13,
    14,     0,     0,     0,     0,    13,    14,     0,     0,     0,
     0,     0,   183,    73,     0,     0,     0,     0,     0,     0,
    75,    76,    77,    78,    79,    80,    81,    82,     0,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    75,
    76,    77,    78,    79,    80,    81,    82,    73,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    74,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    73,     0,     0,    75,    76,    77,    78,    79,    80,    81,
    82,   101,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    73,     0,   107,     0,    75,    76,    77,    78,
    79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    73,     0,     0,    75,    76,
    77,    78,    79,    80,    81,    82,   115,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,     0,    73,     0,
     0,    75,    76,    77,    78,    79,    80,    81,    82,   145,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    73,     0,   147,     0,    75,    76,    77,    78,    79,    80,
    81,    82,     0,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    73,     0,   148,    75,    76,    77,    78,
    79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    73,     0,   149,     0,    75,
    76,    77,    78,    79,    80,    81,    82,     0,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    73,     0,
   165,    75,    76,    77,    78,    79,    80,    81,    82,     0,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     0,    73,     0,     0,    75,    76,    77,    78,    79,    80,
    81,    82,   166,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    73,     0,   178,     0,    75,    76,    77,
    78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    73,     0,     0,    75,
    76,    77,    78,    79,    80,    81,    82,     0,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
     0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
     0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    75,    76,    77,    78,    79,    80,    81,    82,     0,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    75,     0,    77,    78,    79,    80,    81,    82,     0,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    77,
    78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92
};

static const short yycheck[] = {     0,
     1,     9,    32,     7,    81,     6,    69,    72,     9,   147,
    69,   149,    13,    14,    15,    65,    69,    65,    77,    69,
    65,    77,    70,    69,    77,    70,    69,    35,    93,   167,
   168,    81,   113,   114,    35,    79,   113,   114,    65,    79,
   178,     1,    69,    69,    45,    66,     1,    60,     8,    81,
    69,    59,    18,    54,    55,    15,    57,    79,    59,    79,
    15,    79,    79,   113,   114,    39,    73,     7,    69,    79,
    74,    72,   106,   107,   108,   109,   110,   111,   112,   108,
   109,   110,    70,   113,   114,    45,    46,    47,    70,     0,
    50,   146,    93,     6,    54,    69,    97,    -1,    -1,    54,
     1,    -1,    76,    77,    78,   108,   109,   110,   111,   112,
    70,   112,    -1,    73,    15,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    -1,    -1,    -1,    97,    -1,   113,
   114,    -1,    97,    -1,     1,   146,   147,     1,   149,    -1,
    -1,    -1,   112,    54,    -1,    -1,    -1,   112,    15,    -1,
    -1,    15,    -1,    -1,    -1,    -1,   167,   168,    -1,    -1,
    -1,   179,    -1,    -1,    -1,   183,    -1,   178,   179,    -1,
    -1,   182,   183,   184,   144,   145,    -1,   147,     1,   149,
    -1,     1,   147,   153,   149,   155,    97,    54,    -1,    -1,
    54,    -1,    15,    -1,    -1,    15,   166,   167,   168,   169,
    -1,   112,   167,   168,    -1,    -1,   176,    -1,   178,    -1,
    -1,    -1,   182,   178,   184,    -1,    -1,   182,    -1,   184,
    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
    97,    54,    -1,    97,    54,    -1,   147,    15,   149,    -1,
    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   112,    -1,
    96,    97,    98,    99,   100,   101,   167,   168,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   178,    -1,    -1,
    -1,   182,    -1,   184,    97,    -1,    54,    97,    -1,    -1,
   147,    -1,   149,   147,    -1,   149,    -1,    -1,    -1,   112,
    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   167,   168,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
    -1,   178,    -1,    -1,   178,   182,    -1,   184,   182,    97,
   184,    -1,    -1,    -1,   147,    -1,   149,   147,    -1,   149,
    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   167,   168,    -1,   167,   168,    -1,
    -1,    -1,    -1,    -1,     0,   178,    -1,    -1,   178,   182,
    -1,   184,   182,    -1,   184,    -1,    -1,    -1,    -1,   147,
    16,   149,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
    26,    -1,    -1,    29,    16,    -1,    -1,    -1,    -1,   167,
   168,    -1,    -1,    39,    26,    -1,    -1,    29,    -1,    -1,
   178,    -1,    48,    -1,   182,    -1,   184,    39,    -1,    -1,
    -1,    57,    -1,    -1,    60,    -1,    48,    -1,    -1,    -1,
    -1,    -1,    -1,    69,    -1,    57,    -1,    73,    60,    -1,
    76,    77,    78,    -1,     7,    -1,    -1,    69,    -1,    -1,
    -1,    73,    74,    16,    76,    77,    78,    96,    97,    98,
    99,   100,   101,    26,    -1,   104,    29,   106,   107,   108,
   109,   110,   111,   112,    -1,    -1,    39,   113,   114,    -1,
    16,    -1,    -1,    -1,    -1,    48,    16,    -1,    -1,    -1,
    26,   113,   114,    29,    57,    -1,    26,    60,    -1,    29,
    -1,    -1,    -1,    39,    -1,    -1,    69,    -1,    -1,    39,
    73,    74,    48,    76,    77,    78,    -1,    -1,    48,    -1,
    -1,    57,    -1,    -1,    60,    -1,    -1,    57,    -1,    -1,
    60,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    69,
    76,    77,    78,    73,    74,    -1,    76,    77,    78,    16,
   113,   114,    -1,    96,    97,    98,    99,   100,   101,    26,
    -1,    -1,    29,   106,   107,   108,   109,   110,   111,   112,
    -1,    -1,    39,    -1,    -1,    -1,    16,   113,   114,    -1,
    -1,    48,    16,   113,   114,    -1,    26,    -1,    -1,    29,
    57,    -1,    26,    60,    -1,    29,    -1,    -1,    -1,    39,
    -1,    -1,    69,    -1,    -1,    39,    73,    74,    48,    76,
    77,    78,    -1,    -1,    48,    -1,    -1,    57,    -1,    -1,
    60,    -1,    -1,    57,    -1,    -1,    60,    -1,    -1,    69,
    -1,    -1,    -1,    73,    74,    69,    76,    77,    78,    73,
    74,    -1,    76,    77,    78,    16,   113,   114,    -1,    -1,
    -1,    98,    99,   100,   101,    26,    -1,    -1,    29,   106,
   107,   108,   109,   110,   111,   112,    -1,    -1,    39,    -1,
    -1,    -1,    16,   113,   114,    -1,    -1,    48,    16,   113,
   114,    -1,    26,    -1,    -1,    29,    57,    -1,    26,    60,
    -1,    29,    -1,    -1,    -1,    39,    -1,    -1,    69,    -1,
    -1,    39,    73,    74,    48,    76,    77,    78,    -1,    -1,
    48,    -1,    -1,    57,    -1,    -1,    60,    67,    68,    57,
    -1,    -1,    60,    -1,    -1,    69,    -1,    -1,    -1,    73,
    -1,    69,    76,    77,    78,    73,    -1,    -1,    76,    77,
    78,    -1,   113,   114,    94,    95,    96,    97,    98,    99,
   100,   101,    -1,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,    67,    68,    -1,    -1,    -1,    -1,   113,
   114,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,    -1,
    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
    94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,    94,
    95,    96,    97,    98,    99,   100,   101,    68,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,    79,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    68,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
   101,    79,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,    68,    -1,    70,    -1,    94,    95,    96,    97,
    98,    99,   100,   101,    -1,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,    68,    -1,    -1,    94,    95,
    96,    97,    98,    99,   100,   101,    79,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,    -1,    68,    -1,
    -1,    94,    95,    96,    97,    98,    99,   100,   101,    79,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
    68,    -1,    70,    -1,    94,    95,    96,    97,    98,    99,
   100,   101,    -1,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,    68,    -1,    70,    94,    95,    96,    97,
    98,    99,   100,   101,    -1,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,    68,    -1,    70,    -1,    94,
    95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,    68,    -1,
    70,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
    -1,    68,    -1,    -1,    94,    95,    96,    97,    98,    99,
   100,   101,    79,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,    68,    -1,    70,    -1,    94,    95,    96,
    97,    98,    99,   100,   101,    -1,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,    68,    -1,    -1,    94,
    95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
    -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
    -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
    94,    -1,    96,    97,    98,    99,   100,   101,    -1,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,    96,
    97,    98,    99,   100,   101,    -1,   103,   104,   105,   106,
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
#line 124 "parse.y"
{dbg("block: a + 0;");
    break;}
case 2:
#line 125 "parse.y"
{dbg("block: ... a + 0;");
    break;}
case 3:
#line 127 "parse.y"
{dbg("block: variable initialization;");
    break;}
case 4:
#line 128 "parse.y"
{dbg("block: ... ; variable initialization;");
    break;}
case 5:
#line 130 "parse.y"
{dbg("block: document.writeln('Hello World');");
    break;}
case 6:
#line 131 "parse.y"
{dbg("block: ... document.writeln('Hello World');");
    break;}
case 7:
#line 133 "parse.y"
{dbg("block: { block }");
    break;}
case 8:
#line 134 "parse.y"
{dbg("block: ... { block }");
    break;}
case 9:
#line 136 "parse.y"
{dbg("block: { }");
    break;}
case 10:
#line 137 "parse.y"
{dbg("block: { }");
    break;}
case 11:
#line 139 "parse.y"
{dbg("block: if ()");
    break;}
case 12:
#line 140 "parse.y"
{dbg("block: ... if ()");
    break;}
case 13:
#line 142 "parse.y"
{dbg("block: switch");
    break;}
case 14:
#line 143 "parse.y"
{dbg("block: ... switch");
    break;}
case 15:
#line 145 "parse.y"
{dbg("block: while");
    break;}
case 16:
#line 146 "parse.y"
{dbg("block: ... while");
    break;}
case 17:
#line 148 "parse.y"
{dbg("block: for");
    break;}
case 18:
#line 149 "parse.y"
{dbg("block: ... for");
    break;}
case 19:
#line 151 "parse.y"
{dbg("block: do ... while();");
    break;}
case 20:
#line 152 "parse.y"
{dbg("block: ... do ... while();");
    break;}
case 21:
#line 155 "parse.y"
{dbg("do_operator: do ... while(expression);");
    break;}
case 22:
#line 158 "parse.y"
{dbg("while_operator: while (expression) block");
    break;}
case 23:
#line 161 "parse.y"
{dbg("for_operator: for(i=0; i < 4; i++) block");
    break;}
case 24:
#line 162 "parse.y"
{dbg("for(i in obj) block");
    break;}
case 26:
#line 170 "parse.y"
{dbg("case_expression: case 1: block");
    break;}
case 27:
#line 171 "parse.y"
{dbg("case_expression: ... case 1: block");
    break;}
case 28:
#line 178 "parse.y"
{dbg("if_operator: if (expression) block");
    break;}
case 29:
#line 179 "parse.y"
{dbg("if_operator: if (expression) single_stat_blck else single_stat_blck");
    break;}
case 30:
#line 183 "parse.y"
{dbg("single_block: a + 0;");
    break;}
case 31:
#line 185 "parse.y"
{dbg("single_block: variable initialization;");
    break;}
case 32:
#line 187 "parse.y"
{dbg("single_block: document.writeln('Hello World');");
    break;}
case 33:
#line 189 "parse.y"
{dbg("single_block: { block }");
    break;}
case 34:
#line 191 "parse.y"
{dbg("single_block: { }");
    break;}
case 35:
#line 193 "parse.y"
{dbg("single_block: if ()");
    break;}
case 36:
#line 195 "parse.y"
{dbg("single_block: switch");
    break;}
case 37:
#line 197 "parse.y"
{dbg("single_block: while");
    break;}
case 38:
#line 199 "parse.y"
{dbg("single_block: for");
    break;}
case 39:
#line 201 "parse.y"
{dbg("single_block: do ... while();");
    break;}
case 40:
#line 208 "parse.y"
{dbg("obj_and_method: f(expr)");
    break;}
case 41:
#line 211 "parse.y"
{dbg("parameters: 1");
    break;}
case 42:
#line 212 "parse.y"
{dbg("parameters: ... , 1");
    break;}
case 43:
#line 215 "parse.y"
{dbg("object: a");
    break;}
case 44:
#line 216 "parse.y"
{dbg("object: ... .a");
    break;}
case 45:
#line 223 "parse.y"
{dbg("var_init: var a...; (local variable)");
    break;}
case 46:
#line 224 "parse.y"
{dbg("var_init: var a");
    break;}
case 47:
#line 225 "parse.y"
{dbg("var_init: a...; (global variable)");
    break;}
case 48:
#line 228 "parse.y"
{dbg("var: ...a");
    break;}
case 49:
#line 229 "parse.y"
{dbg("var_init: a = 0;");
    break;}
case 50:
#line 230 "parse.y"
{dbg("var_init: a = 0, ...");
    break;}
case 51:
#line 233 "parse.y"
{dbg("operation_assign: a = 0;");
    break;}
case 52:
#line 234 "parse.y"
{dbg("operation_assign: a = ...");
    break;}
case 53:
#line 241 "parse.y"
{dbg("empty_expression: ;");
    break;}
case 54:
#line 249 "parse.y"
{dbg("expression: (a+0)");
    break;}
case 55:
#line 253 "parse.y"
{dbg("expression: binary_expression");
    break;}
case 56:
#line 254 "parse.y"
{dbg("expression: ternary_expression");
    break;}
case 57:
#line 255 "parse.y"
{dbg("expression: unary_expression");
    break;}
case 58:
#line 258 "parse.y"
{dbg("expression: literal_number");
    break;}
case 59:
#line 259 "parse.y"
{dbg("expression: constant_string");
    break;}
case 60:
#line 260 "parse.y"
{dbg("expression: literal_string");
    break;}
case 61:
#line 262 "parse.y"
{dbg("expression: empty_expression");
    break;}
case 62:
#line 264 "parse.y"
{dbg("expression: useful_words");
    break;}
case 63:
#line 267 "parse.y"
{dbg("useful_words: null");
    break;}
case 64:
#line 272 "parse.y"
{dbg("unary_expression: ++ a");
    break;}
case 65:
#line 273 "parse.y"
{dbg("unary_expression: ++ (a)");
    break;}
case 66:
#line 274 "parse.y"
{dbg("unary_expression: -- a");
    break;}
case 67:
#line 275 "parse.y"
{dbg("unary_expression: -- (a)");
    break;}
case 68:
#line 280 "parse.y"
{dbg("unary_expression: a ++");
    break;}
case 69:
#line 282 "parse.y"
{dbg("unary_expression: a --");
    break;}
case 70:
#line 286 "parse.y"
{dbg("binary_expression: a * a");
    break;}
case 71:
#line 287 "parse.y"
{dbg("binary_expression: a / a");
    break;}
case 72:
#line 288 "parse.y"
{dbg("binary_expression: a % a");
    break;}
case 73:
#line 289 "parse.y"
{dbg("binary_expression: a - a");
    break;}
case 74:
#line 290 "parse.y"
{dbg("binary_expression: a + a");
    break;}
case 75:
#line 292 "parse.y"
{dbg("binary_expression: a && a");
    break;}
case 76:
#line 293 "parse.y"
{dbg("binary_expression: a || a");
    break;}
case 77:
#line 294 "parse.y"
{dbg("binary_expression: a == a, a === a");
    break;}
case 78:
#line 295 "parse.y"
{dbg("binary_expression: a != a, a !== a");
    break;}
case 79:
#line 296 "parse.y"
{dbg("binary_expression: a < a");
    break;}
case 80:
#line 297 "parse.y"
{dbg("binary_expression: a > a");
    break;}
case 81:
#line 298 "parse.y"
{dbg("binary_expression: a <= a");
    break;}
case 82:
#line 299 "parse.y"
{dbg("binary_expression: a >= a");
    break;}
case 83:
#line 301 "parse.y"
{dbg("binary_expression: a & a");
    break;}
case 84:
#line 302 "parse.y"
{dbg("binary_expression: a | a");
    break;}
case 85:
#line 303 "parse.y"
{dbg("binary_expression: a ^ a");
    break;}
case 86:
#line 304 "parse.y"
{dbg("binary_expression: a << a, a <<< a");
    break;}
case 87:
#line 305 "parse.y"
{dbg("binary_expression: a >> a, a >>> a");
    break;}
case 88:
#line 308 "parse.y"
{dbg("ternary_expression: (a > 0) ? 1 : 0");
    break;}
case 89:
#line 315 "parse.y"
{dbg("Literal string")	;
    break;}
case 90:
#line 316 "parse.y"
{dbg("Constant string");;
    break;}
case 91:
#line 317 "parse.y"
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
#line 321 "parse.y"


void yyYaccInit() {}
void yyYaccCleanup() {}