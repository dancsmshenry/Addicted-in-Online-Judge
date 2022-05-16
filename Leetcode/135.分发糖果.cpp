class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = 1;
        int inc = 1, dec = 0, pre = 1;

        for (int i = 1; i < n; ++ i) {
            if (ratings[i] >= ratings[i - 1]) {
                pre = (ratings[i] == ratings[i - 1]) ? 1 : pre + 1;
                res += pre;
                inc = pre;
                dec = 0;
            } else {
                ++ dec;
                if (dec == inc) {
                    ++ dec;
                }
                res += dec;
                pre = 1;
            }
        }

        return res;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> sugar(n, 1);

        for (int i = 1; i < n; ++ i) {
            if (ratings[i] > ratings[i - 1]) {
                sugar[i] = sugar[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; -- i) {
            if (ratings[i] > ratings[i + 1]) {
                sugar[i] = max(sugar[i], sugar[i + 1] + 1);
            }
        }

        return accumulate(sugar.begin(), sugar.end(), 0);
    }
};