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
class TreeStatus{
    public:
        int select;
        int buselect;
};

class Solution {
public:
    int rob(TreeNode* root){
        TreeStatus res = solve(root);
        return max(res.select, res.buselect);
    }
    
    TreeStatus solve(TreeNode* root){
        if (!root){
            return {0, 0};
        }

        TreeStatus left = solve(root -> left);
        TreeStatus right = solve(root -> right);
        return {root -> val + left.buselect + right.buselect, max(left.select, left.buselect) + max(right.select, right.buselect)};
    }
};