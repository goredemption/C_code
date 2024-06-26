#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
struct contact {
	struct information* book;
	int size;
	int capacity;
};
struct information {
	char name[20];
	char sex[10];
	int age;
	long long number;
	long long card;
	char address[20];
};

void checkcapacity(struct contact* ct);
void DataSave(struct contact* ct);
void initial(struct contact* ct);
void insert(struct contact* ct);
void destroy(struct contact* ct);
void erase(struct contact* ct);
void find(struct contact* ct);
void sort(struct contact* ct);
void modify(struct contact* ct);
void menu();