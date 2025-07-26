#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

int main() {
    ListNode* node4 = new ListNode(1);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution sol;
    bool result = sol.isPalindrome(node1);

    cout << (result ? "Palindrome" : "Not Palindrome") << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}