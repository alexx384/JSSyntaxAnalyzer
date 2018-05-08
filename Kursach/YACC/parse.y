%token 

/* ----- JS reserved words ----- */
ABSTRACT BOOLEAN BREAK BYTE CASE CATCH CHAR CLASS CONST CONTINUE DEBUGGER DEFAULT
DELETE DO DOUBLE ELSE ENUM EXPORT EXTENDS FALSE FINAL FINALLY FLOAT FOR FUNCTION
GOTO IF IMPLEMENTS IMPORT IN INSTANCEOF INT INTERFACE LONG NATIVE NEW NUL
PACKAGE PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC SUPER SWITCH SYNCHRONIZED
THIS THROW THROWS TRANSIENT TRUE TRY TYPEOF VAR VOID VOLATILE WHILE WITH
UNDEFINED NAN INFINITY
/* ----- JS reserved words ----- */

DOT 	// access operator '.'
COMA	// enum operator ','
COLON	// refinement operator ':'
QMARK	// question mark '?'

// () [] {} brackets
LBRACKET_ROUND		// '('
RBRACKET_ROUND		// ')'
LBRACKET_SQUARE		// '['
RBRACKET_SQUARE		// ']'
LBRACKET_CURLY		// '{'
RBRACKET_CURLY		// '}'

// literals
INT_NUM
LITERAL_NUMBER
OBJ_NAME

// constant string
CSTRING

END_OP

// assignment operator
OP_ASSIGN			//	=
OP_ASSIGN_ADD   	// +=
OP_ASSIGN_SUB   	// -=
OP_ASSIGN_MUL   	// *=
OP_ASSIGN_POW   	// **=
OP_ASSIGN_DIV   	// /=
OP_ASSIGN_MOD   	// %=
OP_ASSIGN_LSHIFT	// <<=, <<<=
OP_ASSIGN_RSHIFT	// >>=, >>>=
OP_ASSIGN_AND		// &=
OP_ASSIGN_XOR		// ^=
OP_ASSIGN_OR 		// |=


// logical operation tokens
OPL_NOT		// !
OPL_AND		// &&
OPL_OR		// ||
OPL_EQ		// == equal
OPL_NEQ		// != not equal
OPL_L		// < less
OPL_G		// > greater
OPL_GE		// >= greater equal
OPL_LE		// <= less equal


// bitwise operation tokens
OPB_NOT		// ~
OPB_OR		// |
OPB_AND		// &
OPB_XOR		// ^
OPB_LSHIFT	// <<, <<<
OPB_RSHIFT	// >>, >>>

// arithmetic operation tokens
OPA_MUL // '*'
OPA_DIV // '/'
OPA_MOD // '%'
OPA_ADD // '+'
OPA_SUB // '-'
OPA_INC	// '++'
OPA_DEC // '--'

/////////////////--------------- inline C code

%{	
	#include <malloc.h>
	#include "KurCommon.h"
	
	#ifdef _DEBUG
	#define dbg(str) std::cout << str << std::endl;
	#else
	#define dbg(str)
	#endif
%}


/////////////////--------------- inline C code

// start from label
%start block

// low priority downto max priority
%left COMA
%right OP_ASSIGN OP_ASSIGN_ADD OP_ASSIGN_SUB OP_ASSIGN_MUL OP_ASSIGN_DIV OP_ASSIGN_MOD OP_ASSIGN_LSHIFT OP_ASSIGN_RSHIFT OP_ASSIGN_AND OP_ASSIGN_XOR OP_ASSIGN_OR
%left QMARK COLON
%left OPL_OR
%left OPL_AND
%left OPB_OR 
%left OPB_XOR
%left OPB_AND 
%left OPL_EQ OPL_NEQ
%left IN INSTANCEOF OPL_L OPL_G	OPL_GE OPL_LE
%left OPB_LSHIFT OPB_RSHIFT	
%left OPA_ADD OPA_SUB
%left OPA_MUL OPA_DIV OPA_MOD  
%right OPA_POW
%right OPL_NOT OPB_NOT TYPEOF VOID DELETE OPA_INC OPA_DEC /* and unary +, - */
%left NEW LBRACKET_SQUARE RBRACKET_SQUARE DOT
%left END_OP
%nonassoc LBRACKET_ROUND RBRACKET_ROUND

%%

block:
			expression END_OP									{dbg("block: a + 0;")}
			| block expression END_OP							{dbg("block: ... a + 0;")}
			| empty_expression END_OP 							{dbg("block: ; empty_expression;")}
			| block empty_expression END_OP						{dbg("block: ... ; empty_expression;")}

			| var_init END_OP									{dbg("block: variable initialization;")}
			| block var_init END_OP								{dbg("block: ... ; variable initialization;")}

			| obj_and_method END_OP								{dbg("block: document.writeln('Hello World');")}
			| block obj_and_method END_OP						{dbg("block: ... document.writeln('Hello World');")}

/* >>>>>>>>>>>------ Objects ------<<<<<<<<<<< */

obj_and_method:
			object LBRACKET_ROUND parameters RBRACKET_ROUND {dbg("obj_and_method: f(expr)")}

