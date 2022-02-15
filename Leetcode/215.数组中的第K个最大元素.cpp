class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (true) {
            int i = left, j = right;
            int temp = nums[left];

            while (i < j) {
                while (i < j && nums[j] > temp) j -- ;//大于的都放到右边
                while (i < j && nums[i] <= temp) i ++ ;//小于等于的都放到左边
                if (i < j) swap(nums[i], nums[j]);
            }
            swap(nums[left], nums[j]);//先从右到左，再从左到右，这样第j个才是小于等于temp的数字

            if (j == n - k) {
                return nums[j];
            } else if (j > n - k) {
                right = j - 1;
            } else {
                left = j + 1;
            }
        }

        return -1;
    }
};