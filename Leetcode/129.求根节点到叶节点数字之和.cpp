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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return res;
    }

    void solve(TreeNode* root, int sum){
        if (!root){
            return ;
        }

        sum = sum * 10 + root -> val;
        if (!root -> left && !root -> right){
            res += sum;
            return;
        }

        solve(root -> left, sum);
        solve(root -> right, sum);
    }
};