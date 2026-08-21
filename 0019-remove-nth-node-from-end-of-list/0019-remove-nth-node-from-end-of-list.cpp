/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n + 1 steps ahead to maintain a gap of n nodes
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up dummy node to avoid memory leaks
        return newHead;
    }
};