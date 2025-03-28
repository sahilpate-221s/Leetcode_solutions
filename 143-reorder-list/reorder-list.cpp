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
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next)return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        if(!l1)return l2;
        if(!l2)return l1; 

        ListNode* next1 = l1->next;
        ListNode* next2 = l2->next;

        l1->next = l2;
        l2->next = mergeList(next1,next2);
        return l1;
    }
    void reorderList(ListNode* head) {

        if(!head->next)return;
        ListNode* fast = head;
        ListNode* slow= head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL )
        {
            fast=fast->next->next;
            prev = slow;
            slow=slow->next;
        }

        prev->next = NULL;
        ListNode* reversed = reverseList(slow);

        ListNode* l1 = head;
        ListNode* l2 = reversed;

        head = mergeList(l1,l2);
    }
};