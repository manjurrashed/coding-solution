/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        Node *cur = head;
        Node *prev = nullptr;
        
        while(cur) {
            prev = cur;
            cur = cur->next;
            
            prev->next = new Node(prev->val);
            prev->next->next = cur;
        }
        
        cur = head;
        while (cur) {
            cur->next->random = (cur->random) ? cur->random->next : nullptr;
            cur = cur->next->next;
        }
        
        
        Node *newHead = head->next;
        
        prev = head;
        cur = head->next;
        
        while (cur->next) {
            prev->next = prev->next->next;
            prev = prev->next;
            
            cur->next = cur->next->next;
            cur = cur->next;
        }
        prev->next = nullptr;

        return newHead;
    }
};
