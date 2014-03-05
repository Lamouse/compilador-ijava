id				[a-zA-Z_][a-zA-Z_0-9]*
reserved		("null"|"volatile"|"try"|"transient"|"throw""s"?|"this"|"synchronized"|"switch"|"super"|"short"|"protected"|"private"|"package"|"long"|"interface"|"instanceof"|"import"|"goto"|"for"|"float"|"finally"|"final"|"extends"|"double"|"do"|"char"|"catch"|"case"|"byte"|"break"|"assert"|"abstract")
op1				("&&"|"||")
op2				("<"|">"|"=="|"!="|"<="|">=")
op3				("+"|"-")
op4				("*"|"/"|"%")

%%
{reserved}		{printf("RESERVED\n");}
{op1}			{printf("OP1\n");}
{op2}			{printf("OP2\n");}
{op3}			{printf("OP3\n");}
{op3}			{printf("OP4\n");}

"int"			{printf("INT\n");}
"boolean"		{printf("BOOL\n");}
"void" 			{printf("VOID\n");}
"String" 		{printf("STRING\n");}

"if"			{printf("IF\n");}
"else" 			{printf("ELSE\n");}
"while" 		{printf("WHILE\n");}
"class" 		{printf("CLASS\n");}
"public" 		{printf("PUBLIC\n");}
"static" 		{printf("STATIC\n");}
"return" 		{printf("RETURN\n");}
"(" 			{printf("OCURV\n");}
")" 			{printf("CCURV\n");}
"{" 			{printf("OBRAVE\n");}
"}" 			{printf("CBRAVE\n");}
"[" 			{printf("OSQUARE\n");}
"]" 			{printf("CSQUARE\n");}

"!"				{printf("NOT\n");}
"="				{printf("ASSIGN\n");}
";"				{printf("SEMIC\n");}
","				{printf("COMMA\n");}

"System.out.println" 	{printf("PRINT\n");}
"Integer.parseInt"		{printf("PARSEINT\n");}
".length" 				{printf("DOTLENGTH\n");}

"//".*
"/*""*/"

{id}			{printf("ID(%s)\n", &yytext);}
	
%%
int main() {
	yylex();
}

int yywrap() {
	return 1;
}
