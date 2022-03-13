class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      int top = 0, left = 0;
      int down = m - 1, right = n - 1;
      int count = m * n;
      vector<int> result;

      while (count > 0) {
          for (int i = left; i <= right && count > 0; ++ i, -- count) {
              result.push_back(matrix[top][i]);
          }
          top ++ ;

          for (int i = top; i <= down && count > 0; ++ i, -- count) {
              result.push_back(matrix[i][right]);
          }
          right -- ;

          for (int i = right; i >= left && count > 0; -- i, -- count) {
              result.push_back(matrix[down][i]);
          }
          down -- ;

          for (int i = down; i >= top && count > 0; -- i, -- count) {
              result.push_back(matrix[i][left]);
          }
          left ++ ;
      }

      return result;
    }
};