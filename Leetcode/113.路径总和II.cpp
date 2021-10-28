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
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec; 
        solve(root, targetSum, vec);
        return result;
    }

    void solve(TreeNode* root, int targetSum, vector<int>& vec){
        if (!root){
            return ;
        }

        vec.push_back(root -> val);
        if (targetSum == root -> val && !root -> right && !root -> left){
            result.push_back(vec);
        }

        solve(root -> left, targetSum - root -> val, vec);
        solve(root -> right, targetSum - root -> val, vec);
        vec.pop_back();
    }
};