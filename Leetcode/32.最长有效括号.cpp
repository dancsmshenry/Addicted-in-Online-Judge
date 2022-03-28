class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> s1;
        s1.push(-1);
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; ++ i) {
            if (s[i] == '(') {
                s1.push(i);
            } else {
                s1.pop();
                if (!s1.empty()) {
                    res = max(res, i - s1.top());
                } else {
                    s1.push(i);
                }
            }
        }

        return res;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; ++ i) {
            if (s[i] == '(') {
                ++ left;
            } else {
                ++ right;
            }
            if (left == right) {
                res = max(res, 2 * right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for (int i = n - 1; i >= 0; -- i) {
            if (s[i] == '(') {
                ++ left;
            } else {
                ++ right;
            }
            if (left == right) {
                res = max(res, 2 * left);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return res;
    }
};