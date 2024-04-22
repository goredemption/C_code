#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//
int add(int x, int y) {
	return x + y;
}
int main() {
	int(*p)(int x, int y) = &add;
	int sum=p(5, 6);
	printf("%d", sum);
	return 0;
}