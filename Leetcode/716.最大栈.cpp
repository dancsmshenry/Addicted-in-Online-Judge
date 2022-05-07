class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() = default;
    
    void push(int x) {
        if (!maxVals.empty() && x < maxVals.top()) {
            maxVals.push(maxVals.top());
        } else {
            maxVals.push(x);
        }
        values.push(x);
    }
    
    int pop() {
        int val = values.top();
        values.pop();
        maxVals.pop();
        return val;
    }
    
    int top() {
        return values.top();
    }
    
    int peekMax() {
        return maxVals.top();
    }
    
    int popMax() {
        int maxv = maxVals.top();
        stack<int> temp;
        while (!values.empty() && values.top() != maxv) {
            temp.push(values.top());
            values.pop();
            maxVals.pop();
        }
        values.pop();
        maxVals.pop();
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        return maxv;
    }
private:
    stack<int> values;
    stack<int> maxVals;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
