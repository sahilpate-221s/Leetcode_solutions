class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    ListNode* removeNodes(ListNode* head) {
        if (head == NULL) return head;
        
        // Step 1: Reverse the linked list
        ListNode* reversed = reverse(head);

        // Step 2: Remove smaller nodes
        ListNode* maxNode = reversed;  // Track the maximum node encountered so far
        ListNode* temp = reversed;

        while (temp && temp->next) {
            if (temp->next->val < maxNode->val) {
                temp->next = temp->next->next;  // Remove the smaller node
            } else {
                maxNode = temp->next;  // Update max node
                temp = temp->next;  // Move forward
            }
        }

        // Step 3: Reverse again to restore original order
        return reverse(reversed);
    }
};
