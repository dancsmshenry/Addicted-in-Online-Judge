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
    void flatten(TreeNode* root) {
        if (!root) {
            return ;
        }
        flatten(root -> left);
        flatten(root -> right);
        TreeNode *temp = root -> right;
        root -> right = root -> left;
        root -> left = nullptr;
        while (root -> right) {
            root = root -> right;
        }
        root -> right = temp;
    }
};

// 改为要求中序遍历的写法
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return ;
        }
        flatten(root -> left);
        flatten(root -> right);
        TreeNode *left = root -> left, *mid = new TreeNode(root -> val, nullptr, root -> right);
        if (!left) {
            *root = *mid;
            return ;
        }
        *root = *left;
        while (root -> right) {
            root = root -> right;
        }
        root -> right = mid;
    }

};

// 改为要求后序遍历的写法
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return ;
        }
        flatten(root -> left);
        flatten(root -> right);
        TreeNode *left = root -> left, *right = root -> right, *mid = new TreeNode(root -> val);
        if (!left) {
            if (!right) return ;
            *root = *right;
            while (root -> right) {
                root = root -> right;
            }
            root -> right = mid;
        } else {
            *root = *left;
            while (root -> right) {
                root = root -> right;
            }
            if (!right) {
                root -> right = mid;
            } else {
                root -> right = right;
                while (root -> right) {
                    root = root -> right;
                }
                root -> right = mid;
            }
        }
    }
};