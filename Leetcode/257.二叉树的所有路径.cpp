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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        string sum = "";  
        solve(root, sum);
        return res;
    }

    void solve(TreeNode* root, string sum){
        if (!root){
            return ;
        }

        if (!root -> left && !root -> right){
            sum += to_string(root -> val);
            res.push_back(sum);
            return ;
        }

        solve(root -> left, sum + to_string(root -> val) + "->");
        solve(root -> right, sum + to_string(root -> val) + "->");
    }
};