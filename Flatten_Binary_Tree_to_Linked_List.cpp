#include <iostream>

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
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenTree(root, prev);
    }

private:
    void flattenTree(TreeNode* node, TreeNode*& prev) {
        if (!node) return;

        flattenTree(node->right, prev);
        flattenTree(node->left, prev);

        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
};

void printFlattened(TreeNode* root) {
    while (root) {
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << std::endl;
}

int main() {
    // Construct sample tree:
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(5, nullptr, new TreeNode(6));

    Solution sol;
    sol.flatten(root);

    printFlattened(root);

    return 0;
}