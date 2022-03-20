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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        root -> val = 1;
        if (root) {
            q.push(root);
        }
        int ans = 0;

        while(!q.empty()) {
            ans = max(q.back()->val - q.front()->val + 1, ans);
            int tmp = q.front()->val - 1;

            for(int i = q.size(); i > 0; -- i) {
                auto p = q.front(); 
                q.pop();
                p->val -= tmp;
                if(p->left) {
                    p -> left -> val = 2 * p -> val;
                    q.push(p -> left); 
                }
                if(p->right) {
                    p -> right -> val = 2 * p -> val + 1;
                    q.push(p -> right);
                }
            }
        }

        return ans;
    }
};