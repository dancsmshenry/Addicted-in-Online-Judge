class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {   
        vector<int> mid;
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < (1 << n); ++ i) {
            int number = i;
            mid.clear();
            
            for (int j = 0; j < n; ++ j) {
                if (number % 2 == 1) {
                    mid.push_back(nums[j]);
                }
                number /= 2;     
            }

            res.push_back(mid);
        }

        return res;
    }
};