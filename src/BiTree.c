#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;

typedef struct BiNode {
	ElementType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
} BiNode, *BiTree;

typedef struct BiNode *BiTree;

void initTree(BiTree *biTree) {
	*biTree = NULL;
}

// 采用先序方式创建二叉树
void createTree(BiTree *biTree) {
	ElementType ch;
	scanf("%c", &ch);
	if (ch == '#') {
		*biTree = NULL;
		return;
	}
	*biTree = (BiTree) malloc(sizeof(BiNode));
	(*biTree)->data = ch;
	createTree(&(*biTree)->lchild);
	createTree(&(*biTree)->rchild);
}

int treeDepth(BiTree biTree) {
	if (biTree) {
		int leftBiTreeDepth = treeDepth(biTree->lchild);
		int rightBiTreeDepth = treeDepth(biTree->rchild);
		return leftBiTreeDepth > rightBiTreeDepth ?
				leftBiTreeDepth + 1 : rightBiTreeDepth + 1;
	}
	return 0;
}

// 先序遍历二叉树
void preOrderTraverse(BiTree biTree) {
	if (!biTree) {
		return;
	}
	printf("%c", biTree->data);
	preOrderTraverse(biTree->lchild);
	preOrderTraverse(biTree->rchild);
}

// 中序遍历二叉树
void inOrderTraverse(BiTree biTree) {
	if (!biTree) {
		return;
	}
	inOrderTraverse(biTree->lchild);
	printf("%c", biTree->data);
	inOrderTraverse(biTree->rchild);
}

// 后序遍历二叉树
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
	initTree(&biTree);
	createTree(&biTree);
	preOrderTraverse(biTree);
	printf("\n");
	inOrderTraverse(biTree);
	printf("\n");
	postOrderTraverse(biTree);
	printf("\n");
	printf("tree depth = %d",treeDepth(biTree));
	return 0;
}
