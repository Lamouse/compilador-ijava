#ifndef _LJPARSER_
#define _LJPARSER_

enum Type {String, Bool, Int, StringArray, BoolArray, IntArray, Void};

struct _VarDecl {
	Type type;

	struct _VarDecl* next;
	char*[50];
} VarDecl;

union _Statement {
	CompoundStat compound;
	IfElse ifelse;
	If _if;
	Return _return;
	While _while;
	Store store;

	Statement* next;
} Statement;

struct _MethodDecl {
	Type type;
	ParamDecl* params;
	Statement* statements;

	struct _MethodDecl* next;
	char* id;
} MethodDecl;

struct _Program {
	char* id;

	VarDecl* vars;
	MethodDecl* methods;
} Program;

#endif