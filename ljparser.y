%{
#include<stdio.h>
#include "ljparser.h"

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

%nonassoc IFX  
%nonassoc ELSE
%nonassoc OPERSX
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
program: CLASS ID OBRACE declarations CBRACE									{printf("program\n");}
declarations: declarationList |													{printf("declarations\n");}
declarationList: declaration declarationList | declaration 						{printf("declarationList\n");}
declaration: fieldDecl | methodDecl												{printf("declaration\n");}

fieldDecl: STATIC varDecl														{printf("fieldDecl\n");}
methodDecl: PUBLIC STATIC type ID OCURV params CCURV OBRACE statements CBRACE	{printf("methodDecl\n");}

params: STRING OSQUARE CSQUARE ID | paramList | 								{printf("params\n");}
paramList: param COMMA params | param 											{printf("paramList\n");}
param: varType ID 																{printf("param\n");}

statements: varList stateList | varList | stateList |							{printf("statements\n");}
varList: varDecl varList | varDecl												{printf("varList\n");}

stateList: statement stateList | statement 										{printf("stateList\n");}
statement: ifState ELSE statement
	| ifState %prec IFX 
	| OBRACE statement CBRACE
	| OBRACE CBRACE																
	| WHILE OCURV expr CCURV statement
	| PRINT OCURV expr CCURV SEMIC
	| idState ASSIGN expr SEMIC
	| returnState SEMIC															{printf("statement\n");}

ifState: IF OCURV expr CCURV statement											{printf("ifState\n");}
idState: ID OSQUARE expr CSQUARE | ID 											{printf("idState\n");}
returnState: RETURN expr | RETURN 												{printf("returnState\n");}

varDecl: varType ids SEMIC 														{printf("varDecl\n");}
ids: ID COMMA ids | ID 															{printf("ids\n");}

expr: expr opers expr %prec OPERSX
	| expr OSQUARE expr CSQUARE
	| ID | INTLIT | BOOLIT
	| NEW numType OSQUARE expr CSQUARE
	| OCURV expr CCURV
	| expr DOTLENGTH
	| OP3 expr
	| NOT expr
	| PARSEINT OCURV ID OSQUARE expr CSQUARE CCURV
	| ID OCURV args CCURV														{printf("expr\n");}
	
args: expr COMMA expr | expr													{printf("args\n");}
opers: OP1 | OP2 | OP3 | OP4													{printf("opers\n");}

type: VOID | varType															{printf("Type\n");}
varType: numType | numType OSQUARE CSQUARE										{printf("varType\n");}
numType: INT | BOOL 															{printf("numType\n");}

%%
int main() {
	yyparse();
}

int yyerror (char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linha, coluna, s, yytext); 
}
