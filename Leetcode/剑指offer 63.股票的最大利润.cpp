class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = INT_MAX;
        int res = 0;

        for (auto price: prices) {
            res = max(res, price - minn);
            minn = min(minn, price);
        }

        return res;
    }
};