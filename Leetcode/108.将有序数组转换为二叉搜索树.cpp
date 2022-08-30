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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    TreeNode *solve(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root -> left = solve(nums, left, mid - 1);
        root -> right = solve(nums, mid + 1, right);

        return root;
    }
};

// 另一种边界处理
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rebuild(nums, 0, nums.size());
    }

    TreeNode* rebuild(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(nums[(left + right) / 2]);
        root -> left = rebuild(nums, left, (left + right) / 2);
        root -> right = rebuild(nums, (left + right) / 2 + 1, right);

        return root;
    }
};