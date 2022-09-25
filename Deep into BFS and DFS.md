# 目录

### BFS

- 腐烂的橘子（利用队列实现广搜，非常的经典的广搜题目）





### DFS

- 剑指offer 13
- 22、括号生成（回溯深搜的模板例题，多看多反思）
  - 剑指offer II 085.生成匹配的括号
- 17.电话号码的字母组合（同深搜经典）
- 130、被围绕的区域（非常经典的dfs，注意边界处理）
- 797、所有可能的路径（数据结构书中经典的dfs）
  - 剑指offer II 110 所有路径

- 剑指offer II 081.允许重复选择元素的组合（经典老题）
- 494、目标和（经典的深搜）





## 岛屿系列

### 200、岛屿数量



### 463、岛屿的周长



### 695、岛屿的最大面积

- 剑指offer II 105.岛屿的最大面积
- 这里debug很久的一个原因是，没有把走过的路给置为0，因为如果不置为零，就会导致代码无限递归，最后StackOverflow
- 所以深搜的时候一定要记录当前走过的状态，否则就会爆栈，de半天de不吹来





## 全排列系列

### 46、全排列

- 面试题08.07.无重复字符串的排列组合

- 剑指offer II 083.没有重复元素集合的全排列

- ```cpp
  //	最普通的做法
  class Solution {
  private:
      vector<vector<int>> res{};
      int n{};
  public:
      vector<vector<int>> permute(vector<int>& nums) {
          n = nums.size();
          vector<int> flag(n, 0);
          vector<int> v;
          solve(nums, flag, v);
          return res;
      }
  
      void solve(vector<int>& nums, vector<int>& flag, vector<int>& v) {
          if (v.size() == n) {
              res.push_back(v);
              return ;
          }
          for (int i = 0; i < n; ++ i) {
              if (!flag[i]) {
                  v.push_back(nums[i]);
                  flag[i] = 1;
                  solve(nums, flag, v);
                  v.pop_back();
                  flag[i] = 0;
              }
          }
      }
  };
  ```

- ```cpp
  //	利用排列组合的方法
  //	方法一
  class Solution {
  private:
      int n;
      vector<vector<int>> result;
  public:  
      vector<vector<int>> permute(vector<int>& nums) {
          n = nums.size();
          solve(nums, 0);
          return result;
      }
  
      void solve(vector<int>& nums, int begin) {
          if (begin == n - 1) {
              result.push_back(nums);
          }
  
          for (int i = begin; i < n; ++ i ) {
              swap(nums[i], nums[begin]);
              solve(nums, begin + 1);
              swap(nums[i], nums[begin]);
          }
      }
  };
  
  //	方法二
  class Solution {
  public:
      int n;
      vector<vector<int>> result;
      
      vector<vector<int>> permute(vector<int>& nums) {
          n = nums.size();
          solve(nums, 0);
          return result;
      }
  
      void solve(vector<int> nums, int begin) {
          if (begin == n - 1) {//这里n和n-1也是一样的
              result.push_back(nums);
              return ;
          }
  
          for (int i = begin; i < n; ++ i ) {
              swap(nums[i], nums[begin]);
              solve(nums, begin + 1);
          }
      }
  };
  ```



### 47、全排列II

- 面试题08.08.有重复字符串的排列组合

- ```cpp
  //	最普通的方法，利用数组记录走过的状态
  class Solution {
  private:
      vector<vector<int>> res;
  public:
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<int> ans(22, 0);
  
          for (int i = 0; i < nums.size(); ++ i) {
              ans[nums[i] + 10] ++ ;
          }
          
          vector<int> nullvector;
          solve(ans, nullvector);
          return res;
      }
  
      void solve(vector<int>& ans, vector<int>& res1) {
          if (res1.size() == ans.size()) {
              res.push_back(res1);
              return ;
          }
  
          for (int i = 0; i < ans.size(); ++ i) {
              if (ans[i] > 0) {
                  res1.push_back(i - 10);
                  -- ans[i];
                  solve(ans, res1);
                  ++ ans[i];
                  res1.pop_back();
              }
          }
      }
  };
  ```

