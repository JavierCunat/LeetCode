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
    ListNode* oddEvenList(ListNode* head) {
        //grab evens and make that a list, rewire to not include evens and append this list to the end
        if(head == nullptr) return nullptr;

        //one pointer to start at the evens
        ListNode* evens = head->next;
        ListNode* evenshead = evens;
        ListNode* curr = head;
        while(evens != nullptr && evens->next != nullptr) {
            curr->next = curr->next->next;
            evens->next = evens->next->next;
            curr = curr->next;
            evens = evens->next;
        }

        curr->next = evenshead;
        return head;
    }
};