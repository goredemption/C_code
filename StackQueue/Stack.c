#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void StackInit(Stack* ps) {
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = -1;
}

void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->top + 1 == ps->capacity) {
		Stack* tmp = (Stack*)realloc(ps->data, sizeof(Stack) * (10 + ps->capacity));
		if (tmp == NULL) {
			perror("realloc failed");
			return;
		}
		ps->data = tmp;
		ps->capacity += 10;
	}
	ps->top += 1;
	ps->data[ps->top] = data;
}

void StackPop(Stack* ps) {
	assert(ps);
	assert(ps->top!=-1);
	ps->top -= 1;
}

STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(ps->top != -1);
	return ps->data[ps->top];
}

void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = -1;
	ps->capacity = 0;
}

bool StackEmpty(Stack* ps) {
	assert(ps);
	return ps->top == -1;
}

int StackSize(Stack* ps) {
	return (ps->top) + 1;
}