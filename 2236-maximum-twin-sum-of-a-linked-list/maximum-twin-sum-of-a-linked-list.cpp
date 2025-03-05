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
    int pairSum(ListNode* head) {
        vector<int>temp;
        ListNode* t = head;
        while(t!= NULL)
        {
            temp.push_back(t->val);
            t=t->next;
        }
        int n = temp.size();
        int maxi = -1;
        for(int i=0;i<n/2;i++)
        {
            int index = n-1-i;
            int val = temp[i] + temp[index];
            maxi = max(maxi,val);
        }

        return maxi;
        
    }
};