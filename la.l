%{
/*
	Used for lexical analyzer!
*/
#include "struct.h"
#include "y.tab.h"

#include <stdio.h>
#include <string.h>

Node* createNode(char*, char*);
%}

int	 [0-9]+|0x[0-9A-F]+
id 	 [_a-zA-Z][_a-zA-Z0-9]*

b ;;

unaryop  \+\+|!|\-\-|~ 

%%
\!= {
	printf("NOTEQU: %s_\n", yytext);
	yylval.node = createNode("NOTEQU", yytext);
	return NOTEQU;
}
== {
	printf("EQU: %s_\n", yytext);
	yylval.node = createNode("EQU", yytext);
	return EQU;
}

"<<=" {
	printf("SHLEFTAN: %s_\n", yytext);
	yylval.node = createNode("SHLEFTAN", yytext);
	return SHLEFTAN;
}

">>=" {
	printf("SHRIGHTAN: %s_\n", yytext);
	yylval.node = createNode("SHRIGHTAN", yytext);
	return SHRIGHTAN;
}

"<<" {
	printf("SHLEFT: %s_\n", yytext);
	yylval.node = createNode("SHLEFT", yytext);
	return SHLEFT;
}

">>" {
	printf("SHRIGHT: %s_\n", yytext);
	yylval.node = createNode("SHRIGHT", yytext);
	return SHRIGHT;
}
\+\+ {
	printf("INCR: %s_\n", yytext);
	yylval.node = createNode("INCR", yytext);
	return INCR;
}
\-\- {
	printf("DECR: %s_\n", yytext);
	yylval.node = createNode("DECR", yytext);
	return DECR;
}
&= {
	printf("BANDAN: %s_\n", yytext);
	yylval.node = createNode("BANDAN", yytext);
	return BANDAN;
}

\^= {
	printf("BXORAN: %s_\n", yytext);
	yylval.node = createNode("BXORAN", yytext);
	return BXORAN;
}

\|= {
	printf("BORAN: %s_\n", yytext);
	yylval.node = createNode("BORAN", yytext);
	return BORAN;
}

\+= {
	printf("PLUSAN: %s_\n", yytext);
	yylval.node = createNode("PLUSAN", yytext);
	return PLUSAN;
}

\-= {
	printf("MINUSAN: %s_\n", yytext);
	yylval.node = createNode("MINUSAN", yytext);
	return MINUSAN;
}

\*= {
	printf("PRODUCTAN: %s_\n", yytext);
	yylval.node = createNode("PRODUCTAN", yytext);
	return PRODUCTAN;
}

\/= {
	printf("DIVISIONAN: %s_\n", yytext);
	yylval.node = createNode("DIVISIONAN", yytext);
	return DIVISIONAN;
}
"<=" {
	printf("LESSEQU: %s_\n", yytext);
	yylval.node = createNode("LESSEQU", yytext);
	return LESSEQU;
}
">=" {
	printf("GREATEREQU: %s_\n", yytext);
	yylval.node = createNode("GREATEREQU", yytext);
	return GREATEREQU;
}
&& {
	printf("LOGAND: %s_\n", yytext);
	yylval.node = createNode("LOGAND", yytext);
	return LOGAND;
}
\|\| {
	printf("LOGOR: %s_\n", yytext);
	yylval.node = createNode("LOGOR", yytext);
	return LOGOR;
}

\! {
	printf("LOGNOT: %s_\n", yytext);
	yylval.node = createNode("LOGNOT", yytext);
	return LOGNOT;
}

