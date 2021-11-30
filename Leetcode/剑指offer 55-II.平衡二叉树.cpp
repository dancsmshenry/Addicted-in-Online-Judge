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
        if (!root){
            return true;
        }

        if (abs(deepth(root -> left, 0) - deepth(root -> right, 0)) >= 2){
            return false;
        }

        return isBalanced(root -> left) && isBalanced(root -> right);
    }

    int deepth(TreeNode* root, int count){
        if (!root){
            return count;
        }
        return max(deepth(root -> left, count + 1), deepth(root -> right, count + 1));
    }
};