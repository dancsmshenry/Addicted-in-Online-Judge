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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> mid;
        dfs(res, mid, root, targetSum);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& mid, TreeNode *root, int targetSum) {
        if (!root) {
            return ;
        }
        
        mid.push_back(root -> val);
        if (targetSum == root -> val && !root -> left && !root -> right) {
            res.push_back(mid);
        } else {
            dfs(res, mid, root -> left, targetSum - root -> val);
            dfs(res, mid, root -> right, targetSum - root -> val);
        }

        mid.pop_back();
    }
};