/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root){
            return result;
        }
        solve(root, 1);

        for (int i = 1; i < result.size(); i += 2){
            reverse(result[i].begin(), result[i].end());
        }

        return result;
    }

    void solve(TreeNode* root, int floor){
        if (!root){
            return ;
        }

        if (result.size() < floor){
            result.push_back({});
        }

        result[floor - 1].push_back(root -> val);
        solve(root -> left, floor + 1);
        solve(root -> right, floor + 1);
    }
};