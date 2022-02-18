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
    int res = INT_MAX;
    int pre = -1;
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return res;
    }

    void solve(TreeNode* root) {
        if (!root) {
            return ;
        }

        solve(root -> left);
        if (pre >= 0) {
            res = min(res, abs(pre - root -> val));
        }
        pre = root -> val;
        solve(root -> right);
    }
};