class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= m; ++ j) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i - 1][j - 1];
            }
            dp[0] = INT_MAX;
        }

        return dp[m];
    }
};