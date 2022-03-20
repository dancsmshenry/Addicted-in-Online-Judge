class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; ++ i) {
            while (nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            if (nums[i] <= n && nums[nums[i] - 1] == nums[i] && i != nums[i] - 1) {
                res.push_back(nums[i]);
                nums[i] = n + 1;
            }
        }

        return res;
    }
};