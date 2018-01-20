#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;

typedef struct BiNode {
	ElementType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
} BiNode, *BiTree;

typedef struct BiNode *BiTree;

void init(BiTree *biTree) {

}

// 采用先序方式创建二叉树
void create(BiTree *biTree) {
	ElementType ch;
	scanf("%c", &ch);
	if (ch == '#') {
		*biTree = NULL;
		return;
	}
	*biTree = (BiTree) malloc(sizeof(BiNode));
	(*biTree)->data = ch;
	create(&(*biTree)->lchild);
	create(&(*biTree)->rchild);
}
void preOrderTraverse(BiTree biTree) {
	if (!biTree) {
		return;
	}
	printf("%c", biTree->data);
	preOrderTraverse(biTree->lchild);
	preOrderTraverse(biTree->rchild);
}

void inOrderTraverse(BiTree biTree) {
	if (!biTree) {
		return;
	}
	inOrderTraverse(biTree->lchild);
	printf("%c", biTree->data);
	inOrderTraverse(biTree->rchild);
}

void postOrderTraverse(BiTree biTree) {
	if (!biTree) {
		return;
	}
	postOrderTraverse(biTree->lchild);
	postOrderTraverse(biTree->rchild);
	printf("%c", biTree->data);
}

int main() {
	BiTree biTree;
	create(&biTree);
	preOrderTraverse(biTree);
	inOrderTraverse(biTree);
	postOrderTraverse(biTree);
	return 0;
}
