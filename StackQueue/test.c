#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"

void Test_Stack() {
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d ", StackTop(&s));
	StackPop(&s);
	StackPush(&s, 5);
	while (!StackEmpty(&s)) {
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	StackDestroy(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d ", StackTop(&s));
	StackPop(&s);
	StackPush(&s, 5);
	while (!StackEmpty(&s)) {
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
}

void Test_Queue() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q)) {
		printf("%d ",QueueBack(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q)) {
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
}
int main() {
	Test_Stack();
	return 0;
}