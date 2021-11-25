class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            key：如何获得股票价格差值的最大值
            一定是最低点和这个点以后的最高点的差值
        */
        int n = prices.size(), minn = INT_MAX, res = 0;

        for (int i = 0; i < n; i ++ ){
            minn = min(minn, prices[i]);
            res = max(res, prices[i] - minn);
        }

        return res;
    }
};