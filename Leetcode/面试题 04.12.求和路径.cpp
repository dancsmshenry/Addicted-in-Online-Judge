/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int result = 0;
    int sumn = 0;

    int pathSum(TreeNode* root, int sum) {
        /*
            这里的问题是，一开始，我想不到如何模拟中途选择节点的情况（即不从起始节点出发，而是从中间任意一个节点出发）
            后面经过调试以后发现，应该是可以对每一个点做一次完全遍历，以该点作为起始节点看是否有符合的情况
        */
        sumn = sum;
        solve(root);
        return result;
    }

    void solve1(TreeNode* root, int sum){
        if (!root){
            return ;
        }

        if (sum == root -> val){
            result ++ ;
        }

        solve1(root -> left, sum - root -> val);
        solve1(root -> right, sum - root -> val);
    }

    void solve(TreeNode* root){
        if (!root){
            return ;
        }
        solve1(root, sumn);
        solve(root -> left);
        solve(root -> right);
    }
};