#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    vector<TreeNode*> solve(int start, int end) {
        // Base case: if start > end, there is no tree, so return a vector with nullptr
        if (start > end)
            return {nullptr};

        vector<TreeNode*> ans;

        // Try every number between start and end as the root
        for (int i = start; i <= end; i++) {
            // Recursively get all possible left and right subtrees
            vector<TreeNode*> leftTrees = solve(start, i - 1);
            vector<TreeNode*> rightTrees = solve(i + 1, end);

            // Combine left and right trees with the current root i
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return solve(1, n);
    }
};

// Helper function to print pre-order traversal (for testing/debugging)
void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Main function for testing
int main() {
    Solution sol;
    int n = 3;
    vector<TreeNode*> result = sol.generateTrees(n);

    cout << "Total unique BSTs with " << n << " nodes: " << result.size() << endl;

    // Print each tree's preorder traversal
    int idx = 1;
    for (auto tree : result) {
        cout << "Tree " << idx++ << ": ";
        preorder(tree);
        cout << endl;
    }

    return 0;
}