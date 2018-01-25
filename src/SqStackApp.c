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

typedef struct {
	ElementType data[MAXSIZE];
	int top;
} Stack;
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
	//printf("push e %d\n", e);
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
