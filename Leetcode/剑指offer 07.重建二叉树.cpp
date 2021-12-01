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
        /*设立初始结点*/
        TreeNode* root = new TreeNode(preorder[0]);
        /*寻找初始结点在中序遍历的位置，从而找到左子树和右子树的范围*/
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        /*i为根节点在中序遍历的下标*/
        int i = it - inorder.begin();
        /*如果根节点就在中序遍历的第一位，那么就不用继续遍历了，直接返回(这个思路是错误的)
        因为，如果一棵树的每一个结点都没有左子树的话，那么它的前序遍历和中序遍历都是一样的
        所以对于中序遍历来说，根节点在第一位并不代表什么，还是得继续遍历下去*/
        /*同时，这里是可以不用写这句话的，因为
        对于vector<int> f1(f2.begin(), f2.begin())来说，它的长度其实是0，这正好符合了我最前面的退出条件*/
        if (inorder.size() == 1){
            return root;
        }
        
        /*对左子树进行递归（踩坑：这里用迭代器构造vector的时候，假如是(0, 10)，那么放入的元素其实是0-9，第10个是不包括的）
        find函数（begin，last）如果找不到的话，就会返回last的
        */
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + i);
        vector<int> inorder_left(inorder.begin(), inorder.begin() + i);
        root -> left = buildTree(preorder_left, inorder_left);
        /*对右子树进行递归*/
        vector<int> preorder_right(preorder.begin() + i + 1, preorder.end());
        vector<int> inorder_right(inorder.begin() + i + 1, inorder.end());
        root -> right = buildTree(preorder_right, inorder_right);

        return root;

        //其实我还有一个效率更高的办法，但是暂时因为能力问题，边界不好控制，所以晚点再写
        //思路：写一个solve函数，每次不仅传递数组本身，同时传递两个数组的边界
        /*find函数踩坑：首先，find(begin, end)，从某种意义上来说是可以查到end的位置的*/
    }
};