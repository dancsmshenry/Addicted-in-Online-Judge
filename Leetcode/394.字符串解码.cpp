class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int n = s.size();
        if (n < 2) {
            return s;
        }

        for (int i = 0; i < n; ) {
            while (isalpha(s[i])) {
                char c = s[i];
                res += c;
                ++ i;
            }

            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + s[i] - '0';
                    ++ i;
                }

                int bracket = 0, begin = i + 1;
                do {
                    if (s[i] == '[') ++ bracket;
                    else if (s[i] == ']') -- bracket;
                    ++ i;
                } while (bracket != 0);

                string mid = decodeString(s.substr(begin, i - begin - 1));//此时i指向的是]下一个字符
                while (count > 0) {
                    res += mid;
                    -- count;
                }
            }
        }

        return res;
    }
};