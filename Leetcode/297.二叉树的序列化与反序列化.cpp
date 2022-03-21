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
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                res += "null,";
            } else {
                res += to_string(node -> val) + ',';
                q.push(node -> left);
                q.push(node -> right);
            }
        }

        return res;
    }

     // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null,") {
            return nullptr;
        }
        vector<string> v;
        queue<TreeNode*> q;
        int s = 0;
        for(int i = 0; i < data.size(); ++ i) {
            if(data[i] == ',') {
                v.push_back(data.substr(s,i - s));
                s = i + 1;
            }
        }
        TreeNode* root = new TreeNode(stoi(v[0]));
        q.push(root);
        for(int i = 1; i < v.size(); ) {
            TreeNode *t = q.front();
            q.pop();
            if (t) {
                if(v[i] != "null") {
                    t -> left = new TreeNode(stoi(v[i]));
                }
                i ++ ;
                q.push(t -> left);

                if(v[i] != "null") {
                    t -> right = new TreeNode(stoi(v[i]));
                }
                i ++ ;
                q.push(t -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));