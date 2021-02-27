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
    ListNode *head;
    int size = 0;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand(time(NULL));
        this->head = head;
        while (head) {
            size++;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if (!head) return 0;
        int x = rand() % size;
        ListNode *cur = head;
        cout << x << endl;
        while (x && cur) {
            cur = cur->next;
            x--;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
