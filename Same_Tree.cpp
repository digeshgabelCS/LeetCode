#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, trees are same till this branch
        if (p == nullptr && q == nullptr)
            return true;

        // If one of them is null or values don't match, trees differ
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Create first binary tree:
    //     1
    //    / \
    //   2   3
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Create second binary tree:
    //     1
    //    / \
    //   2   3
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(tree1, tree2);

    if (result)
        cout << "The two trees are the same." << endl;
    else
        cout << "The two trees are different." << endl;

    // Clean up allocated memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;

    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}