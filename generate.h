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
	int temp, temp1;
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
		temp1=geraIf++;
		geraIndentacao();
		printf("%%%d = alloca i1\n", temp);
		geraIndentacao();
		printf("%%%d = icmp eq i1 %s, 0\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, temp1, temp1);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("then%d:\n", temp1);
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->next->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("else%d:\n", temp1);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("ifcont%d:\n", temp1);
		geraIndentacao();
		printf("%%%d = load i1* %%%d\n", geraVar, temp);
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == And) {
		temp = geraVar++;
		temp1=geraIf++;
		geraIndentacao();
		printf("%%%d = alloca i1\n", temp);
		geraIndentacao();
		printf("%%%d = icmp eq i1 %s, 1\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, temp1, temp1);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("then%d:\n", temp1);
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->next->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("else%d:\n", temp1);
		geraIndentacao();
		printf("%%%d = add i1 %s, 0\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("store i1 %%%d, i1* %%%d\n", geraVar++, temp);
		geraIndentacao();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("ifcont%d:\n", temp1);
		geraIndentacao();
		printf("%%%d = load i1* %%%d\n", geraVar, temp);
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
	} else if (type == NewInt) {
		geraIndentacao();
		printf("%%%d = add i32 %s, 1\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("%%%d = mul i32 %%%d, 4\n", geraVar+1, geraVar);
		geraIndentacao();
		printf("%%%d = call noalias i8* @malloc(i32 %%%d)\n", geraVar+2, geraVar+1);
		geraIndentacao();
		printf("%%%d = bitcast i8* %%%d to i32*\n", geraVar+3, geraVar+2);
		geraIndentacao();
		printf("store i32 %s, i32* %%%d\n", oper->params->var, geraVar+3);
		geraIndentacao();
		printf("%%%d = alloca i32*\n",geraVar+4);
		geraIndentacao();
		printf("store i32* %%%d, i32** %%%d\n", geraVar+3, geraVar+4);
		asprintf(&exp->var, "%%%d", geraVar+4);
		geraVar += 5;
	} else if (type == NewBool) {
		geraIndentacao();
		printf("%%%d = add i32 %s, 4\n", geraVar, oper->params->var);
		geraIndentacao();
		printf("%%%d = call noalias i8* @malloc(i32 %%%d)\n", geraVar+1, geraVar);
		geraIndentacao();
		printf("%%%d = bitcast i8* %%%d to i1*\n", geraVar+2, geraVar+1);
		geraIndentacao();
		printf("%%%d = bitcast i1* %%%d to i32*\n", geraVar+3, geraVar+2);
		geraIndentacao();
		printf("store i32 %s, i32* %%%d\n", oper->params->var, geraVar+3);
		geraIndentacao();
		printf("%%%d = alloca i1*\n",geraVar+4);
		geraIndentacao();
		printf("store i1* %%%d, i1** %%%d\n", geraVar+2, geraVar+4);
		asprintf(&exp->var, "%%%d", geraVar+4);

		geraVar += 5;
	} else if (type == LoadArray) {
		generateExp(oper->params->next);
		geraIndentacao();
		printf("%%%d = load ", geraVar);
		generateType(a);
		printf("* %s\n", oper->params->var);

		if(a == BoolArray){
			geraIndentacao();
			printf("%%%d = add i32 %s, 4\n", geraVar+1, oper->params->next->var);
		}
		else{
			geraIndentacao();
			printf("%%%d = add i32 %s, 1\n", geraVar+1, oper->params->next->var);
		}

		geraIndentacao();
		printf("%%%d = getelementptr ", geraVar+2);
		generateType(a);
		printf(" %%%d, i32 %%%d\n", geraVar, geraVar+1);
		geraIndentacao();
		printf("%%%d = load ", geraVar+3);
		generateType(a);
		printf(" %%%d\n", geraVar+2);

		asprintf(&exp->var, "%%%d", geraVar+3);
		geraVar += 4;
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
			if(given >= StringArray)
				printf("*");
			printf(" %s", value->var);
			value = value->next;
			while(value != NULL) {
				printf(", ");
				given = getExpType(value);
				generateType(given);
				if(given >= StringArray)
					printf("*");
				printf(" %s", value->var);
				value = value->next;			
			}
		}

		printf(")\n");
		asprintf(&exp->var, "%%%d", geraVar++);
	} else if (type == Length) {
		geraIndentacao();
		printf("%%%d = load ", geraVar);
		generateType(a);
		printf("* %s\n", oper->params->var);
		
			geraIndentacao();
			printf("%%%d = getelementptr inbounds ",geraVar+1);
			generateType(a);
			printf(" %%%d, i64 0\n", geraVar);
			
			if(a == BoolArray){
				geraIndentacao();
				printf("%%%d = bitcast i1* %%%d to i32*\n", geraVar+2, geraVar+1);

				geraIndentacao();
				printf("%%%d = load i32*", geraVar+3);
				printf(" %%%d\n",geraVar+2);

				/*geraIndentacao();
				printf("%%%d = ptrtoint ",geraVar+4);
				generateType(a-3);
				printf(" %%%d to i32\n",geraVar+3);*/

				asprintf(&exp->var, "%%%d", geraVar+3);
				geraVar+=4;
			}
			else{
				geraIndentacao();
				printf("%%%d = load ", geraVar+2);
				generateType(a);
				printf(" %%%d\n",geraVar+1);
				geraIndentacao();
				printf("%%%d = ptrtoint ",geraVar+3);
				generateType(a-3);
				printf(" %%%d to i32\n",geraVar+2);

				asprintf(&exp->var, "%%%d", geraVar+3);
				geraVar+=4;
			}
	} else if (type == Parse) {
		geraIndentacao();
		printf("%%%d = load i8*** %%%s\n", geraVar, oper->id);

		geraIndentacao();
		printf("%%%d = add i32 %s, 1\n", geraVar+1, oper->params->var);

		geraIndentacao();
		printf("%%%d = getelementptr i8** %%%d, i32 %%%d\n", geraVar+2, geraVar, geraVar+1);

		geraIndentacao();
		printf("%%%d = load i8** %%%d\n", geraVar+3, geraVar+2);

		geraIndentacao();
		printf("%%%d = call i64 @strtol(i8* %%%d, i8** null, i32 0)\n", geraVar+4, geraVar+3);
		geraIndentacao();
		printf("%%%d = trunc i64 %%%d to i32\n", geraVar+5, geraVar+4);
		asprintf(&exp->var, "%%%d", geraVar+5);
		geraVar += 6;
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
		printf("%%%d = add i32 %ld, 0\n", geraVar, strtol(exp->content.literal, NULL, 0));
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
	int temp;

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
		temp = geraIf++;
		geraIndentacao();
		printf("%%%d = icmp eq i1 %s, 0\n", geraVar, print->value->var);
		geraIndentacao();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, temp, temp);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("then%d:\n", temp);
		geraIndentacao();
		printf("%%%d = getelementptr [7 x i8]* @str.false, i32 0, i32 0\n", geraVar);
		geraIndentacao();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d)\n", geraVar + 1, geraVar);
		geraIndentacao();
		geraVar += 2;
		printf("br label %%ifcont%d\n", temp);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("else%d:\n", temp);
		geraIndentacao();
		printf("%%%d = getelementptr [6 x i8]* @str.true, i32 0, i32 0\n", geraVar);
		geraIndentacao();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d)\n", geraVar + 1, geraVar);
		geraIndentacao();
		geraVar += 2;
		printf("br label %%ifcont%d\n", temp);
		printf("\n");
		geraInd--;
		geraIndentacao();
		geraInd++;
		printf("ifcont%d:\n", temp);
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
			printf("%%%d = load ", geraVar);
			generateType(a);
			printf("* %s\n", store->value->var);
			geraIndentacao();
  			printf("store ");
  			generateType(a);
  			printf(" %%%d, ", geraVar++);
  			generateType(a);
  			printf("* %c%s\n", aux2, store->target);
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
		
		if(a == Bool){
			geraIndentacao();
			printf("%%%d = add i32 %s, 4\n", geraVar, store->index->var);
		}
		else{
			geraIndentacao();
			printf("%%%d = add i32 %s, 1\n", geraVar, store->index->var);
		}

		geraIndentacao();
		printf("%%%d = load ", geraVar+1);
		generateType(a);
		printf("** %c%s\n", aux2, store->target);

		geraIndentacao();
		printf("%%%d = getelementptr ", geraVar+2);
		generateType(a);
		printf("* %%%d, i32 %%%d\n", geraVar+1, geraVar);
		geraIndentacao();
		printf("store ");
		generateType(a);
		printf(" %s, ", store->value->var);
		generateType(a);
		printf("* %%%d\n", geraVar+2);

		geraVar += 3;
	}
}

