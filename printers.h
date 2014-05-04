void printStatement(Statement*);
void printExp(Exp*);

char* OperSymbols[] = {"Not", "Or", "And", "Eq", "Neq", "Lt", "Gt", "Leq", "Geq", "Add", "Sub", "Mul", "Div", "Mod", "Minus", "Plus", "NewInt", "NewBool", "Length", "ParseArgs", "LoadArray", "Call"};
int identation = 0;
int isParams = 0;


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
	ident(); printf("%s\n", OperSymbols[(int) type]);

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
	printf("Print\n");

	identation++;
	printExp(print->value);
	identation--;
}

void printIf(IfElse* ifelse) {
	printf("IfElse\n");

	identation++;
	printExp(ifelse->condition);
	if(ifelse->first != NULL && ifelse->first->next != NULL){
		ident();
		printf("CompoundStat\n");
		identation++;
		printStatement(ifelse->first);
		identation--;
	}
	else
		printStatement(ifelse->first);

	if(ifelse->second != NULL && ifelse->second->next != NULL){
		ident();
		printf("CompoundStat\n");
		identation++;
		printStatement(ifelse->second);
		identation--;
	}
	else
		printStatement(ifelse->second);
	identation--;
}

void printWhile(While* _while) {
	printf("While\n");

	identation++;
	printExp(_while->condition);

	if(_while->statement != NULL && _while->statement->next != NULL){
		ident();
		printf("CompoundStat\n");
		identation++;
		printStatement(_while->statement);
		identation--;
	}
	else
		printStatement(_while->statement);
	identation--;
}

void printReturn(Return* _return) {
	printf("Return\n");

	identation++;
	printExp(_return->value);
	identation--;
}

void printStatement(Statement* state) {
	ident();

	if (state == NULL) {
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
