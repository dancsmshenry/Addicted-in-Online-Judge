class MaxQueue {
public:
    /*
    queue是普通队列，只能在队首删除元素，队尾插入元素
    deque是双端队列，可以在队尾和队首删除和插入元素
    用一个双端队列来维护最大值
    */
    queue<int> q1;
    deque<int> d1;
    //init
    MaxQueue() {
        while (!q1.empty()){
            q1.pop();
        }
        while (!d1.empty()){
            d1.pop_back();
        }
    }
    
    //如果d1中没有元素，则代表队列中也没有元素了，直接退出，否则就返回d1的第一个元素
    int max_value() {
        if (d1.empty()){
            return -1;
        }
        return d1.front();
    }
    
    //对于排在该元素前面的元素来说，如果value比他们都大的话，那只要value存在，最大值就轮不到前面的元素，所以就可以把它们全都删掉
    //而value如果比他们都小的话，那么也先放入d1中，因为只要前面比他大的都走了，而后面有比它小，那它就可以是最大的了
    //所以，deque后续维护的是一个从右往左依次递增的队列
    //所以，感觉这道题和滑动窗口好像.....
    void push_back(int value) {
        q1.push(value);
        while (!d1.empty() && d1.back() < value){
            d1.pop_back();
        }
        d1.push_back(value);
    }
    
    //踢出元素时，注意一下该元素是否是当前的最大值
    int pop_front() {
        if (q1.empty()){
            return -1;
        }
        int result = q1.front();
        if (result == d1.front()){
            d1.pop_front();
        }
        q1.pop();
        return result;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */