#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 有一个字符串，字符串是sdjhfskjfh
 * 要消掉连续3个相同的字符
 * 例子："ccbaaabbcd" ==> "d"
 * 
 * 最开始想到的是用栈来解决问题，但是如果要消掉的字符变多了之后，就要用多指针来解决了
*/

class Solution {
public:
    string kaixingxiaoxiaole(string s) {
        if (s.size() < 3) {
            return s;
        }
        stack<char> s1;

        for (int i = 0; i < s.size(); ++ i) {
            if (s1.empty()) {
                s1.push(s[i]);
                continue;
            }
            if (s[i] != s1.top()) {
                s1.push(s[i]);
            } else {
                char mid = s1.top();
                s1.pop();
                if (!s1.empty() && s[i] == s1.top()) {
                    s1.pop();
                } else {
                    s1.push(mid);
                    s1.push(s[i]);
                }
            }
        }

        string res = "";
        while (!s1.empty()) {
            res += s1.top();
            s1.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};