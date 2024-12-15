#include<iostream>
#include<string>
using namespace std;
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int right = 0, length = 0, cnt = 0;
//        char hash_table[128] = { 0 };
//        for (int left = 0; right < s.size();) {
//            while (right < s.size()) {
//                if (++hash_table[s[right]] > 1) {
//                    if (cnt > length) {
//                        length = cnt;
//                    }
//                    break;
//                }
//                else {
//                    right++;
//                    cnt++;
//                }
//            }
//            while (left < s.size() && hash_table[s[right]]>1) {
//                hash_table[s[left]]--;
//                left++;
//                cnt--;
//            }
//            right++;
//            cnt++;
//        }
//        if (cnt > length) {
//            length = cnt;
//        }
//        return length;
//    }
//};
class Solution {
public:
    string minWindow(string s, string t) {
        char* tmp=new char[s.size()];
        int rem_l = 0, rem_r = 0;
        int cnt = 0, length = 100000;
        int left = 0, right = 0;
        //includes A-z all characters inbetween
        char hash_table[58] = { 0 };
        for (auto ch : t) {
            hash_table[ch - 65]--;
        }
        //silde window begin
        while (left < s.size() && right < s.size()) {
            int valid = 1;
            while (right < s.size()) {
                hash_table[s[right] - 65]++;
                cnt++;
                tmp[right] = s[right];
                right++;
                //iterate hash_table to check 
                for (auto ch : hash_table) {
                    if (ch < 0) {
                        valid = 0;
                        break;
                    }
                }
                //if left-right contains t then stop
                if (valid == 1) {
                    valid = 0;
                    break;
                }
                valid = 1;
            }
            //the whole s do not contain t
            if (valid == 1) {
                break;
            }
            while (left < s.size()) {
                hash_table[s[left] - 65]--;
                cnt--;
                left++;
                //find the first character in tmp which in t;  
                for (auto ch : hash_table) {
                    if (ch < 0) {
                        valid = 1;
                        break;
                    }
                }
                if (valid == 1) {
                    break;
                }
            }
            //memeroize new valid substr
            if (valid == 1) {
                if (cnt + 1 < length) {
                    rem_l = left - 1;
                    rem_r = right-1;
                    length = cnt + 1;
                }
            }
        }
        if (length == 100000) {
            return "";
        }
        string fb;
        for (int i = rem_l; i <= rem_r; i++) {
            fb.push_back(tmp[i]);
        }
        return fb;
    }
};
int main() {
    Solution test;
    string s1("ADOBECODEBANC");
    string s2("ABC");
    cout<<test.minWindow(s1,s2);
    return 0;
}