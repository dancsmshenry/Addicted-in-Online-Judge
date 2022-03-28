# 目录

### tire树

- 建立结点tirenode，包含一个指向该结点的数组和一个bool值，布尔值是用来判断是否存在以该节点为末的单词
- 然后依次实现插入，查询单词，查询前缀的操作
- 这道题没啥好说的，注意细节就行了



### 快速幂

- 剑指offer 14- II.剪绳子 II
- 剑指offer 16 数字的整数次方



### 约瑟夫环

- 剑指offer 62.圆圈中最后剩下的数字

- ```cpp
  int solve(int n, int m){
      if (n == 1){
          return 0;
      }else{
          return (solve(n - 1, m) + m) % n;
      }
  }
  ```



### 拓扑排序

- 例题：课程表，课程表II
- 这类题其实有点像模板题，乍一看有点不明来路，但是经过可以训练后是可以达到效果的
- 思路如下：用一个一维数组记录该点的先修课（入度），再用一个二维数组，对于每节课，学了这节课，可以学哪些课
- 然后再把入度为0的课程放入一个队列中（入度为0，表示这节课可以直接上，不需要先修课）
- 然后遍历队列，遍历到的课就是上过了的，然后对那些先修课又这节课的课程，减一他们的入度
- 接着判断入度是否为0，如果是，就代表可以学习了，就把他放入队列中
- 直到队列中没有元素，最后判断



### 原地hash

- 442、数组中的重复数据（每个元素都放到其对应的位置，如果发现对应位置和当前的位置的数都是一样的话，就把它记录下来（因为他出现了两次），并把其中一个设为n+1，这样下次就不会重复记录这个数了）
- 41、缺失的第一个正数（同样的原地hash）
  - 原地hash
  - 每个数都移动到其对应的下标+1的位置（移动的前提：该数大于0，小于n，nums[i] != nums[nums[i]-1]，这是为了防止出现两个位置的数都一样导致无限交换的情况）
  - 然后再遍历一遍，如果当前的数字不等于当前的下标+1，那么下标+1就是缺失的第一个正数
  - 解析：很关键的一点是交换，即对于nums[i]，如果值是在1-n之间的，我就把它放到nums[nums[i] - 1]的位置，然后把nums[num[i] - 1]的值放到nums[i]的位置，一直反复上面的操作，直到两者相同；然后继续操作下一个元素
  - 最后从头开始遍历，如果元素下标和值不符合的话，就返回下标+1

- 剑指03、数组中的重复的数字
  - 这道题也是原地hash
  - 解析：对于每个数nums[i]，如果和nums[nums[i]]相等，就返回数字，否则就进行交换
- 字节面试变种题目：在leetcode41的基础上，找出大于k的不在数组中的最小正整数（solve：把所有的数字都-k，如果全都是负数，就返回k+1，否则就和41题一样处置）



### LRU/LFU

- 460.lfu缓存

- lru

- ```cpp
  struct DLinkedNode {
      int key, value;
      DLinkedNode* prev;
      DLinkedNode* next;
      DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
      DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
  };
  
  class LRUCache {
  private:
      unordered_map<int, DLinkedNode*> cache;
      DLinkedNode* head;
      DLinkedNode* tail;
      int size;
      int capacity;
  
  public:
      /*init*/
      LRUCache(int _capacity): capacity(_capacity), size(0) {
          /*
              使用伪头部和伪尾部节点，方便后续结点的添加和删除
              因为还没有结点，所以先两个结点相连
          */
          head = new DLinkedNode();
          tail = new DLinkedNode();
          head -> next = tail;
          tail -> prev = head;
      }
  
      /*获取key*/
      int get(int key) {
          /*如果key不存在，就返回-1*/
          if (!cache.count(key)) {
              return -1;
          }
  
          /*如果key存在，先通过哈希表定位，然后把结点移到头部*/
          DLinkedNode* node = cache[key];
          moveToHead(node);
  
          return node -> value;
      }
      
      /*插入结点key和value*/
      void put(int key, int value) {
          if (!cache.count(key)) {
              /*如果 key 不存在，创建一个新的节点*/
              DLinkedNode* node = new DLinkedNode(key, value);
              /*结点添加进哈希表*/
              cache[key] = node;
              /*结点添加至双向链表的头部*/
              addToHead(node);
              /*链表长度增加*/
              size ++ ;
              /*如果超出容量，删除双向链表的尾部节点，删除hash中对应的项*/
              if (size > capacity) {
                  DLinkedNode* removed = removeTail();
                  cache.erase(removed -> key);
                  /*防止内存泄漏*/
                  delete removed;
                  size -- ;
              }
          } else {
              /*如果key存在，先通过哈希表定位，然后更新value的值，接着把结点移到头部*/
              DLinkedNode* node = cache[key];
              node -> value = value;
              moveToHead(node);
          }
      }
  
      /*添加结点到头结点的位置*/
      void addToHead(DLinkedNode* node) {
          node -> prev = head;
          node -> next = head -> next;
          head -> next -> prev = node;
          head -> next = node;
      }
      
      /*删除结点*/
      void removeNode(DLinkedNode* node) {
          node -> prev -> next = node -> next;
          node -> next -> prev = node -> prev;
      }
  
      /*将该结点放置头结点的位置*/
      void moveToHead(DLinkedNode* node) {
          removeNode(node);
          addToHead(node);
      }
  
      /*删除最后一个结点*/
      DLinkedNode* removeTail() {
          DLinkedNode* node = tail -> prev;
          removeNode(node);
          return node;
      }
  };
  ```

