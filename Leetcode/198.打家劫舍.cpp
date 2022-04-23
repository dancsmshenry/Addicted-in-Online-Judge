class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> dp{nums[0], max(nums[0], nums[1])};

        for (int i = 2; i < n; ++ i) {
            dp[i % 2] = max(dp[1 - i % 2], dp[i % 2] + nums[i]);
        }

        return dp[1 - n % 2];
    }
};