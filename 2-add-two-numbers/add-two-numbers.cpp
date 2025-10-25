class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = l1;     // Save start of l1
        ListNode* prev = nullptr;
        int carry = 0;

        // Traverse while there are digits or carry
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            int digit = sum % 10;
            carry = sum / 10;

            if (l1) {
                l1->val = digit;          // modify l1 directly
            } else {
                // l1 shorter than l2 or carry remains, extend it
                prev->next = new ListNode(digit);
                l1 = prev->next;
            }

            prev = l1;                    // move prev

            if (l1) l1 = l1->next;        // move l1 safely
            if (l2) l2 = l2->next;        // move l2 safely
        }

        return head;
    }
};
