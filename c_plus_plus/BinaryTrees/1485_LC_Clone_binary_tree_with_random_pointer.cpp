class Solution {
public:
    NodeCopy *get_from_map(Node *root, unordered_map<Node *, NodeCopy *> &map) {
        if (!root) return nullptr;
        if (map.find(root) == map.end()) {
            map[root] = new NodeCopy(root->val);
        }
        return map[root];
    }
    NodeCopy *helper(Node *root, unordered_map<Node *, NodeCopy *> &map) {
        if (!root) return nullptr;
        NodeCopy *new_root = get_from_map(root, map);
        new_root->random = get_from_map(root->random, map);
        new_root->left = helper(root->left, map);
        new_root->right = helper(root->right, map);
        return new_root;
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node *, NodeCopy *> map;
        NodeCopy *new_root = helper(root, map);
        return new_root;
    }
};
