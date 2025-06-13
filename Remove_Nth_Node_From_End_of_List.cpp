#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node pointing to head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers, both starting at dummy
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead to maintain a gap of n between fast and slow
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow is before the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;

        // Free memory of deleted node
        delete toDelete;

        // Get the new head and clean up dummy
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};

// Helper function to create linked list from array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}