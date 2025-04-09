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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        set<int>st;
        for(auto it:nums)
        {
            st.insert(it);
        }

        ListNode* dummyNode = new ListNode(-1);

        ListNode* temp = head;
        ListNode* dummyTemp= dummyNode;

        while(temp)
        {
            if(st.find(temp->val) == st.end())
            {
                dummyTemp->next = new ListNode(temp->val);
                dummyTemp=dummyTemp->next;
            }

            temp=temp->next;
        }

        return dummyNode->next;
        
    }
};