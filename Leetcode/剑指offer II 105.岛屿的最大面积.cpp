class Solution {
private:
    int n{}, m{};
    int arr[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (grid[i][j] == 1) {
                    res = max(dfs(grid, i, j), res);
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i == n || i < 0 || j == m || j < 0 || grid[i][j] == 0) {
            return 0;
        }

        int count = 1;
        grid[i][j] = 0; //  这里没有把它置零，导致无限循环从而使得栈爆了
        for (int k = 0; k < 4; ++ k) {
            count += dfs(grid, i + arr[k][0], j + arr[k][1]);
        }

        return count;
    }
};