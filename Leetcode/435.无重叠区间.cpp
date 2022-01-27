//用dp超时了...
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //这道题关键是要读懂题目的意思：要使得区间和区间之间没有重叠，关键就是要保证后面区间的开头，要大于前面区间的结尾，这样题目就转换为了dp了
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int res = 1;
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (intervals[i][0] >= intervals[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return n - res;
    }
};

//用贪心不会超时
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v){
            return u[1] < v[1];//这里是按照右边界的数来排序的
        });

        int res = 1;//这里注意，第一个区间如果不重叠，则保留下来；如果和后续的重叠了，那么可以先删除掉后面的
        //所以第一个区间保留是可行的
        int right = intervals[0][1];
        for (int i = 1; i < n; i ++ ) {
            if (intervals[i][0] >= right) {
                right = intervals[i][1];
                res ++ ;
            }
        }

        return n - res;
    }
};