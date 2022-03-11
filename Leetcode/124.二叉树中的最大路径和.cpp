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
    int maxn;
    int maxPathSum(TreeNode* root) {
        /**
        最近生病生的有些糊涂了，重新捋一下这道题的思路
        **/
        maxn = root -> val;
        solve(root);
        return maxn;
    }

    int solve(TreeNode* root){
        if (!root){
            return 0;
        }
        int left = max(solve(root -> left), 0);
        int right = max(solve(root -> right), 0);
        //这里改变了一下之前的想法：如果能走并且走到得到的结果是正数就要，否则比零还小的话我还不如不走！（就是因为之前没有让它返回0，导致我方向错误了好久，整个人都是懵逼的..）

        maxn = max(left + right + root -> val, maxn);
        //这里犯了一个递归上非常傻逼的错误：我一直认为要不要判断一下不走根节点，只走左子树或右子树的路径的情况，却忽略了其实之前递归的时候是遍历过这个情况的（因为我们返回的时候都是会加上root->val的），竟然还为此写了什么当root->val大于零等特例的判断，无语死了....
        //就举个例子，对于A结点的左子树和右子树来说，我当时想的是如果只走左子树或只走右子树会是什么情况呢？结果后面才醒悟过来，根本不用判断，因为在此之前，无论你走的是左子树还是右子树，都会遍历一个根节点，而遍历了根节点，就相当于有了判断
        return root -> val + max(left, right);
    }
};