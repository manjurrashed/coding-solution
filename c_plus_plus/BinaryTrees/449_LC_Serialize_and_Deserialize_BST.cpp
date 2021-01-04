/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>
#include <stdlib.h>

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        
        string str = to_string(root->val);
        //string str(itoa(root->val, 16));
        if (root->left) 
            str += "," + serialize(root->left);
        if (root->right) 
            str += "," + serialize(root->right);
        
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode *helper(queue<int> &q, int min, int max) {
        if (q.empty())
            return nullptr;
        
        int x = q.front();
        if (x < min || x >= max)
            return nullptr;
        

        TreeNode *root = new TreeNode(x);
        q.pop();
            
        root->left = helper(q, min, x);
        root->right = helper(q, x, max);
        return root;
        
    }
    TreeNode* deserialize(string data) {
        //cout << data << endl;

        queue<int> q;

        char *buff = std::strtok(data.data(), ",");
        if (!buff)
            return nullptr;
        while (buff) {
            q.push(std::stoi(buff));
            buff = std::strtok(nullptr, ",");
        }
        
        return helper(q, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

