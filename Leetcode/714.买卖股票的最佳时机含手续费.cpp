class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxn = 0, n = prices.size();
        int f[n][3];
        f[0][0] = 0;
        f[0][1] = - prices[0];

        for (int i = 1; i < n; ++ i){
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i] - fee);
            f[i][1] = max(f[i - 1][0] - prices[i], f[i - 1][1]);
            maxn = max(f[i][0], maxn);
        }

        return maxn;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2){
            return 0;
        }
        vector<int> sell(n, 0);
        vector<int> hold(n, 0);
        // sell[0] = 0;
        hold[0] = - prices[0];

        for(int i = 1; i < n; i ++ ){
            sell[i] = max(sell[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sell[i - 1] - prices[i]);
        }

        return sell[n - 1];
    }
};