class Solution {
public:
    int maxCoins(vector<int>& nums) {
        /*init*/
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n - 2; i ++ ){
            f[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2];
        }
        
        /*dp*/
        for (int i = 3; i < n; i ++ ){
            for (int j = 0; j < n - i; j ++ ){
                for (int k = j + 1; k < j + i; k ++ ){
                    int temp = f[j][k] + f[k][j + i] + nums[k] * nums[j] * nums[j + i];
                    f[j][j + i] = temp > f[j][j + i] ? temp : f[j][j + i];
                }
            }
        }

        return f[0][n - 1];
    }
};