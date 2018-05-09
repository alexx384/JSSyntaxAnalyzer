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
unch			[\n ]*
letter [a-zA-Z]


%{
	//yytext : a character array that contains the actual string that matched a pattern.
	//yyleng : the no. of characters matched.
	
	YYSTATPOS g_yypos;
	
	// update global position
	#define UP 		g_yypos.incLinePos(yyleng);
	
	// update position after new line
	#define UPNL 	g_yypos.nextLine();
	
%}

%%

digit /* integer number */ {
	UP	return INT_NUM;
}

{mantissa}([eE][+-]?{digit}+)? /* Float number */ {
UP

return LITERAL_NUMBER;
}




"'"	 /* Const string */	{ UP BEGIN(const_string1); }
"\"" /* Const string */	{ UP BEGIN(const_string2); }

<const_string1>
{
	"'"			{ UP BEGIN(0); return CSTRING; 							}
	"\\'"		{ UP /* escape character*/								}
	\n			{ UPNL; yyerror("Next line but no end ' symbol found\n"); 	}
	<<EOF>>		{ yyerror("EOF but no end ' symbol found\n"); 				}
	.			{ UP /*ignore*/ 											}
}

<const_string2>
{
	"\""		{ UP BEGIN(0); return CSTRING;							}
	"\\\""		{ UP /* escape character*/								}
	\n			{ UPNL; yyerror("Next line but no end \" symbol found\n");	}
	<<EOF>>		{ yyerror("EOF but no end \" symbol found\n");				}
	.			{ UP /*ignore*/ 											}
}



"//".*\n? /* Comments: single line comment */ {
UPNL;  
/* ignore */
}	

"/*" /* Comments: multiple line comment */ { UP BEGIN(long_comment); }

<long_comment>
{
	"*/"		{ UP BEGIN(0); 								}
	\n			{ UPNL; 										}
	<<EOF>>		{ yyerror("EOF but no end */ symbol found\n");	}
	.			{ UP /*ignore*/ 								}
}


"abstract"	    /* JZ reserved word */ 	{ UP return ABSTRACT; 	}
"boolean"       /* JZ reserved word */	{ UP return BOOLEAN; 		}
"break"         /* JZ reserved word */  { UP return BREAK; 		}
"byte"          /* JZ reserved word */  { UP return BYTE; 		}
"case"          /* JZ reserved word */  { UP return CASE; 		}
"catch"         /* JZ reserved word */  { UP return CATCH; 		}
"char"          /* JZ reserved word */  { UP return CHAR; 		}
"class"         /* JZ reserved word */  { UP return CLASS; 		}
"const"         /* JZ reserved word */  { UP return CONST; 		}
"continue"      /* JZ reserved word */  { UP return CONTINUE; 	}
"debugger"      /* JZ reserved word */  { UP return DEBUGGER; 	}
"default"       /* JZ reserved word */  { UP return DEFAULT; 		}
"delete"        /* JZ reserved word */  { UP return DELETE; 		}
"do"            /* JZ reserved word */  { UP return DO; 			}
"double"        /* JZ reserved word */  { UP return DOUBLE; 		}
"else"          /* JZ reserved word */  { UP return ELSE; 		}	
"enum"          /* JZ reserved word */  { UP return ENUM; 		}
"export"        /* JZ reserved word */  { UP return EXPORT; 		}
"extends"       /* JZ reserved word */  { UP return EXTENDS; 		}
"false"         /* JZ reserved word */  { UP return FALSE; 		}
"final"         /* JZ reserved word */  { UP return FINAL; 		}
"finally"       /* JZ reserved word */  { UP return FINALLY; 		}
"float"         /* JZ reserved word */  { UP return FLOAT; 		}
"for"           /* JZ reserved word */  { UP return FOR; 			}
"function"      /* JZ reserved word */  { UP return FUNCTION; 	}
"goto"          /* JZ reserved word */  { UP return GOTO; 		}
"if"            /* JZ reserved word */  { UP return IF; 			}
"implements"    /* JZ reserved word */  { UP return IMPLEMENTS; 	}
"import"        /* JZ reserved word */  { UP return IMPORT; 		}
"in"            /* JZ reserved word */  { UP return IN; 			}
"instanceof"    /* JZ reserved word */  { UP return INSTANCEOF; 	}
"int"           /* JZ reserved word */  { UP return INT; 			}
"interface"     /* JZ reserved word */  { UP return INTERFACE; 	}
"long"          /* JZ reserved word */  { UP return LONG; 		}
"native"        /* JZ reserved word */  { UP return NATIVE; 		}
"new"           /* JZ reserved word */  { UP return NEW; 			}
"null"          /* JZ reserved word */  { UP return NUL; 			}	
"package"       /* JZ reserved word */  { UP return PACKAGE; 		}
"private"       /* JZ reserved word */  { UP return PRIVATE; 		}
"protected"     /* JZ reserved word */  { UP return PROTECTED; 	}
"public"        /* JZ reserved word */  { UP return PUBLIC; 		}
"return"        /* JZ reserved word */  { UP return RETURN; 		}
"short"         /* JZ reserved word */  { UP return SHORT; 		}	
"static"        /* JZ reserved word */  { UP return STATIC; 		}
"super"         /* JZ reserved word */  { UP return SUPER; 		}
"switch"		/* JZ reserved word */  { UP return SWITCH; 		}
"synchronized"	/* JZ reserved word */  { UP return SYNCHRONIZED; }
"this"			/* JZ reserved word */  { UP return THIS; 		}
"throw"         /* JZ reserved word */  { UP return THROW; 		}
"throws"        /* JZ reserved word */  { UP return THROWS; 		}
"transient"     /* JZ reserved word */  { UP return TRANSIENT;	}
"true"          /* JZ reserved word */  { UP return TRUE; 		}
"try"           /* JZ reserved word */  { UP return TRY; 			}
"typeof"        /* JZ reserved word */  { UP return TYPEOF; 		}
"var"           /* JZ reserved word */  { UP return VAR; 			}
"void"          /* JZ reserved word */  { UP return VOID; 		}
"volatile"      /* JZ reserved word */  { UP return VOLATILE; 	}
"while"         /* JZ reserved word */  { UP return WHILE; 		}
"with"          /* JZ reserved word */  { UP return WITH; 		}




