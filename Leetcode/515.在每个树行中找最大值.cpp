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
    vector<int> res;
    
    vector<int> largestValues(TreeNode* root) {
        solve(root, 1);
        return res;
    }

    void solve(TreeNode* root, int floor){
        if (!root){
            return ;
        }

        if (floor > res.size()){
            res.push_back(root -> val);
        }else{
            res[floor - 1] = max(res[floor - 1], root -> val);
        }

        solve(root -> left, floor + 1);
        solve(root -> right, floor + 1);
    }
};


/*快捷方法，层序遍历*/
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if (root){
            q.push(root);
        }

        while (q.size() != 0){
            int size = q.size();
            int maxn = INT_MIN;
            for (int i = 0; i < size; i ++ ){
                TreeNode* node = q.front();
                q.pop();
                maxn = max(maxn, node -> val);
                if (node -> left){
                    q.push(node -> left);
                }
                if (node -> right){
                    q.push(node -> right);
                }
            }
            result.push_back(maxn);
        }

        return result;
    }
};