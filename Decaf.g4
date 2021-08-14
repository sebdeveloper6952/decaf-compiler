grammar Decaf;

/*
 * Parser Rules
 */
program: 'class' 'Program' '{' (declaration)* '}' EOF;

declaration:
	structDeclaration
	| varDeclaration
	| methodDeclaration;

varDeclaration: varType ID ';' | varType ID '[' NUM ']' ';';

structDeclaration: 'struct' ID '{' (varDeclaration)* '}' ';';

varType:
	'int'
	| 'char'
	| 'boolean'
	| 'struct' ID
	| structDeclaration
	| 'void';

methodType: 'int' | 'char' | 'boolean' | 'void';
methodDeclaration:
	methodType ID '()' block
	| methodType ID '(' (parameter (',' parameter)*)? ')' block;

parameter: parameterType ID;

parameterType: 'int' | 'char' | 'boolean';

block: '{' (varDeclaration)* (statement)* '}';

statement:
	'if' '(' expression ')' block ('else' block)?
	| 'while' '(' expression ')' block
	| 'return' expression? ';'
	| methodCall ';'
	| block
	| location '=' expression
	| expression? ';';

location: (ID | ID '[' expression ']') ('.' location)?;

expression:
	location									# expr_loc
	| methodCall								# expr_method_call
	| literal									# expr_literal
	| expression ('*' | '/' | '%') expression	# expr_arith_0
	| expression ('+' | '-') expression			# expr_arith_1
	| expression rel_op expression				# expr_rel
	| expression eq_op expression				# expr_eq
	| expression cond_op expression				# expr_cond
	| '-' expression							# expr_neg
	| '!' expression							# expr_not
	| '(' expression ')'						# expr_par;

methodCall: ID '(' (expression (',' expression)?)* ')';

arith_op: '*' | '/' | '%' | '+' | '-';

rel_op: '<' | '>' | '<=' | '>=';

eq_op: '==' | '!=';

cond_op: '&&' | '||';

literal: int_literal | char_literal | bool_literal;

int_literal: NUM;

char_literal: APOSTROPHE CHAR APOSTROPHE;

bool_literal: TRUE | FALSE;

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

NUM: DIGIT DIGIT*;

APOSTROPHE: '\'';

CHAR: [a-zA-Z0-9];

WHITESPACE: [ \t\r\n] -> skip;