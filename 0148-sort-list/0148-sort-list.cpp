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
    ListNode* sortList(ListNode* head) {
        //use merge sort for O(n log n) average
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = findMid(head);
        ListNode* rightHalf = mid->next;
        mid->next = nullptr; //break the linked list into two

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(rightHalf);

        return merge(leftSorted, rightSorted); //merge both halves
    }

    ListNode* findMid(ListNode* head) { //use fast and slow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* sorted = &dummy;

        while(left != nullptr && right != nullptr) {
            if(left->val > right->val) {
                sorted->next = right;
                right = right->next;
            } else {
                sorted->next = left;
                left = left->next;
            }
            sorted = sorted->next;
        }

        if(left != nullptr) sorted->next = left;

        if(right != nullptr) sorted->next = right;

        return dummy.next; //return head of sorted list
    }
    
};