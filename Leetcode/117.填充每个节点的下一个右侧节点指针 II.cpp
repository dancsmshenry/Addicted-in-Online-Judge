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
        if (!root){
            return nullptr;
        }
        solve(root -> left, root -> right);
        connect(root -> left);
        connect(root -> right);
        return root;
    }

    void solve(Node* rootleft, Node* rootright){
        if (!rootleft || !rootright){
            return ;
        }

        rootleft -> next = rootright;
        /*先连右节点的右边，再连上左边*/
        if (rootleft -> left){
            solve(rootleft -> left, rootright -> right);
            solve(rootleft -> left, rootright -> left);
        }
        
        if (rootleft -> right){
            solve(rootleft -> right, rootright -> right);
            solve(rootleft -> right, rootright -> left);
        }
    }
};