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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next == NULL)return head;

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL)return head;
        ListNode* reversed= reverse(head);

        ListNode* curr = reversed;
        int carry = 0;

        while(curr!= NULL)
        {
            int value = (curr->val *2 + carry );
            carry = value/10;
            value = value%10;
            curr->val = value;

            curr=curr->next;
        }

        head= reverse(reversed);

        if(carry > 0)
        {
            ListNode* carryNode = new ListNode(carry);
            carryNode->next = head;
            head = carryNode;
        }
        return head;
        
    }
};