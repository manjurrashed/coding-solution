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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *forward = head->next;
        
        while (cur) {
            cur->next = prev;
            prev = cur;
            cur = forward;
            if (forward)
                forward = forward->next;
        }
        
        return prev;
    }
};

