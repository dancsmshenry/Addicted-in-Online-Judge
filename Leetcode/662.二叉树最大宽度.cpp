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

struct Node {
    TreeNode *node;
    unsigned long long val;
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<Node> q;
        q.push({root, 0});
        unsigned long long res{1};

        while (!q.empty()) {
            res = max(res, q.back().val - q.front().val + 1);
            for (int i = q.size(); i > 0; -- i) {
                Node mid = q.front();
                q.pop();
                if (mid.node -> left) {
                    q.push({mid.node -> left, mid.val * 2});
                }
                if (mid.node -> right) {
                    q.push({mid.node -> right, mid.val * 2 + 1});
                }
            }
        }

        return res;
    }
};