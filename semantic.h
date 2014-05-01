Program* program;
int hasErrors = 0;


// Utillity
Type getFieldType(char* name) {
	return Void;
}

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

Type getVarType(MethodDecl* method, char* name) {
	Type type = findVarType(method->params, name);

	if (type == Void) {
		type = findVarType(method->vars, name);

		if (type == Void) {
			type = getFieldType(name); 
		}
	}

	return type;
}


// Error-Checking

code ici