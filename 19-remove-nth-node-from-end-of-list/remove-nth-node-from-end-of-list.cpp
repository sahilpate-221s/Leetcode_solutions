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
        if(!head)return NULL;

        ListNode* temp = head;
        for(int i=0;i<n;i++)
        {
            temp=temp->next;
        }
        if(temp == NULL)return head->next;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(temp)
        {
            prev = curr;
            curr=curr->next;
            temp=temp->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        return head;
        
    }
};