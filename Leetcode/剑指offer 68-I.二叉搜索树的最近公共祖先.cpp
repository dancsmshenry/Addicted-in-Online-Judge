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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*如果是一般的树，就要每个结点都去检查一遍，从而找到最近的公共祖先
        而这是二叉搜索树，所以可以不用这样，通过值的判断来找两边即可*/
        if (!root){
            return nullptr;
        }

        if (root -> val > p -> val && root -> val > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }else if (root -> val < p -> val && root -> val < q -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }

        return root;
    }
};