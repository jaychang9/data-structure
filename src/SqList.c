#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int Boolean;
typedef int ElementType;

typedef struct {
	ElementType data[MAXSIZE];
	int length;
} SqList;

Status initList(SqList *sqList) {
	if (!sqList) {
		return FAILURE;
	}
	sqList->length = 0;
	return SUCCESS;
}

Boolean listEmpty(SqList *sqList) {
	return sqList->length > 0 ? FALSE : TRUE;
}

Status clearList(SqList *sqList) {
	if (!sqList) {
		return FAILURE;
	}
	sqList->length = 0;
	return SUCCESS;
}

Status getElement(SqList sqList, int i, ElementType *e) {
	if (i < 1 || i > sqList.length) {
		return FAILURE;
	}
	*e = sqList.data[i];
	return SUCCESS;
}

int locateElement(SqList sqList, ElementType e) {
	for (int i = 0; i < sqList.length; i++) {
		if (sqList.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

Status listInsert(SqList *sqList, int i, ElementType e) {
	if (sqList->length >= MAXSIZE || i < 1 || i > sqList->length + 1) {
		return FAILURE;
	}
	if (i <= sqList->length) {
		// 从最后1个元素到第i个元素每个元素都往后移动一个单位
		for (int j = sqList->length - 1; j >= i - 1; j--) {
			sqList->data[j + 1] = sqList->data[j];
		}
	}
	// 将原先第i个元素值替换为e
	sqList->data[i - 1] = e;
	// 线性表长度+1
	sqList->length = sqList->length + 1;
	return SUCCESS;
}

Status listDelete(SqList *sqList, int i, ElementType *e) {
	if (i <= 0 || i >= sqList->length + 1) {
		return FAILURE;
	}
	*e = sqList->data[i - 1];
	for (int j = i - 1; j < sqList->length - 1; j++) {
		sqList->data[j] = sqList->data[j + 1];
	}
	sqList->length = sqList->length - 1;
	return SUCCESS;
}

void listPrint(SqList *sqList) {
	for (int i = 0; i < sqList->length; i++) {
		printf("%d\n", sqList->data[i]);
	}
	printf("length=%d\n", sqList->length);
}

int main() {
	SqList sqList;
	initList(&sqList);
	for (int i = 1; i <= 10; i++) {
		listInsert(&sqList, i, (ElementType) i);
	}
	listPrint(&sqList);
	printf("locate the element 3's index = %d", locateElement(sqList, 3));
	ElementType deletedElement;
	listDelete(&sqList, 4, &deletedElement);
	printf("deleted element is %d", deletedElement);
	listPrint(&sqList);
	return 0;
}
