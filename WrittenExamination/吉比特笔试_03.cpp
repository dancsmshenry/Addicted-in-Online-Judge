#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for (int i = 0; i < n; ++ i) {
            for (int j = 1; j < k + 1; ++ j) {
                int mid = hold[j];
                hold[j] = max(hold[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], mid + prices[i]);
            }
        }

        return sell[k];
    }

    int solve(vector<int>& arrs) {
        int n = arrs.size();
        vector<int> counts(n + 1, 0);
        for (int i = 1; i <= n; ++ i) {
            counts[i] = counts[i - 1] + arrs[i - 1];
        }

        return maxProfit(3, counts);
    }
};

int main() {
    vector<int> arrs{1,-1,1,-1,1};
    Solution s1;
    cout << s1.solve(arrs) << endl;
    return 0;
}