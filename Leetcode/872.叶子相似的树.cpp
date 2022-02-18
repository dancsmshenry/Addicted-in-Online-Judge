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
    vector<int> res;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        vector<int> r1 = res;
        res = {};
        solve(root2);

        if (r1.size() != res.size()) return false;
        for (int i = 0; i < res.size(); i ++ ) {
            if (r1[i] != res[i]) return false;
        }

        return true;
    }

    void solve(TreeNode* root) {
        if (!root) return ;
        solve(root -> left);
        if (!root -> left && !root -> right) {
            res.push_back(root -> val);
        }
        solve(root -> right);
    }
};