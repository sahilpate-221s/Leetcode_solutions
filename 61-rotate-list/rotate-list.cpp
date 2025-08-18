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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head)
            return head;

        int length = 0;
        ListNode* temp = head;
        ListNode* tail = 0;

        while (temp) {
            if (temp->next == NULL) {
                tail = temp;
            }
            temp = temp->next;
            length++;
        }

        k = k % length;
        temp = head;

        for (int i = 1; i < (length - k); i++) {
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;

        temp->next = NULL;

        return head;
    }
};