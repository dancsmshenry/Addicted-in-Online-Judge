class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        int f[n + 1][n + 1];

        for (int i = 0; i < n; i ++ ){
            for (int j = 0; j < n - i; j ++ ){
                if (s[j] == s[j + i] && (i == 1 || i == 0 || f[j + 1][j + i - 1] == 1)){
                    f[j][j + i] = 1;
                    result ++ ;
                }else{
                    f[j][j + i] = 0;
                }
            }
        }

        return result;
    }
};