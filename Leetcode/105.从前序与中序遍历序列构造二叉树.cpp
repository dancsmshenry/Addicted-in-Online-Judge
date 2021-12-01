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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*原来只要跟着之前的边界来改就行了，费太多时间了......*/
        return solve(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preorder_begin, int preorder_end, int inorder_begin, int inorder_end){
        if (preorder_begin == preorder_end){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorder_begin]);
        
        int i = 0;
        while (inorder[inorder_begin + i] != root -> val){
            i ++ ;
        }
        
        root -> left = solve(preorder, inorder, preorder_begin + 1, preorder_begin + i + 1, inorder_begin, inorder_begin + i);
        root -> right = solve(preorder, inorder, preorder_begin + i + 1, preorder_end, inorder_begin + i + 1, inorder_end);

        return root;
    }
};