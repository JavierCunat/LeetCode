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

//Reviewed on 04/07/2025
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        ListNode* dummy = head;
        ListNode* res = head;
        ListNode* originalRes = res;

        while(dummy != nullptr) {
            counter++;
            dummy = dummy->next;
        }

        int nodeIndexToRemove = counter - n;

        if(nodeIndexToRemove == 0) {
            head = head->next;
        } 
        else if(nodeIndexToRemove == 1) {
            head->next = head->next->next;
        }
        else {
            while(nodeIndexToRemove != 1) {
                nodeIndexToRemove--;
                res = res->next;
            }
            res->next = res->next->next;
            head = originalRes;
        }


    return head;
    }
};
