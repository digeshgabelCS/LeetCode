#include <iostream>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the priority queue (min-heap)
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Min-heap to keep track of the current smallest node
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Initialize heap with the head of each list
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        // Dummy head to simplify code
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage:
    vector<ListNode*> lists;

    // Creating 3 sample sorted linked lists
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    // Merging the lists
    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    // Printing the merged list
    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}