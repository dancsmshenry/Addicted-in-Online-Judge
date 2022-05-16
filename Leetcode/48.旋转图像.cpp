class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i ++) {
            for (int j = i; j < n - i - 1; ++ j) {
                swap(matrix[i][j], matrix[j][n - i - 1]);//a和b交换
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);//a和c交换
                swap(matrix[i][j], matrix[n - j - 1][i]);//d和a交换
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int imin = 0, imax = n - 1;
        while (imin < imax) {
            for (int i = 0; i < imax - imin; ++ i) {
                swap(matrix[imin + i][imax], matrix[imax][imax - i]);
                swap(matrix[imin + i][imax], matrix[imax - i][imin]);
                swap(matrix[imin + i][imax], matrix[imin][imin + i]);
            }
            -- imax;
            ++ imin;
        }
    }
};