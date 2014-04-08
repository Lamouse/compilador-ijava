%{
#include<stdio.h>
#include "ljparser.h"
%}

%token PRINT
%token PARSEINT
%token RETURN
%token DOTLENGTH
%token INT
%token BOOL
%token BOOLIT
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
Program: CLASS ID OBRACE Declarations CBRACE									{printf("Program\n");}
Declarations: Declaration Declarations | Declaration 							{printf("Declarations\n");}
Declaration: FieldDecl | MethodDecl												{printf("Declaration\n");}

FieldDecl: STATIC VarDecl														{printf("FieldDecl\n");}
VarDecl: VarType Ids SEMIC 														{printf("VarDecl\n");}
Ids: ID COMMA Ids | ID 															{printf("Ids\n");}

Params: Param COMMA Params | Param 												{printf("Params\n");}
Param: VarType ID 																{printf("Param\n");}

MethodDecl: PUBLIC STATIC Type ID OCURV Params CCURV Statements 				{printf("MethodDecl\n");}
Statements: OBRACE StateList CBRACE 											{printf("Statements\n");}
StateList: Statement StateList | Statement 										{printf("StateList\n");}
Statement: IfState ELSE Statements												
	| IfState																	
	| WHILE OCURV Expr CCURV Statements											
	| PRINT OCURV Expr CCURV SEMIC												
	| IdState ASSIGN Expr SEMIC													
	| ReturnState SEMIC															{printf("Statement\n");}

IfState: IF OCURV Expr CCURV Statements											{printf("IfState\n");}
IdState: ID OSQUARE Expr CSQUARE | ID 											{printf("IdState\n");}
ReturnState: RETURN Expr | RETURN 												{printf("ReturnState\n");}

Expr: Expr Opers Expr
	| Expr OSQUARE Expr CSQUARE
	| ID | INTLIT | BOOLIT
	| NEW NumType OSQUARE Expr CSQUARE
	| OCURV Expr CCURV
	| Expr DOTLENGTH
	| OP3 Expr
	| NOT Expr
	| PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV
	| ID OCURV Args CCURV														{printf("Expr\n");}
	
Args: Expr COMMA Expr | Expr													{printf("Args\n");}

Type: VOID | VarType															{printf("Type\n");}
VarType: STRING | NumType														{printf("VarType\n");}
NumType: INT | BOOL 															{printf("NumType\n");}
Opers: OP1 | OP2 | OP3 | OP4													{printf("Opers\n");}

%%
int main() {
	yyparse();
}

int yyerror(char* s) {
	printf("%s\n", s);
}
