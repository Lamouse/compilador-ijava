int varName;
int geraIf, geraWhile, geraRet;

// Statics
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
		ident();
		printf("%%%d = add i1 %s, 1\n", varName, oper->params->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Or) {
		temp = varName++;
		temp1=geraIf++;
		ident();
		printf("%%%d = alloca i1\n", temp);
		ident();
		printf("%%%d = icmp eq i1 %s, 0\n", varName, oper->params->var);
		ident();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", varName++, temp1, temp1);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("then%d:\n", temp1);
		generateExp(oper->params->next);
		ident();
		printf("%%%d = add i1 %s, 0\n", varName, oper->params->next->var);
		ident();
		printf("store i1 %%%d, i1* %%%d\n", varName++, temp);
		ident();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("else%d:\n", temp1);
		ident();
		printf("%%%d = add i1 %s, 0\n", varName, oper->params->var);
		ident();
		printf("store i1 %%%d, i1* %%%d\n", varName++, temp);
		ident();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("ifcont%d:\n", temp1);
		ident();
		printf("%%%d = load i1* %%%d\n", varName, temp);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == And) {
		temp = varName++;
		temp1=geraIf++;
		ident();
		printf("%%%d = alloca i1\n", temp);
		ident();
		printf("%%%d = icmp eq i1 %s, 1\n", varName, oper->params->var);
		ident();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", varName++, temp1, temp1);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("then%d:\n", temp1);
		generateExp(oper->params->next);
		ident();
		printf("%%%d = add i1 %s, 0\n", varName, oper->params->next->var);
		ident();
		printf("store i1 %%%d, i1* %%%d\n", varName++, temp);
		ident();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("else%d:\n", temp1);
		ident();
		printf("%%%d = add i1 %s, 0\n", varName, oper->params->var);
		ident();
		printf("store i1 %%%d, i1* %%%d\n", varName++, temp);
		ident();
		printf("br label %%ifcont%d\n", temp1);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("ifcont%d:\n", temp1);
		ident();
		printf("%%%d = load i1* %%%d\n", varName, temp);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Eq) {
		generateExp(oper->params->next);
		ident();
		if(a == Int)
			printf("%%%d = icmp eq i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		else
			printf("%%%d = icmp eq i1 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Neq) {
		generateExp(oper->params->next);
		ident();
		if(a == Int)
			printf("%%%d = icmp ne i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		else
			printf("%%%d = icmp ne i1 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Lt) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = icmp slt i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Gt) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = icmp sgt i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Leq) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = icmp sle i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Geq) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = icmp sge i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Add) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = add i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Sub) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = sub nsw i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Mul) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = mul i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Div) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = sdiv i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Mod) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = srem i32 %s, %s\n", varName, oper->params->var, oper->params->next->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Minus) {
		ident();
		printf("%%%d = mul i32 %s, -1\n", varName, oper->params->var);
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Plus) {
		return;
	} else if (type == NewInt) {
		ident();
		printf("%%%d = add i32 %s, 1\n", varName, oper->params->var);
		ident();
		printf("%%%d = mul i32 %%%d, 4\n", varName+1, varName);
		ident();
		printf("%%%d = call noalias i8* @malloc(i32 %%%d)\n", varName+2, varName+1);
		ident();
		printf("%%%d = bitcast i8* %%%d to i32*\n", varName+3, varName+2);
		ident();
		printf("store i32 %s, i32* %%%d\n", oper->params->var, varName+3);
		ident();
		printf("%%%d = alloca i32*\n",varName+4);
		ident();
		printf("store i32* %%%d, i32** %%%d\n", varName+3, varName+4);
		asprintf(&exp->var, "%%%d", varName+4);
		varName += 5;
	} else if (type == NewBool) {
		ident();
		printf("%%%d = add i32 %s, 4\n", varName, oper->params->var);
		ident();
		printf("%%%d = call noalias i8* @malloc(i32 %%%d)\n", varName+1, varName);
		ident();
		printf("%%%d = bitcast i8* %%%d to i1*\n", varName+2, varName+1);
		ident();
		printf("%%%d = bitcast i1* %%%d to i32*\n", varName+3, varName+2);
		ident();
		printf("store i32 %s, i32* %%%d\n", oper->params->var, varName+3);
		ident();
		printf("%%%d = alloca i1*\n",varName+4);
		ident();
		printf("store i1* %%%d, i1** %%%d\n", varName+2, varName+4);
		asprintf(&exp->var, "%%%d", varName+4);

		varName += 5;
	} else if (type == LoadArray) {
		generateExp(oper->params->next);
		ident();
		printf("%%%d = load ", varName);
		generateType(a);
		printf("* %s\n", oper->params->var);

		if(a == BoolArray){
			ident();
			printf("%%%d = add i32 %s, 4\n", varName+1, oper->params->next->var);
		}
		else{
			ident();
			printf("%%%d = add i32 %s, 1\n", varName+1, oper->params->next->var);
		}

		ident();
		printf("%%%d = getelementptr ", varName+2);
		generateType(a);
		printf(" %%%d, i32 %%%d\n", varName, varName+1);
		ident();
		printf("%%%d = load ", varName+3);
		generateType(a);
		printf(" %%%d\n", varName+2);

		asprintf(&exp->var, "%%%d", varName+3);
		varName += 4;
	} else if (type == Call) {
		MethodDecl* method = getMethod(oper->id);
		Exp* value = oper->params;
		Type given;
		
		while(value != NULL) {
			generateExp(value);
			value = value->next;
		}

		ident();
		printf("%%%d = call ", varName);
		generateType(method->type);
		if(method->type>=StringArray)
			printf("*");
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
		asprintf(&exp->var, "%%%d", varName++);
	} else if (type == Length) {
		if (a == StringArray){
			ident();
			printf("%%%d = sub nsw i32 %s.tam, 1\n", varName, oper->params->var);
			asprintf(&exp->var, "%%%d", varName++);
			return;
		}
		ident();
		printf("%%%d = load ", varName);
		generateType(a);
		printf("* %s\n", oper->params->var);
		
			ident();
			printf("%%%d = getelementptr inbounds ",varName+1);
			generateType(a);
			printf(" %%%d, i64 0\n", varName);
			
			if(a == BoolArray){
				ident();
				printf("%%%d = bitcast i1* %%%d to i32*\n", varName+2, varName+1);

				ident();
				printf("%%%d = load i32*", varName+3);
				printf(" %%%d\n",varName+2);

				/*ident();
				printf("%%%d = ptrtoint ",varName+4);
				generateType(a-3);
				printf(" %%%d to i32\n",varName+3);*/

				asprintf(&exp->var, "%%%d", varName+3);
				varName+=4;
			}
			else{
				ident();
				printf("%%%d = load ", varName+2);
				generateType(a);
				printf(" %%%d\n",varName+1);
				ident();
				printf("%%%d = ptrtoint ",varName+3);
				generateType(a-3);
				printf(" %%%d to i32\n",varName+2);

				asprintf(&exp->var, "%%%d", varName+3);
				varName+=4;
			}
	} else if (type == Parse) {
		/*ident();
		printf("%%%d = load i8*** %%%s\n", varName, oper->id);*/

		ident();
		printf("%%%d = add i32 %s, 1\n", varName, oper->params->var);

		ident();
		printf("%%%d = getelementptr i8** %%%s, i32 %%%d\n", varName+1, oper->id, varName);

		ident();
		printf("%%%d = load i8** %%%d\n", varName+2, varName+1);

		ident();
		printf("%%%d = call i32 (i8*)* @atoi(i8* %%%d)\n", varName+3, varName+2);
		asprintf(&exp->var, "%%%d", varName+3);
		varName += 4;
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
			ident();
			printf("%%%d = load ", varName);
			generateType(getVarType(method, exp->content.id));
			printf("* %c%s\n", aux2, exp->content.literal);

			ident();
			printf("%%%d = add ", varName+1);
			generateType(getVarType(method, exp->content.id));
			printf(" %%%d, 0\n", varName++);
			asprintf(&exp->var, "%%%d", varName++);
		}
	} else if (exp->type == IntLit) {
		ident();
		printf("%%%d = add i32 %ld, 0\n", varName, strtol(exp->content.literal, NULL, 0));
		asprintf(&exp->var, "%%%d", varName++);
	} else if (exp->type == BoolLit) {
		ident();
		aux = 0;
		if(!strcmp(exp->content.literal, "true"))
			aux = 1;
		printf("%%%d = add i1 %d, 0\n", varName, aux);
		asprintf(&exp->var, "%%%d", varName++);
	} else
		generateOper(exp);
}


// Statements
void generateStatement(Statement* state);

void generateReturn(Return* _return) {
	Type a = getExpType(_return->value);

	printf("\n");
	generateExp(_return->value);

	if(a >= StringArray){
		ident();
		printf("%%%d = load ", varName);
		generateType(a);
		printf("* %s\n", _return->value->var);

		ident();
		printf("store ");
		generateType(a);
		printf(" %%%d, ", varName++);
		generateType(a);
		printf("* %%.return\n");
	}
	else if(a != Void){
		ident();
		printf("store ");
		generateType(a);
		printf(" %s, ", _return->value->var);
		generateType(a);
		printf("* %%.return\n");
	}
	
	ident();
	printf("br label %%return\n");
	geraRet = 1;
}

void generatePrint(Print* print) {
	int temp;

	printf("\n");
	generateExp(print->value);
	if(getExpType(print->value) == Int) {
		ident();
		printf("%%%d = getelementptr [4 x i8]* @str.int, i32 0, i32 0\n", varName);
		ident();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d, i32 %s)\n", varName+1, varName, print->value->var);
		varName += 2;
	}
	else{
		temp = geraIf++;
		ident();
		printf("%%%d = icmp eq i1 %s, 0\n", varName, print->value->var);
		ident();
		printf("br i1 %%%d, label %%then%d, label %%else%d\n", varName++, temp, temp);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("then%d:\n", temp);
		ident();
		printf("%%%d = getelementptr [7 x i8]* @str.false, i32 0, i32 0\n", varName);
		ident();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d)\n", varName + 1, varName);
		ident();
		varName += 2;
		printf("br label %%ifcont%d\n", temp);
		printf("\n");
		identation--;
		ident();
		identation++;
		printf("else%d:\n", temp);
		ident();
		printf("%%%d = getelementptr [6 x i8]* @str.true, i32 0, i32 0\n", varName);
		ident();
		printf("%%%d = call i32 (i8*, ...)* @printf( i8* %%%d)\n", varName + 1, varName);
		ident();
		varName += 2;
		printf("br label %%ifcont%d\n", temp);
		printf("\n");
		identation--;
		ident();
		identation++;
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
			ident();
			printf("%%%d = load ", varName);
			generateType(a);
			printf("* %s\n", store->value->var);
			ident();
  			printf("store ");
  			generateType(a);
  			printf(" %%%d, ", varName++);
  			generateType(a);
  			printf("* %c%s\n", aux2, store->target);
		}
		else{
			ident();
			printf("%%%d = getelementptr ", varName);
			generateType(a);
			printf("* %c%s, i32 0\n", aux2, store->target);
			ident();
			printf("store ");
			generateType(a);
			printf(" %s, ", store->value->var);
			generateType(a);
			printf("* %%%d\n", varName++);
		}
	}
	else{
		generateExp(store->index);
		
		if(a == Bool){
			ident();
			printf("%%%d = add i32 %s, 4\n", varName, store->index->var);
		}
		else{
			ident();
			printf("%%%d = add i32 %s, 1\n", varName, store->index->var);
		}

		ident();
		printf("%%%d = load ", varName+1);
		generateType(a);
		printf("** %c%s\n", aux2, store->target);

		ident();
		printf("%%%d = getelementptr ", varName+2);
		generateType(a);
		printf("* %%%d, i32 %%%d\n", varName+1, varName);
		ident();
		printf("store ");
		generateType(a);
		printf(" %s, ", store->value->var);
		generateType(a);
		printf("* %%%d\n", varName+2);

		varName += 3;
	}
}

