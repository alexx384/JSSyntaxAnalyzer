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
	#define dbgCoBlck(str) SetTextColor(LIGHT_BLUE);\
								 std::cout << str << std::endl;\
						   RevertColors();

	#define dbgCoExpr(str) SetTextColor(LIGHT_YELLOW);\
								 std::cout << str << std::endl;\
						   RevertColors();

	#define dbgCoOper(str) SetTextColor(LIGHT_GREEN);\
								 std::cout << str << std::endl;\
						   RevertColors();

	#define dbg(str) std::cout << str << std::endl;
	#else
	#define dbgCoBlck(str)
	#define dbgCoExpr(str)
	#define dbgCoOper(str)
	#define dbg(str)
	#endif
%}


/////////////////--------------- inline C code

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
			expression END_OP									{dbgCoBlck("block: a + 0;")}
			| block expression END_OP							{dbgCoBlck("block: ... a + 0;")}

			| var_init END_OP									{dbgCoBlck("block: variable initialization;")}
			| block var_init END_OP								{dbgCoBlck("block: ... ; variable initialization;")}

			| LBRACKET_CURLY block RBRACKET_CURLY				{dbgCoBlck("block: { block }")}
			| block LBRACKET_CURLY block RBRACKET_CURLY			{dbgCoBlck("block: ... { block }")}

			| LBRACKET_CURLY RBRACKET_CURLY						{dbgCoBlck("block: { }")}
			| block LBRACKET_CURLY RBRACKET_CURLY				{dbgCoBlck("block: { }")}

			| operators 										{dbgCoBlck("block: operators")}
			| block operators									{dbgCoBlck("block: ... operators")}

			| function 											{dbgCoBlck("block: function")}

			| block literal_string COLON 						{dbgCoBlck("block: label")} 

/* >>>>>>>>>>>------ Switch statement ------<<<<<<<<<<< */

function:
			FUNCTION func_name LBRACKET_ROUND func_parameters RBRACKET_ROUND LBRACKET_CURLY func_body RBRACKET_CURLY 	{dbg("function: function func_name (parameters) { func_body }")}

func_body:
			block 												{dbg("func_body: block")}
			|													{dbg("func_body: <nothing>")}

func_name:
			literal_string 										{dbg("func_name: name")}
			| 													{dbg("func_name: <nothing>")}

func_parameters:
			literal_string 										{dbg("func_parameters: a")}		
			| func_parameters COMA literal_string 				{dbg("func_parameters: ... , a")}				
			| 													{dbg("func_parameters: <nothing>")}		

/* <<<<<<<<<<<------ Switch statement ------>>>>>>>>>>> */

operators:
			if_operator 										{dbgCoOper("operators: if ()")}

			| switch_operator 									{dbgCoOper("operators: switch")}

			| while_operator 									{dbgCoOper("operators: while")}

			| for_operator 										{dbgCoOper("operators: for")}

			| do_operator 										{dbgCoOper("operators: do ... while();")}

			| try_operator 										{dbgCoOper("operators: try");}

			| throw_operator 									{dbgCoOper("operators: throw")}

			| return_operator 									{dbgCoOper("operators: return")}

			| break_operator 									{dbgCoOper("operators: break")}

break_operator:
			BREAK END_OP
			| BREAK literal_string END_OP 

return_operator:
			RETURN expression END_OP

throw_operator:
			THROW expression END_OP

try_operator:
			TRY LBRACKET_CURLY block RBRACKET_CURLY catch_operator 										{dbg("try_operator: try { block } catch_operator")}
			| TRY LBRACKET_CURLY block RBRACKET_CURLY FINALLY LBRACKET_CURLY block RBRACKET_CURLY		{dbg("try_operator: try { block } finally { block }")}

catch_operator:
			CATCH LBRACKET_ROUND literal_string RBRACKET_ROUND LBRACKET_CURLY block RBRACKET_CURLY 		{dbg("catch_operator: catch (a) { block }")}
			| CATCH LBRACKET_CURLY block RBRACKET_CURLY													{dbg("catch_operator: catch { block }")}
			| catch_operator FINALLY LBRACKET_CURLY block RBRACKET_CURLY 								{dbg("catch_operator: ... finally { block }")}

do_operator:
			DO single_block WHILE LBRACKET_ROUND expression RBRACKET_ROUND END_OP 	{dbg("do_operator: do ... while(expression);")}

while_operator:
			WHILE LBRACKET_ROUND expression RBRACKET_ROUND single_block 	{dbg("while_operator: while (expression) block")}

for_operator:
			FOR LBRACKET_ROUND expression END_OP expression END_OP expression RBRACKET_ROUND single_block 	{dbg("for_operator: for(i=0; i < 4; i++) block")}
			| FOR LBRACKET_ROUND literal_string IN object RBRACKET_ROUND single_block 						{dbg("for(i in obj) block")}

/* >>>>>>>>>>>------ Switch statement ------<<<<<<<<<<< */

