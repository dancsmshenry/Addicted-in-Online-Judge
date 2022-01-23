class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n);

        for (int i = 0; i < res.size(); i ++ ) {
            res[i] = (i >> 1) ^ i;
        }

        return res;
    }
};