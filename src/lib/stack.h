/**
 * Uma pilha de inteiros
 * @author Gustavo Viegas (3026)
 *
 **/

#ifndef stack_h
#define stack_h

#include <stdlib.h>

// Ponteiro para uma pilha
typedef struct Stack* StackPointer;
// Repreentação de uma pilha de inteiros
typedef struct Stack {
	// Índice atual do topo da pilha
	int currentTop;
	// Valores na pilha
	int values[100];
} Stack;

void initStack(StackPointer *stack);
int isEmpty(StackPointer stack);

int getTop(StackPointer stack);
int push(StackPointer stack, int value);
int pop(StackPointer stack);

#endif
