class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;

public:
    MinStack(){
        while (!s1.empty()){
            s1.pop();
        }

        while (!s2.empty()){
            s2.pop();
        }
    }
    
    void push(int x){
        s1.push(x);
        /*这里少了一个=，即如果有连续的相等的最小值放入栈中，而s2不增加的话，就会导致第一次弹出数字就把s2的最小值踢出，而s1的最小值不变*/
        if (s2.empty() || (x <= s2.top())){
            s2.push(x);
        }
    }
    
    void pop(){
        if (s1.empty()){
            return ;
        }
        /*pop时没有考虑到...*/
        if (s1.top() == s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top(){
        return s1.top();
    }
    
    int min(){
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */