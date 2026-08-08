class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp != NULL) {
                s.append(to_string(temp->val) + ",");
                q.push(temp->left);
                q.push(temp->right);
            } else {
                s.append("null,");
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "null,")
            return NULL;
            
        stringstream ss(data);
        string str;
        
        // First value = root
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            // Left child
            if (getline(ss, str, ',')) {
                if (str != "null") {
                    temp->left = new TreeNode(stoi(str));
                    q.push(temp->left);
                }
            }
            
            // Right child
            if (getline(ss, str, ',')) {
                if (str != "null") {
                    temp->right = new TreeNode(stoi(str));
                    q.push(temp->right);
                }
            }
        }
        
        return root;
    }
};