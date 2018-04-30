%{
	//Defines and includes
	#include "parse.cpp.h"
	#include "KurCommon.h"
	#include <io.h>

	#include <malloc.h>
	#include <stdarg.h>

	#define YY_NO_UNISTD_H
%}

%option noyywrap
%option outfile="lexic.cpp"

%x long_comment
%x const_string1
%x const_string2


digit 			[0-9]
hexdigit		[0-9a-fA-F]
mantissa 		({digit}+(\.{digit}*)?)|(\.{digit}+)
letter [a-zA-Z]


%{
	//yytext : a character array that contains the actual string that matched a pattern.
	//yyleng : the no. of characters matched.
	
	//YYSTAT g_yystat;
	
	// update global position
	#define UPD 	//g_yystat.yyglobalpos += yyleng; g_yystat.yylinepos += yyleng
	
	// update position after new line
	#define UPDNL 	//g_yystat.yyline++; g_yystat.yylinepos = 0; g_yystat.yystartpos = g_yystat.yyglobalpos
	
%}

%%

{mantissa}([eE][+-]?{digit}+)? /* Float number */ {
UPD;

return LITERAL_NUMBER;
}




"'"	 /* Const string */	{ UPD; BEGIN(const_string1); }
"\"" /* Const string */	{ UPD; BEGIN(const_string2); }

<const_string1>
{
	"'"			{ UPD; BEGIN(0); return CSTRING; 							}
	"\\'"		{ UPD; /* escape character*/								}
	\n			{ UPDNL; yyerror("Next line but no end ' symbol found\n"); 	}
	<<EOF>>		{ yyerror("EOF but no end ' symbol found\n"); 				}
	.			{ UPD; /*ignore*/ 											}
}

<const_string2>
{
	"\""		{ UPD; BEGIN(0); return CSTRING;							}
	"\\\""		{ UPD; /* escape character*/								}
	\n			{ UPDNL; yyerror("Next line but no end \" symbol found\n");	}
	<<EOF>>		{ yyerror("EOF but no end \" symbol found\n");				}
	.			{ UPD; /*ignore*/ 											}
}



"//".*\n? /* Comments: single line comment */ {
UPDNL;  
/* ignore */
}	

"/*" /* Comments: multiple line comment */ { UPD; BEGIN(long_comment); }

<long_comment>
{
	"*/"		{ UPD; BEGIN(0); 								}
	\n			{ UPDNL; 										}
	<<EOF>>		{ yyerror("EOF but no end */ symbol found\n");	}
	.			{ UPD; /*ignore*/ 								}
}




"abstract"	    /* JZ reserved word */ 	{ UPD; return ABSTRACT; 	}
"boolean"       /* JZ reserved word */	{ UPD; return BOOLEAN; 		}
"break"         /* JZ reserved word */  { UPD; return BREAK; 		}
"byte"          /* JZ reserved word */  { UPD; return BYTE; 		}
"case"          /* JZ reserved word */  { UPD; return CASE; 		}
"catch"         /* JZ reserved word */  { UPD; return CATCH; 		}
"char"          /* JZ reserved word */  { UPD; return CHAR; 		}
"class"         /* JZ reserved word */  { UPD; return CLASS; 		}
"const"         /* JZ reserved word */  { UPD; return CONST; 		}
"continue"      /* JZ reserved word */  { UPD; return CONTINUE; 	}
"debugger"      /* JZ reserved word */  { UPD; return DEBUGGER; 	}
"default"       /* JZ reserved word */  { UPD; return DEFAULT; 		}
"delete"        /* JZ reserved word */  { UPD; return DELETE; 		}
"do"            /* JZ reserved word */  { UPD; return DO; 			}
"double"        /* JZ reserved word */  { UPD; return DOUBLE; 		}
"else"          /* JZ reserved word */  { UPD; return ELSE; 		}	
"enum"          /* JZ reserved word */  { UPD; return ENUM; 		}
"export"        /* JZ reserved word */  { UPD; return EXPORT; 		}
"extends"       /* JZ reserved word */  { UPD; return EXTENDS; 		}
"false"         /* JZ reserved word */  { UPD; return FALSE; 		}
"final"         /* JZ reserved word */  { UPD; return FINAL; 		}
"finally"       /* JZ reserved word */  { UPD; return FINALLY; 		}
"float"         /* JZ reserved word */  { UPD; return FLOAT; 		}
"for"           /* JZ reserved word */  { UPD; return FOR; 			}
"function"      /* JZ reserved word */  { UPD; return FUNCTION; 	}
"goto"          /* JZ reserved word */  { UPD; return GOTO; 		}
"if"            /* JZ reserved word */  { UPD; return IF; 			}
"implements"    /* JZ reserved word */  { UPD; return IMPLEMENTS; 	}
"import"        /* JZ reserved word */  { UPD; return IMPORT; 		}
"in"            /* JZ reserved word */  { UPD; return IN; 			}
"instanceof"    /* JZ reserved word */  { UPD; return INSTANCEOF; 	}
"int"           /* JZ reserved word */  { UPD; return INT; 			}
"interface"     /* JZ reserved word */  { UPD; return INTERFACE; 	}
"long"          /* JZ reserved word */  { UPD; return LONG; 		}
"native"        /* JZ reserved word */  { UPD; return NATIVE; 		}
"new"           /* JZ reserved word */  { UPD; return NEW; 			}
"null"          /* JZ reserved word */  { UPD; return NUL; 			}	
"package"       /* JZ reserved word */  { UPD; return PACKAGE; 		}
"private"       /* JZ reserved word */  { UPD; return PRIVATE; 		}
"protected"     /* JZ reserved word */  { UPD; return PROTECTED; 	}
"public"        /* JZ reserved word */  { UPD; return PUBLIC; 		}
"return"        /* JZ reserved word */  { UPD; return RETURN; 		}
"short"         /* JZ reserved word */  { UPD; return SHORT; 		}	
"static"        /* JZ reserved word */  { UPD; return STATIC; 		}
"super"         /* JZ reserved word */  { UPD; return SUPER; 		}
"switch"		/* JZ reserved word */  { UPD; return SWITCH; 		}
"synchronized"	/* JZ reserved word */  { UPD; return SYNCHRONIZED; }
"this"			/* JZ reserved word */  { UPD; return THIS; 		}
"throw"         /* JZ reserved word */  { UPD; return THROW; 		}
"throws"        /* JZ reserved word */  { UPD; return THROWS; 		}
"transient"     /* JZ reserved word */  { UPD; return TRANSIENT;	}
"true"          /* JZ reserved word */  { UPD; return TRUE; 		}
"try"           /* JZ reserved word */  { UPD; return TRY; 			}
"typeof"        /* JZ reserved word */  { UPD; return TYPEOF; 		}
"var"           /* JZ reserved word */  { UPD; return VAR; 			}
"void"          /* JZ reserved word */  { UPD; return VOID; 		}
"volatile"      /* JZ reserved word */  { UPD; return VOLATILE; 	}
"while"         /* JZ reserved word */  { UPD; return WHILE; 		}
"with"          /* JZ reserved word */  { UPD; return WITH; 		}




