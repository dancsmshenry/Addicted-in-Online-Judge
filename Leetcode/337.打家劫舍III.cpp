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
    方法一，超时了
    int rob(TreeNode* root) {
        //用常规的递归的不好的地方是，会重复了很多的步骤，浪费时间
        //有两个方向解决：第一，用记忆化数组记录每次的状态；第二，简化递归（自顶向上的思考）
        return max(solve(root, 1), solve(root, 0));
    }

    int solve(TreeNode* root, int flag){
        if (!root){
            return 0;
        }
        int left_zero = solve(root -> left, 0);
        int right_zero = solve(root -> right, 0);

        if (flag == 1){
            return root -> val + left_zero + right_zero;
        }

        return max(solve(root -> left, 1), left_zero) + max(solve(root -> right, 1), right_zero);
    }





    方法二，也超时了
    int rob(TreeNode* root) {
        return solve(root);
    }

    int solve(TreeNode* root){
        if (!root){
            return 0;
        }

        int number1 = root -> val;
        if (root -> left){
            number1 += (solve(root -> left -> right) + solve(root -> left -> left));
        }
        if (root -> right){
            number1 += (solve(root -> right -> left) + solve(root -> right -> right));
        }

        return max(number1, solve(root -> left) + solve(root -> right));
    }
};







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
class TreeStatus{
    public:
        int xuan;
        int buxuan;
};

class Solution {
public:
    int rob(TreeNode* root){
        //wc，有一个非常好的方法，记录下来：就是用一个class来记录节点的状态，这样就不用多次重复遍历了
        TreeStatus res = solve(root);
        return max(res.xuan, res.buxuan);
    }
    
    TreeStatus solve(TreeNode* root){
        if (!root){
            return {0, 0};
        }

        TreeStatus left = solve(root -> left);
        TreeStatus right = solve(root -> right);
        return {root -> val + left.buxuan + right.buxuan, max(left.xuan, left.buxuan) + max(right.xuan, right.buxuan)};
        //return这里一直出问题的原因：没有想对于不拿当前节点的情况的时候，也还是要比较xuan和buxuan的大小的，不能想当然....
    }
};