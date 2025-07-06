#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inorderIndexMap[rootVal];
        int numsLeft = inRootIndex - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                     inorder, inStart, inRootIndex - 1);

        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                      inorder, inRootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1,
                               inorder, 0, inorder.size() - 1);
    }
};

void printInorder(TreeNode* node) {
    if (!node) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}