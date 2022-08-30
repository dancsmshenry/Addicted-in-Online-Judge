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
// 非递归写法
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        int floor{};

        while (!q.empty()) {
            ++ floor;
            int n = q.size();
            for (int i = 0; i < n; ++ i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node -> left && !node -> right) {
                    return floor;
                }
                if (node -> left) {
                    q.push(node -> left);
                }
                if (node -> right) {
                    q.push(node -> right);
                }
            }
        }

        return floor;
    }
};

// 递归写法
class Solution {
private:
    int res{INT_MAX};
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        dfs(root, 1);
        return res;
    }

    void dfs(TreeNode* root, int deepth) {
        if (!root) {
            return ;
        }
        if (!root -> left && !root -> right) {
            res = min(deepth, res);
            return ;
        }
        dfs(root -> left, deepth + 1);
        dfs(root -> right, deepth + 1);
    }
};