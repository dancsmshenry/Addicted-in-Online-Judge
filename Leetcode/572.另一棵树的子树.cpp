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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        bool flag = check(root, subRoot);

        return flag || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

    bool check(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (!root || !subRoot) {//两者只要有一个是空的，就返回false
            return false;
        }

        if (root -> val != subRoot -> val) {
            return false;
        }

        return check(root -> left, subRoot -> left) && check(root -> right, subRoot -> right);
    }
};