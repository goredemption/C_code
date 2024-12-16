#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int biggest = -1;
//        for (auto en : fruits) {
//            if (en > biggest) {
//                biggest = en;
//            }
//        }
//        int* hash_table = new int[biggest + 1];
//        for (int i = 0; i < biggest + 1; i++) {
//            hash_table[i] = 0;
//        }
//        int left = 0, right = 0, length = 0, len_count = 0, two_count = 0;
//        while (left < fruits.size() && right < fruits.size()) {
//            while (right < fruits.size()) {
//                if (hash_table[fruits[right]] == 0) {
//                    two_count += 1;
//                }
//                if (two_count > 2) {
//                    break;
//                }
//                hash_table[fruits[right]]++;
//                len_count++;
//                right++;
//            }
//            if (len_count > length) {
//                length = len_count;
//            }
//            while (left < fruits.size() && right < fruits.size()) {
//                hash_table[fruits[left]]--;
//                len_count--;
//                int l = left;
//                left++;
//                if (hash_table[fruits[l]] == 0) {
//                    two_count--;
//                    break;
//                }
//            }
//            if (right < fruits.size()) {
//                hash_table[fruits[right]]++;
//                len_count++;
//                right++;
//            }
//        }
//        return length;
//    }
//};
//class queue {
//public:
//    queue(int x)
//        : _capacity(x)
//    {
//        _arr = new int[10];
//    }
//    ~queue() {
//        delete[] _arr;
//    }
//private:
//    int* _arr;
//    int _size;
//    int _capacity;
//};
class Solution {
public:
    int _searchMatrix(vector<vector<int>>& matrix, int row, int col,
        int target) {
        if (row > matrix.size()-1 && col > matrix[0].size()-1) {
            return 0;
        }
        if (matrix[row][col] > target) {
            return 0;
        }
        if (matrix[row][col] == target) {
            return 1;
        }
        int i = _searchMatrix(matrix, row + 1, col, target);
        if (i == 1) {
            return 1;
        }
        int j = _searchMatrix(matrix, row, col + 1, target);
        if (j == 1) {
            return 1;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = 0;
        return _searchMatrix(matrix, row, col, target);
    }
};
int main() {
    /*Solution test;
    vector<int> fruits;
    fruits.push_back(3);
    fruits.push_back(3);
    fruits.push_back(3);
    fruits.push_back(1);
    fruits.push_back(2);
    fruits.push_back(1);
    fruits.push_back(1);
    fruits.push_back(2);
    fruits.push_back(3);
    fruits.push_back(3);
    fruits.push_back(4);
    test.totalFruit(fruits);*/
    Solution test;
    vector<vector<int>> num;
    vector<int> a1;
    a1.push_back(1);
    a1.push_back(4);
    a1.push_back(7);
    a1.push_back(11);
    a1.push_back(15);
    vector<int> a2;
    a2.push_back(2);
    a2.push_back(5);
    a2.push_back(8);
    a2.push_back(12);
    a2.push_back(19);
    vector<int> a3;
    a3.push_back(3);
    a3.push_back(6);
    a3.push_back(9);
    a3.push_back(16);
    a3.push_back(22);
    vector<int> a4;
    a4.push_back(10);
    a4.push_back(13);
    a4.push_back(14);
    a4.push_back(17);
    a4.push_back(24);
    vector<int> a5;
    a5.push_back(18);
    a5.push_back(21);
    a5.push_back(23);
    a5.push_back(26);
    a5.push_back(30);
    num.push_back(a1);
    num.push_back(a2);
    num.push_back(a3);
    num.push_back(a4);
    num.push_back(a5);
    test.searchMatrix(num,5);
    return 0;
}