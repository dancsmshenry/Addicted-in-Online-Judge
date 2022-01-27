class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int right = pairs[0][1];
        int res = 1;
        for (int i = 1; i < pairs.size(); i ++ ) {
            if (pairs[i][0] > right) {
                res ++ ;
                right = pairs[i][1];
            }
        }

        return res;
    }
};