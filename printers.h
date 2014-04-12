int identation = 0;

void ident() {
	int i;
	for (i = 0; i < identation; ++i)
		printf("\t");
}

void printType(Type type) {
	if (type == String)
		printf("String\n");
	else if (type == Bool)
		printf("Bool");
	else if (type == Int)
		printf("Bool");
	else if (type == StringArray)
		printf("StringArray");
	else if (type == BoolArray)
		printf("BoolArray");
	else if (type == IntArray)
		printf("IntArray");
	else if (type == Void)
		printf("Void");
}

void printMethod(MethodDecl* method) {
	if (method == NULL)
		return;

	ident(); printf("MethodDecl\n"); identation++;
	ident(); printType(method->type);
	ident(); printf("ID(%s)\n", method->id);

	ident(); printf("MethodParams\n"); identation++;
	//display(method->params);
	identation--;

	ident(); printf("MethodBody\n"); identation++;
	//display(method->vars);
	//display(method->statements);
	identation-=2;

	printMethod(method->next);
}

void printProgram(Program* program) {
	ident(); printf("Program\n"); identation++;
	ident(); printf("ID(%s)\n", program->id);

	printMethod(program->methods);
	//display(program->vars);
	identation--;
}