/* 滚动数组 */
class Solution {
public:
    int fib(int n) {
        vector<int> dp = {0, 1};

        for (int i = 2; i <= n; i ++ ) {
            dp[i % 2] = (dp[i % 2] + dp[1 - i % 2]) % 1000000007;
        }

        return dp[n % 2];
    }
};