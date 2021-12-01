class Solution {
public:
    int translateNum(int num) {
        /*考虑不周，没想到只有一个数的情况...*/
        if (num < 10){
            return 1;
        }
        vector<int> f;
        for (int number = num; number > 0; number /= 10){
            f.push_back(number % 10);
        }
        reverse(f.begin(), f.end());

        /*init*/
        int n = f.size();
        vector<int> dp(n, 1);
        if (f[0] * 10 + f[1] < 26 && f[0] * 10 + f[1] > 9){
            dp[1] ++ ;
        }

        /*dp*/
        for (int i = 2; i < n; i ++ ){
            dp[i] = dp[i - 1];
            if (f[i - 1] * 10 + f[i] < 26 && f[i - 1] * 10 + f[i] > 9){
                dp[i] += dp[i - 2];
            }
        }

        return dp[n - 1];
    }
};