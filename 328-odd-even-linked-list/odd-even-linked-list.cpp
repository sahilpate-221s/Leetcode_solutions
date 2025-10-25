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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* odd = new ListNode(-1);
        ListNode* oddStart = odd;
        ListNode* even = new ListNode(-1);
        ListNode* evenStart = even;

        ListNode* curr = head;
        int count = 1;
        while (curr) {
            if (count % 2 == 0) {
                even->next = curr;
                even = even->next;
            } else {
                odd->next = curr;
                odd = odd->next;
            }
            count++;
            curr = curr->next;
        }
        even->next = NULL;

        ListNode* temp = oddStart;
        oddStart = oddStart->next;
        delete temp;

        ListNode* sec = evenStart;
        evenStart = evenStart->next;
        delete sec;

        odd->next = evenStart;
        return oddStart;
    }
};