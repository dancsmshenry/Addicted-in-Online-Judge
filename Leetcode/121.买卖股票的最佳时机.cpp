class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = INT_MAX;
        int res = 0;

        for (auto& price: prices) {
            minn = min(minn, price);
            res = max(res, price - minn);
        }

        return res;
    }
};