#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int data{};
    TreeNode *right{};
    TreeNode *left{};

    TreeNode(int data) : data(data) {
    }
};

class BinaryTree {
    TreeNode *root{};

    void _print(TreeNode *cur) const {
        if (!cur)
            return;
        _print(cur->left);
        cout << cur->data << ' ';
        _print(cur->right);
    }

    bool _hasPathSum(TreeNode *cur_node, int targetSum, int curSum) const {
        if(!cur_node)
            return false;

        curSum += cur_node->data;
        if(!cur_node->right && !cur_node->left) // we need to reach the leaves
            return curSum == targetSum;

        return _hasPathSum(cur_node->right,targetSum,curSum) ||
               _hasPathSum(cur_node->left,targetSum,curSum);
    }

public:
    BinaryTree(int val) : root(new TreeNode(val)) {} // o(1) time - o(1) memory

    void add(vector<int> values, vector<char> directions) { // o(n) time - o(n) memory
        if ((int) values.size() != (int) directions.size())
            throw out_of_range("Values Not Equal Size.\n");

        transform(directions.begin(), directions.end(), directions.begin(), ::toupper);

        TreeNode *cur = this->root;
        for (int i = 0; i < (int) values.size(); ++i) {
            if (directions[i] == 'R') {
                if (!cur->right)
                    cur->right = new TreeNode(values[i]);
                else if (cur->right->data != values[i])
                    throw out_of_range("Invalid Path.\n");
                cur = cur->right;
            } else if (directions[i] == 'L') {
                if (!cur->left)
                    cur->left = new TreeNode(values[i]);
                else if (cur->left->data != values[i])
                    throw out_of_range("Invalid Path.\n");
                cur = cur->left;
            } else
                throw out_of_range("Invalid Direction.\n");
        }
    }

    void print() const { // o(n) time - o(n) memory
        _print(root);
        cout << '\n';
    }

    // return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
    bool hasPathSum(int target) const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
        return _hasPathSum(root,target,0);
    }
};

int main() {
    BinaryTree T(1);
    T.add({2,4,7},{'L','L','L'});
    T.add({2,4,8},{'L','L','R'});
    T.add({2,5,9},{'L','R','R'});
    T.add({2,5,4},{'L','R','L'});
    T.add({3,6,10},{'R','R','L'});
    T.add({3,6,13},{'R','R','R'});
    T.add({3,6,13},{'R','L','L'});
    T.add({3,6,13},{'R','L','R'});
    T.print();
    return 0;
}
