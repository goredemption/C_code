#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
static int cnt = 0;
class Solution {
public:
    void _pathSum(TreeNode* root, int sum, int val,int check) {
        if (root == nullptr) {
            return;
        }
        if (check == 0) {
            _pathSum(root->left, sum, 0,check);
            _pathSum(root->right, sum, 0,check);
        }
        val = root->val + val;
        if (val == sum) {
            cnt++;
        }
        if (root->left != nullptr) {
            _pathSum(root->left, sum, val, 1);
        }
        if (root->right != nullptr) {
            _pathSum(root->right, sum, val, 1);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        cnt = 0;
        if (root == nullptr) {
            return 0;
        }
        _pathSum(root, sum, 0,0);
        return cnt;
    }
};
int main() {
    TreeNode node1(-8);
    TreeNode node2(6);
    TreeNode node3(8);
    TreeNode node4(8);
    TreeNode node5(2);
    TreeNode node6(-2);
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    node5.right = &node6;
    Solution test;
    test.pathSum(&node1, -2);
    return 0;
}