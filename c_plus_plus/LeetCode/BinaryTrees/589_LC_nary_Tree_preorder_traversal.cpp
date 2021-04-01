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
    void helper(Node* root, vector<int> &result) {
        result.push_back(root->val);
        if (root->children.size() == 0) return;
        for (auto child : root->children) {
            helper(child, result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        helper(root, result);
        return result;
    }
};
