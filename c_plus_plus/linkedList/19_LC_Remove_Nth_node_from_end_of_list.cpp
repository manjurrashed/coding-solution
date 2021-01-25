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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;

        ListNode *left = &dummy;
        ListNode *right = head;
        
        while (right) {
            if (n == 0) {
                left = left->next;
            }
            if (n > 0) n--;
            right = right->next;
        }

        if (left->next) {
            ListNode *p = left->next;
            left->next = left->next->next;
            delete p;
        }

        return dummy.next;
    }
};
