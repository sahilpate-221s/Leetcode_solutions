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
        if (!head)
            return true;

        // finding the mid
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reversed = reverse(slow);
        ListNode* curr2 = reversed;

        ListNode* curr1 = head;

        while (curr2 != NULL) {
            if (curr1->val != curr2->val)
                return false;

                curr1 = curr1->next;
                curr2 = curr2->next;
        }
        return true;
    }
};