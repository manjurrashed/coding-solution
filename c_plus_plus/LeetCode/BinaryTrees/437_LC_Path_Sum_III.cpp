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
    void helper(TreeNode* root, int sum, int &count, unordered_map<int, int> &map, int prefix_sum) {
        if (!root) return;
        
        prefix_sum += root->val;
        if (map.find(prefix_sum - sum) != map.end()) {
            count += map[prefix_sum - sum];
        }
        map[prefix_sum]++;
        
        helper(root->left, sum, count, map, prefix_sum);
        helper(root->right, sum, count, map, prefix_sum);

        if (map[prefix_sum] == 1)
            map.erase(prefix_sum);
        else
            map[prefix_sum]--;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> map;
        int count = 0;
        map[0] = 1;
        int prefix_sum = 0;
        helper(root, sum, count, map, prefix_sum);
        return count;
    }
};
