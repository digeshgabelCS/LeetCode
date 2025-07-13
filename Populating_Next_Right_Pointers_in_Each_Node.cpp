#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Start with the leftmost node of the current level
        Node* leftmost = root;

        // Continue until we reach the leaf level
        while (leftmost->left) {
            // Iterate through the nodes at the current level
            Node* current = leftmost;
            while (current) {
                // Connect left child to right child
                current->left->next = current->right;

                // Connect right child to next node's left child, if exists
                if (current->next)
                    current->right->next = current->next->left;

                // Move to next node in current level
                current = current->next;
            }

            // Move to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};

// Helper function to print next pointers at each level
void printNextPointers(Node* root) {
    Node* level_start = root;
    while (level_start) {
        Node* current = level_start;
        while (current) {
            cout << current->val << "->";
            if (current->next)
                cout << current->next->val << " ";
            else
                cout << "NULL ";
            current = current->next;
        }
        cout << endl;
        level_start = level_start->left;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    printNextPointers(root);

    return 0;
}