//纯暴力
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = search_deep(root);
        vector<vector<int>> res(n);

        //从第一个点开始操作
        solve(res, root, 1);

        for (int i = 1; i < n; i += 2 ){//注意题目的意思：是从左到右，然后又从右到左，所以遇到偶数行就倒置一遍
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }

    int search_deep(TreeNode* root){
        if (!root){
            return 0;
        }

        return max(search_deep(root -> right), search_deep(root -> left)) + 1;
    }

    //暴力，每一次都把当前的元素放入对应的vector中
    void solve(vector<vector<int>>& res, TreeNode* root, int floor){
        if (!root){
            return ;
        }
        res[floor - 1].push_back(root -> val);
        solve(res, root -> left, floor + 1);
        solve(res, root -> right, floor + 1);
    }
};

//层序遍历解决
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //同样可以用层序遍历来解决
        queue<TreeNode*> q1;
        vector<vector<int>> result;
        int deep = 0;
        if (root){
            q1.push(root);
        }

        while (!q1.empty()){
            int size = q1.size();
            vector<int> res;
            for (int i = 0; i < size; i ++ ){
                TreeNode* mid = q1.front();
                q1.pop();
                res.push_back(mid -> val);
                if (mid -> left){
                    q1.push(mid -> left);
                }
                if (mid -> right){
                    q1.push(mid -> right);
                }
            }
            if (deep % 2 == 1){
                reverse(res.begin(), res.end());
            }
            result.push_back(res);
            deep ++ ;
        }

        return result;
    }
};