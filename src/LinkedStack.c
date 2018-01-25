/*
 * 栈的链式存储结构的实现
 *
 *  Created on: 2018年1月25日
 *      Author: Administrator
 */
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

typedef struct StackNode {
	ElementType data;
	struct StackNode *next;
} StackNode;

typedef struct LinkedStack {
	StackNode *top;
	int length;
} Stack;

void initStack(Stack *stack) {
	stack->top = NULL;
	stack->length = 0;
}

void destroyStack(Stack *stack) {
	while (stack->top != NULL) {
		StackNode *cur = stack->top;
		stack->top = cur->next;
		free(cur);
	}
	free(stack);
}

Status clearStack(Stack *stack) {
	while (stack->top != NULL) {
		StackNode *cur = stack->top;
		stack->top = cur->next;
		free(cur);
	}
	return SUCCESS;
}

Status stackEmpty(Stack stack) {
	return stack.length == 0 ? TRUE : FALSE;
}

Boolean getTop(Stack stack, ElementType *e) {
	*e = stack.top->data;
	return SUCCESS;
}

Boolean push(Stack *stack, ElementType e) {
	StackNode *newStackNode = (StackNode*) malloc(sizeof(StackNode));
	newStackNode->data = e;
	newStackNode->next = stack->top;
	stack->top = newStackNode;
	stack->length++;
	return SUCCESS;
}

Boolean pop(Stack *stack, ElementType *e) {
	if (stackEmpty(*stack)) {
		return FAILURE;
	}
	*e = stack->top->data;
	StackNode *temp = stack->top;
	stack->top = temp->next;
	free(temp);
	stack->length--;
	return SUCCESS;
}

int stackLength(Stack stack) {
	return stack.length;
}

int main() {
	printf("LinkedStack\n");
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
