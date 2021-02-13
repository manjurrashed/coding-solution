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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> result;
        vector<int> level;

        if (root) q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            while(size--) {
                Node *node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto child : node->children) {
                    q.push(child);
                }
            }
            result.push_back(level);
            level.clear();
        }
        
        return result;
    }
};
