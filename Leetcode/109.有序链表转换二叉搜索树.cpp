/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head -> val);
            head = head -> next;
        }
        TreeNode* result = solve(res, 0, res.size() - 1);

        return result;
    }

    TreeNode* solve(vector<int>& res, int left, int right) {
        if (left == right) {
            TreeNode* root = new TreeNode(res[left]);
            return root;
        } else if (left > right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(res[(left + right) / 2]);
        root -> left = solve(res, left, (left + right) / 2 - 1);
        root -> right = solve(res, (left + right) / 2 + 1, right);

        return root;
    }
};