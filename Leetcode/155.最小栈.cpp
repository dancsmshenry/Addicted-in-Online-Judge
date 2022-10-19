// 需要额外O(n)的空间
class MinStack {
private:
    stack<int> s1, s2;
public:
    MinStack() {
        while (!s1.empty()){
            s1.pop();
        }
        while (!s2.empty()){
            s2.pop();
        }
    }
    
    void push(int val) {
        s1.push(val);
        if (s2.empty() || s2.top() >= val){
            s2.push(val);
        }
    }
    
    void pop() {
        if (s2.top() == s1.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

// 同样是需要额外O(n)的空间，但是思路上更加的巧妙
class Node {
public:
    int minn;
    int val;
};

class MinStack {
private:
    stack<Node> s1;
public:
    MinStack() {
    }
    
    void push(int val) {
        Node node;
        node.val = val;
        if (s1.empty()) {
            node.minn = val;
        } else {
            node.minn = min(s1.top().minn, val);
        }
        s1.push(node);
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top().val;
    }
    
    int getMin() {
        return s1.top().minn;
    }
};

// 不需要额外的stack实现的
class MinStack {
private:
    vector<long> arr;
    long min_value{};
public:
    MinStack() {}
    
    void push(int val) {
        if (arr.empty()) {
            arr.push_back(0);
            min_value = val;
        } else {
            arr.push_back(val - min_value);
            min_value = val > min_value ? min_value: val;
        }
    }
    
    void pop() {
        min_value = arr.back() >= 0 ? min_value: min_value - arr.back();
        arr.pop_back();
    }
    
    int top() {
        if (arr.back() <= 0) {
            return min_value;
        } else {
            return min_value + arr.back();
        }
    }
    
    int getMin() {
        return min_value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */