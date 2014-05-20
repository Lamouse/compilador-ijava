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
	char aux = '%';
	Ids* ids = var->ids;

	if (var == NULL)
		return;

	while(ids != NULL){
		printf("%c%s = common global ", '%', ids->name);
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

	printf("}\n");
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

void generateProgram(Program* program) {
	generateDeclaration(program->declarations);
}
