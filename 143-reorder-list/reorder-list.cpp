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
        if(!head || !head->next)return head;

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return ;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow=slow->next;
        }
        prev->next = NULL;


        // 1 -> 2-> X       5-> 4-> 3->X 
        ListNode* reversed = reverse(slow);

        ListNode* curr = head;
        ListNode* temp = reversed;

        ListNode* currNext;
        ListNode* tempNext;
        while(curr && temp)
        {
            currNext = curr->next;
            tempNext = temp->next;

            curr->next = temp;
            if(currNext == NULL)break;
            temp->next = currNext;
            
            curr=currNext;
            temp=tempNext;
        }
        
    }
};