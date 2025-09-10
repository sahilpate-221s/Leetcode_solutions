/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;

        // first step1 -> insert new node in between two nodes

        Node* curr = head;
        Node* currNext = NULL;

        while (curr) {
            currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;
            curr = currNext;
        }

        curr = head;
        // step2 : marking the random pointers in the new nodes
        while (curr) {
            if (curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random =
                    curr->random
                        ->next; // ye random ->next iss liye ki curr->random
                                // original list hai aur uska next jo naya node
                                // humne banaya hai wo hai iss liye ye banaya
            }
            curr = curr->next->next;
        }

        // step 3 : remove the old nodes from the new one and return the new
        // nodes

        Node* newHead = head->next;
        curr = head;

        Node* newNode = head->next;

        while (curr && newNode) {
            curr->next = curr->next == NULL ? NULL : curr->next->next;
            newNode->next = newNode->next == NULL ? NULL : newNode->next->next;

            curr = curr->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};