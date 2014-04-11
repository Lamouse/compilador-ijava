int				[0-9]+|0x[a-fA-F0-9]+
id				[a-zA-Z_$][a-zA-Z_$0-9]*
bool			"true"|"false"
reserved		"null"|"volatile"|"try"|"transient"|"throw""s"?|"this"|"synchronized"|"switch"|"super"|"short"|"protected"|"private"|"package"|"long"|"interface"|"instanceof"|"import"|"goto"|"for"|"float"|"finally"|"final"|"extends"|"double"|"do"|"char"|"catch"|"case"|"byte"|"break"|"assert"|"abstract"|"const"|"continue"|"default"|"enum"|"implements"|"native"|"strictfp"|"++"|"--"
op1				"&&"|"||"
op2				"<"|">"|"=="|"!="|"<="|">="
op3				"+"|"-"
op4				"*"|"/"|"%"

%X COMMENT
%{
	#include "y.tab.h"
	#include "string.h"

	int coluna = 1;
	int linha = 1;
	int colunaAux = 0;
	int linhaAux = 0;
%}

%%
"//".*
"/*"							{BEGIN COMMENT; colunaAux=coluna; linhaAux = linha;}
<COMMENT>"*/"					{BEGIN 0; linha = linhaAux; coluna = colunaAux + 2;}
<COMMENT><<EOF>>				{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", linha, coluna);}
<COMMENT>.						{colunaAux++;}
<COMMENT>\n 					{linhaAux++; colunaAux=1;}

<INITIAL>"System.out.println" 	{coluna += yyleng; return PRINT;}
<INITIAL>"Integer.parseInt"		{coluna += yyleng; return PARSEINT;}
<INITIAL>".length" 				{coluna += yyleng; return DOTLENGTH;}

<INITIAL>int					{coluna += yyleng; return INT;}
<INITIAL>boolean				{coluna += yyleng; return BOOL;}
<INITIAL>void					{coluna += yyleng; return VOID;}
<INITIAL>String 				{coluna += yyleng; return STRING;}

<INITIAL>new					{coluna += yyleng; return NEW;}
<INITIAL>if						{coluna += yyleng; return IF;}
<INITIAL>else 					{coluna += yyleng; return ELSE;}
<INITIAL>while 					{coluna += yyleng; return WHILE;}
<INITIAL>class 					{coluna += yyleng; return CLASS;}
<INITIAL>public 				{coluna += yyleng; return PUBLIC;}
<INITIAL>static 				{coluna += yyleng; return STATIC;}
<INITIAL>return 				{coluna += yyleng; return RETURN;}

<INITIAL>"(" 					{coluna += yyleng; return OCURV;}
<INITIAL>")" 					{coluna += yyleng; return CCURV;}
<INITIAL>"{" 					{coluna += yyleng; return OBRACE;}
<INITIAL>"}" 					{coluna += yyleng; return CBRACE;}
<INITIAL>"[" 					{coluna += yyleng; return OSQUARE;}
<INITIAL>"]" 					{coluna += yyleng; return CSQUARE;}
<INITIAL>"!"					{coluna += yyleng; return NOT;}
<INITIAL>"="					{coluna += yyleng; return ASSIGN;}
<INITIAL>";"					{coluna += yyleng; return SEMIC;}
<INITIAL>","					{coluna += yyleng; return COMMA;}

<INITIAL>{reserved}				{yylval.string=(char*)strdup(yytext); coluna += yyleng; return RESERVED;}
<INITIAL>{op1}					{yylval.string=(char*)strdup(yytext); coluna += yyleng; return OP1;}
<INITIAL>{op2}					{yylval.string=(char*)strdup(yytext); coluna += yyleng; return OP2;}
<INITIAL>{op3}					{yylval.string=(char*)strdup(yytext); coluna += yyleng; return OP3;}
<INITIAL>{op4}					{yylval.string=(char*)strdup(yytext); coluna += yyleng; return OP4;}

<INITIAL>{int}					{yylval.number = atoi(yytext); coluna += yyleng; return INTLIT;}
<INITIAL>{bool}					{yylval.number = strcmp(yytext, "true") ? 0 : 1; coluna += yyleng; return BOOLIT;}
<INITIAL>{id} 					{yylval.string=(char*)strdup(yytext); coluna += yyleng; return ID;}
<INITIAL>[ \t]					{coluna++;}
<INITIAL>\n 					{linha++; coluna=1;}
<INITIAL>.						{printf("Line %d, col %d: illegal character ('%s')\n", linha, coluna, yytext); coluna++;}

%%
int yywrap() {
	return 1;
}