- 



### 蓄水池抽样法

- 挖坑（https://blog.csdn.net/weixin_41481113/article/details/83449009）



### 鸡蛋楼梯问题

- 挖坑（非常经典的google面试题）



### 实现优先队列

- 挖坑



### 前缀和+哈希表

- 560、和为k的子数组（看起来是easy题目，但是实现的非常的巧妙，要重点看！）



### 字符串匹配算法

- 挖坑（28、实现strstr，实现kmp算法）



### 高精度加减乘除

- 挖坑（字符串相乘：大数相乘，模拟，注意细节）
- 415、字符串相加（高精度加法）



### 螺旋矩阵

- 54、螺旋矩阵，整体的思路就是每一次走都走到当前的边界的位置，然后调整边界，在继续往下走；注意走的时候用count记录当前的数量，同时每次循环的时候要判断count是否大于0
- 因为可能出现很坑爹的情况，比如说，最后只有1 2 3 这一行了，如果不判断的话，此时可能从左到右这一步走完了，修改了top的范围，但是right仍然是大于等于left的，就会再打印一遍，从而出现重复
- 59、螺旋矩阵II，这道题的思路和上面是一样的，但是每次循环的时候可以不用考虑count是否大于0了，因为循环到最后不会出现 1 2 3 的情况



### rand7()生成rand10()

- leetcode 430 Rand7实现Rand10（ys面wxg的时候遇见的）

- https://imageslr.com/2020/probility-lc430.html#randm-%E7%94%9F%E6%88%90-randn

- 我对这道题的理解，这道题的思路上主要分为两步

- 第一步：从rand10()生成rand7()，方法是：我们只要不断调用 rand10() 即可，直到得到我们要的数

- 解释：第一次出现1-7的数字的概率是7/10，第二次的时候，第一次没有命中，第二次命中了，就是3*7/100，依次类推，就是一个等比公式，求到最后发现，得到rand7中的前7个数字的概率是7 / 10 * 10 / 7，即用过rand10的不断调用（大于7就pass，小于等于7就用），发现得到1-7之间的数字的概率是1，那平摊到每个数字的概率就是1/7，也就是等概率的抽取了

- 结论：如果我们知道rand大的概率，那么rand小的概率也可以直接得到

- 第二步：从rand7()生成rand10()，方法是(randx() - 1) * y + randy()

- 解释：本质上是p(ab) = p(a) * p(b)，设这里的a事件为{0，7，14，21，28，35，42}，b事件为{1，2，3，4，5，6，7}，ab事件则为a事件里面的数和b事件里面的数相加得到的

- 首先确定，两个事件是互不影响的，其次，对于a事件，可以用(randx() - 1) * y实现，其中x为7，y为7；对于b事件，直接是randy()，其中y为7

- 注意，这里也可以换为(randx() - 1) * y + randy() - 1，因为后面randy()- 1得到的也是y个数字......，不过是0-x*y-1

- 优化：最开始的优化：对于rand7生成rand10，如果生成的数字是1-40之间，就直接return x%10 + 1

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

- 拓展：[📝【LeetCode】430. Rand7 实现 Rand10 (imageslr.com)](https://imageslr.com/2020/probility-lc430.html#rand7-生成-rand10)建议反复观看



### 下一个排列

- 31，非常的经典，可以好好看看！！



### 其他

- 在脉脉上看到的字节面试题

  - 题干：给定一个整型数组，在数组中找出由三个数组成的最大乘积
  - 题解：找min1,min2,max1,max2,max3，最大数要么就是max1 * max2 * max3，要么就是max3 * min1 * min2
- ys面试遇到的字节面试题
  - 题干：把数字转换为中文：100001，转换为十万零一





# 数据结构设计



- 设计数据结构，使得随机返回数据、增加数据、删除数据，上述操作的时间复杂度都是O(1)
- hashmap+array实现（array存放数字，hashmap存放每个数字对应的下标）
  - 随机返回：随机返回数组下标即可
  - 增加：在array后面添加一个数字，hashmap存放数字的下标
  - 删除：根据被删除元素找到数字的下标，再回到原数组，将最后一个数字和被删除数字交换，最后一个数字设为0，容量减一



- cpp实现hashmap







# 总结

- 发现字节很喜欢考leetcode的变种题，就是把两道leetcode组合在一起，非常的考验做题家的总结和应对能力
- 还有，有些题目（求两数组的中位数）其实在自己训练的时候，是要自己动脑筋去想去理解的，但是对于面试来说，其实只需要朗诵即可....（虽然听起来很功利，但是对于我这种能力不太行的人来说，是这样的...）
- 有关类型的api，建议都用cppreference去查
- 学会看leetcode的报错！！
- https://leetcode-cn.com/circle/discuss/qJXzLU/