void generateIf(IfElse* ifelse) {
	int temp = geraIf++;
	printf("\n");
	generateExp(ifelse->condition);
	ident();
	printf("%%%d = icmp eq i1 %s, 1\n", varName, ifelse->condition->var);
	ident();
	printf("br i1 %%%d, label %%then%d, label %%else%d\n", varName++, temp, temp);
	printf("\n");
	identation--;
	ident();
	identation++;
	printf("then%d:\n", temp);
	generateStatement(ifelse->first);

	if(geraRet)
		geraRet = 0;
	else{
		ident();
		printf("br label %%ifcont%d\n", temp);
	}
	printf("\n");
	identation--;
	ident();
	identation++;
	printf("else%d:\n", temp);
	generateStatement(ifelse->second);

	if(geraRet)
		geraRet = 0;
	else{
		ident();
		printf("br label %%ifcont%d\n", temp);
	}
	printf("\n");
	identation--;
	ident();
	identation++;
	printf("ifcont%d:\n", temp);
}

void generateWhile(While* _while) {
	int temp = geraWhile++;
	printf("\n");

	ident();
	printf("br label %%cond%d\n", temp);
	printf("\n");
	identation--;
	ident();
	identation++;
	printf("cond%d:\n", temp);
	generateExp(_while->condition);
	ident();
	printf("%%%d = icmp eq i1 %s, 1\n", varName, _while->condition->var);
	ident();
	printf("br i1 %%%d, label %%while%d, label %%whilecont%d\n", varName++, temp, temp);
	printf("\n");
	identation--;
	ident();
	identation++;
	printf("while%d:\n", temp);
	generateStatement(_while->statement);

	if(geraRet){
		geraRet = 0;
	}
	else{
		ident();
		printf("br label %%cond%d", temp);
	}
	printf("\n");
	identation--;
	ident();
	identation++;

	printf("whilecont%d:\n", temp);
}

