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
    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        TreeNode *root = new TreeNode(preorder[left]);
        int mid = left + 1;
        while (mid <= right && preorder[left] > preorder[mid]) {
            mid++;
        }
        root->left = helper(preorder, left + 1, mid - 1);
        root->right = helper(preorder, mid, right);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (!preorder.size()) return nullptr;
        TreeNode *root = helper(preorder, 0, preorder.size() - 1);
        return root;
    }
};