void generateIf(IfElse* ifelse) {
	int temp = geraIf++;
	printf("\n");
	generateExp(ifelse->condition);
	geraIndentacao();
	printf("%%%d = icmp eq i1 %s, 1\n", geraVar, ifelse->condition->var);
	geraIndentacao();
	printf("br i1 %%%d, label %%then%d, label %%else%d\n", geraVar++, temp, temp);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("then%d:\n", temp);
	if(ifelse->first != NULL)
		generateStatement(ifelse->first);
	geraIndentacao();
	printf("br label %%ifcont%d\n", temp);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("else%d:\n", temp);
	if(ifelse->second != NULL)
		generateStatement(ifelse->second);
	geraIndentacao();
	printf("br label %%ifcont%d\n", temp);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("ifcont%d:\n", temp);
}

void generateWhile(While* _while) {
	int temp = geraWhile++;
	printf("\n");

	geraIndentacao();
	printf("br label %%cond%d\n", temp);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("cond%d:\n", temp);
	generateExp(_while->condition);
	geraIndentacao();
	printf("%%%d = icmp eq i1 %s, 1\n", geraVar, _while->condition->var);
	geraIndentacao();
	printf("br i1 %%%d, label %%while%d, label %%whilecont%d\n", geraVar++, temp, temp);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("while%d:\n", temp);
	if(_while->statement != NULL)
		generateStatement(_while->statement);

	geraIndentacao();
	printf("br label %%cond%d", temp);
	printf("\n");
	geraInd--;
	geraIndentacao();
	geraInd++;
	printf("whilecont%d:\n", temp);
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
		ids = ids->next;
	}
	generateLVar(var->next);
}


