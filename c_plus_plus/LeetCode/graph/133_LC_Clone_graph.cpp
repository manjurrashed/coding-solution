/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node *> q;
        unordered_map<Node *, Node *> map;
        q.push(node);
        map[node] = new Node(node->val);
        
        while (!q.empty()) {
            Node *virtex = q.front();
            q.pop();
            Node *new_virtex = map[virtex];
            
            for (auto neighbor : virtex->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    q.push(neighbor);
                    map[neighbor] = new Node(neighbor->val);
                    new_virtex->neighbors.push_back(map[neighbor]);
                } else {
                    new_virtex->neighbors.push_back(map[neighbor]);
                }
            }
        }
        
        return map[node];
    }
};
