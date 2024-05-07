#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//void myitoa(int n, char* str) {
//    int i = 0;
//    char reverse[100] = { 0 };
//    while (n) {
//        reverse[i] = n % 10 + 48;
//        n /= 10;
//        i++;
//    }
//    int k = 0;
//    i--;
//    while (i >= 0) {
//        str[k] = reverse[i];
//        i--;
//    }
//}
//void strran(char* range, int begin, int end) {
//    char bg[100] = { 0 }, ed[100] = { 0 };
//    myitoa(begin, bg);
//    myitoa(end, ed);
//    if (begin == end) {
//        strcat(range, bg);
//    }
//    else {
//        strcat(range, bg);
//        strcat(range, "->");
//        strcat(range, ed);
//    }
//}
//char** summaryRanges(int* nums, int numsSize) {
//    int begin = 0, end = 0;
//    char* range = (char*)calloc(1000, sizeof(char));
//    for (int i = 0; i < numsSize;) {
//        begin = i;
//        end = i;
//        if (end == numsSize - 1) {
//            strran(range, nums[begin], nums[end]);
//            i++;
//        }
//        else {
//            while (nums[end] + 1 == nums[end + 1] && end < numsSize) {
//                end++;
//            }
//            strran(range, nums[begin], nums[end]);
//            i = end++;
//        }
//    }
//    return range;
//}
typedef struct {
    int* data;
    int front;
    int rear;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = 0;
    obj->rear = 0;
    obj->k = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->rear + 1) % (obj->k + 1) == obj->front) {
        return false;
    }
    else {
        obj->data[obj->rear] = value;
        obj->rear = (obj->rear + 1) % (obj->k + 1);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return false;
    }
    else {
        obj->front = (obj->front + 1) % (obj->k + 1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return -1;
    }
    else {
        return obj->data[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return -1;
    }
    else {
        return obj->data[(obj->rear + obj->k) % (obj->k + 1)];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->rear == obj->front) {
        return true;
    }
    else {
        return false;
    }
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->rear + 1) % (obj->k + 1) == obj->front) {
        return true;
    }
    else {
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}
int main() {
    MyCircularQueue* obj=myCircularQueueCreate(3);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueEnQueue(obj, 4);

    return 0;
}