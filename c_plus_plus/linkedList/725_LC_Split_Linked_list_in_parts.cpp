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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        ListNode *cur = root;
        while (cur) cur = cur->next, n++;
        
        int d = n / k;
        int remain = n % k;
        
        if (k > n) {
            d = 1;
            remain = 0;
        }
        
        vector<ListNode*> result;

        cur = root;
        for (int i = 0; i < k; i++) {
            result.push_back(cur);
            int x = d;
            if (remain > 0) {
                remain--;
                x++;
            }
            while (cur && x > 1) {
                cur = cur->next;
                x--;
            }
            if (cur) {
                ListNode *t = cur;
                cur = cur->next;
                t->next = nullptr;
            }
            
        }
        return result;
    }
};

