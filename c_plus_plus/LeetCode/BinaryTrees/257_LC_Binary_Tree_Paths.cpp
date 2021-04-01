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
    void helper(TreeNode* root, string path,  vector<string> &result) {
        if (!root) return;
        if (!root->left && !root->right) {
            path += std::to_string(root->val);
            result.push_back(path);
            return;
        }
        path += std::to_string(root->val) + "->";
        helper(root->left, path, result);
        helper(root->right, path, result);


    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        
        helper(root, path, result);
        
        return result;
    }
};
