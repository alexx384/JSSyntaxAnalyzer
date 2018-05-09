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

ENDLINE

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
%nonassoc NO_ELSE
%nonassoc ELSE
%nonassoc LBRACKET_ROUND RBRACKET_ROUND

%%

block:
			expression END_OP									{dbg("block: a + 0;")}
			//| expression ENDLINE 								{dbg("block: a + 0\\n")}
			| block expression END_OP							{dbg("block: ... a + 0;")}
			//| block expression ENDLINE 							{dbg("block: ... a + 0\\n")}

			| var_init END_OP									{dbg("block: variable initialization;")}
			//| var_init ENDLINE									{dbg("block: variable initialization\\n")}
			| block var_init END_OP								{dbg("block: ... ; variable initialization;")}
			//| block var_init ENDLINE							{dbg("block: ... \\n variable initialization;")}

			| obj_and_method END_OP								{dbg("block: document.writeln('Hello World');")}
			//| obj_and_method ENDLINE							{dbg("block: document.writeln('Hello World')\\n")}
			| block obj_and_method END_OP						{dbg("block: ... document.writeln('Hello World');")}
			//| block obj_and_method ENDLINE					{dbg("block: ... document.writeln('Hello World')\\n")}

			| LBRACKET_CURLY block RBRACKET_CURLY				{dbg("block: { block }")}
			| block LBRACKET_CURLY block RBRACKET_CURLY			{dbg("block: ... { block }")}

			| if_operator 										{dbg("block: if ()")}

			| switch_operator 									{dbg("block: switch")}							

single_block:
			expression END_OP									{dbg("block: a + 0;")}
			//| expression ENDLINE 								{dbg("block: a + 0\\n")}

			| var_init END_OP									{dbg("block: variable initialization;")}
			//| var_init ENDLINE									{dbg("block: variable initialization\\n")}

			| obj_and_method END_OP								{dbg("block: document.writeln('Hello World');")}
			//| obj_and_method ENDLINE							{dbg("block: document.writeln('Hello World')\\n")}

			| LBRACKET_CURLY block RBRACKET_CURLY				{dbg("block: { block }")}

			| if_operator 										{dbg("block: if ()")}

			| switch_operator 									{dbg("block: switch")}

switch_operator:
			SWITCH LBRACKET_ROUND expression RBRACKET_ROUND LBRACKET_CURLY case_expression RBRACKET_CURLY

case_expression:
			CASE expression COLON block 						{dbg("case_expression: case 1: block")}
			| case_expression CASE expression COLON block 		{dbg("case_expression: ... case 1: block")}

if_operator:
			IF LBRACKET_ROUND expression RBRACKET_ROUND single_block %prec NO_ELSE	 	 {dbg("if_operator: if (expression) block")}
			| IF LBRACKET_ROUND expression RBRACKET_ROUND single_block ELSE single_block {dbg("if_operator: if (expression) single_stat_blck else single_stat_blck")}


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
			| VAR literal_string 								{dbg("var_init: var a")}
			| var												{dbg("var_init: a...; (global variable)")}
			
var:
			var COMA literal_string								{dbg("var: ...a")}
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

			| binary_expression 								{dbg("expression: binary_expression")}
			| ternary_expression 								{dbg("expression: ternary_expression")}
			| unary_expression									{dbg("expression: unary_expression")}

			| literal_number 									{dbg("expression: literal_number")}
			| constant_string 									{dbg("expression: constant_string")}
			| literal_string 									{dbg("expression: literal_string")}

			| empty_expression 									{dbg("expression: empty_expression")}

			| useful_words										{dbg("expression: useful_words")}

useful_words:
			BREAK 												{dbg("useful_words: break")}
			| CONTINUE 											{dbg("useful_words: continue")}

unary_expression:
			/* prefix expression */
			OPA_INC literal_string				{dbg("unary_expression: ++ a")}
			| OPA_INC LBRACKET_ROUND literal_string RBRACKET_ROUND 		{dbg("unary_expression: ++ (a)")}
			| OPA_DEC literal_string	 		{dbg("unary_expression: -- a")}
			| OPA_DEC LBRACKET_ROUND literal_string RBRACKET_ROUND 		{dbg("unary_expression: -- (a)")}

			/* postfix expression */
			/* надо подумать на счёт этого. Возможно придётся реализовать 
			   второй тип expression - bracket expression */
			| literal_string OPA_INC 			{dbg("unary_expression: a ++")}
			//| LBRACKET_ROUND literal_string RBRACKET_ROUND OPA_INC 	{dbg("unary_expression: (a) ++")}
			| literal_string OPA_DEC 			{dbg("unary_expression: a --")}
			//| LBRACKET_ROUND literal_string RBRACKET_ROUND OPA_DEC 	{dbg("unary_expression: (a) --")}

binary_expression:
			expression OPA_MUL 		expression 	{dbg("binary_expression: a * a")}
			| expression OPA_DIV    expression	{dbg("binary_expression: a / a")}
			| expression OPA_MOD    expression	{dbg("binary_expression: a % a")}
			| expression OPA_SUB 	expression 	{dbg("binary_expression: a - a")}
			| expression OPA_ADD	expression 	{dbg("binary_expression: a + a")}
			                                          
			| expression OPL_AND	expression 	{dbg("binary_expression: a && a")}	
			| expression OPL_OR 	expression 	{dbg("binary_expression: a || a")}
			| expression OPL_EQ 	expression 	{dbg("binary_expression: a == a, a === a")}
			| expression OPL_NEQ	expression 	{dbg("binary_expression: a != a, a !== a")} 
			| expression OPL_L  	expression 	{dbg("binary_expression: a < a")}
			| expression OPL_G  	expression 	{dbg("binary_expression: a > a")}
			| expression OPL_GE 	expression 	{dbg("binary_expression: a <= a")}
			| expression OPL_LE 	expression 	{dbg("binary_expression: a >= a")}
			                                          
			| expression OPB_AND    expression	{dbg("binary_expression: a & a")}
			| expression OPB_OR     expression	{dbg("binary_expression: a | a")}
			| expression OPB_XOR    expression	{dbg("binary_expression: a ^ a")}
			| expression OPB_LSHIFT expression	{dbg("binary_expression: a << a, a <<< a")} 
			| expression OPB_RSHIFT expression	{dbg("binary_expression: a >> a, a >>> a")}

ternary_expression:
			expression QMARK expression COLON expression {dbg("ternary_expression: (a > 0) ? 1 : 0")}

/* <<<<<<<<<<<------ Expressions ------>>>>>>>>>>> */

			
/////////////////--------------- literals

literal_string : OBJ_NAME 						{dbg("Literal string")	}
constant_string: CSTRING 						{dbg("Constant string");}
literal_number: LITERAL_NUMBER 					{dbg("Literal number")	}

/////////////////--------------- literals

%%

void yyYaccInit() {}
void yyYaccCleanup() {}