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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(postorder, inorder, 0, postorder.size(), 0, inorder.size());
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int postorder_begin, int postorder_end, int inorder_begin, int inorder_end){
        //因为我设计的算法中，最后一个数是用不到的，是取不到的，所以，如果两个边界相等，就直接返回nullptr
        if (postorder_begin == postorder_end){
            return nullptr;
        }
        //后序遍历的最后一个数是根节点
        TreeNode* root = new TreeNode(postorder[postorder_end - 1]);
        
        //在中序遍历中找根节点，坐标为i的地方是根节点
        int i = 0;
        while (inorder[inorder_begin + i] != root -> val){
            i ++ ;
        }
        
        //对于左子树来说，在后续遍历应该是从begin到begin+i（注意，这里的最后一个数是用不到的，所以直接取到i）
        //而在中序遍历中，左子树是从begin到begin+i（取到i的原因同上）
        root -> left = solve(postorder, inorder, postorder_begin, postorder_begin + i, inorder_begin, inorder_begin + i);
        //对于右子树来说，在后续遍历中应该是begin+i到end-1（因为上面遍历的时候begin+i没用到，并且end-1是当前的根节点，而这里的最后一个数是用不到的）
        //而在中序遍历中，右子树是从begin+i+1到end（因为begin+i是当前的根节点）
        root -> right = solve(postorder, inorder, postorder_begin + i, postorder_end - 1, inorder_begin + i + 1, inorder_end);

        return root;
    }
};