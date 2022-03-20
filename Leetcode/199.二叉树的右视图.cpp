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
    vector<int> rightSideView(TreeNode* root) {
        /*
            这道题最朴素的做法就是把所有的数据逐层放到一个二维数组里面，最后收集每一个数组的最后一个元素即可
            从右边看，有以下情况：
            是右子树，那么，就是这一行最右边的那一个右子树
            是左子树，那么就是这一行唯一的子树
            这道题我的做法有几个比较重要的地方：
            首先是用floor来记录每一层子树的深度
            同时是从右边开始遍历（因为是从右边开始看的嘛），再遍历left（所以只要换一下位置便是左视图了）
        */
        vector<int> res;
        solve(root, res, 1);
        return res;
    }

    void solve(TreeNode* root, vector<int>& res, int floor) {
        if (!root) {
            return ;
        }
        if (floor > res.size()) {
            res.push_back(root -> val);
        }

        solve(root -> right, res, floor + 1);
        solve(root -> left, res, floor + 1);
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty()) {
            int n = q1.size();
            for (int i = 0; i < n; i ++ ) {
                TreeNode *mid = q1.front();
                q1.pop();
                if (mid -> left) {
                    q1.push(mid -> left);
                }
                if (mid -> right) {
                    q1.push(mid -> right);
                }
                if (i == n - 1) {
                    res.push_back(mid -> val);
                }
            }
        }

        return res;
    }
};