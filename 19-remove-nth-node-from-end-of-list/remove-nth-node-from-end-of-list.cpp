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

        ListNode* curr = head;

        for(int i=0;i<n;i++)
        {
            curr=curr->next;
        }

        if(!curr)
        {
            return head->next;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(curr)
        {
            curr=curr->next;
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        return head;


        
    }
};