#include<stdlib.h>
#include<string.h>


// Expressions
Exp* newOper(Exp* a, Exp* b, OperType type) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.oper.a = a;
	expr->content.oper.b = b;
	expr->content.oper.type = type;									//ver depois o type
	expr->type = OperKind;
	expr->next = NULL;

	return expr;
}

Exp* newCall(Exp* params, char* method) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.call.params = params;
	expr->content.call.method = method;
	expr->type = CallKind;
	expr->next = NULL;

	return expr;
}

Exp* newLoad(Exp* index, char* id) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.load.index = index;
	expr->content.load.id = id;
	expr->type = LoadKind;
	expr->next = NULL;

	return expr;
}

Exp* newIntLit(int literal) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.literal = literal;
	expr->type = IntLit;
	expr->next = NULL;

	return expr;
}

Exp* newBoolLit(char* value) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	if(strcmp(value, "false")==0)
		expr->content.literal = 0;
	else
		expr->content.literal = 1;
	expr->type = BoolLit;
	expr->next = NULL;

	return expr;
}

Exp* newId(char* id) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.id = id;
	expr->type = Id;
	expr->next = NULL;

	return expr;
}

void connectExp(Exp* a, Exp* b) {
	a->next = b;
}


// Statements
Statement* newIf(Exp* condition, Statement* first, Statement* second) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.ifelse.condition = condition;
	state->content.ifelse.second = second;
	state->content.ifelse.first = first;
	state->type = IfType;
	state->next = NULL;

	return state;
}

Statement* newReturn(Exp* value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content._return.value = value;
	state->type = ReturnType;
	state->next = NULL;

	return state;
}

Statement* newWhile(Exp* condition, Statement* statement) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content._while.condition = condition;
	state->content._while.statement = statement;
	state->type = WhileType;
	state->next = NULL;

	return state;
}

Statement* newStore(char* targe, Exp value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.store.targe = targe;
	state->content.store.value = value;
	state->type = StoreType;
	state->next = NULL;

	return state;
}

Statement* newPrint(Exp value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.print.value = value;
	state->type = PrintType;
	state->next = NULL;

	return state;
}

void connectStatement(Statement* a, Statement* b) {
	a->next = b;
}


// Declarations
Ids* newIds(char* name) {
	Ids* ids = (Ids*) malloc(sizeof(Ids));
	ids->name = name;
	ids->next = NULL;

	return ids;
}

void connectIds(Ids* a, Ids* b) {
	a->next = b;
}

VarDecl* newVarDecl(Type type, Ids ids) {
	VarDecl* vard = (VarDecl*) malloc(sizeof(VarDecl));
	vard->type = type;												//ver depois o type
	vard->ids = ids;
	vard->next = NULL;

	return vard;
}

void connectVarDecl(VarDecl* a, VarDecl* b) {
	a->next = b;
}

MethodDecl* newMethodDecl(Type type, VarDecl* vars, VarDecl* params, Statement* statements, char* id) {
	MethodDecl* meth = (MethodDecl*) malloc(sizeof(MethodDecl));
	meth->type = type;												//ver depois o type
	meth->vars = vars;
	meth->params = params;
	meth->statements = statements;
	meth->id = id;
	meth->next = NULL;

	return meth;
}

void connectMethodDecl(MethodDecl* a, MethodDecl* b) {
	a->next = b;
}

Program* newProgram(char* id, VarDecl* vars, MethodDecl* methods) {
	Program* prog = (Program*) malloc(sizeof(Program));
	prog->id = id;
	prog->vars = vars;
	prog->methods = methods;

	return prog;
}
