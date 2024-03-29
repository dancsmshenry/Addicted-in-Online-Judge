# 目录

### 栈的特性

#### 20、有效的括号

- 模拟进栈出栈喽



#### 232、用栈实现队列

- （非常的经典，要好好的看一看）



#### 225、用队列实现栈



#### 946、验证栈序列

- 模拟栈的操作
  - 如果当前的栈顶等于弹出顺序的，就弹出此时的栈顶，同时将指向弹出顺序的指针往后移一位
  - 如果不等于，就把压入序列的元素继续弹入
- 什么时候退出
  - 压入和弹出队列的元素都全被用完的时候，退出while循环，返回true
  - 压入队列的元素都放入了栈中，但是弹出序列还有未被遍历的元素，返回false



#### 剑指 Offer 31、 栈的压入、弹出序列

- 同上946



### 递增栈

#### 84、柱状图中最大的矩形

- ```cpp
  class Solution {
  public:
      int largestRectangleArea(vector<int>& heights) {
          /*
          这道题感觉到是用栈来实现两个数组的遍历，但是没有经过训练，不知道从何下手...
          思路：对于其中的每一个矩形来说，我们都往它的左右两端拓展搜索，直到找到那些比当前数小的数，记录下它们的坐标
          然后用左右坐标相减得到矩形的长度，当前点的矩形长度作为高
          然后依次比较
          
          这里有个比较巧妙的位置，就是用栈来寻找那些比当前数要小的数
          一开始，栈没有数字，就只是把当前左边放进去
          然后，有了数字以后就开始操作栈顶，
          如果当前的元素小于栈顶的元素，就把元素弹出，直到栈顶元素大于当前元素
          如果当前的元素大于栈顶的元素，就不操作
          理由：因为我们是要找到那个刚好小于当前数的那个数，记录它的坐标作为矩形的长
  
          有个问题就是，一直弹出元素，会不会影响后续的元素呢？不会
  
          如果后面的元素大于前面一个元素，那就直接选这个元素就是了
          如果后面的元素小于前面一个元素，那就把前面一个元素弹出，但是也可以继续使用比前面一个数小的那个数进行判断（因为在前一个元素的时候，踢出的都是比前一个元素还大的数字）
          
          所以，其实弹出元素是不影响的
          栈不是重点，重点是如何维护栈....（只有通过发现题目数据的特性才能够维护好....）
          */
  
          stack<int> s1, s2;
          vector<int> left(heights.size() + 1, 0), right(heights.size() + 1, 0);
  
          for (int i = 0; i < heights.size(); i ++ ){
              while (!s1.empty() && heights[s1.top()] >= heights[i]){
                  s1.pop();
              }
              left[i] = s1.empty() ? -1 : s1.top();//理由同下
              s1.push(i);
          }
  
          for (int i = heights.size() - 1; i >= 0; i -- ){
              while (!s2.empty() && heights[s2.top()] >= heights[i]){
                  s2.pop();
              }
              right[i] = s2.empty() ? heights.size() : s2.top();//栈为空，就表明右边的所有的数都大于第i个数，所以返回heights.size()
              s2.push(i);
          }
  
          int maxn = 0;
          for (int i = 0; i < heights.size(); i ++ ){
              maxn = max(maxn, ((right[i] - i) + (i - left[i]) - 1) * heights[i]);
          }
  
          return maxn;
      }
  };
  ```

- 





### 递减栈

#### 496、下一个更大元素

- 维护一个栈，栈内的元素越往上越小，如果新进来的元素比栈顶的元素大，就记录到hashmap中



#### 503、下一个更大元素II

- 维护一个栈，栈内的元素越往上越小，如果新来的元素大于栈顶元素，就pop同时记录到数组中
- 注意，栈内储存的是数组的下标
- 这道题如果当前元素后面没有比它大的话，就要再从前往后帮他找一遍（所以只有最大的元素才是-1）



#### 739、每日温度

- 非常经典的维护栈，从下到上数字是依次变小的，如果来的数比栈顶小，就放进来；比栈顶大，就踢出去，然后记录他们之间的距离（注意，这里记录的是每天的左边，而不是每天的温度）
- 剑指offer II 038.每日温度





### 字符串（括号）

#### 32、最长有效括号

- 这道题的思路很巧妙，维护栈的方式很好比如说，这里的栈放的是数组的坐标，方便求出最长有效括号的长度对于一段连续的有效括号来说，它的最前面无非就几种情况
  - 第一种，栈是空的，我们是记录坐标的长度的，那应该怎么做？题解提供的办法就是放一个-1进去维护（太妙了）
  - 第二种，最左边是(，那好办，所以我们就用当前的)的左边减去栈顶的坐标为什么，因为对应当前的连续括号来说，他的左边界应该就是这个栈顶坐标（注意，期间会因为)把很多的(给踢出去的
  - 第三种，)，那好办，因为这个根本不会被放进去，所以就变为上述第一二种的情况了
- 维护一个栈，栈储存的是字符串的坐标，新来的元素如果是（，就放进去；如果有），就更新result，同时把（，踢出去





### 字符串（去重）

#### 1047、删除字符串中的所有相邻重复项

- 用栈实现，如果栈是空的，或者当前的元素和栈顶不同，就放入元素；否则就不放入元素，并且把栈顶的元素弹出



#### 844、比较含退格的字符串

- 也是用栈实现，和1047相同，不过注意的是遇到#就要把栈顶给pop



#### 开心消消乐

- 之前是消掉相同的两个，现在是消掉三个..（换汤不换药）





### 贪心+栈

#### 402、移掉K位数字

- 贪心+stack



#### 316、去掉重复字母

- 贪心+stack+hashmap





### 计算器

#### 227、基本计算器II

- （用栈模拟，这类题训练太少，又是根本看不出来...）



#### 225、基本计算器

- 也是用栈模拟，不过很巧妙的地方是怎样使用括号，这里是用一个flag来表示正负，遇到符号就通过栈顶获取；如果后续遇到括号的话，就把当前的flag放入栈顶，后续的数字都是取flag相乘





### 其他

#### 二叉树的前中后序遍历（用栈来实现）

- 这里先写一下栈和递归之间的关系：递归，顾名思义，会出现在自己这个函数中调用自己的情况，那么就是说，我要结果，我就要再调用一遍这个函数，得到另一个结果，然后才能推导出当前的结果；也所以，递归就需要有一个边界条件去防止无限的递归
- 这样就有点像栈，要算A，就要先算B；要算B，就要先算C。就是最先要计算的，是最后才计算出来的；而最后面提出来要计算的，是立刻能计算出来的
- 所以，对于二叉树的各种遍历，其实是可以用栈模拟出来的



#### 剑指 Offer 30、包含min函数的栈

- 很巧妙的解答方式，维护两个栈，一个用来存储入栈的值，另一个在每次pop和push的时候，处理最小值，如果push的比当前最小值的栈还要小的值，就同时把它放入最小栈；pop的时候，如果当前的值等于stack2的top，也踢出（感觉有点像模板题，背下来，面试的时候吟诵背后理论即可）



#### 84、柱状图中最大的矩形

- 很难，但考的很多，需要多看看





# 总结

- 遇到一个数组中，需要维护最大最小值（或者是比前一个大，比前一个小）的，就可以维护一个栈
- 或者说遇到含有括号的题目，就可以用栈
- 或者说涉及到字符串数目的，也可以用
- 字符串特别喜欢和栈一起考察