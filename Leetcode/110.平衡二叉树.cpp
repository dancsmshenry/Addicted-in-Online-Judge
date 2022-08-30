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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        int left = search_high(root -> left), right = search_high(root -> right);

        if (abs(left - right) > 1) {
            return false;
        }

        return isBalanced(root -> left) && isBalanced(root -> right);
    }

    int search_high(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(search_high(root -> left), search_high(root -> right)) + 1;
    }
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;
    }

    int dfs(TreeNode* root) {
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