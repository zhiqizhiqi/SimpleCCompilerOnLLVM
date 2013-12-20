%{
/*
	Used for the syntax analyzer
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "struct.h"
#define YYDEBUG 1
#define CODE_LENGTH 250
#define TYPE_NUMBER 10
#define ID_NUMBER 100

typedef char* string;
typedef struct _TYPE {
	char* type;
	char* name;
	struct _TYPE* next;
} Type;
typedef struct _IDENTIFIER {
	char* id;
	char* type;
	int space;
	int isPara;
} Identifier;
typedef struct _STRUCT_CONTENT {
	char* type;
	char* name;
	struct _STRUCT_CONTENT* next;
} StructContent;

Node *head;
Node* Record(char *, ...);
Type** types;
Identifier* ids;

int ptr_types = 0;
int ptr_ids = 0;
int counter = 0;

char* file_out_name;
FILE *fout;

extern int yydebug; %}

%union {
	Node *node;
};

%token <node> ASSIGNOP TYPE
%token <node> LC RC
%token <node> STRUCT RETURN 
%token <node> IF ELSE BREAK CONT FOR
%token <node> INT ID SEMI COMMA

%token <node> LP RP LB RB DOT
%token <node> LOGNOT INCR DECR BNOT
%token <node> MOD PRODUCT DIVISION
%token <node> PLUS MINUS
%token <node> SHLEFT SHRIGHT
%token <node> GREATER GREATEREQU LESS LESSEQU
%token <node> EQU NOTEQU
%token <node> BAND
%token <node> BXOR
%token <node> BOR
%token <node> LOGAND
%token <node> LOGOR
%token <node> PLUSAN MINUSAN PRODUCTAN DIVISIONAN BANDAN BXORAN BORAN SHLEFTAN SHRIGHTAN

%type <node> PROGRAM EXTDEFS EXTDEF EXTVARS SPEC STSPEC OPTTAG
%type <node> VAR FUNC PARAS PARA STMTBLOCK STMTS STMT ESTMT
%type <node> DEFS DEF DECS DEC INIT EXP ARRS ARGS
%start PROGRAM

%right PLUSAN MINUSAN PRODUCTAN DIVISIONAN BANDAN BXORAN BORAN SHLEFTAN SHRIGHTAN ASSIGNOP
%left LOGOR
%left LOGAND
%left BOR
%left BXOR
%left BAND
%left EQU NOTEQU
%left GREATER GREATEREQU LESS LESSEQU
%left SHLEFT SHRIGHT
%left PLUS MINUS
%left MOD PRODUCT DIVISION
%right LOGNOT INCR DECR BNOT
%left LP RP LB RB DOT

%%
PROGRAM:
	EXTDEFS					{$$ = Record("PROGRAM", $1, NULL);}
	;

EXTDEFS:
	EXTDEF EXTDEFS			{$$ = Record("EXTDEFS", $1, $2, NULL);}
	| 						{$$ = Record("EXTDEFS", NULL);}
	;

EXTDEF:
	SPEC EXTVARS SEMI		{$$ = Record("EXTDEF", $1, $2, $3, NULL);}
	| SPEC FUNC STMTBLOCK	{$$ = Record("EXTDEF", $1, $2, $3, NULL);}
	;

EXTVARS:
	DEC 					{$$ = Record("EXTVARS", $1, NULL);}
	| DEC COMMA EXTVARS		{$$ = Record("EXTVARS", $1, $2, $3, NULL);}
	| 						{$$ = Record("EXTVARS", NULL);}
	;

SPEC:
	TYPE 					{$$ = Record("SPEC", $1, NULL);}
	| STSPEC				{$$ = Record("SPEC", $1, NULL);}
	;

STSPEC:
	STRUCT OPTTAG LC DEFS RC 	{$$ = Record("STSPEC", $1, $2, $3, $4, $5, NULL);}
	| STRUCT ID 				{$$ = Record("STSPEC", $1, $2, NULL);}
	;

OPTTAG:
	ID 						{$$ = Record("OPTTAG", $1, NULL);}
	| 						{$$ = Record("OPTTAG", NULL);}
	;

VAR:
	ID 						{$$ = Record("VAR", $1, NULL);}
	| VAR LB INT RB			{$$ = Record("VAR", $1, $2, $3, $4, NULL);}
	;

FUNC:
	ID LP PARAS RP			{$$ = Record("FUNC", $1, $2, $3, $4, NULL);}
	;

PARAS:
	PARA COMMA PARAS		{$$ = Record("PARAS", $1, $2, $3, NULL);}
	| PARA 					{$$ = Record("PARAS", $1, NULL);}
	| 						{$$ = Record("PARAS", NULL);}
	;

PARA:
	SPEC VAR 				{$$ = Record("PARA", $1, $2, NULL);}
	;

STMTBLOCK:
	LC DEFS STMTS RC 		{$$ = Record("STMTBLOCK", $1, $2, $3, $4, NULL);}
	;

STMTS:
	STMT STMTS				{$$ = Record("STMTS", $1, $2, NULL);}
	|						{$$ = Record("STMTS", NULL);}
	;

STMT:
	EXP SEMI				{$$ = Record("STMT", $1, $2, NULL);}
	| STMTBLOCK				{$$ = Record("STMT", $1, NULL);}
	| RETURN EXP SEMI 		{$$ = Record("STMT", $1, $2, $3, NULL);}
	| IF LP EXP RP STMT ESTMT	{$$ = Record("STMT", $1, $2, $3, $4, $5, $6, NULL);}
	| FOR LP EXP SEMI EXP SEMI EXP RP STMT 		{$$ = Record("STMT", $1, $2, $3, $4, $5, $6, $7, $8, $9, NULL);}
	| CONT SEMI				{$$ = Record("STMT", $1, $2, NULL);}
	| BREAK SEMI			{$$ = Record("STMT", $1, $2, NULL);}
	;

ESTMT:
	ELSE STMT				{$$ = Record("ESTMT", $1, $2, NULL);}
	| 						{$$ = Record("ESTMT", NULL);}
	;

DEFS:
	DEF DEFS				{$$ = Record("DEFS", $1, $2, NULL);}
	| 						{$$ = Record("DEFS", NULL);}
	;

DEF:
	SPEC DECS SEMI			{$$ = Record("DEF", $1, $2, $3, NULL);}
	;

DECS:
	DEC COMMA DECS			{$$ = Record("DECS", $1, $2, $3, NULL);}
	| DEC 					{$$ = Record("DECS", $1, NULL);}
	;

DEC:
	VAR 					{$$ = Record("DEC", $1, NULL);}
	| VAR ASSIGNOP INIT		{$$ = Record("DEC", $1, $2, $3, NULL);}
	;

INIT:
	EXP						{$$ = Record("INIT", $1, NULL);}
	| LC ARGS RC 			{$$ = Record("INIT", $1, $2, $3, NULL);}
	;
EXP:
	ID 						{$$ = Record("EXP", $1, NULL);}
	| EXP PLUS EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP MINUS EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP PRODUCT EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP DIVISION EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP PLUSAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP MINUSAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP PRODUCTAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP DIVISIONAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP MOD EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP SHLEFT EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP SHRIGHT EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP GREATER EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP GREATEREQU EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP LESS EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP LESSEQU EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP EQU EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP NOTEQU EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP BAND EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP BXOR EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP BOR EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP LOGAND EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP LOGOR EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP BANDAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP BXORAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP BORAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP SHLEFTAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP SHRIGHTAN EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP DOT EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| EXP ASSIGNOP EXP		{$$ = Record("EXP", $1, $2, $3, NULL);}
	| MINUS EXP			{$$ = Record("EXP", $1, $2, NULL);}
	| INCR EXP			{$$ = Record("EXP", $1, $2, NULL);}
	| DECR EXP			{$$ = Record("EXP", $1, $2, NULL);}
	| BNOT EXP			{$$ = Record("EXP", $1, $2, NULL);}	
	| LOGNOT EXP			{$$ = Record("EXP", $1, $2, NULL);}
	| LP EXP RP				{$$ = Record("EXP", $1, $2, $3, NULL);}
	| ID LP ARGS RP			{$$ = Record("EXP", $1, $2, $3, $4, NULL);}
	| ID ARRS				{$$ = Record("EXP", $1, $2, NULL);}
	| INT 					{$$ = Record("EXP", $1, NULL);}
	|						{$$ = Record("EXP", NULL);}
	;

ARRS:
	LB EXP RB ARRS			{$$ = Record("ARRS", $1, $2, $3, $4, NULL);}
	|						{$$ = Record("ARRS", NULL);}
	;

ARGS:
	EXP COMMA ARGS			{$$ = Record("ARGS", $1, $2, $3, NULL);}
	| EXP					{$$ = Record("ARGS", $1, NULL);}
	;

%%
void errorOccur(char* msg);

char* getVAR_ID(Node* n);
char* getID_eliminatePara(char* id);
void pop_ids(int);
char* getID_type(char* id);
int getID_space(char* id);
void printIDS();
char* get_TMP();
int isTypeExist(char* type);
void addTypeIntoStruct(int i, char* type, char* name);
StructContent* getStructContent(Node* n);

void code_PROGRAM(Node *n);
void code_EXTDEFS(Node* n);
void code_EXTDEF(Node* n);
void code_EXTVARS(Node* n, char* type);
char* code_SPEC(Node* n);
char* code_STSPEC(Node* n);
void code_DEC(Node* n, char* type);
char* code_EXP(Node* n);
char* code_FUNC(Node* n);
char* code_PARAS(Node* n);
char* code_PARA(Node* n, int mode);
void code_STMTBLOCK(Node* n);
void code_DEFS(Node* n);
void code_DEF(Node* n);
void code_DECS(Node* n, char* type);
void code_STMTS(Node* n);
void code_STMT(Node* n);
void code_ESTMT(Node* n);
char* code_ARGS(Node* n);
char* code_ARRS(Node* n);
char* code_OPTTAG(Node* n);
void deal_with_read(Node* n);
void deal_with_write(Node* n);
void codeGenerator(Node *n);

void walkGraph(Node* n, int layer) {
	fprintf(fout, "%*s_%d", layer*10, n->token, n->attr.space);
	if (n->content != NULL) fprintf(fout, "_%s_%d", n->content, n->attr.space);

	if (n->child != NULL) {
		fprintf(fout, ":\n");
		walkGraph(n->child, layer+1);
	}
	else fprintf(fout, "\n");
	if (n->next != NULL) walkGraph(n->next, layer);

	return;
}

StructContent* getStructContent(Node* n){	// n is a DEFS node
	n = n->child;
	StructContent *ret, *tail;
	ret = (StructContent*) malloc(sizeof(StructContent));
	ret->next = NULL;
	tail = ret;
	while (n != NULL) {	// n is a DEF node
		Node* tmp = n->child;		// SPEC DECS SEMI
		char* type = code_SPEC(tmp);

		//get ids
		tmp = tmp->next->child;		// DEC COMMA DECS | DEC
		while(1 == 1) {
			StructContent* sc_tmp;
			sc_tmp = (StructContent*) malloc(sizeof(StructContent));
			Node* var = tmp->child;
			char* var_id = getVAR_ID(var);
			sc_tmp->type = strdup(type);
			sc_tmp->name = strdup(var_id);
			sc_tmp->next = NULL;
			tail->next = sc_tmp;
			tail = sc_tmp;
			if (tmp->next == NULL) break;
			tmp = tmp->next->next->child;
		}
		//free(type);
		n = n->next->child;
	}

	return ret;
}

void addTypeIntoStruct(int i, char* type, char* name){
	if (i>=ptr_types) return;
	Type* t;
	t = types[i];

	while(t->next != NULL) t = t->next;
	Type* new;
	new = (Type*) malloc(sizeof(Type));
	new->type = strdup(type);
	new->name = strdup(name);
	new->next = NULL;
	t->next = new;
	return;
}

int isTypeExist(char* type) {
	int i;
	for (i = 0; i < ptr_types; ++i) {
		if (strcmp(type, types[i]->type) == 0) return i;
	}
	return -1;
}

char* get_TMP() {
	char* ret;
	ret = malloc(sizeof(char)*50);
	sprintf(ret, "%%tmp_%d", counter++);
	return ret;
}

char* getID_type(char* id) {
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if (strcmp(id, ids[i].id) == 0)
			return ids[i].type;
	}
	return "i32";
}
int getID_space(char* id) {
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if (strcmp(id, ids[i].id) == 0)
			return ids[i].space;
	}
	return 0;	
}

void updateAttr(Node* n, Attr attr) {
	n->attr = attr;
	n = n->child;
	while (n!=NULL) {
		updateAttr(n, attr);
		n = n->next;
	}
	return;
}

void record_ids(char* var_id, char* type, int space, int isPara) {
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if (strcmp(var_id, ids[i].id) == 0) {
			char* msg;
			msg = (char*) malloc(sizeof(char)*100);
			sprintf(msg, "variable \"%s\" occur multi-times.", var_id);
			errorOccur(msg);
		}
	}
	ids[ptr_ids].id = strdup(var_id);
	ids[ptr_ids].type = strdup(type);
	ids[ptr_ids].space = space;
	ids[ptr_ids].isPara = isPara;
	ptr_ids += 1;
	return;
}

void pop_ids(int space){
	while (ids[ptr_ids-1].space == space) {
		ptr_ids -= 1;
	}
	return;
}

void deal_with_read(Node* n) {
	n = n->child;
	Attr attr = {n->attr.space, 1};
	n->next->next->attr =  attr;
	char* args_code = code_ARGS(n->next->next);
	char ret[CODE_LENGTH] = "";
	sprintf(ret, "%%call%d", counter++);
	fprintf(fout, "%s = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), %s)\n", ret, args_code);
	return;
}

void deal_with_write(Node* n){
	n = n->child;
	char* args_code = code_ARGS(n->next->next);
	char ret[CODE_LENGTH] = "";
	sprintf(ret, "%%call%d", counter++);
	fprintf(fout, "%s = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), %s)\n", ret, args_code);
	return;	
}

void code_PROGRAM(Node* n) {
	//printf("PROGRAM\n");
	char* code;
	code = strdup(";author ZZQ\n");
	strcat(code, "@.str = private unnamed_addr constant [3 x i8] c\"%d\\00\", align 1\n");
	strcat(code, "@.str1 = private unnamed_addr constant [4 x i8] c\"%d\\0A\\00\", align 1\n");
	strcat(code, "declare i32 @printf(i8*, ...)\n");
	strcat(code, "declare i32 @__isoc99_scanf(i8*, ...)\n");
	fprintf(fout, "%s", code);
	code_EXTDEFS(n->child);
	return;
}

void code_EXTDEFS(Node* n) {
	//printf("EXTDEFS\n");
	if (n->child == NULL) return;
	n = n->child;         //EXTDEF EXTDEFS
	code_EXTDEF(n);
	code_EXTDEFS(n->next);
	return;
}

void code_EXTDEF(Node* n) {
	//printf("EXTDEF\n");
	n = n->child;
	char* type;
	char code[CODE_LENGTH] = "";

	type = code_SPEC(n);
	n = n->next;
	if (strcmp(n->token, "EXTVARS") == 0) {
		code_EXTVARS(n, type);
	}
	else {     //FUNC
		Attr tmp_attr = {n->attr.space+1};
		updateAttr(n, tmp_attr);
		updateAttr(n->next, tmp_attr);
		char tmp[CODE_LENGTH] = "";
		sprintf(tmp, "define %s ", type);
		strcat(code, tmp);
		strcat(code, code_FUNC(n));

		fprintf(fout, "%s", code);
		code_STMTBLOCK(n->next);
		fprintf(fout, "}\n");

		pop_ids(n->attr.space);
	}
	return;
}

void code_EXTVARS(Node* n, char* type) {
	//printf("EXTVARS\n");
	n = n->child;
	while (n!= NULL){
		if (strcmp(n->token, "DEC") == 0) code_DEC(n, type);
		else if (strcmp(n->token, "EXTVARS") == 0) code_EXTVARS(n, type);
		else {}
		n = n->next;
	}
	return;	
}

char* code_SPEC(Node* n) {
	//printf("SPEC\n");
	char* code = "";
	n = n->child;
	if (strcmp(n->token, "TYPE")==0) return "i32";
	else return code_STSPEC(n); //STSPEC
}

char* code_STSPEC(Node* n) {
	//printf("STSPECT\n");
	n = n->child;
	char *ret, *code;
	ret = (char*) malloc(sizeof(char)*CODE_LENGTH);
	code = (char*) malloc(sizeof(char)*CODE_LENGTH);
	sprintf(ret, "");
	sprintf(code, "");

	if (strcmp(n->next->token, "ID") == 0) {				// STRUCT ID
		char* s_id = n->next->content;
		sprintf(ret, "%%struct.%s", s_id);
	}
	else {													// STRUCT OPTTAG LC DEFS RC
		int org_ptr = ptr_types++;
		char* opttag = code_OPTTAG(n->next);
		StructContent* sc = getStructContent(n->next->next->next);
		types[org_ptr] = (Type*) malloc(sizeof(Type));
		types[org_ptr]->type = (char*) malloc(sizeof(char)* 150);
		types[org_ptr]->next = NULL;
		sprintf(types[org_ptr]->type, "%%struct.%s", opttag);
		ret = strdup(types[org_ptr]->type);
		sprintf(code, "%s = type {", ret);
		sc = sc->next;
		while (sc != NULL) {
			addTypeIntoStruct(org_ptr, sc->type, sc->name);
			strcat(code, sc->type);
			strcat(code, ",");
			StructContent* tmp = sc;
			sc = sc->next;
			//free(tmp);
		}
		code[strlen(code)-1] = '\0';
		strcat(code, "}\n");
	}

	fprintf(fout, "%s", code);
	return ret;
} 

char* code_OPTTAG(Node* n) {		// ID | nothing
	n = n->child;
	return n->content;
}

void code_VAR(Node* n) {
	
}

char* code_FUNC(Node* n) {
	n = n->child;
	char* ret_code;
	ret_code = (char*)malloc(sizeof(char)*CODE_LENGTH);
	char* func_id = n->content;
	char* paras = code_PARAS(n->next->next);
	sprintf(ret_code, "@%s(%s", func_id, paras);
	return ret_code;
}

char* code_PARAS(Node* n) {
	char* ret_code;
	ret_code = (char*)malloc(sizeof(char)*CODE_LENGTH);

	char para_code[CODE_LENGTH] = "";
	char init_code[CODE_LENGTH] = "";
	while(1==1) {
		n = n->child;
		if (n == NULL) break;
		strcat(ret_code, code_PARA(n, 0));
		strcat(init_code, code_PARA(n, 1));
		if (n->next != NULL){
			strcat(ret_code, ", ");
			n = n->next->next;
		}
		else break;
	}
	strcat(ret_code, ") {\nentry:\n");
	strcat(ret_code, init_code);
	return ret_code;
}

char* code_PARA(Node* n, int mode) {
	n = n->child;
	char* ret_code;
	ret_code = (char*)malloc(sizeof(char)*CODE_LENGTH);
	char* type = code_SPEC(n);
	char* var_id = getVAR_ID(n->next);

	if (mode == 0)	{			// get parameter code
		sprintf(ret_code, "%s %%%s", type, var_id);
	}
	else {						// init parameter code
		sprintf(ret_code, "%%%s.addr = alloca i32, align 4\nstore i32 %%%s, i32* %%%s.addr, align 4\n", var_id, var_id, var_id);
		record_ids(var_id, type, n->attr.space, 1);
	}
	return ret_code;
}

void code_STMTBLOCK(Node* n) {
	n = n->child;
	char code[CODE_LENGTH] = "";
	n = n->next;  //DEFS
	code_DEFS(n);
	n = n->next;  //STMTS
	code_STMTS(n);
	return;
}

void code_STMTS(Node* n) {     // | STMT STMTS
	while (n->child != NULL) {
		n = n->child;    //STMT
		code_STMT(n);
		n = n->next;
	}
	return;	
}

void code_STMT(Node* n) {
	n = n->child;

	if (strcmp(n->token, "EXP") == 0)  {				// EXP SEMI
		char* exp_ret = code_EXP(n);
	}
	else if (strcmp(n->token, "STMTBLOCK") == 0) {		// STMTBLOCK
		code_STMTBLOCK(n);
	}
	else if (strcmp(n->token, "RETURN") == 0) {			// RETURN EXP SEMI
		char* exp_code = code_EXP(n->next);
		fprintf(fout, "ret i32 %s\n", exp_code);
	}
	else if (strcmp(n->token, "IF") == 0) {				// IF LP EXP RP STMT ESTMT
		char* exp_code = code_EXP(n->next->next);
		if (strcmp(n->next->next->attr.type, "i32") == 0) {
			char* reg = get_TMP();
			fprintf(fout, "%s = icmp ne i32 %s, 0\n", reg, exp_code);
			exp_code = reg;
		}
		else if (strcmp(n->next->next->attr.type, "i1") == 0) {}
		else errorOccur("The boolean expression in IF has a type error.");

		fprintf(fout, "br i1 %s, label %%if.then%d, label %%if.else%d\n\n", exp_code, counter, counter);
		int tmp_counter = counter++;
		fprintf(fout, "if.then%d:\n", tmp_counter);
		code_STMT(n->next->next->next->next);
		fprintf(fout, "br label %%if.end%d\n\n", tmp_counter);
		fprintf(fout, "if.else%d:\n", tmp_counter);
		code_ESTMT(n->next->next->next->next->next);
		fprintf(fout, "br label %%if.end%d\n\n", tmp_counter);
		fprintf(fout, "if.end%d:\n", tmp_counter);
	}
	else if (strcmp(n->token, "FOR") == 0) {			// FOR LP EXP SEMI EXP SEMI EXP RP STMT
		int tmp_counter = counter++;
		char* exp_code;
		n = n->next->next;				//first EXP
		exp_code = code_EXP(n);
		fprintf(fout, "br label %%for.cond%d\n\n", tmp_counter);
		fprintf(fout, "for.cond%d:\n", tmp_counter);
		n = n->next->next;				//second EXP
		exp_code = code_EXP(n);
		if (strcmp(n->attr.type, "i32") == 0) {
			char* reg = get_TMP();
			fprintf(fout, "%s = icmp ne i32 %s, 0\n", reg, exp_code);
			exp_code = reg;
		}
		else if (strcmp(n->attr.type, "i1") == 0) {}
		else errorOccur("The boolean expression in FOR-LOOP has a type error.");
		fprintf(fout, "br i1 %s, label %%for.body%d, label %%for.end%d\n\n", exp_code, tmp_counter, tmp_counter);
		fprintf(fout, "for.body%d:\n", tmp_counter);
		code_STMT(n->next->next->next->next);
		fprintf(fout, "br label %%for.inc%d\n\n", tmp_counter);
		fprintf(fout, "for.inc%d:\n", tmp_counter);
		exp_code = code_EXP(n->next->next);
		fprintf(fout, "br label %%for.cond%d\n\n", tmp_counter);
		fprintf(fout, "for.end%d:\n", tmp_counter);
	}
	else if (strcmp(n->token, "CONT") == 0) {			// CONT SEMI

	}
	else if (strcmp(n->token, "BREAK") == 0) {			// BREAK SEMI

	}
	else {}

	return;
}

void code_ESTMT(Node* n) {
	n = n->child;
	if (n == NULL) {					// nothing
	}
	else {								// ELSE STMT
		code_STMT(n->next);
	}
	return;
}

void code_DEFS(Node* n) {
	n = n->child;
	while(n != NULL) {
		code_DEF(n);
		n = n->next->child;
	}
	return;
}

void code_DEF(Node* n) {
	//printf("DEF\n");
	n = n->child;
	char* type;
	char code[CODE_LENGTH] = "";

	type = code_SPEC(n);
	n = n->next;          //DECS
	code_DECS(n, type);
	n = n->child;

}

void code_DECS(Node* n, char* type) {
	//printf("DECS\n");
	n = n->child;     //DEC
	while (n!= NULL){
		code_DEC(n, type);
		if (n->next != NULL) n = n->next->next->child;
		else break;
	}
	return;	
}

char* getID_eliminatePara(char* id){
	int i;
	for (i = 0; i < ptr_ids; ++i) {
		if ((strcmp(id, ids[i].id) == 0) && (ids[i].isPara == 1)){
			char* ret;
			ret = (char*)malloc(sizeof(char)*CODE_LENGTH);
			sprintf(ret, "%s.addr", id);
			return ret;
		}
	}
	return id;
}
char* getVAR_ID(Node* n){
	while(n != NULL) {
		if (strcmp(n->token, "ID") == 0) return getID_eliminatePara(n->content);
		n = n->child;
	}
	return "NULL";
}
char* getVAR_INDEX(Node* n){
	if (strcmp(n->child->token, "VAR") != 0) return "-1";
	return n->child->next->next->content;
}

void code_DEC(Node* n, char* type) {
	//printf("DEC\n");
	char code[CODE_LENGTH] = "";
	n = n->child;
	
	char* var_id = getVAR_ID(n);
	// record this variable
	// record_ids(var_id, type, n->attr.space, 0);

	//declare
	//printf("DEC.declare\n");
	char* res = getVAR_INDEX(n);
	char tmp[CODE_LENGTH] = "";
	if (strcmp(res, "-1") == 0) {    // is not array
		if (n->attr.space == 0) sprintf(tmp, "@%s = common global %s ", var_id, type);
		else sprintf(tmp, "%%%s = alloca %s, align 4\n", var_id, type);
		record_ids(var_id, type, n->attr.space, 0);
		//printf("get all\n");
	}
	else {           				// is array
		if (n->attr.space == 0) sprintf(tmp, "@%s = common global [%s x %s] ", var_id, res, type);
		else sprintf(tmp, "%%%s = alloca [%s x %s], align 4\n", var_id, res, type);
		char tmp[CODE_LENGTH] = "";
		sprintf (tmp, "%s x %s", res, type);
		record_ids(var_id, tmp, n->attr.space, 0);
	}
	strcat(code, tmp);

	//printf("__DEC.init__\n");
	//init
	if (n->next != NULL) {
		Node* init_node = n->next->next;
		if (strcmp(init_node->child->token, "EXP") == 0) {
			char* reg_name = code_EXP(init_node->child);
			if (n->attr.space == 0) sprintf(tmp, "%s, align 4\n", reg_name);
			else sprintf(tmp, "store i32 %s, i32* %%%s, align 4\n", reg_name, var_id);
			strcat(code, tmp);
		}
		else {   //list
			Node* args_node = init_node->child->next;
			int i = 0;
			//begin
			Node* exp_node = args_node->child;
			char* reg_name = code_EXP(exp_node);
			if (n->attr.space == 0) {
				sprintf(tmp, "[%s %s", type, reg_name);
			}
			else {
				sprintf(tmp, "%%array%s.d%d = getelementptr inbounds [%s x %s]* %%%s, i32 0, i32 0\n", var_id, i, res, type, var_id);
				strcat(code, tmp);
				sprintf(tmp, "store i32 %s, i32* %%array%s.d%d\n", reg_name, var_id, i);
			}
			strcat(code, tmp);
			while(exp_node->next != NULL) {
				//printf ("flag\n");
				exp_node = exp_node->next->next->child;
				i = i + 1;
				reg_name = code_EXP(exp_node);
				if (n->attr.space == 0) {
					sprintf(tmp, ", %s %s", type, reg_name);
				}
				else {
					sprintf(tmp, "%%array%s.d%d = getelementptr inbounds i32* %%array%s.d%d, i32 1\n", var_id, i, var_id, i-1);
					strcat(code, tmp);
					sprintf(tmp, "store i32 %s, i32* %%array%s.d%d\n", reg_name, var_id, i);
				}
				strcat(code, tmp);
			}
			if (n->attr.space == 0) strcat(code, "], align 4\n");	
		}
	}
	else {
		if (n->attr.space == 0) strcat(code, "zeroinitializer, align 4\n");	
	}
	fprintf(fout, "%s", code);
	return;	
}

void code_INIT(Node* n) {
	
}

// if EXP is a INT, return that INT
// else return the name of that register, which store the EXP result.
char* code_EXP(Node* n) {
	char* ret;
	ret = malloc(sizeof(char)*CODE_LENGTH);
	Node* org = n;
	n = n->child;
	if (n == NULL) {													// nothing
		sprintf(ret, "");
	}
	else if (strcmp(n->token, "ID") ==  0) {
		if (n->next == NULL) {											// ID
			char c;
			if (getID_space(n->content) == 0) c = '@';
			else c = '%';
			org->attr.type = strdup(getID_type(n->content));
			if (org->attr.isLeft == 0) {
				ret = get_TMP();
				fprintf(fout, "%s = load i32* %c%s, align 4\n", ret, c, getID_eliminatePara(n->content));
			}
			else {
				sprintf(ret, "%c%s", c, getID_eliminatePara(n->content));
				if (strcmp(org->attr.type, "i32") == 0) org->attr.type = strdup("i32*");
			}
		}
		else if (strcmp(n->next->token, "LP") == 0) {					// ID LP ARGS RP
			if (strcmp(n->content, "read") == 0) deal_with_read(org);
			else if (strcmp(n->content, "write") == 0) deal_with_write(org);
			else {
				char* args_code = code_ARGS(n->next->next);
				sprintf(ret, "%%call%d", counter++);
				fprintf(fout, "%s = call i32 @%s (%s)\n", ret, n->content, args_code);
			}
			org->attr.type = strdup("i32");	
		}
		else if (strcmp(n->next->token, "ARRS") == 0) {					// ID ARRS
			ret = get_TMP();
			char c;
			char* arrs_code;

			arrs_code = code_ARRS(n->next);
			if (getID_space(n->content) == 0) c = '@';
			else c = '%';
			if (org->attr.isLeft == 0) {
				char* reg = get_TMP();
				fprintf(fout, "%s = getelementptr inbounds [%s]* %c%s, i32 0, %s\n", reg, getID_type(n->content), c, getID_eliminatePara(n->content), arrs_code);
				fprintf(fout, "%s = load i32* %s, align 4\n", ret, reg);
				org->attr.type = strdup("i32");
			}
			else {
				fprintf(fout, "%s = getelementptr inbounds [%s]* %c%s, i32 0, %s\n", ret, getID_type(n->content), c, getID_eliminatePara(n->content), arrs_code);
				org->attr.type = strdup("i32*");
			}
		}
		else {}
	}
	else if (strcmp(n->token, "EXP") == 0) {
		ret = get_TMP();
		if (strcmp(n->next->token, "PLUS") == 0) {						// EXP PLUS EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"+\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = add i32 %s, %s \n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "MINUS") == 0) {				// EXP MINUS EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"-\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = sub i32 %s, %s\n", ret, opr1, opr2);	
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "PRODUCT") == 0) {				// EXP PRODUCT EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"*\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = mul i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "DIVISION") == 0) {				// EXP DIVISION EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"/\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = sdiv i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "MOD") == 0) {					// EXP MOD EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"%%\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = srem i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "BAND") == 0) {					// EXP BAND EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"&\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = and i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "BXOR") == 0) {					// EXP BXOR EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"^\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = xor i32 %s, %s\n", ret, opr1, opr2);	
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "BOR") == 0) {					// EXP BOR EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			fprintf(fout, "%s = or i32 %s, %s\n", ret, opr1, opr2);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"|\"");
				errorOccur(msg);
			}
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "SHLEFT") == 0) {				// EXP SHLEFT EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"<<\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = shl i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "SHRIGHT") == 0) {				// EXP SHRIGHT EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \">>\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = lshr i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i32");
		}
		else if (strcmp(n->next->token, "LOGAND") == 0) {				// EXP LOGAND EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i1") != 0 || strcmp(n->next->next->attr.type, "i1") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"&&\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = and i1 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "LOGOR") == 0) {				// EXP LOGOR EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i1") != 0 || strcmp(n->next->next->attr.type, "i1") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"||\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = or i1 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "GREATER") == 0) {				// EXP GREATER EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \">\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = icmp sgt i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "GREATEREQU") == 0) {			// EXP GREATEREQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \">=\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = icmp sge i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "LESS") == 0) {					// EXP LESS EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"<\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = icmp slt i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "LESSEQU") == 0) {				// EXP LESSEQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"<=\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = icmp sle i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "EQU") == 0) {					// EXP EQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"==\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = icmp eq i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "NOTEQU") == 0) {				// EXP NOTEQU EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32") != 0 || strcmp(n->next->next->attr.type, "i32") != 0) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "There is a type error when dealing with \"!=\"");
				errorOccur(msg);
			}
			fprintf(fout, "%s = icmp ne i32 %s, %s\n", ret, opr1, opr2);
			org->attr.type = strdup("i1");
		}
		else if (strcmp(n->next->token, "DOT") == 0) {					// EXP DOT EXP
			ret = get_TMP();
			char c;
			char *opr1, *opr2, *opr1_type;

			n->attr.isLeft = 1;
			Attr attr = n->next->next->attr;
			attr.isLeft = 1;
			updateAttr(n->next->next, attr);
			opr1 = code_EXP(n);
			opr2 = code_EXP(n->next->next);
			opr1_type = strdup(n->attr.type);
			//printf("___________%s\n", opr1_type);
			opr2++;
			//printf("___________%s\n", opr2);
			int t = isTypeExist(opr1_type);
			if (t == -1) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "variable \"%s\" is not a struct.\n", opr1+1);
				errorOccur(msg);
			}

			int index = 0;
			char* type = NULL;
			Type* tmp = types[t]->next;
			while (tmp!= NULL) {
				if (strcmp(tmp->name, opr2) == 0) {
					type = tmp->type;
					break;
				}
				index++;
				tmp = tmp->next;
			}
			if (type == NULL) {
				char* msg = (char*) malloc(sizeof(char)*50);
				sprintf(msg, "variable \"%s\": there is no \"%s\" in %s.\n", opr1+1, opr2, opr1_type+1);
				errorOccur(msg);
			}
			if ((strcmp(n->next->next->child->token, "ID") == 0) && org->attr.isLeft == 0) {
				char* reg = get_TMP();
				fprintf(fout, "%s = getelementptr inbounds %s* %s, i32 0, i32 %d\n", reg, opr1_type, opr1, index);
				fprintf(fout, "%s = load i32* %s, align 4\n", ret, reg);
			}
			else {
				fprintf(fout, "%s = getelementptr inbounds %s* %s, i32 0, i32 %d\n", ret, opr1_type, opr1, index);
			}
			org->attr.type = strdup(type);
			//printf("DOT done\n");
		}
		else if (strcmp(n->next->token, "ASSIGNOP") == 0) {				// EXP ASSIGNOP EXP
			n->attr.isLeft = 1;
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			if (strcmp(n->attr.type, "i32*") != 0) 
				errorOccur("These is a assign expression, left opr is not a left-value.\n");
			if (strcmp(n->next->next->attr.type, "i32") != 0)
				errorOccur("These is a assign expression which the type of right expression is not int.\n");
			fprintf(fout, "store i32 %s, i32* %s, align 4\n", opr2, opr1);
			org->attr.type = strdup("i32");
		}
		else {		// some operation and then assign     EXP ***AN EXP
			char* opr1 = code_EXP(n);
			char* opr2 = code_EXP(n->next->next);
			Attr attr = n->attr;
			attr.isLeft = 1;
			updateAttr(n, attr);
			char* opr = code_EXP(n);

			if (strcmp(n->next->token, "PLUSAN") == 0) {				// EXP PLUSAN EXP
				fprintf(fout, "%s = add i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "MINUSAN") == 0) {			// EXP MINUSAN EXP
				fprintf(fout, "%s = sub i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "PRODUCTAN") == 0) {		// EXP PRODECTAN EXP
				fprintf(fout, "%s = mul i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "DIVISIONAN") == 0) {		// EXP DIVISIONAN EXP
				fprintf(fout, "%s = sdiv i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "BANDAN") == 0) {			// EXP BANDAN EXP
				fprintf(fout, "%s = and i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "BXORAN") == 0) {			// EXP BXORAN EXP
				fprintf(fout, "%s = xor i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "BORAN") == 0) {			// EXP BORAN EXP
				fprintf(fout, "%s = or i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "SHLEFTAN") == 0) {			// EXP SHLEFTAN EXP
				fprintf(fout, "%s = shl i32 %s, %s \n", ret, opr1, opr2);
			}
			else if (strcmp(n->next->token, "SHRIGHTAN") == 0) {		// EXP SHRIGHTAN EXP
				fprintf(fout, "%s = lshr i32 %s, %s \n", ret, opr1, opr2);
			}
			else {}
			fprintf(fout, "store i32 %s, i32* %s, align 4\n", ret, opr);
			org->attr.type = strdup("i32");
		}

	}
	else if (strcmp(n->token, "MINUS") == 0) {							// MINUS EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = sub i32 0, %s\n", ret, opr);	
	}
	else if (strcmp(n->token, "INCR") == 0) {							// INCR EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = add i32 %s, 1 \n", ret, opr);
		Attr attr = n->attr;
		attr.isLeft = 1;
		updateAttr(n->next, attr);
		opr = code_EXP(n->next);
		fprintf(fout, "store i32 %s, i32* %s, align 4\n", ret, opr);
		org->attr.type = strdup("i32");
	}
	else if (strcmp(n->token, "DECR") == 0) {							// DECR EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = sub i32 %s, 1 \n", ret, opr);
		Attr attr = n->attr;
		attr.isLeft = 1;
		updateAttr(n->next, attr);
		opr = code_EXP(n->next);
		fprintf(fout, "store i32 %s, i32* %s, align 4\n", ret, opr);
		org->attr.type = strdup("i32");
	}
	else if (strcmp(n->token, "BNOT") == 0) {							// BNOT EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		fprintf(fout, "%s = xor i32 %s, -1\n", ret, opr);
		org->attr.type = strdup("i32");
	}
	else if (strcmp(n->token, "LOGNOT") == 0) {							// LOGNOT EXP
		ret = get_TMP();
		char* opr = code_EXP(n->next);
		if (strcmp(n->next->attr.type, "i32") == 0)
			fprintf(fout, "%s = icmp eq i32 %s, 0\n", ret, opr);
		else
			fprintf(fout, "%s = xor i1 %s, -1\n", ret, opr);
		org->attr.type = strdup("i1");
	}
	else if (strcmp(n->token, "LP") == 0) {								// LP EXP RP
		ret = code_EXP(n->next);
		org->attr.type = strdup(n->next->attr.type);
	}
	else if (strcmp(n->token, "INT") == 0) {							// INT
		char* p;
		long int tmp = strtol(n->content, &p, 0);
		sprintf(ret, "%ld", tmp);
		org->attr.type = strdup("i32");
	}
	else {}

	return ret;
}

char* code_ARGS(Node* n) {
	char* ret;
	ret = (char*) malloc(sizeof(char)*CODE_LENGTH);
	sprintf(ret, "");

	char tmp[CODE_LENGTH] = "";
	char c;
	if (n->attr.isLeft == 0) c = ' ';
	else c = '*';

	n->child->attr = n->attr;
	n = n->child;
	char* exp_code = code_EXP(n);
	sprintf(tmp, "i32%c %s", c, exp_code);
	strcat(ret, tmp);
	while (n->next != NULL) {
		n = n->next->next->child;
		exp_code = code_EXP(n);
		sprintf(tmp, ", i32 %s", exp_code);
		strcat(ret, tmp);
	}
	return ret;	
}

char* code_ARRS(Node* n) {					// LB EXP RB ARRS
	char* ret;
	ret = (char*)malloc(sizeof(char)*CODE_LENGTH);
	n = n->child;
	char* exp_code = code_EXP(n->next);
	sprintf(ret, "i32 %s", exp_code);
	return ret;
}

void codeGenerator(Node *n) {
	if (strcmp(n->token, "PROGRAM") == 0) code_PROGRAM(n);
	else if (strcmp(n->token, "EXTDEFS") == 0) code_EXTDEFS(n);
	else if (strcmp(n->token, "EXTDEF") == 0) code_EXTDEF(n);
	else if (strcmp(n->token, "SPEC") == 0) code_SPEC(n);
	else if (strcmp(n->token, "STSPEC") == 0) code_STSPEC(n);
	else if (strcmp(n->token, "OPTTAG") == 0) code_OPTTAG(n);
	else if (strcmp(n->token, "VAR") == 0) code_VAR(n);
	else if (strcmp(n->token, "FUNC") == 0) code_FUNC(n);
	else if (strcmp(n->token, "PARAS") == 0) code_PARAS(n);
	else if (strcmp(n->token, "STMTBLOCK") == 0) code_STMTBLOCK(n);
	else if (strcmp(n->token, "STMTS") == 0) code_STMTS(n);
	else if (strcmp(n->token, "STMT") == 0) code_STMT(n);
	else if (strcmp(n->token, "ESTMT") == 0) code_ESTMT(n);
	else if (strcmp(n->token, "DEFS") == 0) code_DEFS(n);
	else if (strcmp(n->token, "DEF") == 0) code_DEF(n);
	else if (strcmp(n->token, "INIT") == 0) code_INIT(n);
	else if (strcmp(n->token, "EXP") == 0) code_EXP(n);
	else if (strcmp(n->token, "ARGS") == 0) code_ARGS(n);
	else return;
	return;
}
void some_init() {
	types = (Type**) malloc(sizeof(Type*)*TYPE_NUMBER);
	ids = (Identifier*)malloc(sizeof(Identifier)*ID_NUMBER);

}
void printIDS(){
	int i = 0;
	for (i = 0; i < ptr_ids; i++) {
		printf("%s %s %d %d\n", ids[i].id, ids[i].type, ids[i].space, ids[i].isPara);
	}
	printf("\n\n");
	for (i = 0; i < ptr_types; i++) {
		printf("%d: %s____%s\n", i, types[i]->type, types[i]->name);
		Type* tmp = types[i]->next;
		while(tmp != NULL){
			printf("   %s______%s\n", tmp->type, tmp->name);
			tmp = tmp->next;
		}
	}
}

void errorOccur(char* msg){
	fclose(fout);
	fout = fopen(file_out_name, "w");
	fprintf(fout, "ERROR.\n");
	fclose(fout);
	printf("\n\n\nError Info:\n%s\n", msg);
	exit(0);
}

int main(int argc, char* argv[]){
	//printf ("%s%s\n", argv[0], argv[1]);
	yydebug=0;	//set it to 1, that should be DEBUG mode, to 0, that will disable DEBUG
	freopen(argv[1], "r", stdin);
	// fout = stdout;
	fout = fopen(argv[2], "w");
	file_out_name = argv[2];
	yyparse();
	printf("\n\nParsing tree has been built.\n");
	// walkGraph(head, 1);
	// fclose(fout);

	some_init();
	codeGenerator(head);
	printf("LLVM assembly code has been created.\n");

	//printIDS();
	return 0;
}

int yyerror(char *msg){
	//walkGraph(head, 1);
	fprintf(fout, "ERROR.", msg);
	exit(0);
	return 0;
}

Node* Record(char* content, ...){
	Node *res = malloc(sizeof(Node));
	res->token = strdup(content);
	res->content = NULL;

	va_list ap;
	va_start(ap, content);

	Node *tmp;
	tmp = va_arg(ap, Node*);

	res->child = tmp;
	res->next = NULL;

	Node *ttmp;
	while(tmp != NULL) {
		ttmp = va_arg(ap, Node*);
		tmp->next = ttmp;
		tmp = ttmp;
	}
	va_end(ap);

	head = res;
	return res;
}