- ```cpp
  //	利用排列组合实现dfs
  class Solution {
  public:
      int n;
      vector<vector<int>> result;
  
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          n = nums.size();
          sort(nums.begin(), nums.end());
          solve(nums, 0);
  
          return result;
      }
  
      void solve(vector<int> nums, int begin) {
          if (begin == n) {
              result.push_back(nums);
              return ;
          }
  
          for (int i = begin; i < n; ++ i) {
              if (i != begin && nums[i] == nums[begin]) {
                  continue;
              }
              swap(nums[begin], nums[i]);
              solve(nums, begin + 1);
          }
      }
  };
  ```

- 这里利用排序组合进行dfs的思路就是，每次交换数据后，分出的case必须是独一无二的，否则就会出现重复的情况

  - 什么是分出的case，观察两大类题目的代码可以发现，每次将数据swap以后都要进行dfs，这实际上就是要保证前面已经排好的数据的顺序和后面未拍好的数据组合，这两者组合在一起，是独一无二的

  - **举例**，在全排列中的排列组合方法中的第一种方法，交换了数据后传递的是**引用**，如果后续不交换回去的话，对于上述的组合就会出现重复的情况

    - ```cpp
                  // 比如说对于数据1 2 3，将1和1换位了，变为了1 2 3
                  // 然后进入下一层的dfs，一直到最后一层dfs，好像都没有啥问题
                  // 但，上述只是进入的dfs只进行一次for循环的时候（得到 1 2 3）
              
                  // 如果倒数第二个dfs进入第二层循环（后续会得到1 3 2）
                  // 再返回第一层循环，此时会交换3和1，即得到3 1 2
                  // 进入此时的第二层循环（后续会一次输出3 1 2和 3 2 1）
                  // 问题来了，此时是3 2 1，而此时要和最后一次进行交换，就会变成了 1 2 3
                  // 重蹈覆辙了属于是
              
          // 简述：如果不交换回来的话，一开始位于前面的数会因为深层的dfs而被移动到后面，而当前层次的循环在遍历
                  // 到后面数字的时候又会把它交换回前面，从而造成重复
          ```
          
    - 本质上，是因为不交换回去，就会改变原来的状态，从而影响后续所有的数据排列，导致重复

    - 而我们这种不断的分case的情况，就是基于原有的情况，如果改变了最开始原有的情况就会重复

  - 当然为了解决重复，也有其他的办法，就是全排列中的排列组合方法中的第二种方法，即交换数据以后，传递数组的方式是**值传递**，这样就不会影响原来的数组了

  - 题外话：其实原来数组的循环，本质上只是为了让不同位置的数字，都能够在begin的位置出现，这就不仅能解释为什么方法二不用把数据交换回去（一方面，传入的是值传递，另一方面，只要让不同数字在begin出现即可），也解释了为什么方法一要把数据交换回去（如果不交换回去，就有可能出现重复的情况）

  - **举例**，在全排列II中的排列组合方法中的第一种方法，就是上述所说的第二种方法，不过是添加了if语句进行去重

    - 其实，也正是因为swap没有交换回去，使得去重效果更佳，没有造成错误，也从侧面说明了为什么这里不能用全排列中的方法一
    - 因为假设数据是112222344，此时begin为0
    - 此时第一个1和第一个2交换了位置，变为了211222344，而此时的去重语句中begin位置对应的数据是2，而此后又会以2去辨别i后面的数据是否和2相同，就达到了去重的目的

  - 而为什么不能用上述的方法一，就是因为即使是如下图所示，后续要交换回来了原来的数据，即上面的211222344又变回了112222344，将2和1比较当然不同啦，但是其中多个2是重复的..，所以重复报错了

  - ```cpp
            for (int i = begin; i < n; ++ i ) {
                if (i != begin && nums[i] == nums[begin]) {
                    continue;
                }
                swap(nums[i], nums[begin]);
                dfs(nums, begin + 1);
                swap(nums[i], nums[begin]);
            }
    ```

  - PS：下图代码是我想用方法一在全排列II中使用，~~但是还是debug出bug..~~，找到了反例了：

  - 这里为啥出错还是没有找到原因...

  - ```cpp
       class Solution {
       private:
           vector<vector<int>> res{};
           int n{};
       public:
           vector<vector<int>> permuteUnique(vector<int>& nums) {
               n = nums.size();
               sort(nums.begin(), nums.end());
               dfs(nums, 0);
               return res;
           }
       
           void dfs(vector<int>& nums, int begin) {
               if (begin == n - 1) {
                   res.push_back(nums);
               }
       
               for (int i = begin; i < n; ++ i ) {
                   if (i != begin && (nums[i - 1] == nums[i] || nums[i] == nums[begin])) {
                       // 这里加上nums[i]==nums[begin]是为了防止后续的数字和当前nums[begin]重复（比如说112222233，一开始变为122212233，假如当前遍历到第二个2，即下标为2的数字（arr[2]），如果遍历到第二个1后面的2的时候，仅仅通过nums[i-1]!=nums[i]就判断不是重复的，就会重复）
                       continue;
                   }
                   swap(nums[i], nums[begin]);
                   dfs(nums, begin + 1);
                   swap(nums[i], nums[begin]);
               }
           }
       };
       ```

