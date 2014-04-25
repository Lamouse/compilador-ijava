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

%type <method> methodDecl
%type <method> statements

%type <statement> stateList
%type <statement> statement
%type <statement> ifState

%type <var> params
%type <var> paramList
%type <var> param

%type <var> fieldDecl
%type <var> varList
%type <var> varDecl
%type <ids> ids

%type <exp> optionalExp
%type <exp> exp
%type <exp> optionalArgs
%type <exp> args

%type <type> type;
%type <type> varType;
%type <type> numType;

%type <expType> opers;

%union {
	MethodDecl* method;
	Statement* statement;
	VarDecl* var;
    Ids* ids;
    Exp* exp;
    Type type;
    ExpType expType;

	char* string;
	int number;
}

%%
program: CLASS ID OBRACE declarations CBRACE									{$$ = nameProgram($2, $4);}

declarations: declarationList |													{printf("declarations\n");}

declarationList: declaration declarationList | declaration 						{printf("declarationList\n");}

declaration: fieldDecl | methodDecl												{printf("declaration\n");}

fieldDecl: STATIC varDecl														{$$ = $2;}

methodDecl: PUBLIC STATIC type ID OCURV params CCURV OBRACE statements CBRACE	{$$ = newMethodDecl($3, $4, $6, $9);}

statements: varList stateList													{$$ = newMethod($1, $2);}
	| varList																	{$$ = newMethod(NULL, $1);}
	| stateList																	{$$ = newMethod($1, NULL);}
	|																			{$$ = newMethod(NULL, NULL);}

params: STRING OSQUARE CSQUARE ID 												{$$ = newVarDecl(StringArray, newIds($4));}
	| paramList																	{$$ = $1;}
	| 																			{$$ = NULL;}

paramList: param COMMA paramList												{$$ = connectVarDecl($1, $3);}
	| param 																	{$$ = $1;}

varList: varDecl varList														{$$ = connectVarDecl($1, $2);}
	| varDecl																	{$$ = $1;}

param: varType ID 																{$$ = newVarDecl($1, newIds($2));}

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

expr: expr opers expr %prec OPERSX												{$$ = newAnonymousOper($1, $3, $2);}
	| ID OSQUARE expr CSQUARE													{$$ = newAnonymousOper($1, $3, LoadArray);}
	| ID 																		{$$ = newId($1);}
	| INTLIT 																	{$$ = newIntLit($1);}
	| BOOLLIT 																	{$$ = newBoolLit($1);}
	| NEW numType OSQUARE expr CSQUARE											{$$ = newAnonymousOper($4, NULL, $2 == Int ? NewInt:NewBool);}
	| expr DOTLENGTH															{$$ = newAnonymousOper($1, NULL, Length);}
	| OP3 expr																	{$$ = newAnonymousOper($2, NULL, getOperType($2));}
	| NOT expr																	{$$ = newAnonymousOper($2, NULL, Not);}
	| PARSEINT OCURV ID OSQUARE expr CSQUARE CCURV
	| ID OCURV optionalArgs CCURV
	| OCURV expr CCURV															{$$ = $2;}
	
opers: OP1 | OP2 | OP3 | OP4													{$$ = getOperType($1);}

optionalArgs: args 																{$$ = $1;}
	| 																			{$$ = NULL;}

args: expr COMMA args															{$$ = connectExp($1, $3);}
	| expr																		{$$ = $1;}											

type: VOID {$$ = Void;} | varType {$$ = $1;}

varType: numType {$$ = $1;} | numType OSQUARE CSQUARE {$$ = $1 == Int ? IntArray:BoolArray;}

numType: INT {$$ = Int;} | BOOL {$$ = Bool;}

%%
int main() {
	yyparse();
	return 0;
}

int yyerror (char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linhaAux, colunaAux, s, yytext); 
}
