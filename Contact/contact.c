#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void initial(struct contact* ct) {
	ct->book = (struct address*)malloc(3 * sizeof(struct address));
	ct->size = 0;
	ct->capacity = 3;
}
void checkcapacity(struct contact*ct) {
	if (ct->size == ct->capacity) {
		ct->book = (struct address*)realloc(ct->book,2 * (ct->capacity) * sizeof(struct address));
	}
}

void insert(struct contact* ct) {
	assert(ct);
	checkcapacity(ct);
	printf("Name:>");
	scanf("%s", ct->book[ct->size].name);
	printf("\n");
	printf("Sex:>");
	scanf("%s", ct->book[ct->size].sex);
	printf("\n");
	printf("Age:>");
	scanf("%d", &(ct->book[ct->size].age));
	printf("\n");
	printf("PhoneNumber>:");
	scanf("%lld", &(ct->book[ct->size].number));
	printf("\n");
	printf("Address:>");
	scanf("%s", ct->book[ct->size].address);
	printf("\n");
	printf("Loaded In\n");
	ct->size++;
}

void erase(struct contact*ct) {
	int n = 0;
	//check input correctness
	assert(ct&&(n<ct->size)&&(n>=0));
	//check empty
	assert(ct->size > 0);
	for (int i = n; i < ct->size-1; i++) {
		ct->book[i] = ct->book[i + 1];
	}
	ct->size--;
}

void print(struct contact* ct) {
	printf("Content of the book:\n");
	for (int i = 0; i < ct->size; i++) {
		printf("Name:%s\n", ct->book[i].name);
		printf("Sex:%s\n", ct->book[i].sex);
		printf("Age:%d\n", ct->book[i].age);
		printf("PhoneNumber:%lld\n", ct->book[i].number);
		printf("Address:%s", ct->book[i].address);
		printf("\n\n");
	}
}

void destroy(struct contact* ct) {
	free(ct->book);
	ct->book = NULL;
}