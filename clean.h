void cleanStatement(Statement* state);
void cleanExp(Exp* exp);


// Statics
void cleanIds(Ids* ids) {
	if (ids != NULL) {
		free(ids->name);
		cleanIds(ids->next);
		free(ids);
	}
}


// Expressions
void cleanOper(Oper* oper) {
	free(oper->id);
	cleanExp(oper->params);
}

void cleanExp(Exp* exp) {
	if (exp == NULL) {
		return;
	} else if (exp->type == Id) {
		free(exp->content.id);
	} else if (exp->type == IntLit) {
		free(exp->content.literal);
	} else if (exp->type == BoolLit) {
		free(exp->content.literal);
	} else
		cleanOper(&exp->content.oper);
	cleanExp(exp->next);
	free(exp);
}


// Statements
void cleanStore(Store* store) {
	cleanExp(store->index);
	cleanExp(store->value);
	free(store->target);
}

void cleanPrint(Print* print) {
	cleanExp(print->value);
}

void cleanIf(IfElse* ifelse) {
	cleanExp(ifelse->condition);
	cleanStatement(ifelse->first);
	cleanStatement(ifelse->second);
}

void cleanWhile(While* _while) {
	cleanExp(_while->condition);
	cleanStatement(_while->statement);
}

void cleanReturn(Return* _return) {
	cleanExp(_return->value);
}

void cleanStatement(Statement* state) {
	if (state != NULL) {
		if (state->type == IfType)
			cleanIf(&state->content.ifelse);
		else if (state->type == WhileType)
			cleanWhile(&state->content._while);
		else if (state->type == ReturnType)
			cleanReturn(&state->content._return);
		else if (state->type == StoreType)
			cleanStore(&state->content.store);
		else if (state->type == PrintType)
			cleanPrint(&state->content.print);

		if (state->next != NULL)
			cleanStatement(state->next);
		free(state);
	}
}


// Declarations
void cleanVar(VarDecl* var) {
	if (var == NULL)
		return;
	cleanIds(var->ids);
	cleanVar(var->next);
	free(var);
}

void cleanMethod(MethodDecl* method) {
	cleanVar(method->params);
	cleanVar(method->vars);

	if (method->statements != NULL)
		cleanStatement(method->statements);

	free(method->id);
	free(method);
}

void cleanDeclaration(Declaration* decl) {
	if (decl != NULL) {
		if (decl->isMethod) {
			cleanMethod(&decl->content.method);
		} else {
			cleanVar(&decl->content.var);
		}
		cleanDeclaration(decl->next);
	}
}

void cleanProgram(Program* program) {
	cleanDeclaration(program->declarations);
	free(program->id);
	free(program);
}
