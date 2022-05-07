class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1, k = i + 2; k < n; ++ k) {
                while (j < k && nums[i] + nums[j] <= nums[k]) {
                    ++ j;
                }
                res += max(0, k - j);
            }
        }

        return res;
    }
};