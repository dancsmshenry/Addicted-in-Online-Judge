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
    vector<string> start;
    vector<string> dest;

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string result = "";
        vector<string> temp;
        dfs(root, startValue, temp, start);
        dfs(root, destValue, temp, dest);
        
        int p1 = 0;
        while(p1 < start.size() && p1 < dest.size() && start[p1] == dest[p1]){
            p1 ++ ;
        }
        for (int i = p1; i < start.size(); i ++ ){
            result += "U";
        }
        for (int i = p1; i < dest.size(); i ++ ){
            result += dest[i];
        }

        return result;
    }

    void dfs(TreeNode* root, int value, vector<string>& res, vector<string>& result){
        if(!root){
            return ;
        }
        if (root -> val == value){
            result = res;
            return ;
        }

        res.push_back("L");
        dfs(root -> left, value, res, result);
        res.pop_back();
        if (!result.empty()){
            return ;
        }

        res.push_back("R");
        dfs(root -> right, value, res, result);
        res.pop_back();

        return ;
    }
};