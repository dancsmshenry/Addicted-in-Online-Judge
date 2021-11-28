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
    vector<int> result;
    vector<int> levelOrder(TreeNode* root) {
        vector<TreeNode*> v1{root};
        solve(v1);
        return result;
    }

    /*利用结点的不断裂变，把裂变的放入数组当中*/
    void solve(vector<TreeNode*>& mid){
        /*如果所有的结点都是空的，就设为false，就后续直接返回*/
        bool flag = false;
        for (TreeNode* i:mid){
            if (i){
                result.push_back(i -> val);
                flag = true;
            }
        }
        if (!flag){
            return ;
        }
        vector<TreeNode*> res;
        for (TreeNode* i:mid){
            if (i -> left){
                res.push_back(i -> left);
            }
            if (i -> right){
                res.push_back(i -> right);
            }
        }
        solve(res);
    }
};