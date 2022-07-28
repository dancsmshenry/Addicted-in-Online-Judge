# 目录

### 384、打乱数组

- 洗牌算法，用随机数下标来交换数据，达到打乱数组的目的

- ```cpp
  class Solution {
  private:
      vector<int> nums;
      vector<int> original;
  public:
      Solution(vector<int>& nums) {
          this -> nums = nums;
          this -> original.resize(nums.size());
          copy(nums.begin(), nums.end(), original.begin());
      }
      
      vector<int> reset() {
          copy(original.begin(), original.end(), nums.begin());
          return nums;
      }
      
      vector<int> shuffle() {
          for (int i = 0; i < nums.size(); ++ i) {
              int j = i + rand() % (nums.size() - i);
              swap(nums[i], nums[j]);
          }
          return nums;
      }
  };
  
  /**
   * Your Solution object will be instantiated and called as such:
   * Solution* obj = new Solution(nums);
   * vector<int> param_1 = obj->reset();
   * vector<int> param_2 = obj->shuffle();
   */
  ```

- 





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





### 54、螺旋矩阵

- 54、螺旋矩阵，整体的思路就是每一次走都走到当前的边界的位置，然后调整边界，在继续往下走；注意走的时候用count记录当前的数量，同时每次循环的时候要判断count是否大于0
- 因为可能出现很坑爹的情况，比如说，最后只有1 2 3 这一行了，如果不判断的话，此时可能从左到右这一步走完了，修改了top的范围，但是right仍然是大于等于left的，就会再打印一遍，从而出现重复
- 59、螺旋矩阵II，这道题的思路和上面是一样的，但是每次循环的时候可以不用考虑count是否大于0了，因为循环到最后不会出现 1 2 3 的情况





### 56、合并区间

- 将所有的区间按照左边界进行排序，然后模拟依次往后更新合并要放入的区间
- 剑指offer II 074





### 347、前K个高频元素

- 纯纯的模拟+语法题
- 方法一：把数字先放入hashmap中，然后把hashmap中的pair放到vector中进行排序，最后取出前k个高频元素即可
- 方法二：也是先把元素放到hashmap中，然后把pair放到优先队列priority_queue中（如果优先队列的数量大于k的话，就把pop元素），最后去出答案即可
- 剑指offer II 060.出现频率最高的 k 个数字





### 860、柠檬水找零

- 状态机+模拟





### 647、回文子串

- ```cpp
  class Solution {
  public:
      int countSubstrings(string s) {
          int n = s.size(), res = 0;
  
          for (int i = 0; i < 2 * n - 1; ++ i) {
              //	用i/2映射回原来字符串数组的字符，同时利用（i+1）/2和i/2是一样的原理和i%2，针对当前回文串的长度是奇数还是偶数做出应对
              int l = i / 2, r = i / 2 + i % 2;
              while (l >= 0 && r < n && s[l] == s[r]) {
                  -- l;
                  ++ r;
                  ++ res;
              }
          }
  
          return res;
      }
  };
  ```

- 很巧妙的一种模拟方法，值得学习





### 6、Z形变换

- ```cpp
  class Solution {
  public:
      string convert(string s, int numRows) {
          string res{};
          if (numRows == 1) {
              return s;
          }
  
          for (int i = 0; i < numRows; ++ i) {
              int a = 2 * numRows - 2 - i * 2, j = i, l = 0;
              while(j < s.size()) {
                  res += s[j];
                  if (a == 0) {   //  遍历到当前的最后一行的时候，每次只要选择跳过固定步长的字符输入即可
                      j += (2 * numRows - 2);
                  } else if (l % 2 == 0 || 2 * numRows - 2 == a) { // 后一个条件是针对当前处于第一行的情况
                  // 前一个条件则是针对中间层的后一个数字（因为中间层是有两个数字的）
                      j += a;
                  } else {    //  是针对中间层的前一个数字
                      j += (2 * numRows - 2 - a);
                  }
                  ++ l;   //  这里奇数是因为中间层，每两个数字就要往后跳一次
              }
          }
  
          return res;
      }
  };
  ```





# 149、直线上最多的点数

- 暴力模拟，三个循环，第一个循环是当前的点是以当前的点为准星（设为p1），第二个循环时以当前这个点作为参考（设为p2），第三个点设为p3，看是否存在p1p2和p1p3的斜率相同（因为斜率相同就是在同一个线段上）

- ```cpp
  class Solution {
  public:
      int maxPoints(vector<vector<int>>& points) {
          sort(points.begin(), points.end());
          int ans = 1;
          int n = points.size();
  
          for (int i = 0; i < n; ++ i) {
              for (int j = i + 1; j < n; ++ j) {
                  int tmp = 0;
                  int x1 = points[i][0], y1 = points[i][1];
                  int x2 = points[j][0], y2 = points[j][1];
                  int dy = y1 - y2, dx = x1 - x2;
                  for(auto& point : points) {
                      if(dy * (point[0] - x1) == dx * (point[1] - y1)) {
                          ++ tmp;
                      }
                  }
                  ans = max(ans, tmp);
              }
          }
  
          return ans;
      }
  };
  ```

- 