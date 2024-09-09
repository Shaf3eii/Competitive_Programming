#include <iostream>
using namespace std;
#include <vector>
struct TreeNode {
    int val { };
    TreeNode* left { };
    TreeNode* right { };
    TreeNode(int val) : val(val) {}
};

class Solution {
    TreeNode* connect(vector<int>& nums,int st , int nd) {
        if(st > nd)
            return nullptr;
        int mid = st + (nd - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = connect(nums,st,mid-1);
        root->right = connect(nums,mid+1,nd);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return connect(nums,0,(int)nums.size() - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
