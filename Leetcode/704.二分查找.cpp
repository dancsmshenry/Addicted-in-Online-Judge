class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right= n - 1;

        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (nums[left] != target) {
            return -1;
        }
        return left;
    }
};