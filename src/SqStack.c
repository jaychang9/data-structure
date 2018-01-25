#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

typedef int ElementType;
typedef int Status;
typedef int Boolean;

typedef struct SqStack{
	ElementType data[MAXSIZE];
	int top;
	struct SqStack next;
} SqStack, Stack;
void initStack(Stack *stack) {
	stack->top = -1;
}

void destroyStack(Stack *stack) {
	free(stack);
}

Status clearStack(Stack *stack) {
	return TRUE;
}

Status stackEmpty(Stack stack) {
	return stack.top == -1 ? TRUE : FALSE;
}

Boolean getTop(Stack stack, ElementType *e) {
	if (stack.top == -1) {
		return FAILURE;
	}
	*e = stack.data[stack.top];
	return SUCCESS;
}

Boolean push(Stack *stack, ElementType e) {
	if (stack->top == MAXSIZE - 1) {
		return FAILURE;
	}
	stack->data[++stack->top] = e;
	return SUCCESS;
}

Boolean pop(Stack *stack, ElementType *e) {
	if (stack->top == -1) {
		return FAILURE;
	}
	*e = stack->data[stack->top--];
	return SUCCESS;
}

int stackLength(Stack stack) {
	return stack.top + 1;
}

int main() {
	Stack stack;
	initStack(&stack);
	for (int i = 0; i < 15; i++) {
		push(&stack, (ElementType) i);
	}
	printf("current stack length is %d\n", stackLength(stack));
	while (!stackEmpty(stack)) {
		ElementType e;
		pop(&stack, &e);
		printf("pop element is %d,current statck length is %d\n", e,
				stackLength(stack));
	}
	printf("stack's length %d", stackLength(stack));
	return 0;
}
