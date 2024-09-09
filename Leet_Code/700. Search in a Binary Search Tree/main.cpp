#include <iostream>
using namespace std;
#include <queue>
struct TreeNode {
    int val { };
    TreeNode* left { };
    TreeNode* right { };
    TreeNode(int val) : val(val) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == val)
                return node;
            if(node->left && node->val > val)
                q.push(node->left);
            else if(node->right && node->val < val)
                q.push(node->right);
        }
        return nullptr;
    }
};


//class Solution {
//public:
//    TreeNode* searchBST(TreeNode* root, int val) {
//        if(!root)
//            return nullptr;
//        if(val == root->val)
//            return root;
//        if(val > root->val)
//            return searchBST(root->right,val);
//        return searchBST(root->left,val);
//    }
//};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
