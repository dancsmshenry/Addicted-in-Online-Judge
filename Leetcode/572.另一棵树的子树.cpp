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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (check(root, subRoot)) {//以当前节点作为根节点
            return true;
        }

        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

    bool check(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;//两个节点都是nullptr
        if (!root || !subRoot) return false;//对子树的理解有点误解了...
        
        if (root -> val != subRoot -> val) return false;
        return check(root -> left, subRoot -> left) && check(root -> right, subRoot -> right);
    }
};