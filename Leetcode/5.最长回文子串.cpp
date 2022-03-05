class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int> (n, 0));
        string result = "";

        for (int i = 0; i < n; i ++ ){
            for (int j = 0; j < n - i; j ++ ){
                if (i == 0){//一个字母
                    f[j][j + i] = 1;
                }else if (i == 1){//两个字母
                    f[j][j + i] = (s[j] == s[j + i] ? 2 : 0);
                }else if (s[j] == s[j + i] && f[j + 1][j + i - 1] > 0){//两个字母以上
                        f[j][j + i] = i + 1;
                }
                if (f[j][j + i] > result.size()){
                    result = s.substr(j, i + 1);
                }
            }
        }

        return result;
    }
};