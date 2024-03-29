// 递归
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
        vector<int> res{};
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) {
            return ;
        }
        res.push_back(root -> val);
        dfs(root -> left, res);
        dfs(root -> right, res);
    }
};

//用栈模拟递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while (root || !s.empty()) {
            while (root) {
                res.push_back(root -> val);
                s.push(root);
                root = root -> left;//这里放入左节点，就相当于root先把自己（根）放入，再把左节点放入（左）
            }//此时得到的root是nullptr，即上一次放入s的节点是没有左子树了的
            root = s.top();
            s.pop();
            root = root -> right;
        }

        return res;
    }
};