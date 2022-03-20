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

//层序遍历的手法
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<vector<int>> res;
        if (root) {
            q1.push(root);
        }
        int i = 0;

        while (!q1.empty()) {
            int n = q1.size();
            vector<int> mid;
            for (int j = 0; j < n; j ++ ) {
                TreeNode* root1 = q1.front();
                q1.pop();
                mid.push_back(root1 -> val);
                if (root1 -> left) {
                    q1.push(root1 -> left);
                }
                if (root1 -> right) {
                    q1.push(root1 -> right);
                }
            }
            if (i % 2 == 1) {
                reverse(mid.begin(), mid.end());
            }
            res.push_back(mid);
            i ++ ;
        }

        return res;
    }
};