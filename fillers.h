#include<stdlib.h>
#include<string.h>


// Expressions
Exp* newOper(char* id, Exp* params, ExpType type) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.oper.id = id;
	expr->content.oper.params = params;
	expr->type = type;
	expr->next = NULL;

	return expr;
}

Exp* newAnonymousOper(Exp* a, Exp* b, ExpType type) {
	a->next = b;
	return newOper(NULL, a, type);
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

ExpType getOperType(char* oper) {
	if (!strcmp(oper, '||'))
		return Or;
	if (!strcmp(oper, '&&'))
		return And;
}

void connectExp(Exp* a, Exp* b) {
	a->next = b;
	return a;
}


// Statements
Statement* newIf(Exp* condition, Statement* first) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.ifelse.condition = condition;
	state->content.ifelse.first = first;
	state->content.ifelse.second = NULL;
	state->type = IfType;
	state->next = NULL;

	return state;
}

Statement* newElse(Statement* _if, Statement* second) {
	_if->content.ifelse.second = second;
	return _if;
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

Statement* newStore(char* target, Exp* index, Exp* value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.store.target = target;
	state->content.store.value = value;
	state->content.store.index = index;
	state->type = StoreType;
	state->next = NULL;

	return state;
}

Statement* newPrint(Exp* value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.print.value = value;
	state->type = PrintType;
	state->next = NULL;

	return state;
}

void connectStatement(Statement* a, Statement* b) {
	a->next = b;
	return a;
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
	return a;
}

VarDecl* newVarDecl(Type type, Ids* ids) {
	VarDecl* vard = (VarDecl*) malloc(sizeof(VarDecl));
	vard->type = type;
	vard->ids = ids;
	vard->next = NULL;

	return vard;
}

void connectVarDecl(VarDecl* a, VarDecl* b) {
	a->next = b;
	return a;
}

MethodDecl* newMethodDecl(Type type, char* id, VarDecl* params, MethodDecl* method) {
	meth->type = type;
	meth->params = params;
	meth->id = id;

	return meth;
}


MethodDecl* newMethod(VarDecl* vars, Statement* statements) {
	MethodDecl* meth = (MethodDecl*) malloc(sizeof(MethodDecl));
	meth->vars = vars;
	meth->statements = statements;
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
