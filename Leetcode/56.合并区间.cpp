class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{};
        
        for (int i = 0; i < n; ++ i) {
            int imax = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= imax) {
                imax = max(imax, intervals[j][1]);
                ++ j;
            }
            res.push_back({intervals[i][0], imax});
            i = j - 1;
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        int left = intervals[0][0], right = intervals[0][1];

        for (int i = 1; i < n; ++ i) {
            if (intervals[i][0] > right) {
                res.push_back({left, right});
                left = intervals[i][0];
            }
            right = max(right, intervals[i][1]);
        }

        res.push_back({left, right});
        return res;
    }
};