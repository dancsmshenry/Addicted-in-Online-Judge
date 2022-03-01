class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s1;
        int i = 0;
        int n = temperatures.size();
        vector<int> res(n, 0);

        while (i < n) {
            while (i < n && (s1.empty() || temperatures[i] <= temperatures[s1.top()])) {
                s1.push(i);
                i ++ ;
            }
            while (i < n && !s1.empty() && temperatures[i] > temperatures[s1.top()]) {
                res[s1.top()] = i - s1.top();
                s1.pop();
            }
            s1.push(i);
            i ++ ;
        }

        return res;
    }
};