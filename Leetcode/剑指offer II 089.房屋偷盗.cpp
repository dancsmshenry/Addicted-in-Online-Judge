class Solution {
public:
    int rob(vector<int>& nums) { 
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp{nums[0], max(nums[0], nums[1])};

        for (int i = 2; i < n; ++ i) {
            dp[i % 2] = max(dp[i % 2] + nums[i], dp[1 - i % 2]);
        }

        // return max(dp[0], dp[1]);
        return dp[1 - n % 2];
    }
};