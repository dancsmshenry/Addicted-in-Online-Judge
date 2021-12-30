class MedianFinder {
public:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 最小堆，存储右边一半的数据，堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> minHeap;
    /** initialize your data structure here. */
    MedianFinder()=default;

    // 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
    void addNum(int num) {
        /*
         * 当两堆的数据个数相等时候，左边堆添加元素。
         * 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
         * 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
         * 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
         */
        if (maxHeap.size() == minHeap.size()){
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }else{
            /*把元素放到左边的最大堆里面，找到最大值，并记录下来*/
            maxHeap.push(num);
            int top = maxHeap.top();
            /*然后，把最大元素放到右边里面*/
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) * 1.0 / 2;
        } else {
            return maxHeap.top() * 1.0;
        }
    }
};
/*
    注意，这里的总数如果是奇数的话，那么左边一定比右边大1的（因为两个堆相等的话，就会先把元素啊放到左边的堆上面）
*/
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */