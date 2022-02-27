class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxn = 0;

        for (int i = 0; i < n; ++ i ) {
            for (int j = 0; j < m; ++ j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) {
                        dp[i][j] += minn(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
                    }
                    maxn = max(maxn, dp[i][j]);
                }
            }
        }

        return maxn * maxn;
    }

    int minn(int a, int b, int c) {
        int temp = min(a, b);
        return min(temp, c);
    }
};