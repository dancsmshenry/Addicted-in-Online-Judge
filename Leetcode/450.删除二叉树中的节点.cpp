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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key > root -> val) {//往右子树找
            root -> right = deleteNode(root -> right, key);
        } else if (key < root -> val) {//往左子树找
            root -> left = deleteNode(root -> left, key);
        } else {//找到了
            //如果没有左子树，就直接返回右子树；如果没有右子树，就返回左子树
            if (!root -> left) {
                return root -> right;
            } else if (!root -> right) {
                return root -> left;
            } else {
                //如果都有，就把左子树接到右子树的最左边的节点上
                TreeNode* tmp = root -> right;
                while (tmp -> left) {
                    tmp = tmp -> left;
                }
                tmp -> left = root -> left;
                return root -> right;
            }
        }

        return root;
    }
};