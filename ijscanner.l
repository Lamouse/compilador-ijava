boollit			("true"|"false")
int				"int"
bool			"boolean"
new 			"new"
if 				"if"
else 			"else"
while 			"while"
print 			"System.out.println"
parseint		"Integer.parseInt"
class 			"class"
public			"public"
static			"static"
void			"void"
string			"String"
dotlength		".length"
return			"return"
ocurv			"("
ccurv			")"
obrave			"{"
cbrave			"}"
osquare			"["
csquare			"]"
op1				("&&"|"||")
op2				("<"|">"|"=="|"!="|"<="|">=")
op3				("+"|"-")
op4				("*"|"/"|"%")
not				"!"
assign			"="
semic			";"
comma			","
reserved		("null"|"volatile"|"try"|"transient"|"throw""s"?|"this"|"synchronized"|"switch"|"super"|"short"|"protected"|"private"|"package"|"long"|"interface"|"instanceof"|"import"|"goto"|"for"|"float"|"finally"|"final"|"extends"|"double"|"do"|"char"|"catch"|"case"|"byte"|"break"|"assert"|"abstract")
%%
{boollit}		{printf("BOOLLIT\n");}
{int}			{printf("INT\n");}
{bool}			{printf("BOOL\n");}

{reserved}		{printf("RESERVED\n");}
.
\n			
%%
int main() {
	yylex();
}

int yywrap() {
	return 1;
}