// Declarations
void generateParam(VarDecl* var) {
	VarDecl* aux;

	if(var != NULL){
		if(var->type == StringArray) {
			printf("i32 %%%s.tam, ", var->ids->name);
			generateType(var->type);
			printf(" %%%s.temp) {\n", var->ids->name);
			printf("  entry:\n");

			//declarar o array
			//%5 = sext i32 %%%s.tam to i64
			geraIndentacao();
			printf("%%%s = alloca i8**\n", var->ids->name);
			geraIndentacao();
			printf("%%%d = mul i32 4, %%%s.tam\n", geraVar, var->ids->name);
			geraIndentacao();
			printf("%%%d = call noalias i8* @malloc(i32 %%%d)\n", geraVar+1, geraVar);
			geraIndentacao();
			printf("%%%d = bitcast i8* %%%d to i8**\n", geraVar+2, geraVar+1);
			geraIndentacao();
			printf("store i8** %%%d, i8*** %%%s\n", geraVar+2, var->ids->name);
			geraVar+=3;

			//length
			geraIndentacao();
			printf("%%%d = add i32 %%%s.tam, -1\n", geraVar, var->ids->name);
			geraIndentacao();
			printf("%%%d = sext i32 %%%d to i64\n",geraVar+1,geraVar);
  			geraIndentacao();
  			printf("%%%d = inttoptr i64 %%%d to i8*\n",geraVar+2,geraVar+1);
  
			geraIndentacao();
			printf("%%%d = load i8*** %%%s\n", geraVar+3, var->ids->name);
  			geraIndentacao();
  			printf("%%%d = getelementptr inbounds i8** %%%d, i32 0\n",geraVar+4, geraVar+3);
			geraIndentacao();
			printf("store i8* %%%d, i8** %%%d\n",geraVar+2, geraVar+4);
			geraVar+=5;

			//bits a ir buscar
			geraIndentacao();
			printf("%%%d = add i32 %%%s.tam, -1\n", geraVar, var->ids->name);
			
			//copia do array
			geraIndentacao();
			printf("%%%d = load i8*** %%%s\n", geraVar+1, var->ids->name);
			geraIndentacao();
			printf("%%%d = getelementptr inbounds i8** %%%d, i32 1\n", geraVar+2, geraVar+1);
			geraIndentacao();
			printf("%%%d = bitcast i8** %%%d to i8*\n", geraVar+3, geraVar+2);
			geraIndentacao();
			printf("%%%d = getelementptr inbounds i8** %%%s.temp, i32 1\n", geraVar+4, var->ids->name);
			geraIndentacao();
			printf("%%%d = bitcast i8** %%%d to i8*\n", geraVar+5, geraVar+4);
			geraIndentacao();
			printf("%%%d = sub nsw i32 %%%s.tam, 1\n", geraVar+6, var->ids->name);
			geraIndentacao();
			printf("%%%d = sext i32 %%%d to i32\n", geraVar+7, geraVar+6);
			geraIndentacao();
			printf("%%%d = mul i32 %%%d, 8\n", geraVar+8, geraVar+7);
			geraIndentacao();
			printf("call void @llvm.memcpy.p0i8.p0i8.i32(i8* %%%d, i8* %%%d, i32 %%%d, i32 8, i1 false)", geraVar+3, geraVar+5,geraVar+8);

			geraVar+=9;
		}
		else{
			generateType(var->type);
			if(var->type > StringArray){
				printf("* %%%s", var->ids->name);
			}
			else
				printf(" %%%s.temp", var->ids->name);
			aux = var->next;
			while(aux != NULL){
				printf(", ");
				generateType(aux->type);
				if(aux->type > StringArray)
					printf("* %%%s", aux->ids->name);
				else
					printf(" %%%s.temp", aux->ids->name);
				aux = aux->next;
			}
			printf(") {\n");
			printf("  entry:\n");
			aux = var;
			while(aux != NULL){
				if(aux->type < StringArray){
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
				}
				aux = aux->next;
			}
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
	printf("declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1)\n");
	printf("declare i64 @strtol(i8*, i8**, i32)\n");
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
