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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int fatherval) {
        if (!root) {
            return 0;
        }

        if (!root -> left && !root -> right) {
            return fatherval * 10 + root -> val;
        }

        return dfs(root -> left, fatherval * 10 + root -> val) + dfs(root -> right, fatherval * 10 + root -> val);
    }
};

class Solution {
private:
    int res{};
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int count) {
        count = count * 10 + root -> val;
        if (!root -> left && !root -> right) {
            res += count;
            return ;
        }
        if (root -> left) {
            dfs(root -> left, count);
        }
        if (root -> right) {
            dfs(root -> right, count);
        }
    }
};