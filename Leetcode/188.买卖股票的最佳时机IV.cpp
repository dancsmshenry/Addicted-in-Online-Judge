class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp1(n + 1, vector<int> (k + 1, INT_MIN));
        /*表示当前持有股票，这里必须要设置为INT_MIN，因为对于i=1的时候，此时对应的是prices中的0，那么要持有股票的话，就只能当前买股票，不能用前一天的数据
        而当天买股票会导致值为负数，为了防止这一点，就设为INT_MIN，使得当天要股票的话，就必须当天买，不能推到昨天*/
        vector<vector<int>> dp2(n + 1, vector<int> (k + 1, 0));
        /*当前没有股票*/
        
        for (int i = 1; i <= n; i ++ ){
            for (int j = 1; j <= k; j ++ ){
                /*第i天有股票，要么是第i-1天没有股票，第i天买的；要么是第i-1天有股票*/
                dp1[i][j] = max(dp2[i - 1][j - 1] - prices[i - 1], dp1[i - 1][j]);
                /*第i天没有股票，要么是第i-1天有股票，然后第i天卖出的；要么是第i-1天就没有股票*/
                dp2[i][j] = max(dp1[i - 1][j] + prices[i - 1], dp2[i - 1][j]);
            }
        }

        return dp2[n][k];
    }
};