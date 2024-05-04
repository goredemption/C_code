#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void test1() {
	ListNode* pHead=ListCreate();
	ListPushBack(pHead, 1);
	ListPrint(pHead);
	ListPushBack(pHead, 2);
	ListPrint(pHead);
	ListPushBack(pHead, 3);
	ListPrint(pHead);
	ListPushBack(pHead, 4);
	ListPrint(pHead);
	ListPushBack(pHead, 5);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListPopBack(pHead);
	ListPrint(pHead);
	ListDestory(pHead);
}
void test2() {
	ListNode* pHead = ListCreate();
	ListPushFront(pHead, 1);
	ListPrint(pHead);
	ListPushFront(pHead, 2);
	ListPrint(pHead);
	ListPushFront(pHead, 3);
	ListPrint(pHead);
	ListPushFront(pHead, 4);
	ListPrint(pHead);
	ListPushFront(pHead, 5);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListDestory(pHead);
}
void test3() {
	ListNode* pHead = ListCreate();
	ListPushFront(pHead, 1);
	ListPrint(pHead);
	ListInsert(ListFind(pHead, 1), 2);
	ListPrint(pHead);
	ListInsert(ListFind(pHead, 2), 3);
	ListPrint(pHead);
	ListInsert(ListFind(pHead, 3), 4);
	ListPrint(pHead);
	ListInsert(ListFind(pHead, 4), 5);
	ListPrint(pHead);
	ListErase(ListFind(pHead, 1));
	ListPrint(pHead);
	ListErase(ListFind(pHead, 2));
	ListPrint(pHead);
	ListErase(ListFind(pHead, 3));
	ListPrint(pHead);
	ListErase(ListFind(pHead, 4));
	ListPrint(pHead);
	ListErase(ListFind(pHead, 5));
	ListPrint(pHead);
	ListErase(pHead);
	ListPrint(pHead);
	ListDestory(pHead);
}
int main() {
	test1();
	return 0;
}