class Solution {
private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int left, int right, string temp) {
        if (left > n || right > n) {
            return ;
        }
        if (right == left && left == n) {
            res.push_back(temp);
            return ;
        }
        dfs(n, left + 1, right, temp + "(");
        if (left > right) {
            dfs(n, left, right + 1, temp + ")");
        }
    }
};