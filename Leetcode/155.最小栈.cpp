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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */