#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#define SZ 10
//int main() {
//	int arr[SZ] = { 0 };
//	int* left = NULL;
//	int* right = NULL;
//	for (int i = 0; i < SZ; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < SZ-1; i++) {
//		left = (&arr[0] + i);
//		right = left + 1;
//		while (*left != *right&&*left!=0&&right<=&arr[SZ-1]) {
//			right++;
//		}
//		if (*left == *right && *left != 0) {
//			*left = 0;
//			*right = 0;
//		}
//	}
//	for (int i = 0; i < SZ; i++) {
//		if (arr[i] != 0) {
//			printf("Bachelor:>%d\n", arr[i]);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//char* my_strncpy(char* p1, char* p2, int n) {
//	int lenth = strlen(p2);
//	//n>strlen(p2)
//	if (n > lenth) {
//		int i;
//		for (i = 0; i < lenth; i++) {
//			p1[i] = p2[i];
//		}
//		for (i; i < n; i++) {
//			p1[i] = 0;
//		}
//	}
//	//n<=strlen(p2)
//	if (n <= lenth) {
//		for (int i = 0; i < n; i++) {
//			p1[i] = p2[i];
//		}
//	}
//	return p1;
//}
//int main() {
//	char str1[8] = "ertyuiop";
//	char str2[7] = "abcdef";
//	my_strncpy(str1, str2, 9);
//	printf("%s", str1);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//char* my_strncat(char* p1, char* p2, int n) {
//	int lenth = strlen(p2);
//	//n>strlen(p2)
//	if (n > lenth) {
//		char* append = p1;
//		while (*append != 0) {
//			append++;
//		}
//		for (int i = 0; i < lenth; i++) {
//			append[i] = p2[i];
//		}
//	}
//	//n<=strlen(p2)
//	if (n <= lenth) {
//		char* append = p1;
//		while (*append != 0) {
//			append++;
//		}
//		int i = 0;
//		for (i = 0; i < n; i++) {
//			append[i] = p2[i];
//		}
//		append[i] = 0;
//	}
//	return p1;
//}
//int main() {
//	char str1[12] = {'a','b','c','d','e','\0','f','g','h','i','j','k'};
//	char str2[] = "fghlij";
//	my_strncat(str1, str2, 6);
//	printf("%s", str1);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int my_atoi(char* p1) {
	while (*p1 < 48 || *p1>57) {
		p1++;
	}
	char* p = p1;
	while (*p1 >= 48 && *p1 <= 57) {
		p1++;
	}
	*p1 = 0;
	int lenth = strlen(p);
	int value = 0;
	for (int i = lenth-1; i >=0; i--) {

	}
}
int main() {
	char str[10] = { '1','2','3','4','a','b','c','5','6','\0' };
	int i = atoi(str);
	printf("%d", i);
	return 0;
}