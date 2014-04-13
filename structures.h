typedef enum {String, Bool, Int, StringArray, BoolArray, IntArray, Void} Type;
typedef enum {Or, And, Eq, Neq, Lt, Gt, Leq, Geq, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Length, NewInt, NewBool, Parse} OperType;
typedef enum {IfType, ReturnType, WhileType, StoreType, PrintType} StatementType;
typedef enum {OperKind, CallKind, LoadKind, IntLit, BoolLit, Id} ExpType;
typedef struct _Statement Statement;
typedef struct _Exp Exp;

// Expressions
typedef struct {
	Exp* a;
	Exp* b;
	OperType type;
} Oper;

typedef struct {
	Exp* params;
	char* method;
} Call;

typedef struct {
	Exp* index;
	char* id;
} Load;

struct _Exp {
	union {
		Oper oper;
		Call call;
		Load load;

		int literal;
		char* id;
	} content;
	
	ExpType type;
	Exp* next;
};


// Statements
typedef struct {
	Exp value;
} Print;

typedef struct {
	char* target;
	Exp value;
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
	Ids ids;

	struct _VarDecl* next;
} VarDecl;

typedef struct _MethodDecl {
	Type type;
	VarDecl* vars;
	VarDecl* params;
	Statement* statements;

	struct _MethodDecl* next;
	char* id;
} MethodDecl;

typedef struct _Program {
	char* id;

	VarDecl* vars;
	MethodDecl* methods;
} Program;