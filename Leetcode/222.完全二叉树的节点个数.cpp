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
    /*
        思路：
        完全二叉树的一个性质是：所有的叶子节点都在最下面的那一层，同时节点是从左往右排列的
        所以就有了这样一个思路：
        （这段推理非常的精华，看完就理解二叉树递归的本质了，其实就是找到性质相同的子问题，然后用同一个函数不断的去求解）
        
        对于左子树和右子树来说，如果左子树和右子树的高度是相同的
        那就证明左子树的最后一层肯定是被叶子节点铺满的，但是右子树可能是没有被节点铺满的（也有可能被完全铺满）
            就将结果先加上左子树的结点数，然后再来看右子树的节点情况
        
        如果左子树的高度不等于右子树，那么必然是左子树最下面的叶子节点比右子树的叶子节点还要深入一层
        即在最后一行，左子树有节点，而右子树没有节点
            就将结果先加上右子树的结点数，然后再来看左子树的节点情况
    */
    int countNodes(TreeNode* root) {
        if (!root){
            return 0;
        }
        int left = search(root -> left);
        int right = search(root -> right);

        if (left == right){
            return countNodes(root -> right) + (1 << left);
        }

        return countNodes(root -> left) + (1 << right);
    }

    int search(TreeNode* root){
        int total = 0;

        for (; root != nullptr; root = root -> left, total ++ )
            ;

        return total;
    }

    /*dfs*/
    int solve(TreeNode* root){
        if (!root){
            return 0;
        }
        return solve(root -> left) + 1 + solve(root -> right);
    }
};