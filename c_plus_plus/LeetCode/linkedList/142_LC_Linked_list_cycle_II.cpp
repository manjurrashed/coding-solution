/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        #if 0
        unordered_set<ListNode *> set;
        while (head) {
            if (set.find(head) != set.end())
                return head;
            set.insert(head);
            head = head->next;
        }
        return nullptr;
        #endif
        #if 1
        if (!head) return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
        #endif
    }
};
