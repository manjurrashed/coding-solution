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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummy_odd;
        ListNode dummy_even;
        ListNode *odd = &dummy_odd;
        ListNode *even = &dummy_even;
        int flag = 1;
        
        while (head) {
            if (flag) {
                odd->next = head;
                odd = odd->next;
                flag = 0;
            } else {
                even->next = head;
                even = even->next;
                flag = 1;
            }
            head = head->next;
        }
        even->next = nullptr;

        odd->next = dummy_even.next;
        return dummy_odd.next;
    }
};

