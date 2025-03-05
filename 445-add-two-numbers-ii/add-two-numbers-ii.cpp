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
        if(head==NULL || head->next==NULL)return head;

        ListNode* last = reverse(head->next);
        head->next->next=head;
        head->next = NULL;
        return last;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* first = l1;
        ListNode* second = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail  = dummy;
        int carry = 0;
        while(first != NULL && second != NULL)
        {
            int sum = (first->val + second->val) + carry;
            carry = sum/10;
            sum = sum%10;
            tail->next = new ListNode(sum);
            tail=tail->next;


            first=first->next;
            second=second->next;
        }

        while(first != NULL)
        {
            int sum = first->val + carry;
            carry = sum/10;
            sum = sum%10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            first=first->next;
        }
        while(second != NULL)
        {
            int sum = second->val + carry;
            carry = sum/10;
            sum = sum%10;

            tail->next = new ListNode(sum);
            tail=tail->next;
            second=second->next;
        }
        
        if(carry)
        {
            tail->next = new ListNode(carry);
        }

        return reverse(dummy->next);
    }
};