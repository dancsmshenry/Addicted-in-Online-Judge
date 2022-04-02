class Solution {
public:
    int calculate(string s) {
        int flag = 1;
        int i = 0, n = s.size();
        int res = 0;
        stack<int> s1;
        s1.push(flag);

        while (i < n) {
            if (s[i] == ' ') {
                ++ i;
            } else if (s[i] == '+') {
                flag = s1.top();
                ++ i;
            } else if (s[i] == '-') {
                flag = -s1.top();
                i ++ ;
            } else if (s[i] == '(') {
                s1.push(flag);
                ++ i;
            } else if (s[i] == ')') {
                s1.pop();
                ++ i;
            } else {
                long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    ++ i;
                }
                res += flag * num;
            }
        }

        return res;
    }
};