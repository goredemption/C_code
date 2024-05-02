#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void test1() {
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl,1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}
void test2() {
	SeqList sl;
	SeqListInit(&sl);
	SeqListInsert(&sl, 0,1);
	SeqListInsert(&sl, 1,2);
	SeqListInsert(&sl, 2,3);
	SeqListInsert(&sl, 3,4);
	SeqListPrint(&sl);
	SeqListErase(&sl, 0);
	SeqListPrint(&sl);
	SeqListErase(&sl, 0);
	SeqListPrint(&sl);
	SeqListErase(&sl, 0);
	SeqListPrint(&sl);
	SeqListErase(&sl, 0);
	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}
int main() {
	int run = 1;
	SeqList sl;
	SeqListInit(&sl);
	do {
		menu();
		int x = 0;
		scanf("%d", &x);
		switch (x) {
		case 0: {
			run = 0;
			break;
		}
		case 1: {
			int tmp=0;
			scanf("%d", &tmp);
			SeqListPushBack(&sl, tmp);
			break;
		}
		case 2: {
			int tmp = 0;
			scanf("%d", &tmp);
			SeqListPushFront(&sl, tmp);
			break;
		}
		case 3: {
			SeqListPopBack(&sl);
			break;
		}
		case 4: {
			SeqListPopFront(&sl);
			break;
		}
		case 5: {
			int pos = 0;
			int val = 0;
			printf("Position and Value:>");
			scanf("%d %d", &pos,&val);
			SeqListInsert(&sl, pos, val);
			break;
		}
		case 6: {
			int pos = 0;
			printf("Position:>");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
			break;
		}
		case 7: {
			int val = 0;
			printf("Value Looking For:>");
			scanf("%d", &val);
			val=SeqListFind(&sl, val);
			printf("Position:>%d\n", val);
			break;
		}
		case 8: {
			SeqListPrint(&sl);
			break;
		}

		default: {
			printf("Invalid Input\n");
			break;
		}
		}
	} while (run);
	SeqListDestroy(&sl);
	return 0;
}