# 目录



## 摩尔投票

- 169.多数元素（有数字大于当前数量的一半，那么只要每个人相互残杀（不同的就淘汰），最后剩下的就是众数了）

  - ```cpp
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0;
            int target = 0;
            int n = nums.size();
    
            for (int i = 0; i < n; ++ i) {
                if (count == 0) {
                    target = nums[i];
                    count = 1;
                } else {
                    if (target == nums[i]) {
                        ++ count;
                    } else {
                        -- count;
                    }
                }
            }
    
            return target;
        }
    };
    ```

- 这道题还可以用位运算来做

  - ```cpp
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int result = 0;
            int n = nums.size();
                
            for (long i = 0, two = 1; i < 32; i ++ ) {
                int number = 0;
                for (auto& num: nums) {
                    number += (num >> i) & 1;
                }
                if (number > n / 2) {
                    result += two;
                }
                two *= 2;
            }
    
            return result;
        }
    };
    ```





## 水壶问题

- init：x和y分别为两个水壶，target为要凑出来的目标量

- 将两个水壶看作是一个整体A
- 那么对A的操作只能是+x,-x,-y,+y（理解这一步很重要）
- 那么如果要得到target，就必须有mx+ny=target
- 化简一下就是gcd(x,y) * [一大坨数字] = target
- 换言之，只要target % gcd(x,y) == 0，就证明有解
- PS：这里前面是要先剪枝的（比如说x+y<target的话，那么就比不可能得到target；或者说两个水壶中有一个0，那么就要判断两个水壶加起来是否等于target，或者说target是不是也是0）





## 约瑟夫环

- 剑指offer 62.圆圈中最后剩下的数字

- ```cpp
  class Solution {
  public:
      int lastRemaining(int n, int m) {
          if (n == 1) {
              return 0;
              // return 1; // 如果是从1开始的话
          }
  
          return (lastRemaining(n - 1, m) + m) % n;
          /**
          如果是从1开始的话
          int temp = (lastRemaining(n - 1, m) + m) % n;
          return temp == 0 ? n : temp;
          **/
      }
  };
  ```

- 理解一个递推公式：
  - old = (new + m) % n（前提是坐标是从0开始）
  - 即新一轮的坐标加上m就是旧一轮的坐标（注意，因为是从0开始，所以在删除第m个元素的时候，删除的其实是坐标为m-1的元素）
  - 当新的坐标超过了总长度n的时候，就要再回头数起，所以要mod n
- 有了公式以后，就理解一下递归的思路：
  - 假设我要找的点为a1，我们要返回的是这个点在第一次数组中出现的位置
  - 那么我们知道他最后一个点的坐标是0
  - 那么它的上一次位置坐标是什么，就可以用递归公式得出了
  - 所以不断的往上递归，就出现了该数在第一次数组中出现的位置了





## rand7()生成rand10()

- leetcode 430 Rand7实现Rand10

- https://imageslr.com/2020/probility-lc430.html#randm-%E7%94%9F%E6%88%90-randn



从rand10()生成rand7()

- 我们只要不断调用 rand10() 即可，直到得到我们要的数
- 解释：第一次出现1-7的数字的概率是7/10，第二次的时候，第一次没有命中，第二次命中了，就是3*7/100，依次类推，就是一个等比公式，求到最后发现，得到rand7中的前7个数字的概率是7 / 10 * 10 / 7，即用过rand10的不断调用（大于7就pass，小于等于7就用），发现得到1-7之间的数字的概率是1，那平摊到每个数字的概率就是1/7，也就是等概率的抽取了
- 结论：如果我们知道rand大的概率，那么rand小的概率也可以直接得到



从rand7()生成rand10()

- 方法是(randx() - 1) * y + randy()
- 解释：
  - 本质上是p(ab) = p(a) * p(b)，设这里的a事件为{0，7，14，21，28，35，42}，b事件为{1，2，3，4，5，6，7}，ab事件则为a事件里面的数和b事件里面的数相加得到的
  - 首先确定，两个事件是互不影响的，其次，对于a事件，可以用(randx() - 1) * y实现，其中x为7，y为7；对于b事件，直接是randy()，其中y为7
  - 注意，这里也可以换为(randx() - 1) * y + randy() - 1，因为后面randy()- 1得到的也是y个数字......，不过是0-x*y-1



优化

- 最开始的优化：对于rand7生成rand10，如果生成的数字是1-40之间，就直接return x%10 + 1

- 接着优化：而这里还有41-49没有用上，此时就可以再来一遍

- 看了上述的blog之后，有一个快速好记的理解方式：通过m进制的想法，每执行依次randm，就得到一个0-m-1的数字，对应到位置上，后续再把它转化到十进制，即乘以m的零次方，一次方，二次方，三次方，四次方

  - 已知 RandM() 可以等概率的生成 [0, M-1] 范围的随机整数，那么执行 k 次，每次都得到 M 进制的一位，可以等概率生成 [0,Mk−1] 范围的随机整数，记为 x 
  - RandN 至少需要 N 个均匀随机整数，因此只需要取 k，使得 Mk−1>=N 即可 
  - 此时有多种方式得到 RandN： 
  - 一种是只在 x∈[0,N−1] 时返回 x 
  - 另一种是利用取余运算，在保证等概率的前提下，尽可能多的利用生成的数字，从而减少舍弃的数字比例，降低 while 重复执行的概率

- ```cpp
  int x = (rand7() - 1) * 7 + (rand7() - 1); // 0~48
  
  if (x >= 1 && x <= 40) return x % 10 + 1;
  
  x = (x % 40) * 7 + rand7(); // 1~63
  if (x <= 60) return x % 10 + 1;
  ```

- 再来一遍优化，因为61 62 63没有用上，所以来一遍1-21





### 斐波那契数列的logn做法

- https://zhuanlan.zhihu.com/p/52811691