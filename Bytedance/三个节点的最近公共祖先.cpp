/**
 * 求三个节点的公共祖先
 * 
*/

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int value) : left(nullptr), right(nullptr), val(value) {}
    TreeNode(int value, TreeNode *l, TreeNode *r) : left(l), right(r), val(value) {}
    TreeNode(): left(nullptr), right(nullptr) , val(0){}
};

class Solution {
    TreeNode* threejiedianzuxian(TreeNode *root, TreeNode *r1, TreeNode *r2, TreeNode *r3) {
        TreeNode *r4 = find(root, r1, r2);
        return find(root, r4, r3);
    }

    TreeNode* find(TreeNode *root, TreeNode *r1, TreeNode *r2) {
        if (!root || r1 == root || r2 == root) {
            return root;
        }

        TreeNode *l = find(root -> left, r1, r2);
        TreeNode *r = find(root -> right, r1, r2);

        if (!l) {
            return r;
        } else if (!r) {
            return l;
        }

        return root;
    }

    
};