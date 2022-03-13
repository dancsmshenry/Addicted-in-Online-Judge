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

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size() - 1, k);
    }

    int find(vector<int>& nums, int left, int right, int k) {
        if (left >= right) {
            return nums[left];
        }
        int i = left - 1, j = right + 1, mid = nums[left];

        while (i < j) {
            do i ++ ; while (nums[i] < mid);
            do j -- ; while (nums[j] > mid);
            if (i < j) swap(nums[i], nums[j]);
        }

        int temp = right - j;//从0-j的全部都是小于mid的，temp计算右边还有多少数字
        if (temp >= k) {
            return find(nums, j + 1, right, k);
        }

        return find(nums, left, j, k - temp);
    }
};
//还有可以优化的空间https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/er-fen-fa-xuan-qu-zui-da-de-di-kzhi-by-d-uvc7/


class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (true)
        {
            int idx = partition(nums, l, r);
            if (idx == k - 1)
                return nums[idx];
            else if (idx < k - 1)
                l = idx + 1;
            else    
                r = idx - 1;
        }
    }

    //----单向遍历
    int partition(vector<int> & nums, int l, int r)
    {
        int pivot = nums[l];
        int idx = l;
        for (int i = l + 1; i < r + 1; i ++)
        {
            if (nums[i] >= pivot)
            {
                idx ++;
                swap(nums[idx], nums[i]);
            }
        }
        swap(nums[l], nums[idx]);
        return idx;
    }
};