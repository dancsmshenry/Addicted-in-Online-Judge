//dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;

        for (int i = 1; i < n; i ++ ){
            for (int j = 0; j < i; j ++ ){
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};

//二分+贪心
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //二分+贪心！！！
        //这个思路其实是非常的贪心的，每一步，即使是false，也会为后面铺垫更多的机会
        vector<int> dp(1, nums[0]);

        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] > dp.back()) {//如果当前的数字大于数组的最后一个数，就放入
                dp.push_back(nums[i]);
            } else {//否则，就试图把这个数利用二分的方法放入到数组里面，为什么要这样做呢？你比如说我之前连着的两个数是9、19、20，现在来了个10，明显是小于20和19，但是大于9的；那么此时我就把它替换19的位置，为什么要这样做?因为我想让我的数列增长的慢一点，这样如果后面再来一个17的话，我就可以把它用来代替20的位置了，就又可以把我的数列增长的更慢一些，从而为后续添加更多的机会
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }

        return dp.size();
    }
};