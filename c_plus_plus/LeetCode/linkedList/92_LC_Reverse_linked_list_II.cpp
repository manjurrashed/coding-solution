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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *forward = head->next;
        //https://www.youtube.com/watch?v=BE0hruM5O5U
        // keep prev and cur fixed, removed forward node, move forward to the next.
        
        while (n > 1) {
            if (m > 1) {
                prev = cur;
                cur = cur->next;
                forward = forward->next;
                m--;
            } else {
                ListNode *node = forward;
                forward = forward->next;

                cur->next = node->next;
                if (prev) {
                    node->next = prev->next;
                    prev->next = node;
                } else {
                    node->next = head;
                    head = node;
                }
            }
            n--;
        }
        return head;
    }
};

