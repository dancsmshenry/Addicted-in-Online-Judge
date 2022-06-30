# 目录

### tire树

- 建立结点tirenode，包含一个指向该结点的数组和一个bool值，布尔值是用来判断是否存在以该节点为末的单词
- 然后依次实现插入，查询单词，查询前缀的操作
- 这道题没啥好说的，注意细节就行了



### 前缀和

- 二维前缀和
  - 304.二维区域和检索 - 矩阵不可变
  - 剑指offer II 013.二维子矩阵的和



### 快速幂

- 剑指offer 14- II.剪绳子 II
- 剑指offer 16 数字的整数次方



### 拓扑排序

- 例题：课程表，课程表II
- 这类题其实有点像模板题，乍一看有点不明来路，但是经过可以训练后是可以达到效果的
- 思路如下：用一个一维数组记录该点的先修课（入度），再用一个二维数组，对于每节课，学了这节课，可以学哪些课
- 然后再把入度为0的课程放入一个队列中（入度为0，表示这节课可以直接上，不需要先修课）
- 然后遍历队列，遍历到的课就是上过了的，然后对那些先修课又这节课的课程，减一他们的入度
- 接着判断入度是否为0，如果是，就代表可以学习了，就把他放入队列中
- 直到队列中没有元素，最后判断



### 差分数组

- 背景：
  - 如果给你一个包含5000万个元素的数组，然后会有频繁区间修改操作，那什么是频繁的区间修改操作呢？比如让第1个数到第1000万个数每个数都加上1，而且这种操作时频繁的
  - 此时你应该怎么做？很容易想到的是，从第1个数开始遍历，一直遍历到第1000万个数，然后每个数都加上1，如果这种操作很频繁的话，那这种暴力的方法在一些实时的系统中可能就拉跨了
- 使用差分数组，数组的每一项记录的是当前的数与前一项的差值
- 如果想要将指定范围内的数字全部加3，比如下标2-4之间的数字全部加上3，那就在差分数组的1位置加上3，5位置减去3；然后如果想要获取数组的值，就一次遍历一遍差分数组，去更新原数组
- 例题：
  - 1094、拼车
  - 1109、航班预定统计




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





### 下一个排列

- 31，非常的经典，可以好好看看！！





### 部分排序

- 也是非常巧妙的从两边遍历得到结果



### 其他

- 在脉脉上看到的字节面试题

  - 题干：给定一个整型数组，在数组中找出由三个数组成的最大乘积
  - 题解：找min1,min2,max1,max2,max3，最大数要么就是max1 * max2 * max3，要么就是max3 * min1 * min2
- hys面试遇到的字节面试题
  - 题干：把数字转换为中文：100001，转换为十万零一
- 字节原创题目：毒蘑菇（贪心实现）
- 字节原创题目：选数字（贪心+回溯）







# 总结

- 发现字节很喜欢考leetcode的变种题，就是把两道leetcode组合在一起，非常的考验做题家的总结和应对能力
- 还有，有些题目（求两数组的中位数）其实在自己训练的时候，是要自己动脑筋去想去理解的，但是对于面试来说，其实只需要朗诵即可....（虽然听起来很功利，但是对于我这种能力不太行的人来说，是这样的...）
- 有关类型的api，建议都用cppreference去查
- 学会看leetcode的报错！！
- https://leetcode-cn.com/circle/discuss/qJXzLU/
