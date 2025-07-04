#include <iostream>
using namespace std;

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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }
};

int main() {
    // Construct a symmetric tree:
    //       1
    //      / \
    //     2   2
    //    / \ / \
    //   3  4 4  3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    Solution solution;
    cout << (solution.isSymmetric(root) ? "Tree is symmetric" : "Tree is not symmetric") << endl;

    return 0;
}