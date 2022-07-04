// 暴力递归
class Solution {
private:
    int res{};
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return res;
    }

    void dfs(vector<int>& nums, int target, int index) {
        if (index + 1 == nums.size()) {
            res = res + ((nums[index] == target) ? 1: 0);
            res = res + ((nums[index] + target == 0) ? 1: 0);
            return ;
        }
        dfs(nums, target + nums[index], index + 1);
        dfs(nums, target - nums[index], index + 1);
    }
};

// 二维dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0), diff = sum - target;

        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }

        int n = nums.size(), neg = diff / 2;
        vector<vector<int>> dp(2, vector<int>(neg + 1));
        dp[0][0] = 1;

        for (int i = 1, now = 0, old = 0; i <= n; ++ i ) {
            now = i % 2;
            old = 1 - now;
            int num = nums[i - 1];
            for (int j = 0; j <= neg; ++ j) {
                dp[now][j] = dp[old][j];
                if (j >= num) {
                    dp[now][j] += dp[old][j - num];
                }
            }
        }

        return dp[n % 2][neg];
    }
};

// 压缩dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0), diff = sum - target;

        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }

        int n = nums.size(), neg = diff / 2;
        vector<int> dp(neg + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++ i ) {
            for (int j = neg; j >= 0; -- j) {
                if (j >= nums[i]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }

        return dp[neg];
    }
};