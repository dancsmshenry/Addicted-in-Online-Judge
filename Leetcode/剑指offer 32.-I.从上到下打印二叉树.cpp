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
    vector<int> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> q1;
        vector<int> res;
        q1.push(root);

        while (!q1.empty()) {
            TreeNode* mid = q1.front();
            q1.pop();
            res.push_back(mid -> val);
            if (mid -> left) {
                q1.push(mid -> left);
            }
            if (mid -> right) {
                q1.push(mid -> right);
            }
        }

        return res;
    }
};