class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s;

        for (int i = 0; i < n; ++ i) {
            if (s.empty() || temperatures[i] <= temperatures[s.top()]) {
                s.push(i);
                continue;
            }
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};