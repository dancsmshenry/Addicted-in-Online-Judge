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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1{}, arr2{}, res{};
        mid(arr1, root1);
        mid(arr2, root2);
        
        int i = 0, n1 = arr1.size(), j = 0, n2 = arr2.size();
        while (i < n1 || j < n2) {
            if (i < n1 && j < n2) {
                if (arr1[i] > arr2[j]) res.push_back(arr2[j ++ ]);
                else res.push_back(arr1[i ++ ]);
            } else if (i < n1) {
                res.push_back(arr1[i ++ ]);
            } else {
                res.push_back(arr2[j ++ ]);
            }
        }

        return res;
    }

    void mid(vector<int> &arr, TreeNode* root) {
        if (!root) {
            return ;
        }
        mid(arr, root -> left);
        arr.push_back(root -> val);
        mid(arr, root -> right);
    }
};