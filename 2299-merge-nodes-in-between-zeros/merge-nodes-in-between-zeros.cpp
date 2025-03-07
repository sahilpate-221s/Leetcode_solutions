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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL)return head;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* dummyTemp = dummyNode;

        int sum = 0;
        ListNode* temp = head;

        temp=temp->next;
        while(temp != NULL)
        {
            if(temp->val!=0)
            {
                sum+= temp->val;
            }
            
            if(temp->val == 0)
            {
                dummyTemp->next = new ListNode(sum);
                sum=0;
                dummyTemp = dummyTemp->next;
            }

            temp=temp->next;
        }
        return dummyNode->next;

        
    }
};