class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int dp1 = costs[0][0], dp2 = costs[0][1], dp3 = costs[0][2];

        for (int i = 1; i < n; ++ i) {
            int f1 = dp1, f2 = dp2, f3 = dp3;
            dp1 = costs[i][0] + min(f2, f3);
            dp2 = costs[i][1] + min(f1, f3);
            dp3 = costs[i][2] + min(f1, f2);
        }

        return min(min(dp1, dp2), dp3);
    }
};