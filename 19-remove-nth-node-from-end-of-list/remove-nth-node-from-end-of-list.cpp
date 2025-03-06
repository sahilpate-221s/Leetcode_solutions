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

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        for(int i=0;i<n;i++)
        {
            fast = fast->next;
        }
         if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = slow->next;
        delete slow;
        return head;


        
    }
};