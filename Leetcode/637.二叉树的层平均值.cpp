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
    vector<double> averageOfLevels(TreeNode* root) {
        /*
        用队列来实现层序遍历的确是一个非常优秀的解法！！！
        首先放入一个结点，然后先是对结点进行操作（比如求平均值，或者只是单纯的遍历）
        （这里有一个非常巧妙的地方，记录了原来队列的长度，从而防止了后续添加的元素影响长度）
        然后再把该结点的左右子节点放到队列中
        */
        queue<TreeNode*> q;
        vector<double> result;
        if (root){
            q.push(root);
        }
        while (q.size() != 0){
            int size = q.size();//非常巧妙的地方，就是记录了原来队列的长度
            double total = 0;
            for (int i = 0; i < size; i ++ ){
                TreeNode* node = q.front();
                q.pop();
                total += node -> val;
                if (node -> left){
                    q.push(node -> left);
                }
                if (node -> right){
                    q.push(node -> right);
                }
            }
            result.push_back(total / size);
        }
        return result;
    }
};