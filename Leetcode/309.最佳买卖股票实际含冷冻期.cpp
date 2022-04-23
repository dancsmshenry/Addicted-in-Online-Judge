class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int sell1 = 0;
        int sell2 = max(0, prices[1] - prices[0]);
        int hold = max(-prices[1], -prices[0]);

        for (int i = 2; i < n; ++ i) {
            int mid = sell2;
            sell2 = max(sell2, hold + prices[i]);
            hold = max(hold, sell1 - prices[i]);
            sell1 = mid;
        }

        return sell2;
    }
};