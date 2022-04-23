# 目录



## Stock Problem

### 买卖股票的最佳时机I

- jd：只能买卖一次股票（同 剑指 Offer 63. 股票的最大利润）

- 只要找到前面最低点，和这个点以后的最高点的差值即可

- ```cpp
  class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int minn = INT_MAX;
          int res = 0;
  
          for (auto& price: prices) {
              minn = min(minn, price);
              res = max(res, price - minn);
          }
  
          return res;
      }
  };
  ```



### 买卖股票的最佳时机II

- jd：能无限次的买卖股票

- 只要当前的价格大于昨天的，就卖股票拿钱

- ```cpp
  class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int res = 0;
          int n = prices.size();
  
          for (int i = 1; i < n; ++ i) {
              if (prices[i] > prices[i - 1]) {
                  res += (prices[i] - prices[i - 1]);
              }
          }
  
          return res;
      }
  };
  ```



### 买卖股票的最佳时机III

- jd：最多能买卖两次股票
- 每天可以分为两种状态：
  - 没股票 = max（昨天没股票，昨天有股票今天卖股票）
  - 有股票 = max（昨天有股票，昨天没股票今天买股票）
- 再结合最多能买卖两次股票，就变为：
  - 没股票 = max（昨天没股票（处于同一笔交易中），昨天有股票今天卖股票（处于同一笔交易））
  - 有股票 = max（昨天有股票（处于同一笔交易中），昨天没股票今天买股票（进入新一笔交易中））
- 所以这里就把分为两个数组sell和hold，第一个下标表示当前的天数是多少，第二个表示当前是第几个交易阶段

- ```cpp
  class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int n = prices.size();
          /*表示当前持有股票，这里必须要设置为INT_MIN，因为对于i=1的时候，此时对应的是prices中的0，那么要持有股票的话，就只能当前买股票，不能用前一天的数据
          而当天买股票会导致值为负数，为了防止这一点，就设为INT_MIN，使得当天要股票的话，就必须当天买，不能推到昨天*/
          vector<vector<int>> hold(n + 1, vector<int> (3, INT_MIN));
          /*当前没股票*/
          vector<vector<int>> sell(n + 1, vector<int> (3, 0));
  
          for (int i = 1; i <= n; ++ i) {
              for (int j = 1; j < 3; ++ j) {
                  /*第i天有股票，要么是第i-1天没有股票，第i天买的；要么是第i-1天有股票*/
                  hold[i][j] = max(hold[i - 1][j], sell[i - 1][j - 1] - prices[i - 1]);
                  /*第i天没有股票，要么是第i-1天有股票，然后第i天卖出的；要么是第i-1天就没有股票*/
                  sell[i][j] = max(sell[i - 1][j], hold[i - 1][j] + prices[i - 1]);
              }
          }
  
          return sell[n][2];
      }
  };
  
  //滚动数组优化
  class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int n = prices.size();
          int sell1 = 0;
          int sell2 = 0;
          int hold1 = -prices[0];
          int hold2 = -prices[0];
  
          for (int i = 0; i < n; ++ i) {
              sell1 = max(sell1, hold1 + prices[i]);
              hold1 = max(hold1, -prices[i]);
              sell2 = max(sell2, hold2 + prices[i]);
              hold2 = max(hold2, sell1 - prices[i]); 
          }
  
          return sell2;
      }
  };
  ```

- 这里有个很坑的地方，就有点难以理解：
  - 其实当j等于2的时候，真的不代表它经过了两次交易，有可能是前一段中价格实在太低了，就没有买股票，所以值就是0（这里数组初始化的时候就有了），当出现合适的时候就买了股票，记录为第二笔交易
  - 而我们这里对于每一天，都记载了当前是第一笔交易或是第二笔交易的情况，所以算得上是考虑周全了
- 这里我对dp的一个感悟就是，将问题变为一个一个子问题，然后从最后一步看是否符合dp模型，即最优解是否符合状态转移这个过程



### 买卖股票的最佳时机IV

- jd：最多能买卖k次股票
- 和上面的情况一模一样了属于是.....

- ```cpp
  class Solution {
  public:
      int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
          /*表示当前持有股票，这里必须要设置为INT_MIN，因为对于i=1的时候，此时对应的是prices中的0，那么要持有股票的话，就只能当前买股票，不能用前一天的数据
          而当天买股票会导致值为负数，为了防止这一点，就设为INT_MIN，使得当天要股票的话，就必须当天买，不能推到昨天*/
          vector<vector<int>> hold(n + 1, vector<int> (k + 1, INT_MIN));
          /*当前没有股票*/
          vector<vector<int>> sell(n + 1, vector<int> (k + 1, 0));
  
          for (int i = 1; i <= n; ++ i) {
              for (int j = 1; j < k + 1; ++ j) {
                  /*第i天有股票，要么是第i-1天没有股票，第i天买的；要么是第i-1天有股票*/
                  hold[i][j] = max(hold[i - 1][j], sell[i - 1][j - 1] - prices[i - 1]);
                  /*第i天没有股票，要么是第i-1天有股票，然后第i天卖出的；要么是第i-1天就没有股票*/
                  sell[i][j] = max(sell[i - 1][j], hold[i - 1][j] + prices[i - 1]);
              }
          }
  
          return sell[n][k];
      }
  };
  
  //滚动数组优化
  class Solution {
  public:
      int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
          vector<int> hold(k + 1, INT_MIN);
          vector<int> sell(k + 1, 0);
  
          for (int i = 0; i < n; ++ i) {
              for (int j = 1; j < k + 1; ++ j) {
                  int mid = hold[j];
                  hold[j] = max(hold[j], sell[j - 1] - prices[i]);
                  sell[j] = max(sell[j], mid + prices[i]);
              }
          }
  
          return sell[k];
      }
  };
  ```



