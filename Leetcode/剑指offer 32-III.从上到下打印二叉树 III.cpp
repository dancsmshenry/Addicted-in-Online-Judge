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
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root){
            return result;
        }
        solve(root, 1);

        for (int i = 1; i < result.size(); i += 2){
            reverse(result[i].begin(), result[i].end());
        }

        return result;
    }

    void solve(TreeNode* root, int floor){
        if (!root){
            return ;
        }

        if (result.size() < floor){
            result.push_back({});
        }

        result[floor - 1].push_back(root -> val);
        solve(root -> left, floor + 1);
        solve(root -> right, floor + 1);
    }
};

// 利用队列实现层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int count{};
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
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