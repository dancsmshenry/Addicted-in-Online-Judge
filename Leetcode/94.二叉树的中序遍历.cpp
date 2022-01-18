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

    void postorder(TreeNode* root){
        if (!root) return;
        postorder(root->left);
        f.push_back(root->val);
        postorder(root->right);        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        postorder(root);
        return f;
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
    vector<int> inorderTraversal(TreeNode* root){
        //用栈模拟递归（因为是中序遍历，左根右，所以就模拟递归的做法，一直往右边深入，然后再返回根结点和右结点）
        vector<int> res;
        stack<TreeNode*> s1;//先把所有的左节点都放入栈内，然后再逐步把节点值放入res中

        while (root != nullptr || !s1.empty()){
            while (root != nullptr){
                s1.push(root);
                root = root -> left;//一直放入左节点
            }
            root = s1.top();
            s1.pop();
            res.push_back(root -> val);
            root = root -> right;
        }

        return res;
    }
};