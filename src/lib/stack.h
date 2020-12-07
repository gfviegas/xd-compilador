/**
 * Uma pilha de inteiros
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef stack_h
#define stack_h

#include <stdlib.h>

typedef struct Stack* StackPointer;
typedef struct Stack {
	int currentTop;
	int values[100];
} Stack;

void initStack(StackPointer *stack);
int isEmpty(StackPointer stack);

int getTop(StackPointer stack);
int push(StackPointer stack, int value);
int pop(StackPointer stack);

#endif
