Program* program;
MethodDecl* method;
int hasErrors = 0;

// Reports
void reportMissingSymbol(char* name) {
	if (!hasErrors) {
		hasErrors = 1;
		printf("Cannot find symbol %s\n", name);
	}
}

void reportOperatorType(ExpType oper, Type type) {
	if (!hasErrors) {
		hasErrors = 1;
		printf("Operator OPER cannot be applied to type %s\n", getTypeSymbol(type));
	}
}

void reportOperatorTypes(ExpType oper, Type a, Type b) {
	if (!hasErrors) {
		hasErrors = 1;
		printf("Operator OPER cannot be applied to types %s, %s\n", getTypeSymbol(a), getTypeSymbol(b));
	}
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

Type getVarType(char* name) {
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
						if(!strcmp(id1->name, id2->name)) {
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

int checkDuplicateIdsVarDecl(VarDecl* var1, VarDecl* var2){
	Ids* id1, *id2;

	for(id1 = var1->ids; id1 != NULL; id1 = id1->next){
		for (id2 = var2->ids; id2 != NULL && id1 != id2; id2 = id2->next) {
			if(!strcmp(id1->name, id2->name)){
				printf("Symbol %s already defined\n", id1->name);
				return 1;
			}
		}
	}
	return 0;
}

int checkDuplicateIdsVarDecls(VarDecl* var1, VarDecl* var2){
	VarDecl* id1;
	Ids* id2;

	for(id1 = var1; id1 != NULL; id1 = id1->next){
		for (id2 = var2->ids; id2 != NULL; id2 = id2->next) {
			if(!strcmp(id1->ids->name, id2->name)){
				printf("Symbol %s already defined\n", id1->ids->name);
				return 1;
			}
		}
	}
	return 0;
}

int checkLocalVars(MethodDecl* decl) {
	VarDecl* params = decl->params;
	VarDecl* atual;
	VarDecl* temp;
	Ids* id1;

	//check params
	for(atual = params->next; atual != NULL; atual = atual->next){
		if(checkDuplicateIdsVarDecls(atual, params))
			return 1;
	}

	//check vars
	for(atual = decl->vars; atual != NULL; atual = atual->next){
		if(checkDuplicateIdsVarDecls(atual, params))
			return 1;
		for(temp = decl->vars; temp != NULL && temp != atual; temp = temp->next){
			if(checkDuplicateIdsVarDecl(atual, temp))
				return 1;
		}
		if(checkDuplicateIdsVarDecl(atual, atual))
			return 1;
		for(id1 = atual->ids; id1 != NULL; id1 = id1->next){
			if(findFieldType(id1->name) != Void){
				printf("Symbol %s already defined\n", id1->name);
				return 1;
			}
		}		
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

		if(decl->isMethod){
			if(checkLocalVars(&decl->content.method) == 1){
				hasErrors = 1;
				return;
			} 
		} 
	}
}


// Expressions
Type getExpType(Exp* exp);

Type getOperResultType(ExpType type, Oper* oper) {
	Type a = getExpType(oper->params);
	Type b = a != Void ? getExpType(oper->params->next) : Void;

	if (type == Not) {
		if (a != Bool)
			reportOperatorType(type, a);

		return Bool;

	} else if (type >= Or && type <= And) {
		if (a != Bool || b != Bool)
			reportOperatorTypes(type, a, b);

		return Bool;

	} else if (type >= Add && type <= Mod) {
		if (a != Int || b != Int)
			reportOperatorTypes(type, a, b);

		return Int;

	} else if (type == Length) {
		if (a < StringArray)
			reportOperatorType(type, a);

		return Int;

	} else if (type == Parse) {
		if (a != StringArray)
			reportOperatorType(type, a);

		return Int;

	} else if (type == LoadArray) {
		Type arrayType = getVarType(oper->id);
		if (arrayType < StringArray || a != Int)
			printf("WE FOUND LoadArray error!\n");

		return arrayType - 3;
	}

	return Void;
}

Type getExpType(Exp* exp) {
	if (exp == NULL)
		return Void;
	else if (exp->type == Id)
		return getVarType(exp->content.id);
	else if (exp->type == IntLit)
		return Int;
	else if (exp->type == BoolLit)
		return Bool;
	else
		return getOperResultType(exp->type, &exp->content.oper);
}


// Statements
void checkStatement(Statement* state);
void checkStore(Store* store) {
	Type type = getVarType(store->target);
	Type gotten = getExpType(store->value);

	if (type >= StringArray) {
		Type index = getExpType(store->index);
		Type stored = type - 3;

		if (!hasErrors) {
			if (index != Int)
				printf("INDEX ERROR, got type %s\n", getTypeSymbol(index));
			else if (stored != gotten)
				printf("Incompatible type in assignment to %s[] (got %s, required %s)\n", store->target,
					getTypeSymbol(gotten), getTypeSymbol(stored));
		}
	} else if (!hasErrors && type != gotten) {
		printf("Incompatible type in assignment to %s (got %s, required %s)\n", store->target,
			getTypeSymbol(gotten), getTypeSymbol(type));
	}
}

void checkPrint(Print* print) {
	Exp* val;
	for (val = print->value; val != NULL; val = val->next)
		getExpType(val);
}

void checkIf(IfElse* ifelse) {
	getExpType(ifelse->condition);
	checkStatement(ifelse->first);
	checkStatement(ifelse->second);
}

void checkWhile(While* _while) {
	getExpType(_while->condition);
	printStatement(_while->statement);
}

void checkReturn(Return* _return) {
	Type returned = getExpType(_return->value);
	if (returned != method->type)
		printf("Incompatible type in return statement (got %s, required %s)\n",
			getTypeSymbol(returned), getTypeSymbol(method->type));
}


void checkStatement(Statement* state) {
	if (state == NULL)
		return;
	else if (state->type == IfType)
		checkIf(&state->content.ifelse);
	else if (state->type == WhileType)
		checkWhile(&state->content._while);
	else if (state->type == ReturnType)
		checkReturn(&state->content._return);
	else if (state->type == StoreType)
		checkStore(&state->content.store);
	else if (state->type == PrintType)
		checkPrint(&state->content.print);
}

void checkTypeIssues() {
	Declaration* decl;
	Statement* state;

	for (decl = program->declarations; decl != NULL; decl = decl->next) {
		if (decl->isMethod) {
			method = &decl->content.method;

			for (state = decl->content.method.statements; state != NULL; state = state->next) {
				checkStatement(state);
				if (hasErrors)
					return;
			}
		}
	}
}
