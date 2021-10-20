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
    int maxn = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int n = solve(root, 0);
        return maxn;
    }

    int solve(TreeNode* root, int floor){
        if (!root){
            return floor - 1;//如果当前的结点是空的话，那么返回的层数就应该是上一个结点的层数，所以要减一
        }
        int max1 = solve(root -> left, floor + 1);//求出左边的最深的深度；每下一层floor加一
        int max2 = solve(root -> right, floor + 1);//右边同上
        maxn = max(max1 + max2 - 2 * floor, maxn);//维护的是一个相对的全局变量：对于所有的结点，它的最大直径一定是左边的最深的深度加上右边的最深的深度减去2倍的floor
        return max(max1, max2);//因为是求深度，所以要返回左边和右边谁更深一点
    }
};