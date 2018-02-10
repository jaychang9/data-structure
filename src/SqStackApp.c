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

// 斐波那契额数列某项值，用栈实现
void fibonacci(int n) {
	if (n == 1) {
		printf("1\n");
		return;
	}
	if (n == 2) {
		printf("1 1\n");
		return;
	}
	printf("1 1 ");
	Stack stack;
	initStack(&stack);
	push(&stack, 1);
	push(&stack, 1);

	int k = 1;
	while (k <= n - 2) {
		ElementType e1, e2;
		pop(&stack, &e1);
		pop(&stack, &e2);
		int temp = e1 + e2;
		printf("%d ", temp);
		if (k == n - 2) {
			break;
		}
		push(&stack, e1);
		push(&stack, temp);
		k++;
	}
	printf("\n");
}

int main() {
	fibonacci(10);
	return 0;
}
