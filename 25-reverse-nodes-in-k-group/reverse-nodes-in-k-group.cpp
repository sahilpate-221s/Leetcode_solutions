class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return head; // not enough nodes
            node = node->next;
        }

        // Step 2: Reverse first k nodes recursively
        ListNode* newHead = reverseFirstK(head, k);

        // Step 3: head becomes tail after reverse, connect with recursion
        head->next = reverseKGroup(node, k);

        return newHead;
    }

private:
    ListNode* reverseFirstK(ListNode* head, int k) {
        if (k == 1) return head; // last node in group becomes new head
        ListNode* last = reverseFirstK(head->next, k - 1);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
