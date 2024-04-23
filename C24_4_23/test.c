#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main() {
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	int min = 0;
//	if (a < b) {
//		min = a;
//	}
//	else {
//		min = b;
//	}
//	long long i = min;
//	while (1) {
//		if (i % a == 0) {
//			if (i % b == 0) {
//				break;
//			}
//		}
//		i+=min;
//	}
//	printf("%ld", i);
//	return 0;
//}



//int main() {
//	char str[10] = { 0 };
//	int n = 0;
//	scanf("%s", str);
//	scanf("%d", &n);
//	for (int i = n; i < strlen(str); i++) {
//		printf("%c", str[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		printf("%c", str[i]);
//	}
//	return 0;
//}



//int main() {
//	char str1[10] = { 0 };
//	scanf("%s", str1);
//	char str2[10] = { 0 };
//	scanf("%s", str2);
//	for (int i = 0; i <= strlen(str1); i++) {
//		char str3[10] = { 0 };
//		int k = 0;
//		for (int j = i; j < strlen(str1); j++) {
//			str3[k] = str1[j];
//			k++;
//		}
//		for (int j = 0; j < i; j++) {
//			str3[k] = str1[j];
//			k++;
//		}
//		if (strcmp(str2, str3) == 0) {
//			printf("Yes");
//			return 0;
//		}
//	}
//	printf("No");
//	return 0;
//}


//struct student {
//	char name[20];
//	int age;
//};
//int compare1(const void* p1, const void* p2) {
//	double* e1 = (double*)p1;
//	double* e2 = (double*)p2;
//	if (*e1 > *e2) {
//		return 1;
//	}
//	if (*e1 == *e2) {
//		return 0;
//	}
//	if (*e1 < *e2) {
//		return -1;
//	}
//}
//int compare2(const void* p1, const void* p2) {
//	int* e1 = (int*)p1;
//	int* e2 = (int*)p2;
//	if (*e1 > *e2) {
//		return 1;
//	}
//	if (*e1 == *e2) {
//		return 0;
//	}
//	if (*e1 < *e2) {
//		return -1;
//	}
//}
//int compare3(const void* p1, const void* p2) {
//	struct student* e1 = (struct student*)p1;
//	struct student* e2 = (struct student*)p2;
//	if (e1->age > e2->age) {
//		return 1;
//	}
//	if (e1->age == e2->age) {
//		return 0;
//	}
//	if (e1->age < e2->age) {
//		return -1;
//	}
//}
//int main() {
//	double num1[10] = { 1.1,6.7,7.7,4.8,5.4,9.8,10.6,1.2,3.6,8.3 };
//	int num2[10] = { 3,6,7,9,11,17,13,19,1,4 };
//	struct student num3[4] = { {"zhangsan",15},{"wangwu",17},{"lisi",14},{"fanye",19} };
//	qsort(num1, sizeof(num1) / sizeof(num1[0]), sizeof(num1[0]), compare1);
//	qsort(num2, sizeof(num2) / sizeof(num2[0]), sizeof(num2[0]), compare2);
//	qsort(num3, sizeof(num3) / sizeof(num3[0]), sizeof(num3[0]), compare3);
//	for (int i = 0; i < 10; i++) {
//		printf("%lf ", num1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", num2[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 4; i++) {
//		printf("%s %d\n",num3[i].name, num3[i].age);
//	}
//	return 0;
//}

void my_bublesort(void*base,size_t num,size_t sz,int(*p)(void*,void*)) {
	char* start = (char*)base;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (p(start+j*sz, start + (j+1)*sz) > 0) {
				for (int k = 0; k < sz; k++) {
					char tmp = *(start+k+(j+1)*sz);
					*(start + (j+1)*sz + k) = *(start + k+j*sz);
					*(start + k+j*sz) = tmp;
				}
			}
		}
	}
}
int compare(const void* p1, const void* p2) {
	int* e1 = (int*)p1;
	int* e2 = (int*)p2;
	if (*e1 > *e2) {
		return 1;
	}
	if (*e1 == *e2) {
		return 0;
	}
	if (*e1 < *e2) {
		return -1;
	}
}
int main() {
	int arr[10] = { 7,3,9,5,1,13,11,17,21,4 };
	my_bublesort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}