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
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy heads for two partitions
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);
        
        // Pointers to the current last node of each partition
        ListNode* before = beforeHead;
        ListNode* after = afterHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        // Important: terminate the after list
        after->next = nullptr;
        
        // Connect before list with after list
        before->next = afterHead->next;
        
        // Result head is the next of dummy beforeHead
        ListNode* result = beforeHead->next;
        
        // Clean up dummy nodes
        delete beforeHead;
        delete afterHead;
        
        return result;
    }
};

// Helper function to create a linked list from an array
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

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the partition function
int main() {
    int arr[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.partition(head, x);

    cout << "Partitioned list (x = " << x << "): ";
    printList(result);

    return 0;
}
