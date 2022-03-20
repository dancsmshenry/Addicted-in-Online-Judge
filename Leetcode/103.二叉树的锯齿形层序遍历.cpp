//纯暴力
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

//层序遍历解决
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
        //同样可以用层序遍历来解决
        queue<TreeNode*> q1;
        vector<vector<int>> result;
        int deep = 0;
        if (root){
            q1.push(root);
        }

        while (!q1.empty()){
            int size = q1.size();
            vector<int> res;
            for (int i = 0; i < size; i ++ ){
                TreeNode* mid = q1.front();
                q1.pop();
                res.push_back(mid -> val);
                if (mid -> left){
                    q1.push(mid -> left);
                }
                if (mid -> right){
                    q1.push(mid -> right);
                }
            }
            if (deep % 2 == 1){
                reverse(res.begin(), res.end());
            }
            result.push_back(res);
            deep ++ ;
        }

        return result;
    }
};