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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                ListNode* next = curr->next;  // Save next pointer before deletion
                prev->next = curr->next;
                delete curr;
                curr = next;  // Use saved next pointer
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;

    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    Solution sol;

    // Example input
    vector<int> input = {1, 2, 6, 3, 4, 5, 6};
    int valToRemove = 6;

    // Create list and call removeElements
    ListNode* head = createList(input);
    cout << "Original List: ";
    printList(head);

    ListNode* newHead = sol.removeElements(head, valToRemove);
    cout << "Updated List: ";
    printList(newHead);

    // Free memory
    while (newHead) {
        ListNode* tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }

    return 0;
}
