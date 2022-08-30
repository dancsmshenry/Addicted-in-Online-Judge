// 纯暴力
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        solve(res, root, 0);

        for (int i = 1; i < res.size(); i += 2 ){
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }

    void solve(vector<vector<int>>& res, TreeNode* root, int floor){
        if (!root){
            return ;
        }
        if (floor >= res.size()) {
            vector<int> ans{root -> val};
            res.push_back(ans);
        } else {
            res[floor].push_back(root -> val);
        }
        solve(res, root -> left, floor + 1);
        solve(res, root -> right, floor + 1);
    }
};

// 层序遍历解决
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        queue<TreeNode*> q;
        if (!root) {
            return res;
        }
        q.push(root);
        int count{};

        while (!q.empty()) {
            vector<int> temp{};
            int n = q.size();
            for (int i = 0; i < n; ++ i) {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node -> val);
                if (node -> left) {
                    q.push(node -> left);
                }
                if (node -> right) {
                    q.push(node -> right);
                }
            }
            if (count % 2 == 1) {
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            ++ count;
        }

        return res;
    }
};