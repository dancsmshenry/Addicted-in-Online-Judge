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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        bool flag = true;

        while (!q1.empty()) {
            int size = q1.size();
            for (int i = 0; i < size; ++ i) {
                TreeNode *mid = q1.front();
                q1.pop();
                if (!flag && mid) {
                    return false;
                }
                if (!mid) {
                    flag = false;
                } else {
                    q1.push(mid -> left);
                    q1.push(mid -> right);
                }
            }
        }

        return true;
    }
};