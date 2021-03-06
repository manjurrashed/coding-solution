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
#if 0
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = head;
        
        while(cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            } else {
                if (prev->next != cur) {
                    prev->next = cur->next;
                    
                } else {
                    prev = cur;
                }
                cur = cur->next;
            }
        }
        return dummy.next;
#endif
 	ListNode dummy(0);
        dummy.next = head;
        
        ListNode *slow = &dummy;
        ListNode *fast = head;
        while (fast) {
            if (fast->next && fast->val == fast->next->val) {
                while (fast->next && fast->val == fast->next->val) {
                    ListNode *temp = fast;
                    fast = fast->next;
                    delete temp;
                }
                slow->next = fast->next;
                delete fast;
                fast = slow->next;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }
        return dummy.next;

    }
};
