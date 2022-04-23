class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int sell = 0;
        int hold = -prices[0];

        for(int i = 1; i < n; ++ i) {
            sell = max(sell, hold + prices[i] - fee);
            hold = max(hold, sell - prices[i]);
        }

        return sell;
    }
};