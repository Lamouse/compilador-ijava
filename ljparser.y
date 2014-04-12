%{
#include<stdio.h>

extern int coluna;
extern int linha;
extern char* yytext;
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

%right DOTLENGTH ASSIGN
%left OSQUARE
%left OP1
%left OP2
%left OP3
%left OP4
%left NOT

%union {
	char* string;
	int number;
}

%%
Program: CLASS ID OBRACE Declarations CBRACE									{printf("Program\n");}
Declarations: Declaration Declarations | Declaration 							{printf("Declarations\n");}
Declaration: FieldDecl | MethodDecl												{printf("Declaration\n");}

FieldDecl: STATIC VarDecl														{printf("FieldDecl\n");}
MethodDecl: PUBLIC STATIC Type ID OCURV Params CCURV OBRACE Statements CBRACE	{printf("MethodDecl\n");}

Params: STRING OSQUARE CSQUARE ID | ParamList | 								{printf("Params\n");}
ParamList: Param COMMA Params | Param 											{printf("ParamList\n");}
Param: VarType ID 																{printf("Param\n");}

Statements: VarList StateList | VarList | StateList |								{printf("Statements\n");}
VarList: VarDecl VarList | VarDecl												{printf("VarList\n");}

StateList: Statement StateList | Statement 										{printf("StateList\n");}
Statement: IfState ELSE OBRACE Statement CBRACE										
	| IfState																	
	| WHILE OCURV Expr CCURV OBRACE Statement CBRACE											
	| PRINT OCURV Expr CCURV SEMIC												
	| IdState ASSIGN Expr SEMIC													
	| ReturnState SEMIC															{printf("Statement\n");}

IfState: IF OCURV Expr CCURV OBRACE Statement CBRACE							{printf("IfState\n");}
IdState: ID OSQUARE Expr CSQUARE | ID 											{printf("IdState\n");}
ReturnState: RETURN Expr | RETURN 												{printf("ReturnState\n");}

VarDecl: VarType Ids SEMIC 														{printf("VarDecl\n");}
Ids: ID COMMA Ids | ID 															{printf("Ids\n");}

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

Type: VOID | STRING| INT | BOOL													{printf("Type\n");}
VarType: STRING | INT | BOOL | INT OSQUARE CSQUARE | BOOL OSQUARE CSQUARE		{printf("VarType\n");}
NumType: INT | BOOL 															{printf("NumType\n");}
Opers: OP1 | OP2 | OP3 | OP4													{printf("Opers\n");}

%%
int main() {
	yyparse();
}

int yyerror (char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linha, coluna, s, yytext); 
}
