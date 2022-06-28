class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int res = 0;

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n - i; ++ j) {
                if (i == 0) {
                    dp[j][j + i] = 1;
                } else if (i == 1) {
                    dp[j][j + i] = (s[j] == s[j + i]) ? 1: 0;
                } else {
                    if (dp[j + 1][j + i - 1] != 0 && s[j] == s[j + i]) {
                        dp[j][j + i] = 1;
                    }
                }
                res += dp[j][j + i];
            }
        }

        return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};