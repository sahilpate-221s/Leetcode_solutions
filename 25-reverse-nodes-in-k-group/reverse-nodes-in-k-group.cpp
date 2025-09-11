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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return NULL;

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) {
            return head;
        }

        count = 0;
        ListNode* curr = head;
        ListNode* currNext = NULL;
        ListNode* prev = NULL;

        while (curr != NULL && count < k) {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
            count++;
        }

        if (currNext != NULL) {
            head->next = reverseKGroup(currNext, k);
        }

        return prev;
    }
};