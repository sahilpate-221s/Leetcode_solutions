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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        // finding the middle
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reversed = reverse(slow);

        ListNode* second = reversed;
        ListNode* first = head;

        while (second) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};