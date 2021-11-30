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
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        /*没看到题目要求中还有负数...*/
        if (!root){
            return {};
        }
        vector<int> result;
        solve(result, root, target);
        return res;
    }

    void solve(vector<int>& result, TreeNode* root, int target){
        if (!root){
            return ;
        }

        // if (target == root -> val && !root -> left && !root -> right){
        //     result.push_back(root -> val);
        //     res.push_back(result);
        //     result.pop_back();
        // }else if (target > root -> val){
        //     result.push_back(root -> val);
        //     solve(result, root -> left, target - root -> val);
        //     solve(result, root -> right, target - root -> val);
        //     result.pop_back();
        // }

        result.push_back(root -> val);
        if (target == root -> val && !root -> left && !root -> right){
            res.push_back(result);
            result.pop_back();
            return ;
        }
        
        solve(result, root -> left, target - root -> val);
        solve(result, root -> right, target - root -> val);
        result.pop_back();
        
    }
};