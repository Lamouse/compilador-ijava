void printSymbol(VarDecl* var, int isParam) {
	
}

void printSymbols(VarDecl* var, int areParams) {
	while (var != NULL) {
		printSymbol(var, areParams);
		var = var->next;
	}
}

void printMethodSymbols(MethodDecl* method) {
	printf("===== Method %s Symbol Table =====\n", method->id);
	printf("return "); printTypeName(method->type); printf("\n");
	printSymbols(method->params, 1);
	printSymbols(method->vars, 0);
}

void printProgramSymbols(Program* program) {
	printf("===== Class %s Symbol Table =====\n", program->id);
	Declaration* decl;
	
	for (decl = program->declarations; decl != NULL; decl = decl->next) {
		if (decl->isMethod) {
			printf("%s method\n", decl->content.method.id);
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