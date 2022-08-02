class Solution {
private:
    vector<string> res;
public:
    vector<string> permutation(string S) {
        vector<int> ans(125, 0);
        int n = S.length();

        for (int i = 0; i < n; ++ i) {
            ++ ans[S[i]];
        }

        string nullstring = "";
        solve(ans, nullstring);
        return res;
    }

    void solve(vector<int>& ans, string& s) {
        bool flag = true;
        for (int i = 0; i < ans.size(); ++ i) {
            if (ans[i] > 0){
                ans[i] -- ;
                s += (char)i;
                solve(ans, s);
                s.pop_back();
                ans[i] ++ ;
                flag = false;
            }
        }
        if (flag) {
            res.push_back(s);
        }
    }
};