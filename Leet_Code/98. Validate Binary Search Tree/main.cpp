#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isValid(TreeNode *root, long long mini, long long maxi) {
        if (!root)
            return true;
        if (root->val >= maxi || root->val <= mini)
            return false;
        return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
    }
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    return 0;
}