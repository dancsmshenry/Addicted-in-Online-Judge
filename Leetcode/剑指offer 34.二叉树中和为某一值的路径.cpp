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
    vector<vector<int>> res{};
    vector<int> temp{};
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }

    void dfs(TreeNode* root, int target) {
        if (!root) {
            return ;
        }

        target -= root -> val;
        temp.push_back(root -> val);
        if (!root -> left && !root -> right && target == 0) {
            res.push_back(temp);
        } else {
            dfs(root -> left, target);
            dfs(root -> right, target);
        }
        temp.pop_back();
    }
};