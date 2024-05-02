#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"

SListNode* BuySListNode(SLTDataType x) {
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp == NULL) {
		perror("Malloc");
		return;
	}
	tmp->data = x;
	return tmp;
}

void SListPushFront(SListNode** pplist, SLTDataType x) {
	assert(pplist);
	SListNode* newnode;
	newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPushBack(SListNode** pplist, SLTDataType x) {
	assert(pplist);
	SListNode* cur = *pplist;
	if (cur == NULL) {
		*pplist = BuySListNode(x);
		(*pplist)->next = NULL;
	}
	else {
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = BuySListNode(x);
		cur->next->next = NULL;
	}
}

void SListPrint(SListNode* plist) {
	while (plist) {
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPopBack(SListNode** pplist) {
	assert(*pplist);
	SListNode* cur = *pplist;
	if (cur->next == NULL) {
		free(cur);
		*pplist = NULL;
	}
	else {
		while ((cur->next->next) != NULL) {
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SListDestroy(SListNode** pphead) {
	assert(pphead);
	if (*pphead == NULL) {
		return;
	}
	SListNode* cur, * next;
	cur = *pphead;
	next = (*pphead)->next;
	while (next != NULL) {
		free(cur);
		cur = next;
		next = cur->next;
	}
	free(cur);
	*pphead = NULL;
}

SListNode* SListFind(SListNode* plist, SLTDataType x) {
	while (plist!=NULL&&plist->data != x) {
		plist = plist->next;
	}
	return plist;
}

void SListPopFront(SListNode** pplist) {
	assert(pplist && *pplist);
	SListNode* next=(*pplist)->next;
	free(*pplist);
	*pplist = next;
}

void SListInsertAfter(SListNode* pos, SLTDataType x) {
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SListNode* pos) {
	assert(pos&&pos->next);
	SListNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType x) {

}

void SListErase(SListNode** pphead, SListNode* pos) {

}