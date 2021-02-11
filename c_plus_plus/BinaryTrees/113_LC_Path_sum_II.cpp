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
    void helper(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &result) {
        if (!root) return;

        if (!root->left && !root->right && sum == root->val) {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        helper(root->left, sum - root->val, path, result);
        helper(root->right, sum - root->val, path, result);
        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;

        vector<int> path;

        helper(root, targetSum, path, result);
        
        return result;
    }
};
