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
    int maxn{INT_MIN};
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxn;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = max(dfs(root -> left), 0);
        int right = max(dfs(root -> right), 0);
        //这里改变了一下之前的想法：如果能走并且走到得到的结果是正数就要，否则比零还小的话我还不如不走！（就是因为之前没有让它返回0，导致我方向错误了好久，整个人都是懵逼的..）

        maxn = max(left + right + root -> val, maxn);
        //这里犯了一个递归上非常傻逼的错误：我一直认为要不要判断一下不走根节点，只走左子树或右子树的路径的情况，却忽略了其实之前递归的时候是遍历过这个情况的（因为我们返回的时候都是会加上root->val的），竟然还为此写了什么当root->val大于零等特例的判断，无语死了....
        //就举个例子，对于A结点的左子树和右子树来说，我当时想的是如果只走左子树或只走右子树会是什么情况呢？结果后面才醒悟过来，根本不用判断，因为在此之前，无论你走的是左子树还是右子树，都会遍历一个根节点，而遍历了根节点，就相当于有了判断
        // maxn = max(maxn, root -> val + max(left, max(left + right, right)));
        // 这里我忽然想明白了，这样比较是有重复了，因为我下面返回的时候，是return自己左右子树中其中的一个的
        // 所以在上面这一步，只需要比较左右子树连在一起的情况即可

        return root -> val + max(left, right);
    }
};