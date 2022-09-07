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
private:
    unordered_map<int, TreeNode*> hashmap;
    vector<int> res{};

    void findparents(TreeNode* root) {
        if (root -> left) {
            hashmap[root -> left -> val] = root;
            findparents(root -> left);
        }
        if (root -> right) {
            hashmap[root -> right -> val] = root;
            findparents(root -> right);
        }
    }

    // depth是用来记录此时的层数，root表示当前要检测的节点，pre表示当前节点root是从节点pre推演过来的，以此拒绝循环调用
    void dfs(TreeNode* root, TreeNode* pre, int depth) {
        if (!root) {
            return ;
        }
        if (depth == 0) {
            res.push_back(root -> val);
            return ;
        }
        if (root -> left != pre) {
            dfs(root -> left, root, depth - 1);
        }
        if (root -> right != pre) {
            dfs(root -> right, root, depth - 1);
        }
        if (hashmap[root -> val] != pre) {
            dfs(hashmap[root -> val], root, depth - 1);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findparents(root);
        dfs(target, nullptr, k);
        return res;
    }
};