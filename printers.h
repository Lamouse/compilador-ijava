void printStatement(Statement*);
void printExp(Exp*);
void printComp(Comp* comp);

int identation = 0;
int isParams = 0;
int isComp = 0;


// Statics
void ident() {
	int i;
	for (i = 0; i < identation; ++i)
		printf("  ");
}

void printType(Type type) {
	ident();

	if (type == String)
		printf("String\n");
	else if (type == Bool)
		printf("Bool\n");
	else if (type == Int)
		printf("Int\n");
	else if (type == StringArray)
		printf("StringArray\n");
	else if (type == BoolArray)
		printf("BoolArray\n");
	else if (type == IntArray)
		printf("IntArray\n");
	else if (type == Void)
		printf("Void\n");
}

void printId(char* id) {
	if (id != NULL) {
		ident(); printf("Id(%s)\n", id);
	}
}

void printIds(Ids* ids) {
	if (ids != NULL) {
		printId(ids->name);
		printIds(ids->next);
	}
}


// Expressions
void printOper(ExpType type, Oper* oper) {
	ident(); printf("%s\n", OperNames[(int) type]);

	identation++;
	printId(oper->id);
	printExp(oper->params);
	identation--;
}

void printExp(Exp* exp) {
	if (exp == NULL) {
		return;
	} else if (exp->type == Id) {
		printId(exp->content.id);
	} else if (exp->type == IntLit) {
		ident(); printf("IntLit(%s)\n", exp->content.literal);
	} else if (exp->type == BoolLit) {
		ident(); printf("BoolLit(%s)\n", exp->content.literal);
	} else
		printOper(exp->type, &exp->content.oper);

	printExp(exp->next);
}


// Statements
void printStore(Store* store) {
	ident();
	if(store->index == NULL)
		printf("Store\n");
	else
		printf("StoreArray\n");

	identation++;
	printId(store->target);
	printExp(store->index);
	printExp(store->value);
	identation--;
}

void printPrint(Print* print) {
	ident();
	printf("Print\n");

	identation++;
	printExp(print->value);
	identation--;
}

void printIf(IfElse* ifelse) {
	ident();
	printf("IfElse\n");
	identation++;

	printExp(ifelse->condition);
	if(ifelse->first != NULL){
		if(ifelse->first->type == CompType){
			if(&ifelse->first->content.comp.value != NULL && &ifelse->first->content.comp.value->next != NULL){
				printComp(&ifelse->first->content.comp);
			}
		}
		else
			printStatement(ifelse->first);
	}
	else{
		ident();
		printf("Null\n");
	}
	if(ifelse->second != NULL){
		if(ifelse->second->type == CompType){
			if(&ifelse->second->content.comp.value != NULL && &ifelse->second->content.comp.value->next != NULL){
				printComp(&ifelse->second->content.comp);
			}
		}
		else
			printStatement(ifelse->second);
	}
	else{
		ident();
		printf("Null\n");
	}
	identation--;
}

void printWhile(While* _while) {
	ident();
	printf("While\n");

	identation++;
	printExp(_while->condition);
	if(_while->statement != NULL){
		if(_while->statement->type == CompType)
			if(&_while->statement->content.comp.value != NULL && &_while->statement->content.comp.value->next != NULL){
				printComp(&_while->statement->content.comp);
			}
		else
			printStatement(_while->statement);
	}
	else{
		ident();
		printf("Null\n");
	}
	identation--;
}

void printReturn(Return* _return) {
	ident();
	printf("Return\n");

	identation++;
	printExp(_return->value);
	identation--;
}

void printComp(Comp* comp) {
	if(comp->value != NULL){
		if(comp->value->next != NULL){
			ident();
			printf("CompoundStat\n");
			identation++;
			printStatement(comp->value);
			identation--;
		}
		else{
			printStatement(comp->value);
		}
	}
}

void printStatement(Statement* state) {
	if (state == NULL) {
		ident();
		printf("Null\n");
	} else {
		if (state->type == IfType)
			printIf(&state->content.ifelse);
		else if (state->type == WhileType)
			printWhile(&state->content._while);
		else if (state->type == ReturnType)
			printReturn(&state->content._return);
		else if (state->type == StoreType)
			printStore(&state->content.store);
		else if (state->type == PrintType)
			printPrint(&state->content.print);
		else if (state->type == CompType)
			printComp(&state->content.comp);

		if (state->next != NULL)
			printStatement(state->next);
	}
}


// Declarations
void printVar(VarDecl* var) {
	if (var == NULL)
		return;

	ident();
	if (isParams)
		printf("ParamDeclaration\n");
	else
		printf("VarDecl\n");

	identation++;
	printType(var->type);
	printIds(var->ids);
	identation--;

	printVar(var->next);
}

void printMethod(MethodDecl* method) {
	ident(); printf("MethodDecl\n"); identation++;
	printType(method->type);
	printId(method->id);

	ident(); printf("MethodParams\n");
	identation++; isParams = 1;
	printVar(method->params);
	identation--; isParams = 0;

	ident(); printf("MethodBody\n"); identation++;
	printVar(method->vars);
	if (method->statements != NULL)
		printStatement(method->statements);
	identation-=2;
}

void printDeclaration(Declaration* decl) {
	if (decl != NULL) {
		if (decl->isMethod) {
			printMethod(&decl->content.method);
		} else {
			printVar(&decl->content.var);
		}

		printDeclaration(decl->next);
	}
}

void printProgram(Program* program) {
	ident(); printf("Program\n");

	identation++;
	printId(program->id);
	printDeclaration(program->declarations);
	identation--;
}
