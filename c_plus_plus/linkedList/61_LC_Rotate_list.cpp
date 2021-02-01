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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;

        ListNode* tail = head;
        ListNode* cur = head;
        
        int n = 1;
        
        while (tail->next) tail = tail->next, n++;
        
        k = k % n;
        if (k == 0) return head;

        tail->next = head;
        cur = tail;
        k = n - k;

        while (k > 0) cur = cur->next, k--;
        
        head = cur->next;
        cur->next = nullptr;

        return head;
    }
};
