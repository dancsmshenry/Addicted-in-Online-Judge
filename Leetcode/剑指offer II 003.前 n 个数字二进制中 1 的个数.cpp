class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        if (n == 0) {
            return res;
        }
        res[0] = 0;
        res[1] = 1;

        for (int i = 2; i <= n; ++ i) {
            if (i % 2 == 1) {
                res[i] = res[i / 2] + 1;
            } else {
                res[i] = res[i / 2];
            }
        }

        return res;
    }
};