#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
struct contact {
	struct address* book;
	int size;
	int capacity;
};
struct address {
	char name[20];
	char sex[4];
	int age;
	long long number;
	char address[20];
};
void initial(struct contact* ct);
void insert(struct contact* ct);
void destroy(struct contact* ct);
void erase(struct contact* ct);
void find(struct contact* ct);
void sort(struct contact* ct);
void modify(struct contact* ct);
void menu();