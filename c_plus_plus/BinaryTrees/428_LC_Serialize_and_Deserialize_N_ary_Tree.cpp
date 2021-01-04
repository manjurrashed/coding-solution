/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root)
            return "";
        
        string str = "";
        for (auto child : root->children) {
            str += "," + serialize(child);
        }
        return std::to_string(root->val) 
            + "," + std::to_string(root->children.size())
            + str;
    }
	
    // Decodes your encoded data to tree.
    Node* helper(char *data, char **pdata) {
        //cout << data << endl;
    
        char *buff = strtok_r(data, ",", &data);
        if (!buff) 
            return nullptr;
        
        Node *root = new Node(std::stoi(buff));
        
        buff = strtok_r(data, ",", &data);
        if (!buff) 
            return nullptr;
        
        int num = std::stoi(buff);

        for (int i = 0; i < num; i++) {
            Node *child = helper(data, &data);
            root->children.push_back(child);
        }

        *pdata = data;
        return root;
    }
    
    Node* deserialize(string data) {
        cout << data << endl;
        char *buff = data.data();
        return helper(data.data(), &buff);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
