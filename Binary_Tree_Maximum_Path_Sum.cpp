#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftMax = max(0, dfs(node->left));  
        int rightMax = max(0, dfs(node->right));

        maxSum = max(maxSum, node->val + leftMax + rightMax);

        return node->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

TreeNode* buildSampleTree() {
    //       -10
    //       /  \
    //      9   20
    //          / \
    //         15  7

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution solution;
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;  
    return 0;
}