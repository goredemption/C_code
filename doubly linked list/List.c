#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

ListNode* ListCreate() {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("malloc");
		return;
	}
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}

void ListDestory(ListNode* pHead) {
	assert(pHead);
	ListNode* cur=pHead->next, * tmp;
	while (cur!=pHead) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(cur);
}

void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->next;
	printf("Guard<->");
	while (cur != pHead) {
		printf("%d<->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("malloc");
		return;
	}
	newnode->data = x;
	tail->next = newnode;
	newnode->next = pHead;
	pHead->prev = newnode;
	newnode->prev = tail;
}

void ListPopBack(ListNode* pHead) {
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* tail=pHead->prev, * tailPrev=tail->prev;
	free(tail);
	tailPrev->next = pHead;
	pHead->prev = tailPrev;
}

void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("malloc");
		return;
	}
	newnode->data = x;
	newnode->next = pHead->next;
	pHead->next->prev = newnode;
	newnode->prev = pHead;
	pHead->next = newnode;
}

void ListPopFront(ListNode* pHead) {
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* first = pHead->next;
	pHead->next = first->next;
	first->next->prev = pHead;
	free(first);
}

ListNode* ListFind(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* cur=pos, * prev=cur->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("malloc");
		return;
	}
	newnode->data = x;
	prev->next = newnode;
	newnode->next = cur;
	cur->prev = newnode;
	newnode->prev = prev;
}

void ListErase(ListNode* pos) {
	assert(pos);
	assert(pos->next != pos);
	ListNode * prev = pos->prev,*next=pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}