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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;
        if (root){
            q.push(root);
        }

        while (q.size() != 0){
            int size = q.size();
            vector<int> res;
            for (int i = 0; i < size; i ++ ){
                Node* node1 = q.front();
                q.pop();
                res.push_back(node1 -> val);
                for (int i = 0; i < node1 -> children.size(); i ++ ){
                    q.push(node1 -> children[i]);
                }
            }
            result.push_back(res);
        }

        return result;
    }
};