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
    void helper(TreeNode* root, int depth, int &max_depth) {
        if (!root) {
            max_depth = (depth > max_depth) ? depth: max_depth;
            return;
        }
        
        depth += 1;
        helper(root->left, depth, max_depth);
        helper(root->right, depth, max_depth);
    }
    int maxDepth(TreeNode* root) {
	#if 0
        if (!root) return 0;
        int max_depth = INT_MIN;
        helper(root, 0, max_depth);
        return max_depth;
	#endif
	#if 1
        if (!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
        #endif
    }
};
