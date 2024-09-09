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

    int _sumofleftleaves(TreeNode* cur_node, bool left, int &cur_sum) const {
        if(!cur_node)
            return 0;
        if(!cur_node->left && !cur_node->right && left)
            cur_sum += cur_node->data;
        _sumofleftleaves(cur_node->left, true,cur_sum);
        _sumofleftleaves(cur_node->right, false,cur_sum);
        return cur_sum;
    }

    int _maxDepth(TreeNode* cur_node) const {
        if(!cur_node)
            return 0;
        return 1 + max(_maxDepth(cur_node->right), _maxDepth(cur_node->left));
    }

    // The Tree is perfect if each node have 2 children except the leaf node
    bool _isPerfectTree(TreeNode *cur_node,int depth, int level) const {
        if(!cur_node)
            return true;
        if(!cur_node->left && !cur_node->right)
            return depth == (level + 1);
        if(!cur_node->left || !cur_node->right)
            return false;
        return _isPerfectTree(cur_node->left,depth,level+1) ||
               _isPerfectTree(cur_node->right,depth,level+1);
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

    bool isPerfectTree() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
        int depth = _maxDepth(root);
        return _isPerfectTree(root,depth,0);
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
