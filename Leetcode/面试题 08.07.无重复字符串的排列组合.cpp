class Solution {
public:
    int n;
    vector<string> res;

    vector<string> permutation(string S) {
        n = S.size();
        bool flag[n];
        string v = "";
        memset(flag, false ,sizeof(flag));
        solve(S, flag, v);
        return res;
    }

    void solve(string S, bool flag[], string v){
            if (v.size() == n){
                res.push_back(v);
                return ;
            }
            for (int i = 0; i < n; i ++ ){
                if (flag[i] == false){
                flag[i] = true;
                solve(S, flag, v + S[i]);
                flag[i] = false;
            }
        }
    }
};

class Solution {
private:
    vector<string> res{};
    int n{};
public:
    vector<string> permutation(string S) {
        n = S.length();
        dfs(S, 0);
        return res;
    }

    void dfs(string S, int begin) {
        if (begin == n - 1) {
            res.push_back(S);
            return ;
        }

        for (int i = begin; i < n; ++ i) {
            swap(S[begin], S[i]);
            dfs(S, begin + 1);
            swap(S[begin], S[i]);
        }
    }
};