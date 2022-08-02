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
    unordered_set<int> hashmap{};
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        // if (hashmap.contains(k - root -> val)) { //  这是cpp20的性质...
        if (hashmap.find(k - root -> val) != hashmap.end()) {
            return true;
        }
        hashmap.insert(root -> val);

        return findTarget(root -> left, k) || findTarget(root -> right, k);
    }
};