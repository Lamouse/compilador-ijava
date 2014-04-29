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
	int colunaAux = 1;
	int linhaAux = 1;
%}

%%
"//".*
"/*"							{BEGIN COMMENT; colunaAux=coluna+2; linhaAux = linha;}
<COMMENT>"*/"					{BEGIN 0; linha = linhaAux; coluna = colunaAux + 2;}
<COMMENT><<EOF>>				{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", linha, coluna); return *yytext;}
<COMMENT>.						{colunaAux++;}
<COMMENT>\n 					{linhaAux++; colunaAux=1;}

<INITIAL>"System.out.println" 	{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return PRINT;}
<INITIAL>"Integer.parseInt"		{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return PARSEINT;}
<INITIAL>".length" 				{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return DOTLENGTH;}

<INITIAL>int					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return INT;}
<INITIAL>boolean				{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return BOOL;}
<INITIAL>void					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return VOID;}
<INITIAL>String 				{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return STRING;}

<INITIAL>new					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return NEW;}
<INITIAL>if						{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return IF;}
<INITIAL>else 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return ELSE;}
<INITIAL>while 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return WHILE;}
<INITIAL>class 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return CLASS;}
<INITIAL>public 				{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return PUBLIC;}
<INITIAL>static 				{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return STATIC;}
<INITIAL>return 				{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return RETURN;}

<INITIAL>"(" 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OCURV;}
<INITIAL>")" 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return CCURV;}
<INITIAL>"{" 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OBRACE;}
<INITIAL>"}" 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return CBRACE;}
<INITIAL>"[" 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OSQUARE;}
<INITIAL>"]" 					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return CSQUARE;}
<INITIAL>"!"					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return NOT;}
<INITIAL>"="					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return ASSIGN;}
<INITIAL>";"					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return SEMIC;}
<INITIAL>","					{colunaAux = coluna; linhaAux = linha; coluna += yyleng; return COMMA;}

<INITIAL>{reserved}				{yylval.string=(char*)strdup(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return RESERVED;}
<INITIAL>{op1}					{yylval.string=(char*)strdup(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OP1;}
<INITIAL>{op2}					{yylval.string=(char*)strdup(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OP2;}
<INITIAL>{op3}					{yylval.string=(char*)strdup(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OP3;}
<INITIAL>{op4}					{yylval.string=(char*)strdup(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return OP4;}

<INITIAL>{int}					{yylval.number = atoi(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return INTLIT;}
<INITIAL>{bool}					{yylval.number = strcmp(yytext, "true") ? 0 : 1; colunaAux = coluna; linhaAux = linha; coluna += yyleng; return BOOLLIT;}
<INITIAL>{id} 					{yylval.string=(char*)strdup(yytext); colunaAux = coluna; linhaAux = linha; coluna += yyleng; return ID;}
<INITIAL>[ \t]					{colunaAux = coluna; linhaAux = linha; coluna++;}
<INITIAL>\n 					{colunaAux = coluna; linhaAux = linha; linha++; coluna=1;}
<INITIAL><<EOF>>				{colunaAux = coluna; linhaAux = linha; return *yytext;}				//para enviar o EOF ao yacc
<INITIAL>.						{printf("Line %d, col %d: illegal character ('%s')\n", linha, coluna, yytext); colunaAux = coluna; linhaAux = linha; coluna++;}

%%
int yywrap() {
	return 1;
}
