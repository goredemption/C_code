#define _CRT_SECURE_NO_WARNINGS 1	
#include"BinaryTree.h"
#include"Queue.h"

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL) {
		perror("malloc failed");
		return NULL;
	}
	//¸ù
	if (a[(*pi)] == '#') {
		free(root);
		*pi += 1;
		return NULL;
	}
	else {
		root->data = a[(*pi)];
	}
	*pi += 1;
	//×ó
	root->left=BinaryTreeCreate(a, n, pi);
	//ÓÒ
	root->right = BinaryTreeCreate(a, n, pi);
	return root;
}

void BinaryTreeDestory(BTNode** root) {
	if (*root == NULL) {
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1)+BinaryTreeLevelKSize(root->right,k-1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == x) {
		return root;
	}
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left!=NULL&&left->data == x) {
		return left;
	}
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right!=NULL&&right->data == x) {
		return right;
	}
	return NULL;
}

void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("#");
		return;
	}
	printf("%c", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		printf("#");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		printf("#");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c", root->data);
}

int BinaryTreeHeight(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = BinaryTreeHeight(root->left);
	int right = BinaryTreeHeight(root->right);
	if (left > right) {
		return left+1;
	}
	return right+1;
}


void BinaryTreeLevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root == NULL) {
		QueueDestroy(&q);
		return;
	}
	else {
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)) {
		BTNode* tmp=QueueFront(&q);
		QueuePop(&q);
		printf("%c", tmp->data);
		if (tmp->left != NULL) {
			QueuePush(&q, tmp->left);
		}
		if (tmp->right != NULL) {
			QueuePush(&q, tmp->right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}



bool BinaryTreeComplete(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root == NULL) {
		QueueDestroy(&q);
		return false;
	}
	else {
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q)) {
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		if (tmp == NULL&&!QueueEmpty(&q)) {
			while (!QueueEmpty(&q)) {
				BTNode* t = QueueFront(&q);
				if (t != NULL) {
					return false;
				}
				QueuePop(&q);
			}
		}
		if (tmp != NULL) {
			QueuePush(&q, tmp->left);
			QueuePush(&q, tmp->right);
		}
	}
	QueueDestroy(&q);
	return true;
}