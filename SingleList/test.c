#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"
void test1() {
	SListNode* phead = NULL;
	SListPushBack(&phead, 2);
	SListPushFront(&phead, 1);
	SListPushBack(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPrint(phead);
}
void test2() {
	SListNode* phead = NULL;
	SListPushBack(&phead, 2);
	SListPushFront(&phead, 1);
	SListPushBack(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SListDestroy(&phead);
	SListPrint(phead);
}
void test3() {
	SListNode* phead = NULL;
	SListPushBack(&phead, 2);
	SListPushFront(&phead, 1);
	SListPushBack(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPrint(phead);
	SListDestroy(&phead);
}
void test4() {
	SListNode* phead = NULL;
	SListPushBack(&phead, 2);
	SListPushFront(&phead, 1);
	SListPushBack(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	SListInsertAfter(SListFind(phead, 3), 5);
	SListPrint(phead);
	SListEraseAfter(SListFind(phead, 3));
	SListPrint(phead);
	SListEraseAfter(SListFind(phead, 1));
	SListPrint(phead);
	SListDestroy(&phead);
}
int main() {
	test4();
	return 0;
}