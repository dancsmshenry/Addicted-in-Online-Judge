class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int i = 0; i < n - 2; ++ i) {
            f[i][i + 2] = nums[i] * nums[i + 1] * nums[i + 2];
        }
        
        for (int i = 3; i < n; ++ i) {
            for (int j = 0; j < n - i; ++ j) {
                for (int k = j + 1; k < j + i; ++ k) {
                    f[j][j + i] = max(f[j][j + i], f[j][k] + nums[j] * nums[k] * nums[j + i] + f[k][j + i]);
                }
            }
        }

        return f[0].back();
    }
};