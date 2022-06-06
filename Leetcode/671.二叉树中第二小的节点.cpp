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
    int ans = -1; // 一开始为-1，表示当前还没有更新过
    int rootvalue; // 记录当前的最小值

    int findSecondMinimumValue(TreeNode* root) {
        rootvalue = root->val; // 设定当前的最小值
        dfs(root); // 深搜
        return ans;
    }

    void dfs(TreeNode* node) {
         if (!node) { // 如果是空结点的话，就直接退出
            return;
        }

        if (ans != -1 && node->val >= ans) { 
            // 如果当前的ans被更新过了，并且当前结点的值大于ans（这表示这棵树所有的结点都比ans要大）
            // 就可以不往下搜索了，直接退出
            // 反过来的情况，要么就是ans=-1，当前还没有更新过ans
            // 要么就是node ->val < ans，表示还有往下搜的必要（说明存在比ans还要小，但是比rootvalue大的数字）
            return;
        }

        if (node->val > rootvalue) {
            // 如果当前的值比最小值大的话，就更新ans（重点还是上面一条语句过滤了很多东西）
            ans = node->val;
        }

        dfs(node->left); // 左搜
        dfs(node->right); // 右搜
    }
};