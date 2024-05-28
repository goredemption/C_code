#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* q) {
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType data) {
	assert(q);
	if (q->rear == NULL) {
		QNode* tmp = (QNode*)malloc(sizeof(QNode));
		if (tmp == NULL) {
			perror("malloc failed");
			return;
		}
		q->rear = tmp;
		q->front = tmp;
		tmp->next = NULL;
		tmp->data = data;
	}
	else {
		QNode* tmp = (QNode*)malloc(sizeof(QNode));
		if (tmp == NULL) {
			perror("malloc failed");
			return;
		}
		q->rear->next = tmp;
		q->rear = tmp;
		tmp->next = NULL;
		tmp->data = data;
	}
	q->size++;
}

void QueuePop(Queue* q) {
	assert(q);
	assert(q->front != NULL);
	if (q->front->next == NULL) {
		QNode* first = q->front;
		q->front = q->front->next;
		free(first);
		q->rear = NULL;
	}
	else {
		QNode* first = q->front;
		q->front = q->front->next;
		free(first);
	}
	q->size--;
}

QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->front != NULL);
	return q->front->data;
}

QDataType QueueBack(Queue* q) {
	assert(q);
	assert(q->rear != NULL);
	return q->rear->data;
}

int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}

bool QueueEmpty(Queue* q) {
	assert(q);
	return q->size == 0;
}

void QueueDestroy(Queue* q) {
	assert(q);
	QNode* cur = q->front;
	while (cur) {
		QNode* next=cur->next;
		free(cur);
		cur = next;
	}
	q->size = 0;
	q->rear = NULL;
}