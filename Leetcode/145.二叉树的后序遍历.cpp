// 递归版
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res{};
        postorder(res, root);
        return res;
    }

    void postorder(vector<int>& res, TreeNode* root) {
        if (!root) {
            return ;
        }
        postorder(res, root -> left);
        postorder(res, root -> right);
        res.push_back(root -> val);
    }
};

// 非递归版（1）
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s1;
        TreeNode* prev = nullptr;

        while (root != nullptr || !s1.empty()){
            while (root != nullptr){
                s1.push(root);
                root = root -> left;
            }
            root = s1.top();
            s1.pop();
            if (root -> right == nullptr || prev == root -> right){//右边为空或右边的子树走过了，才把当前的节点放入
                res.push_back(root -> val);
                prev = root;//记录右边的这个子树走过了
                root = nullptr;
            }else{//只有当右边不为空，并且，右边的子树还没有走过
                s1.push(root -> right);
                root = root -> right;
            }
        }

        return res;
    }
};

// 非递归版（2）
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // 这种做法的思路：左右根，则反过来就是根右左
        stack<TreeNode*> s;
        vector<int> res{};
        
        while (!s.empty() || root) {
            while (root) {
                res.push_back(root -> val);
                s.push(root);
                root = root -> right;
            }
            root = s.top();
            s.pop();
            root = root -> left;
        }
        reverse(res.begin(), res.end());

        return res;
    }
};