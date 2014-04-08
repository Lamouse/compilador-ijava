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
Program: CLASS ID OBRACE Declarations CBRACE									{};
Declarations: Declaration Declarations | Declaration 							{};
Declaration: FieldDecl | MethodDecl												{};

MethodDecl: PUBLIC STATIC Type ID OCURV Params CCURV OBRACE	Statements CBRACE	{};

FieldDecl: STATIC VarDecl														{};
VarDecl: Type Ids SEMIC 														{};
Ids: ID COMMA Ids | Ids 														{};

Params: Param COMMA Params | Param 												{};
Param: TYPE ID 																	{};
Type: VOID | INT | BOOL | STRING												{};

Program → CLASS ID OBRACE { FieldDecl | MethodDecl } CBRACE
FieldDecl → STATIC VarDecl
MethodDecl → PUBLIC STATIC ( Type | VOID ) ID OCURV
 [ FormalParams ] CCURV OBRACE { VarDecl } { Statement } CBRACE
FormalParams → Type ID { COMMA Type ID }
FormalParams → STRING OSQUARE CSQUARE ID
VarDecl → Type ID { COMMA ID } SEMIC
Type → ( INT | BOOL ) [ OSQUARE CSQUARE ]
Statement → OBRACE { Statement } CBRACE
Statement → IF OCURV Expr CCURV Statement [ ELSE Statement ]
Statement → WHILE OCURV Expr CCURV Statement
Statement → PRINT OCURV Expr CCURV SEMIC
Statement → ID [ OSQUARE Expr CSQUARE ] ASSIGN Expr SEMIC
Statement → RETURN [ Expr ] SEMIC
Expr → Expr ( OP1 | OP2 | OP3 | OP4 ) Expr
Expr → Expr OSQUARE Expr CSQUARE
Expr → ID | INTLIT | BOOLLIT
Expr → NEW ( INT | BOOL ) OSQUARE Expr CSQUARE
Expr → OCURV Expr CCURV
Expr → Expr DOTLENGTH | ( OP3 | NOT ) Expr
Expr → PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV
Expr → ID OCURV [ Args ] CCURV
Args → Expr { COMMA Expr }

%%
int main() {
	yyparse();
}

int yyerror(char* s) {
	printf("%s\n", s);
}