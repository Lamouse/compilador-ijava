int				[0-9]+|0x[a-f0-9]+
id				[a-zA-Z_][a-zA-Z_0-9]*
reserved		"null"|"volatile"|"try"|"transient"|"throw""s"?|"this"|"synchronized"|"switch"|"super"|"short"|"protected"|"private"|"package"|"long"|"interface"|"instanceof"|"import"|"goto"|"for"|"float"|"finally"|"final"|"extends"|"double"|"do"|"char"|"catch"|"case"|"byte"|"break"|"assert"|"abstract"
op1				"&&"|"||"
op2				"<"|">"|"=="|"!="|"<="|">="
op3				"+"|"-"
op4				"*"|"/"|"%"

%S COMMENT
%%
"//".*
"/*"						{BEGIN COMMENT;}
<COMMENT>"*/"				{BEGIN 0;}
<COMMENT><<EOF>>			{BEGIN 0; printf("Line <num linha>, col <num coluna>: unterminated COMMENT\n");}
<COMMENT>.|\n

<INITIAL>"System.out.println" 	{printf("PRINT\n");}
<INITIAL>"Integer.parseInt"		{printf("PARSEINT\n");}
<INITIAL>".length" 				{printf("DOTLENGTH\n");}

<INITIAL>int					{printf("INT\n");}
<INITIAL>boolean				{printf("BOOL\n");}
<INITIAL>void					{printf("VOID\n");}
<INITIAL>String 				{printf("STRING\n");}

<INITIAL>if						{printf("IF\n");}
<INITIAL>else 					{printf("ELSE\n");}
<INITIAL>while 					{printf("WHILE\n");}
<INITIAL>class 					{printf("CLASS\n");}
<INITIAL>public 				{printf("PUBLIC\n");}
<INITIAL>private 				{printf("PRIVATE\n");}
<INITIAL>static 				{printf("STATIC\n");}
<INITIAL>return 				{printf("RETURN\n");}

<INITIAL>"(" 					{printf("OCURV\n");}
<INITIAL>")" 					{printf("CCURV\n");}
<INITIAL>"{" 					{printf("OBRAVE\n");}
<INITIAL>"}" 					{printf("CBRAVE\n");}
<INITIAL>"[" 					{printf("OSQUARE\n");}
<INITIAL>"]" 					{printf("CSQUARE\n");}
<INITIAL>"!"					{printf("NOT\n");}
<INITIAL>"="					{printf("ASSIGN\n");}
<INITIAL>";"					{printf("SEMIC\n");}
<INITIAL>","					{printf("COMMA\n");}

<INITIAL>{reserved}				{printf("RESERVED\n");}
<INITIAL>{op1}					{printf("OP1\n");}
<INITIAL>{op2}					{printf("OP2\n");}
<INITIAL>{op3}					{printf("OP3\n");}
<INITIAL>{op4}					{printf("OP4\n");}

<INITIAL>{int}					{printf("INTLIT(%s)\n", yytext);}
<INITIAL>{id} 					{printf("ID(%s)\n", yytext);}
<INITIAL>[ \t\n]
<INITIAL>.						{printf("Line <num linha>, col <num coluna>: illegal character ('%s')\n", yytext);}

%%
int main() {
	yylex();
}

int yywrap() {
	return 1;
}
