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
    ListNode* swapNodes(ListNode* head, int k) {
        int i=1;
        ListNode* first=head;
        while(i != k && first != NULL)
        {
            first=first->next;
            i++;
        }

        int n=0;
        ListNode* last = head;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            temp=temp->next;
            n++;
        }

        n = n-k;

        while(n--)
        {
            last = last->next;
        }

        swap(first->val,last->val);

        return head;
        
    }
};