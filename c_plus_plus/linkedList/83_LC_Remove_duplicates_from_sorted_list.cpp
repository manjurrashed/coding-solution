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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        
        ListNode *prev = &dummy;
        ListNode *cur = head;
        
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            } else {
                if (prev->next != cur) {
                    prev->next = cur;
                }
                prev = cur;
                cur = cur->next;
            }
        }
        
        return dummy.next;
    }
};
