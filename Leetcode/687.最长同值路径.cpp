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
    int result{};
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, -1);
        return result;
    }

    //  这里的dfs返回非零的情况是，此时的root -> val等于number，所以此时dfs的返回值代表的是节点值为number的 上一层结点 在这个方向上能够取到的最值（注意是上一层）
    int dfs(TreeNode *root, int number) {
        //  如果当前没有节点，即root为nullptr，就返回0
        if (!root) {
            return 0;
        }

        // 这里就和二叉树的直径一样了，也是要把两边的值加起来去求最长路径
        int n1 = dfs(root -> left, root -> val), n2 = dfs(root -> right, root -> val);
        result = max(result, n1 + n2);

        //  或者，当前节点和前一个结点的值不相同，也返回0（ps：为什么要在这里返回，是因为我们还要往下找一下以此时的root->val为根节点的路径，它是否存在最长的情况）
        if (root -> val != number) {
            return 0;
        }

        // 可能会有人好奇为什么这里要加一，而不是上面的n1和n2加一（可能她的想法是dfs返回的是以当前结点为根节点的最长路径）
        // 因为啊，我们不确定当前结点的左节点和右节点是否等于当前结点
        // 如果不等于的话，那么直接在n1和n2上面+1就会导致结果的错误
        // 在或者说，比如叶子节点和它的父节点是相同的，但是叶子结点因为上述写法返回的是0，那么此时父节点就还得去判断这个左右结点到底和我相不相等，就会造成coding上的麻烦
        // 需要总结： LC124-->LC543-->LC687-->LC2246
        return max(n1, n2) + 1;
    }
};