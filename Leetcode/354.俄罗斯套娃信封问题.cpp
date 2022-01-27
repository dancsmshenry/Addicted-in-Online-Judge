//一般的dp会超时的...
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n < 2) {
            return n;
        }
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i ++ ) {
            for (int j = 0; j < i; j ++ ) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

//二分法
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
            //这里的排序其实是很精髓的，首先是按第一个数进行排序正序
            //如果第一个数相等，就按照第二个数倒序排序
            //因为一旦倒序了，只要我后面的信封的第二个数大于前面的信封，就可以放进去
        });

        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; i ++ ) {
            int num = envelopes[i][1];
            if (num > f.back()) {
                f.push_back(num);
            } else {
                auto it = lower_bound(f.begin(), f.end(), num);//二分查找，然后代替
                *it = num;
                //这里的原因和300题的贪心是一样的，可以参照一下
            }
        }

        return f.size();
    }
};