#include <iostream>
#include <set>
#include <vector>  

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> seen;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (seen.find(cur) != seen.end())
                return true;
            seen.insert(cur);
            cur = cur->next;
        }

        return false;
    }
};

ListNode* createListWithCycle(vector<int> values, int pos) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = nullptr;

    if (pos == 0) cycleNode = head;

    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos) cycleNode = current;
    }

    if (cycleNode != nullptr)
        current->next = cycleNode; 
    return head;
}

int main() {
    vector<int> values = {3, 2, 0, -4};
    int pos = 1;
    ListNode* head = createListWithCycle(values, pos);

    Solution sol;
    if (sol.hasCycle(head))
        cout << "Cycle detected in the linked list." << endl;
    else
        cout << "No cycle in the linked list." << endl;

    return 0;
}