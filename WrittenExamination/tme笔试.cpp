// 第二题：从先序遍历和中序遍历中推出原二叉树（树中的值可重复出现）
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param inOrder int整型vector 
     * @return TreeNode类vector
     */
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        return dfs(preOrder, 0, preOrder.size(), inOrder, 0, inOrder.size());
    }
    
    vector<TreeNode*> dfs(vector<int>& pre, int prel, int prer, vector<int>& ino, int inol, int inor) {
        vector<TreeNode*> res;
        if (prel >= prer) {
            vector<TreeNode*> re{nullptr};
            return re;
        }
        
        for (int count = 0; count + inol < inor; ++ count) {
            if (ino[count + inol] == pre[prel]) {
                vector<TreeNode*> left = dfs(pre, prel + 1, prel + 1 + count, ino, inol, inol + count);
                vector<TreeNode*> right = dfs(pre, prel + 1 + count, prer, ino, inol + count + 1, inor);
                for (int i = 0; i < left.size(); ++ i) {
                    for (int j = 0; j < right.size(); ++ j) {
                        TreeNode* root = new TreeNode(pre[prel]);
                        root -> left = left[i];
                        root -> right = right[j];
                        res.push_back(root);
                    }
                }
            }
        }
        
        return res;
    }
};


// 第三题
/**
 * 给定一棵二叉树，二叉树的每个结点只有0或2个孩子。
你需要对每个结点赋值一个正整数，使得每个结点的左右子树权值和相等。
你需要返回所有结点的最小权值和对1e9+7取模的结果。
二叉树结点个数不超过1e5。
 * **/

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tree TreeNode类 
     * @return int整型
     */
    int getTreeSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        buildfloor(root);
        
        return solve(root);
    }
    
    int buildfloor(TreeNode* root) {
        if (!root -> left && !root -> right) {
            return 1;
        }
        int floor{};
        floor = max(buildfloor(root -> right), buildfloor(root -> left)) + 1;
        
        root -> val = floor;
        return floor;
    }
    
    int solve(TreeNode* root) {
        int count = 1;
        if (!root -> left && !root -> right) return count;
        int left = solve(root -> left), right = solve(root -> right);
        if (root -> left -> val > root -> right -> val) count += left * 2;
        else if (root -> left -> val < root -> right -> val) count += right * 2;
        else count += max(left, right) * 2;
        return count % 1000000007;
    }
};

class Solution:
    def getTreeSum(self, tree: TreeNode) -> int:
        def f(node):
            return 0 if not node else max(f(node.left), f(node.right)) * 2 + 1

        return f(tree) % 1000000007



// 第一题
/*
给定一个只包含小写字母字符串，每次可以选择两个相同的字符删除，并在字符串结尾新增任意一个小写字母。
请问最少多少次操作后，所有的字母都不相同？
 
字符串长度<1e3
 
input:
abab
 
output:
2
 
第一次把2个a变成f，第二次把2个b变成b。得到fb，每个字母都不相同，最少操作次数为2。
*/
class Solution:
    def minOperations(self, str: str) -> int:
        c = [0] * 26
        for i in str: c[ord(i) - ord('a')] += 1

        ans = 0
        more = 0
        for i in range(26):
            ans += c[i] // 2
            more += c[i] // 2
            c[i] %= 2
        for i in range(26):
            if c[i] == 0 and more:
                c[i] += 1
                more -= 1
        ans += more

        return ans


// 为啥我的这个有问题？？，只能过60%
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    int minOperations(string str) {
        // write code here
        vector<int> arr(27, 0);
        for (auto& s: str) {
            ++ arr[s - 97];
        }
        
        int count{}, chance{};
        for (auto& num: arr) {
            if (num == 0) ++ chance;
        }
        
        for (auto& num: arr) {
            while (num > 1 && num / 2) {
                int number = num / 2;
                count += number;
                
                if (chance > 0 && num > 2) {
                    if (number > chance) {
                        number -= chance;
                        chance = 0;
                    } else {
                        number = 0;
                        chance -= number;
                    }
                }
                
                num = (num % 2) + number;
            }
        }
        
        return count;
    }
};