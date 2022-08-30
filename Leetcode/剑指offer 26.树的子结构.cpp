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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {//!B是因为如果B是空子树，那么就一定不能是任意一个树的子结构
            return false;
        }
        return dfs(A, B) || isSubStructure(A -> left, B) || isSubStructure(A -> right, B);
    }

    bool dfs(TreeNode* A, TreeNode* B) {
        if (!B) {
            return true;
        }
        if (!A) {
            return false;
        }
        if (A -> val != B -> val) {
            return false;
        }

        return dfs(A -> left, B -> left) && dfs(A -> right, B -> right);
    }
};