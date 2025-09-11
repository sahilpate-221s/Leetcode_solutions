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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        // base case
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* l1Next = l1->next;
        ListNode* l2Next = l2->next;

        l1->next = l2;
        l2->next = merge(l1Next, l2Next);

        return l1;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        // finding the middle of the linked list
        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;

        // reverse the second List

        ListNode* reversed = reverse(slow);

        // merge the two lists the first one and the reversed one

        // merge(head, reversed);
        // using iterative word

        ListNode* first = head;
        ListNode* second = reversed;

        while (first && second) {
            ListNode* fNext = first->next;
            ListNode* sNext = second->next;

            first->next = second;
            if (fNext == nullptr)
                break; // handle odd-length lists
            second->next = fNext;

            first = fNext;
            second = sNext;
        }
    }
};