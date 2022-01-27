class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //排序+贪心/dp，这套的基本套路
        sort(points.begin(), points.end(), [](const auto& i, const auto& j){
            return i[1] < j[1];
        });

        int n = points.size();
        int right = points[0][1];
        int res = 1;
        
        for (int i = 1; i < n; i ++ ) {
            if (points[i][0] > right) {
                res ++ ;
                right = points[i][1];
            }
        }

        return res;
    }
};