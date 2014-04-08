%{
#include<stdio.h>
#include "ljparser.h"
%}

%token PRINT
%token PARSEINT
%token PRINT
%token DOTLENGTH
%token INT
%token BOOL
%token VOID
%token STRING
%token NEW
%token IF
%token ELSE
%token WHILE
%token CLASS
%token PUBLIC
%token STATIC
%token OCURV
%token CCURV
%token OBRACE
%token CBRACE
%token OSQUARE
%token CSQUARE
%token NOT
%token ASSIGN
%token SEMIC
%token COMMA

%token <string> RESERVED
%token <string> OP1
%token <string> OP2
%token <string> OP3
%token <string> OP4

%token <number> INTLIT
%token <number> BOOLLIT
%token <string> ID

%union {
	char* string;
	int number;
}

%%

%%
int main() {
	yyparse();
}

int yyerror(char* s) {
	printf("%s\n", s);
}