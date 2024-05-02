#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void CheckCapacity(SeqList* ps) {
	assert(ps);
	if ((ps->size) == (ps->capacity)) {
		if (ps->capacity == 0) {
			SLDataType* tmp = (SLDataType*)realloc(ps->data,  3 * sizeof(SLDataType));
			if (tmp == NULL) {
				perror("Realloc");
				return;
			}
			ps->data = tmp;
			ps->capacity = 3;
		}
		else {
			SLDataType* tmp = (SLDataType*)realloc(ps->data, 2 * (ps->capacity) * sizeof(SLDataType));
			if (tmp == NULL) {
				perror("Realloc");
				return;
			}
			ps->data = tmp;
			ps->capacity = 2 * ps->capacity;
		}
	}
}
void SeqListInit(SeqList* ps) {
	assert(ps);
	SLDataType* tmp = (SLDataType*)malloc(3 * sizeof(SLDataType));
	if (tmp == NULL) {
		perror("Malloc");
		return;
	}
	ps->data = tmp;
	ps->capacity = 3;
	ps->size = 0;
}

void SeqListDestroy(SeqList* ps) {
	assert(ps);
	free(ps->data);
	ps->capacity = 0;
	ps->size = 0;
	ps->data = NULL;
}

void SeqListPushBack(SeqList* ps, SLDataType x) {
	CheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

void SeqListPrint(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* ps, SLDataType x) {
	CheckCapacity(ps);
	int end = ps->size;
	for (end; end > 0; end--) {
		ps->data[end] = ps->data[end-1];
	}
	ps->data[end] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps) {
	assert(ps);
	assert(ps->size);
	int head = 0;
	for (head; head < ps->size-1; head++) {
		ps->data[head] = ps->data[head + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps) {
	assert(ps);
	assert(ps->size);
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDataType x) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		if (ps->data[i] == x) {
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x) {
	assert(ps);
	assert((pos <= ps->size)&&(pos>=0));
	CheckCapacity(ps);
	int end = ps->size;
	for (end; end>pos; end--) {
		ps->data[end] = ps->data[end - 1];
	}
	ps->data[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, int pos) {
	assert(ps);
	assert(ps->size);
	assert((pos < ps->size) && (pos >= 0));
	for (pos; pos < ps->size - 1; pos++) {
		ps->data[pos] = ps->data[pos + 1];
	}
	ps->size--;
}

void menu() {
	printf("********************************\n");
	printf("1.PushBack  2.PushFront\n");
	printf("3.PopBack  4.PopFront\n");
	printf("5.Insert  6.Erase\n");
	printf("7.Find  8.Print\n");
	printf("0.exit\n");
	printf("********************************\n");
}