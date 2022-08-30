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
private:
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return res;
    }

    void dfs(TreeNode* root, string temp) {
        if (!root) {
            return ;
        }

        temp += to_string(root -> val);
        if (!root -> left && !root -> right) {
            res.push_back(temp);
        } else {
            dfs(root -> left, temp + "->");
            dfs(root -> right, temp + "->");
        }
    }
};