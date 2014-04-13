#include<stdlib.h>


// Expressions
Exp* newOper(Exp* a, Exp* b, OperType type) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.oper.a = a;
	expr->content.oper.b = b;
	expr->content.oper.type = type;					//Aqui nao sei se pode ser o type ou tenho que receber o simbolo de cada um e apartir dai encontrar o tipo
	expr->type = OperKind;

	return expr;
}

Exp* newCall(Exp* params, char* method) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.call.params = params;
	expr->content.call.method = method;
	expr->type = CallKind;

	return expr;
}

Exp* newLoad(Exp* index, char* id) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.load.index = index;
	expr->content.load.id = id;
	expr->type = LoadKind;

	return expr;
}

Exp* newIntLit(int literal) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.literal = literal;
	expr->type = IntLit;

	return expr;
}

Exp* newBoolLit(int literal) {						//Aqui não sei se vai receber logo um int ou se recebo a char* e depois é que converto para 0 ou 1
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.literal = literal;
	expr->type = BoolLit;

	return expr;
}

Exp* newId(char* id) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.id = id;
	expr->type = Id;

	return expr;
}


// Statements
Statement* newIf(Exp* condition, Statement* first, Statement* second) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.ifelse.condition = condition;
	state->content.ifelse.second = second;
	state->content.ifelse.first = first;
	state->type = IfType;

	return state;
}

Statement* newReturn(Exp* value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content._return.value = value;
	state->type = ReturnType;

	return state;
}

Statement* newWhile(Exp* condition, Statement* statement) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content._while.condition = condition;
	state->content._while.statement = statement;
	state->type = WhileType;

	return state;
}

Statement* newStore(char* targe, Exp value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.store.targe = targe;
	state->content.store.value = value;
	state->type = StoreType;

	return state;
}

Statement* newPrint(Exp value) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.print.value = value;
	state->type = PrintType;

	return state;
}


// Declarations
Ids* newIds(char* name, struct _Ids* last) {
	Ids* ids = (Ids*) malloc(sizeof(Ids));
	ids->name = name;
	ids->next = NULL;

	if(last != NULL)
		last->next = ids;

	return ids;
}

VarDecl* newVarDecl(Type type, Ids ids) {
	VarDecl* vard = (VarDecl*) malloc(sizeof(VarDecl));
	vard->type = type;
	vard->ids = ids;

	return vard;
}

MethodDecl* newMethodDecl(Type type, VarDecl* vars, VarDecl* params, Statement* statements, char* id) {
	MethodDecl* meth = (MethodDecl*) malloc(sizeof(MethodDecl));
	meth->type = type;
	meth->vars = vars;
	meth->params = params;
	meth->statements = statements;
	meth->id = id;

	return meth;
}

Program* newProgram(char* id, VarDecl* vars, MethodDecl* methods) {
	Program* prog = (Program*) malloc(sizeof(Program));
	prog->id = id;
	prog->vars = vars;
	prog->methods = methods;

	return prog;
}


//ver depois o next
