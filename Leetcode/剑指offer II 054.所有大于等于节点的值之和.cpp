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
private:
    int pre{};
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        convertBST(root -> right);
        root -> val += pre;
        pre = root -> val;
        convertBST(root -> left);
        return root;
    }
};