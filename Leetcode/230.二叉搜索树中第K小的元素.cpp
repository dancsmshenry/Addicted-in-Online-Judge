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
    int kthSmallest(TreeNode* root, int k) {
        int left = count(root -> left);       

        if (k <= left){
            return kthSmallest(root -> left, k);
        }else if (k > left + 1){
            return kthSmallest(root -> right, k - 1 - left);
        }

        return root -> val;
    }

    int count(TreeNode* root){
        if (!root){
            return 0;
        }
        return count(root -> left) + count(root -> right) + 1;
    }
};

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
private:
    int res;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* root, int& k) {
        if (!root || k < 0) {
            return ;
        }
        dfs(root -> left, k);
        k -- ;
        if (k == 0) {
            res = root -> val;
        }
        dfs(root -> right, k);
    }
};