- 进阶版：优化为迭代的版本...；计算时间复杂度（n * n!）



小结

- 普通的全排列可以用**传引用**和**传值数组**的方式操作，但传引用要记得把数据swap后再swap回来（否则就会有重复），而传值数组就不用swap回来，因为后续的循环是值传递，不影响原来的值
- 而有重复数据的全排列，要先排序一遍，然后用**传值数组**，注意每次swap之前要判断当前遍历到的数字和nums[i]是否相等，如果相等的话就不能swap（否则也会有重复）







## 子集系列

### 78、子集

- 面试题 08.04. 幂集
- 剑指 Offer II 079. 所有子集

- ```cpp
  //	递归法实现枚举，方法一
  class Solution {
  private:
      vector<vector<int>> res{};
      int n{};
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          n = nums.size();
          vector<int> temp{};
          dfs(nums, temp, 0);
          return res;
      }
  
      void dfs(vector<int>& nums, vector<int>& temp, int begin) {
        	//	这种做法就是当参数传入的时候，首先将当前不选择元素的情况放入res中，然后再依次for循环 
          res.push_back(temp);
  
          for (int i = begin; i < n; ++ i) {
              temp.push_back(nums[i]);
              dfs(nums, temp, i + 1);
              temp.pop_back();
          }
      }
  };
  
  //	递归实现枚举，方法二（会浪费部分栈空间，因为它要一直遍历到begin==n的时候才会把数据放到res中，即每条路他都要走到底；而方法一则是一开始就将temp放入res中，即如果该位置不放数据，就不会走动底）
  class Solution {
  private:
      vector<vector<int>> res{};
      int n{};
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          vector<int> temp{};
          n = nums.size();
          dfs(nums, temp, 0);
          return res;
      }
  
      void dfs(vector<int>& nums, vector<int>& temp, int begin) {
          if (begin == n) {
              res.push_back(temp);
              return ;
          }
  
          dfs(nums, temp, begin + 1);
          temp.push_back(nums[begin]);
          dfs(nums, temp, begin + 1);
          temp.pop_back();
      }
  };
  
  //	二进制实现枚举
  class Solution {
  public:
      vector<vector<int>> subsets(vector<int>& nums) {   
          vector<int> mid;
          vector<vector<int>> res;
          int n = nums.size();
  
          for (int i = 0; i < (1 << n); ++ i) {
              int number = i;
              mid.clear();
              
              for (int j = 0; j < n; ++ j) {
                  if (number % 2 == 1) {
                      mid.push_back(nums[j]);
                  }
                  number /= 2;     
              }
  
              res.push_back(mid);
          }
  
          return res;
      }
  };
  
  //	迭代法（不用二进制）实现，非常的巧妙
  class Solution {
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          /**
          首先假设有一个幂集（总共有n个元素），我现在想再加一个元素进去，那么请问现在幂集变为了多少？
          应该是原来的个数再乘以2是吧（这个其实从公式的推到上就可以看出来了）（而实际上，就是原来的幂集（没有这个新的数）加上新的幂集（有这个新的数））
  
          而就是这一点给了启发，既然每加一个元素都会使原来幂集的数量扩至原来的两倍
          那我只要模拟这个过程，维护一个“部分数列”，那么每添加一个数，就插入一个有这个新的数字的“部分数组”
          不断的重复这个过程，最终就是答案！
          **/
          vector<vector<int>> res{};
          vector<int> temp{};
          res.push_back(temp);
          int n = nums.size();
  
          for (int i = 0; i < n; ++ i) {
              int length = res.size();
              for (int j = 0; j < length; ++ j) {
                  temp = res[j];
                  temp.push_back(nums[i]);
                  res.push_back(temp);
              }
          }
  
          return res;
      }
  };
  ```



### 90、子集II

- ```cpp
  //	递归实现枚举
  class Solution {
  private:
      vector<vector<int>> res{};
      int n{};
  public:
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          sort(nums.begin(), nums.end());
          n = nums.size();
          vector<int> temp{};
          dfs(nums, temp, 0);
          return res;
      }
  
      void dfs(vector<int>& nums, vector<int>& temp, int begin) {
          res.push_back(temp);
  
          for (int i = begin; i < n; ++ i) {
              if (i != begin && nums[i] == nums[i - 1]) {
                  continue;
              }
              temp.push_back(nums[i]);
              dfs(nums, temp, i + 1);
              temp.pop_back();
          }
      }
  };
  
  //	还有一种方法，一年多前写的了，有点砍不懂...
  class Solution {
  public:
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          /**
          第一眼看到子集，就觉得可以用位运算来解决
          但是又不知道怎么做
  
          后续感觉又是用回溯来写，可又卡壳了
  
          不过，看了一个评论区里面的一个题解，整个人就通畅了
  
          首先，这道题求子集的过程我已经放到剑指offer 所有子集那里了
          这里重点讨论的是，如何去重：
          如果当前的元素和前面的元素发生重复了怎么办？
          回想之前幂集的做法，当不考虑重复元素的时候，我们是把新的这个元素插入到原来的数列中，获取一个新的数列
          再把这两个数列合并的，是吧
          但，如果出现了相同的，假如加入了a元素后，新的数列是由a1数列和a2数列组成的
          而我后面的元素又是a元素，这是就会造成a1,a2,a2,a2a2数列的重复（即a2和a2是发生了重复的）
          所以为了避免这种重复，当发现了重复元素的时候，我们就选择性的对a2范围的数组进行操作，这样就有效的避免了重复了
  
          而具体如何操作的呢？
          请下面的代码后的注释
          **/
  
          sort(nums.begin(), nums.end());
          vector<vector<int>> res{{}};
          vector<int> ans;
  
          //这里的去重实际上是维护了两个left和right指针，这两个指针的范围就是要操作的数列的范围
          for (int i = 0, len = 0, left = 0, right = 0; i < nums.size(); ++ i) {
              if (i != 0 && (nums[i] == nums[i - 1])){//如果前面有元素，并且前后两个都相等
                  left = res.size() - len;//那就把左边的范围缩小到a2数组的位置（参考上式）
              }else{
                  left = 0;//如果不是，则依旧从0开始计算
              }
              right = res.size();//right是指原数列的尾部嘛
              len = right - left;//维护a1数组的长度，以防后面用得上
              for (int j = left; j < right; ++ j) {
                  ans = res[j];
                  ans.push_back(nums[i]);
                  res.push_back(ans);
              }
          }
          //	这个思路最重要的一点就是，出现重复的数字，我们应该把这个重复的数字放到哪里？
          //	应该放在那些也有重复数据的位置
  
          return res;
      }
  };
  ```
  
- 题解中还有一种用二进制（lc官方题解的方法一）的解法，挖坑







## 组合系列

### 77、组合

