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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int begin, int end) {
        if (begin > end) {
            return {nullptr};
        }
        vector<TreeNode*> res;
        for (int i = begin; i <= end; ++ i) {
            vector<TreeNode*> left = dfs(begin, i - 1), right = dfs(i + 1, end); 
            for (auto&& l: left) {
                for (auto&& r: right) {
                    TreeNode *root = new TreeNode(i, l, r);
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};