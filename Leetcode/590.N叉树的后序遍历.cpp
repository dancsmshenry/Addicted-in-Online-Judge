/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        solve(root);
        return res;
    }

    void solve(Node* root){
        if (!root){
            return ;//没考虑到空树的情况...
        }
        for (int i = 0; i < root -> children.size(); i ++ ){
            solve(root -> children[i]);
        }
        res.push_back(root -> val);
    }
};