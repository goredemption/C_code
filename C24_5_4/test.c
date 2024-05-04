#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;
bool chkPalindrome(ListNode* A) {
    ListNode* head = A, * middle, * tail, * cur = A, * prev, * next;
    if (A==NULL) {
        return false;
    }
    if (A->next == NULL) {
        return true;
    }
    if (A->next->next == NULL) {
        if (A->val == A->next->val) {
            return true;
        }
        else {
            return false;
        }
    }
    int cnt = 1;
    while (cur->next) {
        cnt++;
        cur = cur->next;
    }
    tail = cur;
    cur = A;
    for (int i = 0; i < cnt / 2; i++) {
        cur = cur->next;
    }
    middle = cur;
    prev = middle;
    cur = cur->next;
    next = cur->next;
    while (cur) {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next) {
            next = next->next;
        }
    }
    int k = 0;
    for (int i = 0; i < cnt / 2; i++) {
        if (head->val == tail->val) {
            k++;
        }
        head = head->next;
        tail = tail->next;
    }
    if (k == cnt / 2) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ListNode n1, n2, n3, n4;
    ListNode* head = &n1;
    n1.val = 1, n1.next = &n2;
    n2.val = 2, n2.next = &n3;
    n3.val = 2, n3.next = &n4;
    n4.val = 1, n4.next = NULL;
    bool a=chkPalindrome(head);
    return 0;
}