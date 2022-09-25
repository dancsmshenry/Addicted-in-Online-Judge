#include <vector>
#include <iostream>
using namespace std;

// https://mp.weixin.qq.com/s/NZPaFsFrTybO3K3s7p7EVg

class Solution {
    int backToOrigin(int n) {
        int length = 10;
        vector<vector<int>> dp(length, vector<int> (n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i < n + 1; ++ i) {
            for (int j = 0; j < length; ++ j) {
                dp[i][j] = dp[i - 1][(j - 1 + length) % length] + dp[i - 1][(j + 1) % length];
            }
        }

        return dp[n][0];
    }
};