### 最佳买卖股票时机含冷冻期

- jd：能无限买卖股票，但是卖出股票的第二天是不能买入股票的（即冷冻期为1天）
- 参考股票模型，然后魔改一下，注意init即可
- 拓展：如果冷冻期是2天，3天，那也是一样的

- ```cpp
  class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int n = prices.size();
          /*判断边界情况*/
          if (n < 2) {
              return 0;
          }
          /*init数组*/
          vector<int> sell(n, 0);
          vector<int> hold(n, 0);
          /*最开始持有的话，就是第一天股票的价格*/
          hold[0] = -prices[0];
          /*第二天买的话就看谁的价格更低一点*/
          hold[1] = max(-prices[1], -prices[0]);
          /*第二天卖的话，看有无利润喽*/
          sell[1] = max(0, prices[1] - prices[0]);
  
          for (int i = 2; i < n; ++ i) {
              sell[i] = max(sell[i - 1], hold[i - 1] + prices[i]);
              /*如果今天有股票的话，要么昨天有，要个过了冷冻期再才能买股票*/
              hold[i] = max(hold[i - 1], sell[i - 2] - prices[i]);
          }
  
          return sell[n - 1];
      }
  };
  
  //使用滚动数组优化
  class Solution {
  public:
      int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();
          if (n < 2) {
              return 0;
          }
          int sell = 0;
          int hold = -prices[0];
  
          for(int i = 1; i < n; ++ i) {
              sell = max(sell, hold + prices[i] - fee);
              hold = max(hold, sell - prices[i]);
          }
  
          return sell;
      }
  };
  ```



### 买卖股票的最佳时机含手续费

- jd：可以无限买卖股票，但买卖股票有手续费
- 太经典的模型了.....

- ```cpp
  class Solution {
  public:
      int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();
          if (n < 2) {
              return 0;
          }
          vector<int> sell(n, 0);
          vector<int> hold(n, -prices[0]);
  
          for(int i = 1; i < n; ++ i) {
              sell[i] = max(sell[i - 1], hold[i - 1] + prices[i] - fee);
              hold[i] = max(hold[i - 1], sell[i - 1] - prices[i]);
          }
  
          return sell[n - 1];
      }
  };
  
  //发现sell和hold只依赖前面一个，所以可以滚动数组优化
  class Solution {
  public:
      int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();
          if (n < 2) {
              return 0;
          }
          int sell = 0;
          int hold = -prices[0];
  
          for(int i = 1; i < n; ++ i) {
              sell = max(sell, hold + prices[i] - fee);
              hold = max(hold, sell - prices[i]);
          }
  
          return sell;
      }
  };
  ```






## Knapsack Problem

- 01背包问题
- 完全背包问题
- 多重背包问题
- 混合背包问题
- 二维费用背包问题
- 分组背包问题
- 背包问题求方法数
- 单词拆分

 

## House Robber

- 打家劫舍I
- 打家劫舍II
- 打家劫舍III



## 区间型dp

- 戳气球
- 单词拆分
- 最长回文子串
- 647、回文子串
- 718、最长重复子数组



## 序列型dp

- 正则表达式
- 编辑距离
- 97、交错字符串



## 传统dp

- 最长子序列
- 零钱兑换
- 爬楼梯
- 斐波那契数列
- 不同路径
- 最小路径和
- 最小三角路径和



## Others

- 接雨水
- 俄罗斯套娃信封问题
- 鸡蛋掉落
- 剑指offer n个骰子的点数
- 最长重复子数组（这么经典的dp我居然没看出来......）
- 53、最大子序列和（剑指offer 42.连续子数组的最大和）
  - 简单题，但是思路却很巧妙
  - 先初始化dp为第一个元素
  - 对于后面的每一个元素，如果我当前的dp是正的话，那我就加上当前的数；否则dp就变为当前的数（这一步非常的关键，可以认为是一种贪心的做法，因为dp为正的时候，它可以搏一搏更大的数，因为后面如果是正的，就更大了；如果负的，那么首先res已经记录了max值，其次，加上负的，有可能后面还会有更大的数。这无疑是一种贪心了）
  - 然后将此时的dp和res进行比较，res去max
  - 最后遍历完所有的元素后，return res



# 总结

- 题目如果涉及到区间的，马上想到区间型动态规划
  - 解：首先是确定区间i-j，然后在i-j里面选择数字k，查看i-k和k+1-j的情况，然后把状态转移给i-j
  - 注意要控制好循环的边界，同时做好dp数组的初始化
- 而区间型的dp，看看是否可以用背包问题来优化一下
  - 例如单词拆分，用区间是可以做出来，但是时间空间的效率都太慢了
  - 所以思考一下对于0-i之间的字母，如果可以用dictionary组合出来，必然存在j，使得j-i之间为一个在dictionary里面的单词
  - 而要保证0-i之间为true，就要保证后面是一个单词，并且前面也要是true
  - 这就是最早的硬币问题啦
- 而股票问题给我们最大的启示就是
  - 首先，要找到正确的状态去转移，题目往往会给很多无用的信息
  - 如果状态的维数太高，考虑是不是要降维换成数组来表示（如三维数组变为sold和hold两个数组）



## 滚动数组优化

- 思路：可以用first和second，或者temp来实现，或者使用二进制来实现
- 例题：
  - 62、不同路径
  - 63、不同路径II
  - 64、最小路径和
  - 120、最小三角路径和
  - 198、打家劫舍
  - 213、打家劫舍II（这里只能用第一种方法来实现滚动数组，小心坑）
