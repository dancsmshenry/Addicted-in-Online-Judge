# 目录



### 分发糖果

- ```cpp
  class Solution {
  public:
      int candy(vector<int>& ratings) {
          int n = ratings.size();
          int ret = 1;
          int inc = 1, dec = 0, pre = 1;
  
          for (int i = 1; i < n; ++ i) {
              if (ratings[i] >= ratings[i - 1]) {//如果一直是递增的序列的话
                  dec = 0;//重置下降序列的长度
                  pre = (ratings[i] == ratings[i - 1]) ? 1 : pre + 1;//如果比前面大，就是pre+1;否则就是1（这里是个很贪心的技巧，因为只是要求相邻的孩子高的糖果多）
                  ret += pre;//加上当前长度
                  inc = pre;//统计上升序列的长度
              } else {
                  dec++;//统计下降序列的长度
                  if (dec == inc) {
                      dec++;
                  }//这一步非常的精髓，首先是他统计了这个下降序列的长度，如果该下降序列的长度大于前面上升序列的长度，就把后面下降序列的每一位都加一
                  //所以inc实际上是统计了上升序列的长度的
                  ret += dec;//有多少下降的数字就加多少（有一个，就加一，有两个，就加1+2，有三个，就加1+2+3）
                  pre = 1;//重置上升序列的长度
              }
          }
  
          return ret;
      }
  };
  ```





### 45、跳跃游戏II

- ```cpp
  class Solution {
  public:
      int jump(vector<int>& nums) {
          int maxPos = 0, n = nums.size(), end = 0, step = 0;
  
          for (int i = 0; i < n - 1; ++ i) {
              if (maxPos >= i) {
                  maxPos = max(maxPos, i + nums[i]);
                  if (i == end) {
                      end = maxPos;
                      ++step;
                  }
              }
          }
          
          return step;
      }
  };
  ```

- 能跳就跳，同时记录每次跳的终点





### 134、加油站

- ```cpp
  class Solution {
  public:
      int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          int oil = 0;
          int total_oil = 0;
          int station = 0;
  
          for (int i = 0; i < gas.size(); ++ i) {
              total_oil += (gas[i] - cost[i]);
              oil += (gas[i] - cost[i]);
              if (oil < 0) {
                  oil = 0;
                  station = i + 1;
              }
          }
  
          return total_oil < 0 ? -1: station;
      }
  };
  ```

- 如果总共的消耗大于补给，就返回-1

- 如果当天的油量小于0，就从下一天开始骑行
