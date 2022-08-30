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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode *left = mirrorTree(root -> right);
        root -> right = mirrorTree(root -> left);
        root -> left = left;

        return root;
    }
};