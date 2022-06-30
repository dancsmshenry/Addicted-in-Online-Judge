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
    int base = 0;
    TreeNode* bstToGst(TreeNode* root) {
        /*  
            对于每个节点来说，它的右子树是用来给自己赋值的，左子树是用来找到最大值返回参数的
            所以，左边能走，就加上左边的值，不能走就加上base
            这里的base可以认为是父节点给自己点的一个基数（因为先假设当前节点是左子节点，那它所有的值都是要加上这个base的，而所有的根结点都可以看作是一个节点的左子节点）
            而对于左边，如果不能走，那root->val就是该子树的max了
            否则就继续走下去，返回max
        */
        if (!root){
            return nullptr;
        }
        solve(root);
        return root;
    }

    int solve(TreeNode* root){/*这里不需要判断root是否为空*/
        if (root -> right){/*右边能走*/
            root -> val += solve(root -> right);
        }else{/*右边不能走*/
            root -> val += base;
        }

        if (root -> left){/*左边能走*/
            base = root -> val;
            return solve(root -> left);
        }

        return root -> val;/*左边不能走*/
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
class Solution {
private:
    int pre{};
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        bstToGst(root -> right);
        root -> val += pre;
        pre = root -> val;
        bstToGst(root -> left);
        
        return root;
    }
};