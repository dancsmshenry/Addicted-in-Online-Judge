/**
 * 给定一个二进制数组，你可以最多将 1 个 0 翻转为 1，找出其中最大连续 1 的个数
 * 
 * 输入：[1,0,1,1,0]
 * 输出：4
 * 解释：翻转第一个 0 可以得到最长的连续 1。
 * 当翻转以后，最大连续 1 的个数为 4。
**/
class Solution {
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int dp1 = 0;
        int dp0 = 0;
        int res = -1;

        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 1) {
                dp1 = dp1 + 1;
                dp0 = dp0 + 1;
            } else {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(res, max(dp1, dp0));
        }

        return res;
    }
};//解析：https://blog.csdn.net/tankpanv/article/details/99680166