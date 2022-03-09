class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        return (findKth(nums1, 0, nums2, 0, (m + n + 1) / 2) + findKth(nums1, 0, nums2, 0, (m + n + 2) / 2)) / 2.0;
    }
    //在两个有序数组中找到第k个元素（例如找第一个元素，k=1，即nums[0]）
    // i: nums1的起始位置 j: nums2的起始位置（i，j都是从0开始）
    int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        //若nums1为空（或是说其中数字全被淘汰了），在nums2中找第k个元素，此时nums2起始位置是j，所以是j+k-1
        if (i == nums1.size()) {
            return nums2[j + k - 1];
        }
        // nums2同理
        if (j == nums2.size()) {
            return nums1[i + k - 1];
        }

        //递归出口（当k等于1的时候，就直接返回两边的最小值）
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        //这两个数组的第K/2小的数字，若不足k/2个数字则赋值整型最大值，以便淘汰另一数组的前k/2个数字
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;

        //二分法核心部分
        //注意这里都是k-k/2，因为15/2=7，但是我们前面加上k/2的时候，筛掉的是7，后面应该再找第8个，而不是第7个
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
};
//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/zong-he-bai-jia-ti-jie-zong-jie-zui-qing-xi-yi-don/