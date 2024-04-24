#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//int my_strlen(const char* p) {
//	assert(p);
//	int cnt = 0;
//	while (*p++) {
//		cnt++;
//	}
//	return cnt;
//}
//int main() {
//	char str[10] = { 'A','B','C','g','p','i' };
//	printf("%d", my_strlen(str));
//	return 0;
//}

//void my_strcpy(char* dest,const char* src) {
//	assert(dest && src);
//	while (*dest++ = *src++) {
//		;
//	}
//}
//int main() {
//	char str1[7] = { 'A','C','b','p','o','q' ,0};
//	char str2[10] = { 0 };
//	my_strcpy(str2, str1);
//	printf("%s", str2);
//	return 0;
//}

//int my_strcmp(const char* p1,const char* p2) {
//	assert(p1 && p2);
//	while (*p1!=0 && *p2!=0) {
//		if (*p1 == *p2) {
//			p1++;
//			p2++;
//			continue;
//		}
//		return *p1 - *p2;
//	}
//	return *p1 - *p2;
//}
//int main() {
//	char str1[5] = { 'a','b','c','d',0 };
//	char str2[5] = { 'a','b','c','d',0 };
//	char str3[5] = { 'a','b','d','c',0 };
//	char str4[7] = { 'a','b','c','d','e',0 };
//	printf("%d\n", my_strcmp(str1, str2));
//	printf("%d\n", my_strcmp(str1, str3));
//	printf("%d\n", my_strcmp(str1, str4));
//	return 0;
//}

//char* my_strcat(const char*dest,const char*src) {
//	assert(dest && src);
//	char* p = dest;
//	while (*p != 0) {
//		p++;
//	}
//	while (*p++ = *src++) {
//		;
//	}
//	return dest;
//}
//int main() {
//	char str1[10] = { 'a','b','c','d','e',0 };
//	char str2[5] = { 'f','g','h',0 };
//	printf("%s", my_strcat(str1, str2));
//	return 0;
//}


//char* my_strstr(char* p1, char* p2) {
//	char* compare1 = p1;
//	char* head = p1;
//	char* compare2 = p2;
//	while (1) {
//		if (*compare1 == *compare2&&*compare1!=0) {
//			compare1++;
//			compare2++;
//		}
//		else {
//			if (*compare2 == 0) {
//				return head;
//			}
//			if (*compare1 == 0) {
//				return NULL;
//			}
//			head++;
//			compare1 = head;
//			compare2 = p2;
//		}
//	}
//}
//int main() {
//	char str1[10] = { 'A','B','D','C','B','D','P','U','W',0};
//	char str2[4] = { 'B','D','P',0 };
//	char* p=my_strstr(str1, str2);
//	if ( p!= NULL) {
//		strcpy(p, "Find");
//		printf("%s", str1);
//	}
//	return 0;
//}


//void* my_memcpy(void* dest, void* src, size_t n) {
//	assert(dest && src);
//	char* p1 = (char*)dest;
//	char* p2 = (char*)src;
//	for (int i = 0; i < n; i++) {
//		*(p1 + i) = *(p2 + i);
//	}
//	return p1;
//}
//int main() {
//	int arr1[7] = { 0,1,2,3,4,5,6 };
//	int arr2[5] = { 7,8,9,10,11 };
//	int* arr = (int*)my_memcpy(arr1, arr2,5*sizeof(arr1[0]));
//	for (int i = 0; i < 7; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

void* my_mommove(void* dest, void* src, size_t n) {
	assert(dest&&src);
	char* p1 = (char*)dest;
	char* p2 = (char*)src;
	if ( src>dest) {
		for (int i = 0; i < n; i++) {
			*(p1 + i) = *(p2 + i);
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			*(p1 + i) = *(p2 + i);
		}
	}
	return dest;
}

int main() {
	int arr[10] = { 0,1,7,3,11,13,4,5,6 };
	int*p=(int*)my_mommove(arr+3, arr , 5 * sizeof(arr[0]));
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}