- ```cpp
  //	正常方法
  class Solution {
  private:
      vector<vector<int>> res{};
      int n{};
      int k{};
  public:
      vector<vector<int>> combine(int n, int k) {
          this -> n = n;
          this -> k = k;
          vector<int> temp{};
          dfs(temp, 1);
          return res;
      }
  
      void dfs(vector<int>& temp, int begin) {
          if (k - temp.size() > n - begin + 1) {
              return ;
          }
          if (temp.size() == k) {
              res.push_back(temp);
              return ;
          }
          for (int i = begin; i <= n; ++ i) {
              temp.push_back(i);
              dfs(temp, i + 1);
              temp.pop_back();
          }
      }
  };
  
  //	利用flag数组对数据的位置进行记录
  class Solution {
  private:
      vector<vector<int>> res;
      int k{};
      int n{};
  public:
      vector<vector<int>> combine(int n, int k) {
          this -> k = k;
          this -> n = n;
          vector<int> flag(n + 1, 0);
          vector<int> temp{};
          dfs(1, flag, temp);
          return res;
      }
  
      void dfs(int begin, vector<int>& flag, vector<int>& temp) {
          if (k - temp.size() > n - begin + 1) {
              return ;
          }
          if (temp.size() == k) {
              res.push_back(temp);
              return ;
          }
          for (int i = begin; i <= n; ++ i) {
              if (!flag[i]) {
                  temp.push_back(i);
                  flag[i] = 1;
                  dfs(i + 1, flag, temp);
                  flag[i] = 0;
                  temp.pop_back();
              }
          }
      }
  };
  ```

- 注意要**剪枝**

- PS：还有一种基于二进制的方法，太笨了，学不会..





### 39、组合总和

- ```cpp
  class Solution {
  private:
      vector<vector<int>> res{};
      int n{};
  public:
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<int> temp{};
          n = candidates.size();
          dfs(candidates, temp, target, 0);
          return res;
      }
  
      void dfs(vector<int>& candidates, vector<int>& temp, int target, int begin) {
          if (target == 0) {
              res.push_back(temp);
              return ;
          }
          for (int i = begin; i < n; ++ i) {
              if (target < candidates[i]) {
                  continue;
              }
              temp.push_back(candidates[i]);
              dfs(candidates, temp, target - candidates[i], i);
              temp.pop_back();
          }
      }
  };
  ```





### 40、组合总和II

- ```cpp
  class Solution {
  private:
      vector<vector<int>> res{};
  public:
      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<int> temp{};
          sort(candidates.begin(), candidates.end());
          dfs(candidates, temp, target, 0);
          return res;
      }
  
      void dfs(vector<int>& candidates, vector<int>& temp, int target, int begin) {
          if (target == 0) {
              res.push_back(temp);
              return ;
          }
  
          for (int i = begin; i < candidates.size(); ++ i) {
              if (i != begin && candidates[i] == candidates[i - 1]) {
                  continue;
              }
              if (candidates[i] <= target) {
                  temp.push_back(candidates[i]);
                  dfs(candidates, temp, target - candidates[i], i + 1);
                  temp.pop_back();
              }
          }
      }
  };
  ```





### 216、组合总和III

- ```cpp
  class Solution {
  private:
      int k{};
      vector<vector<int>> res{};
  public:
      vector<vector<int>> combinationSum3(int k, int n) {
          vector<int> temp{};
          this -> k = k;
          dfs(temp, 1, n);
          return res;
      }
  
      void dfs(vector<int>& temp, int begin, int target) {
          if (k < temp.size()) {
              return ;
          }
          
          if (target == 0 && temp.size() == k) {
              res.push_back(temp);
          }
         
  
          for (int i = begin; i < 10; ++ i) {
              if (i > target) {
                  return ;
              }
              temp.push_back(i);
              dfs(temp, i + 1, target - i);
              temp.pop_back();
          }
      }
  };
  ```







## 总结

- 排列问题，需要的是交换数据的位置（例如全排列）
- 而组合问题，需要的是选择当前的元素是否要放入temp中（例如子集问题，以及后续的组合问题）
- PS：**如果出现重复的数据，就代表原数据必须要先排序一遍**