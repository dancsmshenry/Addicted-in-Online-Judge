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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root){
            return 0;
        }

        int result = solve(root, targetSum);
        result += pathSum(root -> left, targetSum);
        result += pathSum(root -> right, targetSum);
        return result;
    }

    int solve(TreeNode* root, int targetSum){
        if (!root){
            return 0;
        }
        int result = 0;
        if (root -> val == targetSum){
            result ++ ;//之前是这里直接return了，导致忽略了一些情况/
        }
        result += solve(root -> left, targetSum - root -> val);
        result += solve(root -> right, targetSum - root -> val);
        return result;
    }
};