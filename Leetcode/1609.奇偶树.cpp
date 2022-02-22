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
    bool isEvenOddTree(TreeNode* root) {
        int floor = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            int pre = floor % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < n; ++ i ) {
                TreeNode* node = q.front();
                q.pop();
                if ((node -> val % 2) == (floor % 2)) {
                    return false;
                }
                if ((floor % 2 == 0 && node -> val <= pre) || (floor % 2 == 1 && node -> val >= pre)) return false;//没读清题目.....
                pre = node -> val;
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            floor ++ ;
        }

        return true;
    }
};