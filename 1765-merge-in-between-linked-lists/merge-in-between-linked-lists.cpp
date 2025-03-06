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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list1;
        ListNode* prev = NULL;
        for(int i=0;i<a;i++)
        {
            prev = first;
            first=first->next;
        }

        for(int i=0;i<b;i++)
        {
            second = second->next;
        }
        ListNode* secondTemp = second->next;

        ListNode* list = list2;
        while(list->next != NULL)
        {
            list=list->next;
        }
        
        prev->next = list2;
        list->next = secondTemp;

        return list1;
        
    }
};