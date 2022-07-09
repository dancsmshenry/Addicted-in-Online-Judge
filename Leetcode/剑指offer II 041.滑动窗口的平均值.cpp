class MovingAverage {
private:
    queue<int> q;
    int size, num, sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):size(size), num(0), sum(0) {}
    
    double next(int val) {
        sum += val;
        q.push(val);
        ++ num;

        if (num > size) {
            sum -= q.front();
            q.pop();
            -- num;
        }

        return (double)sum / num;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */