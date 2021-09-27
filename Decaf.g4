grammar Decaf;

/*
 * Lexer Rules
 */
fragment ALPHA: [a-zA-Z_];

fragment DIGIT: [0-9];

fragment ALPHA_NUM: ALPHA | DIGIT;

fragment LETTER: [a-zA-Z];

CLASS: 'class';
PROGRAM: 'Program';
STRUCT: 'struct';
TRUE: 'true';
FALSE: 'false';
IF: 'if';
ELSE: 'else';
VOID: 'void';
ID: ALPHA ALPHA_NUM*;
CHAR: '\'' LETTER '\'';
NUM: DIGIT DIGIT*;
WHITESPACE: [ \t\r\n] -> skip;
COMMENT: '//' ~('\r' | '\n')+ -> skip;

/*
 * Parser Rules
 */

program: 'class' 'Program' '{' (declaration)* '}' EOF;

declaration:
	structDeclaration
	| varDeclaration
	| methodDeclaration;

varDeclaration:
	varType ID ';'						# var_decl
	| varType ID '[' NUM ']' ';'		# var_arr_decl
	| 'struct' ID ID ('[' NUM ']')? ';'	# var_struct_decl;

structDeclaration: 'struct' ID '{' (varDeclaration)* '}' ';';

varType: 'int' | 'char' | 'bool' | 'void';

methodType: 'int' | 'char' | 'bool' | 'void';
methodDeclaration:
	methodType ID '(' (parameter (',' parameter)*)? ')' block;

parameter: parameterType ID;

parameterType: 'int' | 'char' | 'bool';

block: '{' (varDeclaration)* (statement)* '}';

statement:
	'if' '(' expression ')' block ('else' block)?	# st_if
	| 'while' '(' expression ')' block				# st_while
	| 'return' expression? ';'						# st_return
	| methodCall ';'								# st_method_call
	| block											# st_block
	| location '=' expression						# st_assignment
	| expression? ';'								# st_expression;

location:
	ID ('[' expression ']')? '.' location	# loc_member
	| ID '[' expression ']'					# loc_array
	| ID									# loc_var;

expression:
	methodCall									# expr_method_call
	| location									# expr_loc
	| literal									# expr_literal
	| '-' expression							# expr_neg
	| expression ('*' | '/' | '%') expression	# expr_arith_0
	| expression ('+' | '-') expression			# expr_arith_1
	| '!' expression							# expr_not
	| expression rel_op expression				# expr_rel
	| expression eq_op expression				# expr_eq
	| expression cond_op expression				# expr_cond
	| '(' expression ')'						# expr_par;

methodCall: ID '(' (expression (',' expression)*)? ')';

rel_op: '<' | '>' | '<=' | '>=';

eq_op: '==' | '!=';

cond_op: '&&' | '||';

literal: int_literal | char_literal | bool_literal;

int_literal: NUM;

char_literal: CHAR;

bool_literal: TRUE | FALSE;
