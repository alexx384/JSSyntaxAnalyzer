%token 

/* ----- JS reserved words ----- */
ABSTRACT
BOOLEAN
BREAK
BYTE
CASE
CATCH
CHAR
CLASS
CONST
CONTINUE
DEBUGGER
DEFAULT
DELETE
DO
DOUBLE	
ELSE
ENUM
EXPORT
EXTENDS
FALSE
FINAL
FINALLY
FLOAT
FOR
FUNCTION
GOTO
IF
IMPLEMENTS
IMPORT
IN	
INSTANCEOF
INT
INTERFACE
LONG
NATIVE
NEW
NUL
PACKAGE
PRIVATE
PROTECTED
PUBLIC
RETURN
SHORT
STATIC
SUPER
SWITCH
SYNCHRONIZED
THIS
THROW
THROWS
TRANSIENT
TRUE
TRY
TYPEOF
VAR
VOID
VOLATILE
WHILE
WITH
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
			| empty_expression 									{dbg("block: ; (empty_expression)")}
			| block empty_expression							{dbg("block: ... ; (empty_expression)")}

			| VAR var_init 										{dbg("block: var a... (local variable)")}
			| block VAR var_init 								{dbg("block: ... var a... (local variable)")}
			| var_init 											{dbg("block: a... (global variable)")}
			| block var_init 									{dbg("block: ... a... (global variable)")}

var_init:
			operation_assign COMA var_init						{dbg("var_init: a = 0, ...")}
			| literal_string COMA var_init						{dbg("var_init: a, ...")}
			| operation_assign END_OP							{dbg("var_init: a = 0;")}
			| literal_string END_OP								{dbg("var_init: a;")}

operation_assign:
			literal_string OP_ASSIGN expression					{dbg("operation_assign: a = 0;")}
			| literal_string OP_ASSIGN operation_assign			{dbg("operation_assign: a = ...")}

/* >>>>>>>>>>>------ Expressions ------<<<<<<<<<<< */

expression: 
			// expr in brackets
			//| LBRACKET_ROUND expression RBRACKET_ROUND DOT refinements_and_calls 	{dbg("(expr).f(). ...")	}
			
			////------ expression operands end
					
			LBRACKET_ROUND expression RBRACKET_ROUND			{dbg("expression: (a+0)")			}

			| unary_expression				
			| binary_expression
			| ternary_expression


			| literal_number
			| constant_string
			| literal_string

empty_expression:
			{dbg("empty_expression: ;")}

unary_expression:
			/* prefix expression */
			OPA_INC	expression 		{dbg("unary_expression: ++ a")}
			| OPA_DEC expression  	{dbg("unary_expression: -- a")}

			/* postfix expression */
			| expression OPA_INC 	{dbg("unary_expression: a ++")}
			| expression OPA_DEC 	{dbg("unary_expression: a --")}

binary_expression:
			expression OPA_MUL 	expression 	{dbg("binary_expression: a * a")}
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

constant_string: CSTRING 						{dbg("Constant string");}
literal_string : OBJ_NAME 						{dbg("Literal string")	}
literal_number: LITERAL_NUMBER 					{dbg("Literal number")	}

/////////////////--------------- literals

%%

void yyYaccInit() {}
void yyYaccCleanup() {}