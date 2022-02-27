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
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root){
    //         return nullptr;
    //     }

    //     if (root -> val == p -> val || root -> val == q -> val){
    //         return root;
    //     }

    //     if ((search(root -> left, p) && search(root -> right, q)) || (search(root -> left, q) && search(root -> right, p))){
    //         return root;
    //     }

    //     TreeNode* node1 = lowestCommonAncestor(root -> right, p, q);

    //     return node1 == nullptr ? lowestCommonAncestor(root -> left, p, q) : node1;
    // }

    // bool search(TreeNode* root, TreeNode* p){
    //     if (!root){
    //         return false;
    //     }
    //     if (root -> val == p -> val){
    //         return true;
    //     }

    //     return search(root -> left, p) || search(root -> right, p);
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        /*
        这种做法的思路非常的巧妙：
        从一开始，对于每一个结点进入的结点来说，p和q结点一定在它本身或者左右两边（这个论证很重要）
        然后，先判断root是否为q或p结点，因为如果是的话，那这就是他们之间最近的祖先
        如果不是的话，那就证明q和p在root的子树上了
        那么，往左边找和往右边找
        这里插一句：如果当前的结点是空的话，就证明是叶子结点的下一个了
        接下来就分情况了：
        如果left不为空，right不为空，那就证明数字出现在root结点的子树中，就返回root
        如果left为空，那么right不为空，就证明数字出现在right子树中
        反之亦然
        如果left和right都不为空，那么就证明root为它的最近的公共祖先
        大前提：所有数字都是独一无二的，p和q一定存在在树里面的

        发现结点共性
        将所有考虑到的情况加入到递归里面
        优化语言
        */
        if (!root) {
            return nullptr;
        }
        if (root -> val == p -> val || root -> val == q -> val) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p ,q);
        if (left && right) {
            return root;
        }
        
        return left ? left : right;
    }
};