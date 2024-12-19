#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        vector<int> st;
//        ListNode* pt = head;
//        int cnt = 0;
//        while (pt != nullptr) {
//            cnt++;
//            pt = pt->next;
//        }
//        pt = head;
//        int index = cnt - n;
//        int i = 0;
//        while (pt != nullptr) {
//            if (i != index) {
//                st.push_back(pt->val);
//            }
//            pt = pt->next;
//            i++;
//        }
//        pt = head;
//        i = 0;
//        while (pt != nullptr) {
//            pt->val = st[i];
//            if (pt->next->next == nullptr) {
//                pt->next = nullptr;
//            }
//            pt = pt->next;
//            i++;
//        }
//        return head;
//    }
//};

//class Solution {
//public:
//    bool checkInclusion(string s1, string s2) {
//        int hash_table1[26] = { 0 };
//        int parameter = 97;
//        for (auto ch : s1) {
//            hash_table1[ch - parameter]++;
//        }
//        for (int i = 0; i < s2.size(); i++) {
//            int hash_table2[26] = { 0 };
//            for (int j = i; j < i + s1.size(); j++) {
//                hash_table2[s2[j] - parameter]++;
//            }
//            for (int k = 0; k < 26; k++) {
//                if (hash_table1[k] == hash_table2[k]) {
//                    continue;
//                }
//                else {
//                    return false;
//                }
//            }
//            return true;
//        }
//        return true;
//    }
//};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash_table[26] = { 0 };
        for (auto ch : s1) {
            hash_table[ch - 97]++;
        }
        for (int i = 0; i < s1.size(); i++) {
            hash_table[s2[i] - 97]--;
        }
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            if (hash_table[i] > 0) {
                diff += hash_table[i];
            }
        }
        if (diff == 0) {
            return true;
        }
        for (int i = s1.size(); i < s2.size(); i++) {
            char come = s2[i];
            char go = s2[i - s1.size()];
            int cmp_come = hash_table[come - 97];
            int cmp_go = hash_table[go - 97];
            int after_come = --hash_table[come - 97];
            int after_go = ++hash_table[go - 97];
            if (cmp_come>0&&cmp_come > after_come && cmp_go < after_go&&cmp_go<0) {
                diff--;
            }
            if (diff == 0) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    //ListNode node1(1);
    //ListNode node2(2);
    //ListNode node3(3);
    //ListNode node4(4);
    //ListNode node5(5);
    //node1.next = &node2;
    //node2.next = &node3;
    //node3.next = &node4;
    //node4.next = &node5;
    //node5.next = nullptr;
    //Solution test;
    //test.removeNthFromEnd(&node1, 2);
    Solution test;
    string s1("ab");
    string s2("eidbaooo");
    test.checkInclusion(s1, s2);
    return 0;
}