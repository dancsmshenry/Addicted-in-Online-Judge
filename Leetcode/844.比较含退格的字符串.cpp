class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //还差一种双指针的做法
        string s1 = solve(s), s2 = solve(t);
        return s1 == s2;
    }

    string solve(string s) {
        string s1 = "";
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (s1.empty()) {
                if (s[i] != '#') s1.push_back(s[i]);
            } else {
                if (s[i] == '#') s1.pop_back();
                else s1.push_back(s[i]);
            }
            ++ i;
        }

        return s1;
    }
};