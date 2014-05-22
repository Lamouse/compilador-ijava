int geraInd;
int geraVar;
int geraIf;
int geraWhile;

// Statics
void geraIndentacao() {
	int i;
	for (i = 0; i < geraInd; ++i)
		printf("  ");
}

void generateType(Type type) {
	if (type == String)
		printf("i8*");
	else if (type == Bool)
		printf("i1");
	else if (type == Int)
		printf("i32");
	else if (type == StringArray)
		printf("i8**");
	else if (type == BoolArray)
		printf("i1*");
	else if (type == IntArray)
		printf("i32*");
	else if (type == Void)
		printf("void");
}


// Expressions
void generateExp(Exp* exp);
void generateOper(Exp* exp) {
	int temp;
	ExpType type = exp->type;
	Oper* oper = &exp->content.oper;
	Type a = getExpType(oper->params);
	Type b = a != Void ? getExpType(oper->params->next) : Void;

	generateExp(oper->params);

	if(type == Not) {
		geraIndentacao();
		printf("%%%d = add i1 %s, 1\n", geraVar, oper->params->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Or) {
		temp = geraVar++;
		geraIndentacao();
		printf("%%%d = alloca i1", temp);
		geraIndentacao();
		printf("%%%d = icmp eq i1 %s, 0\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, geraIf, geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("then%d:\n", geraIf);
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->next->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("else%d:\n", geraIf);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("ifcont%d:\n", geraIf++);
		geraIndentacao();
		printf("%%%d = load i1* %%%d", geraVar, temp);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == And) {
		temp = geraVar++;
		geraIndentacao();
		printf("%%%d = alloca i1", temp);
		geraIndentacao();
		printf("%%%d = icmp eq i1 %s, 1\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, geraIf, geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("then%d:\n", geraIf);
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->next->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("else%d:\n", geraIf);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("ifcont%d:\n", geraIf++);
		geraIndentacao();
		printf("%%%d = load i1* %%%d", geraVar, temp);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Eq) {
		generateExp(oper->params->next);
		geraIndentacao();
		if(a == Int)
			printf("%%%d = icmp eq i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		else
			printf("%%%d = icmp eq i1 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Neq) {
		generateExp(oper->params->next);
		geraIndentacao();
		if(a == Int)
			printf("%%%d = icmp ne i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		else
			printf("%%%d = icmp ne i1 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Lt) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = icmp slt i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Gt) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = icmp sgt i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Leq) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = icmp sle i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Geq) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = icmp sge i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Add) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = add i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Sub) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = sub nsw i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Mul) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = mul i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Div) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = sdiv i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Mod) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = srem i32 %s, %s\n", geraVar, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Minus) {
		geraIndentacao();
		printf("%%%d = mul i32 %s, -1\n", geraVar, oper->params->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Plus) {
		return;
	} else if (type == NewInt || type == NewBool) {
		asprintf(&exp->var, "%s", oper->params->var);
	} else if (type == LoadArray) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = load ", geraVar);
		generateType(a);
		printf("* %s\n", oper->params->var);

		geraIndentacao();
		printf("%%%d = getelementptr ", geraVar+1);
		generateType(a);
		printf(" %%%d, i32 %s\n", geraVar, oper->params->next->var);
		geraIndentacao();
		printf("%%%d = load ", geraVar+2);
		generateType(a);
		printf(" %%%d\n", geraVar+1);

		asprintf(&exp->var, "%%%d", geraVar+2);
		geraVar += 3;
	} else if (type == Call) {
		MethodDecl* method = getMethod(oper->id);
		Exp* value = oper->params;
		Type given;
		
		while(value != NULL) {
			generateExp(value);
			value = value->next;
		}

		geraIndentacao();
		printf("%%%d = call ", geraVar);
		generateType(method->type);
		printf(" @%s(", oper->id);

		value = oper->params;
		if(value != NULL) {
			given = getExpType(value);
			generateType(given);
			printf(" %s", value->var);
			value = value->next;
			while(value != NULL) {
				printf(", ");
				given = getExpType(value);
				generateType(given);
				printf(" %s", value->var);
				value = value->next;			
			}
		}

		printf(")\n");
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Length) {
		geraIndentacao();
		printf("%%%d = load i32* %s.length\n", geraVar,oper->params->var);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Parse) {
		geraIndentacao();
		printf("%%%d = add i32 %s, 1\n", geraVar, oper->params->var);

		geraIndentacao();
		printf("%%%d = getelementptr i8** %%%s, i32 %%%d\n", geraVar+1, oper->id, geraVar);

		geraIndentacao();
		printf("%%%d = load i8** %%%d\n", geraVar+2, geraVar+1);

		geraIndentacao();
		printf("%%%d = call i32 (i8*)* @atoi(i8* %%%d)\n", geraVar+3, geraVar+2);

		asprintf(&exp->var, "%%%d", geraVar+3);
		geraVar += 4;
	}
}

void generateExp(Exp* exp) {
	int aux;
	char aux2;
	Type a;

	if (exp == NULL) {
		return;
	} else if (exp->type == Id) {
		if(findFieldType(exp->content.literal) == Void)
			aux2 = '%';
		else
			aux2 = '@';

		a = getExpType(exp);
		if(a >= StringArray)
			asprintf(&exp->var, "%c%s", aux2, exp->content.literal);
		else{
			geraIndentacao();
			printf("%%%d = load ", geraVar);
			generateType(getVarType(method, exp->content.id));
			printf("* %c%s\n", aux2, exp->content.literal);

			geraIndentacao();
			printf("%%%d = add ", geraVar+1);
			generateType(getVarType(method, exp->content.id));
			printf(" %%%d, 0\n", geraVar++);
			asprintf(&exp->var, "%%%d", geraVar++);
		}
	} else if (exp->type == IntLit) {
		geraIndentacao();
		printf("%%%d = add i32 %s, 0\n", geraVar, exp->content.literal);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (exp->type == BoolLit) {
		geraIndentacao();
		aux = 0;
		if(!strcmp(exp->content.literal, "true"))
			aux = 1;
		printf("%%%d = add i1 %d, 0\n", geraVar, aux);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else
		generateOper(exp);
}


// Statements
void generateStatement(Statement* state);

void generateReturn(Return* _return) {
	printf("\n");
	generateExp(_return->value);

	geraIndentacao();
	printf("ret ");
	generateType(method->type);
	if(method->type == Void)
		printf("\n");
	else
		printf(" %s\n", _return->value->var);
}

void generatePrint(Print* print) {
	printf("\n");
	generateExp(print->value);
	if(getExpType(print->value) == Int) {
		geraIndentacao();
		printf("%%%d = getelementptr [4 x i8]* @str.int, i32 0, i32 0\n", geraVar);
		geraIndentacao();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d, i32 %s)\n", geraVar+1, geraVar, print->value->var);
		geraVar += 2;
	}
	else{
		geraIndentacao();
		printf("%%%d = icmp eq i1 %s, 0\n", geraVar, print->value->var);
		geraIndentacao();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, geraIf, geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("then%d:\n", geraIf);
		geraIndentacao();
		printf("%%%d = getelementptr [7 x i8]* @str.false, i32 0, i32 0\n", geraVar);
		geraIndentacao();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d)\n", geraVar + 1, geraVar);
		geraIndentacao();
		geraVar += 2;
		printf("br label %%ifcont%d\n", geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("else%d:\n", geraIf);
		geraIndentacao();
		printf("%%%d = getelementptr [6 x i8]* @str.true, i32 0, i32 0\n", geraVar);
		geraIndentacao();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d)\n", geraVar + 1, geraVar);
		geraIndentacao();
		geraVar += 2;
		printf("br label %%ifcont%d\n", geraIf);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("ifcont%d:\n", geraIf++);
	}
}

void generateStore(Store* store) {
	char aux2;
	Type a = getExpType(store->value);;

	if(findFieldType(store->target) == Void)
		aux2 = '%';
	else
		aux2 = '@';

	printf("\n");
	generateExp(store->value);
	if(store->index == NULL){
		if(a > StringArray){
			geraIndentacao();
			printf("%%%d = call noalias i8* @malloc(i32 %s)\n", geraVar, store->value->var);
			geraIndentacao();
			printf("%%%d = bitcast i8* %%%d to ", geraVar+1, geraVar);
			generateType(a);
			printf("\n");
			geraIndentacao();
			printf("store ");
			generateType(a);
			printf(" %%%d, ", geraVar+1);
			generateType(a);
			printf("* %c%s\n", aux2, store->target);
			geraIndentacao();
			printf("store i32 %s, i32* %c%s.length\n", store->value->var, aux2, store->target);
			geraVar += 2;
		}
		else{
			geraIndentacao();
			printf("%%%d = getelementptr ", geraVar);
			generateType(a);
			printf("* %c%s, i32 0\n", aux2, store->target);
			geraIndentacao();
			printf("store ");
			generateType(a);
			printf(" %s, ", store->value->var);
			generateType(a);
			printf("* %%%d\n", geraVar++);
		}
	}
	else{
		generateExp(store->index);
		geraIndentacao();
		printf("%%%d = load ", geraVar);
		generateType(a);
		printf("** %c%s\n", aux2, store->target);

		geraIndentacao();
		printf("%%%d = getelementptr ", geraVar+1);
		generateType(a);
		printf("* %%%d, i32 %s\n", geraVar, store->index->var);
		geraIndentacao();
		printf("store ");
		generateType(a);
		printf(" %s, ", store->value->var);
		generateType(a);
		printf("* %%%d\n", geraVar+1);

		geraVar += 2;
	}
}

void generateIf(IfElse* ifelse) {

}

void generateWhile(While* _while) {
	printf("\n");

	geraIndentacao();
	printf("br label %%cond%d\n", geraWhile);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("cond%d:\n", geraWhile);
	generateExp(_while->condition);
	geraIndentacao();
	printf("%%%d = icmp eq i1 %s, 1\n", geraVar, _while->condition->var);
	geraIndentacao();
	printf("br i1 %%%d, label %%while%d, label %%whilecont%d\n", geraVar++, geraWhile, geraWhile);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("while%d:\n", geraWhile);
	if(_while->statement != NULL)
		generateStatement(_while->statement);

	geraIndentacao();
	printf("br label %%cond%d", geraWhile);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("whilecont%d:\n", geraWhile);
	geraWhile++;
}

void generateComp(Comp* comp) {
	if(comp->value != NULL)
		generateStatement(comp->value);
}

void generateStatement(Statement* state) {
	if (state->type == IfType)
		generateIf(&state->content.ifelse);
	else if (state->type == ReturnType)
		generateReturn(&state->content._return);
	else if (state->type == WhileType)
		generateWhile(&state->content._while);
	else if (state->type == StoreType)
		generateStore(&state->content.store);
	else if (state->type == PrintType)
		generatePrint(&state->content.print);
	else if (state->type == CompType)
		generateComp(&state->content.comp);

	if (state->next != NULL)
		generateStatement(state->next);
}

void generateLVar(VarDecl* var) {
	Ids* ids;

	if (var == NULL)
		return;
	ids = var->ids;

	while(ids != NULL){
		geraIndentacao();
		printf("%%%s = alloca ", ids->name);
		generateType(var->type);
		printf("\n");
		if(var->type > StringArray){
			geraIndentacao();
			printf("%%%s.length = alloca i32\n", ids->name);
		}
		ids = ids->next;
	}
	generateLVar(var->next);
}


// Declarations
void generateParam(VarDecl* var) {
	VarDecl* aux;

	if(var != NULL){
		if(var->type >= StringArray) {
			printf("i32 %%%s.tam, ", var->ids->name);
			generateType(var->type);
			printf(" %%%s) {\n", var->ids->name);
			printf("  entry:\n");
			geraIndentacao();
			printf("%%%s.length = alloca i32\n", var->ids->name);
			geraIndentacao();
			printf("%%%d = add i32 %%%s.tam, -1\n", geraVar, var->ids->name);
			geraIndentacao();
			printf("store i32 %%%d, i32* %%%s.length\n\n", geraVar++, var->ids->name);
			return;
		}
		generateType(var->type);
		printf(" %%%s.temp", var->ids->name);
		aux = var->next;
		while(aux != NULL){
			printf(", ");
			generateType(aux->type);
			printf(" %%%s.temp", aux->ids->name);
			aux = aux->next;
		}
		printf(") {\n");
		printf("  entry:\n");
		aux = var;
		while(aux != NULL){
			geraIndentacao();
			printf("%%%s = alloca ", aux->ids->name);
			generateType(aux->type);
			printf("\n");

			geraIndentacao();
			printf("store ");
			generateType(aux->type);
			printf(" %%%s.temp, ", aux->ids->name);
			generateType(aux->type);
			printf("* %%%s\n", aux->ids->name);
			aux = aux->next;
		}
	}
}

void generateGVar(VarDecl* var) {
	Ids* ids;

	if (var == NULL)
		return;
	ids = var->ids;

	while(ids != NULL){
		printf("@%s = common global ", ids->name);
		generateType(var->type);
		if(var->type >= StringArray)
			printf(" null\n");
		else
			printf(" 0\n");
		ids = ids->next;
	}
}

void generateMethod(MethodDecl* method) {
	geraInd = 2;
	geraVar = 0;
	geraIf = 0;
	geraWhile = 0;

	printf("\ndefine ");
	generateType(method->type);
	printf(" @%s(", method->id);
	generateParam(method->params);
	generateLVar(method->vars);
	if(method->statements != NULL)
		generateStatement(method->statements);

	printf("}\n\n");
}

void generateDeclaration(Declaration* decl) {
	if (decl != NULL) {
		if (decl->isMethod) {
			method = &decl->content.method;
			generateMethod(&decl->content.method);
		} else {
			generateGVar(&decl->content.var);
		}

		generateDeclaration(decl->next);
	}
}

void generateFunction() {
	printf("\n");
	printf("declare i32 @atoi(i8*)\n");
	printf("declare noalias i8* @malloc(i32)\n");
	printf("declare i32 @printf(i8*, ...) nounwind\n");
	printf("@str.int = internal constant [4 x i8] c\"%%d\\0A\\00\"\n");
	printf("@str.true = private unnamed_addr constant [6 x i8] c\"true\\0A\\00\"\n");
	printf("@str.false = private unnamed_addr constant [7 x i8] c\"false\\0A\\00\"\n");
}

void generateProgram(Program* program) {
	generateDeclaration(program->declarations);
	generateFunction();
}
