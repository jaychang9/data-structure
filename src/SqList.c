#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElementType;

typedef struct {
	ElementType data[MAXSIZE];
	int length;
} SqList;

Status sqListInit(SqList *sqList) {
	sqList->length = 0;
	return SUCCESS;
}

Status sqListGetElement(SqList sqList, int i, ElementType *e) {
	if (i < 1 || i > sqList.length) {
		return FAILURE;
	}
	*e = sqList.data[i];
	return SUCCESS;
}

Status sqListInsert(SqList *sqList, int i, ElementType e) {
	if (i < 1 || i > sqList->length + 1 || sqList->length >= MAXSIZE) {
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

void sqListPrint(SqList *sqList) {
	for (int i = 0; i < sqList->length; i++) {
		printf("%d\n", sqList->data[i]);
	}
	printf("length=%d\n",sqList->length);
}

int main() {
	SqList sqList;
	sqListInit(&sqList);
	for (int i = 1; i <= 10; i++) {
		sqListInsert(&sqList, i, (ElementType) i);
	}
	sqListPrint(&sqList);
	return 0;
}
