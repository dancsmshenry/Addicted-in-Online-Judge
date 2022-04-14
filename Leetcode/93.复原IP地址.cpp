class Solution {
private:
    vector<string> result;
    int n;
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if (n < 4) {
            return result;
        }

        solve("", s, 0, 0);

        return result;
    }

    void solve(string res, string s, int begin, int count) {
        if (count > 4) {
            return ;
        }
        if (begin == n && count == 4) {
            result.push_back(res);
            return ;
        }

        string number = "";
        for (int i = begin; i < n; ++ i) {
            number += s[i];
            if (stoi(number) < 256) {
                string mid = res + number;
                if (count < 3) mid += '.';
                solve(mid, s, i + 1, count + 1);
            } else {
                return ;
            }
            if (s[begin] == '0') {//这里有点坑爹，就是如果当前的数字第一位是0，那就不能往后走了
                return ;
            }
        }
    }
};