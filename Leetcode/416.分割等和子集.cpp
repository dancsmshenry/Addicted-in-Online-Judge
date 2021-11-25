//该方法回溯超时了，要改用其他的方法
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        return solve(nums, 0, 0);
        //回溯超时了，那应该如何记录数据呢？
    }

    bool solve(vector<int>& nums, int begin, int target){
        if (begin == nums.size() - 1){
            if (target == nums[begin]){
                return true;   
            }
            if ((target + nums[begin]) == 0){
                return true;
            }
            return false;
        }
        return solve(nums, begin + 1, target + nums[begin]) || solve(nums, begin + 1, target - nums[begin]);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        首先的思路是建立一个二维数组，行代表的是第i个元素，列代表的是当前前i项能求到的和
        但是思路上有个问题是，他是要求把数组分割为两个子集，即求和后为0
        而数组的下标是大于-1的

        看到的一个解决方案，是先求和全部，然后判断对当前的子集能否得到总和的一半，能的话就ok了
        这个转换确实是挺绝的
        */
        //init
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i ++ ){
            sum += nums[i];
        }
        if (sum % 2 == 1){
            return false;
        }
        sum = sum / 2;
    
        //dp,f表示前i个数字相加后能不能得到j
        vector<vector<bool>> f(n, vector<bool> (sum + 1, false));
        for (int i = 1; i < n; i ++ ){      
            f[i][nums[i]] = true;  
            for (int j = 0; j <= sum; j ++ ){
                f[i][j] = (f[i - 1][j] || f[i][j]);
                if (j + nums[i] <= sum){
                    f[i][j + nums[i]] = (f[i - 1][j] || f[i][j + nums[i]]);
                }
            }
            if (f[i][sum]){
                return true;
            }
        }

        return false;
    }
};