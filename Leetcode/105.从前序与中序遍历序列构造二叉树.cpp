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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = solve(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }

    TreeNode* solve(vector<int>& pre, int pre_left, int pre_right, vector<int>& ino, int ino_left, int ino_right) {
        if (pre_left == pre_right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[pre_left]);

        int i = 0;
        while (root -> val != ino[ino_left + i]) {
            ++ i;
        }

        root -> left = solve(pre, pre_left + 1, pre_left + 1 + i, ino, ino_left, ino_left + i);
        root -> right = solve(pre, pre_left + 1 + i, pre_right, ino, ino_left + i + 1, ino_right);

        return root;
    }
};