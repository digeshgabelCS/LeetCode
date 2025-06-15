#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Iterate while there are at least two nodes to swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* swapped = sol.swapPairs(head);

    cout << "Swapped List:  ";
    printList(swapped);

    return 0;
}