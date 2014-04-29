#ifndef _STRUCTURES_
#define _STRUCTURES_

typedef enum {String, Bool, Int, StringArray, BoolArray, IntArray, Void} Type;
typedef enum {IfType, ReturnType, WhileType, StoreType, PrintType} StatementType;
typedef enum {Or, And, Eq, Neq, Lt, Gt, Leq, Geq, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Length, NewInt, NewBool, Parse, Call, LoadArray, IntLit, BoolLit, Id} ExpType;
typedef struct _Statement Statement;
typedef struct _Exp Exp;

// Expressions
typedef struct {
	Exp* params;
	char* id;
} Oper;

struct _Exp {
	union {
		Oper oper;
		int literal;
		char* id;
	} content;
	
	ExpType type;
	Exp* next;
};


// Statements
typedef struct {
	Exp* value;
} Print;

typedef struct {
	char* target;
	Exp* index;
	Exp* value;
} Store;

typedef struct {
	Exp* condition;
	Statement* first;
	Statement* second;
} IfElse;

typedef struct {
	Exp* condition;
	Statement* statement;
} While;

typedef struct {
	Exp* value;
} Return;

struct _Statement {
	union {
		IfElse ifelse;
		Return _return;
		While _while;
		Store store;
		Print print;
	} content;

	StatementType type;
	Statement* next;
};


// Declarations
typedef struct _Ids {
	struct _Ids* next;
	char* name;
} Ids;

typedef struct _VarDecl {
	Type type;
	Ids* ids;
	struct _VarDecl* next;
} VarDecl;

typedef struct _MethodDecl {
	Type type;
	VarDecl* vars;
	VarDecl* params;
	Statement* statements;
	char* id;
} MethodDecl;

typedef struct _Declaration {
	union {
		MethodDecl method;
		VarDecl var;
	} content;
	
	struct _Declaration* next;
	int isMethod;
} Declaration;

typedef struct _Program {
	char* id;
	Declaration* declarations;
} Program;

#endif
