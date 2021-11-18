class Solution {
public:
    int number = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            本质上要计算的就是f[nums.size() - 1][target]有多少种方法
            但是我写的过程中发现，其实第二个维度不仅无法确定大小（因为可能出现数字加起来大于target的情况）
            而且还无法记录负数

            于是，我打算用递归回溯来实现
        */
        solve(nums, 0, target);
        return number;
    }

    void solve(vector<int>& nums, int begin, int target){
        if (begin == nums.size() - 1){
            if (target == nums[begin]){
                number ++ ;   
            }
            if ((target + nums[begin]) == 0){
                number ++ ;
            }
            return ;
        }
        solve(nums, begin + 1, target + nums[begin]);
        solve(nums, begin + 1, target - nums[begin]);
    }
};