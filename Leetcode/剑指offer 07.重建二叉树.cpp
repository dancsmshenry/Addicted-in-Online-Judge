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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*忘记有空的树了...*/
        if (preorder.size() == 0){
            return nullptr;
        }
        /*将前序遍历的第一个点作为初始结点*/
        TreeNode* root = new TreeNode(preorder[0]);
        /* 当前只有一个节点的话，直接返回 */
        if (inorder.size() == 1){
            return root;
        }
        /*寻找初始结点在中序遍历的位置，从而找到左子树和右子树的范围*/
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        /*i为根节点在中序遍历的下标*/
        int i = it - inorder.begin();
        /*一个错误的思路：如果根节点就在中序遍历的第一位，那么就不用继续遍历了，直接返回
        反例：如果一棵树的每一个结点都没有左子树的话，那么它的前序遍历和中序遍历都是一样的*/ 
        
        /*对左子树进行递归*/
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + i);
        vector<int> inorder_left(inorder.begin(), inorder.begin() + i);
        root -> left = buildTree(preorder_left, inorder_left);
        /*对右子树进行递归*/
        vector<int> preorder_right(preorder.begin() + i + 1, preorder.end());
        vector<int> inorder_right(inorder.begin() + i + 1, inorder.end());
        root -> right = buildTree(preorder_right, inorder_right);

        return root;

        /*
        踩坑：
        1、find函数（begin，last）如果找不到的话，就会返回last的
        2、这里用迭代器构造vector的时候，假如是(0, 10)，那么放入的元素其实是0-9，第10个是不包括的）
        */
    }
};

/* 更节省空间的方法 */
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preorder_begin, int preorder_end, int inorder_begin, int inorder_end) {
        if (preorder_begin == preorder_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorder_begin]);
        
        int i = 0;
        while (inorder[inorder_begin + i] != root -> val) {
            i ++ ;
        }
        
        root -> left = solve(preorder, inorder, preorder_begin + 1, preorder_begin + i + 1, inorder_begin, inorder_begin + i);
        root -> right = solve(preorder, inorder, preorder_begin + i + 1, preorder_end, inorder_begin + i + 1, inorder_end);

        return root;
    }

};