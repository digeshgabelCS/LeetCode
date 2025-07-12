#include <iostream>
#include <vector>
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
    vector<vector<int>> result;

    void dfs(TreeNode* node, int targetSum, vector<int>& path, int currentSum) {
        if (!node) return;

        path.push_back(node->val);
        currentSum += node->val;

        if (!node->left && !node->right) {
            if (currentSum == targetSum) {
                result.push_back(path);
            }
        } else {
            dfs(node->left, targetSum, path, currentSum);
            dfs(node->right, targetSum, path, currentSum);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path, 0);
        return result;
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    /*
        Construct the following binary tree:
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \     / \
        7    2   5   1

        targetSum = 22
    */

    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->right->right->left = newNode(5);
    root->right->right->right = newNode(1);

    int targetSum = 22;

    Solution solution;
    vector<vector<int>> paths = solution.pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":" << endl;
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}