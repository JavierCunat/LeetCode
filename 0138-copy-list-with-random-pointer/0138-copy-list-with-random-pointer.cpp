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
        if (!head) return nullptr;

        Node* curr = head;
        //create interweaved copy list (A-> A'-> B -> B')
        //set randoms to nullptr for now and then can figure out once we have copy list created
        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        //use orginal list random pointers and then just point our copy list random to that random pointer's next
        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //detach two lists keep copy
        Node* dummy = new Node(0);
        Node* currCopy = dummy;
        curr = head;

        while(curr) {
            Node* copy = curr->next;
            Node* nextOriginal = copy->next;

            currCopy->next = copy;
            currCopy = copy;

            curr->next = nextOriginal;
            curr = nextOriginal;
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};