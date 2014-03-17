int				[0-9]+|0x[a-fA-F0-9]+
id				[a-zA-Z_$][a-zA-Z_$0-9]*
bool			"true"|"false"
reserved		"null"|"volatile"|"try"|"transient"|"throw""s"?|"this"|"synchronized"|"switch"|"super"|"short"|"protected"|"private"|"package"|"long"|"interface"|"instanceof"|"import"|"goto"|"for"|"float"|"finally"|"final"|"extends"|"double"|"do"|"char"|"catch"|"case"|"byte"|"break"|"assert"|"abstract"|"const"|"continue"|"default"|"enum"|"implements"|"native"|"strictfp"
op1				"&&"|"||"
op2				"<"|">"|"=="|"!="|"<="|">="
op3				"+"|"-"
op4				"*"|"/"|"%"

%X COMMENT
%{
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

<INITIAL>"System.out.println" 	{printf("PRINT\n"); coluna += yyleng;}
<INITIAL>"Integer.parseInt"		{printf("PARSEINT\n"); coluna += yyleng;}
<INITIAL>".length" 				{printf("DOTLENGTH\n"); coluna += yyleng;}

<INITIAL>int					{printf("INT\n"); coluna += yyleng;}
<INITIAL>boolean				{printf("BOOL\n"); coluna += yyleng;}
<INITIAL>void					{printf("VOID\n"); coluna += yyleng;}
<INITIAL>String 				{printf("STRING\n"); coluna += yyleng;}

<INITIAL>new					{printf("NEW\n"); coluna += yyleng;}
<INITIAL>if						{printf("IF\n"); coluna += yyleng;}
<INITIAL>else 					{printf("ELSE\n"); coluna += yyleng;}
<INITIAL>while 					{printf("WHILE\n"); coluna += yyleng;}
<INITIAL>class 					{printf("CLASS\n"); coluna += yyleng;}
<INITIAL>public 				{printf("PUBLIC\n"); coluna += yyleng;}
<INITIAL>static 				{printf("STATIC\n"); coluna += yyleng;}
<INITIAL>return 				{printf("RETURN\n"); coluna += yyleng;}

<INITIAL>"(" 					{printf("OCURV\n"); coluna += yyleng;}
<INITIAL>")" 					{printf("CCURV\n"); coluna += yyleng;}
<INITIAL>"{" 					{printf("OBRACE\n"); coluna += yyleng;}
<INITIAL>"}" 					{printf("CBRACE\n"); coluna += yyleng;}
<INITIAL>"[" 					{printf("OSQUARE\n"); coluna += yyleng;}
<INITIAL>"]" 					{printf("CSQUARE\n"); coluna += yyleng;}
<INITIAL>"!"					{printf("NOT\n"); coluna += yyleng;}
<INITIAL>"="					{printf("ASSIGN\n"); coluna += yyleng;}
<INITIAL>";"					{printf("SEMIC\n"); coluna += yyleng;}
<INITIAL>","					{printf("COMMA\n"); coluna += yyleng;}

<INITIAL>{reserved}				{printf("RESERVED(%s)\n", yytext); coluna += yyleng;}
<INITIAL>{op1}					{printf("OP1(%s)\n", yytext); coluna += yyleng;}
<INITIAL>{op2}					{printf("OP2(%s)\n", yytext); coluna += yyleng;}
<INITIAL>{op3}					{printf("OP3(%s)\n", yytext); coluna += yyleng;}
<INITIAL>{op4}					{printf("OP4(%s)\n", yytext); coluna += yyleng;}

<INITIAL>{int}					{printf("INTLIT(%s)\n", yytext); coluna += yyleng;}
<INITIAL>{bool}					{printf("BOOLLIT(%s)\n", yytext); coluna += yyleng;}
<INITIAL>{id} 					{printf("ID(%s)\n", yytext); coluna += yyleng;}
<INITIAL>[ \t]					{coluna++;}
<INITIAL>\n 					{linha++; coluna=1;}
<INITIAL>.						{printf("Line %d, col %d: illegal character ('%s')\n", linha, coluna, yytext); coluna++;}

%%
int main() {
	yylex();
}

int yywrap() {
	return 1;
}
