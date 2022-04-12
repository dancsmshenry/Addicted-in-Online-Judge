class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (int i = 0; i < n;) {
            int imin = intervals[i][0], imax = intervals[i][1];
            int j = i + 1;
            while (j < n) {
                if (intervals[j][0] <= imax && intervals[j][1] >= imax) {
                    imax = intervals[j][1];//只有这种情况才会合并[1,5]，[2,6](注意如果是[1,5]，[2,4]就直接忽略的)
                } else if (imax < intervals[j][0]) {
                    res.push_back({imin, imax});//否则就把当前的区间放入
                    break;
                }
                ++ j;
            }
            if (j >= n) {
                res.push_back({imin, imax});
            }
            i = j;
        }

        return res;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for (int i = 0; i < n;) {
            int imax = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= imax) {
                imax = max(imax, intervals[j][1]);
                ++ j;
            }
            res.push_back({intervals[i][0], imax});
            i = j;
        }

        return res;
    }
};