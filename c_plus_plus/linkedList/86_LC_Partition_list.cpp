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
    ListNode* partition(ListNode* head, int x) {

        ListNode* left = nullptr;
        ListNode* right = nullptr;

        ListNode* lcur = nullptr;
        ListNode* rcur = nullptr;
        
        ListNode* cur = head;
        
        while (cur) {
            if (cur->val < x) {
                if (left == nullptr) {
                    left = cur;
                    lcur = cur;
                } else {
                    lcur->next = cur;
                    lcur = lcur->next;
                }
                cur = cur->next;
                lcur->next = nullptr;
            } else {
                if (right == nullptr) {
                    right = cur;
                    rcur = cur;
                } else {
                    rcur->next = cur;
                    rcur = rcur->next;
                }
                cur = cur->next;
                rcur->next = nullptr;
            }
        }
        if (lcur)
            lcur->next = right;

        return (left) ? left : right;
    }
};
