class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = nums.size() - 1;

        while (true) {
            int mid = nums[left];
            int idx = left;
            for (int i = left + 1; i <= right; ++ i) {
                if (nums[i] >= mid) {
                    ++ idx;
                    swap(nums[i], nums[idx]);
                }
            }
            swap(nums[left], nums[idx]);
            if (idx == k - 1) {
                return nums[idx];
            } else if (idx > k - 1) {
                right = idx - 1;
            } else {
                left = idx + 1;
            }
        }
    }
};