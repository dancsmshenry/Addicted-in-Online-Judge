class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, grid[0][0]);

        for (int i = 1; i < m; ++ i) {
            dp[i] = dp[i - 1] + grid[0][i];
        }

        for (int i = 1; i < n; ++ i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < m; ++ j) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }

        return dp.back();
    }
};