\+ {
	printf("PLUS: %s_\n", yytext);
	yylval.node = createNode("PLUS", yytext);
	return PLUS;
}
\- {
	printf("MINUS: %s_\n", yytext);
	yylval.node = createNode("MINUS", yytext);
	return MINUS;
}
\* {
	printf("PRODUCT: %s_\n", yytext);
	yylval.node = createNode("PRODUCT", yytext);
	return PRODUCT;
}
\/ {
	printf("DIVISION: %s_\n", yytext);
	yylval.node = createNode("DIVISION", yytext);
	return DIVISION;
}
% {
	printf("MOD: %s_\n", yytext);
	yylval.node = createNode("MOD", yytext);
	return MOD;
}
& {
	printf("BAND: %s_\n", yytext);
	yylval.node = createNode("BAND", yytext);
	return BAND;
}
\^ {
	printf("BXOR: %s_\n", yytext);
	yylval.node = createNode("BXOR", yytext);
	return BXOR;
}
\| {
	printf("BOR: %s_\n", yytext);
	yylval.node = createNode("BOR", yytext);
	return BOR;
}
~ {
	printf("BNOT: %s_\n", yytext);
	yylval.node = createNode("BNOT", yytext);
	return BNOT;
}
\< {
	printf("LESS: %s_\n", yytext);
	yylval.node = createNode("LESS", yytext);
	return LESS;
}

\> {
	printf("GREATER: %s_\n", yytext);
	yylval.node = createNode("GREATER", yytext);
	return GREATER;
}
; {
	printf("SEMI: %s_\n", yytext);
	yylval.node = createNode("SEMI", yytext);
	return SEMI;
}

, {
	printf("COMMA: %s_\n", yytext);
	yylval.node = createNode("COMMA", yytext);
	return COMMA;
}

\. {
	printf("DOT: %s_\n", yytext);
	yylval.node = createNode("DOT", yytext);
	return DOT;
}

= {
	printf("ASSIGNOP: %s_\n", yytext);
	yylval.node = createNode("ASSIGNOP", yytext);
	return ASSIGNOP;
}

int {
	printf("TYPE: %s_\n", yytext);
	yylval.node = createNode("TYPE", yytext);
	return TYPE;
}

\( {
	printf("LP: %s_\n", yytext);
	yylval.node = createNode("LP", yytext);
	return LP;
}

\) {
	printf("RP: %s_\n", yytext);
	yylval.node = createNode("RP", yytext);
	return RP;
}

\[ {
	printf("LB: %s_\n", yytext);
	yylval.node = createNode("LB", yytext);
	return LB;
}

\] {
	printf("RB: %s_\n", yytext);
	yylval.node = createNode("RB", yytext);
	return RB;
}


\{ {
	printf("LC: %s_\n", yytext);
	yylval.node = createNode("LC", yytext);
	return LC;
}

\} {
	printf("RC: %s_\n", yytext);
	yylval.node = createNode("RC", yytext);
	return RC;
}

struct {
	printf("STRUCT: %s_\n", yytext);
	yylval.node = createNode("STRUCT", yytext);
	return STRUCT;
}

return {
	printf("RETURN: %s_\n", yytext);
	yylval.node = createNode("RETURN", yytext);
	return RETURN;
}

if {
	printf("IF: %s_\n", yytext);
	yylval.node = createNode("IF", yytext);
	return IF;
}

else {
	printf("ELSE: %s_\n", yytext);
	yylval.node = createNode("ELSE", yytext);
	return ELSE;
}

break {
	printf("BREAK: %s_\n", yytext);
	yylval.node = createNode("BREAK", yytext);
	return BREAK;
}

continue {
	printf("CONT: %s_\n", yytext);
	yylval.node = createNode("CONT", yytext);
	return CONT;
}

for {
	printf("FOR: %s_\n", yytext);
	yylval.node = createNode("FOR", yytext);
	return FOR;
}



{int} {
	printf("INT: %s_\n", yytext);
	yylval.node = createNode("INT", yytext);
	return INT;
}


{id} {
	printf("ID: %s_\n", yytext);
	yylval.node = createNode("ID", yytext);
	return ID;
}


%%
Attr initAttr() {
	Attr ret;
	ret.space = 0;
	ret.isLeft = 0;
	return ret;
}

Node* initNode() {
	Node* ret;
	ret = malloc(sizeof(Node));

	ret->attr = initAttr();
	return ret;
}

int yywrap(void)
{
	printf("yywrap\n");
	return 1;
}

Node* createNode(char* token, char* content) {
	Node * res;
	res = malloc(sizeof(Node));
	res->attr = initAttr();
	
	res->content = strdup(content);
	res->token = strdup(token);
	res->next = NULL;
	res->child = NULL;

	return res;
}

