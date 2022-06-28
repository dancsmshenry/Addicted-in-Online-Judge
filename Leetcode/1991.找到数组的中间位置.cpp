class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; ++ i) {
            if (prev == total - (prev + nums[i])) {
                return i;
            }
            prev += nums[i];
        }

        return -1;
    }
};