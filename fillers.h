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

Exp* newLiteral(int literal, ExpType type) {
	Exp* expr = (Exp*) malloc(sizeof(Exp));
	expr->content.literal = literal;
	expr->type = type;
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
	if (!strcmp(oper, "&&"))
		return And;
	if (!strcmp(oper, "||"))
		return Or;
	if (!strcmp(oper, "<"))
		return Lt;
	if (!strcmp(oper, ">"))
		return Gt;
	if (!strcmp(oper, "=="))
		return Eq;
	if (!strcmp(oper, "!="))
		return Neq;
	if (!strcmp(oper, "<="))
		return Leq;
	if (!strcmp(oper, ">="))
		return Geq;
	if (!strcmp(oper, "+"))
		return Add;
	if (!strcmp(oper, "-"))
		return Sub;
	if (!strcmp(oper, "*"))
		return Mul;
	if (!strcmp(oper, "/"))
		return Div;
	if (!strcmp(oper, "%"))
		return Mod;
}

Exp* connectExp(Exp* a, Exp* b) {
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

Statement* connectStatement(Statement* a, Statement* b) {
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

Ids* connectIds(Ids* a, Ids* b) {
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

VarDecl* connectVarDecl(VarDecl* a, VarDecl* b) {
	a->next = b;
	return a;
}

Declaration* newFieldDecl(VarDecl* var) {
	Declaration* decl = (Declaration*) malloc(sizeof(Declaration));
	decl->content.var = *var;
	decl->isMethod = 0;
	decl->next = NULL;

	return decl;
}

Declaration* declareMethod(Type type, char* id, VarDecl* params, Declaration* decl) {
	decl->content.method.type = type;
	decl->content.method.params = params;
	decl->content.method.id = id;

	return decl;
}

Declaration* newMethod(VarDecl* vars, Statement* statements) {
	Declaration* decl = (Declaration*) malloc(sizeof(Declaration));
	decl->content.method.statements = statements;
	decl->content.method.vars = vars;
	decl->isMethod = 1;
	decl->next = NULL;

	return decl;
}

Declaration* connectDeclaration(Declaration* a, Declaration* b) {
	a->next = b;
	return a;
}

Program* newProgram(char* id, Declaration* declarations) {
	Program* prog = (Program*) malloc(sizeof(Program));
	prog->declarations = declarations;
	prog->id = id;

	return prog;
}
