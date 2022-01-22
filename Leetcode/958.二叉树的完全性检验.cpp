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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q1;
        bool flag = true;
        q1.push(root);

        while (!q1.empty()){
            int size = q1.size();
            for (int i = 0; i < size; i ++ ){
                TreeNode* mid = q1.front();
                q1.pop();
                if (mid == nullptr){
                    flag = false;
                    continue;
                }
                if (flag == false) return false;
                q1.push(mid -> left);
                q1.push(mid -> right);
            }
        }

        return true;
    }
};