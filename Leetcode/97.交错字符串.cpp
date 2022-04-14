class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        if (n + m != t) {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));

        dp[0][0] = true;
        for (int i = 0; i <= n; ++ i) {
            for (int j = 0; j <= m; ++ j) {
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};