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

    ListNode* removeNodes(ListNode* head) {
        if(head==NULL)return head;
        ListNode* reversed = reverse(head);

         ListNode* curr = reversed;  // Maximum node so far
        ListNode* temp = reversed;

        while (temp && temp->next) {
            if (temp->next->val < curr->val) {
                temp->next = temp->next->next;  // Remove the smaller node
            } else {
                curr = temp->next;  // Update max node
                temp = temp->next;  // Move forward
            }
        }

        // Step 3: Reverse again to restore order
        return reverse(reversed);
        
        
    }
};