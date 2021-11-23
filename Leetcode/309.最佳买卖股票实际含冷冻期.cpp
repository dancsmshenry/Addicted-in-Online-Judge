class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            f[i][n]表示当前有的总money
            f[i][4] = f[i - 1][3];//4表示冷冻，即在昨天就把股票给卖出去了
            f[i][3] = f[i - 1][2] + prices[i];//3表示卖出，即把今天持有的股票给卖出去了
            f[i][2] = -prices[i] + max(f[i - 1][0], f[i - 1][4])//2表示买入，同时比较昨天的money
            f[i][1] = max(f[i][2], f[i][1]);//1表示持有，即要么是昨天刚买的，要么就是昨天就持有的
            f[i][0] = max(f[i][0], f[i][4]);//0表示没有股票，要么昨天也没有，要么昨天是冷冻期
        */
        
        int n = prices.size(), maxn = 0;
        vector<vector<int>> f(n, vector<int> (5, 0));
        //init
        f[0][2] = -(prices[0]);
        f[0][1] = INT_MIN;//这里为INT_MIN是因为为了防止在遍历到第二个数的情况的时候，面对持有，选择的是f[0][2]而不是f[0][1]
        
        //dp
        for (int i = 1; i < n; i ++ ){
            f[i][4] = f[i - 1][3];//4表示冷冻，即在昨天就把股票给卖出去了
            f[i][3] = max(f[i - 1][2], f[i - 1][1]) + prices[i];//3表示卖出，即把今天持有的股票给卖出去了
            f[i][2] = max(f[i - 1][0], f[i - 1][4]) - prices[i];//2表示买入，同时比较昨天的money
            f[i][1] = max(f[i - 1][2], f[i - 1][1]);//1表示持有，即要么是昨天刚买的，要么就是昨天就持有的
            f[i][0] = max(f[i - 1][0], f[i - 1][4]);//0表示没有股票，要么昨天也没有，要么昨天是冷冻期
            int max1 = max(f[i][0], f[i][3]);
            maxn = max(max1, f[i][4]);
        }
        
        return maxn;
    }
};