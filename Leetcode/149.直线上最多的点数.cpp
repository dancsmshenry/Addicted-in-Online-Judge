class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        int n = points.size();

        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                int tmp = 0;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dy = y1 - y2, dx = x1 - x2;
                for(auto& point : points) {
                    if(dy * (point[0] - x1) == dx * (point[1] - y1)) {
                        ++ tmp;
                    }
                }
                ans = max(ans, tmp);
            }
        }

        return ans;
    }
};