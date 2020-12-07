#include "stack.h"

void initStack(StackPointer *stack) {
	*stack = (StackPointer) malloc(sizeof(Stack));
	if (!(*stack)) return;

	(*stack)->currentTop = -1;
}

int isEmpty(StackPointer stack) {
	return stack->currentTop < 0;
}

int getTop(StackPointer stack) {
	return stack->values[stack->currentTop];
}

int push(StackPointer stack, int value) {
	stack->currentTop += 1;
	stack->values[stack->currentTop] = value;

	return stack->currentTop;
}

int pop(StackPointer stack) {
	int value = getTop(stack);
	stack->currentTop -= 1;

	return value;
}
