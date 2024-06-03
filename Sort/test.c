#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void TestShellSort() {
	int arr[] = { 10,3,4,1,2,9,8,7,5,6,6,19 };
	int n = sizeof(arr) / sizeof(int);
	ShellSort(arr, n);
	PrintArray(arr, n);
}

void TestOP() {
	srand((unsigned int)time(0));
	int size = 10000;
	int* a1 = (int*)malloc(sizeof(int) * size);
	int* a2 = (int*)malloc(sizeof(int) * size);
	int* a3 = (int*)malloc(sizeof(int) * size);
	int* a4 = (int*)malloc(sizeof(int) * size);
	int* a5 = (int*)malloc(sizeof(int) * size);
	int* a6 = (int*)malloc(sizeof(int) * size);
	int* a7 = (int*)malloc(sizeof(int) * size);
	if (a1 == NULL || a2 == NULL || a3 == NULL || a4 == NULL || a5 == NULL || a6 == NULL || a7 == NULL) {
		perror("malloc failed");
		return;
	}
	for (int i = 0; i < size; i++) {
		a1[i] = rand() + i;
		a2[i] = rand() + i;
		a3[i] = rand() + i;
		a4[i] = rand() + i;
		a5[i] = rand() + i;
		a6[i] = rand() + i;
		a7[i] = rand() + i;
	}

	int begin1 = clock();
	ShellSort(a1, size);
	int end1 = clock();

	int begin2 = clock();
	BubbleSort(a2, size);
	int end2 = clock();

	int begin3 = clock();
	QuickSort(a3, 0, size);
	int end3 = clock();

	printf("ShellSort:%d\n",end1-begin1);
	printf("BubbleSort:%d\n", end2 - begin2);
	printf("QuickSort:%d\n", end3 - begin3);
}

void TestBubbleSort() {
	int arr[] = { 10,3,4,1,2,9,8,7,5,6,6,19 };
	int n = sizeof(arr) / sizeof(int);
	BubbleSort(arr, n);
	PrintArray(arr, n);
}

void TestQuickSort() {
	int arr[] = { 10,3,4,1,2,9,8,7,5,6,6,19 };
	//int arr[] = { 4,1,3,2,6 };
	int n = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0,n-1);
	PrintArray(arr, n);
}

int main() {
	//TestShellSort();
	//TestBubbleSort();
	TestQuickSort();

	//TestOP();
	return 0;
}