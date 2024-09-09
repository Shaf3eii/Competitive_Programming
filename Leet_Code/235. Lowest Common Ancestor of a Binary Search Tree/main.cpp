#include <iostream>
using namespace std;

struct TreeNode {
    int val { };
    TreeNode* left { };
    TreeNode* right { };
    TreeNode(int val) : val(val) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if((root->val >= min(p->val,q->val)) && (root->val <= max(q->val,p->val)))
            return root;
        if(root->val < p->val)
            return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
