class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }else if (n == 2){
            return max(nums[0], nums[1]);
        }

        return max(solve(nums, 0, n - 1), solve(nums, 1, n));
    }

    int solve(vector<int>& nums, int begin, int end){
        //复盘一下使用二进制滚动数组时的一个错误(这里其实最好不要用二进制，因为，我们不知道begin是奇数还是偶数，这会导致我们后面遍历i%2的时候不好处理，比如说begin如果是奇数，那begin一开始就要放到1的位置；如果begin是偶数的话，那begin一开始就要放到0的位置，处理上就会有点麻烦)
        int first = nums[begin], second = max(nums[begin], nums[begin + 1]);
        for (int i = begin + 2; i < end; i ++ ){
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }

        return second;
    }
};