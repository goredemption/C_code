#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void test1() {

}

int main() {
	Heap hp;
	HeapCreate(&hp, 0);
	HeapPush(&hp, 1);
	HeapPush(&hp, 15);
	HeapPush(&hp, 3);
	HeapPush(&hp, 2);
	HeapPush(&hp, 5);
	HeapPush(&hp, 8);
	HeapPush(&hp, 7);
	HeapPush(&hp, 2);
	HeapPush(&hp, 9);
	HeapPush(&hp, 10);
	while (!HeapEmpty(&hp)) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapDestory(&hp);
	return 0;
}