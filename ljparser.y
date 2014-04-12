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
program: CLASS ID OBRACE declarations CBRACE									{printf("program\n");}
declarations: declaration declarations | declaration | 							{printf("declarations\n");}
declaration: fieldDecl | methodDecl												{printf("declaration\n");}

fieldDecl: STATIC varDecl														{printf("fieldDecl\n");}
methodDecl: PUBLIC STATIC type ID OCURV params CCURV OBRACE statements CBRACE	{printf("methodDecl\n");}

params: STRING OSQUARE CSQUARE ID | paramList | 								{printf("params\n");}
paramList: param COMMA params | param 											{printf("paramList\n");}
param: varType ID 																{printf("param\n");}

statements: varList stateList | varList | stateList |							{printf("statements\n");}
varList: varDecl varList | varDecl												{printf("varList\n");}

stateList: statement stateList | statement 										{printf("stateList\n");}
statement: ifState ELSE OBRACE statement CBRACE										
	| ifState																	
	| WHILE OCURV expr CCURV OBRACE statement CBRACE											
	| PRINT OCURV expr CCURV SEMIC												
	| idState ASSIGN expr SEMIC													
	| returnState SEMIC															{printf("statement\n");}

ifState: IF OCURV expr CCURV OBRACE statement CBRACE							{printf("ifState\n");}
idState: ID OSQUARE expr CSQUARE | ID 											{printf("idState\n");}
returnState: RETURN expr | RETURN 												{printf("returnState\n");}

varDecl: varType ids SEMIC 														{printf("varDecl\n");}
ids: ID COMMA ids | ID 															{printf("ids\n");}

expr: expr opers expr
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

type: VOID | STRING| INT | BOOL													{printf("Type\n");}
varType: STRING | INT | BOOL | INT OSQUARE CSQUARE | BOOL OSQUARE CSQUARE		{printf("varType\n");}
numType: INT | BOOL 															{printf("numType\n");}
opers: OP1 | OP2 | OP3 | OP4													{printf("opers\n");}

%%
int main() {
	yyparse();
}

int yyerror (char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linha, coluna, s, yytext); 
}
