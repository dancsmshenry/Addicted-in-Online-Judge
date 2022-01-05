/*第一种方法非常的丑陋，有点看不下去了....*/
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
    bool isValidBST(TreeNode* root) {
        /**
        思路：暴力深搜，对于每一个点，都判断是不是其左边所有的数都小于当前的结点值，其右边的所有数都大于当前的结点值
        **/
        if (!root){
            return true;
        }
        
        if (!solve(root -> left, root -> val, true) || !solve(root -> right, root -> val, false)){
            return false;
        }

        return isValidBST(root -> left) && isValidBST(root -> right);
    }

    bool solve(TreeNode* root, int number, bool flag){//同一个搜索函数，flag==1表示往左边搜，==0表示往右边搜
        if (!root){
            return true;
        }
        if (flag){
            if (root -> val >= number){
                return false;
            }
        }else{
            if (root -> val <= number){
                return false;
            }
        }

        return solve(root -> left, number, flag) && solve(root -> right, number, flag);
    }
};

/*第二种做法，思路非常的清晰易懂（当然，用中序遍历的话，也可以把整个二叉树都先放到一个vector里面，然后再逐个比较）*/
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
    /*这种做法思路上特别的清晰，就中序遍历，左根右
    然后用一个pre来记录前面一个结点，如果当前结点小于小于等于前面结点，直接false
    而且，中序遍历保证了pre是每个结点的前一个结点（第一个结点的前面是nullptr）*/
    TreeNode* pre = nullptr; // 用来记录前一个节点
    bool isValidBST(TreeNode* root){
        if (!root){
            return true;
        }
        bool left = isValidBST(root -> left);

        if (pre != nullptr && pre -> val >= root -> val){
            return false;
        }
        pre = root; // 左子树走完了，那么当前的结点就是右子树前面的一个结点了，所以用root来更新pre

        bool right = isValidBST(root -> right);
        return left && right;
    }
};