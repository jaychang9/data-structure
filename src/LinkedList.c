#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef int Status;
typedef int ElementType;

typedef struct Node {
	ElementType data;
	struct Node* next;
} Node;

typedef struct Node *LinkedList;

void listInit(LinkedList *list, int n) {
	// 头结点数据域存储链表长度
	(*list)->data = n;
	(*list)->next = NULL;
	// list的值是linkedList的地址，所以跟&linkedList是一样的
	printf("init method list's address = %p\n", list);
	// &list是指向linkedList指针的地址
	printf("init method &list's address = %p\n", &list);
	// 是头结点的地址
	printf("init method *list's address = %p\n", *list);

	Node *p = (*list);
	for (int i = 0; i < n; i++) {
		p->next = (Node*) malloc(sizeof(Node));
		p->next->data = i;
		p->next->next = NULL;
		p = p->next;
	}
}

Status listSearch(LinkedList list, int i, ElementType *e) {
	Node *p = list->next;
	// j=1表示从第1个结点开始
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	printf("i=%d,j=%d\n", i, j);
	if (!p || j > i) {
		return FAILURE;
	}
	*e = p->data;
	return SUCCESS;
}

Status listInsert(LinkedList list, int i, ElementType e) {
	Node *p = list;
	// j=0表示从头结点开始
	int j = 0;
	// j < i - 1条件表示循环完成后（j == i - 1结束循环），p指向第i-1个结点
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) {
		return FAILURE;
	}
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;
	return SUCCESS;
}

Status listDelete(LinkedList linkedList, int i, ElementType *e) {
	Node *p = linkedList;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) {
		return FAILURE;
	}
	Node *tmp = p->next;
	p->next = tmp->next;
	*e = tmp->data;
	free(tmp);
	return SUCCESS;
}

LinkedList listReverse(LinkedList list) {
	Node *cur = list->next;
	if (!cur || !cur->next) {
		return list;
	}
	Node *pre = NULL;
	Node *next = NULL;

	while (cur) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	LinkedList reverseList = (LinkedList) malloc(sizeof(Node));
	// 拷贝链表长度数据
	reverseList->data = list->data;
	reverseList->next = pre;
	free(list);
	return reverseList;

}

/**
 * 找倒数第k个结点
 */
Node* listTheBackKthNode(LinkedList list, int k) {
	if (!list->next || k <= 0 || k > list->data) {
		return NULL;
	}
	// 设置两个指针p1,p2初始都指向第1个结点，p2向右移动k个位置,然后p1,p2同时向右移动，直至p2移动到末尾
	Node *p1 = list->next;
	Node *p2 = p1;
	int j = 1;
	while (p2->next && j < k) {
		p2 = p2->next;
		j++;
	}
	while (p2->next) {
		p2 = p2->next;
		p1 = p1->next;
	}
	return p1;
}

/**
 * 找到中间结点
 */
Node* listTheMiddleNode(LinkedList list) {
	if (!list->next) {
		return NULL;
	}
	// 获取链表的长度（头结点数据域存储了链表的长度）
	int len = list->data;
	int mid = len / 2;
	Node *p1 = list->next;
	Node *p2 = p1;
	int j = 1;
	while (p2 && j < mid + 1) {
		p2 = p2->next;
		j++;
	}
	while (p2->next) {
		p2 = p2->next;
		p1 = p1->next;
	}
	return p1;
}

void listPrint(LinkedList list) {
	Node *p = list->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	// 初始化一个单项链表的头结点
	// LinkedList linkedList = (Node*)malloc(sizeof(Node));
	LinkedList linkedList = (LinkedList) malloc(sizeof(Node));
	// 头结点的地址
	printf("main method linkedList's address = %p\n", linkedList);
	// 指向头结点的指针的地址
	printf("main method &linkedList's address = %p\n", &linkedList);
	listInit(&linkedList, 10);
	ElementType searchElement = -1;
	Status searchResult = listSearch(linkedList, 3, &searchElement);
	printf("search result:%d,the element is %d\n", searchResult, searchElement);
	printf("insert %d\n", listInsert(linkedList, 10, 33));
	listPrint(linkedList);
	ElementType deletedElement = -1;
	Status deleteResult = listDelete(linkedList, 2, &deletedElement);
	printf("delete result:%d,deleted element:%d\n", deleteResult,
			deletedElement);
	listPrint(linkedList);
	LinkedList reverseList = listReverse(linkedList);
	listPrint(reverseList);
	int k = 2;
	Node *theBackKthNode = listTheBackKthNode(reverseList, k);
	printf("the back %dth node is %d\n", k,
			theBackKthNode ? theBackKthNode->data : -1);

	Node *theMiddleNode = listTheMiddleNode(reverseList);
	printf("the middle node is %d\n",theMiddleNode->data);
	return 0;
}
