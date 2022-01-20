class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        //init
        vector<int> dp(n, nums[0]);
        dp[1] = max(dp[0], nums[1]);

        //dp
        for (int i = 2; i < n; i ++ ){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

//滚动数组解法
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        //init
        vector<int> dp{nums[0], max(nums[0], nums[1])};

        //dp
        for (int i = 2; i < n; i ++ ){
            dp[i % 2] = max(dp[i % 2] + nums[i], dp[1 - i % 2]);
        }

        return dp[(n - 1) % 2]; 
    }
};