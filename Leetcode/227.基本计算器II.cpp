class Solution {
public:
    int calculate(string s) {
        stack<int> s1;
        int i = 0;
        s1.push(isnumber(s, i));

        while (i < s.size()) {
            if (s[i] == '+') {
                s1.push(isnumber(s, ++ i));
            } else if (s[i] == '-') {
                s1.push(isnumber(s, ++ i) * (-1));
            } else if (s[i] == '*') {
                s1.top() *= isnumber(s, ++ i);
            } else if (s[i] == '/') {
                s1.top() /= isnumber(s, ++ i);
            } else {
                i ++ ;
            }
        }

        int res = 0;
        while (!s1.empty()){
            res += s1.top();
            s1.pop();
        }
        return res;
    }

    int isnumber(string& s, int& i){//取数
        while (s[i] == ' ') i ++ ;
        long number = 0;
        while (i < s.size() && isdigit(s[i])){
            number = number * 10 + s[i] - '0';
            i ++ ;
        }
        return number;
    }
};