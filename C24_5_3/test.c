#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    if (head == NULL) {
        return head;
    }
    //Settle the head  position
    while (cur != NULL && (cur->val) == val) {
        struct ListNode* tmp = cur;
        head = cur->next;
        cur = cur->next;
        free(tmp);
    }
    if (head == NULL) {
        return head;
    }
    //Link a new list(without Nodeval==val)
    struct ListNode* new = cur;
    cur = cur->next;
    while (cur) {
        if (cur->val != val) {
            new->next = cur;
            new = cur;
            cur = cur->next;
        }
        else {
            struct ListNode* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    new->next = NULL;
    return head;
}

struct Node* copyRandomList(struct Node* head) {
    struct Node* newhead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ran, * old = head, * new = newhead, * curo = head, * curn = newhead;
    if (head == NULL) {
        return NULL;
    }
    while (curo != NULL) {
        struct Node* tmp;
        curn->val = curo->val;
        curo = curo->next;
        if (curo != NULL) {
            tmp = (struct Node*)malloc(sizeof(struct Node));
            curn->next = tmp;
            curn = tmp;
        }
        else {
            curn->next = NULL;
        }
    }
    while (new != NULL && old != NULL) {
        curn = newhead;
        curo = head;
        ran = old->random;
        while (curo != ran) {
            curo = curo->next;
            curn = curn->next;
        }
        new->random = curn;
        new = new->next;
        old = old->next;
    }
    return newhead;
}
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* prev = head, * cur = head->next, * next = head->next->next;
    head->next = NULL;
    while (cur) {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next != NULL)
            next = next->next;
    }
    return prev;
}
int main() {
    struct Node l1, l2, l3, l4, l5;
    struct Node* head = &l1;
    struct Node* newhead;
    l1.val = 7, l1.next = &l2,l1.random=NULL;
    l2.val = 13, l2.next = &l3,l2.random=&l1;
    l3.val = 11, l3.next = &l4,l3.random=&l5;
    l4.val = 10, l4.next = &l5,l4.random=&l3;
    l5.val = 1, l5.next = NULL,l5.random=&l1;
    newhead=copyRandomList(head);
    return 0;
}