class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if (sum % 2 == 1){
            return false;
        }
        sum = sum / 2;
    
        vector<int> f(sum + 1, false);
        f[0] = true;
        for (int i = 1; i <= n; ++ i) {
            if (nums[i - 1] > sum) {
                return false;
            }
            for (int j = sum; j >= 0; -- j) {
                if (j + nums[i - 1] <= sum) {
                    f[j + nums[i - 1]] |= f[j];
                }
            }
            if (f[sum]) {
                return true;
            }
        }

        return false;
    }
};