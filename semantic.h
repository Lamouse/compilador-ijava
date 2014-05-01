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


// Duplicate Detection
int checkOldDeclaration(Declaration* decl) {
	Declaration* tempDecl;
	VarDecl* varDecl, *varTempDecl;
	Ids* id1, *id2;

	for (tempDecl = program->declarations; tempDecl != NULL; tempDecl = tempDecl->next) {
		if(decl->isMethod == tempDecl->isMethod){
			if(decl->isMethod && tempDecl->isMethod){
				if(decl != tempDecl && !strcmp(decl->content.method.id, tempDecl->content.method.id)){
					printf("Symbol %s already defined\n", decl->content.method.id);
					return 1;
				}
			}
			else{
				varDecl = &decl->content.var;
				varTempDecl = &tempDecl->content.var;
				for(id1 = varDecl->ids; id1 != NULL; id1 = id1->next){
					for(id2 = varTempDecl->ids; id2 != NULL && id1 != id2; id2 = id2->next){
						if(!strcmp(id1->name, id2->name)){
							printf("Symbol %s already defined\n", id1->name);
							return 1;
						}
					}
				}
			}
		}

		if(tempDecl == decl)
			return 0;
	}
	return 0;	
}

void checkDuplicateDeclaration() {
	Declaration* decl;	

	for (decl = program->declarations; decl != NULL; decl = decl->next) {
		if(checkOldDeclaration(decl) == 1){
			hasErrors = 1;
			return;
		} 
	}
}


// Compatiblity Errors

i code ici