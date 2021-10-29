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
    vector<int> res;
    
    vector<int> largestValues(TreeNode* root) {
        solve(root, 1);
        return res;
    }

    void solve(TreeNode* root, int floor){
        if (!root){
            return ;
        }

        if (floor > res.size()){
            res.push_back(root -> val);
        }else{
            res[floor - 1] = max(res[floor - 1], root -> val);
        }

        solve(root -> left, floor + 1);
        solve(root -> right, floor + 1);
    }
};