void generateComp(Comp* comp) {
	generateStatement(comp->value);
}

void generateStatement(Statement* state) {
	if (state == NULL)
		return;
	else if (state->type == IfType)
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

	if (!geraRet)
		generateStatement(state->next);
}

void generateLVar(VarDecl* var) {
	if (var == NULL)
		return;

	Ids* ids;
	for (ids = var->ids; ids != NULL; ids = ids->next) {
		ident();
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
			printf(" %%%s) {\n", var->ids->name);
			printf("  entry:\n");

			//declarar o array
			//%5 = sext i32 %%%s.tam to i64
			/*ident();
			printf("%%%s = alloca i8**\n", var->ids->name);
			ident();
			printf("%%%d = mul i32 4, %%%s.tam\n", varName, var->ids->name);
			ident();
			printf("%%%d = call noalias i8* @malloc(i32 %%%d)\n", varName+1, varName);
			ident();
			printf("%%%d = bitcast i8* %%%d to i8**\n", varName+2, varName+1);
			ident();
			printf("store i8** %%%d, i8*** %%%s\n", varName+2, var->ids->name);
			varName+=3;

			//length
			ident();
			printf("%%%d = add i32 %%%s.tam, -1\n", varName, var->ids->name);
			ident();
			printf("%%%d = sext i32 %%%d to i64\n",varName+1,varName);
  			ident();
  			printf("%%%d = inttoptr i64 %%%d to i8*\n",varName+2,varName+1);
  
			ident();
			printf("%%%d = load i8*** %%%s\n", varName+3, var->ids->name);
  			ident();
  			printf("%%%d = getelementptr inbounds i8** %%%d, i32 0\n",varName+4, varName+3);
			ident();
			printf("store i8* %%%d, i8** %%%d\n",varName+2, varName+4);
			varName+=5;

			//bits a ir buscar
			ident();
			printf("%%%d = add i32 %%%s.tam, -1\n", varName, var->ids->name);
			
			//copia do array
			ident();
			printf("%%%d = load i8*** %%%s\n", varName+1, var->ids->name);
			ident();
			printf("%%%d = getelementptr inbounds i8** %%%d, i32 1\n", varName+2, varName+1);
			ident();
			printf("%%%d = bitcast i8** %%%d to i8*\n", varName+3, varName+2);
			ident();
			printf("%%%d = getelementptr inbounds i8** %%%s.temp, i32 1\n", varName+4, var->ids->name);
			ident();
			printf("%%%d = bitcast i8** %%%d to i8*\n", varName+5, varName+4);
			ident();
			printf("%%%d = sub nsw i32 %%%s.tam, 1\n", varName+6, var->ids->name);
			ident();
			printf("%%%d = sext i32 %%%d to i32\n", varName+7, varName+6);
			ident();
			printf("%%%d = mul i32 %%%d, 8\n", varName+8, varName+7);
			ident();
			printf("call void @llvm.memcpy.p0i8.p0i8.i32(i8* %%%d, i8* %%%d, i32 %%%d, i32 8, i1 false)", varName+3, varName+5,varName+8);

			varName+=9;*/
		} else {
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
					ident();
					printf("%%%s = alloca ", aux->ids->name);
					generateType(aux->type);
					printf("\n");

					ident();
					printf("store ");
					generateType(aux->type);
					printf(" %%%s.temp, ", aux->ids->name);
					generateType(aux->type);
					printf("* %%%s\n", aux->ids->name);
				}
				aux = aux->next;
			}
		}
	} else {
		printf(") {\n");
		printf("  entry:\n");
	}
}

