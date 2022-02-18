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
    int pre = -1;
    int res = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return res;
    }

    void solve(TreeNode* root) {
        if (!root) {
            return ;
        }

        solve(root -> left);
        if (pre < 0) {//如果左边没有东西的话,这里要判断的是在这个点之前是否有点，而不是是否有左节点
            pre = root -> val;
        } else {
            res = min(res, abs(pre - root -> val));
            pre = root -> val;
        }
        
        solve(root -> right);
    }
};