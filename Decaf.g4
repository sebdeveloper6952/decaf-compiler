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

NUM: DIGIT DIGIT*;

APOSTROPHE: '\'';

CHAR_LITERAL: APOSTROPHE (LETTER | [\\\t\n]) APOSTROPHE;

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
	location
	| methodCall
	| literal
	| expression ('*' | '/' | '%') expression
	| expression ('+' | '-') expression
	| expression rel_op expression
	| expression eq_op expression
	| expression cond_op expression
	| '-' expression
	| '!' expression
	| '(' expression ')';

methodCall:
	ID '()'
	| ID '(' expression ')'
	| ID '(' expression (',' expression)+ ')';

arith_op: '*' | '/' | '%' | '+' | '-';

rel_op: '<' | '>' | '<=' | '>=';

eq_op: '==' | '!=';

cond_op: '&&' | '||';

literal: int_literal | char_literal | bool_literal;

int_literal: NUM;

char_literal: '\'' CHAR_LITERAL '\'';

bool_literal: TRUE | FALSE;

WHITESPACE: [\t\r\n ] -> skip;