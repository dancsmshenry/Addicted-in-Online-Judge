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
        vector<int> f;
        postorder(root, f);
        return f;
    }

    void postorder(TreeNode* root, vector<int>& f) {
        if (!root) return;
        postorder(root -> left);
        postorder(root -> right); 
        f.push_back(root -> val);       
    }
};

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
        vector<int> res;
        stack<TreeNode*> s1;
        if (!root) {
            return res;
        }

        while (!s1.empty() || root) {
            while (root) {
                res.push_back(root -> val);
                s1.push(root);
                root = root -> right;
            }
            root = s1.top();
            s1.pop();
            root = root -> left;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};