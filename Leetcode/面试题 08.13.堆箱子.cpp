class Solution {
public:
    int pileBox(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i ++ ) {
            dp[i] = intervals[i][2];
        }

        for (int i = 1; i < n; i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (intervals[i][0] > intervals[j][0] && intervals[i][1] > intervals[j][1] && intervals[i][2] > intervals[j][2])
                dp[i] = max(dp[i], dp[j] + intervals[i][2]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};