[_$a-zA-Z]+[_$a-zA-Z0-9]* /* Variable/function name */ {
UP	return OBJ_NAME;
}



"==" | "===" { UP return OPL_EQ; 	}
"!=" | "!==" { UP return OPL_NEQ; }
"!"  { UP return OPL_NOT; }
"&&" { UP return OPL_AND; }
"||" { UP return OPL_OR; 	}
"<"  { UP return OPL_L; 	}
">"  { UP return OPL_G; 	}
"<=" { UP return OPL_LE; 	}
">=" { UP return OPL_GE; 	}

">>=" | ">>>="  { UP return OP_ASSIGN_LSHIFT; }
"<<=" | "<<<="  { UP return OP_ASSIGN_RSHIFT; }
"+="  { UP return OP_ASSIGN_ADD; }
"-="  { UP return OP_ASSIGN_SUB; }
"**=" { UP return OP_ASSIGN_POW; }
"*="  { UP return OP_ASSIGN_MUL; }
"/="  { UP return OP_ASSIGN_DIV; }
"%="  { UP return OP_ASSIGN_MOD; }
"&="  { UP return OP_ASSIGN_AND; }
"|="  { UP return OP_ASSIGN_OR; }
"^="  { UP return OP_ASSIGN_XOR; }
"="   { UP return OP_ASSIGN; }

"~"  { UP return OPB_NOT; }
"|"  { UP return OPB_OR;  }
"&"  { UP return OPB_AND; }
"^"  { UP return OPB_XOR; }
"<<"|"<<<"  { UP return OPB_LSHIFT; }
">>"|">>>"  { UP return OPB_RSHIFT; }

"++" { UP return OPA_INC; }
"--" { UP return OPA_DEC; }
"*"  { UP return OPA_MUL; }
"/"  { UP return OPA_DIV; }
"%"  { UP return OPA_MOD; }
"+"  { UP return OPA_ADD; }
"-"  { UP return OPA_SUB; }

"." { UP return DOT; }
"," { UP return COMA; }
":" { UP return COLON; }
"?" { UP return QMARK; }
"(" { UP return LBRACKET_ROUND; }
")" { UP return RBRACKET_ROUND; }
"[" { UP return LBRACKET_SQUARE;}
"]" { UP return RBRACKET_SQUARE;}
"{" { UP return LBRACKET_CURLY; }
"}" { UP return RBRACKET_CURLY; }


[\t ] /* Spaces: tab and space */ {
UP	
}

";" /* Spaces: operation splitter */ {
	UP
	return END_OP;
}

"\n" /* Spaces: newline */ {
	UPNL;
	//return ENDLINE;
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
	
	std::cout << "Error position: Line " << g_yypos.getLine() << ", Column " << g_yypos.getCol() << std::endl;

	//printf("Position: [line %u: %u]\n", g_yystat.yyline, g_yystat.yylinepos);
	//printf("Text: '%s'\n", yytext);
	
	//yyin.close();
	//yyLexCleanup();
	//yyYaccCleanup();
	
	//WAIT_USER;
	//exit(1);
}

//void yyLexCleanup() {}
