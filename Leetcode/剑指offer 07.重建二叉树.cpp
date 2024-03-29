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
        return rebuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *rebuild(vector<int>& preorder, int preorder_left, int preorder_right, vector<int>& inorder, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preorder_left]);
        int i = 0;
        while (inorder[inorder_left + i] != root -> val) {//这里使用auto的find会更加复杂，建议不要使用
            i ++ ;
        }

        root -> left = rebuild(preorder, preorder_left + 1, preorder_left + i, inorder, inorder_left, inorder_left + i - 1);
        root -> right = rebuild(preorder, preorder_left + i + 1, preorder_right, inorder, inorder_left + i + 1, inorder_right);

        return root;
    }
};

// 另一种边界处理
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rebuild(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* rebuild(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int inleft, int inright) {
        if (pleft >= pright) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[pleft]);
        int count{};
        while (inorder[inleft + count] != root -> val) {
            ++ count;
        }

        root -> left = rebuild(preorder, pleft + 1, pleft + count + 1, inorder, inleft, inleft + count);
        root -> right = rebuild(preorder, pleft + count + 1, pright, inorder, inleft + count + 1, inright);

        return root;
    }
};