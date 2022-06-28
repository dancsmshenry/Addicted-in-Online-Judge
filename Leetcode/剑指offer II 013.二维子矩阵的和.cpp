class NumMatrix {
private:
    vector<vector<int>> record{};
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> temp(n + 1, vector<int>(m + 1, 0));
        temp.swap(record);
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= m; ++ j) {
                record[i][j] = matrix[i - 1][j - 1] + record[i - 1][j] + record[i][j - 1] - record[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return record[row2 + 1][col2 + 1] - record[row1][col2 + 1] - record[row2 + 1][col1] + record[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */