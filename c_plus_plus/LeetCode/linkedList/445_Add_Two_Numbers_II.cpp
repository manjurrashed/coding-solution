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
    ListNode* reverse_list(ListNode* l) {
        ListNode* prev = nullptr;
        while (l) {
            ListNode* temp = l->next;
            l->next = prev;
            prev = l;
            l = temp;
        }
        return prev;
    }
    ListNode* sum_list(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *cur = &dummy;
        int carry = 0;
        while (carry || l1 || l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode;
            cur = cur->next;
            cur->val = (carry > 9) ? (carry - 10) : carry;
            carry = (carry > 9) ? 1 : 0;
        }
        
        return dummy.next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse_list(l1);
        l2 = reverse_list(l2);
        return reverse_list(sum_list(l1, l2));
    }
};

