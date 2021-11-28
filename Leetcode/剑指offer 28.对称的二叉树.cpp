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
    bool isSymmetric(TreeNode* root) {
        if (!root){
            return true;
        }

        return solve(root -> left, root -> right);
    }

    bool solve(TreeNode* node1, TreeNode* node2){
        /*两个都为空*/
        if (!node1 && !node2){
            return true;
        }

        /*有一个为空，另一个不为空*/
        if (!node1 || !node2){
            return false;
        }
        
        /*两个值不相等*/
        if (node1 -> val != node2 -> val){
            return false;
        }

        /*继续递归对称*/
        return solve(node1 -> left, node2 -> right) && solve(node1 -> right, node2 -> left);
    }
};