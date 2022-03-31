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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s1;
        TreeNode *pre = nullptr;
        TreeNode *r1 = nullptr, *r2 = nullptr;

        while (!s1.empty() || root) {
            while (root) {
                s1.push(root);
                root = root -> left;
            }
            root = s1.top();
            s1.pop();
            if (!pre) {
                pre = root;
            } else {
                if (root -> val < pre -> val) {
                    r1 = root;
                    if (r2 == nullptr) {
                        r2 = pre;
                    } else {
                        break;
                    }
                }
                pre = root;
            }
            root = root -> right;
        }

        swap(r1 -> val, r2 -> val);
    }
};