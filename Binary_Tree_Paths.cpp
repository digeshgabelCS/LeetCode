#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        dfs(root, "", result);
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        if (node->left) {
            dfs(node->left, path, result);
        }
        if (node->right) {
            dfs(node->right, path, result);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    cout << "Root-to-leaf paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}