void printTypeSymbol(Type type) {
	if (type == String)
		printf("String");
	else if (type == Bool)
		printf("boolean");
	else if (type == Int)
		printf("int");
	else if (type == StringArray)
		printf("String[]");
	else if (type == BoolArray)
		printf("boolean[]");
	else if (type == IntArray)
		printf("int[]");
	else if (type == Void)
		printf("void");
}

void printSymbol(VarDecl* var, int isParam) {
	Ids* id;

	for (id = var->ids; id != NULL; id = id->next) {
		printf("%s\t", id->name); printTypeSymbol(var->type);
		printf(isParam ? "\tparam\n" : "\n");
	}
}

void printSymbols(VarDecl* var, int areParams) {
	while (var != NULL) {
		printSymbol(var, areParams);
		var = var->next;
	}
}

void printMethodSymbols(MethodDecl* method) {
	printf("\n===== Method %s Symbol Table =====\n", method->id);
	printf("return\t"); printTypeSymbol(method->type); printf("\n");
	printSymbols(method->params, 1);
	printSymbols(method->vars, 0);
}

void printProgramSymbols(Program* program) {
	printf("===== Class %s Symbol Table =====\n", program->id);
	Declaration* decl;
	
	for (decl = program->declarations; decl != NULL; decl = decl->next) {
		if (decl->isMethod) {
			printf("%s\tmethod\n", decl->content.method.id);
		} else {
			printSymbol(&decl->content.var, 0);
		}
	}

	for (decl = program->declarations; decl != NULL; decl = decl->next) {
		if (decl->isMethod) {
			printMethodSymbols(&decl->content.method);
		}
	}
}
