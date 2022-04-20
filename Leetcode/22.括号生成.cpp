class Solution {
private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return res;
    }

    void solve(string&& s, int left, int right, int n) {
        if (left > n || right > n) {
            return ;
        }
        if (left == right && n == left) {
            res.push_back(s);
            return ;
        }
        solve(s + "(", left + 1, right, n);
        if (right < left) {
            solve(s + ')', left, right + 1, n);
        }
    }
};