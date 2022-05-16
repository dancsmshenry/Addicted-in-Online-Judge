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





### 螺旋矩阵

- 54、螺旋矩阵，整体的思路就是每一次走都走到当前的边界的位置，然后调整边界，在继续往下走；注意走的时候用count记录当前的数量，同时每次循环的时候要判断count是否大于0
- 因为可能出现很坑爹的情况，比如说，最后只有1 2 3 这一行了，如果不判断的话，此时可能从左到右这一步走完了，修改了top的范围，但是right仍然是大于等于left的，就会再打印一遍，从而出现重复
- 59、螺旋矩阵II，这道题的思路和上面是一样的，但是每次循环的时候可以不用考虑count是否大于0了，因为循环到最后不会出现 1 2 3 的情况