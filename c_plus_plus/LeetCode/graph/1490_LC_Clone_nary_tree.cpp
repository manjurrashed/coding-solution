/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        
        queue<Node *> q;
        unordered_map<Node *, Node *> map;
        
        q.push(root);
        map[root] = new Node(root->val);
        
        while (!q.empty()) {
            Node *node = q.front(); 
            q.pop();
            Node *new_node = map[node];
            
            for (auto child : node->children) {
                if (map.find(child) == map.end()) {
                    q.push(child);
                    map[child] = new Node(child->val);
                    new_node->children.push_back(map[child]);
                } else {
                    new_node->children.push_back(map[child]);
                }
            }
        }
        
        return map[root];
    }
};
