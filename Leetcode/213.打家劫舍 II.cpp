class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        return max(solve(nums, 0, n - 1), solve(nums, 1, n));
    }

    int solve(vector<int>& nums, int begin, int end) {
        int first = nums[begin], second = max(nums[begin], nums[begin + 1]);

        for (int i = begin + 2; i < end; ++ i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
    }
};