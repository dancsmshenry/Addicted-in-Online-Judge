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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    TreeNode* solve(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nums[left + (right - left) / 2]);
        root -> left = solve(nums, left, left + (right - left) / 2 - 1);
        root -> right = solve(nums, left + (right - left) / 2 + 1, right);

        return root;
    }
};