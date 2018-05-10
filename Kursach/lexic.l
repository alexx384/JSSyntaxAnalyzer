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
	
	#define DEBUGLEX

	#ifdef DEBUGLEX
		#define DL(x) std::cout << #x << std::endl;
	#elif
		#define DL(x)
	#endif
%}

%%

digit /* integer number */ {
	UP DL(INT_NUM);	return INT_NUM;
}

{mantissa}([eE][+-]?{digit}+)? /* Float number */ {
UP
DL(LITERAL_NUMBER);
return LITERAL_NUMBER;
}




"'"	 /* Const string */	{ UP DL(const_string1); BEGIN(const_string1); }
"\"" /* Const string */	{ UP DL(const_string2); BEGIN(const_string2); }

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
UPNL; DL(single line comment); 
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


"abstract"	    /* JZ reserved word */ 	{ UP DL(ABSTRACT); return ABSTRACT; 	}
"boolean"       /* JZ reserved word */	{ UP DL(BOOLEAN); return BOOLEAN; 		}
"break"         /* JZ reserved word */  { UP DL(BREAK); return BREAK; 		}
"byte"          /* JZ reserved word */  { UP DL(BYTE); return BYTE; 		}
"case"          /* JZ reserved word */  { UP DL(CASE); return CASE; 		}
"catch"         /* JZ reserved word */  { UP DL(CATCH); return CATCH; 		}
"char"          /* JZ reserved word */  { UP DL(CHAR); return CHAR; 		}
"class"         /* JZ reserved word */  { UP DL(CLASS); return CLASS; 		}
"const"         /* JZ reserved word */  { UP DL(CONST); return CONST; 		}
"continue"      /* JZ reserved word */  { UP DL(CONTINUE); return CONTINUE; 	}
"debugger"      /* JZ reserved word */  { UP DL(DEBUGGER); return DEBUGGER; 	}
"default"       /* JZ reserved word */  { UP DL(DEFAULT); return DEFAULT; 		}
"delete"        /* JZ reserved word */  { UP DL(DELETE); return DELETE; 		}
"do"            /* JZ reserved word */  { UP DL(DO); return DO; 			}
"double"        /* JZ reserved word */  { UP DL(DOUBLE); return DOUBLE; 		}
"else"          /* JZ reserved word */  { UP DL(ELSE); return ELSE; 		}	
"enum"          /* JZ reserved word */  { UP DL(ENUM); return ENUM; 		}
"export"        /* JZ reserved word */  { UP DL(EXPORT); return EXPORT; 		}
"extends"       /* JZ reserved word */  { UP DL(EXTENDS); return EXTENDS; 		}
"false"         /* JZ reserved word */  { UP DL(FALSE); return FALSE; 		}
"final"         /* JZ reserved word */  { UP DL(FINAL); return FINAL; 		}
"finally"       /* JZ reserved word */  { UP DL(FINALLY); return FINALLY; 		}
"float"         /* JZ reserved word */  { UP DL(FLOAT); return FLOAT; 		}
"for"           /* JZ reserved word */  { UP DL(FOR); return FOR; 			}
"function"      /* JZ reserved word */  { UP DL(FUNCTION); return FUNCTION; 	}
"goto"          /* JZ reserved word */  { UP DL(GOTO); return GOTO; 		}
"if"            /* JZ reserved word */  { UP DL(IF); return IF; 			}
"implements"    /* JZ reserved word */  { UP DL(IMPLEMENTS); return IMPLEMENTS; 	}
"import"        /* JZ reserved word */  { UP DL(IMPORT); return IMPORT; 		}
"in"            /* JZ reserved word */  { UP DL(IN); return IN; 			}
"instanceof"    /* JZ reserved word */  { UP DL(INSTANCEOF); return INSTANCEOF; 	}
"int"           /* JZ reserved word */  { UP DL(INT); return INT; 			}
"interface"     /* JZ reserved word */  { UP DL(INTERFACE); return INTERFACE; 	}
"long"          /* JZ reserved word */  { UP DL(LONG); return LONG; 		}
"native"        /* JZ reserved word */  { UP DL(NATIVE); return NATIVE; 		}
"new"           /* JZ reserved word */  { UP DL(NEW); return NEW; 			}
"null"          /* JZ reserved word */  { UP DL(NUL); return NUL; 			}	
"package"       /* JZ reserved word */  { UP DL(PACKAGE); return PACKAGE; 		}
"private"       /* JZ reserved word */  { UP DL(PRIVATE); return PRIVATE; 		}
"protected"     /* JZ reserved word */  { UP DL(PROTECTED); return PROTECTED; 	}
"public"        /* JZ reserved word */  { UP DL(PUBLIC); return PUBLIC; 		}
"return"        /* JZ reserved word */  { UP DL(RETURN); return RETURN; 		}
"short"         /* JZ reserved word */  { UP DL(SHORT); return SHORT; 		}	
"static"        /* JZ reserved word */  { UP DL(STATIC); return STATIC; 		}
"super"         /* JZ reserved word */  { UP DL(SUPER); return SUPER; 		}
"switch"		/* JZ reserved word */  { UP DL(SWITCH); return SWITCH; 		}
"synchronized"	/* JZ reserved word */  { UP DL(SYNCHRONIZED); return SYNCHRONIZED; }
"this"			/* JZ reserved word */  { UP DL(THIS); return THIS; 		}
"throw"         /* JZ reserved word */  { UP DL(THROW); return THROW; 		}
"throws"        /* JZ reserved word */  { UP DL(THROWS); return THROWS; 		}
"transient"     /* JZ reserved word */  { UP DL(TRANSIENT); return TRANSIENT;	}
"true"          /* JZ reserved word */  { UP DL(TRUE); return TRUE; 		}
"try"           /* JZ reserved word */  { UP DL(TRY); return TRY; 			}
"typeof"        /* JZ reserved word */  { UP DL(TYPEOF); return TYPEOF; 		}
"var"           /* JZ reserved word */  { UP DL(VAR); return VAR; 			}
"void"          /* JZ reserved word */  { UP DL(VOID); return VOID; 		}
"volatile"      /* JZ reserved word */  { UP DL(VOLATILE); return VOLATILE; 	}
"while"         /* JZ reserved word */  { UP DL(WHILE); return WHILE; 		}
"with"          /* JZ reserved word */  { UP DL(WITH); return WITH; 		}

