# 海量数据排序

- 100亿个数据，512M内存，如何找出中位数（归并），别的方法呢（不会）



先对数据进行hash分组，将hash结果相同的数据放到同一个文件中

然后对每个文件的数据都单独的进行排序

最后多个文件进行归路排序





# 海量数据找前N个数据

步骤

- 分而治之，将数据通过hashfunc映射到不同的文件中
- 在每个文件中，使用hashmap或前缀树统计频率
- 应用堆排序或快速排序对数据进行处理



例子一：海量数据中找最值（内存有限，无法放下所有的数据）

- 通过hashfunc将ip数据划分为多个小文件
- 再找出每个小文件中的最大值（可以用归并快排等排序）
- 然后再在这么多个小文件的最大值中找到最大值



例子二：在海量数据中找到出现频率最高的前k个‘

- 如果内存中能够放下所有的数据，那么就直接在内存中进行频率的统计；否则就对hash值取模后分发到不同的文件中，然后再用hashmap或者前缀树进行统计

- 然后维护一个大小为k的**最小堆**，遍历所有数据出现的频率，每次分别和根元素进行比较，最后找到topk
  - 这里的重点就是这个堆可以用来处理流式数据，可以在不把所有元素放入的情况下，把topk找到
  - 同时也可以每次只比较两个文件的前100个数据，然后再来比较下一个文件，类似归并排序





# 海量数据找交集

例子三：给定两个海量数据的文件（数据不能全放到内存中），找相同的数据

- 对两个文件的数据用相同的hashfunc，然后用相同的数进行取模以此划分到同一个文件中
- 接着遍历两个文件相同hash值的文件的hashset，找到相同的就输出保存即可





# bitmap

例子一：海量数据中找不重复的整数个数（即只招只出现了一次的数据，PS：内存装不下）

- 可以用hashfunc，根据hash值后取模，以此划分到不同的小文件中
- 接着统计每个小文件中数据出现的次数，将次数为1的数据记录下来即可



- 当然还有另外一种方法，比如说用bitmap
  - 位图的思想是用bit数组来记录0-1两种状态，可以将具体数据映射到这个bit数组的对应位置，bit数组中0表示数据存在，1表示数据不存在。举个例子，利用位图表示0-5中的元素，0-5中只有6个数，所以用6bit足以表示，例如3可以表示为[0,0,0,1,0,0]。位图在大量数据查询、去重等应用场景中使用的比较多，这个算法具有比较高的空间利用率
  - 而bitmap的实现，一个long8个字节，64bit，那么一个long就可以表示64个数字
- 可以用上两个bitmap
  - 对于元素的遍历，如果该元素没出现过，就在第一个bitmap上置零
  - 如果出现过一次，那么就是第一个bitmap上为1，在第二个hashmap上为0
  - 如果出现过多次，那么就是第一个bitmap上为1，在第二个hashmap上为1



例子二：海量数据中找不同数据的个数

- 直接上bitmap，先开一个包含所有情况大小的数组，然后如果数据出现了就在其位置上置一，否则就是零
- 最后，统计1的个数即可



例子三：海量数据找中位数

- 一种分治的思想
- 第一遍：优先考虑每个整数二进制的最高位，将最高位为1的分到文件a，将最高位为0的分到文件b
- 统计文件a和文件b中的整数个数，如果文件a和文件b中的整数个数相同，那么中位数则是文件a中的最小值和文件b中的最大值的平均值。如果文件a中的整数个数小于文件b，那么中位数肯定在文件b中，反之亦然
- 如果文件a或文件b中的整数还是无法直接读取进内存中，那么继续使用上个步骤的方法进行分流（即看每个整数二进制的第二高位），直到中位数所在的部分数据的大小能够刚好放到内存中，然后对其排序即可



- 另一种基于堆的思路

- ```java
  class MedianFinder {
      PriorityQueue<Integer> l = new PriorityQueue<>((a,b)->b-a);
      PriorityQueue<Integer> r = new PriorityQueue<>((a,b)->a-b);
  
      public void addNum(int num) {
          int s1 = l.size(), s2 = r.size();
          if (s1 == s2) {
              if (r.isEmpty() || num <= r.peek()) {
                  l.add(num);
              } else {
                  l.add(r.poll());
                  r.add(num);
              }
          } else {
              if (l.peek() <= num) {
                  r.add(num);
              } else {
                  r.add(l.poll());
                  l.add(num);
              }
          }
      }
  
      public double findMedian() {
          int s1 = l.size(), s2 = r.size();
          if (s1 == s2) {
              return (l.peek() + r.peek()) / 2.0;
          } else {
              return l.peek();
          }
      }
  }
  ```

- 但是如果内存不够的话，就只能用分治的方法了







https://soulmachine.gitbooks.io/system-design/content/cn/