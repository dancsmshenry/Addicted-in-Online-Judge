class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        /*init*/
        vector<vector<int>> f(n, vector<int> (n, 1));
        for (int i = 0; i < n - 1; i ++ ){
            f[i][i + 1] = (s[i] == s[i + 1] ? 2 : 1);
        }
        
        /*区间型dp*/
        for (int j = 2; j < n; j ++ ){
            for (int i = 0; i < n - j; i ++ ){
                f[i][i + j] = max(f[i][i + j - 1], f[i + 1][i + j]);
                f[i][i + j] = max(f[i][i + j], f[i + 1][i + j - 1]);
                if (s[i] == s[i + j]){
                    f[i][i + j] = max(2 + f[i + 1][i + j - 1], f[i][i + j]);
                }
            }
        }
        return f[0][n - 1];
    }
};