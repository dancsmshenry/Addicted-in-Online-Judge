#include <cstdlib>

class Solution {
public:
    vector<string> result;

    vector<string> restoreIpAddresses(string s) {
        string res = "";
        solve(s, 0, res, 0);
        return result;
    }

    void solve(string s, int begin, string res, int count){
        if (count > 4) return ;
        if (begin == s.size() && count == 4){//只有放入了四次数字的res才能被放入
            result.push_back(res);
            return ;
        }

        string total = "";
        for (int i = begin; i < s.size(); i ++ ){
            total += s[i];
            if (stoi(total) <= 255){
                string res1 = res + total;
                if (count < 3) res1 += ".";
                solve(s, i + 1, res1, count + 1);
            }else break;

            char c1 = s[begin];//还是访问s[begin]的问题，不知道怎么写...
            if (c1 == '0') return ;
        }
    }
};