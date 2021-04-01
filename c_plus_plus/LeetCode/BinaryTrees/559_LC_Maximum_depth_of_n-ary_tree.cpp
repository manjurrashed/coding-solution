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
    void helper(Node* root, int depth, int &max_depth) {
        depth++;
        if (root->children.size() == 0) {
            max_depth = (depth > max_depth) ? depth : max_depth;
            return;
        }
        for (auto child : root->children) {
            helper(child, depth, max_depth);
        }
    }
    int maxDepth(Node* root) {
        if (!root) return 0;
        int max_depth = 0;
        helper(root, 0, max_depth);
        return max_depth;
    }
};
