void generateType(Type type) {
	if (type == String)
		printf("i8* ");
	else if (type == Bool)
		printf("i1 ");
	else if (type == Int)
		printf("i32 ");
	else if (type == StringArray)
		printf("i8** ");
	else if (type == BoolArray)
		printf("i1* ");
	else if (type == IntArray)
		printf("i32* ");
	else if (type == Void)
		printf("i1 ");
}


// Statements
void generatePrint(Print* print) {
/*	if(getExpType(print->value) == Int) {

	}
	else
*/
}


void generateStatement(Statement* state) {
	if (state->type == PrintType)
		generatePrint(&state->content.print);

	if (state->next != NULL)
		generateStatement(state->next);
}

void generateLVar(VarDecl* var) {
	Ids* ids;

	if (var == NULL)
		return;
	ids = var->ids;

	while(ids != NULL){
		printf("\t%c%s = alloca ", '%', ids->name);
		generateType(var->type);
		printf("\n");
		ids = ids->next;
	}
	generateLVar(var->next);
}


// Declarations
void generateParam(VarDecl* var) {
	if(var != NULL){
		generateType(var->type);
		printf("%c%s", '%', var->ids->name);
		var = var->next;
		while(var != NULL){
			printf(", ");
			generateType(var->type);
			printf("%c%s", '%', var->ids->name);
			var = var->next;
		}
	}
}

void generateGVar(VarDecl* var) {
	Ids* ids;

	if (var == NULL)
		return;
	ids = var->ids;

	while(ids != NULL){
		printf("%c%s = common global ", '@', ids->name);
		generateType(var->type);
		if(var->type >= StringArray)
			printf("null\n");
		else
			printf("0\n");
		ids = ids->next;
	}
}

void generateMethod(MethodDecl* method) {
	printf("\ndefine ");
	generateType(method->type);
	printf("@%s(", method->id);
	generateParam(method->params);
	printf(") {\n");
	generateLVar(method->vars);
	if(method->statements != NULL)
		generateStatement(method->statements);
	printf("}\n\n");
}

void generateDeclaration(Declaration* decl) {
	if (decl != NULL) {
		if (decl->isMethod) {
			generateMethod(&decl->content.method);
		} else {
			generateGVar(&decl->content.var);
		}

		generateDeclaration(decl->next);
	}
}

//
void generateFunction() {
	printf("define i32 @print(i32 %%v, i1 %%t) {\n");
	printf("\tentry:\n");
	printf("\t\t%%ifcond1 = icmp eq i1 %%t, 0\n");
	printf("\t\tbr i1 %%ifcond1, label %%then, label %%else\n");
	printf("\n");
	printf("\tthen:\n");
	printf("\t\t%%cast1 = getelementptr [4 x i8]* @str_int, i32 0, i32 0\n");
	printf("\t\tcall i32 (i8*, ...)* @printf( i8* %%cast1, i32 %%v)\n");
	printf("\t\tbr label %%ifcont\n");
	printf("\n");
	printf("\telse:\n");
	printf("\t\t%%ifcond2 = icmp eq i32 %%v, 0\n");
	printf("\t\tbr i1 %%ifcond2, label %%false, label %%true\n");
	printf("\n");
	printf("\tfalse:\n");
	printf("\t\t%%cast2 = getelementptr [7 x i8]* @str_false, i32 0, i32 0\n");
	printf("\t\tcall i32 (i8*, ...)* @printf( i8* %%cast2)\n");
	printf("\t\tbr label %%ifcont\n");
	printf("\n");
	printf("\ttrue:\n");
	printf("\t\t%%cast3 = getelementptr [6 x i8]* @str_true, i32 0, i32 0\n");
	printf("\t\tcall i32 (i8*, ...)* @printf( i8* %%cast3)\n");
	printf("\t\tbr label %%ifcont\n");
	printf("\n");
	printf("\tifcont:\n");
	printf("\t\tret i32 0\n");
	printf("}\n");
	printf("\n");
	printf("declare i32 @printf(i8*, ...) nounwind\n");
	printf("@str_int = internal constant [4 x i8] c\"%%d\\0A\\00\"\n");
	printf("@str_true = private unnamed_addr constant [6 x i8] c\"true\\0A\\00\"\n");
	printf("@str_false = private unnamed_addr constant [7 x i8] c\"false\\0A\\00\"\n");
}


void generateProgram(Program* program) {
	generateDeclaration(program->declarations);
	generateFunction();
}
