class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> f(n, 0);

        int res = 0;
        for (int i = 2; i < n; i ++ ){
            if (nums[i] + nums[i - 2] == nums[i - 1] * 2){
                f[i] = f[i - 1] + 1;
            }
            res += f[i];
        }

        return res;
    }
};