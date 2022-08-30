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
    int kthLargest(TreeNode* root, int k) {
        int deep = deepth(root -> right);

        if (k == deep + 1){
            return root -> val;
        }else if (k > deep + 1){
            return kthLargest(root -> left, k - deep - 1);
        }

        return kthLargest(root -> right, k);
    }
    
    int deepth(TreeNode* root){
        if (!root){
            return 0;
        }
        return 1 + deepth(root -> left) + deepth(root -> right);
    }
};

// dfs
class Solution {
private:
    int res{};
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* root, int &k) {
        if (!root || k <= 0) {
            return ;
        }
        dfs(root -> right, k);
        -- k;
        if (k == 0) {
            res = root -> val;
        }
        dfs(root -> left, k);
    }
};

// 非递归class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root -> right;
            }
            root = s.top();
            -- k;
            if (k == 0) {
                return root -> val;
            }
            s.pop();
            root = root -> left;
        }

        return -1;
    }
};