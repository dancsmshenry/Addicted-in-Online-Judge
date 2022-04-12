class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++ i) {
            // for (int j = n - 1; j > i + 1; -- j) {
            //     int k = i + 1;
            //     while (k < j && nums[k] + nums[i] <= nums[j]) {
            //         ++ k;
            //     }
            //     count += max(j - k, 0);
            // }
            int k = i + 1;
            for (int j = i + 2; j < n; ++ j) {
                while (k < j && nums[k] + nums[i] <= nums[j]) {
                    ++ k;
                }
                count += max(j - k, 0);
            }
        }

        return count;
    }
};