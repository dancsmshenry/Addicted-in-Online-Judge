/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*基本的根左右
        对于每个点，都用dfs函数进行操作*/
        if (!root){
            return root;
        }
        dfs(root -> left, root -> right);/*先对root->left和root->right操作*/
        connect(root -> left);
        connect(root -> right);
        return root;
    }

    /*先合并，然后继续往下合并*/
    void dfs(Node* rootleft, Node* rootright){
        if (rootleft && rootright){
            rootleft -> next = rootright;
        }else{
            return ;
        }
        /*合并*/
        dfs(rootleft -> right, rootright -> left);
    }
};