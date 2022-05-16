# 目录

### 48、旋转图像

- ```cpp
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
  ```

- ```cpp
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
  ```





### 498、对角线遍历

- ```cpp
  class Solution {
  private:
      vector<int> res;
      int n{}, m{};
  public:
      vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
          // flag为true的时候，往右上方走，到顶后先往右边看，再往下面看
          // flag为false的时候，往左下方走，到底后，先往下面看，再往右边看
          n = mat.size();
          m = mat[0].size();
          solve(mat, 0, 0, true);
          return res;
      }
  
      void solve(vector<vector<int>>& mat, int i, int j, bool flag) {
          if (flag == true) {
              while (i >= 0 && i < n && j >= 0 && j < m) {
                  res.push_back(mat[i][j]);
                  -- i;
                  ++ j;
              }
              ++ i;
              -- j;
              if (j + 1 < m) {
                  solve(mat, i, j + 1, false);
              } else if (i + 1 < n) {
                  solve(mat, i + 1, j, false);
              }
              return ;
          }
          while (i >= 0 && i < n && j >= 0 && j < m) {
              res.push_back(mat[i][j]);
              ++ i;
              -- j;
          }
          ++ j;
          -- i;
          if (i + 1 < n) {
              solve(mat, i + 1, j, true);
          } else if (j + 1 < m) {
              solve(mat, i, j + 1, true);
          }
      }
  };
  ```





### 349、两个数组的交集

- ```cpp
  class Solution {
  public:
      vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
          unordered_set<int> res;
          unordered_set<int> hashset;
          vector<int> result;
  
          for (int& i: nums1) {
              hashset.insert(i);
          }
  
          for (int& i: nums2) {
              if (hashset.count(i)) {
                  res.insert(i);
              }
          }
  
          for (const int& i: res) {
              result.push_back(i);
          }
          return result;
      }
   };
  ```

- 