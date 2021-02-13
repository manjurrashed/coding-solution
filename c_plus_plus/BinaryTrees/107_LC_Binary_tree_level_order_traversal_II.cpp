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
    void helper(TreeNode* root, int level, vector<vector<int>> &result) {
        if (!root) return;
        if (level == result.size()) {
            result.push_back({root->val});
        } else {
            result[level].push_back(root->val);
        }
        helper(root->left, level + 1, result);
        helper(root->right, level + 1, result);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        helper(root, 0, result);
        std::reverse(result.begin(), result.end());
        return result;
    }
};
