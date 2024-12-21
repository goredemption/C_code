#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> back;
        for (auto en : smalls) {
            vector<int> tmp;
            if (en.empty()) {
                back.push_back(tmp);
                continue;
            }
            int index_b = 0;
            int index_s = 0;
            while (index_b < big.size()) {
                int begin = index_b;
                while (index_s < en.size() && index_b < big.size()) {
                    if (en[index_s] != big[index_b]) {
                        break;
                    }
                    index_s++;
                    index_b++;
                }
                if (index_s==en.size()) {
                    tmp.push_back(begin);
                }
                index_s = 0;
                index_b = begin+1;
            }
            back.push_back(tmp);
        }
        return back;
    }
};
int main() {
    vector<string> smalls;
    smalls.push_back("is");
    smalls.push_back("ppi");
    smalls.push_back("hi");
    smalls.push_back("sis");
    smalls.push_back("i");
    smalls.push_back("ssippi");
    string big("mississippi");
    Solution test;
    test.multiSearch(big, smalls);
    return 0;
}