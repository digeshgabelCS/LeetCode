#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> inorderIndexMap;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        postIndex = postorder.size() - 1;
        return buildSubTree(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndexMap[rootVal];

        root->right = buildSubTree(inorder, postorder, inIndex + 1, inRight);
        root->left  = buildSubTree(inorder, postorder, inLeft, inIndex - 1);

        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}