switch_operator:
			SWITCH LBRACKET_ROUND expression RBRACKET_ROUND LBRACKET_CURLY case_expression RBRACKET_CURLY

case_expression:
			CASE expression COLON block 						{dbg("case_expression: case 1: block")}
			| case_expression CASE expression COLON block 		{dbg("case_expression: ... case 1: block")}
			| DEFAULT COLON block 								{dbg("case_expression: default: block")}

/* <<<<<<<<<<<------ Switch statement ------>>>>>>>>>>> */

/* >>>>>>>>>>>------ If statement ------<<<<<<<<<<< */

if_operator:
			IF LBRACKET_ROUND expression RBRACKET_ROUND single_block %prec NO_ELSE	 	 {dbg("if_operator: if (expression) block")}
			| IF LBRACKET_ROUND expression RBRACKET_ROUND single_block ELSE single_block {dbg("if_operator: if (expression) single_stat_blck else single_stat_blck")}

single_block:
			expression END_OP									{dbg("single_block: a + 0;")}

			| LBRACKET_CURLY block RBRACKET_CURLY				{dbg("single_block: { block }")}

			| LBRACKET_CURLY RBRACKET_CURLY						{dbg("single_block: { }")}

			| literal_string COLON single_block 				{dbg("single_block: label")}

			| operators 										{dbg("single_block: operators")}

/* <<<<<<<<<<<------ If statement ------>>>>>>>>>>> */


/* >>>>>>>>>>>------ Variable initialization ------<<<<<<<<<<< */

var_init:
			VAR var												{dbg("var_init: var a...; (local variable)")}
			| VAR literal_string 								{dbg("var_init: var a")}
			| assign_expression COMA var						{dbg("var_init: a...; (global variable)")}

var:
			var COMA literal_string								{dbg("var: ...a")}
			| assign_expression 								{dbg("var_init: a = 0;")}
			| var COMA assign_expression 						{dbg("var_init: a = 0, ...")}


/* <<<<<<<<<<<------ Variable initialization ------>>>>>>>>>>> */

/* >>>>>>>>>>>------ Expressions ------<<<<<<<<<<< */

expression: 
			// expr in brackets
			//| LBRACKET_ROUND expression RBRACKET_ROUND DOT refinements_and_calls 	{dbg("(expr).f(). ...")	}
			
			////------ expression operands end

			LBRACKET_ROUND expression RBRACKET_ROUND			{dbgCoExpr("expression: (a+0)")}

			| assign_expression									{dbgCoExpr("expression: assign_expression")}
			| binary_expression 								{dbgCoExpr("expression: binary_expression")}
			| ternary_expression 								{dbgCoExpr("expression: ternary_expression")}
			| unary_expression									{dbgCoExpr("expression: unary_expression")}
			| new_expression 									{dbgCoExpr("expression: new_expression")}
			| delete_expression 								{dbgCoExpr("expression: delete_expression")}

			| obj_and_method 									{dbgCoExpr("expression: obj_and_method")}

			| literal_number 									{dbgCoExpr("expression: literal_number")}
			| constant_string 									{dbgCoExpr("expression: constant_string")}
			//| literal_string 									{dbgCoExpr("expression: literal_string")}

			| empty_expression 									{dbgCoExpr("expression: empty_expression")}

			| useful_words										{dbgCoExpr("expression: useful_words")}

assign_expression:
			object OP_ASSIGN expression 						{dbg("assign_expression: this.a = 0")}

new_expression:
			NEW expression 										{dbg("new_expression: new a()")}

delete_expression:
			DELETE object;

empty_expression:
			{dbg("empty_expression: ;")}

useful_words:
			NUL 												{dbg("useful_words: null")}
			| TRUE 												{dbg("useful_words: true")}
			| FALSE 											{dbg("useful_words: false")}
			| UNDEFINED 										{dbg("useful_words: undefined")}
			| NAN 												{dbg("useful_words: NaN")}
			| INFINITY 											{dbg("useful_words: Infinity")}

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

/* >>>>>>>>>>>------ Objects ------<<<<<<<<<<< */

obj_and_method:
			object LBRACKET_ROUND parameters RBRACKET_ROUND {dbg("obj_and_method: f(expr)")}
			| object

parameters:
			expression 											{dbg("parameters: 1")}
			| parameters COMA expression 						{dbg("parameters: ... , 1")}

object:
			literal_string	 									{dbg("object: a")}
			| object DOT literal_string							{dbg("object: ... .a")}
			| THIS DOT literal_string 							{dbg("object: this.a")}

/* <<<<<<<<<<<------ Objects ------>>>>>>>>>>> */

/* <<<<<<<<<<<------ Expressions ------>>>>>>>>>>> */

			
/////////////////--------------- literals

literal_string : OBJ_NAME 						{dbg("Literal string")	}
constant_string: CSTRING 						{dbg("Constant string");}
literal_number: LITERAL_NUMBER 					{dbg("Literal number")	}

/////////////////--------------- literals

%%

void yyYaccInit() {}
void yyYaccCleanup() {}