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
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp{};
        dfs(root, temp, targetSum);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& temp, int targetSum) {
        if (!root) {
            return ;
        }
        temp.push_back(root -> val);
        if (targetSum == root -> val && !root -> left && !root -> right) {
            res.push_back(temp); // 注意，即使是在把temp放入到res中后，最后也还是要pop_back的
        } else {
            dfs(root -> left, temp, targetSum - root -> val);
            dfs(root -> right, temp, targetSum - root -> val);
        }
        temp.pop_back();
    }
};