class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right_most = 0;//注意只有一个数的情况...
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            if (i <= right_most) {
                if (i + nums[i] >= n - 1) {
                    return true;
                }
                right_most = max(right_most, i + nums[i]);
            }
        }

        return false;
    }
};