//递归
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
    vector<int> f;

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return f;
    }

    void preorder(TreeNode* root){
        if (!root) return;
        f.push_back(root->val);
        preorder(root->left);
        preorder(root->right);        
    }
};

//用栈模拟递归
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s1;

        while (root != nullptr || !s1.empty()){
            while (root != nullptr){
                res.push_back(root -> val);
                s1.push(root);
                root = root -> left;//这里放入左节点，就相当于root先把自己（根）放入，再把左节点放入（左）
            }//此时得到的root是nullptr，即上一次放入s1的节点是没有左子树了的
            root = s1.top();
            s1.pop();
            root = root -> right;
        }

        return res;
    }
};