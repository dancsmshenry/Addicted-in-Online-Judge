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
    vector<int> mid;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }

    void dfs(TreeNode *root, int target) {
        if (!root) {
            return ;
        }
        
        mid.push_back(root -> val);
        if (target == root -> val && !root -> left && !root -> right) {
            res.push_back(mid);
        } else {
            dfs(root -> left, target - root -> val);
            dfs(root -> right, target - root -> val);
        }

        mid.pop_back();
    }
};