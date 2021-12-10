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
    // int result = 0;
    // int sumOfLeftLeaves(TreeNode* root) {
    //     solve(root, 0);
    //     return result;
    // }

    // void solve(TreeNode* root, int flag){
    //     if (!root){
    //         return ;
    //     }
    //     if (!root -> left && !root -> right && flag == 1){
    //         result += root -> val;
    //     }
    //     solve(root -> left, 1);
    //     solve(root -> right, 0);
    // }


    // int result = 0;
    // int sumOfLeftLeaves(TreeNode* root){
    //     if (!root){
    //         return 0;
    //     }
    //     solve(root -> left);
    //     sumOfLeftLeaves(root -> left);
    //     sumOfLeftLeaves(root -> right);
    //     return result;
    // }

    // void solve(TreeNode* root){
    //     if (!root){
    //         return ;
    //     }
    //     if (!root -> left && !root -> right){
    //         result += root -> val;
    //     }
    // }

    int sumOfLeftLeaves(TreeNode* root){
        if (!root){
            return 0;
        }
        return solve(root -> left) + sumOfLeftLeaves(root -> left) + sumOfLeftLeaves(root -> right);
    }

    int solve(TreeNode* root){
        if (!root){
            return 0;
        }
        if (!root -> left && !root -> right){
            return root -> val;
        }
        return 0;
    }
};