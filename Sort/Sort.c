#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"
void Swap(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n) {
	int begin = 0;
	int end = 0;
	int cp = end + 1;
	while (cp < n) {
		while (end >= begin) {
			if (a[end] > a[end + 1]) {
				Swap(&a[end], &a[end + 1]);
				end--;
			}
			else {
				break;
			}
		}
		end = cp;
		cp++;
	}
}

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n) {
	int gap = n / 3;
	while (1) {
		int end = 0;
		int begin = 0;
		int cp = 0;
		while (begin < gap) {
			end = begin;
			cp = end + gap;
			while (cp < n) {
				while (end >= begin) {
					if (a[end] > a[end + gap]) {
						Swap(&a[end], &a[end + gap]);
						end -= gap;
					}
					else {
						break;
					}
				}
				end = cp;
				cp += gap;
			}
			begin++;
		}
		if (gap == 1) {
			break;
		}
		gap = gap / 3 + 1;
	}

}

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int cur = begin;
		int* tb = &a[begin], * ts = &a[end];
		while (cur <= end) {
			if (a[cur] > *tb) {
				tb = &a[cur];
			}
			if (a[cur] < *ts) {
				ts = &a[cur];
			}
			cur++;
		}
		Swap(tb, &a[end]);
		if (ts == &a[end]) {
			ts = tb;
		}
		else {
			Swap(ts, &a[begin]);
		}
		begin++;
		end--;
	}
}


// ∂—≈≈–Ú
void AdjustDown(int* a, int n, int root) {
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	while (root < n) {
		if (left >= n) {
			break;
		}
		int big = left;
		if (right < n && a[left] < a[right]) {
			big = right;
		}
		if (a[big] < a[root]) {
			break;
		}
		Swap(&a[root], &a[big]);
		root = big;
		left = root * 2 + 1;
		right = root * 2 + 2;
	}
}

void HeapSort(int* a, int n) {
	int insert = 0;
	while (insert < n) {
		int root = (insert - 1) / 2;
		while (root > 0) {
			AdjustDown(a, insert + 1, root);
			root = (root - 1) / 2;
		}
		AdjustDown(a, insert + 1, root);
		insert++;
	}
	int end = n - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

// √∞≈›≈≈–Ú
void BubbleSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1- i; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void SetMiddle(int* x, int* y, int* z) {
	if (*x > *z) {
		//*x>*z>*y
		if (*z > *y) {
			Swap(x, z);
		}
		//*x>*z *y>*z
		else {
			//*x>*y>*z
			if (*x > *y) {
				Swap(x, y);
			}
			//*y>*x>*z
		}
	}
	//*z>*x
	else {
		//*y>*z>*x
		if (*y > *z) {
			Swap(x, z);
		}
		//*z>*y *z>*x
		else {
			//*z>*y>*x
			if (*y > *x) {
				Swap(y, x);
			}
			//*z>*x>*z
		}
	}
}

int SinglePassSort1(int* a, int left, int right) {
	SetMiddle(&a[left], &a[right], &a[(right + left) / 2]);
	int key = left;
	while (right > left) {
		while (right > left&&a[right]>a[key]) {
			if (a[right] <= a[key]) {
				break;
			}
			right--;
		}
		while (left < right) {
			if (a[left] > a[key]) {
				Swap(&a[left], &a[right]);
				break;
			}
			left++;
		}
	}
	Swap(&a[key], &a[left]);
	return left;
}

void QuickSort(int* a, int left, int right) {
	int key=SinglePassSort2(a, left, right);
	if (key-1 > left) {
		QuickSort(a, left, key - 1);
	}
	if (key+1 < right) {
		QuickSort(a, key + 1, right);
	}
}

// øÏÀŸ≈≈–ÚÕ⁄ø”∑®
int SinglePassSort2(int* a, int left, int right) {
	SetMiddle(&a[left], &a[right], &a[(right + left) / 2]);
	int hole=left;
	int key = a[left];
	while (left < right) {
		while (right > left) {
			if (a[right] < key) {
				Swap(&a[hole], &a[right]);
				hole = right;
				break;
			}
			right--;
		}
		while (left < right) {
			if (a[left] > key) {
				Swap(&a[hole], &a[left]);
				hole = left;
				break;
			}
			left++;
		}
	}
	a[hole] = key;
	return hole;
}