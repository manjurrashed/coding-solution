/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int level, int &depth) {
        if (!root) return;
        if (!root->left && !root->right) {
            depth = (level < depth) ? level : depth;
            return;
        }
        helper(root->left, level + 1, depth);
        helper(root->right, level + 1, depth);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = INT_MAX;
        helper(root, 1, depth);
        return depth;
    }
};
