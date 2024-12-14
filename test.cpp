#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//    int longestOnes(vector<int>& nums, int k) {
//        int left = 0, right = 0, cnt = 0, length = 1, max = 0;
//        while (right < nums.size()) {
//            if (nums[right] == 0) {
//                cnt++;
//                if (cnt > k) {
//                    while (left <= right) {
//                        if (nums[left] == 0) {
//                            left++;
//                            cnt--;
//                            if (cnt <= k) {
//                                if (length > max) {
//                                    max = length;
//                                }
//                                length = right - left + 1;
//                                break;
//                            }
//                        }
//                        else {
//                            left++;
//                        }
//                    }
//                    right++;
//                }
//                else {
//                    right++;
//                    length++;
//                }
//            }
//            else {
//                right++;
//                length++;
//            }
//        }
//        return max;
//    }
//};
//class Solution {
//public:
//    void swap(int* x1, int* x2) {
//        int tmp = *x1;
//        *x1 = *x2;
//        *x2 = tmp;
//    }
//    void set_middle(int* left, int* right, int* middle) {
//        if (*left > *right) {
//            if (*right > *middle) {
//                swap(left, right);
//            }
//            else {
//                if (*left > *middle) {
//                    swap(left, middle);
//                }
//                //middle>left>right
//                else {
//                    ;
//                }
//            }
//        }
//        //right>left
//        else {
//            if (*left > *middle) {
//                ;
//            }
//            else {
//                if (*right > *middle) {
//                    swap(left, middle);
//                }
//                else {
//                    //middle>right>left
//                    swap(left, right);
//                }
//            }
//        }
//    }
//    int singlepass(vector<int>& nums, int left, int right) {
//        set_middle(&nums[left], &nums[right], &nums[(left + right) / 2]);
//        int key = nums[left];
//        int key_index = left;
//        while (left < right) {
//            while (right > left && nums[right] >= key) {
//                right--;
//            }
//            while (left < right && nums[left] <= key) {
//                left++;
//            }
//            swap(&nums[left], &nums[right]);
//        }
//        swap(&nums[left], &nums[key_index]);
//        return left;
//    }
//    void quicksort(vector<int>& nums, int left, int right) {
//        int key = singlepass(nums, left, right);
//        if (key - left > 1) {
//            quicksort(nums, left, key - 1);
//        }
//        if (right - key > 1) {
//            quicksort(nums, key + 1, right);
//        }
//    }
//    int minSubArrayLen(int target, vector<int>& nums) {
//        quicksort(nums, 0, nums.size() - 1);
//        int length = 0, sum = 0;
//        int right = nums.size() - 1;
//        while (sum < target) {
//            sum += nums[right];
//            right--;
//            length++;
//        }
//        return length;
//    }
//};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        for (int i = 0; i < s.size(); i++) {
            string tmp;
            tmp.push_back(s[i]);
            int cnt = 1;
            for (int j = i + 1; j < s.size(); j++) {
                int valid = 1;
                for (auto ch : tmp) {
                    if (ch == s[j]) {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                    tmp.push_back(s[j]);
                    cnt++;
                }
                else {
                    if (cnt > length) {
                        length = cnt;
                    }
                    break;
                }
            }
        }
        return length;
    }
};
int main() {
    /*Solution test;
    int a[] = { 0,0,1,1,1,0,0 };
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    test.longestOnes(nums, 0);*/
    /*Solution test;
    int target = 7;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    test.minSubArrayLen(target, nums);*/
    Solution test;
    string s1("jbpnbwwd");
    cout<<s1.size();
    test.lengthOfLongestSubstring(s1);
    return 0;
}