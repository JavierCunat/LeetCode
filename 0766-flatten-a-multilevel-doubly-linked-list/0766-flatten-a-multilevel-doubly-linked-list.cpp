/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* explore(Node *curr) {
        while (curr && curr->child == nullptr) curr = curr->next;
        return curr;
    };

    Node* flatten(Node* head) {
        if(head == nullptr) return head;

        Node* curr = head;

        while(curr != nullptr) {

            if(curr->child != nullptr) {
                Node* next = curr->next;
                
                curr->next = curr->child;
                curr->child->prev = curr;

                Node* tail = curr->child;
                while(tail->next != nullptr) tail = tail->next;

                tail->next = next;
                if(next != nullptr) next->prev = tail;

                curr->child = nullptr;
            }

            curr = curr->next;
        }

        return head;
    }
};