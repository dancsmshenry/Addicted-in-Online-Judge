class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size(), ans = 0;

        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k ++ ) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] == 0) {
                            ans ++ ;
                        }
                    }
                }
            }
        }

        return ans;
    }
};