#include <iostream>
#include <algorithm>
#include <cmath>

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
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; 
        
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; 
        
        if (std::abs(leftHeight - rightHeight) > 1)
            return -1;  
        
        return std::max(leftHeight, rightHeight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

TreeNode* createSampleTree() {
    TreeNode* leftChild = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    TreeNode* rightChild = new TreeNode(3);
    TreeNode* root = new TreeNode(1, leftChild, rightChild);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createSampleTree();
    
    if (solution.isBalanced(root))
        std::cout << "The binary tree is height-balanced.\n";
    else
        std::cout << "The binary tree is NOT height-balanced.\n";
    return 0;
}