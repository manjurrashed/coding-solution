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
    ListNode *getMidNode(ListNode *fast) {
        ListNode *slow = fast;
        while (fast) {
            fast = (fast && fast->next) ? fast->next->next : nullptr;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *cur) {
        if (!cur)
            return nullptr;
        
        ListNode *prev = nullptr;
        ListNode *fwd = cur->next;
        
        while (cur) {
            cur->next = prev;
            prev = cur;
            cur = fwd;
            fwd = (fwd) ? fwd->next : nullptr;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid_node = getMidNode(head);
        ListNode *rev = reverse(mid_node);
        
        while (rev) {
            if (rev->val != head->val) {
                return false;
            }
            rev = rev->next;
            head = head->next;
        }
        
        return true;
    }
};

