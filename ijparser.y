%{
#include<stdio.h>
#include "ijparser.h"

extern int colunaAux;
extern int linhaAux;
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

%type <MethodDecl> methodDecl
%type <MethodDecl> statements

%type <Statement> stateList
%type <Statement> statement
%type <Statement> ifState

%type <VarDecl> params
%type <VarDecl> paramList
%type <VarDecl> param

%type <VarDecl> fieldDecl
%type <VarDecl> varList
%type <VarDecl> varDecl
%type <Ids> ids

%type <Exp> optionalExp
%type <Exp> exp

%union {
	char* string;
	int number;
}

%%
program: CLASS ID OBRACE declarations CBRACE									{printf("program\n");}
declarations: declarationList |													{printf("declarations\n");}
declarationList: declaration declarationList | declaration 						{printf("declarationList\n");}
declaration: fieldDecl | methodDecl												{printf("declaration\n");}

fieldDecl: STATIC varDecl														{$$ = $2;}
methodDecl: PUBLIC STATIC type ID OCURV params CCURV OBRACE statements CBRACE	{$$ = newMethodDecl($3, $4, $6, $9);}
statements: varList stateList													{$$ = newMethod($1, $2);}
	| varList																	{$$ = newMethod(NULL, $1);}
	| stateList																	{$$ = newMethod($1, NULL);}
	|																			{$$ = newMethod(NULL, NULL);}

params: STRING OSQUARE CSQUARE ID | paramList | 								{printf("params\n");}
paramList: param COMMA paramList | param 										{printf("paramList\n");}
param: varType ID 																{printf("param\n");}

varList: varDecl varList														{$$ = connectVarDecl($1, $2);}
	| varDecl																	{$$ = $1;}

varDecl: varType ids SEMIC 														{$$ = newVarDecl($1, $2);}
ids: ID COMMA ids | ID 															{$$ = connectIds($1, $3);}

stateList: statement stateList													{$$ = connectStatements($1, $2);}
	| statement 																{$$ = $1;}

statement: ifState ELSE statement 												{$$ = newElse($1, $3);}
	| ifState %prec IFX 														{$$ = $1;}
	| OBRACE stateList CBRACE													{$$ = $2;}
	| OBRACE CBRACE																{$$ = NULL;}
	| WHILE OCURV expr CCURV statement 											{$$ = newWhile($3, $5);}
	| PRINT OCURV expr CCURV SEMIC												{$$ = newPrint($3);}
	| ID ASSIGN expr SEMIC														{$$ = newStore($1, NULL, $3);}
	| ID OSQUARE expr CSQUARE ASSIGN expr SEMIC									{$$ = newStore($1, $3, $7);}
	| RETURN optionalExp SEMIC													{$$ = newReturn($2);}
ifState: IF OCURV expr CCURV statement											{$$ = newIf($3, $5);}

optionalExp: expr																{$$ = $1;}
	|																			{$$ = NULL;}
expr: expr opers expr %prec OPERSX
	| expr OSQUARE expr CSQUARE
	| ID | INTLIT | BOOLIT
	| NEW numType OSQUARE expr CSQUARE
	| OCURV expr CCURV
	| expr DOTLENGTH
	| OP3 expr
	| NOT expr
	| PARSEINT OCURV ID OSQUARE expr CSQUARE CCURV
	| ID OCURV CCURV
	| ID OCURV args CCURV														{printf("expr\n");}
	
args: expr COMMA args | expr													{printf("args\n");}
opers: OP1 | OP2 | OP3 | OP4													{printf("opers\n");}

type: VOID | varType															{printf("Type\n");}
varType: numType | numType OSQUARE CSQUARE										{printf("varType\n");}
numType: INT | BOOL 															{printf("numType\n");}

%%
int main() {
	yyparse();
	return 0;
}

int yyerror (char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linhaAux, colunaAux, s, yytext); 
}
