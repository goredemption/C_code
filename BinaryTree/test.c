#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

void test1() {
	int p = 0;
	char str[] = "ABD##E##CF##G##";
	BTNode* root = BinaryTreeCreate(str, sizeof(str) / sizeof(char), &p);
	BinaryTreeLevelOrder(root);
	printf("%c\n", BinaryTreeFind(root, 'F')->data);
	printf("%d\n", BinaryTreeLevelKSize(root,5));
	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelOrderTravel:");
	BinaryTreeLevelOrder(root);
	printf("CompleteBinaryTreeCheck:%d\n", BinaryTreeComplete(root));
	BinaryTreeDestory(&root);
}
int main() {
	test1();
	return 0;
}


