class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s1, s2;
        vector<int> left(n, 0), right(n, 0);

        for (int i = 0; i < n; ++ i) { 
            while (!s1.empty() && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        for (int i = n - 1; i >= 0; -- i) {
            while (!s2.empty() && heights[s2.top()] >= heights[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++ i) {
            // res = max(res, ((right[i] - i) + (i - left[i]) - 1) * heights[i]);
            res = max(res, ((right[i] - left[i] - 1) * heights[i]));
        }

        return res;
    }
};

// 常数优化
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0), right(n, n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++ i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++ i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};