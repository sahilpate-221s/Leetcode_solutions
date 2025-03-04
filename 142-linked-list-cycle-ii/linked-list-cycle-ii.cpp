/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
     ListNode* fast = head;
     ListNode* slow = head;   

     while(fast != NULL && fast->next != NULL)
     {
        fast = fast->next->next;
        slow=slow->next;
        if(slow==fast)break;
     }

     if(fast != slow)return NULL;

        slow = head;
        while(fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};