[_$a-zA-Z]+[_$a-zA-Z0-9]*+(:) /* Variable/function name */ {
UP DL(LABEL);
}


[_$a-zA-Z]+[_$a-zA-Z0-9]* /* Variable/function name */ {
UP DL(OBJ_NAME);	return OBJ_NAME;
}



(==|===)  { UP DL(OPL_EQ); return OPL_EQ; 	}
(!=|!==) { UP DL(OPL_NEQ); return OPL_NEQ; }
"!"  { UP DL(OPL_NOT); return OPL_NOT; }
"&&" { UP DL(OPL_AND); return OPL_AND; }
"||" { UP DL(OPL_OR); return OPL_OR; 	}
"<"  { UP DL(OPL_L); return OPL_L; 	}
">"  { UP DL(OPL_G); return OPL_G; 	}
"<=" { UP DL(OPL_LE); return OPL_LE; 	}
">=" { UP DL(OPL_GE); return OPL_GE; 	}

(>>=|>>>=)  { UP DL(OP_ASSIGN_LSHIFT); return OP_ASSIGN_LSHIFT; }
(<<=|<<<=)  { UP DL(OP_ASSIGN_RSHIFT); return OP_ASSIGN_RSHIFT; }
"+="  { UP DL(OP_ASSIGN_ADD); return OP_ASSIGN_ADD; }
"-="  { UP DL(OP_ASSIGN_SUB); return OP_ASSIGN_SUB; }
"**=" { UP DL(OP_ASSIGN_POW); return OP_ASSIGN_POW; }
"*="  { UP DL(OP_ASSIGN_MUL); return OP_ASSIGN_MUL; }
"/="  { UP DL(OP_ASSIGN_DIV); return OP_ASSIGN_DIV; }
"%="  { UP DL(OP_ASSIGN_MOD); return OP_ASSIGN_MOD; }
"&="  { UP DL(OP_ASSIGN_AND); return OP_ASSIGN_AND; }
"|="  { UP DL(OP_ASSIGN_OR); return OP_ASSIGN_OR; }
"^="  { UP DL(OP_ASSIGN_XOR); return OP_ASSIGN_XOR; }
"="   { UP DL(OP_ASSIGN); return OP_ASSIGN; }

"~"  { UP DL(OPB_NOT); return OPB_NOT; }
"|"  { UP DL(OPB_OR); return OPB_OR;  }
"&"  { UP DL(OPB_AND); return OPB_AND; }
"^"  { UP DL(OPB_XOR); return OPB_XOR; }
(<<|<<<)  { UP DL(OPB_LSHIFT); return OPB_LSHIFT; }
(>>|>>>)  { UP DL(OPB_RSHIFT); return OPB_RSHIFT; }

"++" { UP DL(OPA_INC); return OPA_INC; }
"--" { UP DL(OPA_DEC); return OPA_DEC; }
"*"  { UP DL(OPA_MUL); return OPA_MUL; }
"/"  { UP DL(OPA_DIV); return OPA_DIV; }
"%"  { UP DL(OPA_MOD); return OPA_MOD; }
"+"  { UP DL(OPA_ADD); return OPA_ADD; }
"-"  { UP DL(OPA_SUB); return OPA_SUB; }

"." { UP DL(DOT); return DOT; }
"," { UP DL(COMA); return COMA; }
":" { UP DL(COLON); return COLON; }
"?" { UP DL(QMARK); return QMARK; }
"(" { UP DL(LBRACKET_ROUND); return LBRACKET_ROUND; }
")" { UP DL(RBRACKET_ROUND); return RBRACKET_ROUND; }
"[" { UP DL(LBRACKET_SQUARE); return LBRACKET_SQUARE;}
"]" { UP DL(RBRACKET_SQUARE); return RBRACKET_SQUARE;}
"{" { UP DL(LBRACKET_CURLY); return LBRACKET_CURLY; }
"}" { UP DL(RBRACKET_CURLY); return RBRACKET_CURLY; }


[\t ] /* Spaces: tab and space */ {
UP	DL(TAB);
}

";" /* Spaces: operation splitter */ {
	UP
	DL(END_OP);
	return END_OP;
}

"\n" /* Spaces: newline */ {
	UPNL;
	DL(ENDLINE);
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
