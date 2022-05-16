class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            while (nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }

            if (nums[i] <= n && nums[nums[i] - 1] == nums[i] && nums[i] - 1 != i) {
                res.push_back(nums[i]);
                nums[nums[i] - 1] = n + 1;
                nums[i] = n + 1;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++ i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++ i) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};