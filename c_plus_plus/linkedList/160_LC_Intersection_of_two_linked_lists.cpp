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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        #if 0
        for (ListNode *one = headA; one != nullptr; one = one->next) {
            for (ListNode *two = headB; two != nullptr; two = two->next) {
                if (one == two)
                    return one;
            }
        }
        return nullptr;
        #endif
        #if 0
        unordered_set<ListNode *> set;
        for (ListNode *one = headA; one != nullptr; one = one->next) {
            set.insert(one);
        }
        for (ListNode *two = headB; two != nullptr; two = two->next) {
            if (set.find(two) != set.end())
                return two;
        }
        return nullptr;
        #endif
        
        #if 1
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
        #endif

    }
};
