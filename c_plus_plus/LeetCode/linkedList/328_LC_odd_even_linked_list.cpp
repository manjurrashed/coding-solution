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
        if (!head) return nullptr;

        ListNode dummyOdd; dummyOdd.next = head;
        ListNode dummyEven; if (head->next) dummyEven.next = head->next;
        
        ListNode *odd = &dummyOdd;
        ListNode *even = &dummyEven;
       
        ListNode *cur = head;
        int flag = 0;
        while (cur) {
            if (flag == 0) {
                odd->next = cur;
                odd = odd->next;
                cur = cur->next;
                flag = 1;
            } else {
                even->next = cur;
                even = even->next;
                cur = cur->next;
                flag = 0;
            }
        }
        
        odd->next = dummyEven.next;
        even->next = nullptr;
        
        return dummyOdd.next;
    }
};
