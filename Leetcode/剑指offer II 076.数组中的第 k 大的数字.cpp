class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (true) {
            int index = find(nums, left, right);
            if (index == k - 1) {
                return nums[k - 1];
            } else if (index > k - 1) {
                right = index - 1;
            } else {
                left = index + 1;
            }
        }
    }

    int find(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        int count = left;
        for (int i = left + 1; i < right + 1; ++ i) {
            if (nums[i] > temp) {
                count ++ ;
                swap(nums[i], nums[count]);
            }
        }
        swap(nums[left], nums[count]);
        return count;
    }
};