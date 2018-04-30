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
LITERAL_NUMBER
LITERAL_STRING

// constant string
CSTRING

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
%start expression

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
%nonassoc LBRACKET_ROUND RBRACKET_ROUND

%%

//////////////-------------- expression

expression: 
			// expr in brackets
			LBRACKET_ROUND expression RBRACKET_ROUND								{dbg("(expr)")			}
			//| LBRACKET_ROUND expression RBRACKET_ROUND DOT refinements_and_calls 	{dbg("(expr).f(). ...")	}
			
			////------ expression operands end
		
			// ternary operations
			| expression QMARK expression COLON expression {dbg("expr ? expr : expr")}
			
			// binary operations (infix)
			| expression OPA_MUL 	expression 	{dbg("binary *")}
			| expression OPA_DIV    expression	{dbg("binary /")}
			| expression OPA_MOD    expression	{dbg("binary %")}
			| expression OPA_SUB 	expression 	{dbg("binary -")}
			| expression OPA_ADD	expression 	{dbg("binary +")}
			                                          
			| expression OPL_AND	expression 	{dbg("binary &&")}	
			| expression OPL_OR 	expression 	{dbg("binary ||")}
			| expression OPL_EQ 	expression 	{dbg("binary ==, ===")}
			| expression OPL_NEQ	expression 	{dbg("binary !=, !==")} 
			| expression OPL_L  	expression 	{dbg("binary <")}
			| expression OPL_G  	expression 	{dbg("binary >")}
			| expression OPL_GE 	expression 	{dbg("binary <=")}
			| expression OPL_LE 	expression 	{dbg("binary >=")}
			                                          
			| expression OPB_AND    expression	{dbg("binary &")}
			| expression OPB_OR     expression	{dbg("binary |")}
			| expression OPB_XOR    expression	{dbg("binary ^")}
			| expression OPB_LSHIFT expression	{dbg("binary <<, <<<")} 
			| expression OPB_RSHIFT expression	{dbg("binary >>, >>>")}


			| literal_number
			| constant_string
			| literal_string

//////////////-------------- expression
			
			
/////////////////--------------- literals

constant_string: CSTRING {dbg("Constant string");}
literal_string: LITERAL_STRING {dbg("Literal string")	}
literal_number: LITERAL_NUMBER {dbg("Literal number")	}

/////////////////--------------- literals

%%

void yyYaccInit() {}
void yyYaccCleanup() {}