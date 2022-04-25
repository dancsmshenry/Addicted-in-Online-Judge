class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, length = 1;
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for (int i = 0; i < n; ++ i ) {
            for (int j = 0; j < n - i; ++ j ) {
                if (i == 0) {
                    dp[j][j] = 1;
                } else if (i == 1) {
                    dp[j][j + i] = (s[j + i] == s[j]) ? 2 : 0;
                } else if (dp[j + 1][j + i - 1] != 0) {
                    dp[j][j + i] = (s[j + i] == s[j]) ? dp[j + 1][j + i - 1] + 2 : 0;
                }

                if (length< dp[j][j + i]) {
                    begin = j;
                    length = i + 1;
                }
            }
        }

        return s.substr(begin, length);
    }
};