parameters:
			expression 											{dbg("parameters: 1")}
			| parameters DOT expression 						{dbg("parameters: ... , 1")}

object:
			literal_string	 									{dbg("object: a")}
			| object DOT literal_string							{dbg("object: ... .a")}

/* <<<<<<<<<<<------ Objects ------>>>>>>>>>>> */

/* >>>>>>>>>>>------ Variable initialization ------<<<<<<<<<<< */

var_init:
			VAR var												{dbg("var_init: var a...; (local variable)")}
			| var												{dbg("var_init: a...; (global variable)")}
			
var:
			literal_string 										{dbg("var: a")}
			| var COMA literal_string							{dbg("var: ...a")}
			| operation_assign 									{dbg("var_init: a = 0;")}
			| var COMA operation_assign 						{dbg("var_init: a = 0, ...")}

operation_assign:
			literal_string OP_ASSIGN expression					{dbg("operation_assign: a = 0;")}
			| literal_string OP_ASSIGN operation_assign			{dbg("operation_assign: a = ...")}

/* <<<<<<<<<<<------ Variable initialization ------>>>>>>>>>>> */

/* >>>>>>>>>>>------ Expressions ------<<<<<<<<<<< */

empty_expression:
			{dbg("empty_expression: ;")}

expression: 
			// expr in brackets
			//| LBRACKET_ROUND expression RBRACKET_ROUND DOT refinements_and_calls 	{dbg("(expr).f(). ...")	}
			
			////------ expression operands end

			LBRACKET_ROUND expression RBRACKET_ROUND			{dbg("expression: (a+0)")}

			| binary_expression
			| ternary_expression
			| unary_expression				

			| literal_number
			| constant_string

literal_expression:
			literal_string
			| expression

unary_expression:
			/* prefix expression */
			OPA_INC literal_string				{dbg("unary_expression: ++ a")}
			| OPA_INC LBRACKET_ROUND literal_string RBRACKET_ROUND
			| OPA_DEC literal_string	 		{dbg("unary_expression: -- a")}
			| OPA_DEC LBRACKET_ROUND literal_string RBRACKET_ROUND

			/* postfix expression */
			/* надо подумать на счёт этого. Возможно придётся реализовать 
			   второй тип expression - bracket expression */
			| literal_string OPA_INC 			{dbg("unary_expression: a ++")}
			//| LBRACKET_ROUND literal_string RBRACKET_ROUND OPA_INC
			| literal_string OPA_DEC 			{dbg("unary_expression: a --")}
			//| LBRACKET_ROUND literal_string RBRACKET_ROUND OPA_DEC

binary_expression:
			literal_expression OPA_MUL 		literal_expression 	{dbg("binary_expression: a * a")}
			| literal_expression OPA_DIV    literal_expression	{dbg("binary_expression: a / a")}
			| literal_expression OPA_MOD    literal_expression	{dbg("binary_expression: a % a")}
			| literal_expression OPA_SUB 	literal_expression 	{dbg("binary_expression: a - a")}
			| literal_expression OPA_ADD	literal_expression 	{dbg("binary_expression: a + a")}
			                                          
			| literal_expression OPL_AND	literal_expression 	{dbg("binary_expression: a && a")}	
			| literal_expression OPL_OR 	literal_expression 	{dbg("binary_expression: a || a")}
			| literal_expression OPL_EQ 	literal_expression 	{dbg("binary_expression: a == a, a === a")}
			| literal_expression OPL_NEQ	literal_expression 	{dbg("binary_expression: a != a, a !== a")} 
			| literal_expression OPL_L  	literal_expression 	{dbg("binary_expression: a < a")}
			| literal_expression OPL_G  	literal_expression 	{dbg("binary_expression: a > a")}
			| literal_expression OPL_GE 	literal_expression 	{dbg("binary_expression: a <= a")}
			| literal_expression OPL_LE 	literal_expression 	{dbg("binary_expression: a >= a")}
			                                          
			| literal_expression OPB_AND    literal_expression	{dbg("binary_expression: a & a")}
			| literal_expression OPB_OR     literal_expression	{dbg("binary_expression: a | a")}
			| literal_expression OPB_XOR    literal_expression	{dbg("binary_expression: a ^ a")}
			| literal_expression OPB_LSHIFT literal_expression	{dbg("binary_expression: a << a, a <<< a")} 
			| literal_expression OPB_RSHIFT literal_expression	{dbg("binary_expression: a >> a, a >>> a")}

ternary_expression:
			literal_expression QMARK literal_expression COLON literal_expression {dbg("ternary_expression: (a > 0) ? 1 : 0")}

/* <<<<<<<<<<<------ Expressions ------>>>>>>>>>>> */

			
/////////////////--------------- literals

literal_string : OBJ_NAME 						{dbg("Literal string")	}
constant_string: CSTRING 						{dbg("Constant string");}
literal_number: LITERAL_NUMBER 					{dbg("Literal number")	}

/////////////////--------------- literals

%%

void yyYaccInit() {}
void yyYaccCleanup() {}