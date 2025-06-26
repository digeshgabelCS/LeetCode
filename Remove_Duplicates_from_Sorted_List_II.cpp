#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node before the head to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current) {
            // Check for duplicates
            bool duplicate = false;
            while (current->next && current->val == current->next->val) {
                duplicate = true;
                current = current->next;
            }
            
            if (duplicate) {
                // Skip all duplicates
                prev->next = current->next;
            } else {
                // No duplicate, move prev to current
                prev = prev->next;
            }
            
            current = current->next;
        }
        
        ListNode* result = dummy->next;
        delete dummy; // Free dummy node memory
        return result;
    }
};

// Helper to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to free linked list memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example: 1->2->3->3->4->4->5
    vector<int> values = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(result);

    // Clean up memory
    freeList(result);

    return 0;
}