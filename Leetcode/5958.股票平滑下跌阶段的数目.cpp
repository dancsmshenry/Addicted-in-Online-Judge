class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 1;
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i ++ ){
            if (prices[i] == prices[i - 1] - 1){
                ans[i] += ans[i - 1];
            }
            res += ans[i];
        }

        return res;
    }
};