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
    void helper(Node *root, int level, vector<vector<int>> &result) {
        if (!root) return;
        if (level == result.size()) {
            result.push_back({root->val});
        } else {
            result[level].push_back(root->val);
        }
        for (auto child : root->children) 
            helper(child, level + 1, result);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        helper(root, 0, result);
        return result;
    }
};
