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
        if(!head)return head;
        ListNode* curr =  head;

        for(int i=0;i<n;i++)
        {
            curr = curr->next;
        }

        if(!curr)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp; // free memory
            return head;
        }

        ListNode* slow = head;
        ListNode* prev = NULL;

        while(curr != NULL)
        {
            curr=curr->next;
            prev = slow;
            slow = slow->next;


        }
        prev->next = slow->next;
        slow->next = NULL;
        return head;


        
    }
};