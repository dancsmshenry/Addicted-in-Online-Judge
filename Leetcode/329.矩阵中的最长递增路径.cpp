class Solution {
public:
    int longestIncreasingPath(vector< vector<int> > &matrix) {
        rows = matrix.size();
        columns = matrix[0].size();
        if (rows == 0 || columns == 0) {
            return 0;
        }

        int ans = 0;
        vector<vector<int>> memo(rows, vector<int>(columns, 0)); // 这个数组还是很巧妙的啊
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < columns; ++ j) {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }

        return ans;
    }

private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows = 0, columns = 0;
    int dfs(vector<vector<int>> &matrix, int row, int column, vector<vector<int>> &memo) {
        if (memo[row][column] != 0) {
            return memo[row][column];
        }

        ++ memo[row][column];
        for (int i = 0; i < 4; ++ i) {
            int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
                memo[row][column] = max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }

        return memo[row][column];
    }
};