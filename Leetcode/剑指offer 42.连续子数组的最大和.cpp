class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0], res = dp;

        for (int i = 1; i < nums.size(); i ++ ) {
            if (dp < 0) {
                dp = nums[i];
            } else {
                dp += nums[i];
            }
            res = max(res, dp);
        }

        return res;
    }
};