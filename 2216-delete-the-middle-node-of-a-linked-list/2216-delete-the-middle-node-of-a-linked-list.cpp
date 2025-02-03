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
    ListNode* deleteMiddle(ListNode* head) {
        //use one fast and one slow pointer to traverse through the linked list
        //lmao don't remember how to do that way so can just iterate through list get len and then we know the mid is len/2
        int lenOfList = 0;
        for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
            lenOfList++;
        }

        if(lenOfList == 1) return nullptr;

        ListNode* prevToDelete = nullptr;
        ListNode* toDelete = head;
        for(int i = 0; i < lenOfList/2; i++) {
            prevToDelete = toDelete;
            toDelete = toDelete->next;
        }

        //rewirte and delete mid node
        ListNode* next = toDelete->next;
        prevToDelete->next = next;
        delete toDelete;

        return head;
    }
};