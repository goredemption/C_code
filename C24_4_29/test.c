#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//void merge(int* nums1,  int m, int* nums2, int n) {
//    int* arr=(int*)malloc((m+n)*sizeof(int));
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < m && j < n) {
//        if (nums1[i] < nums2[j]) {
//            arr[k] = nums1[i];
//            i++;
//            k++;
//            continue;
//        }
//        if (nums1[i] > nums2[j]) {
//            arr[k] = nums2[j];
//            j++;
//             k++;
//             continue;
//        }
//        if (nums1[i] == nums2[j]) {
//            arr[k] = nums1[i];
//            k++;
//            arr[k] = nums2[j];
//            k++;
//            j++;
//            i++;
//            continue;
//        }
//    }
//    while (j < n) {
//        arr[k] = nums2[j];
//        j++;
//        k++;
//    }
//    while (i < m) {
//        arr[k] = nums1[i];
//        i++;
//        k++;
//    }
//    for (int p = 0; p < m + n; p++) {
//        nums1[p] = arr[p];
//    }
//}
//int main() {
//    int nums1[2] = { 2,0 };
//    int nums2[1] = { 1 };
//    int m = 1;
//    int n = 1;
//    merge(nums1, m, nums2, n);
//    return 0;
//}


//#include<stdio.h>
//#define offset(n,m) ((char*)&(m)-(char*)&(n)) 
//struct student {
//	char a;
//	int i;
//	char b;
//};
//int main() {
//	struct student S = { {'a'},{4},{'b'}};
//	int distance=(char*) & S.i - (char*) & S;
//
//	printf("%p\n%p\n", &S, &S.i);
//	printf("%d", distance);
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
#define oddeven(n) int i = 0b10101010101010101010101010101010
int j = 0b01010101010101010101010101010101;
int k = n & i
int p = n & j
n = k | p
int main() {
	int i = 0b10101010101010101010101010101010;
	int j = 0b01010101010101010101010101010101;
	int n = 0;
	scanf("%d", &n);
	int k = n & i;
	int p = n & j;
	n = k | p;
	/*int k = _CRT_INT_MAX;*/
	/*int n = 2;
	n = n & i;
	printf("%d", n);*/
	/*printf("%d %d\n", i ,j);
	printf("%d\n", _CRT_INT_MAX);
	char s[10];
	itoa(_CRT_INT_MAX, s, 2);
	printf("%s",s);*/
	return 0;
}