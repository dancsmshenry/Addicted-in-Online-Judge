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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q1;
        int floor = 0;
        if (root) {
            q1.push(root);
        }

        while (!q1.empty()) {
            int size = q1.size();
            for (int i = 0; i < size; ++ i) {
                TreeNode *mid = q1.front();
                q1.pop();
                if (!mid -> left && !mid -> right) {
                    return floor + 1;
                }
                if (mid -> left) {
                    q1.push(mid -> left);
                }
                if (mid -> right) {
                    q1.push(mid -> right);
                }
            }
            ++ floor;
        }

        return floor;
    }
};