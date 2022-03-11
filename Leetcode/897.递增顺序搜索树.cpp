】#pragma endregion/**
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
    TreeNode* res = new TreeNode(1);
    TreeNode* increasingBST(TreeNode* root) {
        //中序遍历.....
        TreeNode* result = res;
        solve(root);
        return result -> right;
    }

    void solve(TreeNode* root) {
        if (!root) return ;
        solve(root -> left);
        TreeNode* newroot = new TreeNode(root -> val);
        res -> right = newroot;
        res = res -> right;
        increasingBST(root -> right);
    }
};