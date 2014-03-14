int				[0-9]+|0x[a-f0-9]+
id				[a-zA-Z_$][a-zA-Z_$0-9]*
bool			"true"|"false"
reserved		"null"|"volatile"|"try"|"transient"|"throw""s"?|"this"|"synchronized"|"switch"|"super"|"short"|"protected"|"private"|"package"|"long"|"interface"|"instanceof"|"import"|"goto"|"for"|"float"|"finally"|"final"|"extends"|"double"|"do"|"char"|"catch"|"case"|"byte"|"break"|"assert"|"abstract"
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
"/*"						{BEGIN COMMENT; linhaAux=linha;}
<COMMENT>"*/"				{BEGIN 0; coluna += colunaAux; linha = linhaAux + 2; colunaAux=0; linhaAux=0;}
<COMMENT><<EOF>>			{BEGIN 0; printf("Line %d, col %d: unterminated COMMENT\n", linha, coluna);}
<COMMENT>.					{linhaAux++;}
<COMMENT>\n 				{colunaAux++; linhaAux=0;}

<INITIAL>"System.out.println" 	{printf("PRINT\n"); linha += yyleng;}
<INITIAL>"Integer.parseInt"		{printf("PARSEINT\n"); linha += yyleng;}
<INITIAL>".length" 				{printf("DOTLENGTH\n"); linha += yyleng;}

<INITIAL>int					{printf("INT\n"); linha += yyleng;}
<INITIAL>boolean				{printf("BOOL\n"); linha += yyleng;}
<INITIAL>void					{printf("VOID\n"); linha += yyleng;}
<INITIAL>String 				{printf("STRING\n"); linha += yyleng;}

<INITIAL>new					{printf("NEW\n"); linha += yyleng;}
<INITIAL>if						{printf("IF\n"); linha += yyleng;}
<INITIAL>else 					{printf("ELSE\n"); linha += yyleng;}
<INITIAL>while 					{printf("WHILE\n"); linha += yyleng;}
<INITIAL>class 					{printf("CLASS\n"); linha += yyleng;}
<INITIAL>public 				{printf("PUBLIC\n"); linha += yyleng;}
<INITIAL>private 				{printf("PRIVATE\n"); linha += yyleng;}
<INITIAL>static 				{printf("STATIC\n"); linha += yyleng;}
<INITIAL>return 				{printf("RETURN\n"); linha += yyleng;}

<INITIAL>"(" 					{printf("OCURV\n"); linha += yyleng;}
<INITIAL>")" 					{printf("CCURV\n"); linha += yyleng;}
<INITIAL>"{" 					{printf("OBRAVE\n"); linha += yyleng;}
<INITIAL>"}" 					{printf("CBRAVE\n"); linha += yyleng;}
<INITIAL>"[" 					{printf("OSQUARE\n"); linha += yyleng;}
<INITIAL>"]" 					{printf("CSQUARE\n"); linha += yyleng;}
<INITIAL>"!"					{printf("NOT\n"); linha += yyleng;}
<INITIAL>"="					{printf("ASSIGN\n"); linha += yyleng;}
<INITIAL>";"					{printf("SEMIC\n"); linha += yyleng;}
<INITIAL>","					{printf("COMMA\n"); linha += yyleng;}

<INITIAL>{reserved}				{printf("RESERVED\n"); linha += yyleng;}
<INITIAL>{op1}					{printf("OP1\n"); linha += yyleng;}
<INITIAL>{op2}					{printf("OP2\n"); linha += yyleng;}
<INITIAL>{op3}					{printf("OP3\n"); linha += yyleng;}
<INITIAL>{op4}					{printf("OP4\n"); linha += yyleng;}

<INITIAL>{int}					{printf("INTLIT(%s)\n", yytext); linha += yyleng;}
<INITIAL>{bool}					{printf("BOOLLIT(%s)\n", yytext); linha += yyleng;}
<INITIAL>{id} 					{printf("ID(%s)\n", yytext); linha += yyleng;}
<INITIAL>[ \t]					{linha++;}
<INITIAL>\n 					{coluna++; linha=0;}
<INITIAL>.						{printf("Line %d, col %d: illegal character ('%s')\n", linha, coluna, yytext); linha++;}

%%
int main() {
	yylex();
}

int yywrap() {
	return 1;
}
