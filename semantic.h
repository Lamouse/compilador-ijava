Program* program;
int hasErrors = 0;

// Reports
void reportMissingSymbol(char* name) {
	hasErrors = 1;
	printf("Cannot find symbol %s\n", name);
} 


// Utillity
Type findVarType(VarDecl* var, char* name) {
	Ids* id;

	while (var != NULL) {
		for (id = var->ids; id != NULL; id = id->next) {
			if (!strcmp(name, id->name))
				return var->type;
		}

		var = var->next;
	}

	return Void;
}


Type findFieldType(char* name) {
	Declaration* decl;
	Type type;
	
	for (decl = program->declarations; decl != NULL; decl = decl->next)
		if (!decl->isMethod) {
			type = findVarType(&decl->content.var, name);
			if (type != Void)
				return type;
		}

	return Void;
}

Type getFieldType(char* name) {
	Type type = findFieldType(name);
	if (type == Void)
		reportMissingSymbol(name);

	return type;
}

Type getVarType(MethodDecl* method, char* name) {
	Type type = findVarType(method->params, name);

	if (type == Void) {
		type = findVarType(method->vars, name);

		if (type == Void) {
			type = findFieldType(name);
			if (type == Void)
				reportMissingSymbol(name); 
		}
	}

	return type;
}


// Error-Checking

code ici