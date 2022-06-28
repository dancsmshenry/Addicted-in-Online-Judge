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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        if (dfs(root) == false) {
            return nullptr;
        }
        root -> left = pruneTree(root -> left);
        root -> right = pruneTree(root -> right);

        return root;
    }

    bool dfs(TreeNode* root) {
        if (!root) {
            return false;
        }
        if (root -> val == 0 && dfs(root -> left) == false && dfs(root -> right) == false) {
            return false;
        }
        return true;
    }
};

// 正确的做法
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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode *left = pruneTree(root -> left), *right = pruneTree(root -> right);
        if (root -> val == 0 && left == nullptr && right == nullptr) {
            return nullptr;
        }
        root -> left = left;
        root -> right = right;
        return root;
    }
};