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
    int pairSum(ListNode* head) {
        //hint we can reverse the arrays from the middle, now we can match up our twins, this will work since even

        //get the middle of the linked-list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse the back end of the linked list
        ListNode* curr = slow;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* backHalfReversed = prev;
        int maxSeen = INT_MIN;
        
        while(backHalfReversed != nullptr) {
            maxSeen = max(backHalfReversed->val + head->val, maxSeen);
            backHalfReversed = backHalfReversed->next;
            head = head->next;
        }

        return maxSeen;
    }
};