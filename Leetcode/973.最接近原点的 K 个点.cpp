class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& p1, const vector<int>& p2){
            int r1 = p1[0] * p1[0] + p1[1] * p1[1];
            int r2 = p2[0] * p2[0] + p2[1] * p2[1];
            return r1 <= r2;
        };

        int n = points.size();
        int left = 0, right = n - 1;

        while (true) {
            vector<int> mid = points[left];
            int idx = left;
            for (int i = left + 1; i <= right; ++ i) {
                if (cmp(points[i], mid)) {
                    ++ idx;
                    swap(points[idx], points[i]);
                }
            }
            swap(points[left], points[idx]);

            if (idx == k - 1) {
                return vector<vector<int>>(points.begin(), points.begin() + k);
            } else if (idx > k - 1) {
                right = idx - 1;
            } else {
                left = idx + 1;
            }
        }
    }
};