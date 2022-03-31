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
    bool isBalanced(TreeNode* root) {
        return dfs(root) == -1 ? false : true;
    }

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = dfs(root -> left);
        int right = dfs(root -> right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    }
};