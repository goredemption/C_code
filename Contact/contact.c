#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
int search(struct contact* ct) {
	//check NULL pointer
	assert(ct);
	if (ct->book == NULL) {
		printf("/* Book is empty */\n");
		return -1;
	}
	char name[20] = { 0 };
	printf("Target Name:>");
	scanf("%s", name);
	for (int i = 0; i < ct->size; i++) {
		if (strcmp(ct->book[i].name, name) == 0) {
			return i;
		}
	}
	printf("/* No such person */\n");
	return -1;
}

void initial(struct contact* ct) {
	ct->book = (struct address*)malloc(3 * sizeof(struct address));
	ct->size = 0;
	ct->capacity = 3;
}
void checkcapacity(struct contact*ct) {
	assert(ct);
	if (ct->size == ct->capacity) {
		if (ct->capacity == 0) {
			initial(ct);
		}
		else {
			struct address* tmp = (struct address*)realloc(ct->book, 2 * (ct->capacity) * sizeof(struct address));
			if (tmp != NULL) {
				ct->book = tmp;
				ct->capacity=2*(ct->capacity);
			}
			else {
				perror("Realloc");
			}
		}
	}
}

void insert(struct contact* ct) {
	//check NULL pointer
	assert(ct);
	checkcapacity(ct);
	printf("Name:>");
	scanf("%s", ct->book[ct->size].name);
	printf("Sex:>");
	scanf("%s", ct->book[ct->size].sex);
	printf("Age:>");
	scanf("%d", &(ct->book[ct->size].age));
	printf("PhoneNumber>:");
	scanf("%lld", &(ct->book[ct->size].number));
	printf("Address:>");
	scanf("%s", ct->book[ct->size].address);
	printf("/* Loaded In */\n");
	ct->size++;
}

void erase(struct contact*ct) {
	int n=search(ct);
	//check input correctness
	if (n == -1) {
		return;
	}
	for (int i = n; i < ct->size-1; i++) {
		ct->book[i] = ct->book[i + 1];
	}
	ct->size--;
	printf("/* Erase Successfully */\n");
}

void find(struct contact* ct) {
	int n=search(ct);
	if (n == -1) {
		return;
	}
	printf("/* Finding Result: */\n");
	printf("Name:%s\n", ct->book[n].name);
	printf("Sex:%s\n", ct->book[n].sex);
	printf("Age:%d\n", ct->book[n].age);
	printf("PhoneNumber:%lld\n", ct->book[n].number);
	printf("Address:%s", ct->book[n].address);
	printf("\n\n");
}

void print(struct contact* ct) {
	if (ct->book == NULL) {
		printf("/* Book is empty */\n");
		return;
	}
	printf("/* Content of the book: */\n");
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
	if (ct->book == NULL) {
		printf("/* Book is empty */\n");
		return;
	}
	free(ct->book);
	ct->book = NULL;
	ct->capacity = 0;
	ct->size = 0;
	printf("/* Destroyed */\n");
}

void modify(struct contact* ct) {
	int n = search(ct);
	if (n == -1) {
		return;
	}
	printf("Name:>");
	scanf("%s", ct->book[n].name);
	printf("Sex:>");
	scanf("%s", ct->book[n].sex);
	printf("Age:>");
	scanf("%d", &(ct->book[n].age));
	printf("PhoneNumber>:");
	scanf("%lld", &(ct->book[n].number));
	printf("Address:>");
	scanf("%s", ct->book[n].address);
	printf("/* Modified */\n");
}
int compare(void* p1, void* p2) {
	struct address* cur = (struct address*)p1;
	struct address* next = (struct address*)p2;
	return strcmp(cur->name, next->name);
}
void sort(struct contact* ct) {
	qsort(ct->book,ct->size,sizeof(struct address),compare);
}

void menu() {
	printf("********************************\n");
	printf("1.Insert  2.Erase\n");
	printf("3.Find    4.Modify\n");
	printf("5.Print   6.Destory\n");
	printf("7.Sort    0.Exit\n");
	printf("********************************\n");
}