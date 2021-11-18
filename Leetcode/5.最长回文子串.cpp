class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));

        for (int l = 0; l < s.size(); l ++ ) 
        {
            for (int i = 0; i + l < s.size(); i ++ ) 
            {
                if (l == 0) dp[i][i + l] = 1;
                else if (l == 1) dp[i][i + l] = (s[i] == s[i + l]);
                else dp[i][i + l] = (s[i] == s[i + l] && dp[i + 1][i + l - 1]);
                if (dp[i][i + l] && l + 1 > ans.size()) ans = s.substr(i, l + 1);
            }
        }

        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int maxn = INT_MIN;
        int f[s.size() + 1][s.size() + 1];
        string result = "";

        for (int i = 0; i < s.size(); i ++ ){
            for (int j = 0; j < s.size() - i; j ++ ){
                f[j][j + i] = 0;
                if (i == 0){
                    f[j][j + i] = 1;
                }else if (i == 1){
                    f[j][j + i] = (s[j] == s[j + i] ? 2 : 0);
                }else{
                    if (s[j] == s[j + i] && f[j + 1][j + i - 1] != 0){
                        f[j][j + i] = (i + 1);
                    }
                }
                if (f[j][j + i] > maxn){
                    maxn = f[j][j + i];
                    result = s.substr(j, i + 1);
                }
            }
        }

        return result;
    }
};