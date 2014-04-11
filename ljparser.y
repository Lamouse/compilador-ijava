%{
#include<stdio.h>
<<<<<<< HEAD
#include "ljparser.h"

extern int coluna;
extern int linha;
extern char* yytext;
=======
>>>>>>> c108f0df4ede68c9eea2fdaac832004690a35489
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
Program: CLASS ID OBRACE Declarations CBRACE									{printf("Program\n");}
	| CLASS ID OBRACE CBRACE													{printf("Program\n");}

Declarations: FieldDecl MethodDecl												{printf("Declarations\n");}
	| FieldDecl																	{printf("Declarations\n");}
	| MethodDecl																{printf("Declarations\n");}

FieldDecl: STATIC VarDecl FieldDecl	| STATIC VarDecl							{printf("FieldDecl\n");}	

<<<<<<< HEAD
MethodDecl: PUBLIC STATIC MethodType ID OCURV FormalParams CCURV Statements MethodDecl
																				{printf("MethodDecl\n");}
	| PUBLIC STATIC MethodType ID OCURV FormalParams CCURV Statements 			{printf("MethodDecl\n");}

VarDecl: Type Ids																{printf("VarDecl\n");}
Ids: ID SEMIC | ID COMMA														{printf("Ids\n");}
MethodType: VOID | Type 														{printf("MethodType\n");}
Type: INT | BOOL | INT OSQUARE CSQUARE | BOOL OSQUARE CSQUARE					{printf("Type\n");}
NumType: INT | BOOL 															{printf("NumType\n");}

FormalParams: Params | STRING OSQUARE CSQUARE ID | 								{printf("FormalParams\n");}
Params: Param COMMA Params | Param 												{printf("Params\n");}
Param: Type Ids 																{printf("Param\n");}
=======
MethodDecl: PUBLIC STATIC MethodType ID OCURV Params CCURV Statements MethodDecl
																				{printf("MethodDecl\n");}
	| PUBLIC STATIC MethodType ID OCURV Params CCURV Statements 				{printf("MethodDecl\n");}

VarDecl: Type Ids																{printf("VarDecl\n");}
Ids: ID COMMA Ids | ID SEMIC													{printf("Ids\n");}
MethodType: VOID | Type 														{printf("MethodType\n");}
Type: SingletonType | SingletonType OSQUARE CSQUARE								{printf("Type\n");}
SingletonType: NumType | STRING                                                 {printf("SingletonType\n");}
NumType: INT | BOOL 															{printf("NumType\n");}

Params: | Param COMMA Params | Param 											{printf("Params\n");}
Param: Type ID																	{printf("Param\n");}
>>>>>>> c108f0df4ede68c9eea2fdaac832004690a35489

Statements: OBRACE VarDecl1 ListStatement CBRACE								{printf("Statements\n");}
	| OBRACE VarDecl1 CBRACE													{printf("Statements\n");}
	| OBRACE ListStatement CBRACE												{printf("Statements\n");}
	| OBRACE CBRACE																{printf("Statements\n");}

VarDecl1: VarDecl VarDecl1 | VarDecl 											{printf("VarDecl1\n");}

ListStatement: Statement ListStatement | Statement								{printf("ListStatement\n");}

Statement: IfState ELSE Statement												{printf("Statement\n");}
	| IfState %prec IFX															{printf("Statement\n");} 
	| OBRACE Statement CBRACE													{printf("Statement\n");}
	| OBRACE CBRACE																{printf("Statement\n");}
	| WHILE OCURV Expr CCURV Statement											{printf("Statement\n");}
	| PRINT OCURV Expr CCURV SEMIC												{printf("Statement\n");}
	| IdState ASSIGN Expr SEMIC													{printf("Statement\n");}
	| ReturnState SEMIC															{printf("Statement\n");}

IfState: IF OCURV Expr CCURV Statement											{printf("IfState\n");}
IdState: ID OSQUARE Expr CSQUARE | ID 											{printf("IdState\n");}
ReturnState: RETURN Expr | RETURN 												{printf("ReturnState\n");}

Expr: Expr Opers Expr %prec OPERSX												{printf("Expr\n");}
	| Expr OSQUARE Expr CSQUARE 												{printf("Expr\n");}
	| ID | INTLIT | BOOLIT 														{printf("Expr\n");}
	| NEW NumType OSQUARE Expr CSQUARE											{printf("Expr\n");}
	| OCURV Expr CCURV															{printf("Expr\n");}
	| Expr DOTLENGTH															{printf("Expr\n");}
	| OP3 Expr																	{printf("Expr\n");}
	| NOT Expr																	{printf("Expr\n");}
	| PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV								{printf("Expr\n");}
	| ID OCURV CCURV															{printf("Expr\n");}
	| ID OCURV Args CCURV														{printf("Expr\n");}
	
Args: Expr COMMA Expr | Expr													{printf("Args\n");}

Opers: OP1 | OP2 | OP3 | OP4													{printf("Opers\n");}

%%
int main() {
	yyparse();
}

int yyerror (char *s) { 
	printf ("Line %d, col %d: %s: %s\n", linha, coluna, s, yytext); 
}

