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
		printf("Operator %s cannot be applied to type %s\n", OperSymbols[oper], getTypeSymbol(type));
	}
}

void reportOperatorTypes(ExpType oper, Type a, Type b) {
	if (!hasErrors) {
		hasErrors = 1;
		printf("Operator %s cannot be applied to types %s, %s\n", OperSymbols[oper], getTypeSymbol(a), getTypeSymbol(b));
	}
}

void reportIndexTypes(Type array, Type index) {
	if (array < StringArray || index != Int) 
		reportOperatorTypes(LoadArray, array, index);
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

MethodDecl* getMethod(char* name) {
	Declaration* decl;

	for (decl = program->declarations; decl != NULL; decl = decl->next)
		if (decl->isMethod)
			if (!strcmp(decl->content.method.id, name))
				return &decl->content.method;

	reportMissingSymbol(name);
	return NULL;
}


// Duplicate Detection
int checkOldDeclaration(Declaration* decl) {
	Declaration* tempDecl;
	VarDecl* varDecl, *varTempDecl;
	Ids* id1, *id2;
	char* name;

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
		else{
			if(decl->isMethod){
				name = decl->content.method.id;
				varDecl = &tempDecl->content.var;
			}
			else{
				name = tempDecl->content.method.id;
				varDecl = &decl->content.var;
			}

			for(id1 = varDecl->ids; id1 != NULL; id1 = id1->next){
				if(!strcmp(id1->name, name)) {
					printf("Symbol %s already defined\n", id1->name);
					return 1;
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
			if (!strcmp(id1->name, id2->name)){
				printf("Symbol %s already defined\n", id1->name);
				return 1;
			}
		}
	}
	return 0;
}

int checkDuplicateIdsVarDecls(VarDecl* var1, VarDecl* var2){
	Ids* id1;
	VarDecl* id2;

	for(id1 = var1->ids; id1 != NULL; id1 = id1->next){
		for (id2 = var2; id2 != NULL && id2->ids != id1; id2 = id2->next) {
			if(!strcmp(id1->name, id2->ids->name)){
				printf("Symbol %s already defined\n", id1->name);
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
	if(params != NULL){
		for(atual = params->next; atual != NULL; atual = atual->next){
			//check param and old params
			if(checkDuplicateIdsVarDecls(atual, params))
				return 1;
		}
	}

	for(atual = decl->vars; atual != NULL; atual = atual->next){
		//check vars and params
		if(params != NULL){
			if(checkDuplicateIdsVarDecls(atual, params))
				return 1;
		}

		//check vars and old vars
		for(temp = decl->vars; temp != NULL && temp != atual; temp = temp->next){
			if(checkDuplicateIdsVarDecl(atual, temp))
				return 1;
		}

		//check ids inside vars
		if(checkDuplicateIdsVarDecl(atual, atual))
			return 1;	
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

	} else if (type >= Eq && type <= Neq) {
		if (a != b)
			reportOperatorTypes(type, a, b);

		return a;

	} else if (type >= Lt && type <= Mod) {
		if (a != Int || b != Int)
			reportOperatorTypes(type, a, b);

		return Int;

	} else if (type >= Minus && type <= NewBool) {
		if (a != Int)
			reportOperatorType(type, a);

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
		Type array = getVarType(method, oper->id);
		reportIndexTypes(array, a);

		return hasErrors ? Void : array - 3;

	} else if (type == Call) {
		MethodDecl* method = getMethod(oper->id);

		if (!hasErrors) {
			VarDecl* param = method->params;
			Exp* value = oper->params;
			int i = 1;

			while (value != NULL || param != NULL) {
				Type given = getExpType(value);
				Type expected = param != NULL ? getVarType(method, param->ids->name) : Void;

				if (given != expected) {
					hasErrors = 1;
					printf("Incompatible type of argument %d in call to method %s (got %s, required %s)\n",
						i, method->id, getTypeSymbol(given), getTypeSymbol(expected));
					break;
				}

				value = value->next;
				param = param->next;
				i++;
			}

			return method->type;
		}

	} else if (type == Length) {
		if (a < StringArray)
			reportOperatorType(type, a);

		return Int;

	}  else if (type == Parse) {
		if (a != String) {
			hasErrors = 1;
			printf("Incompatible type of argument 1 in call to method Integer.parseInt (got %s, required String)\n", getTypeSymbol(a));
		}

		return Int;
	}

	return Void;
}

Type getExpType(Exp* exp) {
	if (exp == NULL)
		return Void;
	else if (exp->type == Id)
		return getVarType(method, exp->content.id);
	else if (exp->type == BoolLit)
		return Bool;
	else if (exp->type == IntLit) {
		if (!hasErrors && exp->content.literal[0] == '0' && exp->content.literal[1] != 'x') {
			hasErrors = 1;
			printf("Invalid literal %s\n", exp->content.literal);
		}

		return Int;
	} else
		return getOperResultType(exp->type, &exp->content.oper);
}


// Statements
void checkStatement(Statement* state);
void checkStore(Store* store) {
	Type type = getVarType(method, store->target);
	Type gotten = getExpType(store->value);

	if (store->index != NULL) {
		Type index = getExpType(store->index);
		Type stored = type - 3;
		reportIndexTypes(type, index);

		if (!hasErrors && stored != gotten) {
			hasErrors = 1;
			printf("Incompatible type in assignment to %s[] (got %s, required %s)\n", store->target,
				getTypeSymbol(gotten), getTypeSymbol(stored));
		}
	} else if (!hasErrors && type != gotten) {
		hasErrors = 1;
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
	checkStatement(_while->statement);
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
