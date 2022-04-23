class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell1 = 0;
        int sell2 = 0;
        int hold1 = -prices[0];
        int hold2 = -prices[0];

        for (int i = 0; i < n; ++ i) {
            sell1 = max(sell1, hold1 + prices[i]);
            hold1 = max(hold1, -prices[i]);
            sell2 = max(sell2, hold2 + prices[i]);
            hold2 = max(hold2, sell1 - prices[i]); 
        }

        return sell2;
    }
};