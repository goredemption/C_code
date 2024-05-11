#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

// 堆的构建
void HeapCreate(Heap* hp, int n) {
	assert(hp);
	HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (tmp == NULL) {
		perror("malloc failed");
		return;
	}
	hp->arr = tmp;
	hp->capacity = n;
	hp->size = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->capacity = 0;
	hp->size = 0;
}
void Swap(HPDataType* p1, HPDataType* p2) {
	HPDataType* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void UpAdjustment(HPDataType* arr, int child) {
	int parent = (child - 1) / 2;
	while (child>0) {
		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else {
			break;
		}
	}
}
void DownAdjustment(HPDataType* arr, int size) {
	int parent = 0;
	int child = parent * 2 + 1;
	while(child<size){
		if (arr[child] < arr[child + 1]&&child+1<size) {
			child += 1;
		}
		if (arr[parent] < arr[child]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else {
			break;
		}
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	assert(hp->arr);
	if (hp->size == hp->capacity) {
		int newcapacity = hp->capacity == 0 ? 5 : 2 * hp->capacity;
		HPDataType* tmp = (HPDataType*)realloc(hp->arr, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL) {
			perror("realloc failed");
			exit(-1);
		}
		hp->arr = tmp;
		hp->capacity = newcapacity;
	}
	hp->arr[hp->size] = x;
	hp->size++;
	UpAdjustment(hp->arr,hp->size-1);
}
// 堆的删除
void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->size);
	Swap(&hp->arr[0],&hp->arr[hp->size-1]);
	hp->size--;
	DownAdjustment(hp->arr,hp->size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(hp->size);
	return hp->arr[0];
}
// 堆的数据个数
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->size;
}
// 堆的判空
bool HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->size == 0;
}