#include <iostream>
#include <algorithm>
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
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main() {
    // Create a simple binary tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), nullptr);
    root->right = new TreeNode(3);

    Solution sol;
    int result = sol.minDepth(root);

    cout << "Minimum depth of the tree: " << result << endl;

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}