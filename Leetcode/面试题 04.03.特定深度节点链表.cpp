/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> result;
        queue<TreeNode*> q1;
        if (tree){
            q1.push(tree);
        }

        while (!q1.empty()){
            int size = q1.size();
            ListNode* mid = new ListNode(0), *mid1 = mid;
            for (int i = 0; i < size; i ++ ){
                TreeNode* treenode = q1.front();
                q1.pop();
                ListNode* node = new ListNode(treenode -> val);
                mid -> next = node;
                mid = mid -> next;
                if (treenode -> left){
                    q1.push(treenode -> left);
                }
                if (treenode -> right){
                    q1.push(treenode -> right);
                }
            }
            result.push_back(mid1 -> next);
        }

        return result;
    }
};