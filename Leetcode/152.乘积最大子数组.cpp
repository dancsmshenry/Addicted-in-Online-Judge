class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn = nums[0], minn = nums[0]；
        int result = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; ++ i) {
            int mx = maxn, mn = minn;
            maxn = max(nums[i] * mx, max(nums[i], mn * nums[i]));
            minn = min(nums[i] * mn, min(nums[i], mx * nums[i]));
            result = max(maxn, result);
        }

        return result;
    }
};