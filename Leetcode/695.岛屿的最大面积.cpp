class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int total = 1;
        grid[i][j] = 0;

        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            total += dfs(grid, i + 1, j);
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            total += dfs(grid, i - 1, j);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
            total += dfs(grid, i, j + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            total += dfs(grid, i, j - 1);
        }

        return total;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        
        return res;
    }
};