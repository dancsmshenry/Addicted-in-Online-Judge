class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //两次二分
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int one, two;
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[right] != target) {
            return {-1 ,-1};
        }
        one = right;
        left = 0;
        right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        two = right;

        return {one, two};
    }
};