void generateGVar(VarDecl* var) {
	if (var == NULL)
		return;

	Ids* ids;
	for (ids = var->ids; ids != NULL; ids = ids->next) {
		printf("@%s = common global ", ids->name);
		generateType(var->type);

		if(var->type >= StringArray)
			printf(" null\n");
		else
			printf(" 0\n");
	}
}

void generateMethod(MethodDecl* method) {
	identation = 2;
	varName = 0;
	geraIf = 0;
	geraWhile = 0;
	geraRet = 0;

	printf("\ndefine ");
	if(!strcmp(method->id, "main"))
		printf("i32");
	else
		generateType(method->type);
	if(method->type>=StringArray)
		printf("*");
	printf(" @%s(", method->id);
	generateParam(method->params);

	if(method->type != Void){
		ident();
		printf("%%.return = alloca ");
		generateType(method->type);
		printf("\n");

		if(method->type < StringArray){
			ident();
			printf("store ");
			generateType(method->type);
			printf(" 0, ");
			generateType(method->type);
			printf("* %%.return\n");
		}
		else{
			ident();
			printf("store ");
			generateType(method->type);
			printf(" null, ");
			generateType(method->type);
			printf("* %%.return\n");
		}
	}

	generateLVar(method->vars);
	generateStatement(method->statements);

	printf("\n");
	if(geraRet == 0){
		ident();
		printf("br label %%return\n\n");
	}
	else
		geraRet = 0;
	identation--;
	ident();
	identation++;
	printf("return:\n");
	
	ident();
	if(method->type == Void){
		if(!strcmp(method->id, "main"))
			printf("ret i32 0\n");
		else
			printf("ret void\n");
	}
	else{
		if(method->type >= StringArray){
			printf("ret ");
			generateType(method->type);
			printf("* %%.return\n");
		}
		else{
			printf("%%%d = load ", varName);
			generateType(method->type);
			printf("* %%.return\n");
			ident();
			printf("ret ");
			generateType(method->type);
			printf(" %%%d\n", varName++);
		}
	}
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

void generateProgram(Program* program) {
	generateDeclaration(program->declarations);

	printf("\n");
	printf("declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture, i8* nocapture readonly, i32, i32, i1)\n");
	printf("declare i32 @atoi(i8*)\n");
	printf("declare noalias i8* @malloc(i32)\n");
	printf("declare i32 @printf(i8*, ...) nounwind\n");
	printf("@str.int = internal constant [4 x i8] c\"%%d\\0A\\00\"\n");
	printf("@str.true = private unnamed_addr constant [6 x i8] c\"true\\0A\\00\"\n");
	printf("@str.false = private unnamed_addr constant [7 x i8] c\"false\\0A\\00\"\n");
}
