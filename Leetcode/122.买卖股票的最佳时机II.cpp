class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            key：贪心，只要价格够高就卖股票
        */
        int n = prices.size(), res = 0;

        for (int i = 1; i < n; i ++ ){
            res += max(0, prices[i] - prices[i - 1]);
        }

        return res;
    }
};