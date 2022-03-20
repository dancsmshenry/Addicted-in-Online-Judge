class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int minn = INT_MAX, maxn = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            if (nums[i] >= maxn) {
                maxn = nums[i];
            } else {
                right = i;
            }

            if (nums[n - i - 1] <= minn) {
                minn = nums[n - i - 1];
            } else {
                left = n - i - 1;
            }
        }

        return right == left ? 0 : right - left + 1;
    }
};