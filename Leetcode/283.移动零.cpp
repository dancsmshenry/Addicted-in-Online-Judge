class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;

        while (right < n) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                ++ left;
            }
            ++ right;
        }
    }
};