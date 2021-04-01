/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == nullptr)
            return "$";
    
        return std::to_string(root->val) 
            + "," + serialize(root->left)
            + ","  + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(char *data) {
        
        char *buff = std::strtok(data, ",");
        if (!buff || *buff == '$')
            return nullptr;
        
        int x = std::stoi(buff);
        TreeNode* root = new TreeNode(x);
    
        root->left = helper(nullptr);
        root->right = helper(nullptr);
        
        return root;
    }
    
    TreeNode* deserialize(string data) {
        //cout << data;
        return helper(data.data());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

