#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Solution class to convert sorted linked list to balanced BST */
class Solution {
public:
    ListNode* current;

    int getLength(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    TreeNode* buildTree(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        // Build left subtree
        TreeNode* leftChild = buildTree(left, mid - 1);

        // Create root node with current list node's value
        TreeNode* node = new TreeNode(current->val);
        node->left = leftChild;

        // Move to next list node
        current = current->next;

        // Build right subtree
        node->right = buildTree(mid + 1, right);

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        current = head;
        return buildTree(0, length - 1);
    }
};

/* Helper function to print BST in-order (for verification) */
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

/* Helper function to create a linked list from an array */
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

/* Main function to test the implementation */
int main() {
    // Example sorted linked list: [ -10, -3, 0, 5, 9 ]
    int arr[] = { -10, -3, 0, 5, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode* head = createLinkedList(arr, n);

    // Convert to BST
    Solution solution;
    TreeNode* bstRoot = solution.sortedListToBST(head);

    // Print BST In-Order (should be sorted)
    cout << "In-order traversal of the constructed BST: ";
    inorderPrint(bstRoot);
    cout << endl;

    return 0;
}