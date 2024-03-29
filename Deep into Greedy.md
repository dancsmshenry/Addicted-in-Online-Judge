# 目录



## 135、分发糖果

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





## 45、跳跃游戏II

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





## 134、加油站

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





## 738、单调递增的数字

- 直接贪心：

  - 从左往右看，如果数字越来越大就跳过，发现变小则记录下来此时的位置
  - 然后从变小的地方开始往前走，将当前位置的数字减一，然后往前走，直到当前的数字大于前面的数字
  - 然后把当前位置再往后挪一点的位置，全部设为9

- ```cpp
  class Solution {
  public:
      int monotoneIncreasingDigits(int n) {
          string arr = to_string(n);
          int i = 0;
          while (i + 1 < arr.size() && arr[i] <= arr[i + 1]) {
              ++ i;
          }
  
          if (i < arr.size() - 1) {
              while (i >= 0 && arr[i] > arr[i + 1]) {
                  arr[i] -= 1;
                  -- i;
              }
  
              for (i += 2; i < arr.size(); ++ i) {
                  arr[i] = '9';
              }
          }
  
          return stoi(arr);
      }
  };
  ```





## 455、分发饼干

- 把小孩的胃口和饼干分别进行排序
- 为了满足更多的小孩子，必须让大的饼干优先给胃口大的小孩



## 56、合并区间

- 先排序
  - 方法一：根据区间调整当前的left和right，然后组装放入res中
  - 方法二：将区间放入stack中，动态调整栈顶







## 字节原创题目

### 字节面试题01

- 选数字，本质上就是贪心的思想+状态机转移
- 如果一开始，就没有小于等于当前位置的数字，或者小于等于的是0（比如说第一个位置是1，但是当前只有0符合），就直接填满n-1个maxn（maxn为最大的那个数）
- 否则，就继续往下走，说白了真的就是状态机.....





### 毒蘑菇
