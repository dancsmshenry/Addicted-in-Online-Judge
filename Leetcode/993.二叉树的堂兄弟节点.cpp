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
    TreeNode* root1 = nullptr;
    int deepth1 = 0;

    bool isCousins(TreeNode* root, int x, int y) {
        search(root, nullptr, x, 0);
        int deepth2 = deepth1;
        TreeNode* root2 = root1;
        search(root, nullptr, y, 0);

        if ((deepth1 != deepth2) || (root1 == root2)) return false;
        return true;
    }

    void search(TreeNode* root, TreeNode* parant, int target, int depth) {
        if (!root) return ;
        if (root -> val == target) {
            root1 = parant;
            deepth1 = depth;
            return ;
        }

        search(root -> left, root, target, depth + 1);
        search(root -> right, root, target, depth + 1);
    }
};