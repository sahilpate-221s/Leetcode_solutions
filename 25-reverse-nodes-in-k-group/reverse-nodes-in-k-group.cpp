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
    ListNode* reverse(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* last = reverse(head->next, k - 1);
        head->next->next = head;
        head->next = NULL;

        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (!node)
                return head;
            node = node->next;
        }

        ListNode* newHead = reverse(head, k);

        head->next = reverseKGroup(node, k);
        return newHead;
    }
};