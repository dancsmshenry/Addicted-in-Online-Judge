/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* b = nullptr;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B){/*最开始，B为空的话，直接返回false*/
            return false;
        }
        b = B;

        return solve(A, B, 0);
    }

    bool solve(TreeNode* A, TreeNode* B, int flag){/*需要用一个flag来标识它的父级对象是否已匹配，0标识没匹配，1标识已匹配*/
        if ((!A && !B) || !B){/*如果两个都是空，或者B是空，那么就直接返回true*/
            return true;
        }
        
        if (!A && B){/*如果A为空，B不为空，返回false*/
            return false;
        }                

        /*先将整棵树和左右对比，*/
        bool test = solve(A -> left, b, 0) || solve(A -> right, b, 0);
        if (A -> val == B -> val){/*值相等，再把结果和左右对比*/
            test |= solve(A -> left, B -> left, 1) && solve(A -> right, B -> right, 1);
        }else if (A -> val != B -> val && flag == 1){/*flag用来标记该结点的父类是否被匹配上了，如果被匹配上了，而且值又不相等的话，那么就直接退出*/
            return false;
        }
        /*值不相等，那就直接返回左右两边和树b的结果*/
        return test;
    }
};