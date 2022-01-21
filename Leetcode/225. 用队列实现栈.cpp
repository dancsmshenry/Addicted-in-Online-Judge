//用两个队列的方法
class MyStack {
private:
    queue<int> q1;//这里用来存储按顺序传进来的栈的数据
    queue<int> q2;//这里用来存储栈顶
public:
    MyStack() {
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
    }
    
    void push(int x) {
        q1.push(x);
        if (!q2.empty()) q2.pop();//原来之前出现问题是这里的问题....
        q2.push(x);
    }
    
    int pop(){
        int pop = q2.front();
        q2.pop();
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (q2.size() > 1){
            q1.push(q2.front());
            q2.pop();
        }
        if (q2.empty() && q1.empty()) return pop;
        int temp = q2.front();
        q1.push(temp);
        return pop;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 //用一个队列的方法
 class MyStack {
private:
    queue<int> q1;
public:
    MyStack() {
        while (!q1.empty()) q1.pop();
    }
    
    void push(int x) {
        int size = q1.size();
        q1.push(x);
        for (int i = 0; i < size; i ++ ){
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }
    
    int pop() {
        int pop = q1.front();
        q1.pop();
        return pop;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */