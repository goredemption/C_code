#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> tri;
        tri.resize(rowIndex);
        int j = 1;
        for (int i = 0; i < rowIndex; i++) {
            tri[i].resize(j);
            tri[i][0] = 1;
            tri[i][j - 1] = 1;
            j++;
        }
        for (int i = 2; i < rowIndex; i++) {
            for (j = 1; j < tri[i].size() - 1; j++) {
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
        }
        return tri[rowIndex - 1];
    }
};
int main() {
    int test = 3;
    Solution t;
    vector<int> tmp = t.getRow(test);
    return 0;
}