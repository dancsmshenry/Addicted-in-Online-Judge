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
        if (!B) {
            return false;
        }
        if (!A) {
            return false;
        }

        bool flag1 = solve(A, B);
        bool flag2 = (isSubStructure(A -> left, B) || isSubStructure(A -> right, B));

        return flag1 || flag2;
    }

    bool solve(TreeNode* A, TreeNode* B) {
        if (!B) {
            return true;
        }
        if (!A) {
            return false;
        }

        if (A -> val != B -> val) {
            return false;
        }

        return solve(A -> left, B -> left) && solve(A -> right, B -> right);
    }
};