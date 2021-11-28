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
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*思考了一下，发现其实吧，二叉树也是前中后序遍历+递归组成的题目*/
        solve(root, 1);
        return res;
    }

    void solve(TreeNode* root, int floor){
        if (!root){
            return ;
        }
        if (res.size() < floor){
            vector<int> mid;
            mid.push_back(root -> val);
            res.push_back(mid);
        }else{
            res[floor - 1].push_back(root -> val);
        }
        solve(root -> left, floor + 1);
        solve(root -> right, floor + 1);
    }
};