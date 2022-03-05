class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }

    void dfs(vector<string>& res, string&& mid, int left, int right, int n) {
        if (right == n) {
            res.push_back(mid);
            return ;
        }
        if (left < n) {
            dfs(res, mid + '(', left + 1, right, n);
        }
        if (left > right) {
            dfs(res, mid + ')', left, right + 1, n);
        }
    }
};