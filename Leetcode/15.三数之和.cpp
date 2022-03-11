class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left ++ ;
                    while (left < right && nums[left] == nums[left - 1]) left ++ ;
                    right -- ;
                    while (right > left && nums[right] == nums[right + 1]) right -- ;
                } else if (sum > 0) {
                    right -- ;
                    while (right > left && nums[right] == nums[right + 1]) right -- ;
                } else {
                    left ++ ;
                    while (left < right && nums[left] == nums[left - 1]) left ++ ;
                }
            }
        }

        return result;
    }
};