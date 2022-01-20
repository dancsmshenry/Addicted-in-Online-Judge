class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);

        for (int i = 0; i < triangle.size(); i ++ ){
            for (int j = i; j >= 0; j -- ){
                if (j == 0){
                    dp[j] += triangle[i][j];
                }else if (j == i){
                    dp[j] = dp[j - 1] + triangle[i][j];
                }else{
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
        }
        
        int res = INT_MAX;//这里要在最后再比较大小
        for (auto& num: dp){
            res = min(res, num);
        }
        return res;
    }
};