[_$a-zA-Z]+[_$_$a-zA-Z0-9]* /* Variable/function name */ {
UPD;
	
	return LITERAL_STRING;
}



"==" | "===" { UPD; return OPL_EQ; 	}
"!=" | "!==" { UPD; return OPL_NEQ; }
"!"  { UPD; return OPL_NOT; }
"&&" { UPD; return OPL_AND; }
"||" { UPD; return OPL_OR; 	}
"<"  { UPD; return OPL_L; 	}
">"  { UPD; return OPL_G; 	}
"<=" { UPD; return OPL_LE; 	}
">=" { UPD; return OPL_GE; 	}

">>=" | ">>>="  { UPD; return OP_ASSIGN_LSHIFT; }
"<<=" | "<<<="  { UPD; return OP_ASSIGN_RSHIFT; }
"+="  { UPD; return OP_ASSIGN_ADD; }
"-="  { UPD; return OP_ASSIGN_SUB; }
"**=" { UPD; return OP_ASSIGN_POW; }
"*="  { UPD; return OP_ASSIGN_MUL; }
"/="  { UPD; return OP_ASSIGN_DIV; }
"%="  { UPD; return OP_ASSIGN_MOD; }
"&="  { UPD; return OP_ASSIGN_AND; }
"|="  { UPD; return OP_ASSIGN_OR; }
"^="  { UPD; return OP_ASSIGN_XOR; }
"="   { UPD; return OP_ASSIGN; }

"~"  { UPD; return OPB_NOT; }
"|"  { UPD; return OPB_OR;  }
"&"  { UPD; return OPB_AND; }
"^"  { UPD; return OPB_XOR; }
"<<"|"<<<"  { UPD; return OPB_LSHIFT; }
">>"|">>>"  { UPD; return OPB_RSHIFT; }

"++" { UPD; return OPA_INC; }
"--" { UPD; return OPA_DEC; }
"*"  { UPD; return OPA_MUL; }
"/"  { UPD; return OPA_DIV; }
"%"  { UPD; return OPA_MOD; }
"+"  { UPD; return OPA_ADD; }
"-"  { UPD; return OPA_SUB; }

"." { UPD; return DOT; }
"," { UPD; return COMA; }
":" { UPD; return COLON; }
"?" { UPD; return QMARK; }
"(" { UPD; return LBRACKET_ROUND; }
")" { UPD; return RBRACKET_ROUND; }
"[" { UPD; return LBRACKET_SQUARE;}
"]" { UPD; return RBRACKET_SQUARE;}
"{" { UPD; return LBRACKET_CURLY; }
"}" { UPD; return RBRACKET_CURLY; }


[\t ] /* Spaces: tab and space */ {
UPD;	
}

";" /* Spaces: operation splitter */ {
	//g_yystat.yystartpos = g_yystat.yyglobalpos;
}

"\n" /* Spaces: newline */ {
UPDNL;
}

. 	/* Lex error */  {
	
	yyerror("Unexpected symbol '%c'\n", yytext[0]);
}

%%

//void yyLexInit() 
//{	
//	g_yystat.yyline = 1;
//	g_yystat.yylinepos = 0;
//	g_yystat.yyglobalpos = 0;
//	g_yystat.yystartpos = 0;
//}


void yyerror(const char* format, ...)
{
	// retrieve the variable arguments and print
	va_list args;  
    va_start( args, format );  
	vprintf(format, args);
	
	if (!strcmp(format, "parse error"))
		printf("\n");
	
	//printf("Position: [line %u: %u]\n", g_yystat.yyline, g_yystat.yylinepos);
	//printf("Text: '%s'\n", yytext);
	
	//yyin.close();
	//yyLexCleanup();
	//yyYaccCleanup();
	
	//WAIT_USER;
	//exit(1);
}

//void yyLexCleanup() {}
