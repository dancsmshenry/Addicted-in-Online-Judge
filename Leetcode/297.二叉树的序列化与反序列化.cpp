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
    void rserialize(TreeNode* root, string& str) {
        //先序遍历
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode* root) {
        //对二叉树进行先序遍历的处理
        string ret;
        rserialize(root, ret);
        return ret;
    }

    //完全不明白它是如何通过先序遍历推出原来的二叉树的...
    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        
        return root;
    }

    TreeNode* deserialize(string data) {
        //list为双向链表
        list<string> dataArray;
        string str;

        //把所有的结点的值都放入list（去掉其中的逗号）
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        //最后还会有数字字符留在str中，要把它加上去
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }

        return rdeserialize(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));