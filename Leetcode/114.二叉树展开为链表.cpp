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
        //这道题思路一下子就有了，但是代码功夫不行，导致耽搁了好久.....
        if (!root){
            return ;
        }
        flatten(root -> left);//把左子树变为链表
        flatten(root -> right);//把右子树变为链表

        TreeNode* noderight = root -> right;//记录下右子树的数据和左子树的数据
        TreeNode* nodeleft = root -> left;
        root -> left = nullptr;//令左子树为nullptr
        root -> right = nodeleft;//令右子树先变为左子树

        //想办法让原来的左子树变为右子树
        TreeNode* node = root;
        while (node -> right){
            node = node -> right;
        }
        node -> right = noderight;
    }
};