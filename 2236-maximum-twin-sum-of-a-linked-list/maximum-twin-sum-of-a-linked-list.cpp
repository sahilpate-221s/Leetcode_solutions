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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow=slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next==NULL)return head;

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }
    int pairSum(ListNode* head) {
        if(head==NULL || head->next == NULL)return 0;
        
        ListNode* middle = findMiddle(head);
        // cout<<middle->val;
        ListNode* secondHalf = reverse(middle);
        cout<<secondHalf->val;

        ListNode* first = head;
        ListNode* second = secondHalf;

        int maxi = -1;
        while(second != NULL)
        {
            int val = first->val + second->val;
            second=second->next;
            first=first->next;

            maxi = max(maxi,val);
        }

        return maxi;
    }
};