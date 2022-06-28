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
    int result{};
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *root, int number) {
        if (root -> left == nullptr && root -> right == nullptr) {
            result += (number * 10 + root -> val);
            return ;
        }
        if (root -> left) {
            dfs(root -> left, number * 10 + root -> val);
        }
        if (root -> right) {
            dfs(root -> right, number * 10 + root -> val);
        }
    }
};