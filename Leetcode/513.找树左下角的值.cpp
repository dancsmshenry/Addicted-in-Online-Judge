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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> d1;
        d1.push(root);
        int target = 0;

        while (!d1.empty()) {
            int n = d1.size();
            for (int i = 0; i < n; i ++ ) {
                if (i == 0) {
                    target = d1.front() -> val;
                }
                if (d1.front() -> left) {
                    d1.push(d1.front() -> left);
                }
                if (d1.front() -> right) {
                    d1.push(d1.front() -> right);
                }
                d1.pop();
            }
        }

        return target;
    }
};