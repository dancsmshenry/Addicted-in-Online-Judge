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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> cur;
	    queue<unsigned long long> pos;
	    if (root) {
            cur.push(root);
	        pos.push(0);
        }
	    unsigned long long ans = 1;
	    int j = 1;

	    while (!cur.empty()) {
		    ans = max(ans, pos.back()-pos.front() + 1);
            for (int i = cur.size(); i > 0; -- i) {
			    TreeNode* node = cur.front();
			    cur.pop();
			    unsigned long long position = pos.front();
			    pos.pop();
			    if (node -> left) {
				    cur.push(node -> left);
				    pos.push(position * 2);
			    }
			    if (node -> right) {
				    cur.push(node -> right);
				    pos.push(position * 2 + 1);
			    }
		    }
	    }

	    return ans;
    }
};