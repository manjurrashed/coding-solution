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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;
        ListNode dummy;
        dummy.next = head;
        ListNode *cur = &dummy;
        while (head) {
            if (head->val == val) {
                cur->next = head->next;
                delete head;
                head = cur->next;
            } else {
                head = head->next;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
