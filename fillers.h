#include<stdlib.h>

Statement* newIf(Exp* condition, Statement* first, Statement* second) {
	Statement* state = (Statement*) malloc(sizeof(Statement));
	state->content.ifelse.condition = condition;
	state->content.ifelse.second = second;
	state->content.ifelse.first = first;
	state->type = IfType;

	return state;
}