#include <iostream>
#include <algorithm>  // for std::max

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + std::max(leftDepth, rightDepth);
    }
};

int main() {
    // Create a simple tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution solution;
    int depth = solution.maxDepth(root);

    std::cout << "Maximum Depth of the tree is: " << depth << std::endl;

    delete node4;
    delete node2;
    delete node3;
    delete root;

    return 0;
}