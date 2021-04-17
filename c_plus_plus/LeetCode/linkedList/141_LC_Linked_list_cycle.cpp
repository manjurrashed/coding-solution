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
    bool hasCycle(ListNode *head) {
        #if 0
        //time : O(n), space : O(n)
        unordered_set<ListNode *> set;
        while (head) {
            if (set.find(head) != set.end())
                return true;
            set.insert(head);
            head = head->next;
        }
        return false;
        #endif
        #if 1
        // Time O(n), Space O(1)
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
        #endif
    }
};

