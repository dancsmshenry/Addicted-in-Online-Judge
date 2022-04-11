class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort_k(nums, 0, nums.size() - 1, k);
    }

    int quick_sort_k(vector<int>& nums, int left, int right, int k) {
        if (left >= right) {
            return nums[left];
        }

        int l = left - 1, r = right + 1, mid = nums[left];
        while (l < r) {
            do l ++ ; while (nums[l] < mid);
            do r -- ; while (nums[r] > mid);
            if (l < r) swap(nums[l], nums[r]);
        }

        int length = right - r;
        if (length >= k) {
            return quick_sort_k(nums, r + 1, right, k);
        }

        return quick_sort_k(nums, left, r, k - length);
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (true) {
            int idx = partition(nums, l, r);
            if (idx == k - 1) {
                return nums[idx];
            } else if (idx < k - 1) {
                l = idx + 1;
            } else {
                r = idx - 1;
            }
        }
    }

    //单向遍历
    int partition(vector<int> & nums, int l, int r) {
        //理解：把小于等于pivot的都放到左边，然后返回中间的那个值的坐标，检测是否是第k大的数，然后调整长度
        int pivot = nums[l];
        int idx = l;
        for (int i = l + 1; i < r + 1; ++ i) {
            if (nums[i] >= pivot) {
                ++ idx;
                swap(nums[idx], nums[i]);
            }
        }
        swap(nums[l], nums[idx]);
        return idx;
    }
};