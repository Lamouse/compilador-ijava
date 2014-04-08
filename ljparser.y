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

FieldDecl: STATIC VarDecl														{};
VarDecl: VarType Ids SEMIC 														{};
Ids: ID COMMA Ids | Ids 														{};

Params: Param COMMA Params | Param 												{};
Param: VarType ID 																{};

MethodDecl: PUBLIC STATIC Type ID OCURV Params CCURV Statements 				{};
Statements: OBRACE StateList CBRACE 											{};
StateList: Statement StateList | Statement 										{};
Statement: IfState ELSE Statements												{};
	| IfState																	{};
	| WHILE OCURV Expr CCURV Statements											{};
	| PRINT OCURV Expr CCURV SEMIC												{};
	| IdState ASSIGN Expr SEMIC													{};
	| ReturnStare SEMIC															{};

IfState: IF OCURV Expr CCURV Statements											{};
IdState: ID OSQUARE Expr CSQUARE | ID
ReturnState: RETURN Expr | RETURN 												{};

Type: VOID | VarType															{};
VarType: STRING | NumType														{};
NumType: INT | BOOL 															{};
Opers: OP1 | OP2 | OP3 | OP4													{};

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
