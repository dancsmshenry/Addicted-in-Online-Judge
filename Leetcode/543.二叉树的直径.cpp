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
    int res{};
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root -> left), right = dfs(root -> right);
        // 看到这里我更加理解了这类题了
        // 为什么res的更新只对left + right处理，乍一看，好像只针对两边连在一起的情况进行处理呢？
        // 因为啊，先说这道题，二叉树的直径最大必然不能只往一个方向走，必然要是两边连在一起的，所以red只对两边进行更新
        // 再说回来二叉树的最大路径和，因为那道题对上面left的取值做了最低的界限，即如果当前的路走到底是负数的话，那么就不走它了
        // 就设为0即可，所以就变成了这个问题了..
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};